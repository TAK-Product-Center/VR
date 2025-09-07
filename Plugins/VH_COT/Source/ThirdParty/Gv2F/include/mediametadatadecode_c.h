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

#ifndef PGSC_METADATADECODE_C_H
#define PGSC_METADATADECODE_C_H

#include "mediaconsumers_c.h"
#include "mediaannotations_type_c.h"

#ifdef __cplusplus 
extern "C" {
#endif

/**
 * Defines the various metadata sources supported by
 * 'MediaMetadataDecode_decode'.
 */
typedef enum {
    METADATA_SRCTYPE_KLV, // struct KLVData
    METADATA_SRCTYPE_ESD, // array of struct ESDClosedCaptionData, NULL
                          // terminated
} MetadataSourceTypes;

/**
 * Defines the various value types that may be represented in a
 * 'DecodedMetadataItem'.
 */
typedef enum {
    /** Signed integer, up to 32 bits */
    METADATA_VALTYPE_INT,
    /** Signed long integer, up to 64 bits */
    METADATA_VALTYPE_LONG,
    /** Floating-point value, 64 bits */
    METADATA_VALTYPE_FLOAT,
    /** ASCII string data */
    METADATA_VALTYPE_ASCII,
    /** byte data */
    METADATA_VALTYPE_BINARY,
} MetadataValueTypes;

typedef enum {
    // predator metadata common items
    /**
     * Coordinated Universal Time (UTC) represented in the number of
     * microseconds elapsed since midnight (00:00:00), January 1, 1970.
     *
     * <P>Representation: METADATA_VALTYPE_LONG</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 UNIX Time Stamp (Tag 2)</LI>
     *  <LI>MISB EG 0104 User Defined Time Stamp (UL
     *      060E2B34010101030702010101050000)</LI>
     * </UL>
     */
    METADATA_ITEMID_UNIX_TIME_STAMP = 0x00000001, 

    /**
     * Descriptive Mission Identifier to distinguish event or sortie.
     *
     * <P>Representation: METADATA_VALTYPE_STRING</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Mission ID (Tag 3)</LI>
     *  <LI>MISB EG 0104 Episode Number (UL 060E2B34010101010105050000000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_MISSION_ID, 

    /**
     * Aircraft heading angle. Relative between longitudinal axis and True North
     * measured in the horizontal plane.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Heading Angle (Tag 5)</LI>
     *  <LI>MISB EG 0104 Platform Heading Angle (UL
     *      060E2B34010101070701100106000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_HEADING_ANGLE, 

    /**
     * Aircraft pitch angle. Angle between longitudinal axis and horzontal
     * plane. Positive angles above horizontal plane.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Pitch Angle (Tag 6)</LI>
     *  <LI>MISB EG 0104 Platform Pitch Angle (UL
     *      060E2B34010101070701100105000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_PITCH_ANGLE, 

    /**
     * Platform roll angle. Angle between transverse axis and horizontal plane.
     * Positive angles for right wing lowered below horizontal plane.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Roll Angle (Tag 7)</LI>
     *  <LI>MISB EG 0104 Platform Roll Angle (UL
     *      060E2B34010101070701100106000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_ROLL_ANGLE, 

    /**
     * The platform designation metadata item distinguishes which platform is
     * carrying the motion imagery generating payload equipment.
     *
     * <P>Representation: METADATA_VALTYPE_STRING</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Designation (Tag 10)</LI>
     *  <LI>MISB EG 0104 Device Designation (UL
     *      060E2B34010101010101200100000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_DESIGNATION, 

    /**
     * The name of the sensor.
     *
     * <P>Representation: METADATA_VALTYPE_STRING
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Image Source Sensor (Tag 11)</LI>
     *  <LI>MISB EG 0104 Image Source Device (UL
     *      060E2B34010101010420010201010000)</LI>
     * </UL>
     */
    METADATA_ITEMID_IMAGE_SOURCE_SENSOR, 

    /**
     * String of the image coordinate system used.
     *
     * <P>Representation: METADATA_VALTYPE_STRING</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Image Coordinate System (Tag 12)</LI>
     *  <LI>MISB EG 0104 Image Coordinate System (UL
     *      060E2B34010101010701010100000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_IMAGE_COORDINATE_SYSTEM, 

    /**
     * Sensor Latitude. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Latitude (Tag 13)</LI>
     *  <LI>MISB EG 0104 Device Latitude (UL 
     *      060E2B34010101030701020102040200)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_LATITUDE, 

    /**
     * Sensor Longitude. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Longitude (Tag 14)</LI>
     *  <LI>MISB EG 0104 Device Longitude (UL 
            060E2B34010101030701020102060200)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_LONGITUDE, 

    /**
     * Altitude of sensor as measured from Mean Sea Level (MSL).
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor True Altitude (Tag 15)</LI>
     *  <LI>MISB EG 0104 Device Altitude (UL 060E2B34010101010701020102020000)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_TRUE_ALTITUDE, 

    /**
     * Horizontal field of view of selected imaging sensor.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Horizontal Field of View (Tag 16)</LI>
     *  <LI>MISB EG 0104 Field of View (Horizontal) (UL
     *      060E2B34010101020420020101080000)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_HORIZONTAL_FIELD_OF_VIEW, 

    /**
     * Vertical field of view of selected imaging sensor.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Vertical Field of View (Tag 17)</LI>
     *  <LI>MISB EG 0104 Field of View (Vertical) (UL
     *      060E2B340101010204200201010A0100)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_VERTICAL_FIELD_OF_VIEW, 

    /**
     * Slant range in meters. Distance to target.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Slant Range (Tag 21)</LI>
     *  <LI>MISB EG 0104 Slant Range (UL 060E2B34010101010701080101000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_SLANT_RANGE, 

    /**
     * Target Width within sensor field of view. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Width (Tag 22)</LI>
     *  <LI>MISB EG 0104 Target Width (UL 060E2B34010101010701090201000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_WIDTH, 

    /**
     * Terrain Latitude of frame center. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Frame Center Latitude (Tag 23)</LI>
     *  <LI>MISB EG 0104 Frame Center Latitude (UL
     *      060E2B34010101010701020103020000)</LI>
     * </UL>
     */
    METADATA_ITEMID_FRAME_CENTER_LATITUDE, 

    /**
     * Terrain Longitude of frame center. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Frame Center Longitude (Tag 24)</LI>
     *  <LI>MISB EG 0104 Frame Center Longitude (UL
     *      060E2B34010101010701020103040000)</LI>
     * </UL>
     */
    METADATA_ITEMID_FRAME_CENTER_LONGITUDE, 

    /**
     * Terrain elevation at frame center relative to Mean Sea Level (MSL).
     * Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Frame Center Elevation (Tag 25)</LI>
     *  <LI>MISB EG 0104 Frame Center Elevation (UL
     *      060E2B340101010A0701020103160000)</LI>
     * </UL>
     */
    METADATA_ITEMID_FRAME_CENTER_ELEVATION, 

    /**
     * Frame Latitude for upper left corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Latitude Point 1 (Tag 26)</LI>
     *  <LI>MISB EG 0104 Corner Latitude Point 1 (UL
     *      060E2B34010101030701020103070100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LATITUDE_POINT_1, 

    /**
     * Frame Longitude for upper left corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Longitude Point 1 (Tag 27)</LI>
     *  <LI>MISB EG 0104 Corner Longitude Point 1 (UL
     *      060E2B340101010307010201030B0100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LONGITUDE_POINT_1, 

    /**
     * Frame Latitude for upper right corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Latitude Point 2 (Tag 28)</LI>
     *  <LI>MISB EG 0104 Corner Latitude Point 2 (UL
     *      060E2B34010101030701020103080100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LATITUDE_POINT_2, 

    /**
     * Frame Longitude for upper right corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Longitude Point 2 (Tag 29)</LI>
     *  <LI>MISB EG 0104 Corner Longitude Point 2 (UL
     *      060E2B340101010307010201030C0100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LONGITUDE_POINT_2, 

    /**
     * Frame Latitude for lower right corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Latitude Point 3 (Tag 30)</LI>
     *  <LI>MISB EG 0104 Corner Latitude Point 3 (UL
     *      060E2B34010101030701020103090100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LATITUDE_POINT_3, 

    /**
     * Frame Longitude for lower right corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Longitude Point 3 (Tag 31)</LI>
     *  <LI>MISB EG 0104 Corner Longitude Point 3 (UL
     *      060E2B340101010307010201030D0100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LONGITUDE_POINT_3, 

    /**
     * Frame Latitude for lower left corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Latitude Point 4 (Tag 32)</LI>
     *  <LI>MISB EG 0104 Corner Latitude Point 4 (UL
     *      060E2B340101010307010201030A0100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LATITUDE_POINT_4, 

    /**
     * Frame Longitude for lower left corner. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Offset Corner Longitude Point 4 (Tag 33)</LI>
     *  <LI>MISB EG 0104 Corner Longitude Point 4 (UL
     *      060E2B340101010307010201030E0100)</LI>
     * </UL>
     */
    METADATA_ITEMID_CORNER_LONGITUDE_POINT_4, 

    /**
     * Start time of scene, project, event, mission, editing event, license,
     * publication, etc. Represented as the microseconds elapsed since midnight
     * (00:00:00), January 1, 1970.
     *
     * <P>Representation: METADATA_VALTYPE_LONG</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Event Start Time UTC (Tag 72)</LI>
     *  <LI>MISB EG 0104 Event Start Date Time UTC (UL
     *      060E2B34010101010702010207010000)</LI>
     * </UL>
     */
    METADATA_ITEMID_EVENT_START_TIME_UTC, 

    /************************************************************************/
    // MISB STD 0102
    /**
     * This metadata element contains a value representing the entire security
     * classification of the file in accordance with U.S. and NATO
     * classification guidance. Values allowed are: TOP SECRET, SECRET,
     * CONFIDENTIAL, RESTRICTED, and UNCLASSIFIED (all caps) followed by a
     * double forward slash “//”. This is a mandatory entry whenever the Security
     * Metadata Sets are used.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Security Classification (Tag 1, UL
     *      060E2B34010101030208020100000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_SECURITY_CLASSIFICATION = 0x00000101,

    /**
     * This metadata element identifies the country coding method for the
     * Classifying Country and Releasing Instructions metadata. Examples of the
     * Country Coding Method include FIPS 10-4 two-letter or four-letter
     * alphabetic country code; ISO-3166 two-letter, three-letter, or 3-digit
     * numeric; or STANAG 1059 two-letter or three-letter codes.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Classifying Country and Releasing Instructions Country
     *      Coding Method (Tag 2, UL 060E2B34010101030701200102070000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CLASSIFYING_COUNTRY_AND_RELEASING_INSTRUCTIONS_COUNTRY_CODING_METHOD,

    /**
     * This metadata element contains a value for the classifying country code
     * preceded by a double slash "//."
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Classifying Country (Tag 3, UL
     *      060E2B34010101030701200102080000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CLASSIFYING_COUNTRY,

    /**
     * If the classification of any material in the transport stream or file is
     * Top Secret, Secret, or Confidential and requires special handling, then
     * SCI/SHI digraphs, trigraphs, or compartment names must be added
     * identifying a single or a combination of special handling instructions. A
     * single entry shall be ended with a double forward slash “//”. Multiple
     * digraphs, trigraphs, or compartment names shall be separated by a single
     * forward slash “/” and the last entry shall be ended with a double forward
     * slash “//”.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Security-SCI/SHI Information (Tag 4, UL
     *      060E2B34010101010E01020302000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_SECURITY_SCISHI_INFORMATION,

    /**
     * This metadata element set contains a value representing all pertinent
     * caveats (or codewords) from each category of the appropriate security
     * entity register. Entries in this field may be abbreviated or spelled out
     * as free-text entries. The Caveats field shall also be used to indicate
     * FOR OFFICIAL USE ONLY or may be abbreviated as FOUO.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Caveats (Tag 5, UL 060E2B34010101030208020200000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CAVEATS,

    /**
     * This metadata element contains a list of country codes to indicate the
     * countries to which information in a digital motion imagery file is
     * releasable. Multiple country codes shall be separated by a blank (space,
     * NOT underscore). Multiple country codes shall be concatenated in one
     * Releasing Instructions metadata element entry. The use of blank spaces to
     * separate country codes, instead of semi-colons or other characters, is to
     * comply with security guidelines and to allow parsing of fields by
     * automated security screening systems. The country code of the originating
     * country shall appear first, then the country codes of other countries to
     * which the data are releasable shall appear in alphabetical order, and,
     * finally, the codes of any non-state organizations (such as NATO) to which
     * the data are releasable shall appear in alphabetical order.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Releasing Instructions (Tag 6, UL
     *      060E2B34010101030701200102090000)</LI>
     * </UL>
     */
    METADATA_ITEMID_RELEASING_INSTRUCTIONS,

    /**
     * This metadata element identifies the name and type of authority used to
     * classify the file. The metadata element is free text and can contain
     * either the original classification authority name and position or
     * personal identifier, or the title of the document or security
     * classification guide used to classify the material.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Classified By (Tag 7, UL
     *      060E2B34010101030208020300000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CLASSIFIED_BY,

    /**
     * This metadata element contains information about the original source file
     * or document from which the classification was derived.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Derived From (Tag 8, UL
     *      060E2B34010101030208020600000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_DERIVED_FROM,

    /**
     * This metadata element identifies the classification or marking system
     * used in this Security Metadata Set as determined by the appropriate
     * security entity for the country originating the data
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Classification Reason (Tag 9, UL
     *      060E2B34010101030208020400000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CLASSIFICATION_REASON,

    /**
     * This metadata element provides either a date when the classified material
     * may be automatically declassified or if it is subject to Manual Review
     * (MR) and is exempt from automatic declassification. The declassification
     * date format shall be YYYYMMDD or the letters “MR” shall be used.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Declassification Date (Tag 10, UL
     *      060E2B34010101030208020500000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_DECLASSIFICATION_DATE,

    /**
     * This metadata element identifies the classification or marking system
     * used in this Security Metadata Set as determined by the appropriate
     * security entity for the country originating the data.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Classification and Marking System (Tag 11, UL
     *      060E2B34010101030208020800000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CLASSIFICATION_AND_MARKING_SYSTEM,

    /**
     * This metadata element identifies the coding method for the Object Country
     * Code metadata. Examples of the Object Country Coding Method shall include
     * FIPS 10-4 two-letter or four-letter alphabetic country code or a
     * combination of the two; ISO-3166 two-letter, three-letter, or 3-digit
     * numeric or a combination of the three; or STANAG 1059 two-letter,
     * three-letter, or 3-digit numeric codes or a combination of the three.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Object Country Coding Method (Tag 12, UL
     *      060E2B34010101030701200102060000)</LI>
     * </UL>
     */
    METADATA_ITEMID_OBJECT_COUNTRY_CODING_METHOD,

    /**
     * This metadata element contains a value identifying the country (or
     * countries) that is the object of the video or metadata in the transport
     * stream or file. Multiple country codes shall be separated by a semi-colon
     * “;” (no spaces). Multiple country codes shall be concatenated in one
     * Object Country Code metadata element entry and shall not be encoded as
     * individual metadata elements in the Sets. It is required to populate this
     * field with the Object Country Code of the geographic region lying under
     * the center of the frame. The Object Country Codes of other represented
     * geographic regions may be included in addition to the country code of the
     * geographic region under the center of frame. Note: The use of the
     * semi-colon to separate country codes, instead of blanks or other
     * characters, is to allow processing by current, automated imagery
     * processing and management tools.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Object Country Codes (Tag 13, UL
     *      060E2B34010101030701200102010100)</LI>
     * </UL>
     */
    METADATA_ITEMID_OBJECT_COUNTRY_CODES,

    /**
     * This metadata element allows for security related comments and format
     * changes that may be necessary in the future
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Classification Comments (Tag 14, UL
     *      060E2B34010101030208020700000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_CLASSIFICATION_COMMENTS,

    /**
     * The 32-byte UMID defined by SMPTE 330M shall be used to identify the
     * video essence to which security metadata is linked.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 UMID Video (Tag 15, UL
     *      060A2B3401010101010101XY00000000; XY may be 10, 11, 12, 20, 21, 22)</LI>
     * </UL>
     */
    METADATA_ITEMID_UMID_VIDEO,

    /**
     * The 32-byte UMID defined by SMPTE 330M shall be used to identify the
     * audio essence to which security metadata is linked.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 UMID Audio (Tag 16, UL
     *      060A2B3401010101010102XY00000000; XY may be 10, 11, 12, 20, 21, 22)</LI>
     * </UL>
     */
    METADATA_ITEMID_UMID_AUDIO,

    /**
     * The 32-byte UMID defined by SMPTE 330M shall be used to identify the
     * data essence to which security metadata is linked.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 UMID Data (Tag 17, UL
     *      060A2B3401010101010103XY00000000; XY may be 10, 11, 12, 20, 21, 22)</LI>
     * </UL>
     */
    METADATA_ITEMID_UMID_DATA,

    /**
     * The 32-byte UMID defined by SMPTE 330M shall be used to identify the
     * system essence to which security metadata is linked.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 UMID System (Tag 18, UL
     *      060A2B3401010101010104XY00000000; XY may be 10, 11, 12, 20, 21, 22)</LI>
     * </UL>
     */
    METADATA_ITEMID_UMID_SYSTEM,

    /**
     * In MPEG-2 Program Streams the 8-bit stream_id specifies the type and
     * number of the Elementary Stream. In MPEG-2 Transport Streams the
     * stream_id may be set by the user to any valid value which correctly
     * describes the Elementary Stream type. (ISO/IEC 13818-1, par 2.4.3.7 and
     * Table 2-18) The stream_id shall be the Value for the Stream ID metadata
     * element.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Stream ID (Tag 19, UL
     *      060E2B34010101030103040200000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_STREAM_ID,

    /**
     * When multiple Transport Streams are present in a network environment the
     * 16-bit transport_stream_id uniquely identifies a specific Transport
     * Stream from any other Transport Stream to remove any ambiguity. Its value
     * is defined by the originator. (ISO/IEC 13818-1, par 2.4.4.5.) The
     * transport_stream_id shall be the Value for the Transport Stream ID.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Transport Stream ID (Tag 20, UL
     *      060E2B34010101030103040300000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_TRANSPORT_STREAM_ID,

    /**
     * The 16-byte Universal Label Key for the element, set or pack to which the
     * Security Metadata Set is linked shall be the Value of the Universal Label
     * Key ID.
     *
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Item Designator ID (Tag 21, UL
     *      060E2B34010101030103060100000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_ITEM_DESIGNATOR_ID,

    /**
     * The version number of the Security Metadata Universal and Local Set for
     * Digital Motion Imagery is indicated via the Version Key.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0102 Version (Tag 22, UL
     *      060E2B34010101010E01020504000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_MISB0102VERSION,

    /***********************************************************************/
    // MISB STD 0601

    /**
     * Checksum used to detect errors within a UAV Local Data Set packet.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Checksum (Tag 1)</LI>
     * </UL>
     */
    METADATA_ITEMID_MISB0601CHECKSUM = 0x00000201,

    /**
     * Identifier of platform as posted. E.g.: "AF008", "BP101", etc.
     *
     * <P>Representation: METADATA_VALTYPE_ASCII</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Tail Number (Tag 4)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_TAIL_NUMBER,

    /**
     * True airspeed (TAS) of platform. Indicated Airspeed adjusted for
     * temperature and altitude. Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform True Air Speed (Tag 8)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_TRUE_AIR_SPEED,

    /**
     * Indicated airspeed (IAS) of platform. Derived from Pitot tube and static
     * pressure sensors. Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Indicated Air Speed (Tag 9)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_INDICATED_AIR_SPEED,

    /**
     * Relative rotation angle of sensor to platform longitudinal axis. Rotation
     * angle between platform longitudinal axis and camera pointing direction as
     * seen from above the platform.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Relative Azimuth Angle (Tag 18)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_RELATIVE_AZIMUTH_ANGLE,

    /**
     * Relative Elevation Angle of sensor to platform longitudinal-transverse
     * plane. Negative angles down.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Relative Elevation Angle (Tag 19)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_RELATIVE_ELEVATION_ANGLE,

    /**
     * Relative roll angle of sensor to aircraft platform. Twisting angle of
     * camera about lens axis. Top of image is zero degrees. Positive angles are
     * clockwise when looking from behind camera.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Relative Roll Angle (Tag 20)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_RELATIVE_ROLL_ANGLE,

    /**
     * Flag for icing detected at aircraft location.
     * <UL>
     *  <LI>0: Detector off</LI>
     *  <LI>1: No icing Detected</LI>
     *  <LI>2: Icing Detected</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Icing Detected (Tag 34)</LI>
     * </UL>
     */
    METADATA_ITEMID_ICING_DETECTED,

    /**
     * Wind direction at aircraft location. This is the direction the wind is
     * coming from relative to true north.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Wind Direction (Tag 35)</LI>
     * </UL>
     */
    METADATA_ITEMID_WIND_DIRECTION,

    /**
     * Wind speed at aircraft location. Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Wind Speed (Tag 36)</LI>
     * </UL>
     */
    METADATA_ITEMID_WIND_SPEED,

    /**
     * Static pressure at aircraft location. Measured in Millibars.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Static Pressure (Tag 37)</LI>
     * </UL>
     */
    METADATA_ITEMID_STATIC_PRESSURE,

    /**
     * Density altitude at aircraft location. Relative aircraft performance
     * metric based on outside air temperature, static pressure, and humidity.
     * Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Density Altitude (Tag 38)</LI>
     * </UL>
     */
    METADATA_ITEMID_DENSITY_ALTITUDE,

    /**
     * Temperature outside of aircraft. Measured in degrees Celcius.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Outside Air Temperature (Tag 39)</LI>
     * </UL>
     */
    METADATA_ITEMID_OUTSIDE_AIR_TEMPERATURE,

    /**
     * Calculated Target latitude. This is the crosshair location if different
     * from frame center. Based on WGS84 ellipsoid
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Location Latitude (Tag 40)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_LOCATION_LATITUDE,


    /**
     * Calculated Target longitude. This is the crosshair location if different
     * from frame center. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Location Longitude (Tag 41)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_LOCATION_LONGITUDE,


    /**
     * Calculated target elevation. This is the crosshair loaciton if different
     * from frame center. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Location Elevation3 (Tag 42)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_LOCATION_ELEVATION,

    /**
     * Tracking gate width (x value) of tracked target within field of view.
     * Closely tied to source video resolution in pixels. Measured in pixels.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Track Gate Width (Tag 43)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_TRACK_GATE_WIDTH,


    /**
     * Tracking gate height (y value) of tracked target within field of view.
     * Closely tied to source video resolution in pixels. Measured in pixels.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Track Gate Height (Tag 44)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_TRACK_GATE_HEIGHT,


    /**
     * Circular Error 90 (CE90) is the estimated error distance in the
     * horizontal direction. Specifies the radius of 90% probability on a
     * plane tangent to the earth’s surface. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Error Estimate - CE90 (Tag 45)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_ERROR_ESTIMATE_CE90,

    /**
     * Lateral Error 90 (LE90) is the estimated error distance in the vertical
     * (or lateral) direction. Specifies the interval of 90% probability in
     * the local vertical direction. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Error Estimate - LE90 (Tag 46)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_ERROR_ESTIMATE_LE90,

    /**
     * Generic Flagged Metadata. Bit Position Format Msb87654321Lsb.
     * <UL>
     *   <LI>1- Laser Range Finder 1on,0off</LI>
     *   <LI> 2- Auto-Track 1on,0off</LI>
     *   <LI> 3- IR Polarity 1blk,0wht</LI>
     *   <LI> 4- Icing detected 1ice,0(no ice/sensor off)</LI>
     *   <LI> 5- Slant Range 1 measured, 0 calculated</LI>
     *   <LI> 6->8- Not defined. Use 0</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Generic Flag Data 01 (Tag 47)</LI>
     * </UL>
     */
    METADATA_ITEMID_GENERIC_FLAG_DATA_01,

    /**
     * Differential pressure at aircraft location. Measured as the
     * Stagnation/impact/total pressure minus static pressure. Measured in
     * Millibars.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:
     * <UL>
     *  <LI>MISB STD 0601 Differential Pressure (Tag 49)</LI>
     * </UL>
     */
    METADATA_ITEMID_DIFFERENTIAL_PRESSURE,

    /**
     * Platform Attack Angle. Angle between platform longitudinal axis and
     * relative wind. Positive angles for upward relative wind.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Angle of Attack (Tag 50)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_ANGLE_OF_ATTACK,

    /**
     * Vertical speed of the aircraft relative to zenith. Positive ascending,
     * negative descending. Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Vertical Speed (Tag 51)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_VERTICAL_SPEED,

    /**
     * The sideslip angle is the angle between the platform longitudinal axis
     * and relative wind. Positive angles to right wing, neg to left.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Sideslip Angle (Tag 52)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_SIDESLIP_ANGLE,

    /**
     * Local pressure at airfield of known height. Pilot's responsibility to
     * update. Measured in Millibars.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Airfield Barometric Pressure (Tag 53)</LI>
     * </UL>
     */
    METADATA_ITEMID_AIRFIELD_BAROMETRIC_PRESSURE,

    /**
     * Elevation of Airfield corresponding to Airfield Barometric Pressure.
     * Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Airfield Elevation (Tag 54)</LI>
     * </UL>
     */
    METADATA_ITEMID_AIRFIELD_ELEVATION,

    /**
     * Relative Humidty at aircraft location.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Relative Humidity (Tag 55)</LI>
     * </UL>
     */
    METADATA_ITEMID_RELATIVE_HUMIDITY,

    /**
     * Speed projected to the ground of an airborne platform passing overhead.
     * Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Ground Speed (Tag 56)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_GROUND_SPEED,

    /**
     * Horizontal distance from ground position of aircraft relative to nadir,
     * and target of interest. Dependent upon Slant Range and Depression Angle.
     * Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Ground Range (Tag 57)</LI>
     * </UL>
     */
    METADATA_ITEMID_GROUND_RANGE,

    /**
     * Remainging fuel on airborne platform. Metered as fuel weight remaining in
     * kilograms.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Fuel Remaining (Tag 58)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_FUEL_REMAINING,

    /**
     * Call Sign of platform or operating unit.
     *
     * <P>Representation: METADATA_VALTYPE_STRING</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Call Sign (Tag 59)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_CALL_SIGN,

    /**
     * Current weapons stored on aircraft broken into two bytes:
     * [byteN] = [[nib1][nib2]], nib1= msn.
     * <UL>
     *   <LI>byte1-nib1 = Station Number</LI>
     *   <LI>byte1-nib2 = Substation Number</LI>
     *   <LI>byte2-nib1 = Weapon Type</LI>
     *   <LI>byte2-nib2 = Weapon Variant</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Weapon Load (Tag 60)</LI>
     * </UL>
     */
    METADATA_ITEMID_WEAPON_LOAD,

    /**
     * Indication when a particular weapon is released. Correlate with Unix Time
     * stamp. Identical format to Weapon Load byte 2: [byteN] = [[nib1][nib2]]
     * <UL>
     *   <LI>nib1 = Station Number</LI>
     *   <LI>nib2 = Substation Number</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Weapon Fired (Tag 61)</LI>
     * </UL>
     */
    METADATA_ITEMID_WEAPON_FIRED,

    /**
     * A laser's Pulse Repetition Frequency (PRF) code used to mark a target.
     * The Laser PRF code is a three or four digit number consisting of the
     * values 1..8. Only the values 1111..8888 can be used 0's or 9's.
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Laser PRF Code (Tag 62)</LI>
     * </UL>
     */
    METADATA_ITEMID_LASER_PRF_CODE,

    /**
     * Names sensor field of view quantized steps.
     * <UL>
     *   <LI>0x00 = Ultranarrow</LI>
     *   <LI>0x01 = Narrow</LI>
     *   <LI>0x02 = Medium</LI>
     *   <LI>0x03 = Wide</LI>
     *   <LI>0x04 = Ultrawide</LI>
     *   <LI>0x05 = Narrow Medium</LI>
     *   <LI>0x06 = 2x Ultranarrow</LI>
     *   <LI>0x07 = 4x Ultranarrow</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Field of View Name (Tag 63)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_FIELD_OF_VIEW_NAME,

    /**
     * Aircraft magnetic heading angle. Relative between longitudinal axis and
     * Magnetic North measured in the horizontal plane.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Platform Magnetic Heading (Tag 64)</LI>
     * </UL>
     */
    METADATA_ITEMID_PLATFORM_MAGNETIC_HEADING,

    /**
     * Version number of the UAS LDS document used to generate a source of UAS
     * LDS KLV metadata.
     * <UL>
     *   <LI>0 is pre-release, initial release (0601.0), or test data.</LI>
     *   <LI>1..255 corresponds to document revisions EG0601.1 thru EG0601.255.</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 UAS LDS Version Number (Tag 65)</LI>
     * </UL>
     */
    METADATA_ITEMID_UASLDS_VERSION_NUMBER,

    /**
     * Covariance Matrix of the error associated with a targeted location.
     *
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Target Location Covariance Matrix (Tag 66)</LI>
     * </UL>
     */
    METADATA_ITEMID_TARGET_LOCATION_COVARIANCE_MATRIX,

    /**
     * Alternate Platform Latitude. Represents latitude of platform connected
     * with UAS. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Alternate Platform Latitude (Tag 67)</LI>
     * </UL>
     */
    METADATA_ITEMID_ALT_PLATFORM_LATITUDE,

    /**
     * Alternate Platform Longitude. Represents longitude of platform connected
     * with UAS. Based on WGS84 ellipsoid.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Alternate Platform Longitude (Tag 68)</LI>
     * </UL>
     */
    METADATA_ITEMID_ALT_PLATFORM_LONGITUDE,

    /**
     * Altitude of alternate platform as measured from Mean Sea Level (MSL).
     * Represents of platform conneted with UAS. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Alternate Platform Altitude (Tag 69)</LI>
     * </UL>
     */
    METADATA_ITEMID_ALT_PLATFORM_ALTITUDE,

    /**
     * Name of alternate platform connected to UAS. E.g.: 'Apachce', 'Rover',
     * 'Predator', 'Reaper', 'Outrider', 'Pioneer', 'IgnatER', 'Warrior',
     * 'Shadow', 'Hunter II', 'Global Hawk', 'Scan Eagle', etc.
     *
     * <P>Representation: METADATA_VALTYPE_STRING</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Alternate Platform Name (Tag 70)</LI>
     * </UL>
     */
    METADATA_ITEMID_ALT_PLATFORM_NAME,

    /**
     * Heading angle of alternate platform connected to UAS. Relative between
     * longitudinal axis and True North measured in the horizontal plane.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Alternate Platform Heading (Tag 71)</LI>
     * </UL>
     */
    METADATA_ITEMID_ALT_PLATFORM_HEADING,

    /**
     * Local set tag to include the MISB EG0806 RVT Local Data Set metadata
     * items within STD 0601. The length field is the size of all RVT LDS
     * metadata items packaged within. Use the EG0806 Local Set Tags.
     *
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 RVT Local Data Set (Tag 73)</LI>
     * </UL>
     */
    METADATA_ITEMID_RVT_LOCAL_DATASET,

    /**
     * Local set tag to include the MISB EG0903 VMTI Local Data Set metadata
     * items within STD 0601. The length field is the size of all VMTI LDS
     * metadata items packaged within. Use the EG0903 Local Set Tags.
     *
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 VMTI Local Data Set (Tag 74)</LI>
     * </UL>
     */
    METADATA_ITEMID_VMTI_LOCAL_DATASET,

    /**
     * Sensor Ellipsoid Height as measured from the reference WGS84 Ellipsoid.
     * Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor Ellipsoid Height (Tag 75)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_ELLIPSOID_HEIGHT,

    /**
     * Alternate Platform Ellipsoid Height as measured from the reference WGS84
     * Ellipsoid. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Alternate Platform Ellipsoid Height (Tag 76)</LI>
     * </UL>
     */
    METADATA_ITEMID_ALTERNATE_PLATFORM_ELLIPSOID_HEIGHT,

    /**
     * - Indicates the mode of operations of the event portrayed in metadata.
     * <UL>
     *   <LI>0x00 = "Other"</LI>
     *   <LI>0x01 = "Operational"</LI>
     *   <LI>0x02 = "Training"</LI>
     *   <LI>0x03 = "Exercise"</LI>
     *   <LI>0x04 = "Maintenance"</LI>
     *   <LI>0x05 = "Test"</LI>
     * </UL>
     *
     * <P>Representation: METADATA_VALTYPE_INT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Operational Mode (Tag 77)</LI>
     * </UL>
     */
    METADATA_ITEMID_OPERATIONAL_MODE,

    /**
     * Frame Center Ellipsoid Height as measured from the reference WGS84
     * Ellipsoid. Measured in meters.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Frame Center Height Above Ellipsoid (Tag 78)</LI>
     * </UL>
     */
    METADATA_ITEMID_FRAME_CENTER_HEIGHT_ABOVE_ELLIPSOID,

    /**
     * Northing velocity of the sensor or platform. Positive towards True North.
     * Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor North Velocity (Tag 79)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_NORTH_VELOCITY,

    /**
     * Easting velocity of the sensor or platform. Positive towards East.
     * Measured in meters per second.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Sensor East Velocity (Tag 80)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_EAST_VELOCITY,

    /**
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 Imagery Horizon Pixel Pack (Tag 81)</LI>
     * </UL>
     */
    METADATA_ITEMID_IMAGE_HORIZON_PIXEL_PACK,

    /**
     * Local set tag to include the ST1204 MIIS Core Identifier Binary Value
     * within ST0601. Use according to the rules and requirements defined in
     * ST1204.
     *
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 MIIS Core Identifier (Tag 94)</LI>
     * </UL>
     */
    METADATA_ITEMID_MIIS_CORE_IDENTIFIER,

    /**
     * Local set tag to include the ST1206 SAR Motion Imagery Metadata Local Set
     * data within ST0601. Use according to the rules and requirements defined
     * in ST1206.
     *
     * <P>Representation: METADATA_VALTYPE_BINARY</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB STD 0601 SAR Motion Imagery Metadata (Tag 95)</LI>
     * </UL>
     */
    METADATA_ITEMID_SAR_MOTION_IMAGERY_METADATA,

    /***********************************************************************/
    // MISB EG 0104

    /**
     * The date and time of the collection expressed as microseconds elapsed
     * since Midnight 01 January 1970 UTC.
     *
     * <P>Representation: METADATA_VALTYPE_LONG</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB EG 0104 Start Date Time UTC (UL
     *      060E2B34010101010702010201010000)</LI>
     * </UL>
     */
    METADATA_ITEMID_START_DATE_TIME_UTC = 0x00000401,

    /**
     * Sensor roll angle about boresight.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB EG 0104 Sensor Roll Angle (UL 060E2B34010101010701100101000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_SENSOR_ROLL_ANGLE,

    /**
     * Angle measured from the first row of the image to true North. Assumes the
     * boresight angle is perpendicular to the top row of the image. The angle
     * is computed as the sensor absolute azimuth plus 90 degrees.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB EG 0104 Angle to North (UL 060E2B34010101010701100102000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_ANGLE_TO_NORTH,

    /**
     * The inverse of sensor depression angle.
     *
     * <P>Representation: METADATA_VALTYPE_FLOAT</P>
     *
     * <P>This metadata item may be derived from the following:</P>
     * <UL>
     *  <LI>MISB EG 0104 Obliquity Angle (UL 060E2B34010101010701100103000000)</LI>
     * </UL>
     */
    METADATA_ITEMID_OBLIQUITY_ANGLE,

} MetadataItemIDs;


typedef struct DecodedMetadataItem_s {
    /**
     * The item's ID.
     */
    MetadataItemIDs id;

    /**
     * The decoded type of the value.
     */
    MetadataValueTypes value_type;

    /**
     * Stores the raw (coded) value. When 'value_type' is
     * METADATA_VALTYPE_STRING or METADATA_VALTYPE_BINARY, the data pointed to
     * can be considered the decoded value as well. Values of type
     * METADATA_VALTYPE_STRING are not guaranteed to be null terminated ('\0'),
     * so the 'raw_len' should always be used to determine string length.
     */
    const uint8_t* raw;

    /**
     * The length of the raw (coded) value.
     */
    int raw_len;

    /**
     * Stores the decoded value as a primitive. The value of the union will
     * only have meaning when 'value_type' is one of the types associated with
     * union members.
     */
    union {
        int i;       // METADATA_VALTYPE_INT
        long long l; // METADATA_VALTYPE_LONG
        double f;    // METADATA_VALTYPE_FLOAT
    } value;
} DecodedMetadataItem;

//////////////////////////////////////////////////////////////////

typedef void* MediaMetadataDecode_C;

MediaMetadataDecode_C MediaMetadataDecode_create();
void MediaMetadataDecode_destroy(MediaMetadataDecode_C iface);
void MediaMetadataDecode_clear(MediaMetadataDecode_C iface);
int MediaMetadataDecode_decode(MediaMetadataDecode_C iface,
                               MetadataSourceTypes source_type,
                               const void* srcData,
                               const DecodedMetadataItem ***decoded);
const DecodedMetadataItem* MediaMetadataDecode_get(MediaMetadataDecode_C iface,
                                                   MetadataItemIDs id);
int MediaMetadataDecode_getCurrentItems(MediaMetadataDecode_C iface,
                                        const DecodedMetadataItem ***decoded);

int MediaMetadataDecode_decodeKLV(const KLVData *klv,
                                  const DecodedMetadataItem **decoded);
int MediaMetadataDecode_decodeESD(const ESDClosedCaptionData **esd,
                                  const DecodedMetadataItem **decoded);

void MediaMetadataDecode_releaseDecodedMetadataItemArray(const DecodedMetadataItem *decoded);
void MediaMetadataDecode_releaseDecodedMetadataItemPointerArray(const DecodedMetadataItem **decoded);

#ifdef __cplusplus 
};  // End of extern C
#endif

#endif
