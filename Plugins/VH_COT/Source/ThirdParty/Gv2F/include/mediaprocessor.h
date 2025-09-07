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

#ifndef PGSC_MEDIAPROCESSOR_H
#define PGSC_MEDIAPROCESSOR_H

#include <stdint.h>
#include <stdlib.h>
#include <vector>
#include <string>

#include "mediaexception.h"
#include "mediaformats.h"
#include "mediaconsumers.h"
#include "mediaannotations.h"
#include "mediaprocessor_c.h"

namespace PGSCMedia {


/*
 * MediaProcessor is the main interface class to the internal video
 * processing and playback machinery.  This class can universally be used to
 * both play media, with decoding and output timed appropriately, and for media
 * processing in which the media is decoded and output as quickly 
 * as is permitted by the available system resources.
 *
 * This class controls asynchronous processing of media. The client
 * utilizing this interface receives decoded and/or processed data
 * through one or more "consumers" as data both becomes available
 * and its rendering time arrives.
 *
 * Consumers are interfaces that clients of this class must implement and
 * pass to this class to receive callbacks of certain events and output data.
 * The specific consumers are discussed in detail both in the function that
 * receives their reference, as well as in the specific consumer interface
 * descriptions.  Generally speaking, however, the following applies to
 * all consumer interfaces and their callbacks therein:
 * - Consumers are called back to by internal processing threads.
 *   Handling the events should occur in an expedicious manner, otherwise
 *   internal processing will be delayed and could cause undesirable
 *   loss in performance.
 * - Data buffers or other resources provided via reference/pointer to a
 *   Consumer in a callback function are internally managed by the 
 *   MediaProcessor. No memory management/cleanup of these items is expected
 *   by the client application.  These resources are valid for the duration
 *   of the callback - referencing a pointer given to a callback after the
 *   callback terminates may result in undefined behavior (unless otherwise
 *   noted in the specific Consumer interface documentation).
 * - Multiple Callbacks to the same Consumer callback function will
 *   not occur concurrently.  However, multiple different callbacks may
 *   be invoked simultaneously (by separate internal threads).  
 * - A consumer configured in a processor must remain valid for the duration
 *   that the processor exists.
 *
 * Using this class generally involves these steps:
 * 1. Initialize the PGSCMedia library by calling PGSCMediaInit().
 * 2. Create a MediaProcessor using one of the createFrom...() functions.
 * 3. Query track information using getTrackInfo().
 * 4. Install any relevant callbacks to receive data of interest.
 * 5. Set playback rate, discard mode, or other options as desired.
 * 6. Start playback/processing using start() [alternatively, if you don't
 *    wish to start playback immediately but would like to present the video's
 *    first frame to the user, call prefetch(). Then, call start() when you
 *    wish to begin playback.]
 * 7. Process data delivered to the various callbacks as desired.
 * 8. Pause (using stop()), change playback rate, seek (setTime()), or
 *    extract clips and snapshots as desired.
 * 9. When finished with playback/processing operations, clean up
 *    the resources used by the MediaProcessor by passing it to
 *    destroyProcessor().
 *
 * This class is NOT intended to be called into by multiple threads
 * simultaneously to the same instance.
 */
class MediaProcessor {

public:

    /****************************************************************/
    // Initialization

    /*
     * Initializes the PGSCMedia library. This needs to be called once
     * before using any other calls in this API.
     */
    static void PGSCMediaInit(const char *licenseData, unsigned int len)
                                          //throw (MediaException)  WITH_VH
    {
        if (::PGSCMediaInit(licenseData, len))
            throw MediaException();
    }


    /****************************************************************/
    // Administrative

    /*
     * Programatically query the version string for the build of this 
     * library.
     */
    static std::string getVersion() { 
          return MediaProcessor_getVersion();
    }


    /****************************************************************/
    // Creation
    
