////============================================================================
////
////    FILE:           AttributeSet.h
////
////    DESCRIPTION:    A class that provides a mapping of names to one of a set
////                    of value types.
////
////    AUTHOR(S):      scott           scott_barrett@partech.com
////
////
////    HISTORY:
////
////      DATE          AUTHOR          COMMENTS
////      ------------  --------        --------
////      Jan 15, 2015  scott           Created.
////      Feb 9, 2018   joe b.          See improvements.
////
////========================================================================////
////                                                                        ////
////    (c) Copyright 2015 PAR Government Systems Corporation.              ////
////                                                                        ////
////========================================================================////

/*
 Improvments:
    - AttributeSet has one member: unordered_map<std::string, std::shared_ptr<AttrItem>> for all items
    - Created AttrItem base and concrete types
    - Since attr items are all immutable, copying an attribute set is trivial (relies on std::shared_ptr<>).
    - Rely on built-in copy and move constructors
 */


#ifndef ATAKMAP_UTIL_ATTRIBUTE_SET_H_INCLUDED
#define ATAKMAP_UTIL_ATTRIBUTE_SET_H_INCLUDED


////========================================================================////
////                                                                        ////
////    INCLUDES AND MACROS                                                 ////
////                                                                        ////
////========================================================================////


#include <algorithm>
#include <cstdint>
#include <cstring>
#include <functional>
#include <iterator>
#include <map>
#include <memory>
#include <sstream>
#include <utility>
#include <vector>
#include <unordered_map>

#include "port/Platform.h"
#include "util/StringMap.h"

////========================================================================////
////                                                                        ////
////    FORWARD DECLARATIONS                                                ////
////                                                                        ////
////========================================================================////

////========================================================================////
////                                                                        ////
////    TYPE DEFINITIONS                                                    ////
////                                                                        ////
////========================================================================////


namespace atakmap                       // Open atakmap namespace.
{
namespace util                          // Open util namespace.
{

class ENGINE_API AttributeSet
  {


                                        //====================================//
  public:                               //                      PUBLIC        //
                                        //====================================//


    //==================================
    //  PUBLIC NESTED TYPES
    //==================================


    enum Type
      {
        INT,
        LONG,
        DOUBLE,
        STRING,
        BLOB,
        ATTRIBUTE_SET,
        INT_ARRAY,
        LONG_ARRAY,
        DOUBLE_ARRAY,
        STRING_ARRAY,
        BLOB_ARRAY
      };

    typedef std::pair<const unsigned char*, const unsigned char*>       Blob;
    typedef std::pair<const int*, const int*>                   IntArray;
    typedef std::pair<const int64_t*, const int64_t*>                 LongArray;
    typedef std::pair<const double*, const double*>             DoubleArray;
    typedef std::pair<const char* const*, const char* const*>   StringArray;
    typedef std::pair<const Blob*, const Blob*>                 BlobArray;


    //==================================
    //  PUBLIC INTERFACE
    //==================================


    ~AttributeSet()
        NOTHROWS;

    //
    // Clears all attributes.
    //
    void
    clear ();

    bool
    containsAttribute (const char* key)
        const
        NOTHROWS
      { return attrItems.find(key) != attrItems.end(); }

    std::vector<const char*>
    getAttributeNames ()
        const
        NOTHROWS;

    //
    // Returns the AttributeSet attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not an AttributeSet.
    //
    const AttributeSet&
    getAttributeSet (const char* attributeName)
        const;

    //
    // Returns the AttributeSet attribute with the supplied attributeName via
    // the specified shared_ptr reference.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not an AttributeSet.
    //
    void
    getAttributeSet(std::shared_ptr<AttributeSet> &value,
                    const char *attributeName);

    //
    // Returns the type of the attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName.
    //
    Type
    getAttributeType (const char* attributeName)
        const;

    //
    // Returns the Blob attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a Blob.
    //
    Blob
    getBlob (const char* attributeName)
        const;

    //
    // Returns the BlobArray attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a BlobArray.
    //
    BlobArray
    getBlobArray (const char* attributeName)
        const;

    //
    // Returns the double attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a double.
    //
    double
    getDouble (const char* attributeName)
        const;

    //
    // Returns the double array attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a double array.
    //
    DoubleArray
    getDoubleArray (const char* attributeName)
        const;

    //
    // Returns the int attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a int.
    //
    int
    getInt (const char* attributeName)
        const;

    //
    // Returns the int array attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a int array.
    //
    IntArray
    getIntArray (const char* attributeName)
        const;

    //
    // Returns the int64_t attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a int64_t.
    //
    int64_t
    getLong (const char* attributeName)
        const;

    //
    // Returns the int64_t array attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a int64_t array.
    //
    LongArray
    getLongArray (const char* attributeName)
        const;

    //
    // Returns the string attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a string.
    //
    const char*
    getString (const char* attributeName)
        const;

    //
    // Returns the string array attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL or if
    // the AttributeSet does not contain the supplied attributeName or if the
    // attribute is not a string array.
    //
    StringArray
    getStringArray (const char* attributeName)
        const;

