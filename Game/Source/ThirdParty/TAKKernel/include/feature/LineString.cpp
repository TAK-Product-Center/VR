////============================================================================
////
////    FILE:           LineString.cpp
////
////    DESCRIPTION:    Implementation of LineString class.
////
////    AUTHOR(S):      scott           scott_barrett@partech.com
////
////
////    HISTORY:
////
////      DATE          AUTHOR          COMMENTS
////      ------------  --------        --------
////      Dec 10, 2014  scott           Created.
////
////========================================================================////
////                                                                        ////
////    (c) Copyright 2014 PAR Government Systems Corporation.              ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    INCLUDES AND MACROS                                                 ////
////                                                                        ////
////========================================================================////


#include "feature/LineString.h"

#include <cstdint>
#include <ostream>

#include "util/IO.h"


#define MEM_FN( fn )    "atakmap::feature::LineString::" fn ": "


////========================================================================////
////                                                                        ////
////    USING DIRECTIVES AND DECLARATIONS                                   ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    EXTERN DECLARATIONS                                                 ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    FILE-SCOPED TYPE DEFINITIONS                                        ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    EXTERN VARIABLE DEFINITIONS                                         ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    FILE-SCOPED VARIABLE DEFINITIONS                                    ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    FILE-SCOPED FUNCTION DEFINITIONS                                    ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    EXTERN FUNCTION DEFINITIONS                                         ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    PRIVATE INLINE MEMBER FUNCTION DEFINITIONS                          ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    PUBLIC MEMBER FUNCTION DEFINITIONS                                  ////
////                                                                        ////
////========================================================================////


namespace atakmap                       // Open atakmap namespace.
{
namespace feature                       // Open feature namespace.
{

void
LineString::addPoint (double x,
                      double y)
  {
    if(points.size() == 0)
        envelope.dirty = true;

    points.push_back (x);
    points.push_back (y);
    if (getDimension () == _3D)
      {
        points.push_back (0);
      }
    if (x < envelope.value.minX) envelope.value.minX = x;
    else if (x > envelope.value.maxX) envelope.value.maxX = x;
    if (y < envelope.value.minY) envelope.value.minY = y;
    else if (y > envelope.value.maxY) envelope.value.maxY = y;
    ++count;
  }

void
LineString::addPoint (double x,
                      double y,
                      double z)
  {
    if (getDimension () == _2D)
      {
        throw std::out_of_range (MEM_FN ("addPoint")
                                 "Can't add 3D point to 2D string");
      }

      if(points.size() == 0)
          envelope.dirty = true;

    points.push_back (x);
    points.push_back (y);
    points.push_back (z);
    if (x < envelope.value.minX) envelope.value.minX = x;
    else if (x > envelope.value.maxX) envelope.value.maxX = x;
    if (y < envelope.value.minY) envelope.value.minY = y;
    else if (y > envelope.value.maxY) envelope.value.maxY = y;
    if (z < envelope.value.minZ) envelope.value.minZ = z;
    else if (z > envelope.value.maxZ) envelope.value.maxZ = z;
    ++count;
  }

void
LineString::addPoint (Point point)
  {
    if (point.getDimension () == _3D && getDimension () == _2D)
      {
        throw std::out_of_range (MEM_FN ("addPoint")
                                 "Can't add 3D point to 2D string");
      }

    if(points.size() == 0)
        envelope.dirty = true;
    points.push_back (point.x);
    points.push_back (point.y);
    if (point.x < envelope.value.minX) envelope.value.minX = point.x;
    else if (point.x > envelope.value.maxX) envelope.value.maxX = point.x;
    if (point.y < envelope.value.minY) envelope.value.minY = point.y;
    else if (point.y > envelope.value.maxY) envelope.value.maxY = point.y;
    if (getDimension () == _3D)
      {
        points.push_back (point.z);     // Should be 0 if point is _2D.
        if (point.z < envelope.value.minZ) envelope.value.minZ = point.z;
        else if (point.z > envelope.value.maxZ) envelope.value.maxZ = point.z;
      }
    ++count;
  }

Point
LineString::getPoint (std::size_t index)
    const
  {
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("getX") "Index out of range");
      }

    auto iter
        (points.begin () + index * getDimension ());

    return getDimension () == _2D
        ? Point (*iter, *(iter + 1))
        : Point (*iter, *(iter + 1), *(iter + 2));
  }

double
LineString::getX (std::size_t index)
    const
  {
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("getX") "Index out of range");
      }

    return points[index * getDimension ()];
  }



double
LineString::getY (std::size_t index)
    const
  {
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("getY") "Index out of range");
      }

    return points[index * getDimension () + 1];
  }