    /*
     * Create a MediaProcessor which reads source data from the specified
     * file.
     * If an error occurs opening or reading the media headers/information
     * from the file, a MediaException will be thrown.
     * The returned MediaProcessor's resources should be freed when
     * no longer needed by passing it to destroyProcessor().
     */
    static MediaProcessor *createFromFile(const char *file)
                                          //throw (MediaException)
    {
        MediaProcessor_C p;
        if (MediaProcessor_createFromFile(&p, file) != 0) {
            throw MediaException();
        }
        MediaProcessor *mp = new MediaProcessor(p);
        return mp;
    }

    /*
     * Create a MediaProcessor which reads source data from a streaming
     * source.  The streaming source can, optionally, be buffered, enabling
     * seeking, extraction, etc. of the streaming source over the buffering
     * period.
     * The buffering period can be specified by time, maximum byte size, or
     * both.  When both are specified, buffering will be limited by whichever
     * limiting parameter is reached first.
     * The UDP streaming supported is UDP datagrams carrying
     * any of the supported media formats.
     *
     * If an error occurs connecting to the streaming source, or reading 
     * the media headers/information, a MediaException will be thrown.
     * The returned MediaProcessor's resources should be freed when
     * no longer needed by passing it to destroyProcessor().
     * @param mcastAddr Multi-cast IP address in dotted-decimal notation if
     *                  receiving a multi-cast stream. (ex: "239.1.1.1")
     *                  NULL for unicast streams.
     * @param port local port number (or multicasted port number)
     *             to receive data on
     * @param timeout amount of time to wait between received data packets;
     *             if data is not received in the given amount of milliseconds
     *             the source stream is considered to be at its end.  This
     *             must be non-zero and to avoid long delays should be kept to
     *             reasonably short amounts of time (several seconds or less)
     * @param bufferTime amount of time to buffer, in milliseconds.
     *                   Use 0 to limit solely by maxByteSize.
     * @param maxByteSize maximum number of bytes to buffer; use 0 for
     *                    unlimited. If both maxByteSize and bufferTime
     *                    are specified as 0, buffering is disabled.
     * @param tmp_dir temporary directory (which must exist) into which
     *                files can be created to buffer the stream as needed.
     *                Can be NULL if buffering is disabled.
     * @param localAddress ip address of local interface via which the
     *                stream should be listened for
     *                NULL will result in listening on an OS-dependent
     *                interface for multi-cast streams and all interfaces
     *                for unicast streams
     */
    static MediaProcessor *createFromStream(const char *mcastAddr,
                                            int port,
                                            unsigned int timeout,
                                            long bufferTime,
                                            unsigned long maxByteSize,
                                            const char *tmp_dir,
                                            const char *localAddress=NULL)
                                          //throw (MediaException)
    {
        MediaProcessor_C p;
        if (MediaProcessor_createFromStream(&p, mcastAddr, port, 
                                            timeout, bufferTime,
                                            maxByteSize, tmp_dir,
                                            localAddress) != 0) {
            throw MediaException();
        }
        MediaProcessor *mp = new MediaProcessor(p);
        return mp;
    }

