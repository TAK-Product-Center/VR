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



#ifndef PGSC_METADATAINJECTOR_H
#define PGSC_METADATAINJECTOR_H

#include <stdlib.h>

#include "metadatainjector_c.h"
#include "mediaconsumers.h"
#include "mediamultiplexer.h"

namespace PGSCMedia {

/**
 * The status update consumer for the MetadataInjector. This class provides
 * the callback functions of StatusUpdateConsumer as well as additional callback
 * functions to support metadata injection activities.
 *
 * Unless otherwise noted, the public functions of the MetadataInjector
 * (including KLV injection via its KLVConsumer) may not be called during the
 * execution of a callback function.
 */
class MetadataInjectorStatusUpdateConsumer : public StatusUpdateConsumer
{
public :
    /**
     * This callback is invoked when the media is opened. Applications requiring
     * synchronization between the media stream and an external metadata source
     * may be able to accomplish such synchronization using this function.
     */
    virtual void mediaOpened(long mediaTimeMillis) = 0;

    /**
     * This callback is invoked when a packet is demultiplexed from the source
     * stream and provides the current media time to the consumer.
     *
     * Note: The user may inject KLV data via the KLVConsumer or close the
     * MetadataInjector during this callback.
     *
     * @param mediaTimeMillis   The current media time, in milliseconds
     */
    virtual void mediaTimeUpdate(long mediaTimeMillis) = 0;
};

class KLVInjector : public KLVConsumer
{
public :
    /**
     * Instructs the injector that multiple KLVData struct's with the same
     * timestamp will be passed to the injector. The injector will then combine
     * the KLV items into a single packet to be passed to the multiplexer.
     *
     * When KLV combining is enabled, the combined packet will become eligible
     * for interleaving once a KLV item with a timestamp different than the
     * timestamp of the last KLVData struct passed to 'mediaKLVData' is passed
     * to 'mediaKLVData'.
     *
     * For applications with a minimum latency, the combined packet will become
     * sent to the multiplexer once the packet's timestamp leaves the buffering
     * period.
     *
     * For applications without a minimum latency, once all KLV for the
     * associated timestamp has been passed to the 'mediaKLVData' function,
     * combining should be disabled to send the packet to the multiplexer.
     *
     * @param _combine  'true' to enable KLV combining, 'false' otherwise.
     */
    virtual void combineKLV(bool _combine) = 0;
};

/**
 * The MetadataInjector is used to inject KLV metadata into an existing stream.
 * The output is always MPEG-2 Transport Stream (TS).
 *
 * The injector can be used to inject either synchronous or asynchronous KLV
 * metadata into the stream. If the appropriate stream type does not exist in
 * the input source, a new stream is added to the output.
 *
 * A latency buffering period may be specified (0 by default), which buffers the
 * specified amount of data before before multiplexing to the output sink. This
 * allows for the injection and interleaving of KLV data with timestamps prior
 * to the current media time provided it is within the buffering period.
 * Injected KLVData with a timestamp greater than the current media time will be
 * buffered until it can be interleaved appropriately. For file based injection
 * activities, this means that all KLV to be injected may be buffered prior to
 * calling open. Injected KLVData with a timestamp less than the current media
 * time minus the minimum latency will be injected at the current time minus the
 * minimum latency. A special timestamp value of -1 may be used to inject the
 * associated KLVData at the current media time.
 *
 * If EOF is encountered during the injection activity, the MetadataInjector is
 * automatically closed.
 */
class MetadataInjector {
public :
    /**
     * Creates a new MetadatInjector. The injector is not yet connected to an
     * input stream.
     *
     * @param syncMetadata  If 'true', synchronous metadata will be injected,
     *                      otherwise, asynchronous metadata will be injected.
     */
    MetadataInjector(bool syncMetadata) throw (MediaException)
                            : klvinjector(NULL)
    {
        cinjector = MetadataInjector_create(syncMetadata);
        if(!cinjector)
            throw MediaException();
        sink.opaque = NULL;
        sink.dataSinkWrite = dataSinkRedirect;

        status_consume.mediaStreamExtentsUpdate =
                            &CallbackRedirect::mediaStreamExtentsUpdate;
        status_consume.mediaEOF = &CallbackRedirect::mediaEOF;
        status_consume.mediaFatalError = &CallbackRedirect::mediaFatalError;
        status_consume.mediaOpened = &mediaOpenedRedirect;
        status_consume.mediaTimeUpdate = &mediaTimeUpdateRedirect;
    }

    /**
     * Destroys the MetadataInjector instance. The injector is closed before
     * being destroyed if it is currently open.
     * 
     * @param injector  The injector to be destroyed
     */
    ~MetadataInjector()
    {
        if(klvinjector)
            delete klvinjector;
        MetadataInjector_destroy(cinjector);
    }

