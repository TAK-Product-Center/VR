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



#ifndef PGSC_MEDIAMULTIPLEXER_C_H
#define PGSC_MEDIAMULTIPLEXER_C_H

#include "mediaformats_c.h"
#include "mediaconsumers_c.h"

#ifdef __cplusplus 
extern "C" {
#endif

typedef struct MultiplexerDataSink_C_s {
    void *opaque;
    int (*dataSinkWrite)(const unsigned char* buf,
                         int len,
                         void* opaque);
} MultiplexerDataSink_C;

typedef void* MediaMultiplexer_C;

MediaMultiplexer_C MediaMultiplexer_create();
int MediaMultiplexer_setNumTracks(MediaMultiplexer_C mux, const int numTracks);
KLVConsumer_C* MediaMultiplexer_setKLVTrack(MediaMultiplexer_C mux, const KLVEncodingFormat_C *outfmt);
VideoConsumer_C* MediaMultiplexer_setVideoTrack(MediaMultiplexer_C mux, const VideoMediaFormat_C *infmt, const VideoEncodingFormat_C *outfmt);
int MediaMultiplexer_setOutputSink(MediaMultiplexer_C mux, const MultiplexerDataSink_C* sink);
int MediaMultiplexer_open(MediaMultiplexer_C mux);
int MediaMultiplexer_destroy(MediaMultiplexer_C mux);

#ifdef __cplusplus 
}; // End of extern C
#endif

#endif