    /*
     * !!! THIS FUNCTION IS NOT YET IMPLEMENTED !!!
     *
     * Create a MediaProcessor which reads source data from a streaming
     * source.  The streaming source can, optionally, be buffered, enabling
     * seeking, extraction, etc. of the streaming source over the buffering
     * period.
     * The buffering period can be specified by time, maximum byte size, or
     * both.  When both are specified, buffering will be limited by whichever
     * limiting parameter is reached first.
     *
     * If an error occurs connecting to the streaming source, or reading 
     * the media headers/information, a MediaException will be thrown.
     * The returned MediaProcessor's resources should be freed when
     * no longer needed by passing it to destroyProcessor().
     * @param addr The RTSP stream address. Should be in the form
     *             {host}:{port}/[{file}]
     * @param timeout amount of time to wait between received data packets;
     *             if data is not received in the given amount of milliseconds
     *             the source stream is considered to be at its end.  This
     *             must be non-zero and to avoid long delays should be kept to
     *             reasonably short amounts of time (several seconds or less)
     * @param bufferTime amount of time to buffer, in milliseconds.
     *                   Use 0 to limit solely by maxByteSize.
     * @param maxByteSize maximum number of bytes to buffer; use 0 for
     *                    unlimited. If both maxByteSize and bufferTime
     *                    are specified as 0, buffering is disabled.
     * @param tmp_dir temporary directory (which must exist) into which
     *                files can be created to buffer the stream as needed.
     *                Can be NULL if buffering is disabled.
     */
    static MediaProcessor *createFromRtsp(const char *addr,
                                            unsigned int timeout,
                                            long bufferTime,
                                            unsigned long maxByteSize,
                                            const char *tmp_dir)
                                          //throw (MediaException)  // WITH_VH
    {
        MediaProcessor_C p;
        if (MediaProcessor_createFromRtsp(&p, addr, 
                                            timeout, bufferTime,
                                            maxByteSize, tmp_dir) != 0) {
            throw MediaException();
        }
        MediaProcessor *mp = new MediaProcessor(p);
        return mp;
    }

    /*
     * Create a MediaProcessor derived from an existing MediaProcessor. 
     * This creates a new MediaProcessor that uses the same input data as
     * the supplied MediaProcessor.  Other than using the same input source,
     * no other configuration or settings are carried over to the new
     * MediaProcessor from the supplied one.  Use and operation of the new
     * MediaProcessor is largely independent of the source MediaProcessor,
     * with a few exceptions noted below. 
     * This means that, in addition to other things, the new MediaProcessor
     * and existing, provided MediaProcessor can...
     * 1. Be controlled and positioned at different points in the source media.
     * 2. Use completely distinct consumer instances, or the same ones; the
     *    consumer configuration is completely independent.
     * 3. Be used simultaneously (even concurrently by multiple threads,
     *    though each one is individually subject to the single-threading
     *    limitation outlined for the MediaProcessor interface).
     *
     * Notable points of caution about "cloned" MediaProcessors created by 
     * this function, and use of this function:
     * 1. Each MediaProcessor must be destroyed via destroyProcessor when no
     *    longer needed; this can be done in any order.
     * 2. This function cannot be used to create a "clone" MediaProcessor from
     *    a MediaProcessor that is reading from an *unbuffered* network stream.
     *    This will always fail as this type of source cannot be shared.
     * 3. Creating "clone" MediaProcessors of a MediaProcessor that was
     *    created from a buffered network stream results in the stream
     *    buffer being shared between the MediaProcessors.  This means that
     *    buffer length is controlled by the intersection of all
     *    MediaProcessors that share the network buffer.  See
     *    setStreamingBufferDiscardEnabled() for more on this.
     *
     * If there is an error creating the new MediaProcessor, a MediaException
     * will be thrown.
     *
     * @param proc the MediaProcessor to derive a new MediaProcessor
     *        from.
     */
     static MediaProcessor *createFromProcessor(MediaProcessor *proc)
                                                  // throw (MediaException)
     {
        MediaProcessor_C p;
        if (MediaProcessor_createFromProcessor(&p, proc->cprocessor) != 0) {
            throw MediaException();
        }
        MediaProcessor *mp = new MediaProcessor(p);
        return mp;
     }
     

    /*
     * Deallocates a MediaProcessor and all of its internal resources.
     * This, not a call to delete or other deallocation means, should be
     * used to dispose of a MediaProcessor that is no longer needed.
     * It is safe to call this on a running processor;  such a processor
     * will be internally stopped before destruction.
     */
    static void destroyProcessor(MediaProcessor *processor)
    {
        MediaProcessor_destroyProcessor(processor->cprocessor);
        delete processor;
    }


    /****************************************************************/
    // Setup and configuration
    
