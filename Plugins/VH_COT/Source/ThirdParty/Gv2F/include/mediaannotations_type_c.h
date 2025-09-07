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

#ifndef PGSC_MEDIAANNOTATIONS_TYPE_C_H
#define PGSC_MEDIAANNOTATIONS_TYPE_C_H

#ifdef __cplusplus 
extern "C" {
#endif


typedef enum {
    /**
     * Annotation type indicator for CGM vector-based graphics.
     * The origin/anchor point for CGM images is the origin of the
     * CGM's VDC.
     */
    ANNOTYPE_CGM
} MediaAnnotationType;

/**
 * Annotation structure.
 */
typedef struct MediaAnnotation_s {
    /** Data of the type indicated by 'type' and length 'len'. */
    char *data;

    /** Length of the data field */
    int len;

    /**
     * Type of the annotation data in 'data'.  
     * Also specifies interpretation of x and y location
     */
    MediaAnnotationType type;
    
    /** X-location, relative to left side of video frames */
    int x;

    /** Y-location, relative to top of video frames */
    int y;
} MediaAnnotation;


#ifdef __cplusplus 
}; // End extern "C"
#endif

#endif
