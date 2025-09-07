#include "GLTFRenderer.h"

#include <memory>

#ifdef __ANDROID__
#include <android/log.h>
#endif

#include "Matrix.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

#define CheckGLErrors(desc)                                                   \
  {                                                                           \
    GLenum e = glGetError();                                                  \
    if (e != GL_NO_ERROR) {                                                   \
      printf("OpenGL error in \"%s\": %d (%d) %s:%d\n", desc, e, e, __FILE__, \
             __LINE__);                                                       \
      exit(20);                                                               \
    }                                                                         \
  }

namespace {
    void DrawMesh(const GLRendererState &rstate, const GLMeshState &mesh);
    void DrawNode(const GLRendererState &rstate, const GLNodeBinding &node, const GLuint u_xform, const double *xform);
}

void TAK::Engine::Formats::Cesium3DTiles::Renderer_draw(const GLRendererState &state, const GLuint u_xform, const double *xform)
{
    GLboolean cullFaceEnabled = glIsEnabled(GL_CULL_FACE);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    for(auto node : state.nodes)
        DrawNode(state, node, u_xform, xform);

    if(cullFaceEnabled)
        glEnable(GL_CULL_FACE);
    else
        glDisable(GL_CULL_FACE);
}
void TAK::Engine::Formats::Cesium3DTiles::Renderer_release(const GLRendererState &state)
{
    // cleanup VBOs
    if(state.gBufferState.size()) {
        std::vector<GLuint> vbos;
        vbos.reserve(state.gBufferState.size());
        for (auto it = state.gBufferState.begin(); it != state.gBufferState.end(); it++)
            vbos.push_back(it->second);
        glDeleteBuffers((GLsizei)vbos.size(), vbos.data());
    }

    // cleanup textures
    for(auto it = state.textures.begin(); it != state.textures.end(); it++)
        glDeleteTextures(1u, &it->second);
}

namespace {

    void DrawMesh(const GLRendererState &rstate, const GLMeshState &glmesh) {
        for (size_t i = 0; i < glmesh.primitives.size(); i++) {
            const GLPrimitive &primitive = glmesh.primitives[i];

            if(primitive.doubleSided)
                glDisable(GL_CULL_FACE);
            else
                glEnable(GL_CULL_FACE);

            std::vector<GLuint> activeAttribs;
            activeAttribs.reserve(primitive.accessors.size());

            // Assume TEXTURE_2D target for the texture object.
            glBindTexture(GL_TEXTURE_2D, primitive.texid);

            for (const GLAccessor &accessor : primitive.accessors) {
                glBindBuffer(GL_ARRAY_BUFFER, accessor.vb);

                // it->first would be "POSITION", "NORMAL", "TEXCOORD_0", ...
                glVertexAttribPointer(accessor.attrib, accessor.size,
                                      accessor.type, accessor.normalized,
                                      accessor.stride,
                                      BUFFER_OFFSET(accessor.offset));

                glEnableVertexAttribArray(accessor.attrib);
                activeAttribs.push_back(accessor.attrib);
            }

            if(primitive.indexed) {
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, primitive.indices.vb);
                glDrawElements(primitive.mode, primitive.indices.count, primitive.indices.type,
                               BUFFER_OFFSET(primitive.indices.offset));

                // unbind the index buffer
                glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            } else {
                glDrawArrays(primitive.mode, 0, primitive.accessors[0].count);
            }
            // disable the attributes enabled for draw
            for(auto attrib_id : activeAttribs)
                glDisableVertexAttribArray(attrib_id);

            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    }

// Hierarchically draw nodes
    void DrawNode(const GLRendererState &rstate, const GLNodeBinding &node, const GLuint u_xform, const double *xform) {
        // Apply xform

        //glPushMatrix();
        const double *node_xform = xform;
        double mx[16];
        Matrix_identity(mx);
        if (node.matrix.size() == 16) {
            // Use `matrix' attribute
            //glMultMatrixd(node.matrix.data());
            if(xform)
                Matrix_concatenate(mx, xform, node.matrix.data());
            else
                Matrix_concatenate(mx, mx, node.matrix.data());
            node_xform = mx;
        }

        // upload the node transform if it has been modified
        if(node_xform != xform) {
            float node_xformf[16];
            for(std::size_t i = 0u; i < 16u; i++)
                node_xformf[i] = (float)node_xform[i];
            glUniformMatrix4fv(u_xform, 1u, false, node_xformf);
        }

        //std::cout << "node " << node.name << ", Meshes " << node.meshes.size() << std::endl;

        for (size_t i = 0; i < node.meshes.size(); i++) {
            DrawMesh(rstate, node.meshes[i]);
        }

        // Draw child nodes.
        for (size_t i = 0; i < node.children.size(); i++) {
            DrawNode(rstate, node.children[i], u_xform, node_xform);
        }

        //glPopMatrix();
        if(node_xform != xform) {
            if(!xform) {
                Matrix_identity(mx);
                xform = mx;
            }
            float xformf[16];
            for(std::size_t i = 0u; i < 16u; i++)
                xformf[i] = (float)xform[i];
            glUniformMatrix4fv(u_xform, 1u, false, xformf);
        }
    }
}