    /*
     * Get information about the track layout of the media.
     * The returned vector will include only tracks which can be
     * accessed through this API;  unrecognized tracks are not exported.
     * Tracks in the returned vector are in ascending track number order.
     */
    std::vector<MediaFormat *> getTrackInfo()
    {
        if (formats.empty()) {
            MediaFormat_C **cformats;
            int n = MediaProcessor_getTrackInfo(cprocessor, &cformats);
            for (int i = 0; i < n; ++i) {
                MediaFormat *fmt = translateFormat(cformats[i]);
                formats.push_back(fmt);
            }
        }
        return formats;
    }

    /*
     * Add a consumer for the indicated video track number.
     * The consumer will receive video frame data as it is decoded
     * and the presentation time is reached.
     * See class documentation on how consumers work, in general.
     * @param tracknum the track number of video track to which the
     *                 consumer should be associated
     * @param consumer the VideoConsumer to associate with the track
     */
    void setVideoConsumer(int tracknum, VideoConsumer *consumer)
    {
        vid_consume.opaque = consumer;
        if (!consumer)
            MediaProcessor_setVideoConsumer(cprocessor, tracknum, NULL);
        else
            MediaProcessor_setVideoConsumer(cprocessor, tracknum,
                                            &vid_consume);
    }


    /*
     * Add a consumer for the indicated KLV metadata track number.
     * The consumer will receive KLV data as it is decoded
     * and the presentation time is reached.
     * See class documentation on how consumers work, in general.
     * @param tracknum the track number of video track to which the
     *        consumer should be associated
     * @param consumer the KLVConsumer to associate with the track
     */
    void setKLVConsumer(int tracknum, KLVConsumer *consumer)
    {
        klv_consume.opaque = consumer;
        if (!consumer)
            MediaProcessor_setKLVConsumer(cprocessor, tracknum, NULL);
        else
            MediaProcessor_setKLVConsumer(cprocessor, tracknum, &klv_consume);
    }

    /*
     * Add a consumer for ESD Closed-Caption metadata. The captions will be
     * derived from the enabled video track; if no VideoConsumer is installed
     * captions will not be delivered, even if present in the stream.
     *
     * The ESD data will be delivered on the same processing thread as the video
     * data.
     *
     * @param consumer  The ESDConsumer to add, NULL to remove
     */
    void setESDConsumer(ESDConsumer *consumer)
    {
        esd_consume.opaque = consumer;
        if (!consumer)
            MediaProcessor_setESDConsumer(cprocessor, NULL);
        else
            MediaProcessor_setESDConsumer(cprocessor, &esd_consume);
    }

    /*
     * Add a consumer for status updates. This consumer is notified
     * when various important events about the overall status of the
     * MediaProcessor changes.
     * See class documentation on how consumers work, in general.
     * @param consumer the consumer to receive overall status events
     */
    void setStatusUpdateConsumer(StatusUpdateConsumer *consumer)
    {
        status_consume.opaque = consumer;
        if (!consumer)
            MediaProcessor_setStatusUpdateConsumer(cprocessor, NULL);
        else
            MediaProcessor_setStatusUpdateConsumer(cprocessor, 
                                                   &status_consume);
    }

    /*
     * Add a consumer for the source media data.  The consumer will
     * be fed bytes of the streaming input as it is read by the internal
     * processing. This is not supported for file-based sources.
     * See class documentation on how consumers work, in general.
     * @param type specifies the format to which the incoming data
     *             should be translated before providing to this
     *             consumer
     * @param consumer the consumer to receive incoming data bytes
     */
    void setMediaConsumer(MediaFileType type, MediaConsumer *consumer)
    {
        media_consume.opaque = consumer;
        if (!consumer)
            MediaProcessor_setMediaConsumer(cprocessor, type, NULL);
        else
            MediaProcessor_setMediaConsumer(cprocessor, type, &media_consume);
    }


