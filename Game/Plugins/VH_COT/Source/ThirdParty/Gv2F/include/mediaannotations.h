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

#ifndef PGSC_MEDIAANNOTATIONS_H
#define PGSC_MEDIAANNOTATIONS_H

#include <stdint.h>
#include <stdlib.h>
#include <vector>

#include "mediaannotations_c.h"
#include "mediaconsumers.h"

namespace PGSCMedia {


/**
 * Interface for managing annotations in a media stream that can
 * carry KLV metadata.
 * The interface allows access to existing annotations in a source media
 * clip, as well as providing a way to create new annotations.  Methods
 * to modify both existing and new annotations are provided.  Exports
 * of the media will reflect the changes made in the form of new/updated
 * KLV metadata compliant with MISB RP0602.
 * To obtain this interface, see MediaProcessor's getAnnotations() method.
 *
 * Annotations can be composed of one of several types of source data.
 * See the MediaAnnotationType for the list of currently supported
 * annotation types.
 * Annotations are located on media frames by way of an X and Y coordinate.
 * The origin for the coordinate system is the upper-left corner of the
 * media frame.  The X and Y coordinate specifies the origin/anchor point
 * of the annotation data. NOTE: This origin/anchor point is dependent
 * on annotation type!  See the MediaAnnotationType enumeration documentation
 * for the origin/anchor points for each type of annotation.
 *
 * Annotation Life-Cycle:
 * Annotation objects created/provided by this interface are "live" internal
 * objects that update to reflect changes to them (made by the client
 * of this interface through its direct calls, or by changes encoded
 * in the source media stream) as the source MediaProcessor "plays" through
 * the media.
 * When the source processor is in a stopped state, using the annotation
 * objects of this interface is very simplistic.  The current set of 
 * annotations for the current media time can be obtained, manipulated
 * as desired, additional annotations added, etc without concern for
 * the internal machinery modifying or invalidating the annotation objects
 * concurrently.
 * If utilizing annotation objects when the source processor is in a 
 * started/playing state, it is required to install an AnnotationUpdateConsumer
 * via setConsumer and to react to its events. The events posted to the
 * consumer provide notification of changes being made to the annotation
 * objects by the internal machinery. Accessing annotation objects during
 * playback without properly reacting to the consumer events will result
 * in undefined behavior.
 *
 * AnnotationUpdateConsumer callbacks are not guaranteed to occur
 * synchronously with annotation modifier function calls in this interface.
 * For example, calling deleteAnnotation() may not cause an 
 * annotationsDeleted() callback to occur prior to the completion and return
 * of deleteAnnotation();  it may occur a short time later.
 *
 * Re-entrancy and Multi-threading Constraints:
 * Multiple concurrent calls into the same interface instance
 * may not be made. In addition, concurrent calls into this
 * interface and the parent processor may not be made.
 * Doing so will result in undefined behavior.
 *
 * In addition, calling back to a MediaAnnotations API function from
 * an AnnotationUpdateConsumer callback implementation will result in
 * undefined behavior.
 */
class MediaAnnotations {

public:

    /**
     * Add a new annotation at the current media position.
     * The new annotation is created from the data provided, which is of
     * the specified length and annotation data type.  This data buffer is
     * internally copied and only needs to remain valid for the duration of
     * this call.  The annotation's anchor point is set to the provided x
     * and y location. The returned value is the newly created annotation;
     * the returned MediaAnnotation remains valid for access and manipulation
     * as long as the source MediaProcessor is stopped or, if running, 
     * until a deletion callback is posted to an installed consumer.
     */
    const MediaAnnotation *addAnnotation(const char *data,
                                         int len, 
                                         MediaAnnotationType type,
                                         int xloc, int yloc)
    {
        return MediaAnnotations_addAnnotation(cannos, data, len, 
                                              type, xloc, yloc);
    }

    /**
     * Delete the specified annotation. The entirely parameter specifies
     * the scope of the deletion.  If true, the annotation is removed
     * from all points in the media.  If false, the annotation is retained
     * at points prior to the current media position, but is removed
     * from the current media position forward in media time.
     * Returns true if the delete is successful, false otherwise.
     */
    bool deleteAnnotation(const MediaAnnotation *annotation, bool entirely)
    {
        return MediaAnnotations_deleteAnnotation(cannos, annotation, 
                                                 entirely) != 0;
    }
    
