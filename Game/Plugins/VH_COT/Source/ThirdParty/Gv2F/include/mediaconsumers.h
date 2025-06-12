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

#ifndef PGSC_MEDIACONSUMERS_H
#define PGSC_MEDIACONSUMERS_H

#include <stdint.h>
#include "mediaconsumers_c.h"
#include "mediaannotations_type_c.h"
#include "mediaannotations_c.h"

namespace PGSCMedia {


/*
 * Interface that consumers of video frames must implement.
 * See the general comments on Consumers in the class documentation of
 * MediaProcessor.
 */
class VideoConsumer {
public:
    /*
     * Interface function that receives video frames as they are
     * decoded and their presentation time is reached.
     */
    virtual void mediaVideoFrame(const VideoFrameData *frame) = 0;
};


/*
 * Interface that consumers of KLV track data must implement.
 * See the general comments on Consumers in the class documentation of
 * MediaProcessor.
 */
class KLVConsumer {
public:
    /*
     * Interface function that receives KLV frames as they are parsed
     * and their presentation time is reached.
     */
    virtual void mediaKLVData(KLVData *data) = 0;
};

/*
 * Interface that consumers of ESD closed-caption metadata must implement.
 * See the general comments on Consumers in the class documentation of
 * MediaProcessor.
 */
class ESDConsumer {
public:
    /*
     * Interface function that receives ESD closed-caption metadata as it is
     * encountered in the stream.
     *
     * @param esd   An array of ESDClosedCaptionData pointers, NULL terminated
     * @param len   The number of entries in 'esd' (excluding the NULL
     *              terminator).
     */
    virtual void mediaESDData(const ESDClosedCaptionData **esd,
                              int len) = 0;
};

/*
 * Interface that consumers of the raw incoming data must implement.
 * See the general comments on Consumers in the class documentation of
 * MediaProcessor.
 */
class MediaConsumer {
public:
    /*
     * Interface function that receives incoming stream data as it
     * arrives and is processed.
     * When the end of the source stream is detected, this callback
     * will be called one additional time with length = 0 and 
     * bytes = NULL.
     */
    virtual void mediaBytes(int length, const uint8_t *bytes) = 0;
};


/*
 * Interface for receiving general MediaProcessor status changes.
 */
class StatusUpdateConsumer {
public:
    /*
     * For streaming source media, this callback will be invoked
     * whenever the extents of the source data buffer change.
     * The arguments represent the number of milliseconds since the stream
     * began to the start and end of the buffered region, respectively.
     * @param startMillis number of milliseconds from start of streaming to
     *                    the beginning of the buffered region
     * @param endMillis number of milliseconds from start of streaming to
     *                    the end of the buffered region
     */
    virtual void mediaStreamExtentsUpdate(long startMillis, long endMillis) = 0;
    
    /*
     * This callback is invoked whenever playback/processing reaches the end
     * of the source data and the last of any buffered data is decoded and
     * output.
     * When this event occurs, playback ceases as there is no more data
     * to process/playback.
     */
    virtual void mediaEOF(void) = 0;
    
    /*
     * This callback is invoked whenever a fatal internal error
     * occurs while processing the media.  Following this event,
     * processing/playback is stopped and will no longer be able to be
     * resumed.
     * The argument may contain some additional detail about the problem
     * that was encountered.
     * @param info additional information about the fatal error; may be NULL
     *         if no additional information is available
     */
    virtual void mediaFatalError(const char *info) = 0;
};

/**
 * Annotation status update consumer interface
 * Receives life-cycle event notifications about annotations.
 * See MediaAnnotations documentation for more information about the
 * life-cycle of an annotation object.
 * See the generalized discussion of Consumers in the Processor class 
 * documentation for some general rules/concepts about Consumer implementations
 * and usage. In addition to those general items, the following specific items
 * apply to AnnotationUpdateConsumers:
 * - Contrary to most Consumers, multiple callbacks to different callback
 *   functions in this Consumer will not occur simultaneously.
 * - Calls to the Annotations interface may *not* be made from within a
 *   callback;  doing so results in undefined behavior.
 * - Contrary to most other Consumer callbacks, most
 *   AnnotationUpdateConsumer callbacks provide pointers 
 *   which remain valid after the callback completes.  See specific callback
 *   documentation for more details. Note that while the pointers to the
 *   individual MediaAnnotation objects in many of these callbacks remain
 *   valid after completion of the callback, the arrays in which those
 *   pointers are supplied do not.
 */
class AnnotationUpdateConsumer {
public:
    /**
     * The supplied annotations have been added to the set of currently
     * "active" annotations that should be presented along with the
     * other media (video frames, etc).
     * The annotation objects remain valid until a delete
     * notification for it is received.
     */
    virtual void annotationsAdded(const MediaAnnotation **annos, int len) = 0;