    /*
     * Enable or disable the limit controls of a streaming buffer.
     * Streaming sources are optionally buffered (see createFromStream())
     * with limits to the buffer time or byte length.  This function can
     * be used to disable buffer limitations, temporarily allowing the
     * buffer to grow beyond the limitations specified when opening.
     * For non-streaming sources this does nothing.
     *
     * For MediaProcessor instances that are sharing a buffered network
     * source with other MediaProcessor instances (see createFromProcessor()),
     * buffers will not be discarded to maintain the buffer limit during any
     * time for which any MediaProcessor sharing the buffer has this
     * setting disabled.
     */
    void setStreamingBufferDiscardEnabled(bool discardEnabled)
    {
        MediaProcessor_setStreamingBufferDiscardEnabled(
                     cprocessor, discardEnabled ? 1 : 0);
    }
    
    /*
     * Indicate if streaming buffer limit controls are currently enabled.
     */
    bool isStreamingBufferDiscardEnabled()
    {
        return MediaProcessor_isStreamingBufferDiscardEnabled(cprocessor) != 0;
    }
    
    /*
     * Obtain the interface used to manipulate annotations in the media.
     * Note that the prohibition of concurrent calls described in this
     * interface's documentation extends to the returned MediaAnnotations
     * interface instance. Multiple concurrent calls into any API function
     * of either interface results in undefined behavior.
     * Returns NULL if the media format does not support annotations.
     */
    MediaAnnotations *getAnnotations()
    {
        if (!annos) {
            MediaAnnotations_C cannos = MediaProcessor_getAnnotations(cprocessor);
            if (cannos)
                annos = new MediaAnnotations(cannos);
        }
        return annos;
    }
    
    /****************************************************************/
    // Media Information

    /*
     * Get the duration of the media, in milliseconds.
     * If the duration is unknown (for streaming sources, or file formats
     * without a clear duration), -1 is returned.
     */
    long getDuration()
    {
        return MediaProcessor_getDuration(cprocessor);
    }
    
    /*
     * Gets the average bit rate of the file in bits per second.
     * If the bitrate is unknown or not able to be determined, -1 is returned.
     */
    float getBitRate()
    {
        return MediaProcessor_getBitRate(cprocessor);
    }

    /**
     * Gets the frame rate (in frames per second) of the video track of this
     * file, if there is one. Note that the returned value may not necessarily
     * be accurate, because (for example) frame rates can change during
     * playback.
     *
     * If the frame rate is unknown or not able to be determined, -1 is
     * returned.
     */
    float getFrameRate()
    {
        return MediaProcessor_getFrameRate(cprocessor);
    }

    /**
     * Indicates whether this processor is based on streaming media (true),
     * or is file-based (false).
     */
    bool isStreaming()
    {
        return MediaProcessor_isStreaming(cprocessor);
    }
    
    /****************************************************************/
    // Playback/Processing control

    /*
     * Sets the playback/processing rate.  This is the rate at which the
     * internal processing/playback clock runs and times delivery of
     * data to the relevant consumers. The specified rate is a multiplier
     * against real-time.  A rate of 1.0 is real-time;
     * larger numbers result in faster-than-realtime processing
     * (2.0 is double-speed), and rates between 0 and 1.0 slow 
     * processing (0.5 is half-speed).  Values less than or equal to zero
     * are treated as 1.0.
     *
     * If the rate results in faster processing than the system can maintain,
     * one of two behaviors can occur depending on the most recent call to
     * setFrameDiscardEnabled(). See that function for further information.
     *
     * When using the processor for data processing (instead of visual
     * playback), large rate values can be used in conjunction with
     * disabling frame discard to achieve "as fast as possible" processing.
     *
     * The default rate is 1.0.
     * @param rate playback rate multiplier
     */
    void setRate(float rate)
    {
        MediaProcessor_setRate(cprocessor, rate);
    }
    
    /*
     * Gets the desired playback rate that was last configured with setRate().
     * The return value is a multiplier of play/processing speed. See 
     * setRate() for more information
     */
    float getRate()
    {
        return MediaProcessor_getRate(cprocessor);
    }    
    