double
LineString::getZ (std::size_t index)
    const
  {
    if (getDimension () == _2D)
      {
        throw std::out_of_range (MEM_FN ("getZ") "No Z values in 2D string");
      }
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("getZ") "Index out of range");
      }

    return points[index * getDimension () + 2];
  }

const double *
LineString::getPoints ()
    const
  {
    return points.empty() ? nullptr : &points.at(0);
  }
void
LineString::setPoint (std::size_t index,
                      const Point& point)
  {
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("setPoint") "Index out of range");
      }
    if (point.getDimension () == _3D && getDimension () == _2D)
      {
        throw std::out_of_range (MEM_FN ("setPoint")
                                 "Can't set 3D point in 2D string");
      }

    auto iter
        (points.begin () + index * getDimension ());

    const double ox = *iter;
    *iter = point.x;
    const double oy = *iter;
    *++iter = point.y;
    envelope.dirty |=
        (ox == envelope.value.minX || ox == envelope.value.maxX) ||
        (oy == envelope.value.minY || oy == envelope.value.maxY);
    if (point.x < envelope.value.minX) envelope.value.minX = point.x;
    else if (point.x > envelope.value.maxX) envelope.value.maxX = point.x;
    if (point.y < envelope.value.minY) envelope.value.minY = point.y;
    else if (point.y > envelope.value.maxY) envelope.value.maxY = point.y;
    if (getDimension () == _3D)
      {
        const double oz = *iter;
        *++iter = point.z;              // Should be 0 if point is _2D.
        envelope.dirty |= (oz == envelope.value.minZ || oz == envelope.value.maxZ);
        if (point.z < envelope.value.minZ) envelope.value.minZ = point.z;
        else if (point.z > envelope.value.maxZ) envelope.value.maxZ = point.z;
      }
  }

void
LineString::setX (std::size_t index,
                  double value)
  {
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("setX") "Index out of range");
      }

    auto &pointsx = points[index * getDimension ()];
    envelope.dirty |= (pointsx == envelope.value.minX || pointsx == envelope.value.maxX);
    pointsx = value;
    if (value < envelope.value.minX) envelope.value.minX = value;
    else if (value > envelope.value.maxX) envelope.value.maxX = value;
  }

void
LineString::setY (std::size_t index,
                  double value)
  {
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("setY") "Index out of range");
      }

    auto& pointsy = points[index * getDimension() + 1];
    envelope.dirty |= (pointsy == envelope.value.minY || pointsy == envelope.value.maxY);
    pointsy = value;
    if (value < envelope.value.minY) envelope.value.minY = value;
    else if (value > envelope.value.maxY) envelope.value.maxY = value;
  }

void
LineString::setZ (std::size_t index,
                  double value)
  {
    if (getDimension () == _2D)
      {
        throw std::out_of_range (MEM_FN ("setZ") "No Z values in 2D string");
      }
    if (index >= count)
      {
        throw std::out_of_range (MEM_FN ("setZ") "Index out of range");
      }

    auto &pointsz = points[index * getDimension () + 2];
    envelope.dirty |= (pointsz == envelope.value.minZ || pointsz == envelope.value.maxZ);
    pointsz = value;
    if (value < envelope.value.minZ) envelope.value.minZ = value;
    else if (value > envelope.value.maxZ) envelope.value.maxZ = value;
  }


void
LineString::addPoints (const double* begin,
                       const double* end,
                       Dimension dim)
  {
    if (dim > getDimension ())
      {
        throw std::out_of_range (MEM_FN ("addPoints")
                                 "Can't add 3D points to 2D string");
      }

    std::ptrdiff_t coordCount (end - begin);

    if (coordCount < 0 || coordCount % dim != 0)
      {
        throw std::invalid_argument (MEM_FN ("addPoints")
                                     "Invalid coordinate range");
      }
    if (dim == getDimension ())
      {
        points.insert<const double*> (points.end (), begin, end);
        envelope.dirty = true;
      }
    else                                // dim == _2D, dimension == _3D
      {
        //
        // Need to append 0 for z values.
        //

        if(points.size() == 0)
            envelope.dirty = true;

        while (begin < end)
          {
            const double x = *begin++;
            const double y = *begin++;
            points.push_back (x);
            points.push_back (y);
            points.push_back (0);
            if (x < envelope.value.minX) envelope.value.minX = x;
            else if (x > envelope.value.maxX) envelope.value.maxX = x;
            if (y < envelope.value.minY) envelope.value.minY = y;
            else if (y > envelope.value.maxY) envelope.value.maxY = y;
          }
      }
    count += (coordCount / dim);
  }


