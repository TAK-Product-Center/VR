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

#ifndef PGSC_MEDIAANNOTATIONS_C_H
#define PGSC_MEDIAANNOTATIONS_C_H

#include "mediaannotations_type_c.h"
#include "mediaconsumers_c.h"

#ifdef __cplusplus 
extern "C" {
#endif


typedef void* MediaAnnotations_C;

const MediaAnnotation *MediaAnnotations_addAnnotation(
                       MediaAnnotations_C iface, const char *data,
                       int len, MediaAnnotationType type,
                       int xloc, int yloc);

int  MediaAnnotations_deleteAnnotation(MediaAnnotations_C iface, 
                                       const MediaAnnotation *annotation,
                                       int entirely);
int  MediaAnnotations_moveAnnotation(MediaAnnotations_C iface, 
                                     const MediaAnnotation *annotation,
                                     int xloc, int yloc,
                                     int overrideSubsequent);
int  MediaAnnotations_modifyAnnotation(MediaAnnotations_C iface, 
                                       const MediaAnnotation *annotation,
                                       const char *data, int len,
                                       int overrideSubsequent);
int MediaAnnotations_getCurrentAnnotations(MediaAnnotations_C iface, 
                                           const MediaAnnotation ***annos);
void MediaAnnotations_releaseAnnotationArray(MediaAnnotations_C iface, 
                                             const MediaAnnotation **annos);

void MediaAnnotations_setConsumer(MediaAnnotations_C iface, 
                                  AnnotationUpdateConsumer_C *consumer);



#ifdef __cplusplus 
}; // End extern "C"
#endif

#endif
