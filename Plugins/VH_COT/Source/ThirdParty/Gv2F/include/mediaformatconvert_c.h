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

#ifndef PGSC_MEDIAFORMATCONVERT_C_H
#define PGSC_MEDIAFORMATCONVERT_C_H

#include "mediaformats_c.h"
#include "mediaconsumers_c.h"

#ifdef __cplusplus 
extern "C" {
#endif

typedef void* MediaFormatConvert_C;

int MediaFormatConvert_create(MediaFormatConvert_C *conv,
                              VideoMediaFormat_C *fmt,
                              MediaPixelFormat outfmt);
void MediaFormatConvert_destroy(MediaFormatConvert_C conv);

int MediaFormatConvert_setScaleForAspect(MediaFormatConvert_C conv, int en);
int MediaFormatConvert_setScaleOutputSize(MediaFormatConvert_C conv, int w, 
                                                                     int h);
void MediaFormatConvert_getScaleOutputSize(MediaFormatConvert_C conv, int *w, 
                                                                      int *h);
const VideoFrameData *MediaFormatConvert_getOutputFrame(
                                                MediaFormatConvert_C conv);
int MediaFormatConvert_setOutputBuffer(MediaFormatConvert_C conv,
                                       uint8_t *buf, unsigned int bufsize);
unsigned int MediaFormatConvert_getRequiredBufferSize(MediaFormatConvert_C conv);
int MediaFormatConvert_convert(MediaFormatConvert_C conv,
                               const VideoFrameData *frame);

#ifdef __cplusplus 
};  // End of extern C
#endif

#endif