bool
LineString::isClosed ()
    const
    NOTHROWS
  {
    bool closed (false);

    if (count)
      {
        auto head (points.begin ());
        auto tail (points.end () - getDimension ());

        closed = getDimension () == _2D
            ? *head == *tail && *++head == *++tail
            : *head == *tail && *++head == *++tail && *++head ==*++tail;
      }

    return closed;
  }


///
///  atakmap::feature::Geometry member functions.
///


Envelope
LineString::getEnvelope ()
    const
  {
    if (points.empty ())
      {
        //throw std::length_error (MEM_FN ("getEnvelope") "Empty line string");
        return Envelope(0, 0, 0, 0, 0, 0);
      }

    if (!envelope.dirty)
        return envelope.value;
    auto iter (points.begin ());
    double minX (*iter++);
    double minY (*iter++);
    double minZ (getDimension () == _3D ? *iter++ : 0);
    double maxX (minX);
    double maxY (minY);
    double maxZ (minZ);
    const std::vector<double>::const_iterator end (points.end ());

    if (getDimension () == _2D)
      {
        while (iter != end)
          {
            if (*iter < minX)           { minX = *iter; }
            else if (*iter > maxX)      { maxX = *iter; }
            iter++;
            if (*iter < minY)           { minY = *iter; }
            else if (*iter > maxY)      { maxY = *iter; }
            iter++;
          }
      }
    else
      {
        while (iter != end)
          {
            if (*iter < minX)           { minX = *iter; }
            else if (*iter > maxX)      { maxX = *iter; }
            iter++;
            if (*iter < minY)           { minY = *iter; }
            else if (*iter > maxY)      { maxY = *iter; }
            iter++;
            if (*iter < minZ)           { minZ = *iter; }
            else if (*iter > maxZ)      { maxZ = *iter; }
            iter++;
          }
      }

    envelope.value = Envelope (minX, minY, minZ, maxX, maxY, maxZ);
    envelope.dirty = false;
    return envelope.value;
  }


void
LineString::toBlob (std::ostream& strm,
                    BlobFormat format)
    const
  {
    Dimension dim (getDimension ());

    switch (format)
      {
      case GEOMETRY:

        insertBlobHeader (strm, getEnvelope ());
        util::write<uint32_t> (strm, dim == _2D ? 2 : 1002);
        break;

      case ENTITY:

        strm.put (ENTITY_START_BYTE);
        util::write<uint32_t> (strm, dim == _2D ? 2 : 1002);
        break;

      default:

        break;
      }

    util::write<uint32_t> (strm, static_cast<uint32_t>(count));
    if(count)
        strm.write (reinterpret_cast<const char*> (&*points.begin ()),
                    points.size () * sizeof (double));

    if (format == GEOMETRY)
      {
        strm.put (BLOB_END_BYTE);
      }
  }


void
LineString::toWKB (std::ostream& strm,
                   bool includeHeader)
    const
  {
    if (includeHeader)
      {
        util::write<uint32_t> (strm.put (util::ENDIAN_BYTE),
                               getDimension () == _2D ? 2 : 1002);
      }
    util::write<uint32_t> (strm, static_cast<uint32_t>(count));
    if(count)
        strm.write (reinterpret_cast<const char*> (&*points.begin ()),
                points.size () * sizeof (double));
  }


}                                       // Close feature namespace.
}                                       // Close atakmap namespace.


////========================================================================////
////                                                                        ////
////    PROTECTED MEMBER FUNCTION DEFINITIONS                               ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    PRIVATE MEMBER FUNCTION DEFINITIONS                                 ////
////                                                                        ////
////========================================================================////


namespace atakmap                       // Open atakmap namespace.
{
namespace feature                       // Open feature namespace.
{


///
///  atakmap::feature::Geometry member functions.
///


void
LineString::changeDimension (Dimension dim)
  {
    if(!points.empty())
    {
      // XXX - optimize
      std::vector<double> newPoints (count * dim);
      double *src = points.data();
      double *dst = newPoints.data();
      double pt[3];
      pt[2u] = 0.0;
      for(std::size_t i = 0; i < count; i++) {
        memcpy(pt, src, sizeof(double)*getDimension());
        memcpy(dst, pt, sizeof(double)*dim);
        src += getDimension();
        dst += dim;
      }
      points.swap (newPoints);

      // XXX -
    }
  }


///
///  atakmap::feature::Geometry member functions.
///


std::size_t
LineString::computeWKB_Size()
    const
  {
    return util::WKB_HEADER_SIZE
        + sizeof(uint32_t)
        + sizeof(double) * points.size();
  }


}                                       // Close feature namespace.
}                                       // Close atakmap namespace.
