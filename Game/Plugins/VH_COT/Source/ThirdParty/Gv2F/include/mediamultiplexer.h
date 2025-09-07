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


#ifndef PGSC_MEDIAMULTIPLEXER_H
#define PGSC_MEDIAMULTIPLEXER_H

#include "mediaexception.h"
#include "mediaconsumers.h"
#include "mediaformats.h"
#include "mediamultiplexer_c.h"

namespace PGSCMedia {

/**
 * Data sink interface for the multiplexer. The multiplexer will write to the
 * sink as its input is processed. If a write operation fails, the multiplexer
 * will throw a MediaException as the multiplexer has no practical means of
 * continuing if the sink is no longer viable.
 */
class MultiplexerDataSink {
public :
    /**
     * Writes the specified data buffer to the data sink.
     *
     * @param buf   The data
     * @param len   The number of bytes in the buffer to be written to the sink
     *
     * @return  non-negative integer on success, negative integer if the write failed.
     */
    virtual int dataSinkWrite(const unsigned char* buf, int len) = 0;
};

/**
 * Interface to the media multiplexer. The multiplexer is capable of generating
 * an MPEG-2 Transport Stream (TS) (SPECIFICATION REFERENCE) that contains two
 * tracks, one video and one KLV, or one track, video. The multiplexer accepts
 * decoded/decompressed data and will perform the necessary coding/compression.
 * Video data will be coded as MPEG-2 Video (SPECIFICATION REFERENCE) and KLV
 * tracks will be coded as synchronous metadata (SPECIFICATION REFERENCE).
 *
 * <P>The multiplexer is configured by first specifying the number of tracks,
 * then setting the video/klv track and obtaining the consumers (more on that
 * below), setting the data sink, and finally invoking open. The multiplexer may
 * throw a MediaException during any one of the configuration steps, and may
 * throw a MediaException during 'open' if the combination of parameters
 * presents an issue. The 'open' function must be invoked before passing data to
 * the multiplexer.
 *
 * <P>The multiplexer returns a VideoConsumer and KLVConsumer when the video and
 * KLV tracks are configured, respectively.  These consumers are to be used to
 * pass the appropriate data to the multiplexer for processing. These consumers
 * obey the contracts defined in 'mediaconsumers.h'; they only assume access to
 * the data they are passed during the invocation of the function. Data for a
 * specific track MUST be passed in monotonically increasing timestamps,
 * however, data does not need to be delivered interleaved fashion across the
 * different tracks (e.g. all data could be provided, in order, for the video
 * track, followed by all data for the KLV track). Buffering will be performed
 * by the multiplexer to ensure proper interleaving order, so for performance
 * reasons, it is recommended but not required that data be delivered in a
 * reasonably interleaved fashion. Frame duplication/dropping will be performed
 * for the video track in the case that the timestamps for delivered frames are
 * not consistent with the specified frame rate. Additional buffering will be
 * performed for the KLV track to support proper multiplexing of multiple KLV
 * items with the same timestamp. At anytime, 'NULL' may be passed to the
 * KLVConsumer in order to flush any buffered KLV data to the multiplexer.
 */
class MediaMultiplexer {
public :
    /**
     * Creates a new MediaMultiplexer.
     */
    MediaMultiplexer() //throw (MediaException)  // WITH_VH
                       : vidconsumer(NULL),
                         klvconsumer(NULL)
    {
        cmultiplexer = MediaMultiplexer_create();
        if(!cmultiplexer)
            throw MediaException();
        sink.opaque = NULL;
        sink.dataSinkWrite = dataSinkRedirect;
    }

    /**
     * Destroys MediaMultiplexer. If the multiplexer has been opened, all output
     * will be flushed to the sink.
     */
    ~MediaMultiplexer() {
        MediaMultiplexer_destroy(cmultiplexer);
        if(vidconsumer)
            delete vidconsumer;
        if(klvconsumer)
            delete klvconsumer;
    }

    /**
     * Sets the number of tracks in the outputs.
     *
     * @param numTracks The number of tracks. Must be 1 or 2.
     */
    void setNumTracks(const int numTracks) {
        MediaMultiplexer_setNumTracks(cmultiplexer, numTracks);
    }