    /**
     * Returns a KLVConsumer that may be used to inject data into the stream.
     *
     * The injection consumer may be obtained at any time once the
     * MetadataInjector has been created. If its mediaKLVData function is
     * be invoked before 'open' has been called, all data passed will be
     * buffered and appropriately interleaved once 'open' is called; the
     * 'mediaKLVData' function may not be called once 'close' has been called.
     *
     * @return  A KLVConsumer that may be used to inject KLV data into the
     *          media stream
     */
    KLVInjector *getKLVInjector() throw (MediaException)
    {
        if(klvinjector)
            return klvinjector;
        KLVInjector_C *injector = MetadataInjector_getKLVInjector(cinjector);
        if(!injector)
            throw MediaException();
        klvinjector = new KLVRedirector(injector);
        return klvinjector;
    }

    /**
     * Sets the minimum latency that will be introduced. This latency period
     * will allow for interleaving of injected data. Data that is injected with
     * a timestamp less than the current media time minus the minimum latency
     * will be injected at the current media time minus the minimum latency.
     *
     * Note that additional latency may be introduced; the minimum latency is a
     * guaranteed overhead that allows for data buffering and interleaving of
     * injected data.
     */
    void setMinimumLatency(int latencyMillis)
    {
        MetadataInjector_setMinimumLatency(cinjector, latencyMillis);
    }

    /**
     * Sets the output data sink for the MetadataInjector. This function may
     * only be invoked before 'open' has been called.
     *
     * @param _sink The data sink
     */
    void setOutputSink(MultiplexerDataSink* _sink) throw (MediaException) {
        if(sink.opaque)
            throw MediaException();
        sink.opaque = _sink;
        int err = MetadataInjector_setOutputSink(cinjector, &sink);
        if(err)
            throw MediaException();
    }

    /**
     * Sets the consumer to receive status updates during the metadata injection
     * process. The consumer must be set prior to calling 'open'.
     *
     * @param consumer  The status update consumer
     */
    void setStatusUpdateConsumer(MetadataInjectorStatusUpdateConsumer *consumer)
    {
        status_consume.opaque = consumer;
        if (!consumer)
            MetadataInjector_setStatusUpdateConsumer(cinjector, NULL);
        else
            MetadataInjector_setStatusUpdateConsumer(cinjector,
                                                     &status_consume);
    }

    /**
     * Opens the specified file.
     *
     * @param file  A media file
     *
     * @throw MediaException    If there is an issue opening the media file or
     *                          if the MetadataInjector has not been properly
     *                          configured.
     */
    void openFile(const char *file) throw (MediaException)
    {
        int err = MetadataInjector_openFile(cinjector, file);
        if(err)
            throw MediaException();
    }

    /**
     * Opens the specified UDP stream.
     *
     * @param mcastAddr The multicast address (NULL for unicast)
     * @param port      The port
     * @param timeout   The timeout, in milliseconds
     *
     * @throw MediaException    If there is an issue opening the media stream or
     *                          if the MetadataInjector has not been properly
     *                          configured.
     */
    void openStream(const char *mcastAddr,
                    int port,
                    int timeout) throw (MediaException)
    {
        int err = MetadataInjector_openStream(cinjector, mcastAddr, port, timeout);
        if(err)
            throw MediaException();
    }

    /**
     * Opens the RTSP source.
     *
     * @param addr      The RTSP address
     * @param timeout   The timeout, in milliseconds
     *
     * @throw MediaException    If there is an issue opening the media source or
     *                          if the MetadataInjector has not been properly
     *                          configured.
     */
    void openRtsp(const char *addr,
                  unsigned int timeout) throw (MediaException)
    {
        int err = MetadataInjector_openRtsp(cinjector, addr, timeout);
        if(err)
            throw MediaException();
    }

    /**
     * Closes the metadata injector. All buffered data will be multiplexed and
     * any remaining output flushed to the output data sink.
     */
    void close()
    {
        MetadataInjector_close(cinjector);
    }
private :
    static int dataSinkRedirect(const unsigned char* buf, int len, void *opaque)
    {
        MultiplexerDataSink *c = (MultiplexerDataSink *)opaque;
        return c->dataSinkWrite(buf, len);
    }

    static void mediaOpenedRedirect(void *opaque, long mediaTimeMillis)
    {
        MetadataInjectorStatusUpdateConsumer *c = (MetadataInjectorStatusUpdateConsumer *)opaque;
        c->mediaOpened(mediaTimeMillis);
    }

    static void mediaTimeUpdateRedirect(void *opaque, long mediaTimeMillis)
    {
        MetadataInjectorStatusUpdateConsumer *c = (MetadataInjectorStatusUpdateConsumer *)opaque;
        c->mediaTimeUpdate(mediaTimeMillis);
    }

    class KLVRedirector : public KLVInjector {
        public :
            virtual void mediaKLVData(KLVData *data) {
                injector->mediaKLVData(injector->opaque, data);
            }

            virtual void combineKLV(bool enabled) {
                injector->combineKLV(injector->opaque, enabled);
            }
        protected:
            virtual ~KLVRedirector() {}
        private :
            KLVRedirector(KLVInjector_C *c) : injector(c) {}

            KLVInjector_C *injector;

            friend class MetadataInjector;
    };

    MetadataInjector_C cinjector;
    KLVRedirector *klvinjector;
    MultiplexerDataSink_C sink;
    MetadataInjectorStatusUpdateConsumer_C status_consume;
};

}; // end PGSCMedia namespace

#endif
