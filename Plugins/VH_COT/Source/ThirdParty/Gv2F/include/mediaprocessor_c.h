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

#ifndef PGSC_MEDIAPROCESSOR_C_H
#define PGSC_MEDIAPROCESSOR_C_H

#include <stdint.h>

#include "mediaformats_c.h"
#include "mediaconsumers_c.h"
#include "mediaannotations_c.h"


#ifdef __cplusplus 
extern "C" {
#endif

int PGSCMediaInit(const char *licenseData, unsigned int len);

/* Supported snapshot export file type specifications */
typedef enum {
    JPEG,
    PNG,
} SnapShotFileType;

/* Supported clip extraction and streaming media capture formats */
typedef enum { 
    MEDIATYPE_NATIVE,                 // "As-is" - no transcoding
} MediaFileType;

/* Supported frame skipping flags */
typedef enum {
/* No frames are skipped. */
    FRAMESKIP_NONE,
/* Bidirectional frames (B-Frames) are skipped. */
    FRAMESKIP_BIDIR,
/* Non-key frames are skipped (only I-frames are returned) */
    FRAMESKIP_NONKEY,
/* Frames are parsed but not decoded */
    FRAMESKIP_PARSE_ONLY,
} VideoFrameSkip;

typedef void* MediaProcessor_C;

const char * MediaProcessor_getVersion();

int MediaProcessor_createFromFile(MediaProcessor_C *proc, const char *file);
int MediaProcessor_createFromStream(MediaProcessor_C *proc, 
                                            const char *mcastAddr,
                                            int port,
                                            unsigned int timeout,
                                            long bufferTime,
                                            unsigned long maxByteSize,
                                            const char *tmp_dir,
                                            const char *local_addr);
int MediaProcessor_createFromRtsp(MediaProcessor_C *proc, 
                                            const char *addr,
                                            unsigned int timeout,
                                            long bufferTime,
                                            unsigned long maxByteSize,
                                            const char *tmp_dir);
int MediaProcessor_createFromProcessor(MediaProcessor_C *proc,
                                       MediaProcessor_C sourceProc);
void MediaProcessor_destroyProcessor(MediaProcessor_C proc);


int MediaProcessor_getTrackInfo(MediaProcessor_C proc, MediaFormat_C ***formats);

void MediaProcessor_setVideoConsumer(MediaProcessor_C proc, 
                      int tracknum, VideoConsumer_C *consumer);

void MediaProcessor_setKLVConsumer(MediaProcessor_C proc,
                      int tracknum, KLVConsumer_C *consumer);

void MediaProcessor_setESDConsumer(MediaProcessor_C proc,
                                   ESDConsumer_C *consumer);

void MediaProcessor_setStatusUpdateConsumer(MediaProcessor_C proc,
                      StatusUpdateConsumer_C *consumer);

void MediaProcessor_setMediaConsumer(MediaProcessor_C proc,
                      MediaFileType type, MediaConsumer_C *consumer);

void MediaProcessor_setStreamingBufferDiscardEnabled(MediaProcessor_C proc,
                      int discardEnabled);
    
int MediaProcessor_isStreamingBufferDiscardEnabled(MediaProcessor_C proc);

MediaAnnotations_C MediaProcessor_getAnnotations(MediaProcessor_C proc);
    
long MediaProcessor_getDuration(MediaProcessor_C proc);
    
float MediaProcessor_getBitRate(MediaProcessor_C proc);

float MediaProcessor_getFrameRate(MediaProcessor_C proc);

int MediaProcessor_isStreaming(MediaProcessor_C proc);

void MediaProcessor_setRate(MediaProcessor_C proc, float rate);

float MediaProcessor_getRate(MediaProcessor_C proc);
    
void MediaProcessor_setFrameDiscardEnabled(MediaProcessor_C proc, int discard);
    
int MediaProcessor_getFrameDiscardEnabled(MediaProcessor_C proc);

void MediaProcessor_setFrameSkip(MediaProcessor_C proc, VideoFrameSkip skip);

VideoFrameSkip MediaProcessor_getFrameSkip(MediaProcessor_C proc);
    
long MediaProcessor_setTime(MediaProcessor_C proc, long timeMillis);
    
long MediaProcessor_getTime(MediaProcessor_C proc);

void MediaProcessor_prefetch(MediaProcessor_C proc);

void MediaProcessor_start(MediaProcessor_C proc);

void MediaProcessor_stop(MediaProcessor_C proc);
    
int MediaProcessor_isProcessing(MediaProcessor_C proc);
    
int MediaProcessor_setStopTime(MediaProcessor_C proc, long millis);

int MediaProcessor_extractCurrentFrame(MediaProcessor_C proc, SnapShotFileType type,
                           const char *filename);
    
int MediaProcessor_extractMediaClip(MediaProcessor_C proc, 
                          MediaFileType type, long timeStart, long timeEnd,
                          const char *filename);

const VideoFrameData *MediaProcessor_duplicateFrame(const VideoFrameData *f);
void MediaProcessor_destroyDuplicateFrame(const VideoFrameData *f);

#ifdef __cplusplus 
};  // End of extern C
#endif

#endif
