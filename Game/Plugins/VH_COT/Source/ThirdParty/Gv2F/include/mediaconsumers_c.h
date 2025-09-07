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

#ifndef PGSC_MEDIACONSUMERS_C_H
#define PGSC_MEDIACONSUMERS_C_H

#include <stdint.h>
#include "mediaformats_c.h"
#include "mediaannotations_type_c.h"

#ifdef __cplusplus 
extern "C" {
#endif

/*
 * Data structure presented to video consumers, representing a single
 * frame of decoded data.
 */
typedef struct VideoFrameData_s {
    /*
     * Pixel format of the frame.
     */
    MediaPixelFormat pixel_format;
    
    /* Width of the frame */
    int width;
    
    /* Height of the frame */
    int height;

    /*
     * Array of decoded video data sample planes.  The number of
     * data planes is intrinsic to the video format of the track
     * from which this data is being produced (see VideoMediaFormat).
     * Within each plane, data elements are ordered row-major, with
     * the top-most row's data first.
     * Each row of data has a number of samples equal to the frame width,
     * unless otherwise noted in the VideoMediaFormat.
     * Each row of data may have some extra data samples at the end - this
     * is indicated by the difference between the line_stride and the
     * frame width; these samples should be skipped.
     * The number of rows is indicated by the frame height, unless
     * otherwise noted in the VideoMediaFormat.  Note that different
     * planes can have different dimensions in some formats - examine
     * carefully the VideoMediaFormat you are working with.
     */
    uint8_t **data;
    
    /*
     * The line strides for each plane of data.  This is the number of
     * samples from one row to the next.  This may differ from actual
     * number of expected/useful samples in the VideoMediaFormat; the 
     * difference indicates the number of samples at the end of each
     * row that should be skipped/discarded.
     */
    int *line_stride;

    /*
     * The timestamp of this frame, in milliseconds from the start
     * of the media.
     */    
    long timestamp_millis;

    /*
     * A set of flags indicating various things about the video frame.
     * One or more of the FRAME_FLAG_* constants OR'd together.
     */
    int flags;
    
} VideoFrameData;

/*
 * Indicate that a frame represents a "key frame", a frame which
 * can be decoded without knowledge of other frames in the source
 * bitstream
 */
#define FRAME_FLAG_KEY 0x00000001


/*
 * Data structure presented to consumers of KLV data.
 */
typedef struct KLVData_s {
    /*
     * The 16-byte KLV key.
     */
    uint8_t *key;
    
    /*
     * The length, in number of bytes, of the value array.
     * May be 0, in which case there is no value.
     */
    unsigned int length;
    
    /*
     * The value of the KLV item. The number of elements in the array
     * is indicated by length. 
     */
    uint8_t *value;

    
    /*
     * The timestamp of this frame, in milliseconds from start of the media.
     */    
    long timestamp_millis;
} KLVData;

/*
 * Data structure presented to consumers of ESD Closed-Caption metadata.
 */
typedef struct ESDClosedCaptionData_s {
    /*
     * The 2-character ESD key. The key string is NOT null terminated.
     */
    uint8_t *key;
    
    /*
     * The length, in number of characters, of the value array.
     * May be 0, in which case there is no value.
     */
    unsigned int length;
    
    /*
     * The value of the ESD closed-caption metadata item. The number of elements
     * in the array is indicated by length. The value string is NOT null
     * terminated.
     */
    uint8_t *value;

    /*
     * The timestamp of the associated frame, in milliseconds from start of the
     * media.
     */    
    long timestamp_millis;
} ESDClosedCaptionData;

typedef struct VideoConsumer_C_s {
    void *opaque;
    void (*mediaVideoFrame)(void *opaque, const VideoFrameData *frame);
} VideoConsumer_C;


typedef struct KLVConsumer_C_s {
    void *opaque;
    void (*mediaKLVData)(void *opaque, KLVData *data);
} KLVConsumer_C;

typedef struct ESDConsumer_C_s {
    void *opaque;
    void (*mediaESDData)(void *opaque, const ESDClosedCaptionData **esd,
                         int len);
} ESDConsumer_C;

typedef struct MediaConsumer_C_s {
    void *opaque;
    void (*mediaBytes)(void *opaque, int length, const uint8_t *bytes);
} MediaConsumer_C;

typedef struct StatusUpdateConsumer_C_s {
    void *opaque;
    void (*mediaStreamExtentsUpdate)(void *opaque, long startMillis, 
                                     long endMillis);
    void (*mediaEOF)(void *opaque);
    void (*mediaFatalError)(void *opaque, const char *info);
} StatusUpdateConsumer_C;

typedef struct AnnotationUpdateConsumer_C_s {
    void *opaque;
    void (*annotationsAdded)(void *opaque, const MediaAnnotation **annos,
                             int len);
    void (*annotationsDeleted)(void *opaque, const MediaAnnotation **annos,
                               int len);
    void (*annotationsAllDeleted)(void *opaque);
    void (*annotationsUpdating)(void *opaque, const MediaAnnotation **annos,
                                int len);
    void (*annotationsUpdated)(void *opaque, const MediaAnnotation **annos,
                               int len);
} AnnotationUpdateConsumer_C;

#ifdef __cplusplus 
};  // End extern C
#endif

#endif
