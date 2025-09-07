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

#ifndef PGSC_MEDIAMETADATAENCODE_H
#define PGSC_MEDIAMETADATAENCODE_H

#include "mediaexception.h"

#include "mediametadataencode_c.h"

namespace PGSCMedia {

/**
 * Interface for metadata encoding.
 *
 * <P>The library currently supports encoding the following KLV Sets/Packs:
 * <UL>
 *  <LI>MISB Standard 0601, UAS Datalink Local Metadata Set - 060E2B34020B01010E01030101000000</LI>
 *  <LI>MISB EG 0104, Predator UAV Basic Universal Metadata Set - 060E2B34020101010E01010201010000</LI>
 *  <LI>MISB Standard 0102, Security Metadata Universal Set - 060E2B34020101010208020000000000</LI>
 *  <LI>MISB Standard 0102, Security Metadata Local Set - 060E2B34020301010E01030302000000</LI>
 * </UL>
 */
class MediaMetadataEncode {

private :
    MediaMetadataEncode() {}
    ~MediaMetadataEncode() {}

public:

    /**
     * Encodes the specified DecodedMetadataItem instances as KLV. The 'key'
     * member of the specified KLVData shall be set by the user to one of the
     * keys supported for encoding by the library.
     *
     * @param klv       Returns the encoded metadata. The 'key' member should be
     *                  set by the user to one of the keys supported for
     *                  encoding by the library. The library will set the
     *                  'length' and 'value' members before the function
     *                  returns. If the function returns successfully and
     *                  'length' is non-zero, the user must pass 'klv' to
     *                  MediaMetadataEncode::releaseEncodedKLVData when the
     *                  KLVData is no longer needed to release the memory
     *                  allocated by the library.
     * @param decoded   An array of DecodedMetadataItem pointers to be encoded
     *                  as KLV
     * @param len       The number of elements in the 'decoded' array.
     *
     * @throws MediaException   thrown if the metadata cannot be encoded. This
     *                          will occur if the specified key is not supported
     *                          or if none of the specified items can be encoded
     *                          as part of the pack/set defined by the key.
     */
    static void encodeKLV(KLVData *klv, const DecodedMetadataItem **decoded, const int len) throw (MediaException)
    {
        int err = MediaMetadataEncode_encodeKLV(klv, decoded, len);
        if(err)
            throw MediaException();
    }

    /**
     * Releases the KLVData's value allocated by the library.
     *
     * @param klv   The KLVData whose 'value' member was allocated by the
     *              library
     */
    static void releaseEncodedKLVData(const KLVData* klv)
    {
        MediaMetadataEncode_releaseEncodedKLVData(klv);
    }

private:

};

};

#endif
