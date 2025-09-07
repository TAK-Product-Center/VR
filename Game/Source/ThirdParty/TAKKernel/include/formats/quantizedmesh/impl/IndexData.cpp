#include "formats/quantizedmesh/impl/IndexData.h"
#include "formats/quantizedmesh/impl/TerrainData.h"
#include "math/Rectangle2.h"
#include "math/Utils.h"

#include <cassert>


using namespace TAK::Engine;
using namespace TAK::Engine::Formats::QuantizedMesh;
using namespace TAK::Engine::Formats::QuantizedMesh::Impl;

namespace {
    // From Java reference "TriangleIndices"
    struct LocalQuadConsts {
        static const int levelCount = IndexData::QUAD_MAX_LEVEL - IndexData::QUAD_MIN_LEVEL + 1;

        int sizes[levelCount];

        LocalQuadConsts()
        {
            for (int i = 0; i < levelCount; ++i)
                sizes[i] = 1 << (IndexData::QUAD_MAX_LEVEL - i);
        }
    };

    const LocalQuadConsts QUAD_CONSTS;
}


IndexData::IndexData() NOTHROWS :
    totalSize(0),
    triangleCount(0),
    quadtree(Math::Rectangle2<double>(0, 0, 0xFFFF, 0xFFFF), 0u)
{
}

Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::IndexData_deserialize(std::unique_ptr<IndexData> &result, const VertexData &vertexData, Util::DataInput2 &input) NOTHROWS
{
    result.reset(new IndexData());
    return IndexData_deserialize(*result, vertexData, input);
}
Util::TAKErr TAK::Engine::Formats::QuantizedMesh::Impl::IndexData_deserialize(IndexData &result, const VertexData &vertexData, Util::DataInput2 &input) NOTHROWS
{
    Util::TAKErr code = Util::TE_Ok;
    int length = 0;

    {
        code = input.readInt(&result.triangleCount);
        TE_CHECKRETURN_CODE(code);
        bool is32Bit = vertexData.vertexCount > (1 << 16);
        length = result.triangleCount * 3;

        code = Indices_deserialize(result.indices, length, is32Bit, true, input);
        TE_CHECKRETURN_CODE(code);
    }

    double quadtreeMinX = vertexData[result.indices[0]].x;
    double quadtreeMinY = vertexData[result.indices[0]].y;
    double quadtreeMaxX = quadtreeMinX;
    double quadtreeMaxY = quadtreeMinY;
    for(int i = 0; i < length; i += 3) {
        const Math::Vector4<double> a = vertexData[result.indices[i]];
        const Math::Vector4<double> b = vertexData[result.indices[i+1]];
        const Math::Vector4<double> c = vertexData[result.indices[i+2]];

        const double minX = std::min(std::min(a.x, b.x), c.x);
        const double minY = std::min(std::min(a.y, b.y), c.y);
        const double maxX = std::max(std::max(a.x, b.x), c.x);
        const double maxY = std::max(std::max(a.y, b.y), c.y);

        // skip degenerate triangles
        if(minX == maxX || minY == maxY)
            continue;

        if(minX < quadtreeMinX)
            quadtreeMinX = minX;
        if(minY < quadtreeMinY)
            quadtreeMinY = minY;
        if(maxX > quadtreeMaxX)
            quadtreeMaxX = maxX;
        if(maxY > quadtreeMaxY)
            quadtreeMaxY = maxY;
    }
    result.quadtree.bounds.x = quadtreeMinX;
    result.quadtree.bounds.y = quadtreeMinY;
    result.quadtree.bounds.width = quadtreeMaxX-quadtreeMinX;
    result.quadtree.bounds.height = quadtreeMaxY-quadtreeMinY;

    for(int i = 0; i < length; i += 3) {
        const Math::Vector4<double> a = vertexData[result.indices[i]];
        const Math::Vector4<double> b = vertexData[result.indices[i+1]];
        const Math::Vector4<double> c = vertexData[result.indices[i+2]];

        const double minX = std::min(std::min(a.x, b.x), c.x);
        const double minY = std::min(std::min(a.y, b.y), c.y);
        const double maxX = std::max(std::max(a.x, b.x), c.x);
        const double maxY = std::max(std::max(a.y, b.y), c.y);

        // skip degenerate triangles
        if(minX == maxX || minY == maxY)
            continue;

        result.quadtree.push_back(Math::Rectangle2<double>(minX, minY, (maxX-minX), (maxY-minY)), i/3);
    }

    // Total size in memory
    result.totalSize = 8 + 4 + 4 + result.indices.getTotalSize();
    return Util::TE_Ok;
}


