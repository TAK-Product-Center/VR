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

#ifndef PGSC_MEDIAFORMATCONVERT_H
#define PGSC_MEDIAFORMATCONVERT_H

#include "mediaexception.h"
#include "mediaformatconvert_c.h"
#include "mediaformats.h"
#include "mediaconsumers_c.h"

namespace PGSCMedia {


/**
 * Class to convert VideoFrameData from one MediaPixelFormat to another
 * and/or scale the VideoFrameData's dimensions.
 * 
 * To reduce the number of iterations across the frame data,
 * this class combines several common operations into a single pass over
 * the source data.
 *
 * Major operations performed by this class:
 *
 * 1. Conversion of frame format/color representation.  Typically, video
 *     frames decode to YUV-based formats.  This can convert to a more
 *     user-friendly RGB-based format.
 * 2. Scaling the frame up, down, or stretching for aspect correction.  Many
 *     videos are coded with a narrower width than they are intended to be
 *     displayed, which is reflected in the output aspect ratio of the video
 *     track's format description (see VideoMediaFormat).  This class can
 *     adjust for the aspect ratio or to an arbitrary width/height.  The
 *     default scaling operation is to adjust frames as needed to achieve the
 *     aspect radio indicated by the track format information.
 *
 * As input, this class takes VideoFrameData objects.  The converted and/or
 * scaled output is written to a provided buffer.  Depending on the output
 * PixelFormat, one or more data planes are accessed via offsets into the
 * output array;  these are reflected in the output VideoFrameData's data
 * fields.
 * Each plane has an internal line stride as well, indicating
 * the number elements from any position in a row of the output image to the
 * same position in the next row (this may be greater than the image width,
 * in which case the difference is made by ignoring data beyond the width of
 * the plane). This is also reflected in the output VideoFrameData.
 *
 * Using this class generally involves the following steps:
 * 1. Create an instance, providing the track's VideoMediaFormat
 *     to describe the input frame format and, optionally, a MediaPixelFormat
 *     to which you would like the output converted.
 * 2. Call any of the setXXX methods to configure scaling operations.
 * 3. Call getRequiredBufferSize() to ascertain the size of the buffer
 *     needed for the output format you've configured.
 * 4. Create and supply an appropriately sized buffer via setOutputBuffer().
 * 5. Obtain the VideoFrameData that describes the output by calling 
 *     getOutputFrame();  this frame gets filled in with data on all
 *     subsequent calls to convert() (until you change output dimension
 *     options - see step 7).  The number of data planes in the output frame
 *     is dictated by the output MediaPixelFormat.
 * 6. Each time a frame is to be converted, call convert().  The output is
 *     placed in the previously supplied buffer, broken up into data planes
 *     in the configuration detailed by the output VideoFrameData object.
 * 7. If you need to change output dimension options, you can do so.
 *     Be sure to check the buffer size required by the new configuration
 *     and, if necessary, supply a new output buffer (step 4). At this
 *     point it is necessary to re-acquire the VideoFrameData
 *     object describing the output (step 5) as the frame layout may have
 *     been changed.
 *
 * Threading note: Each MediaFormatConvert object may only be accessed
 * by one thread at a time.
 */
class MediaFormatConvert {
public:
    /**
     * Create a MediaFormatConvert which will convert frames in the
     * supplied source format.  Frames will retain the source MediaPixelFormat.
     * A MediaException will be thrown if a converter object cannot
     * be created for the specific source format.
     * @param inputFormat the format of frames which will be supplied to the
     *                    convert() function for conversion
     */
    MediaFormatConvert(VideoMediaFormat inputFormat) //throw (MediaException)  // WITH_VH
    {
        MediaFormatConvert_C fc;
        VideoMediaFormat_C fmtc;
        inputFormat.toC(&fmtc);
        if (MediaFormatConvert_create(&fc, &fmtc,
                                      fmtc.frame_format))
            throw MediaException();
        cconv = fc;
    }

    /**
     * Create a MediaFormatConvert which will convert frames in the
     * supplied source format.  Frames will be converted to the specified
     * MediaPixelFormat.
     * A MediaException will be thrown if a converter object cannot
     * be created for the specific source or destination format.
     * @param inputFormat the format of frames which will be supplied to the
     *                    convert() function for conversion
     * @param outputFormat the pixel format that output frames should
     *                     be converted to
     */
    MediaFormatConvert(VideoMediaFormat inputFormat,
                       MediaPixelFormat outputFormat) //throw (MediaException)  // WITH_VH
    {
        MediaFormatConvert_C fc;
        VideoMediaFormat_C fmtc;
        inputFormat.toC(&fmtc);
        if (MediaFormatConvert_create(&fc, &fmtc, outputFormat))
            throw MediaException();
        cconv = fc;
    }

    ~MediaFormatConvert()
    {
        MediaFormatConvert_destroy(cconv);
    }
    