    /**
     * Relocate the specified annotation.  The relocation changes the position
     * of the annotation on the frame, but all other aspects of the
     * annotation remain the same.  The movement is reflected at the current
     * media position. The overrideSubsequent argument specifies how this move
     * influences the annotation later in the media timeline.  If true,
     * existing movements, modifications, and deletions subsequent in time
     * are discarded in favor of this newly specified position and current
     * position.
     * If false, existing moves, modifies, and deletes subsequent in media
     * time are left as-is.
     * Regardless of the value of overrideSubsequent, the position prior
     * to the current media position is unchanged.
     * Returns true if the move was successful, false otherwise.
     */
    bool moveAnnotation(const MediaAnnotation *annotation, int xloc, int yloc,
                        bool overrideSubsequent)
    {
        return MediaAnnotations_moveAnnotation(cannos, annotation, xloc, yloc,
                                        overrideSubsequent ? 1 : 0) != 0;
    }
    
    /**
     * Change the actual data bytes associated with the annotation.
     * The new data must be of the same data type that the annotation
     * currently is.  The provided data is internally copied and need only
     * be valid for the duraction of this call.  
     * The modification is reflected at the current
     * media position. The overrideSubsequent argument specifies how this 
     * modification influences the annotation later in the media timeline.
     * If true, existing movements, modifications, and deletions subsequent
     * in time are discarded in favor of the new data and current position.
     * If false, existing moves, modifies, and deletes subsequent in media
     * time are left as-is.
     * Regardless of the value of overrideSubsequent, the data bytes 
     * comprising the annotation prior to the current media position
     * are left unchanged.
     * Returns true if the modification is successful, false otherwise.
     */
    bool modifyAnnotation(const MediaAnnotation *annotation,
                          const char *data, int len, bool overrideSubsequent)
    {
        return MediaAnnotations_modifyAnnotation(cannos, annotation, data,
                                          len, overrideSubsequent) != 0;
    }

    /**
     * Obtain the set of annotations that is active ("on screen") 
     * at the current media position. Note that if the source MediaProcessor
     * is in a "running" state, then this information and indeed the 
     * data contents of the annotations themselves may change
     * as the media plays back.
     * Thus, if you utilize the returned items while the source MediaProcessor
     * is running, you must install and properly react to the events 
     * that are dispatched to the AnnotationUpdateConsumer.
     * If using the returned values solely when the MediaProcessor is stopped,
     * an AnnotationUpdateConsumer is not strictly necessary, however the
     * returned objects may still change and/or become invalid if the object
     * is passed to modification methods of this interface.
     * See this interface's main documentation for more on annotation
     * object life cycles.
     */
    std::vector<const MediaAnnotation *> getCurrentAnnotations()
    {
        const MediaAnnotation **a;
        int n = MediaAnnotations_getCurrentAnnotations(cannos, &a);
        std::vector<const MediaAnnotation *> ret;
        for (int i = 0; i < n; ++i)
            ret.push_back(a[i]);
        MediaAnnotations_releaseAnnotationArray(cannos, a);
        return ret;
    }

    /**
     * Configure a consumer to receive updates relevant to changes in
     * the current state of annotation objects. See the
     * AnnotationUpdateConsumer for more information.
     */
    void setConsumer(AnnotationUpdateConsumer *consumer)
    {
        anno_consume.opaque = consumer;
        if (!consumer)
            MediaAnnotations_setConsumer(cannos, NULL);
        else
            MediaAnnotations_setConsumer(cannos, &anno_consume);
    }
    
private:
    MediaAnnotations(MediaAnnotations_C ciface) : cannos(ciface) {
        anno_consume.annotationsAdded = &CallbackRedirect::annotationsAdded;
        anno_consume.annotationsDeleted = 
                                      &CallbackRedirect::annotationsDeleted;
        anno_consume.annotationsAllDeleted =
                                   &CallbackRedirect::annotationsAllDeleted;
        anno_consume.annotationsUpdating = 
                                     &CallbackRedirect::annotationsUpdating;
        anno_consume.annotationsUpdated = 
                                      &CallbackRedirect::annotationsUpdated;
    }
    ~MediaAnnotations() {
    }

    MediaAnnotations_C cannos;
    AnnotationUpdateConsumer_C anno_consume;

    friend class MediaProcessor;    
};


};  // End of namespace

#endif