    //
    // Removes the attribute with the supplied attributeName.
    //
    // Throw std::invalid_argument if the supplied attributeName is NULL.
    //
    void
    removeAttribute (const char* attributeName);

    //
    // Sets the value of the supplied attributeName to the supplied AttributeSet.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL.
    //
    void
    setAttributeSet (const char* attributeName,
                     const AttributeSet& value);

    //
    // Sets the value of the supplied attributeName to the supplied Blob.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL or if
    // either of the Blob's pointers are NULL.
    //
    void
    setBlob (const char* attributeName,
             const Blob& value);

    //
    // Sets the value of the supplied attributeName to the supplied Blob array.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL or if
    // any of the value's pointers are NULL.
    //
    void
    setBlobArray (const char* attributeName,
                  const BlobArray& value);

    //
    // Sets the value of the supplied attributeName to the supplied double.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL.
    //
    void
    setDouble (const char* attributeName,
               double value);

    //
    // Sets the value of the supplied attributeName to the supplied double array.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL or if
    // either of the value's pointers are NULL.
    //
    void
    setDoubleArray (const char* attributeName,
                    const DoubleArray& value);

    //
    // Sets the value of the supplied attributeName to the supplied integer.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL.
    //
    void
    setInt (const char* attributeName,
            int value);

    //
    // Sets the value of the supplied attributeName to the supplied integer
    // array.  Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL or if
    // either of the value's pointers are NULL.
    //
    void
    setIntArray (const char* attributeName,
                 const IntArray& value);

    //
    // Sets the value of the supplied attributeName to the supplied int64_t.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL.
    //
    void
    setLong (const char* attributeName,
             int64_t value);

    //
    // Sets the value of the supplied attributeName to the supplied int64_t array.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL or if
    // either of the value's pointers are NULL.
    //
    void
    setLongArray (const char* attributeName,
                  const LongArray& value);

    //
    // Sets the value of the supplied attributeName to the supplied string.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName or value is
    // NULL.
    //
    void
    setString (const char* attributeName,
               const char* value);

    //
    // Sets the value of the supplied attributeName to the supplied string array.
    // Replaces any existing value for attributeName.
    //
    // Throws std::invalid_argument if the supplied attributeName is NULL or if
    // any of the value's pointers are NULL.
    //
    void
    setStringArray (const char* attributeName,
                    const StringArray& value);


                                        //====================================//
  protected:                            //                      PROTECTED     //
                                        //====================================//

                                        //====================================//
  private:                              //                      PRIVATE       //
                                        //====================================//


    //==================================
    //  PRIVATE NESTED TYPES
    //==================================

      struct ENGINE_API AttrItem_
      {
          AttributeSet::Type type{ AttributeSet::Type::BLOB };
          std::vector<uint8_t> object;
          bool null{ false };
          std::shared_ptr<AttributeSet> nested;
          struct {
              std::vector<std::string> ref;
              std::vector<const char *> raw;
          } sarray;
          struct {
              std::vector<std::vector<uint8_t>> ref;
              std::vector<Blob> raw;
          } barray;

          union {
              int i;
              int64_t l;
              double d;
          } primitive;

          AttrItem_() = default;
          AttrItem_(const AttrItem_ &other);
          ~AttrItem_() {};

          void reset(const AttributeSet::Type t) NOTHROWS
          {
              type = t;
              sarray.raw.clear();
              sarray.ref.clear();
              barray.raw.clear();
              barray.ref.clear();
              object.clear();
              null = true;
              primitive.l = 0ULL;
          }
      };

    //==================================
    //  PRIVATE IMPLEMENTATION
    //==================================


    static
    bool
    invalidBlob (const Blob& blob);

    static
    bool
    isNULL (const void* ptr);

    void
    throwNotFound (const char* attributeName,
                   const char* attributeType,
                   const char* errHdr)
        const;


    //==================================
    //  PRIVATE REPRESENTATION
    //==================================
#define ATTRSET_CSTRING_KEY 1
#if ATTRSET_CSTRING_KEY
      TAK::Engine::Util::StringMap<AttrItem_> attrItems;
#else
    std::map<std::string, std::shared_ptr<AttrItem>, std::less<>> attrItems;
#endif
  };


}                                       // Close util namespace.
}                                       // Close atakmap namespace.


////========================================================================////
////                                                                        ////
////    EXTERN DECLARATIONS                                                 ////
////                                                                        ////
////========================================================================////


////========================================================================////
////                                                                        ////
////    PUBLIC INLINE DEFINITIONS                                           ////
////                                                                        ////
////========================================================================////


namespace atakmap                       // Open atakmap namespace.
{
namespace util                          // Open util namespace.
{





}                                       // Close util namespace.
}                                       // Close atakmap namespace.


////========================================================================////
////                                                                        ////
////    PROTECTED INLINE DEFINITIONS                                        ////
////                                                                        ////
////========================================================================////


#endif  // #ifndef ATAKMAP_UTIL_ATTRIBUTE_SET_H_INCLUDED