    /*
     * Controls how video data is handled if the system cannot process
     * media as fast as required by the current desired processing rate (see
     * set/getRate()).
     * When set to true (the default), frames will be discarded as necessary
     * to try to achieve the desired rate.  When false, no frames will
     * be discarded;  playback/processing will continue as close to the 
     * desired rate as possible without sacrificing frames.
     * @param discard true to allow frames to be dropped when playback
     *                     runs behind the desired rate, false to not
     *                     drop frames even when playback is running behind
     */
    void setFrameDiscardEnabled(bool discard)
    {
        MediaProcessor_setFrameDiscardEnabled(cprocessor, discard ? 1 : 0);
    }    
    
    /*
     * Gets the current frame discard enable state.  See setFrameDiscardEnable()
     * for more information on how this parameter influences processing of the
     * media.
     */
    bool getFrameDiscardEnabled()
    {
        return MediaProcessor_getFrameDiscardEnabled(cprocessor);
    }   

    /*
     * Controls what frames are processed and output by the video decoder.
     */
    void setFrameSkip(VideoFrameSkip skip)
    {
        MediaProcessor_setFrameSkip(cprocessor, skip);
    }

    /*
     * Returns the current frame skip setting.
     */
    VideoFrameSkip getFrameSkip()
    {
        return MediaProcessor_getFrameSkip(cprocessor);
    }  
    
    /*
     * Sets the current playback/processing location based on time, in
     * milliseconds. Most media formats cannot be randomly accessed at
     * any arbitrary point; for these sources, the resulting playback
     * location may not be precisly the same as the specified time.
     * Rather, playback/processing will resume from the next 
     * (later/subsequent) random access point and the timestamp for
     * such (in milliseconds) will be returned.
     * If the processing was running when this function was called,
     * it will continue to run from the new position.
     * @param timeMillis the target time to continue playback from,
     *                   in milliseconds
     */
    long setTime(long timeMillis)
    {
        return MediaProcessor_setTime(cprocessor, timeMillis);
    }    
    
    /*
     * Gets the current playback time position, in milliseconds.
     */
    long getTime()
    {
        return MediaProcessor_getTime(cprocessor);
    }    
    
    /**
     * Fetch and output a single video frame. This should be called to output a
     * frame upon startup, if one does not wish to start playback immediately.
     * This allows the initial frame of the video to be displayed to the user
     * prior to start() being called.
     */
    void prefetch()
    {
        MediaProcessor_prefetch(cprocessor);
    }    

    /*
     * Initiates or resumes processing.  Once this is called,
     * processing will begin from the current time position at the currently
     * configured rate.  Processing will subsequently cease due to one of:
     * 1. stop() being called
     * 2. All input media is exhausted, in which case any configured
     *    StatusUpdateConsumer will be notified through its mediaEOF()
     *    callback.
     * 3. The processor is destroyed via destroyProcessor()
     * 4. A fatal error occurs internally, in which case any configured
     *    StatusUpdateConsumer will be notified through its mediaFatalError()
     *    callback.
     */
    void start()
    {
        MediaProcessor_start(cprocessor);
    }    
    
    /*
     * Stops processing if it is active. The current media time is preserved
     * and will be the point where processing is resumed if start() is later
     * invoked.  If processing is not active, this does nothing.
     */
    void stop()
    {
        MediaProcessor_stop(cprocessor);
    }    
    
    /*
     * Indicates if processing is currently running (that is, if
     * start() has been invoked and none of the stop conditions has yet
     * been reached.
     */
    bool isProcessing()
    {
        return MediaProcessor_isProcessing(cprocessor) != 0;
    }    
    
