#ifndef PGSC_METADATAENCODE_C_H
#define PGSC_METADATAENCODE_C_H

#include "mediametadatadecode_c.h"

#ifdef __cplusplus 
extern "C" {
#endif

int MediaMetadataEncode_encodeKLV(KLVData *klv,
                                  const DecodedMetadataItem **decoded,
                                  const int len);

void MediaMetadataEncode_releaseEncodedKLVData(const KLVData *klv);


#ifdef __cplusplus 
}
#endif

#endif