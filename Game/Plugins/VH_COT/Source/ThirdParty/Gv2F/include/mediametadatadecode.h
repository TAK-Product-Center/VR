/**
 * GV2F
 * Copyright 2011 PAR Government Systems
 *
 * Restricted Rights:
 * Use, reproduction, or disclosure of executable code, application interface
 * (API), source code, or related information is subject to restrictions set
 * forth in the contract and/or license agreement.    The Government's rights
 * to use, modify, reproduce, release, perform, display, or disclose this
 * software are restricted as identified in the purchase contract. Any
 * reproduction of computer software or portions thereof marked with this
 * legend must also reproduce the markings. Any person who has been provided
 * access to this software must be aware of the above restrictions.
 */

#ifndef PGSC_MEDIAMETADATADECODE_H
#define PGSC_MEDIAMETADATADECODE_H

#include <map>

#include "mediametadatadecode_c.h"
#include "mediaexception.h"

namespace PGSCMedia {

/**
 * Interface for decoding and managing metadata that is encountered in the
 * stream.
 *
 * <P>A static function is provided for parsing and decoding KLV data into its
 * constituent items. The decoded items will have defined value types, both
 * semantically and syntactically (documentation concerning the format and
 * meaning of values associated with specific IDs can be found in the "C"
 * header).
 *
 * <P>Instances of this class will provide identical decoding functionality as
 * well as a data management feature. The class will maintain an internal buffer
 * of encountered metadata items enabling it to report to the user which items
 * have changed as well as maintain copies of the items' data, allowing them to
 * persist longer than the source object; the user may request a given item at
 * any time provided the request is made in a thread-safe manner.
 */
class MediaMetadataDecode {

public:

    /**
     * Creates a new MediaMetadataDecode.
     */
    MediaMetadataDecode()
    {
        cmetadata = MediaMetadataDecode_create();
        if(!cmetadata)
            throw MediaException();
    }

    ~MediaMetadataDecode()
    {
        MediaMetadataDecode_destroy(cmetadata);
    }

    /**
     * Clears the internal metadata buffer.
     */
    void clear()
    {
        MediaMetadataDecode_clear(cmetadata);
    }

    /**
     * Decodes the specified KLVData data and updates the internal metadata
     * buffer. A map containing the items whose values have changed will be
     * returned.  The returned items are live and may be modified or
     * deleted by concurrent calls to 'decode' and 'clear', respectively, so
     * access to the pointers should be made in a thread-safe manner. Since the
     * returned objects are live and not copies, the user is not responsible for
     * releasing the the associated memory.
     *
     * @param klv   KLV data
     *
     * @return  A map containing only those items whose values have changed
     *          since the last call to 'decode'
     */
    const std::map<MetadataItemIDs, const DecodedMetadataItem*> decode(const KLVData *klv)
    {
        const DecodedMetadataItem **decoded;
        int count = MediaMetadataDecode_decode(cmetadata, METADATA_SRCTYPE_KLV, klv, &decoded);
        std::map<MetadataItemIDs, const DecodedMetadataItem*> retval;
        if (count) {
            for(int i = 0; i < count; i++)
                retval[decoded[i]->id] = decoded[i];
            MediaMetadataDecode_releaseDecodedMetadataItemPointerArray(decoded);
        }
        return retval;
    }

    /**
     * Decodes the specified ESDClosedCaptionData data and updates the internal
     * metadata buffer. A map containing the items whose values have changed
     * will be returned.  The returned items are live and may be modified or
     * deleted by concurrent calls to 'decode' and 'clear', respectively, so
     * access to the pointers should be made in a thread-safe manner. Since the
     * returned objects are live and not copies, the user is not responsible for
     * releasing the the associated memory.
     *
     * @param esd   ESD data array, NULL terminated
     *
     * @return  A map containing only those items whose values have changed
     *          since the last call to 'decode'
     */
    const std::map<MetadataItemIDs, const DecodedMetadataItem*> decode(const ESDClosedCaptionData **esd)
    {
        const DecodedMetadataItem **decoded;
        int count = MediaMetadataDecode_decode(cmetadata, METADATA_SRCTYPE_ESD, esd, &decoded);
        std::map<MetadataItemIDs, const DecodedMetadataItem*> retval;
        if (count) {
            for(int i = 0; i < count; i++)
                retval[decoded[i]->id] = decoded[i];
            MediaMetadataDecode_releaseDecodedMetadataItemPointerArray(decoded);
        }
        return retval;
    }