int IndexData::get(int i) const
{
    return indices[i];
}
const int IndexData::operator[](int idx) const
{
    return indices[idx];
}

bool IndexData::is32Bit() const
{
    return indices.getIs32Bit();
}

int64_t IndexData::getTotalSize() const
{
    return totalSize;
}

int IndexData::getLength() const
{
    return indices.getLength();
}

const std::vector<int> *IndexData::getTriangleIndices(int level, int x, int y)
{
    const Quadtree *qt = &quadtree;
    // recurse the quadtree to the leaf node that contains the point
    while(qt && !qt->children.empty()) {
        const auto &p = *qt;
        qt = nullptr;
        for(const auto &c : p.children) {
            if(Math::Rectangle2_contains(
                    c.bounds.x, c.bounds.y, c.bounds.x+c.bounds.width, c.bounds.y+c.bounds.height,
                    (double)x, (double)y)) {

                qt = &c;
                break;
            }
        }
    }
    return qt ? &qt->elements.indices : nullptr;
}

IndexData::Quadtree::Quadtree(const Math::Rectangle2<double> &bounds_, const std::size_t depth_) NOTHROWS :
    bounds(bounds_),
    depth(depth_)
{
    constexpr std::size_t limit = 32u;
    elements.bounds.reserve(limit);
    elements.indices.reserve(limit);
}
void IndexData::Quadtree::push_back(const Math::Rectangle2<double> &bounds_, const int triangleIndex) NOTHROWS
{
    constexpr std::size_t limit = 32u;
    constexpr std::size_t maxDepth = 10u;
    if(children.empty()) {
        if(elements.bounds.size() < limit || depth == maxDepth) {
            elements.indices.push_back(triangleIndex);
            elements.bounds.push_back(bounds_);
            return;
        } else {
            // subdivide
            assert(elements.bounds.size() == limit);

            const auto childWidth = bounds.width / 2.0;
            const auto childHeight = bounds.height / 2.0;

            children.reserve(4u);
            children.emplace_back(Math::Rectangle2<double>(bounds.x,              bounds.y,               childWidth, childHeight), depth+1u);
            children.emplace_back(Math::Rectangle2<double>(bounds.x + childWidth, bounds.y,               childWidth, childHeight), depth+1u);
            children.emplace_back(Math::Rectangle2<double>(bounds.x,              bounds.y + childHeight, childWidth, childHeight), depth+1u);
            children.emplace_back(Math::Rectangle2<double>(bounds.x + childWidth, bounds.y + childHeight, childWidth, childHeight), depth+1u);

            for(std::size_t i = 0; i < limit; i++) {
                const auto &elements_bounds = elements.bounds[i];
                const auto element_index = elements.indices[i];
                for(auto &child : children) {
                    if(Math::Rectangle2_intersects(
                            child.bounds.x, child.bounds.y,
                            child.bounds.x+child.bounds.width, child.bounds.y+child.bounds.height,
                            elements_bounds.x, elements_bounds.y,
                            elements_bounds.x+elements_bounds.width, elements_bounds.y+elements_bounds.height,
                            true)) {

                        child.push_back(elements_bounds, element_index);
                    }
                }
            }
            // elements have been transferred to children
            elements.bounds.clear();
            elements.indices.clear();
        }
    }

    for(auto &child : children) {
        if(Math::Rectangle2_intersects(
                child.bounds.x, child.bounds.y,
                child.bounds.x+child.bounds.width, child.bounds.y+child.bounds.height,
                bounds_.x, bounds_.y,
                bounds_.x+bounds_.width, bounds_.y+bounds_.height,
                true)) {

            child.push_back(bounds_, triangleIndex);
        }
    }
}