    /**
     * Configures the KLV track.
     * 
     * <P>A MediaException will be thrown if the KLV track has already been
     * configured. A MediaException will be thrown if the multiplexer has been
     * opened.
     *
     * @param outfmt    Describes the desired attributes for the KLV to be
     *                  output
     *
     * @return  A KLVConsumer that will accept KLV data that will be
     *          multiplexed.
     */
    KLVConsumer* setKLVTrack(const KLVEncodingFormat *fmt) {//throw (MediaException) {  // WITH_VH
        if(klvconsumer)
            throw MediaException();

        KLVEncodingFormat_C cfmt;
        fmt->toC(&cfmt);
        KLVConsumer_C* consumer = MediaMultiplexer_setKLVTrack(cmultiplexer, &cfmt);
        if(!consumer)
            throw MediaException();
        klvconsumer = new KLVRedirector(consumer);
        return klvconsumer;
    }

    // XXX - need to check frame rates
    /**
     * Configures the video track.
     * 
     * <P>A MediaException will be thrown if some of the parameters are missing
     * or the values are unacceptable. A MediaException will be thrown if the
     * video track has already been configured. A MediaException will be thrown
     * if the multiplexer has been opened.
     *
     * @param infmt     Describes the attributes of the frames that will be
     *                  passed to the returned consumer
     * @param outfmt    Describes the desired attributes for the video encoding
     *                  process
     *
     * @return  A VideoConsumer that will accept decoded frames which will be
     *          encoded and multiplexed.
     */
    VideoConsumer* setVideoTrack(const VideoMediaFormat *infmt, const VideoEncodingFormat *outfmt) {//throw (MediaException) {
        if(vidconsumer)
            throw MediaException();

        VideoMediaFormat_C cinfmt;
        infmt->toC(&cinfmt);
        VideoEncodingFormat_C coutfmt;
        outfmt->toC(&coutfmt);
        VideoConsumer_C* consumer = MediaMultiplexer_setVideoTrack(cmultiplexer, &cinfmt, &coutfmt);
        if(!consumer)
            throw MediaException();
        vidconsumer = new VideoRedirector(consumer);
        return vidconsumer;
    }

    /**
     * Sets the output data sink for the multiplexer. The multiplexer will write
     * its output to the sink during processing.
     *
     * @param _sink The data sink
     */
    void setOutputSink(MultiplexerDataSink* _sink) {//throw (MediaException) {
        if(sink.opaque)
            throw MediaException();
        sink.opaque = _sink;
        int err = MediaMultiplexer_setOutputSink(cmultiplexer, &sink);
        if(err)
            throw MediaException();
    }

    /**
     * Opens the multiplexer. This function should be invoked once the tracks
     * have been configured and a data sink has been specified. Upon successful
     * return of this function, data may be passed to the multiplexer for
     * processing.
     */
    void open() {//throw (MediaException) {
        int err = MediaMultiplexer_open(cmultiplexer);
        if(err)
            throw MediaException();
    }

private :
    static int dataSinkRedirect(const unsigned char* buf, int len, void *opaque)
    {
        MultiplexerDataSink *c = (MultiplexerDataSink *)opaque;
        return c->dataSinkWrite(buf, len);
    }

    class KLVRedirector : public KLVConsumer {
        public :
            virtual void mediaKLVData(KLVData *data) {
                consumer->mediaKLVData(consumer->opaque, data);
            }

        protected:
            virtual ~KLVRedirector() {}
        private :
            KLVRedirector(KLVConsumer_C *c) : consumer(c) {}

            KLVConsumer_C *consumer;

            friend class MediaMultiplexer;
    };

    class VideoRedirector : public VideoConsumer {
        public :
            virtual void mediaVideoFrame(const VideoFrameData *frame) {
                consumer->mediaVideoFrame(consumer->opaque, frame);
            }

        protected:
            virtual ~VideoRedirector() {}
        private :
            VideoRedirector(VideoConsumer_C *c) : consumer(c) {}

            VideoConsumer_C *consumer;

            friend class MediaMultiplexer;
    };


    VideoRedirector *vidconsumer;
    KLVRedirector *klvconsumer;
    MultiplexerDataSink_C sink;
    MediaMultiplexer_C cmultiplexer;
};

};

#endif