    /**
     * This function, along with setScaleOutputSize, controls the scaling
     * component of the convert operation. Specifically, this function
     * enables or disables automatic scaling of the input frames based on
     * the display aspect ratio and coded picture size of the source
     * track's format. If this is enabled (the default mode of operation),
     * any prior call setScaleOutputSize() will no longer impact scaling
     * operation and automatic aspect-ratio based scaling is done.  If this
     * is called with an argument of false, the automatic aspect-ratio scaling
     * is disabled and the scaler is disabled (output data planes will be sized
     * the same as the input frames). setScaleOutputSize() may be
     * subsequently used to set arbitrary sizes to scale to.
     *
     * NOTE: After calling this function, the output buffer size
     * requirement may be different and a new output buffer may have to be
     * supplied. The output frame configuration will also change, and must
     * be reacquired.
     *
     * @param useAspect true to enable aspect-ratio based automatic scaling,
     *                  false to disable aspect-ratio scaling and set scaler
     *                  to output the same size output as frame input
     * @throws MediaException if the converter cannot be configured to scale 
     *                        to the specified size
     */
    void setScaleForAspect(bool en) //throw (MediaException)  // WITH_VH
    {
        if (MediaFormatConvert_setScaleForAspect(cconv, en ? 1 : 0))
            throw MediaException();
    }
    
    /**
     * This function, along with setScaleForAspect(), controls the scaling
     * component of the convert operation. When the automatic aspect-ratio
     * scaling functionality is enabled (the default), calls to this function
     * will do nothing.  When the aspect-ratio scaling function is disabled,
     * calls to this function will configure the scaling component of
     * the convert operation to scale the input frames to the given size
     * before output.
     *
     * Note that for best appearance, sizes should be conform to the
     * video display aspect ratio (given in the video track's
     * VideoMediaFormat).
     *
     * NOTE: After calling this function, the output buffer size
     * requirement may be different and a new output buffer may have to be
     * supplied. The output frame configuration will also change, and must
     * be reacquired.
     *
     * @param w the width to which the frame data should be
     *             scaled prior to output
     * @param h the height to which the frame data should be
     *             scaled prior to output
     * @throws MediaException if the converter cannot be configured to scale 
     *                        to the specified size
     */
    void setScaleOutputSize(int w, int h) //throw (MediaException)
    {
        if (MediaFormatConvert_setScaleOutputSize(cconv, w, h))
            throw MediaException();
    }

    /**
     * Obtains the width and height of the "frame" data that will be
     * populated in the output data arrays upon the next call to convert(). 
     * This is influenced by the source video format and the scaling
     * configuration (setScale* methods). 
     *
     * @param w pointer to integer to receive the width dimension
     * @param h pointer to integer to receive the height dimension
     */
    void getScaleOutputSize(int *w, int *h)
    {
        MediaFormatConvert_getScaleOutputSize(cconv, w, h);
    }
    
    /**
     * Obtains a VideoFrameData object that details the frame layout
     * of the output frames.  The configuration may change following
     * calls that change the scaler configuration; re-invoking this to
     * get the new layout after calling a scaler configuration function
     * will be necessary.
     * This should be invoked after the scaler configuration has been made
     * and after an appropriately sized output buffer has been provided.
     * The data pointers of the provided frame will point to offsets
     * inside the previously supplied output buffer.
     */
    const VideoFrameData *getOutputFrame()
    {
        return MediaFormatConvert_getOutputFrame(cconv);
    }

    /**
     * Provides an output buffer into which the frames should be converted.
     * The buffer is used to house all data planes of the frame to be output.
     * Changes to the scaler configuration can require providing a new buffer,
     * depending on the needed output size.
     * The provided buffer must remain valid until this object is destroyed
     * or until a new buffer is provided. The buffer's deallocation is
     * the responsibility of the application providing the buffer.
     * Pointers to the individual planes are provided in the VideoFrameData
     * object describing the output frame layout, which is obtained by invoking
     * getOutputFrame().  Throws MediaException if the buffer is too small.
     * @param buf buffer to decode frames into
     * @param bufsize the size of the buffer pointed to by buf; must be at
     *                least as big as the return value of
     *                getRequiredBufferSize()
     */
    void setOutputBuffer(uint8_t *buf, unsigned int bufsize)
                                       //throw (MediaException)
    {
        if (MediaFormatConvert_setOutputBuffer(cconv, buf, bufsize))
            throw MediaException();
    }
    
    /**
     * Obtains the required buffer size for output.  A buffer of at least
     * this size must be supplied to setOutputBuffer prior to invoking
     * convert().
     */
    unsigned int getRequiredBufferSize()
    {
        return MediaFormatConvert_getRequiredBufferSize(cconv);
    }

    /**
     * Convert the given video frame and produce output in the previously
     * supplied output buffer, whose data planes and layout is described by
     * the VideoDataFrame accessed through getOutputFrame().  This performs
     * any pixel format conversion and the scaling operation currently
     * configured.
     *
     * Unless changes are made to the configuration of the class or the
     * output buffer, the output buffer is reused and the layout (offsets
     * and strides in the VideoDataFrame) remain the same following
     * subsequent calls to convert(). 
     *
     * @param frame the source VideoFrameData to convert
     */
    void convert(const VideoFrameData *frame) //throw (MediaException)
    {
        if (MediaFormatConvert_convert(cconv, frame)) { }
            //throw MediaException();
    }

private:
    MediaFormatConvert_C cconv;


};


};

#endif