    /**
     * Returns the metadata item with the specified ID from the internal buffer.
     * The returned metadata item is live and may be modified or deleted by
     * concurrent calls to 'decode' and 'clear', respectively, so access to this
     * pointer should be made in a thread-safe manner. Since the returned object
     * is live and not a copy, the user is not responsible for releasing the
     * the associated memory.
     *
     * @param id    An item ID
     *
     * @return  A live reference to the stored metadata item for that ID, or
     *          NULL if that item has not been encountered since the last call
     *          to 'clear'.
     */
    const DecodedMetadataItem* operator[](const MetadataItemIDs id)
    {
        return MediaMetadataDecode_get(cmetadata, id);
    }

    /**
     * Returns a map containing all of the current metadata items from the
     * internal buffer. The returned items are live and may be modified or
     * deleted by concurrent calls to 'decode' and 'clear', respectively, so
     * access to the pointers should be made in a thread-safe manner. Since the
     * returned objects are live and not copies, the user is not responsible for
     * releasing the the associated memory.
     *
     * @return  A map containing live references to the latest values of all
     *          items that have been encountered since the last call to 'clear'.
     */
    const std::map<MetadataItemIDs, const DecodedMetadataItem*> getCurrentItems()
    {
        const DecodedMetadataItem **decoded;
        int count = MediaMetadataDecode_getCurrentItems(cmetadata, &decoded);
        std::map<MetadataItemIDs, const DecodedMetadataItem*> retval;
        for(int i = 0; i < count; i++)
            retval[decoded[i]->id] = decoded[i];
        if(count)
            MediaMetadataDecode_releaseDecodedMetadataItemPointerArray(decoded);
        return retval;
    }


    /**
     * Decodes the specified KLVData data and returns the decoded items in the
     * specified array. The returned array is valid until released by the user,
     * however, the 'raw' member of each item is only guaranteed to be valid
     * while 'klv' is valid. For example, if this function is invoked during a
     * 'mediaKLVData' callback, any access to the 'raw' member for any array
     * element must be made before the callback returns.
     *
     * <P>The returned array must be released by the user by invoking the
     * function 'releaseDecodedMetadataItemArray'. If the returned count
     * is zero, the returned array is invalid and cannot be accessed
     * and also should not be released.
     *
     * @param klv       KLV data
     * @param decoded   Returns an array of decoded metadata items
     *
     * @return  The number of elements in the array.
     */
    static int decodeKLV(const KLVData *klv, const DecodedMetadataItem **decoded)
    {
        return MediaMetadataDecode_decodeKLV(klv, decoded);
    }

    /**
     * Decodes the specified ESDClosedCaptionData data and returns the decoded
     * items in the specified array. The returned array is valid until released
     * by the user, however, the 'raw' member of each item is only guaranteed to
     * be valid while 'esd' is valid. For example, if this function is invoked
     * during a 'mediaESDData' callback, any access to the 'raw' member for any
     * array element must be made before the callback returns.
     *
     * <P>The returned array must be released by the user by invoking the
     * function 'releaseDecodedMetadataItemArray'. If the returned count
     * is zero, the returned array is invalid and cannot be accessed
     * and also should not be released.
     *
     * @param esd       ESD data array, NULL terminated
     * @param decoded   Returns an array of decoded metadata items
     *
     * @return  The number of elements in the array.
     */
    static int decodeESD(const ESDClosedCaptionData **esd, const DecodedMetadataItem **decoded)
    {
        return MediaMetadataDecode_decodeESD(esd, decoded);
    }

    /**
     * Releases a DecodedMetadataItem array allocated by the library.
     *
     * @param decoded   The array to be released.
     */
    static void releaseDecodedMetadataItemArray(const DecodedMetadataItem *decoded)
    {
        MediaMetadataDecode_releaseDecodedMetadataItemArray(decoded);
    }

private:

    MediaMetadataDecode_C cmetadata;

};

};  // End of namespace

#endif
