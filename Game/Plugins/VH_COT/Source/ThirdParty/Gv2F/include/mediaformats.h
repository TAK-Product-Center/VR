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

#ifndef PGSC_MEDIAFORMATS_H
#define PGSC_MEDIAFORMATS_H

#include "mediaformats_c.h"

namespace PGSCMedia {


/*
 * Base format descriptor, giving essential details about one track in a
 * media file/stream.
 */
struct MediaFormat {
    typedef enum {
        FORMAT_VIDEO,                  // Indicates VideoMediaFormat subclass
        FORMAT_KLV,
    } MediaFormatType;
   
    /* The type of format, as per above */ 
    const MediaFormatType format_type;
    
    /* The track number that this format describes */
    const int track_num;
    
protected:
    MediaFormat(MediaFormat_C *cf)      : format_type(FORMAT_KLV),
                                          track_num(cf->track_num) {}
    MediaFormat(VideoMediaFormat_C *cf) : format_type(FORMAT_VIDEO),
                                          track_num(cf->track_num) {}
    MediaFormat(MediaFormatType type, int track) : 
                                          format_type(type),
                                          track_num(track) {}

    friend class MediaProcessor;
    friend class KLVEncodingFormat;
};

/*
 * Format description for video tracks.
 */
class VideoMediaFormat : public MediaFormat {
public:

    /*
     * Frame format indication, detailing layout of the data returned
     * to video consumers.
     */
    const MediaPixelFormat frame_format;
    
    /*
     * Intended aspect ratio for display. This ratio describes how the video
     * frame should be scaled from the raw decoded data in order to have the
     * video render as intended. The ratio is that of display width against 
     * raw video width. To compute the display width to scale to,
     * multiply frame_width by aspect_ratio.
     */
    const float aspect_ratio;
    
    /*
     * The width of the raw decoded data. This is the fundamental
     * number of samples in the decoded video data in the horizontal
     * direction. Some videos are intended to be scaled in the horizontal
     * direction before display to achieve a specific aspect ratio (see
     * aspect_ratio).
     */
    const int frame_width;
    
    /*
     * The height of the decoded data.  This is the fundamental number of
     * samples in the vertical direction.
     */
    const int frame_height;

    /* Convert this VideoMediaFormat to a VideoMediaFormat_C */
    void toC(VideoMediaFormat_C *cf) const
    {
        cf->format_type = ::FORMAT_VIDEO;
        cf->track_num = track_num;
        cf->frame_format = frame_format;
        cf->aspect_ratio = aspect_ratio;
        cf->frame_width = frame_width;
        cf->frame_height = frame_height;
    }

    VideoMediaFormat(int track, MediaPixelFormat fmt, float aspect,
                     int w, int h) :
                           MediaFormat(FORMAT_VIDEO, track),
                           frame_format(fmt),
                           aspect_ratio(aspect),
                           frame_width(w),
                           frame_height(h) {}

protected:    
    VideoMediaFormat(VideoMediaFormat_C *cf) :
                           MediaFormat(cf),
                           frame_format((MediaPixelFormat)cf->frame_format),
                           aspect_ratio(cf->aspect_ratio),
                           frame_width(cf->frame_width),
                           frame_height(cf->frame_height) {}

    friend class MediaProcessor;
};

/*
 * Format description for video tracks.
 */
class VideoEncodingFormat : public VideoMediaFormat {
public:

    /**
     * The target bit rate for the video.
     */
    const int bit_rate;

    /**
     * The target frame rate for the video. Currently supported frame rates
     * include:
     * <UL>
     *  <LI>25</LI>
     *  <LI>29.97</LI>
     *  <LI>30</LI>
     *  <LI>50</LI>
     *  <LI>59.97</LI>
     *  <LI>60</LI>
     * </UL>
     */
    const float frame_rate;

    /* Convert this VideoMediaFormat to a VideoMediaFormat_C */
    void toC(VideoEncodingFormat_C *cf) const
    {
        cf->format_type = ::FORMAT_VIDEO;
        cf->track_num = track_num;
        cf->frame_format = frame_format;
        cf->aspect_ratio = aspect_ratio;
        cf->frame_width = frame_width;
        cf->frame_height = frame_height;
        cf->bit_rate = bit_rate;
        cf->frame_rate = frame_rate;
    }

    /**
     * Creates a new VideoEncodingFormat
     * 
     * @param track     target track number
     * @param fmt       target pixel format
     * @param aspect    target aspect ratio
     * @param w         target raw width (NOT adjusted for aspect ratio)
     * @param h         target raw height (NOT adjusted for aspect ratio)
     * @param br        target bit rate
     * @param fr        target frame rate
     */
    VideoEncodingFormat(int track, MediaPixelFormat fmt, float aspect,
                     int w, int h, int br, float fr) :
                           VideoMediaFormat(track, fmt, aspect, w, h),
                           bit_rate(br),
                           frame_rate(fr) {}

    /**
     * Creates a new VideoEncodingFormat
     * 
     * @param track     target track number
     * @param toCopy    A VideoMediaFormat instance to copy the 'frame_format',
     *                  'aspect_ratio', 'width', and 'height' from
     * @param br        target bit rate
     * @param fr        target frame rate
     */
    VideoEncodingFormat(int track, const VideoMediaFormat *toCopy, int br, float fr) :
                           VideoMediaFormat(track, toCopy->frame_format,
                                            toCopy->aspect_ratio,
                                            toCopy->frame_width,
                                            toCopy->frame_height),
                           bit_rate(br),
                           frame_rate(fr) {}

};

/*
 * Format description for KLV tracks.
 */
class KLVEncodingFormat : public MediaFormat {
public:

    /**
     * Indicates whether or not the KLV should be encoded synchronously.
     */
    const bool synchronous;

    /* Convert this VideoMediaFormat to a VideoMediaFormat_C */
    void toC(KLVEncodingFormat_C *cf) const
    {
        cf->format_type = ::FORMAT_KLV;
        cf->track_num = track_num;
        cf->synchronous = synchronous?1:0;
    }

    /**
     * Creates a new KLVEncodingFormat.
     *
     * @param track     target track number
     * @param sync      if 'true', the KLV will be coded as synchronous in the
     *                  output, otherwise it will be coded as asynchronous
     */
    KLVEncodingFormat(int track, bool sync) :
                           MediaFormat(FORMAT_KLV, track),
                           synchronous(sync) {}

};

};  // End of namespace

#endif