    /*
     * Sets the stop time for the processor. When set, the processor will stop
     * playback when the media time becomes equal to, or greater than, the
     * specified stop time. The stop time will remain set until explicitly
     * cleared by specifying a value of '0'.
     *
     * This function may only be invoked on a stopped processor
     * (MediaProcessor::isProcessing() returns false).
     *
     * @param millis    The stop time, in milliseconds. A value of '0' may be
     *                  specified to clear the stop time.
     *
     * @return  'true' if the stop time was successfully set, 'false' otherwise.
     */
    bool setStopTime(long millis)
    {
        return MediaProcessor_setStopTime(cprocessor, millis) == 0;
    }

    /****************************************************************/
    // Processing operations

    /*
     * Extract the current video frame to a still image in the specified
     * format. Any existing file at the specified location will be
     * overwritten.  This call blocks until the operation is complete.
     */
    void extractCurrentFrame(SnapShotFileType type, const char *filename)
                                                  //throw (MediaException)
    {
        int r = MediaProcessor_extractCurrentFrame(cprocessor, type, filename);
        if (r)
            throw MediaException();
    }

    
    /*
     * Extracts a sub-section of the source media, converted to
     * the specified format if necessary, to a file.
     * The times are specified in milliseconds; invalid time specifications
     * are clipped to the start and end of media time.
     * Any existing file at the specified location will be overwritten.
     * This call blocks until the operation is complete.
     */
    void extractMediaClip(MediaFileType type, long timeStart, long timeEnd,
                          const char *filename) //throw (MediaException)
    {
        int r = MediaProcessor_extractMediaClip(cprocessor, type,
                                                timeStart, timeEnd, filename);
        if (r)
            throw MediaException();
    }


    /****************************************************************/
    // Static utilities

    /**
     * Duplicates the frame provided into a new frame. This performs a
     * "deep copy" of all the data associated with the frame.
     * Frames created by this remain valid until provided to
     * destroyDuplicateFrame().
     */
    static const VideoFrameData *duplicateFrame(const VideoFrameData *frame)
    {
        return MediaProcessor_duplicateFrame(frame);
    }
    
    /**
     * Reclaim the resources associated with the associated frame, which must
     * have been created by duplicateFrame()
     */
    static void destroyDuplicateFrame(const VideoFrameData *frame)
    {
        MediaProcessor_destroyDuplicateFrame(frame);
    }


private:
    MediaProcessor(MediaProcessor_C cp) : cprocessor(cp), annos(NULL) {
        vid_consume.mediaVideoFrame = &CallbackRedirect::mediaVideoFrame;
        klv_consume.mediaKLVData = &CallbackRedirect::mediaKLVData;
        esd_consume.mediaESDData = &CallbackRedirect::mediaESDData;
        media_consume.mediaBytes = &CallbackRedirect::mediaBytes;
        status_consume.mediaStreamExtentsUpdate =
                            &CallbackRedirect::mediaStreamExtentsUpdate;
        status_consume.mediaEOF = &CallbackRedirect::mediaEOF;
        status_consume.mediaFatalError = &CallbackRedirect::mediaFatalError;
    }

    ~MediaProcessor()
    {
        if (annos)
            delete annos;
        std::vector<MediaFormat *>::iterator it;
        for (it = formats.begin(); it != formats.end(); it++) {
            MediaFormat *fmt = *it;
            delete fmt;
        }
    }
    
    MediaFormat *translateFormat(MediaFormat_C *cf)
    {
        MediaFormat *f;
        if (cf->format_type == ::FORMAT_VIDEO) 
            f = new VideoMediaFormat((VideoMediaFormat_C *)cf);
        else
            f = new MediaFormat(cf);
        return f;
    }


    MediaProcessor_C cprocessor;
    MediaAnnotations *annos;
    std::vector<MediaFormat *> formats;
    
    VideoConsumer_C vid_consume;
    KLVConsumer_C klv_consume;
    ESDConsumer_C esd_consume;
    MediaConsumer_C media_consume;
    StatusUpdateConsumer_C status_consume;

};


};  // End of namespace

#endif
