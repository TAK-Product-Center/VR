/*
  Derived From: https://github.com/sp4cerat/Fast-Quadric-Mesh-Simplification/blob/master/src.gl/Simplify.h

# MIT License

Copyright © 2015-2019 Spacerat and contributors

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "model/MeshSimplification.h"

#include <cassert>
#include <cstring>
#include <vector>

#include "math/Vector4.h"
#include "model/MeshBuilder.h"

using namespace TAK::Engine::Model;

using namespace TAK::Engine::Math;
using namespace TAK::Engine::Util;

#define loop(__v, __v0, __lim) for(int __v = __v0; __v < __lim; __v++)
#define loopi(__v0, __lim) loop(i, __v0, __lim)
#define loopj(__v0, __lim) loop(j, __v0, __lim)
#define loopk(__v0, __lim) loop(k, __v0, __lim)
#ifdef printf
#undef printf
#endif
#define printf(...)

#define timeGetTime() TAK::Engine::Port::Platform_systime_millis()

#ifndef min
#define min(a, b) std::min(a, b)
#endif
#ifndef max
#define max(a, b) std::max(a, b)
#endif

namespace {
    struct vec3f {
        double x {0.0};
        double y {0.0};
        double z {0.0};

        void cross(const vec3f &other) NOTHROWS
        {
            auto v = Vector2_cross(Point2<double>(x, y, z), Point2<double>(other.x, other.y, other.z));
            x = v.x;
            y = v.y;
            z = v.z;
        }
        void cross(const vec3f &a, const vec3f &b) NOTHROWS
        {
            auto v = Vector2_cross(Point2<double>(a.x, a.y, a.z), Point2<double>(b.x, b.y, b.z));
            x = v.x;
            y = v.y;
            z = v.z;
        }
        void normalize() NOTHROWS
        {
            auto v = Vector2_normalize(Point2<double>(x, y, z));
            x = v.x;
            y = v.y;
            z = v.z;
        }
        double dot(const vec3f &other) const NOTHROWS
        {
            return Vector2_dot(Point2<double>(x, y, z), Point2<double>(other.x, other.y, other.z));
        }
        vec3f operator+(const vec3f &other) const NOTHROWS
        {
            auto v = Vector2_add(Point2<double>(x, y, z), Point2<double>(other.x, other.y, other.z));
            return {v.x, v.y, v.z};
        }
        vec3f operator-(const vec3f &other) const NOTHROWS
        {
            auto v = Vector2_subtract(Point2<double>(x, y, z), Point2<double>(other.x, other.y, other.z));
            return {v.x, v.y, v.z};
        }
        vec3f operator/(const float d) const NOTHROWS
        {
            auto v = Vector2_multiply(Point2<double>(x, y, z), 1.0/d);
            return {v.x, v.y, v.z};
        }
    };

    class SymetricMatrix {

    public:

        // Constructor

        SymetricMatrix(double c=0) { loopi(0,10) m[i] = c;  }

        SymetricMatrix(	double m11, double m12, double m13, double m14,
                           double m22, double m23, double m24,
                           double m33, double m34,
                           double m44) {
            m[0] = m11;  m[1] = m12;  m[2] = m13;  m[3] = m14;
            m[4] = m22;  m[5] = m23;  m[6] = m24;
            m[7] = m33;  m[8] = m34;
            m[9] = m44;
        }

        // Make plane

        SymetricMatrix(double a,double b,double c,double d)
        {
            m[0] = a*a;  m[1] = a*b;  m[2] = a*c;  m[3] = a*d;
            m[4] = b*b;  m[5] = b*c;  m[6] = b*d;
            m[7 ] =c*c; m[8 ] = c*d;
            m[9 ] = d*d;
        }

        double operator[](int c) const { return m[c]; }

        // Determinant

        double det(	int a11, int a12, int a13,
                       int a21, int a22, int a23,
                       int a31, int a32, int a33)
        {
            double det =  m[a11]*m[a22]*m[a33] + m[a13]*m[a21]*m[a32] + m[a12]*m[a23]*m[a31]
                          - m[a13]*m[a22]*m[a31] - m[a11]*m[a23]*m[a32]- m[a12]*m[a21]*m[a33];
            return det;
        }

        const SymetricMatrix operator+(const SymetricMatrix& n) const
        {
            return SymetricMatrix( m[0]+n[0],   m[1]+n[1],   m[2]+n[2],   m[3]+n[3],
                                   m[4]+n[4],   m[5]+n[5],   m[6]+n[6],
                                   m[ 7]+n[ 7], m[ 8]+n[8 ],
                                   m[ 9]+n[9 ]);
        }

        SymetricMatrix& operator+=(const SymetricMatrix& n)
        {
            m[0]+=n[0];   m[1]+=n[1];   m[2]+=n[2];   m[3]+=n[3];
            m[4]+=n[4];   m[5]+=n[5];   m[6]+=n[6];   m[7]+=n[7];
            m[8]+=n[8];   m[9]+=n[9];
            return *this;
        }

        double m[10];
    };
///////////////////////////////////////////

    struct Simplify {
        // Global Variables & Strctures

        struct Triangle {
            int v[3];
            double err[4];
            int deleted, dirty;
            vec3f n;
        };
        struct Vertex {
            vec3f p;
            int tstart, tcount;
            SymetricMatrix q;
            int border;
        };
        struct Ref {
            int tid, tvertex;
        };
        std::vector<Triangle> triangles;
        std::vector<Vertex> vertices;
        std::vector<Ref> refs;

        // Helper functions

//        double vertex_error(SymetricMatrix q, double x, double y, double z);
//        double calculate_error(int id_v1, int id_v2, vec3f &p_result);
//        bool flipped(vec3f p, int i0, int i1, Vertex &v0, Vertex &v1, std::vector<int> &deleted);
//        void update_triangles(int i0, Vertex &v, std::vector<int> &deleted, int &deleted_triangles);
//        void update_mesh(int iteration);
//        void compact_mesh();

        //
        // Main simplification function
        //
        // target_count  : target nr. of triangles
        // agressiveness : sharpness to increase the threshold.
        //                 5..8 are good numbers
        //                 more iterations yield higher quality
        //
        void simplify_mesh(int target_count, double agressiveness = 7) {
            // init
            printf("%s - start\n", __FUNCTION__);
            auto timeStart = timeGetTime();

            loopi(0, triangles.size()) triangles[i].deleted = 0;

            // main iteration loop

            int deleted_triangles = 0;
            std::vector<int> deleted0, deleted1;
            int triangle_count = (int)triangles.size();

            loop(iteration, 0, 100) {
                // target number of triangles reached ? Then break
                printf("iteration %d - triangles %d - threshold %lf\n", iteration,
                       triangle_count - deleted_triangles, (0.000000001 * pow(double(iteration + 3), agressiveness)));
                if (triangle_count - deleted_triangles <= target_count)break;

                // update mesh once in a while
                if (iteration % 5 == 0) {
                    update_mesh(iteration);
                }

                // clear dirty flag
                loopi(0, triangles.size()) triangles[i].dirty = 0;

                //
                // All triangles with edges below the threshold will be removed
                //
                // The following numbers works well for most models.
                // If it does not, try to adjust the 3 parameters
                //
                double threshold = 0.000000001 * pow(double(iteration + 3), agressiveness);

                // remove vertices & mark deleted triangles
                loopi(0, triangles.size()) {
                    Triangle &t = triangles[i];
                    if (t.err[3] > threshold) continue;
                    if (t.deleted) continue;
                    if (t.dirty) continue;

                    loopj(0, 3)
                        if (t.err[j] < threshold) {
                            int i0 = t.v[j];
                            Vertex &v0 = vertices[i0];
                            int i1 = t.v[(j + 1) % 3];
                            Vertex &v1 = vertices[i1];

                            // Border check
                            if (v0.border || v1.border) continue;

                            // Compute vertex to collapse to
                            vec3f p;
                            calculate_error(i0, i1, p);

                            deleted0.resize(v0.tcount); // normals temporarily
                            deleted1.resize(v1.tcount); // normals temporarily

                            // don't remove if flipped
                            if (flipped(p, i0, i1, v0, v1, deleted0)) continue;
                            if (flipped(p, i1, i0, v1, v0, deleted1)) continue;

                            // not flipped, so remove edge
                            v0.p = p;
                            v0.q = v1.q + v0.q;
                            auto tstart = refs.size();

                            update_triangles(i0, v0, deleted0, deleted_triangles);
                            update_triangles(i0, v1, deleted1, deleted_triangles);

                            auto tcount = refs.size() - tstart;

                            if (tcount <= v0.tcount) {
                                // save ram
                                if (tcount)
                                    memcpy(&refs[v0.tstart], &refs[tstart], tcount * sizeof(Ref));
                            } else
                                // append
                                v0.tstart = (int)tstart;

                            v0.tcount = (int)tcount;
                            break;
                        }
                    // done?
                    if (triangle_count - deleted_triangles <= target_count)break;
                }
            }

            // clean up mesh
            compact_mesh();

            // ready
            auto timeEnd = timeGetTime();
            printf("%s - %d/%d %d%% removed in %d ms\n", __FUNCTION__,
                   triangle_count - deleted_triangles,
                   triangle_count, deleted_triangles * 100 / triangle_count,
                   (int)(timeEnd - timeStart));

        }

        // Check if a triangle flips when this edge is removed

        bool flipped(vec3f p,int i0,int i1,Vertex &v0,Vertex &v1,std::vector<int> &deleted)
        {
            int bordercount=0;
            loopk(0,v0.tcount)
            {
                Triangle &t=triangles[refs[v0.tstart+k].tid];
                if(t.deleted)continue;

                int s=refs[v0.tstart+k].tvertex;
                int id1=t.v[(s+1)%3];
                int id2=t.v[(s+2)%3];

                if(id1==i1 || id2==i1) // delete ?
                {
                    bordercount++;
                    deleted[k]=1;
                    continue;
                }
                vec3f d1 = vertices[id1].p-p; d1.normalize();
                vec3f d2 = vertices[id2].p-p; d2.normalize();
                if(fabs(d1.dot(d2))>0.999) return true;
                vec3f n;
                n.cross(d1,d2);
                n.normalize();
                deleted[k]=0;
                if(n.dot(t.n)<0.2) return true;
            }
            return false;
        }

        // Update triangle connections and edge error after a edge is collapsed

        void update_triangles(int i0,Vertex &v,std::vector<int> &deleted,int &deleted_triangles)
        {
            vec3f p;
            loopk(0,v.tcount)
            {
                Ref &r=refs[v.tstart+k];
                Triangle &t=triangles[r.tid];
                if(t.deleted)continue;
                if(deleted[k])
                {
                    t.deleted=1;
                    deleted_triangles++;
                    continue;
                }
                t.v[r.tvertex]=i0;
                t.dirty=1;
                t.err[0]=calculate_error(t.v[0],t.v[1],p);
                t.err[1]=calculate_error(t.v[1],t.v[2],p);
                t.err[2]=calculate_error(t.v[2],t.v[0],p);
                t.err[3]=min(t.err[0],min(t.err[1],t.err[2]));
                refs.push_back(r);
            }
        }

        // compact triangles, compute edge error and build reference list

        void update_mesh(int iteration)
        {
            if(iteration>0) // compact triangles
            {
                int dst=0;
                loopi(0,triangles.size())
                if(!triangles[i].deleted)
                {
                    triangles[dst++]=triangles[i];
                }
                triangles.resize(dst);
            }
            //

            // Init Reference ID list
            loopi(0,vertices.size())
            {
                vertices[i].tstart=0;
                vertices[i].tcount=0;
            }
            loopi(0,triangles.size())
            {
                Triangle &t=triangles[i];
                loopj(0,3) vertices[t.v[j]].tcount++;
            }
            int tstart=0;
            loopi(0,vertices.size())
            {
                Vertex &v=vertices[i];
                v.tstart=tstart;
                tstart+=v.tcount;
                v.tcount=0;
            }

            // Write References
            refs.resize(triangles.size()*3);
            loopi(0,triangles.size())
            {
                Triangle &t=triangles[i];
                loopj(0,3)
                {
                    Vertex &v=vertices[t.v[j]];
                    refs[v.tstart+v.tcount].tid=i;
                    refs[v.tstart+v.tcount].tvertex=j;
                    v.tcount++;
                }
            }

            // Init Quadrics by Plane & Edge Errors
            //
            // required at the beginning ( iteration == 0 )
            // recomputing during the simplification is not required,
            // but mostly improves the result for closed meshes
            //
            if( iteration == 0 )
            {
                // Identify boundary : vertices[].border=0,1

                std::vector<int> vcount,vids;

                loopi(0,vertices.size())
                vertices[i].border=0;

                loopi(0,vertices.size())
                {
                    Vertex &v=vertices[i];
                    vcount.clear();
                    vids.clear();
                    loopj(0,v.tcount)
                    {
                        int tk=refs[v.tstart+j].tid;
                        Triangle &t=triangles[tk];
                        loopk(0,3)
                        {
                            int ofs=0,id=t.v[k];
                            while(ofs<vcount.size())
                            {
                                if(vids[ofs]==id)break;
                                ofs++;
                            }
                            if(ofs==vcount.size())
                            {
                                vcount.push_back(1);
                                vids.push_back(id);
                            }
                            else
                                vcount[ofs]++;
                        }
                    }
                    loopj(0,vcount.size()) if(vcount[j]==1)
                        vertices[vids[j]].border=1;
                }
                //initialize errors
                loopi(0,vertices.size())
                vertices[i].q=SymetricMatrix(0.0);

                loopi(0,triangles.size())
                {
                    Triangle &t=triangles[i];
                    vec3f n,p[3];
                    loopj(0,3) p[j]=vertices[t.v[j]].p;
                    n.cross(p[1]-p[0],p[2]-p[0]);
                    n.normalize();
                    t.n=n;
                    loopj(0,3) vertices[t.v[j]].q =
                                       vertices[t.v[j]].q+SymetricMatrix(n.x,n.y,n.z,-n.dot(p[0]));
                }
                loopi(0,triangles.size())
                {
                    // Calc Edge Error
                    Triangle &t=triangles[i];vec3f p;
                    loopj(0,3) t.err[j]=calculate_error(t.v[j],t.v[(j+1)%3],p);
                    t.err[3]=min(t.err[0],min(t.err[1],t.err[2]));
                }
            }
        }

        // Finally compact mesh before exiting

        void compact_mesh()
        {
            int dst=0;
            loopi(0,vertices.size())
            {
                vertices[i].tcount=0;
            }
            loopi(0,triangles.size())
            if(!triangles[i].deleted)
            {
                Triangle &t=triangles[i];
                triangles[dst++]=t;
                loopj(0,3)vertices[t.v[j]].tcount=1;
            }
            triangles.resize(dst);
            dst=0;
            loopi(0,vertices.size())
            if(vertices[i].tcount)
            {
                vertices[i].tstart=dst;
                vertices[dst].p=vertices[i].p;
                dst++;
            }
            loopi(0,triangles.size())
            {
                Triangle &t=triangles[i];
                loopj(0,3)t.v[j]=vertices[t.v[j]].tstart;
            }
            vertices.resize(dst);
        }

        // Error between vertex and Quadric

        double vertex_error(SymetricMatrix q, double x, double y, double z)
        {
            return   q[0]*x*x + 2*q[1]*x*y + 2*q[2]*x*z + 2*q[3]*x + q[4]*y*y
                     + 2*q[5]*y*z + 2*q[6]*y + q[7]*z*z + 2*q[8]*z + q[9];
        }

        // Error for one edge

        double calculate_error(int id_v1, int id_v2, vec3f &p_result)
        {
            // compute interpolated vertex

            SymetricMatrix q = vertices[id_v1].q + vertices[id_v2].q;
            bool   border = vertices[id_v1].border & vertices[id_v2].border;
            double error=0;
            double det = q.det(0, 1, 2, 1, 4, 5, 2, 5, 7);

            if ( det != 0 && !border )
            {
                // q_delta is invertible
                p_result.x = -1/det*(q.det(1, 2, 3, 4, 5, 6, 5, 7 , 8));	// vx = A41/det(q_delta)
                p_result.y =  1/det*(q.det(0, 2, 3, 1, 5, 6, 2, 7 , 8));	// vy = A42/det(q_delta)
                p_result.z = -1/det*(q.det(0, 1, 3, 1, 4, 6, 2, 5,  8));	// vz = A43/det(q_delta)
                error = vertex_error(q, p_result.x, p_result.y, p_result.z);
            }
            else
            {
                // det = 0 -> try to find best result
                vec3f p1=vertices[id_v1].p;
                vec3f p2=vertices[id_v2].p;
                vec3f p3=(p1+p2)/2;
                double error1 = vertex_error(q, p1.x,p1.y,p1.z);
                double error2 = vertex_error(q, p2.x,p2.y,p2.z);
                double error3 = vertex_error(q, p3.x,p3.y,p3.z);
                error = min(error1, min(error2, error3));
                if (error1 == error) p_result=p1;
                if (error2 == error) p_result=p2;
                if (error3 == error) p_result=p3;
            }
            return error;
        }

        // Optional : Store as OBJ

//        void write_obj(char* filename)
//        {
//            FILE *file=fopen(filename, "w");
//            if (!file)
//            {
//                printf("write_obj: can't write data file \"%s\".\n", filename);
//                system("PAUSE");
//                exit(0);
//            }
//            loopi(0,vertices.size())
//            {
//                fprintf(file, "v %lf %lf %lf\n", vertices[i].p.x,vertices[i].p.y,vertices[i].p.z);
//            }
//            loopi(0,triangles.size()) if(!triangles[i].deleted)
//            {
//                fprintf(file, "f %d// %d// %d//\n", triangles[i].v[0]+1, triangles[i].v[1]+1, triangles[i].v[2]+1);
//            }
//            fclose(file);
//        }
    };
}

TAKErr TAK::Engine::Model::MeshSimplication_simplify(MeshPtr &value, const Mesh &src, const double maxError) NOTHROWS
{
    if(!src.isIndexed())
        return TE_InvalidArg;

    if(src.getVertexDataLayout().attributes&~VertexAttribute::TEVA_Position)
        Logger_log(TELL_Warning, "MeshSimplification_simplify: discarding all vertex attributes other than positioins");

    Simplify s;
    s.vertices.reserve(src.getNumVertices());
    for(std::size_t i = 0u; i < src.getNumVertices(); i++) {
        Point2<double> xyz;
        src.getPosition(&xyz, i);
        Simplify::Vertex v;
        v.p = {xyz.x, xyz.y, xyz.z};
        s.vertices.push_back(v);
    }
    s.triangles.reserve(src.getNumIndices());
    for(std::size_t i = 0u; i < src.getNumIndices(); i += 3) {
        std::size_t idx[3];
        src.getIndex(idx, i);
        src.getIndex(idx+1, i+1);
        src.getIndex(idx+2, i+2);
        Simplify::Triangle t;
        t.v[0] = (int)idx[0];
        t.v[1] = (int)idx[1];
        t.v[2] = (int)idx[2];
        s.triangles.push_back(t);
    }
    s.simplify_mesh((int)(src.getNumVertices()*0.05), 10);

    const auto indexType = (s.vertices.size() <= 0xFFFFu) ?
            TAK::Engine::Port::TEDT_UInt16 : TAK::Engine::Port::TEDT_UInt32;
    std::vector<double> positions(s.vertices.size()*3u);
    std::vector<uint8_t> indices(s.triangles.size()*3u*TAK::Engine::Port::DataType_size(indexType));

    auto xyz = positions.data();
    for(const auto &v : s.vertices) {
        *xyz++ = v.p.x;
        *xyz++ = v.p.y;
        *xyz++ = v.p.z;
    }
    if(indexType == Port::TEDT_UInt16) {
        auto idx = reinterpret_cast<uint16_t *>(indices.data());
        for(auto &t : s.triangles) {
            *idx++ = (uint16_t)t.v[0];
            *idx++ = (uint16_t)t.v[1];
            *idx++ = (uint16_t)t.v[2];
        }
    } else {
        assert(indexType == Port::TEDT_UInt32);
        auto idx = reinterpret_cast<uint32_t *>(indices.data());
        for(auto &t : s.triangles) {
            *idx++ = (uint32_t)t.v[0];
            *idx++ = (uint32_t)t.v[1];
            *idx++ = (uint32_t)t.v[2];
        }
    }

    VertexDataLayout layout;
    layout.attributes = VertexAttribute::TEVA_Position;
    layout.interleaved = false;
    layout.position.type = Port::TEDT_Float64;
    layout.position.size = 3u;
    layout.position.stride = Port::DataType_size(layout.position.type)*layout.position.size;

    return MeshBuilder_buildNonInterleavedMesh(
            value,
            TEDM_Triangles,
            TEWO_Undefined,
            layout,
            0, nullptr,
            src.getAABB(),
            s.vertices.size(), positions.data(), nullptr, nullptr, nullptr,
            indexType, s.triangles.size()*3u, indices.data());
}