namespace
{

    void bindMesh(CesiumGltf::Model &model, CesiumGltf::Mesh &mesh, GLRendererState *modelBinding, GLMeshState *binding);
    // bind models
    void bindModelNodes(CesiumGltf::Model &model, CesiumGltf::Node &node, GLRendererState *binding, GLNodeBinding &nodeBinding);

    int getPrimitiveTexture(CesiumGltf::Model &model, CesiumGltf::MeshPrimitive &primitive);
}

bool TAK::Engine::Formats::Cesium3DTiles::Renderer_bindModel(GLRendererState *state, CesiumGltf::Model &model) {
    if(model.scenes.empty())
        return false;

    GLRendererState &binding = *state;

    int sceneIdx = model.scene;
    if(sceneIdx < 0 || sceneIdx >= model.scenes.size())
        sceneIdx = 0;

    // layout specifier in shader
    GLint vtloc = 0;
    GLint nrmloc = 1;
    GLint uvloc = 2;

    state->gGLProgramState.attribs[state->gGLProgramState.nextAttribAlias] = vtloc;
    state->gGLProgramState.attribAliases["POSITION"] = state->gGLProgramState.nextAttribAlias++;
    state->gGLProgramState.attribs[state->gGLProgramState.nextAttribAlias] = nrmloc;
    state->gGLProgramState.attribAliases["NORMAL"] = state->gGLProgramState.nextAttribAlias++;
    state->gGLProgramState.attribs[state->gGLProgramState.nextAttribAlias] = uvloc;
    state->gGLProgramState.attribAliases["TEXCOORD_0"] = state->gGLProgramState.nextAttribAlias++;

    // bind all Buffer Views to VBOs
    for (int i = 0; i < model.bufferViews.size(); ++i) {
        const CesiumGltf::BufferView &bufferView = model.bufferViews[i];
        if (!bufferView.target.has_value() || bufferView.target == 0) {  // TODO impl drawarrays
            //__android_log_print(ANDROID_LOG_WARN, "GLTF", "WARN: bufferView.target is zero");
            continue;  // Unsupported bufferView.
            /*
              From spec2.0 readme:
              https://github.com/KhronosGroup/glTF/tree/master/specification/2.0
                       ... drawArrays function should be used with a count equal to
              the count            property of any of the accessors referenced by the
              attributes            property            (they are all equal for a given
              primitive).
            */
        }

        const CesiumGltf::Buffer &buffer = model.buffers[bufferView.buffer];
        //std::cout << "bufferview.target " << bufferView.target << std::endl;
        //__android_log_print(ANDROID_LOG_DEBUG, "GLTF", "bufferview.target  0x%X", bufferView.target);

        GLuint vbo;
        glGenBuffers(1, &vbo);
        binding.gBufferState[i] = vbo;
        GLenum target = bufferView.target.value();
        glBindBuffer(target, vbo);

        //std::cout << "buffer.data.size = " << buffer.data.size()
        //          << ", bufferview.byteOffset = " << bufferView.byteOffset
        //          << std::endl;
        //__android_log_print(ANDROID_LOG_DEBUG, "GLTF", "buffer.data.size = %lu, bufferview.byteOffset = %d", (unsigned int)buffer.data.size(), bufferView.byteOffset);

        glBufferData(target, bufferView.byteLength,
                     &buffer.cesium.data.at(0) + bufferView.byteOffset, GL_STATIC_DRAW);
        glBindBuffer(target, 0u);
    }

    // construct a single pixel white texture for untextured meshes
    {
        GLuint texid;
        glGenTextures(1, &texid);
        glBindTexture(GL_TEXTURE_2D, texid);
        glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        unsigned short px = 0xFFFF;

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1u,
                     1u, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5,
                     &px);

        glBindTexture(GL_TEXTURE_2D, 0);

        binding.textures[-1] = texid;
    }

    for(int i = 0; i < model.meshes.size(); i++) {
        bindMesh(model, model.meshes[i], &binding, &binding.gMeshState[i]);
    }

    const CesiumGltf::Scene &scene = model.scenes[sceneIdx];
    binding.nodes.resize(scene.nodes.size());
    for (size_t i = 0; i < scene.nodes.size(); ++i) {
        bindModelNodes(model, model.nodes[scene.nodes[i]], &binding, binding.nodes[i]);
    }

    return true;
}