    /**
     * The indicated annotations have been removed from the set of
     * currently "active" annotations. They should be removed from
     * active presentation and, at the completion of this notification,
     * any reference to the indicated MediaAnnotation objects are no
     * longer valid.
     */
    virtual void annotationsDeleted(const MediaAnnotation **annos, int len)=0;

    /**
     * All annotations have been removed from the set of
     * currently "active" annotations; any previously
     * obtained MediaAnnotation object references become invalid at the
     * conclusion of this notification.
     */
    virtual void annotationsAllDeleted() = 0;

    /**
     * The specified annotations will be modified.  This function is
     * provided as a hook for consumers to provide proper synchronization
     * to protect against concurrent use by the client and modification by
     * the library of an annotation.
     * Any modification to the member fields of an annotation will not
     * happen until this callback completes; once the modifications are
     * subsequently made, a callback to annotationUpdated() will be made.
     * Only one batch of updates will be active at any one time; that is
     * multiple calls to this callback will not occur without a 
     * corresponding call to annotationModified having occurred in between.
     */
    virtual void annotationsUpdating(const MediaAnnotation **annos, int len)=0;

    /**
     * The specified annotations have been modified and the member fields
     * should be re-examined by the consumer to update visual representations
     * or other uses of the annotation.
     * The consumer should release any exclusivity synchronizations it locked
     * in a prior call to annotationsUpdating. 
     */
    virtual void annotationsUpdated(const MediaAnnotation **annos, int len)=0;

};



class CallbackRedirect {
  public:
    static void mediaVideoFrame(void *opaque, const VideoFrameData *frame)
    {
        VideoConsumer *c = (VideoConsumer *)opaque;
        c->mediaVideoFrame(frame);
    }

    static void mediaKLVData(void *opaque, KLVData *data)
    {
        KLVConsumer *c = (KLVConsumer *)opaque;
        c->mediaKLVData(data);
    }

    static void mediaESDData(void *opaque, const ESDClosedCaptionData **data, int len)
    {
        ESDConsumer *c = (ESDConsumer *)opaque;
        c->mediaESDData(data, len);
    }

    static void mediaBytes(void *opaque, int length, const uint8_t *bytes)
    {
        MediaConsumer *c = (MediaConsumer *)opaque;
        c->mediaBytes(length, bytes);
    }

    static void mediaStreamExtentsUpdate(void *opaque, long startMillis, 
                                  long endMillis)
    {
        StatusUpdateConsumer *c = (StatusUpdateConsumer *)opaque;
        c->mediaStreamExtentsUpdate(startMillis, endMillis);
    }

    static void mediaEOF(void *opaque)
    {
        StatusUpdateConsumer *c = (StatusUpdateConsumer *)opaque;
        c->mediaEOF();
    }

    static void mediaFatalError(void *opaque, const char *info)
    {
        StatusUpdateConsumer *c = (StatusUpdateConsumer *)opaque;
        c->mediaFatalError(info);
    }

    static void annotationsAdded(void *opaque, const MediaAnnotation **annos,
                                 int len)
    {
        AnnotationUpdateConsumer *c = (AnnotationUpdateConsumer *)opaque;
        c->annotationsAdded(annos, len);
    }

    static void annotationsDeleted(void *opaque, const MediaAnnotation **annos,
                                   int len)
    {
        AnnotationUpdateConsumer *c = (AnnotationUpdateConsumer *)opaque;
        c->annotationsDeleted(annos, len);
    }

    static void annotationsAllDeleted(void *opaque)
    {
        AnnotationUpdateConsumer *c = (AnnotationUpdateConsumer *)opaque;
        c->annotationsAllDeleted();
    }

    static void annotationsUpdating(void *opaque, 
                                    const MediaAnnotation **annos,
                                    int len)
    {
        AnnotationUpdateConsumer *c = (AnnotationUpdateConsumer *)opaque;
        c->annotationsUpdating(annos, len);
    }

    static void annotationsUpdated(void *opaque, const MediaAnnotation **annos,
                                   int len)
    {
        AnnotationUpdateConsumer *c = (AnnotationUpdateConsumer *)opaque;
        c->annotationsUpdated(annos, len);
    }


};


};  // End of namespace

#endif
