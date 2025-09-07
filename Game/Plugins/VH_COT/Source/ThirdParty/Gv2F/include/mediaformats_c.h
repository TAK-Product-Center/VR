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

#ifndef PGSC_MEDIAFORMATS_C_H
#define PGSC_MEDIAFORMATS_C_H

#ifdef __cplusplus 
extern "C" {
#endif

typedef enum {
    FORMAT_VIDEO,
    FORMAT_KLV,
} MediaFormatType;

typedef enum {
    /**
     * Video returns RGB format data in 3
     * data planes, R first, then G, then B
     */
    PIXELS_RGB=0,  

    /**
     * Video returns YUV format data in
     * 3 data planes, Y first, then U,
     * then V.  The U & V chroma planes  
     * are half-width and half-height.               
     */
    PIXELS_YUV_420,   
    /**
     * Video returns RGB format data packed
     * as 8-bit samples in 32-bit quantities
     * in a single plane.
     * Layout is:
     *         X        R        G      B
     * Bit: 31 .. 24 23 .. 16 15 .. 8 7 .. 0
     * Bit 31 = most significant,
     * Bit 0 = least significant 
     * "X" bits must be ignored - they
     * can have any value.
     * Note that these are written as true
     * 32-bit units! If you attempt to use
     * the individual color values by byte
     * access, they will be found in
     * the native endian order of a 32-bit
     * quantity on your platform.            
     */
    PIXELS_RGB_PACKED,
    /**
     * Video returns RGB format data packed
     * as 8-bit samples in a single data plane
     * with the order B-G-R.  That is, for
     * a given offset 'x' into the data plane:
     * if (x % 3) == 0, offset x is B data
     * if (x % 3) == 1, offset x is G data
     * if (x % 3) == 2, offset x is R data           
     */
    PIXELS_BGR8_PACKED,   
    /**
     * Video returns YUV format data in
     * 3 data planes, Y first, then U, then V.
     * The U & V chroma planes are half-width.
     * 8-bit samples with a JPEG-based YUV
     * color space.        
     */
    PIXELS_YUV_422J, 
    /**
     * Video returns YUV format data in
     * 3 data planes, Y first, then U,
     * then V.  The U & V chroma planes
     * are half-width and half-height.
     * 8-bit samples with a JPEG-based YUV
     * color space.            
     */
    PIXELS_YUV_420J, 
    /**
      * Video returns YVU420 Semi-Planar format
      * data in 2 planes. 8-bit samples.
      */
    PIXELS_NV21,
    /**
      * Video returns YUV420 Semi-Planar format
      * data in 2 planes. 8-bit samples.
      */
    PIXELS_NV12,
    /**
      * Video returns packed format data in 1 plane with
      * 8-bit samples. The samples are ordered Y, U, Y, V.
      * The U and V have half as many samples horizontally
      * as Y does.
      */
    PIXELS_YUYV,
} MediaPixelFormat;

typedef struct MediaFormat_C_s {
    MediaFormatType format_type;
    int track_num;
} MediaFormat_C;

/*
 * Format description for video tracks.
 */
typedef struct VideoMediaFormat_C_s {
    MediaFormatType format_type;
    int track_num;

    MediaPixelFormat frame_format;
    float aspect_ratio;
    int frame_width;
    int frame_height;
} VideoMediaFormat_C;

typedef struct VideoEncodingFormat_C_s {
    MediaFormatType format_type;
    int track_num;

    MediaPixelFormat frame_format;
    float aspect_ratio;
    int frame_width;
    int frame_height;

    int bit_rate;
    float frame_rate;
} VideoEncodingFormat_C;

typedef struct KLVEncodingFormat_C_s {
    MediaFormatType format_type;
    int track_num;

    int synchronous;                      // 0 if false, 1 if true
} KLVEncodingFormat_C;

#ifdef __cplusplus 
}; // End of extern C
#endif

#endif