namespace
{
    void bindMesh(CesiumGltf::Model &model,
                  CesiumGltf::Mesh &mesh,
                  GLRendererState *modelBinding,
                  GLMeshState *binding) {

        binding->primitives.reserve(mesh.primitives.size());
        for (size_t i = 0; i < mesh.primitives.size(); ++i) {
            CesiumGltf::MeshPrimitive primitive = mesh.primitives[i];

            GLPrimitive glprimitive;
            glprimitive.texid = 0u;
            glprimitive.mode = primitive.mode;

            if(primitive.indices >= 0 && primitive.indices < model.accessors.size()) {
                CesiumGltf::Accessor &indexAccessor = model.accessors[primitive.indices];

                glprimitive.indexed = true;

                glprimitive.indices.vb = modelBinding->gBufferState[indexAccessor.bufferView];
                glprimitive.indices.type = indexAccessor.componentType;
                glprimitive.indices.count = (GLuint)indexAccessor.count;
                glprimitive.indices.offset = (GLuint)indexAccessor.byteOffset;
            } else {
                glprimitive.indexed = false;
            }

            // bind all attributes
            glprimitive.accessors.reserve(primitive.attributes.size());
            for (auto &attrib : primitive.attributes) {
                CesiumGltf::Accessor accessor = model.accessors[attrib.second];

                if(modelBinding->gGLProgramState.attribAliases.find(attrib.first) == modelBinding->gGLProgramState.attribAliases.end())
                    continue;
                if(accessor.bufferView < 0 || accessor.bufferView >= model.bufferViews.size())
                    continue;
                if(modelBinding->gBufferState.find(accessor.bufferView) == modelBinding->gBufferState.end())
                    continue;

                int64_t byteStride = model.bufferViews[accessor.bufferView].byteStride.value_or(0);

                GLAccessor glaccessor;
                glaccessor.vb = modelBinding->gBufferState[accessor.bufferView];

                glaccessor.size = 1;
                if (accessor.type == CesiumGltf::AccessorSpec::Type::SCALAR)
                    glaccessor.size = 1;
                else if (accessor.type == CesiumGltf::AccessorSpec::Type::VEC2)
                    glaccessor.size = 2;
                else if (accessor.type == CesiumGltf::AccessorSpec::Type::VEC3)
                    glaccessor.size = 3;
                else if (accessor.type == CesiumGltf::AccessorSpec::Type::VEC4)
                    glaccessor.size = 4;
                else
                    assert(0);

                glaccessor.attrib = modelBinding->gGLProgramState.attribAliases[attrib.first];
                glaccessor.type = accessor.componentType;
                glaccessor.normalized = GL_FALSE;
                glaccessor.stride = (GLuint)byteStride;
                glaccessor.offset = (GLuint)accessor.byteOffset;
                glaccessor.vb = modelBinding->gBufferState[accessor.bufferView];
                glaccessor.count = (GLuint)accessor.count;

                glprimitive.accessors.push_back(glaccessor);
            }

            // primitive has no usable accessors, skip binding
            if(glprimitive.accessors.empty())
                continue;

            if(primitive.material >= 0 && primitive.material < model.materials.size())
                glprimitive.doubleSided = model.materials[primitive.material].doubleSided;
            else
                glprimitive.doubleSided = false;

            // generate and upload the texture
            const int primitiveMatTexIdx = getPrimitiveTexture(model, primitive);
            if(primitiveMatTexIdx >= 0) {
                // load the texture
                if (modelBinding->textures.find(model.textures[primitiveMatTexIdx].source) ==
                    modelBinding->textures.end()) {
                    GLuint texid;
                    glGenTextures(1, &texid);

                    CesiumGltf::Texture &tex = model.textures[primitiveMatTexIdx];
                    CesiumGltf::Image &image = model.images[tex.source];

                    glBindTexture(GL_TEXTURE_2D, texid);
                    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
                    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

                    GLenum format = GL_RGBA;

                    if (image.cesium.channels == 1) {
                        format = GL_RED;
                    } else if (image.cesium.channels == 2) {
                        format = GL_RG;
                    } else if (image.cesium.channels == 3) {
                        format = GL_RGB;
                    } else {
                        // ???
                    }

                    GLenum type = GL_UNSIGNED_BYTE;
                    if (image.cesium.bytesPerChannel == 1) {
                        // ok
                    } else if (image.cesium.bytesPerChannel == 2) {
                        type = GL_UNSIGNED_SHORT;
                    } else {
                        // ???
                    }
                    void *data = image.cesium.pixelData.empty() ? NULL : &image.cesium.pixelData.at(0);
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.cesium.width, image.cesium.height, 0,
                                 format, type, data);
                    modelBinding->textures[tex.source] = texid;
                }

                // set the texture ID
                glprimitive.texid = modelBinding->textures[model.textures[primitiveMatTexIdx].source];
            }

            if(!glprimitive.texid)
                glprimitive.texid = modelBinding->textures[-1];

            binding->primitives.push_back(glprimitive);
        }
    }

    // bind models
    void bindModelNodes(CesiumGltf::Model &model,
                        CesiumGltf::Node &node, GLRendererState *binding, GLNodeBinding &bnode) {

        float mx[16];
        Matrix_identity(mx);
        if (node.matrix.size() == 16) {
            bnode.matrix.resize(16);
            memcpy(&bnode.matrix.at(0), &node.matrix.at(0), sizeof(double)*16u);
        } else if(!node.scale.empty() || !node.rotation.empty() || !node.translation.empty()) {
            bnode.matrix.resize(16);
            Matrix_identity(&bnode.matrix.at(0));

            // Assume Trans x Rotate x Scale order
            if (node.scale.size() == 3) {
                //glScaled(node.scale[0], node.scale[1], node.scale[2]);
                Matrix_scale(&bnode.matrix.at(0), &bnode.matrix.at(0), node.scale[0], node.scale[1], node.scale[2]);
            }

            if (node.rotation.size() == 4) {
                //glRotated(node.rotation[0], node.rotation[1], node.rotation[2], node.rotation[3]);
                Matrix_rotate(&bnode.matrix.at(0), &bnode.matrix.at(0), node.rotation[0], node.rotation[1], node.rotation[2], node.rotation[3]);
            }

            if (node.translation.size() == 3) {
                //glTranslated(node.translation[0], node.translation[1], node.translation[2]);
                Matrix_translate(&bnode.matrix.at(0), &bnode.matrix.at(0), node.translation[0], node.translation[1], node.translation[2]);
            }
        }

        auto it = binding->gMeshState.find(node.mesh);
        if (it != binding->gMeshState.end()) {
            bnode.meshes.push_back(it->second);
        }

        bnode.children.resize(node.children.size());
        for (size_t i = 0; i < node.children.size(); i++) {
            bindModelNodes(model, model.nodes[node.children[i]], binding, bnode.children[i]);
        }
    }

    int getPrimitiveTexture(CesiumGltf::Model &model, CesiumGltf::MeshPrimitive &primitive)
    {
        if(model.textures.empty())
            return -1; // no textures
        if(primitive.material < 0)
            return -1; // primitive has no material
        if(model.materials.size() < primitive.material)
            return -1; // material is not valid
        auto material = model.materials[primitive.material];
        const int primitiveMatTexIdx = material.pbrMetallicRoughness.has_value() && material.pbrMetallicRoughness.value().baseColorTexture.has_value() ?
                material.pbrMetallicRoughness.value().baseColorTexture.value().index : 0;
        if(primitiveMatTexIdx < 0)
            return -1;
        if(model.textures.size() < primitiveMatTexIdx)
            return -1; // texture is not valid
        return primitiveMatTexIdx;
    }
}
