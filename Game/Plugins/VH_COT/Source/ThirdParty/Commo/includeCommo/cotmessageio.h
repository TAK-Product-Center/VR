#ifndef COTMESSAGEIO_H_
#define COTMESSAGEIO_H_

#include "commoutils.h"
#include "commoresult.h"
#include <stddef.h>
#include <stdint.h>

namespace atakmap {
namespace commoncommo {


/**
 * Enum representing the methods by which cot messages may be sent to remote
 * recipients.
 */
enum CoTSendMethod {
    /** Send only via TAK server (streaming) connections */
    SEND_TAK_SERVER = 0x1,
    /** Send only via point to point direct to device methods */
    SEND_POINT_TO_POINT = 0x2,
    /** Send via any available method */
    SEND_ANY = 0x3
};

/**
 * Identifies a geographic point in/destined for a CoT message.
 */
struct COMMONCOMMO_API CoTPointData {
    /**
     * Value to be used for hae, ce, and/or le
     * if they are to be considered as not initialized to a meaningful
     * value.
     */
#define COMMO_COT_POINT_NO_VALUE 9999999.0

    /**
     * Create a new CoTPointData with given arguments.
     * All arguments are required; HAE, CE, and/or LE may be
     * specified as COMMO_COT_POINT_NO_VALUE, which indicates their
     * value has no meaningful significance.
     * @param lat latitude in degrees
     * @param lon longitude in degrees
     * @param hae HAE value or COMMO_COT_POINT_NO_VALUE
     * @param ce CE value or COMMO_COT_POINT_NO_VALUE
     * @param le LE value or COMMO_COT_POINT_NO_VALUE
     */
    CoTPointData(double lat, double lon, double hae,
                 double ce, double le) : lat(lat), lon(lon), hae(hae), ce(ce), le(le)
    {
    };

    double lat;
    double lon;
    double hae;
    double ce;
    double le;
};


/**
 * Enum representing the different types of CoT message traffic.
 */
enum CoTMessageType {
    SITUATIONAL_AWARENESS,
    CHAT,
};


/**
 * Interface that can be implemented and registered with a Commo instance
 * to indicate interest in receiving any CoT messages received
 * on any non-generic inbound interfaces.
 */
class COMMONCOMMO_API CoTMessageListener
{
public:
    CoTMessageListener() {};

    /**
     * Invoked when a CoT Message has been received.  The message
     * is provided without modification. Some basic validity checking
     * is done prior to passing it off to listeners, but it is limited
     * and should not be relied upon for anything specific.
     * 
     * @param cotMessage the CoT message that was received
     * @param rxEndpointId identifier of NetworkInterface upon which
     *                     the message was received, if known, or NULL
     *                     if not known
     */
    virtual void cotMessageReceived(const char *cotMessage, const char *rxIfaceEndpointId) = 0;

protected:
    virtual ~CoTMessageListener() {};

private:
    COMMO_DISALLOW_COPY(CoTMessageListener);
};


/**
 * Interface that can be implemented and registered with a Commo instance
 * to indicate interest in receiving any messages received
 * on inbound interfaces flagged for generic data.
 */
class COMMONCOMMO_API GenericDataListener
{
public:
    GenericDataListener() {};

    /**
     * Invoked when data has been received on a generic inbound interface. 
     * The data is provided as-is, no modification or validity checking
     * is performed.
     * 
     * @param data the data that was received
     * @param length the length of the received data, in number of bytes
     * @param rxEndpointId identifier of NetworkInterface upon which
     *                     the message was received, if known, or NULL
     *                     if not known
     */
    virtual void genericDataReceived(const uint8_t *data,
                                     size_t length,
                                     const char *rxIfaceEndpointId) = 0;

protected:
    virtual ~GenericDataListener() {};

private:
    COMMO_DISALLOW_COPY(GenericDataListener);
};


/**
 * Interface that can be implemented and registered with a Commo instance
 * to indicate interest in receiving advisory notification when CoT messages
 * failed to send.  Note that only messages sent to destination contacts that 
 * use point-to-point TCP-based communication are able to detect failure
 * to send.
 */
class COMMONCOMMO_API CoTSendFailureListener
{
public:
    /**
     * Invoked when a CoT Message sent to a known contact was unable
     * to be sent for some reason. This callback is advisory in nature;
     * it is not intended to be used to definitively track the delivery status
     * of all messages in all cases as some contacts use network technologies
     * that do not allow for detection of errors.
     * 
     * @param host the contact's known hostname to where the message could
     *             not be delivered.
     * @param port the contact's known port to where the message could not be
     *             delivered
     * @param errorReason an advisory error or reason message as to what 
     *             happened to cause the delivery to fail 
     */
    virtual void sendCoTFailure(const char *host, int port, const char *errorReason) = 0;

protected:
    CoTSendFailureListener() {};
    virtual ~CoTSendFailureListener() {};
    
private:
    COMMO_DISALLOW_COPY(CoTSendFailureListener);
};


/**
 * Interface that can be implemented and registered with a Commo instance
 * to provide an extension implementation to CoT Detail encoding.
 * Implementations can translate portions of CoT detail XMl to/from a binary
 * representation for bandwidth efficiency.  See TAK protocol detail extension
 * documentation for further details. Note specifically that extensions must
 * be registered to the central extension registry before being deployed!
 *
 * Encoding and decoding may be called from multiple threads simultaneously.
 */
class COMMONCOMMO_API CoTDetailExtender
{
public:
    /**
     * Given an xml element node tree for the element that this extension
     * was registered to support, encodes the data to the binary equivalent
     * in compliance with the protocol extension.
     * @param encodedExtension populated with an allocated buffer containing
     *                         the newly encoded extension data. Only populated
     *                         when SUCCESS is returned. encodedSize contains
     *                         the number of bytes of data. The buffer
     *                         must remain valid until passed to releaseEncodeResult().
     * @param encodedSize populated with the number of bytes of data in the 
     *                    encodedExtension result buffer. Only populated
     *                    when SUCCESS is returned.
     * @param cotDetailElement contains an XML document whose root element
     *                    is the node for which the Extender was registered
     *                    to support.  NULL terminated.
     * @return SUCCESS if the encoding completed and the result parameters are
     *         populated, ILLEGAL_ARGUMENT if the element cannot be encoded
     *         and no output results have been set
     */
    virtual CommoResult encode(uint8_t **encodedExtension, size_t *encodedSize, const char *cotDetailElement) = 0;

    /**
     * Given a buffer of binary encoded extension data, decodes to an xml
     * document containing the element node tree for the element that
     * this extension was registered to support. The decoding is performed
     * in compliance with the protocol extension which this Extender
     * is supporting. Implementations must perform validity checking on the
     * provided data!
     * @param cotDetailElement populated with an allocated buffer containing
     *                    the newly decoded xml equivalent of the provided
     *                    binary extension data.  Must contain an XML document
     *                    whose root element is the node for which the
     *                    Extender was registered to support. NULL terminated.
     *                    Only populated on a SUCCESS return.
     *                    The buffer must remain valid until passed
     *                    to releaseDecodeResult()
     * @param encodedExtension the encoded extension data to decode. The length
     *                         of data is provided in encodedSize
     * @param encodedSize the number of bytes of data in the 
     *                    encodedExtension buffer
     * @return SUCCESS if the decoding was completed successfully and the
     *         result parameters are populated, ILLEGAL_ARGUMENT if the
     *         extension data cannot be encoded and no output results
     *         have been set
     */
    virtual CommoResult decode(const char **cotDetailElement, const uint8_t *encodedExtension, size_t encodedSize) = 0;


    /**
     * Release a result buffer from a prior decode() call.
     * @param resultBuffer buffer to release
     */
    virtual void releaseDecodeResult(const char *resultBuffer) = 0;

    /**
     * Release a result buffer from a prior encode() call.
     * @param resultBuffer buffer to release
     */
    virtual void releaseEncodeResult(const uint8_t *resultBuffer) = 0;

protected:
    CoTDetailExtender() {};
    virtual ~CoTDetailExtender() {};
    
private:
    COMMO_DISALLOW_COPY(CoTDetailExtender);
};


}
}


#endif /* COTMESSAGE_H_ */
