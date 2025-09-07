#ifndef COMMO_H_
#define COMMO_H_


#include "commoresult.h"
#include "commologger.h"
#include "commoutils.h"
#include "netinterface.h"
#include "missionpackage.h"
#include "contactuid.h"
#include "cotmessageio.h"
#include "simplefileio.h"
#include "cloudio.h"
#include "fileioprovider.h"
#include "enrollment.h"

#include <memory>
#include <stdint.h>
#include <stddef.h>

namespace atakmap {
namespace commoncommo {

namespace impl
{
    struct CommoImpl;
}

// Workaround quirks of operating on marine air ground tablet
#define QUIRK_MAGTAB 1



/**
 * The main interface to the Commo library.  An instance of this class
 * will provide most functionality of the library.  As a general rule, 
 * objects implementing any of the listener interfaces must remain valid 
 * from the time they are added until either they are removed using
 * the appropriate Commo method or this Commo instance is shutdown.
 *
 * Before creating the first instance of a Commo object, callers
 * must externally load and initialize the dependent libraries used internally
 * by Commo.  Specifically as of the time of this writing, this is libxml2,
 * openssl, and libcurl. openssl must be initialized to support use by multiple
 * threads. A method is provided here to do a compatible, default set of
 * initialization calls to these libraries.
 *
 */
class COMMONCOMMO_API Commo {
public:
    // Both uid and callsign are copied internally
    /**
     * Create a new Commo instance with the specified logging implementation,
     * which is required.  The specified UID and callsign will be used
     * to identify this system in outbound messages generated internally
     * by the library. The specified address mode controls how 
     * addresses for all NetInterfaces managed by this Commo instance
     * are interpreted.  
     * The provided uid and callsign are copied internally, so they 
     * need not exist once this call completes.
     *
     * @param logger a CommoLogger implementation used to log all
     *               information from this Commo instance
     * @param ourUID string that uniquely identifies this TAK device
     * @param ourCallsign callsign to use in messages originating from
     *                    this instance
     * @param addrMode addressing mode used by NetInterfaces that
     *                    the new instance will create and manage
     */
    Commo(CommoLogger *logger, const ContactUID *ourUID, const char *ourCallsign,
          netinterfaceenums::NetInterfaceAddressMode addrMode = netinterfaceenums::MODE_PHYS_ADDR);
    virtual ~Commo();


    /**
     * Configures mission package transfer helper client-side interface
     * for this Commo instance.
     * Once configured, the helper interface implementation must remain valid
     * until shutdown() is invoked or this Commo instance is destroyed;
     * the interface implementation cannot be swapped or deactivated.
     * After a successful return, other Mission Package related
     * api calls may be made.
     * @return SUCCESS if IO implementation is accepted, or ILLEGAL_ARGUMENT
     *        if missionPacakgeIO is NULL or if setupMissionPackageIO has
     *        previously been called successfully on this Commo instance.
     */
    CommoResult setupMissionPackageIO(MissionPackageIO *missionPackageIO);


    /**
     * Enables simple file transfers for this Commo instance.
     * Simple file transfers are transfers of files via traditional
     * client-server protocols (where commo is the client)
     * and is not associated with CoT sending/receiving or
     * mission package management.
     * Once enabled, transfers cannot be disabled.
     * The caller must supply an implementation of the 
     * SimpleFileIO interface that will remain operable
     * until shutdown() is invoked.
     * After a successful return, simpleFileTransferInit()
     * can be invoked to initiate file transfers with an external server.
     * @return SUCCESS if IO implementation is accepted, or ILLEGAL_ARGUMENT
     *      if simpleFileIO is NULL, or if this method has previously
     *      been called successfully for this Commo instance.
     * @param simpleFileIO reference to an implementation of
     *                         the SimpleFileIO interface that
     *                         this Commo instance can use to interface
     *                         with the application during simple file
     *                         transfers
     */
    CommoResult enableSimpleFileIO(SimpleFileIO *simpleFileIO);


    /**
     * Enables certificate enrollment for this Commo instance.
     * Certificate enrollment allows a client to request client
     * certificates from a server for which it later intends to connect
     * for messaging purposes (see addStreamingInterface()).
     * The caller must supply an implementation of the 
     * EnrollmentIO interface that will remain operable
     * until shutdown() is invoked.
     * Once enabled, enrollment cannot be disabled nor can the
     * EnrollmentIO interface be changed.
     * After a successful return, enrollmentInit()
     * can be invoked to initialize an enrollment transaction
     * with an external server.
     * Throws CommoException if enrollmentIO is NULL, or
     * if this method has previously been called successfully for this
     * Commo instance.
     * @param enrollmentIO reference to an implementation of
     *                         the EnrollmentIO interface that
     *                         this Commo instance can use to interface
     *                         with the application during enrollment
     *                         transactions
     * @return SUCCESS if the IO implementation is accepted, 
     *      ILLEGAL_ARGUMENT if enrollmentIO is NULL or if this method has
     *      previously been called successfully for this Commo instance
     */
    CommoResult enableEnrollment(EnrollmentIO *enrollmentIO);

    /**
     * Shuts down all background operations associated with this Commo object.
     * All listeners are immediately discarded, any background transfers or
     * other operations immediately cease, and all Contacts are considered
     * "gone".
     * Attempting future operations other then shutdown() on this Commo object
     * will cause undefined results.
     * Note that during this method's execution, any previously added 
     * Listener (for any of the several varieties of Listeners supported by 
     * this class, including any configured xxxIO interfaces) may still receive
     * some method invocations from the Commo library, but by the time
     * this method returns the Commo library will
     * no longer invoke any methods on those listeners nor will it hold
     * any references to said listeners.
     * Shutdown is also recursive in that all objects created and
     * any subinterfaces by this Commo object will also be shut down,
     * no longer functional, and made invalid to dereference.
     */
    void shutdown();
    
    /**
     * Enable/disable workarounds for various quirks.
     * Changing this may cause restarts/reconnects of various interfaces
     * depending on the quirk changed.
     */
    void setWorkaroundQuirks(int quirksMask);

    /**
     * Changes the callsign of the local system, as used for sending
     * any outbound messages generated internally by Commo.  The callsign
     * is internally copied and need not remain valid after this method
     * returns.
     * @param callsign the new callsign to use in future outgoing messages
     */
    void setCallsign(const char *callsign);

    /**
     * Registers a FileIOProvider, causing the provided FileIOProvider
     * to be used for all future IO transactions until such time where it is
     * unregistered via unregisterFileIOProvider().  The default FileIOProvider
     * if none is registered does simple file-based IO using operating system
     * provided calls.
     *
     * @param provider The FileIOProvider to register
     */
    void registerFileIOProvider(std::shared_ptr<FileIOProvider>& provider);

    /**
     * Unregisters a FileIOProvider and reverts to the default provider.
     * The default FileIOProvider does simple file-based IO using operating
     * system provided calls.
     *
     * @param provider The FileIOProvider to register
     */
    void deregisterFileIOProvider(const FileIOProvider& provider);
    
    /**
     * Register a CoTDetailExtender that implements a specific CoT detail
     * extension for TAK Protocol. The provided CoTDetailExtender will be used
     * to encode any CoT XML message containing the provided extensionDetailElement
     * that is being transmitted via binary TAK protocol representation, 
     * as well as to decode any binary TAK protocol message that contains
     * the extension identified by the provided extensionId.
     * The extensionId is expected to be registered with the TAK Protocol
     * central extension registry to handle the indicated extensionDetailElement
     * before it is used in production.
     * The provided CoTDetailExtender implementation must remain valid
     * until deregistered or shutdown() is invoked on this Commo instance.
     * This method may cause one or more active streaming connections to
     * terminate and re-establish to renegotiate the extensions in use.
     * @param extensionId unique and centrally registered identifier for the
     *                    TAK protocol extension being implemented by 
     *                    extender
     * @param extensionDetailElement name of the element node of the cot detail
     *                    the extension handles. Needs only be valid for duration
     *                    of this method invocation.
     * @param extender CoTDetailExtender to register
     * @return SUCCESS if registration is successful, ILLEGAL_ARGUMENT
     *         if another Extender has already been registered for
     *         the given extensionId or any other error occurs.
     */
    CommoResult registerCoTDetailExtender(unsigned int extensionId, const char *extensionDetailElement, CoTDetailExtender *extender);

    /**
     * Deregister any previously registered CoTDetailExtender for the given
     * extensionId.
     * This method may cause one or more active streaming connections to
     * terminate and re-establish to renegotiate the extensions in use.
     * @param extensionId unique and centrally registered identifier for the
     *                    TAK protocol extension to be deregistered
     * @return SUCCESS if deregistration is successful, ILLEGAL_ARGUMENT
     *         if no Extender has been registered for
     *         the given extensionId or any other error occurs.
     */
    CommoResult deregisterCoTDetailExtender(unsigned int extensionId);
    
    /**
     * Enable or disable the insertion of destination UIDs in outbound 
     * directed messages.  When enabled, a __dest detail element is inserted in
     * all outbound messages with an attribute containing the destination
     * contact's UID.
     *
     * @param insertDestUid true to enable insertion of destination UID
     *        information in outbound CoT, false (the default) to disable
     *        this behavior
     */
    void setDestUidInsertionEnabled(bool insertDestUid);

    /**
     * Controls what type of endpoint should be preferred when sending to
     * contacts when both types of endpoints are available.  The default
     * is to NOT prefer stream endpoints (that is, mesh/local endpoints
     * are preferred).
     *
     * @param preferStream true to prefer streaming endpoints when
     *                     sending to contacts instead of mesh/local endpoints.
     */
    void setPreferStreamEndpoint(bool preferStream);

    /**
     * Advertise our endpoint using UDP protocol instead of the
     * default of TCP. USE THIS FUNCTION WITH CAUTION:
     * enabling this advertises us to others as receiving via UDP
     * which is an unreliable protocol where messages may be corrupted
     * or discarded entirely during network transit.
     * If you do use this, it should be set as early as possible in a session
     * and changed only very infrequently as remote clients expect to see
     * a stable endpoint advertisement generally.
     *
     * @param en true to send out UDP endpoints from now on, false 
     *           (the default) to send out TCP endpoints
     */
    void setAdvertiseEndpointAsUdp(bool en);


    /**
     * Enables encryption/decryption for non-streaming CoT interfaces
     * using the specified keys, or disables it entirely. 
     * This is symmetric in that if you encrypt outbound,
     * everything inbound is expected to be encrypted and will fail if it
     * is not.
     * The two keys MUST be 32 bytes (256 bits) long and must be unique
     * from each other.
     * Specify NULL for both to disable encryption/decryption (the default).
     * The provided keys are copied and need not remain valid after the call
     * completes.
     *
     * @param authKey 256 bit authentication key
     * @param cryptoKey 256 bit crypto key 
     * @return SUCCESS or ILLEGAL_ARGUMENT if keys are identical
     */
    CommoResult setCryptoKeys(const uint8_t *authKey, const uint8_t *cryptoKey);

    /**
     * Enables or disables (the default) the ability of datagram sockets
     * created by the system to share their local address with other sockets
     * on the system created by other applications.  Note that this
     * option is unreliable when unicast datagrams are sent to the
     * local system, as it is indeterminate
     * which local socket will receive the unicast datagrams.  Use this option
     * with caution if you expect to be able to receive unicasted datagrams.
     * This option is global in that it affects all datagram sockets and
     * when the option is changed, all datagram sockets will be torn down and
     * rebuilt.
     * NOTE: PRESENTLY ONLY SUPPORTED ON LINUX AND WINDOWS.
     * Enabling on any other platform will cause undefined behavior!
     * @param en true to allow address reuse, false otherwise
     */
    void setEnableAddressReuse(bool en);

    /**
     * Enables or disables loopback of multicast data to the local system.
     * If enabled, multicasted data sent by us will be made available to other
     * listening sockets on the same local system. Note that this inheritly
     * means that the current Commo instance will also receive back copies
     * of the data if it is listening (addInboundInterface()) on the same
     * multicast address and port as an outbound interface
     * (addBroadcastInterface()); thus the application must be prepared to
     * receive and process copies of messages it broadcasts out.
     * NOTE: On Windows, this method has no effect and is not supported
     * as Windows does not provide a means to control this on th
     * sending side.  Windows controls this on the receiving side.
     * The default is disabled. Toggling this option will cause
     * all internal sockets to be rebuilt.
     * @param en true to enable looping back of multicasts,, false otherwise
     */
    void setMulticastLoopbackEnabled(bool en);

    /**
     * Sets the global TTL for broadcast messages.  If the
     * ttl is out of valid range, it will be clamped to the nearest
     * valid value.
     * @param ttl the new TTL to use in future broadcast messages
     */
    void setTTL(int ttl);
    
    /**
     * Sets global UDP timeout value, in seconds; if the given # of seconds
     * elapses without a socket receiving data, it will be destroyed
     * and rebuilt. If the timed-out socket was a multicast socket,
     * multicast joins will be re-issued.
     * 0 means never timeout. Default is 30 seconds.
     *
     * @param seconds timeout value in seconds - use 0 for "never"
     */
    void setUdpNoDataTimeout(int seconds);

    /**
     * Sets the global timeout in seconds used for all outgoing
     * TCP connections
     * (except those used to upload or download mission packages).
     * @param seconds timeout in seconds
     */
    void setTcpConnTimeout(int seconds);

    /**
     * Indicates if stream monitoring is to be performed or not.
     * If enabled, Commo will monitor incoming traffic on each
     * configured and active streaming interface.  If no traffic
     * arrives for a substantive period of time, commo will
     * send a "ping" CoT message to the streaming server and expect
     * a response. This will repeat for a short time, and, if
     * no reply is received, the streaming connection will be
     * shut down and an attempt to re-establish the connection
     * will be made a short time later.
     * Server "pong" responses, if they arrive, are never delivered
     * to the application's CoTMessageListener.
     * Default is enabled.
     * @param en true to enable monitoring, false to disable it
     */
    void setStreamMonitorEnabled(bool enable);
    
    /**
     * Gets the TAK protocol version current in use when sending things
     * via broadcastCoT(). Zero (0) is legacy XML, > 0 is binary
     * TAK protocol.
     * @return protocol version in use for broadcast
     */
    int getBroadcastProto();


    /**
     * Sets the local web server port to use for outbound peer-to-peer
     * mission package transfers, or disables this functionality if
     * MP_LOCAL_PORT_DISABLE is specified.
     * The local web port number must be a valid, free, local port
     * for TCP listening or the constant MP_LOCAL_PORT_DISABLE. 
     * On successful return, the server will be active on the specified port
     * and new outbound transfers (sendMissionPackage()) will use
     * this to host outbound transfers.
     * If this call fails, transfers using the local web server will be
     * disabled until a future call completes successfully (in other words,
     * will act as if this had been called with MP_LOCAL_PORT_DISABLE).
     *
     * Note carefully: calling this to change the port or disable the local
     * web server will cause all in-progress mission package sends to
     * be aborted.
     *
     * The default state is to have the local web server disabled, as if
     * this had been called with MP_LOCAL_PORT_DISABLE.
     *
     * @param localWebPort TCP port number to have the local web server
     *                     listen on, or MP_LOCAL_PORT_DISABLE.
     *                     The port must be free at the time of invocation.
     * @return SUCCESS if the provided port number is successfully opened
     *      and usable for the local web server (or if MP_LOCAL_PORT_DISABLE
     *      is passed), or ILLEGAL_ARGUMENT if the port is not valid/available
     *      or setupMissionPackageIO has not yet been successfully invoked
     * @deprecated the local http server functionality is slated for removal.
     *     Please ensure you are enabling the https server
     *     (see setMissionPackageLocalHttpsParams())
     */
    COMMO_DEPRECATED CommoResult setMissionPackageLocalPort(int localWebPort);
    
    /**
     * Controls if mission package sends via TAK servers may or may
     * not be used.  The default, once mission package IO has been setup
     * via setupMissionPackageIO(), is enabled.
     * Note carefully: Disabling this after it was previously enabled
     * may cause some existing outbound mission package transfers to be
     * aborted!
     * @param enabled true to enable server-based transfers, false to disable
     */
    void setMissionPackageViaServerEnabled(bool enabled);

    /**
     * Sets the TCP port number to use when contacting a TAK
     * Server's http web api. Default is port 8080.
     *
     * @param port tcp port to use
     * @return SUCCESS if new port number is valid, ILLEGAL_ARGUMENT if port
     *       number is invalid
     */
    CommoResult setMissionPackageHttpPort(int port);

    /**
     * Sets the TCP port number to use when contacting a TAK
     * Server's https web api. Default is port 8443.
     *
     * @param serverPort tcp port to use
     * @return SUCCESS if new port number is valid, ILLEGAL_ARGUMENT if port
     *       number is invalid
     */
    CommoResult setMissionPackageHttpsPort(int port);

    /**
     * Set number of attempts to receive a mission package that a remote
     * device has sent us a request to download.
     * Once this number of attempts has been exceeded, the transfer
     * will be considered failed. Minimum value is 1.
     * The default value is 10.
     * New settings influence subsequent transfers;
     * currently ongoing transfers use settings in place at the time they
     * began.
     *
     * @param nTries number of attempts to make
     * @return SUCCESS if new setting is accepted, ILLEGAL_ARGUMENT if
     *      supplied number of tries is out of legitimate range
     */
    CommoResult setMissionPackageNumTries(int nTries);
    
    /**
     * Set timeout, in seconds, for initiating connections to remote
     * hosts when transferring mission packages.  This is used when
     * receiving mission packages from TAK servers and/or other devices,
     * as well as uploading mission packages to TAK servers.
     * The minimum value is five (5) seconds; default value is 90 seconds.
     * New settings influence sunsequent transfers; currently ongoing transfers
     * use settings in place at the time they began.
     *
     * @param seconds connect timeout in seconds
     * @return SUCCESS if the new value is accepted, ILLEGAL_ARGUMENT
     *                 if the value is out of range
     */
    CommoResult setMissionPackageConnTimeout(int seconds);
    
    /**
     * Set timeout, in seconds, for data transfers. After this number
     * of seconds has elapsed with no data transfer progress taking place,
     * the transfer attempt is considered a failure.
     * This is used when receiving mission packages.
     * Minimum value is 15 seconds, default value is 120 seconds.
     * New settings influence sunsequent transfers; currently ongoing transfers
     * use settings in place at the time they began.
     *
     * @param seconds transfer timeout in seconds
     * @return SUCCESS if argument is legitimate value, ILLEGAL_ARGUMENT
     *       if it is out of legitimate range.
     */
    CommoResult setMissionPackageTransferTimeout(int seconds);

    /**
     * Sets the local https web server paramerters to use with the local
     * https server for outbound peer-to-peer
     * mission package transfers, or disables this functionality.
     * The local web port number must be a valid, free, local port
     * for TCP listening or the constant MPIO_LOCAL_PORT_DISABLE. 
     * The certificate data and password must be non-NULL and non-empty
     * except in the specific case that localWebPort is
     * MPIO_LOCAL_PORT_DISABLE.
     * Certificate data must be in pkcs#12 format and should represent
     * the complete certificate, key, and supporting certificates that
     * the server should use when negotiating with the client.
     * On successful return, the https server will be configured to use the
     * specified port and new outbound transfers (sendMissionPackage())
     * will use this to host outbound transfers.
     * Note that prior versions of this library required the http server to
     * be enabled for the https server to be supported;  this is no longer
     * necessary.
     * If this call fails, transfers using the local https server will be
     * disabled until a future call completes successfully (in other words,
     * will act as if this had been called with MPIO_LOCAL_PORT_DISABLE).
     *
     * Note carefully: calling this to change the port or disable the local
     * https web server will cause all in-progress mission package sends to
     * be aborted.
     *
     * The default state is to have the local https web server disabled, as if
     * this had been called with MPIO_LOCAL_PORT_DISABLE.
     *
     * @param port TCP port number to have the local https web server
     *                     listen on, or MPIO_LOCAL_PORT_DISABLE.
     *                     The port must be free at the time of invocation.
     * @param cert certificate store, with key, in pkcs12 format
     * @param certLen length of cert, in bytes
     * @param certPass password for certificate
     * @return SUCCESS if the cert is valid and the provided TCP port number
     *         is successfully opened and usable for the local web server 
     *         (or if MP_LOCAL_PORT_DISABLE is passed), ILLEGAL_ARGUMENT
     *         if the passed port cannot be used or if
     *         setupMissionPackageIO() has not previously been invoked
     *         successfully, INVALID_CERT if "cert" could not be read,
     *         or INVALID_CERT_PASSWORD if certPass is incorrect. 
     */
    CommoResult setMissionPackageLocalHttpsParams(int port, const uint8_t *cert,
                               size_t certLen, const char *certPass);

    /**
     * Add a new outbound broadcast interface.  
     * The local interface address is specified by hwAddress, the format for
     * which is dictated by the NetInterfaceAddressMode used to create this
     * Commo object (see constructor).
     * The types of data routed to this outbound
     * address are specified in "types"; at least one type must be specified.
     * The multicast destination is specified as a string in 
     * dotted-decimal notation ("239.1.1.1").
     * Outbound broadcast messages matching any of the types given will
     * be sent out this interface to the multicast address specified
     * to the specified port.
     * @param hwAddress address identifier of the local network interface
     *                  to be used for broadcasting
     * @param types array of the CoTMessageType(s) to be
     *              sent out this interface
     * @param nTypes the number of elements in the types array
     * @param mcastAddr the dotted-decimal notation of the
     *                  destination multicast address
     * @param destPort the destination port to send broadcasts out on
     * @return On success, returns NetInterface object uniquely
     *         identifying the added interface.
     *         Remains valid until it is passed to removeBroadcastInterface.
     *         On any error NULL is returned, including (but not limited to)
     *         if mcastAddr does not represent a valid multicast address,
     *         types does not contain at least one element, or
     *         destPort is out of range
     */
    PhysicalNetInterface *addBroadcastInterface(const HwAddress *hwAddress, const CoTMessageType *types, size_t nTypes, const char *mcastAddr, int destPort);

    /**
     * Add a new outbound broadcast interface that directs
     * all broadcasted messages of the matching type 
     * to the given UDP unicast destination.
     * This call varies from the other form of addBroadcastInteface()
     * in that it is for unicasted destinations whereas the other form
     * is for mulicasted destinations.
     * The types of data routed to this outbound
     * address are specified in "types"; at least one type must be specified.
     * The unicast destination is specified as a string in 
     * dotted-decimal notation ("10.0.0.2").
     * Outbound broadcast messages matching any of the types given will
     * be sent to the unicast address and port specified.
     * @param types array of the CoTMessageType(s) to be sent out this interface
     * @param nTypes number of elements in the types array
     * @param unicastAddr the dotted-decimal notation of the
     *                  destination unicast address
     * @param destPort the destination port to send broadcasts out on
     * @return On success, a NetInterface object uniquely identifying
     *         the added interface. Remains valid until it is
     *         passed to removeBroadcastInterface. On any error, NULL
     *         is returned, including (but not limited to)
     *         if unicastAddr does not represent a valid
     *         unicast address, types does not contain at
     *         least one element, or destPort is out of range
     */
    PhysicalNetInterface *addBroadcastInterface(const CoTMessageType *types, size_t nTypes, const char *unicastAddr, int destPort);

    /**
     * Remove the specified interface from attempting to be used for broadcast.
     * The iface can be removed regardless of if it is in the up or down state.
     * When this call completes, the interface will no longer be used for any outgoing
     * messages. However it is possible that previously queued messages may be sent
     * during execution of this method.
     * After completion, the supplied NetInterface is considered invalid.
     *  
     * @param iface previously added PhysicalNetInterface to remove from service
     * @return SUCCESS if the supplied interface is successfully removed,
     *         ILLEGAL_ARGUMENT if the supplied NetInterface was
     *         not created via addBroadcastInterface() or was already
     *         removed
     */
    CommoResult removeBroadcastInterface(PhysicalNetInterface *iface);

    /**
     * Adds a new inbound listening interface on the specified port.
     * The local interface address is specified by hwAddress, the format for
     * which is dictated by the NetInterfaceAddressMode used to create this
     * Commo object (see constructor).
     * If mcastAddrs are given (non-NULL), each element must be a
     * dotted-decimal notation of a multicast group to listen on; 
     * the library will tell the system it is interested in
     * the given multicast groups on the specified interfaces.
     * Depending on the value of asGeneric, the interface will be
     * expecting to receive CoT messages or any sort of generic data
     * and be posted to the corresponding type of registered listeners
     * (CoTMessageListener or GenericDataListener, respectively).
     * NOTE: Generic and non-generic interfaces cannot be configured 
     * against different hwAddress-identified interfaces on the same 
     * port number!
     * @param hwAddress address identifier of the local network interface
     *                  to listen on
     * @param port the port number to listen on
     * @param mcastAddrs array of one or more multicast addresses to listen for
     *              traffic on (in addition to unicasted messages);
     *              each element is specified in the "dotted decimal" form.
     *              Can be NULL or an empty array to indicate that
     *              the interface is only to be used for unicast data.
     * @param nMcastAddrs number of addresses in the mcastAddrs array
     * @param asGeneric true if interface will expect and post generic
     *              data to GenericDataListeners or false to expect
     *              and post CoT messages to CoTMessageListeners
     * @return On success, PhysicalNetInterface object uniquely identifying the
     *         added interface.  Remains valid as long as it is
     *         not passed to removeInboundInterface. NULL on any error, 
     *         including but not limited to port out of range,
     *         mcastAddrs containing any invalid multicast addresses,
     *         specifying different asGeneric values on the same port,
     *         the specified port on the specified interface
     *         is already in use.
     */
    PhysicalNetInterface *addInboundInterface(const HwAddress *hwAddress, int port, const char **mcastAddrs, size_t nMcastAddrs, bool asGeneric);

    /**
     * Remove the specified interface from being used for message reception.
     * The iface can be removed regardless of if it is in the up or down state.
     * When this call completes, the interface will no longer be used.
     * However it is possible that previously received messages may be passed
     * to CoTMessageListeners during execution of this method.
     * After completion, the supplied PhysicalNetInterface is
     * considered invalid.
     *
     * @param iface previously added NetInterface to remove from service
     * @return SUCCESS if interface is valid and successfully removed,
     *         ILLEGAL_ARGUMENT if the supplied NetInterface 
     *         was not created via addInboundInterface() or
     *         was already removed
     */
    CommoResult removeInboundInterface(PhysicalNetInterface *iface);

    /**
     * Adds a new inbound TCP-based listening interface on the specified port.
     * Listens on all network interfaces. The interface will generally
     * be up most of the time, but may go down if there is some low-level 
     * system error. In this event, commo will attempt to re-establish
     * as a listener on the given port. 
     * @param port the local port number to listen on
     * @return On success, a TcpInboundNetInterface object uniquely
     *         identifying the added interface.  Remains valid as long as
     *         it is not passed to removeTcpInboundInterface. NULL if
     *         any error occurs, including but not limited to
     *         port out of range, or the specified port is already in use.
     */
    TcpInboundNetInterface *addTcpInboundInterface(int port);

    /**
     * Remove the specified inbound tcp-based interface from being 
     * used for message reception.
     * The iface can be removed regardless of if it is in the up or down state.
     * When this call completes, the interface will no longer be used.
     * However it is possible that previously received messages may be passed
     * to CoTMessageListeners during execution of this method.
     * After completion, the supplied TcpInboundNetInterface is
     * considered invalid.
     *
     * @param iface previously added NetInterface to remove from service
     * @return SUCCESS if iface is valid and successfully removed from use,
     *         ILLEGAL_ARGUMENT if the supplied NetInterface 
     *         was not created via addTcpInboundInterface() or
     *         was already removed
     */
    CommoResult removeTcpInboundInterface(TcpInboundNetInterface *iface);


    /**
     * Adds a new inbound Quic-based listening interface on the specified port.
     * Listens on all network interfaces. The interface will generally
     * be up most of the time, but may go down if there is some low-level 
     * system error. In this event, commo will attempt to re-establish
     * as a listener on the given port.
     * The certificate given will be presented to incoming connections.
     * @param port the local (udp) port number to listen on
     * @param cert certificate store, with key, in pkcs12 format
     * @param certLen length of cert, in bytes
     * @param certPass password for certificate
     * @param errCode if non-NULL, populated with an error code 
     *                if the method fails
     * @return On success, a QuicInboundNetInterface object uniquely
     *         identifying the added interface.  Remains valid as long as
     *         it is not passed to removeQuicInboundInterface. NULL if
     *         any error occurs, including but not limited to
     *         invalid certificate or certificate password, 
     *         port out of range or the specified port is already in use.
     */
    QuicInboundNetInterface *addQuicInboundInterface(int port,
                                      const uint8_t *cert,
                                      size_t certLen, 
                                      const char *certPass,
                                      CommoResult *errCode);

    /**
     * Remove the specified inbound quic-based interface from being 
     * used for message reception.
     * The iface can be removed regardless of if it is in the up or down state.
     * When this call completes, the interface will no longer be used.
     * However it is possible that previously received messages may be passed
     * to CoTMessageListeners during execution of this method.
     * After completion, the supplied QuicInboundNetInterface is
     * considered invalid.
     *
     * @param iface previously added NetInterface to remove from service
     * @return SUCCESS if iface is valid and successfully removed from use,
     *         ILLEGAL_ARGUMENT if the supplied NetInterface 
     *         was not created via addQuicInboundInterface() or
     *         was already removed
     */
    CommoResult removeQuicInboundInterface(QuicInboundNetInterface *iface);


    /**
     * Adds a new streaming interface to a remote TAK server. 
     *
     * This Commo instance will attempt to establish and maintain
     * a connection with a TAK server at the specified hostname on the
     * specified remote port number.  The connection will be used to
     * receive CoT messages of all types from the TAK server, for non-broadcast
     * sending of all types of CoT messages to contacts known via
     * this interface, as well as for broadcasting CoTMessages of the types
     * specified. Depending on the arguments given, attempts to connect will
     * be made with plain TCP, SSL encrypted TCP, or SSL encrypted with
     * server authentication: specifying NULL for clientCert, trustStore,
     * username, and password results in a plain TCP connection.
     * Specifying non-NULL for clientCert requires
     * trustStore to be non-NULL; this results in an SSL connection.
     * Additionally specifying non-NULL username and password will result
     * in the SSL connection that sends a TAK server authentication message
     * when connecting. For non-SSL connections, the username and password are
     * ignored and no auth message will be sent. Regardless of the type 
     * of connection, 
     * this Commo instance will attempt to create and restore the
     * server connection as needed until this interface is removed or this
     * Commo object is shutdown.
     * The returned interface is valid until removed via
     * removeStreamingInterfaceor this Commo object is shutdown.
     * All parameters are internally copied and need not remain valid after
     * this method completes.
     *  
     * @param hostname the resolvable hostname or "dotted decimal"
     *                 notation of the IP address of the server
     * @param port remote port number of the TAK server to connect to
     * @param types array of one or more CoTMessageTypes specifying the types
     *              of broadcast cot messages that will be sent out
     *              this interface;  may be NULL/empty if no broadcast
     *              messages should go out this interface
     * @param nTypes number of elements in the types array
     * @param clientCert if the connection is SSL based, this holds the 
     *                   client's certificate chain in
     *                   PKCS #12 format. This should include the certificate,
     *                   private key, and any additional certificates to
     *                   send to the server during authentication.
     *                   Use NULL for non-SSL connections
     * @param clientCertLen length of clientCert, in bytes
     * @param caCert if the connection is SSL based, this holds the
     *               certificate of the CA that signed the clientCert
     *               and that is to be used to verify the server cert,
     *               in PKCS #12 format. 
     *               Use NULL for non-SSL connections
     * @param caCertLen length of caCert, in bytes
     * @param certPassword for SSL connections, the passphrase to decode
     *                     the ca cert.
     *                     Use NULL for non-SSL connections
     * @param caCertPassword for SSL connections, the passphrase to decode
     *                     the ca cert.
     *                     Use NULL for non-SSL connections
     * @param username if non-NULL, an authentication message with the 
     *                 username and password specified will be sent to the
     *                 TAK server upon connection. If non-NULL, password
     *                 MUST also be non-NULL. Not used for non-SSL connections.
     * @param password the accompanying password to go with the username
     *                 in the authentication message
     * @param errCode if non-NULL, populated with an error code 
     *                if the method fails
     * @return on success, StreamingNetInterface object uniquely identifying
     *         the added interface.  Remains valid as long as it is
     *         not passed to removeStreamingInterface.  NULL if an error occurs,
     *         including but not limited to invalid certificates,
     *         invalid port numbers, or invalid combinations of arguments
     * @deprecated this variant of addStreamingInterface is legacy; please
     *     use the variant that specifies the transport method
     */
    COMMO_DEPRECATED StreamingNetInterface *addStreamingInterface(
                                                 const char *hostname,
                                                 int port,
                                                 const CoTMessageType *types,
                                                 size_t nTypes,
                                                 const uint8_t *clientCert, size_t clientCertLen,
                                                 const uint8_t *caCert, size_t caCertLen,
                                                 const char *certPassword,
                                                 const char *caCertPassword,
                                                 const char *username, const char *password,
                                                 CommoResult *errCode = NULL);

    /**
     * Adds a new streaming interface to a remote TAK server. 
     *
     * This Commo instance will attempt to establish and maintain
     * a connection with a TAK server at the specified hostname on the
     * specified remote port number.  The connection will be used to
     * receive CoT messages of all types from the TAK server, for non-broadcast
     * sending of all types of CoT messages to contacts known via
     * this interface, as well as for broadcasting CoTMessages of the types
     * specified. The connection will use the underlying transport protcol
     * specified in the first arugment.
     * For TRANSPORT_TCP, NULL MUST be specified for for clientCert, trustStore,
     * username, and password as these cannot be utilized on plain TCP
     * connections.
     * For TRANSPORT_SSL and TRANSPORT_QUIC, clientCert and
     * trustStore must be valid/non-NULL.  Additionally, with these
     * transports, a non-NULL username and password will result
     * in an SSL connection that sends a TAK server authentication message
     * when connecting. If username is given, password must also be given.
     * Regardless of the type of connection, 
     * this Commo instance will attempt to create and restore the
     * server connection as needed until this interface is removed or this
     * Commo object is shutdown.
     * The returned interface is valid until removed via
     * removeStreamingInterface or this Commo object is shutdown.
     * All parameters are internally copied and need not remain valid after
     * this method completes.
     *  
     * @param transport the transport protocol to use
     * @param hostname the resolvable hostname or "dotted decimal"
     *                 notation of the IP address of the server
     * @param port remote port number of the TAK server to connect to
     * @param types array of one or more CoTMessageTypes specifying the types
     *              of broadcast cot messages that will be sent out
     *              this interface;  may be NULL/empty if no broadcast
     *              messages should go out this interface
     * @param nTypes number of elements in the types array
     * @param clientCert if the connection is SSL based, this holds the 
     *                   client's certificate chain in
     *                   PKCS #12 format. This should include the certificate,
     *                   private key, and any additional certificates to
     *                   send to the server during authentication.
     *                   Use NULL for TCP connections
     * @param clientCertLen length of clientCert, in bytes
     * @param caCert if the connection is SSL based, this holds the
     *               certificate of the CA that signed the clientCert
     *               and that is to be used to verify the server cert,
     *               in PKCS #12 format. 
     *               Use NULL for TCP connections
     * @param caCertLen length of caCert, in bytes
     * @param certPassword for SSL connections, the passphrase to decode
     *                     the ca cert.
     *                     Use NULL for TCP connections
     * @param caCertPassword for SSL connections, the passphrase to decode
     *                     the ca cert.
     *                     Use NULL for TCP connections
     * @param username if non-NULL, an authentication message with the 
     *                 username and password specified will be sent to the
     *                 TAK server upon connection. If non-NULL, password
     *                 MUST also be non-NULL. Not used for TCP connections.
     * @param password the accompanying password to go with the username
     *                 in the authentication message
     * @param errCode if non-NULL, populated with an error code 
     *                if the method fails
     * @return on success, StreamingNetInterface object uniquely identifying
     *         the added interface.  Remains valid as long as it is
     *         not passed to removeStreamingInterface.  NULL if an error occurs,
     *         including but not limited to invalid certificates,
     *         invalid port numbers, or invalid combinations of arguments
     */
    StreamingNetInterface *addStreamingInterface(
            netinterfaceenums::StreamingTransport transport,
            const char *hostname, int port,
            const CoTMessageType *types,
            size_t nTypes,
            const uint8_t *clientCert, size_t clientCertLen,
            const uint8_t *caCert, size_t caCertLen,
            const char *certPassword,
            const char *caCertPassword,
            const char *username, const char *password,
            CommoResult *errCode = NULL);

    /**
     * Remove a previously added streaming interface. 
     * The iface can be removed regardless of if it is in the up or down state.
     * When this call completes, the interface will no longer be used.
     * However it is possible that previously received messages may be passed
     * to CoTMessageListeners during execution of this method.
     * After completion, the supplied StreamingNetInterface is
     * considered invalid.
     *  
     * @param iface previously added StreamingNetInterface to 
     *              remove from service
     * @return SUCCESS if iface is valid and successfully removed,
     *         ILLEGAL_ARGUMENT if the supplied
     *         StreamingNetInterface was not created via
     *         addStreamingInterface() or was already removed
     */
    CommoResult removeStreamingInterface(StreamingNetInterface *iface);


    /**
     * Register an InterfaceStatusListener to receive notifications 
     * of interface status changes.
     * @param listener the InterfaceStatusListener to add
     * @return SUCCESS if listener added successfully, ILLEGAL_ARGUMENT
     *         if the specified listener was already added
     */
    CommoResult addInterfaceStatusListener(InterfaceStatusListener *listener);

    /**
     * Remove a previously registered InterfaceStatusListener; upon completion
     * of this method, no additional status change messages will be sent to
     * the specified listener. Some state change messages may be delivered
     * to the listener during execution of this method, however.
     * 
     * @param listener the InterfaceStatusListener to remove
     * @return SUCCESS if the listener is successfully removed,
     *         ILLEGAL_ARGUMENT if the specified listener was
     *         not previously added using addInterfaceStatusListener
     */
    CommoResult removeInterfaceStatusListener(InterfaceStatusListener *listener);

    /**
     * Adds an instance of CoTMessageListener which desires to be notified
     * when new CoT messages are received. See CoTMessageListener
     * interface.
     * 
     * @param listener the listener to add
     * @return SUCCESS if listener added successfully, ILLEGAL_ARGUMENT
     *         if the specified listener was already added
     */
    CommoResult addCoTMessageListener(CoTMessageListener *listener);

    /**
     * Removes a previously added instance of CoTMessageListener;
     * upon completion of this method, the listener will no longer
     * receive any further event updates.  The listener may
     * receive events while this method is being executed.
     * 
     * @param listener the listener to remove
     * @return SUCCESS if the listener was removed successfully,
     *         ILLEGAL_ARGUMENT if the specified listener
     *         was not previously added
     */
    CommoResult removeCoTMessageListener(CoTMessageListener *listener);

    /**
     * Adds an instance of GenericDataListener which desires to be notified
     * when new data is received on any inbound interface created
     * for generic data reception. See GenericDataListener
     * interface.
     * 
     * @param listener the listener to add
     * @return SUCCESS if the listener was successfully added,
     *         ILLEGAL_ARGUMENT if the specified listener
     *         was already added
     */
    CommoResult addGenericDataListener(GenericDataListener *listener);

    /**
     * Removes a previously added instance of GenericDataListener;
     * upon completion of this method, the listener will no longer
     * receive any further event updates.  The listener may
     * receive events while this method is being executed.
     * 
     * @param listener the listener to remove
     * @return SUCCESS if listener is removed successfully, 
     *         ILLEGAL_ARGUMENT if the specified listener
     *         was not previously added
     */
    CommoResult removeGenericDataListener(GenericDataListener *listener);

    /**
     * Adds an instance of CoTSendFailureListener which desires to be notified
     * if a failure to send a CoT message to a specific contact or TCP
     * endpoint is detected. See CoTSendFailureListener interface.
     * 
     * @param listener the listener to add
     * @return SUCCESS if the listener is added successfully,
     *         ILLEGAL_ARGUMENT if the specified listener
     *         was already added
     */
    CommoResult addCoTSendFailureListener(CoTSendFailureListener *listener);

    /**
     * Removes a previously added instance of CoTSendFailureListener;
     * upon completion of this method, the listener will no longer
     * receive any further failure notifications.  The listener may
     * receive events while this method is being executed.
     * 
     * @param listener the listener to remove
     * @return SUCCESS if the listener is removed successfully,
     *         ILLEGAL_ARGUMENT if the specified listener
     *         was not previously added
     */
    CommoResult removeCoTSendFailureListener(CoTSendFailureListener *listener);


    /**
     * Send a CoT-formatted message to the specified Contacts.
     * The message is queued for transmission immediately, but the 
     * actual transmission is done asynchronously. Because of the
     * nature of CoT messaging, there may be no indication returned
     * of the success or failure of the transmission. If the means
     * by which the destination contact(s) is/are reachable allows for
     * error detection, transmission errors will be posted to any
     * CoTSendFailureListeners that are registered with this Commo instance.
     *
     * If CONTACT_GONE is returned from this method, the references in the
     * "destinations" list are reordered and the size is updated to indicate
     * which and how many of the provided Contacts are considered 'gone' OR
     * those that could not be sent to because the send method was incompatible
     * with their only known methods of reachability. Note that this is not
     * a fatal error; the message will still try to be sent to the contacts
     * not identified as "gone".
     *
     * sendMethod specifies how the message can be delivered - if the contact
     * does not have an endpoint matching the specified method(s), the
     * message will not be sent to them, GONE will be returned, and they
     * will be present at the head of the returned list. Specifying more
     * than one type does not mean the message will be sent via all
     * those methods; it merely specifies that those methods are allowed.
     *
     * Destination ContactUIDs in "destinations" and the cot message to send
     * need only remain valid for the duration of this call.
     * 
     * @param destinations Contacts to send to. This list may be updated 
     *                     during this call, see the method description
     *                     for details
     * @param cotMessage CoT message to send
     * @param sendMethod method(s) by which the message may be sent
     * @return SUCCESS if the message is accepted and all specified
     *         destination contacts have a known transmission method
     *         matching the provided sendMethod, ILLEGAL_ARGUMENT
     *         if cotMessage was not recognized as a valid message,
     *         CONTACT_GONE if one or more of the destination contacts
     *         is unknown or does not have a known transmission method
     *         matching the provided sendMethod (see above for
     *         how destinations list is modified in this case)
     */
    CommoResult sendCoT(ContactList *destinations, const char *cotMessage, CoTSendMethod sendMethod = SEND_ANY);

    /**
     * Sends the provided CoT-formatted message out all broadcast interfaces
     * and streams configured for the CoTMessageType of the cotMessage and
     * that match the send method specified.
     * The message is queued for delivery immediately, but the actual
     * transmission is done asynchronously.
     * The cot message to send need only remain valid for the duration of
     * this call.
     * 
     * @param cotMessage the CoT message content
     * @param sendMethod method by which to broadcast - other broadcast
     *               interfaces or streams not matching this method
     *               will be ignored when sending this broadcast
     * @return SUCCESS if the message is accepted for transmission
     *         ILLEGAL_ARGUMENT if cotMessage was not recognized as a
     *         valid message
     */
    CommoResult broadcastCoT(const char *cotMessage, CoTSendMethod sendMethod = SEND_ANY);

    /**
     * Attempt to send a CoT-formatted message to the specified host
     * on the specified TCP port number.  
     * The message is queued for transmission; the actual transmission happens
     * asynchronously.
     * A connection is made to the host on the specified port, the message
     * is sent, and the connection is closed.
     * If the transmission fails,
     * a failure will be posted to any registered CoTSendFailureListeners.
     * Use of this method is deprecated in favor of sendCoT().
     *
     * @param host host or ip number in string form designating the remote
     *                 system to send to
     * @param port destination TCP port number
     * @param cotMessage CoT message to send
     * @return SUCCESS if the message is accepted for future transmission,
     *         ILLEGAL_ARGUMENT if host, port, or cotMessage is not valid
     */
    CommoResult sendCoTTcpDirect(const char *host, int port, const char *cotMessage);

    /**
     * Attempts to send a CoT-formatted message to one or all connected
     * streaming interfaces with a special destination tag
     * that indicates to TAK server that this message is intended
     * as a control message for the server itself.
     * The message is queued for transmission; the actual transmission
     * happens asynchronously.
     * streamingRemoteId and cotMessage need only remain valid for the
     * duration of the method call.
     * @param streamingRemoteId the identifier of the 
     *        StreamingNetInterface to send to, or NULL
     *        to send to all streams.
     *                 This must correspond to a currently
     *                 valid StreamingNetInterface
     * @param cotMessage CoT message to send
     * @return SUCCESS if message accepted for future transmission,
     *         ILLEGAL_ARGUMENT if streamingRemoteId or cotMessage is not valid
     */
    CommoResult sendCoTServerControl(const char *streamingRemoteId,
                                     const char *cotMessage);
    
    /**
     * Attempts to send a CoT-formatted message to a mission-id
     * destination on a single, or all connected, streaming interfaces.
     * The message is queued for transmission; the actual transmission happens
     * asynchronously.
     * streamingRemoteId, mission and cotMessage need only remain valid for the
     * duration of the method call.
     * @param streamingRemoteId the identifier of the StreamingNetInterface
     *                 to send to, or NULL to send to all streams.
     *                 If given, must correspond to a currently
     *                 valid StreamingNetInterface
     * @param mission the mission identifier indicating the mission
     *                to deliver to
     * @param cotMessage CoT message to send
     * @return SUCCESS if message queued for future transmission,
     *         ILLEGAL_ARGUMENT if streamingRemoteId or cotMessage is not valid
     */
    CommoResult sendCoTToServerMissionDest(const char *streamingRemoteId,
                                           const char *mission,
                                           const char *cotMessage);

    /**
     * Initiate an enrollment operation for the given server.
     * The enrollment operation will be initialized and associated
     * with the unique identifier returned via enrollmentId. 
     * The enrollment operation will not commence processing until
     * enrollmentStart() is invoked with the returned identifier.
     * Once started, updates on progress
     * and completion status of the operation will be delivered to the
     * enrollmentIO interface implementation previously registered with this
     * Commo instance via enableEnrollment() (which must be successfully
     * invoked prior to using this method).
     * All arguments are required (non-NULL) unless otherwise noted and
     * need remain valid only for the duration of this method call.
     *
     * @param enrollmentId populated with enrollment operation identifier
     *                     when SUCCESS is returned
     * @param host the hostname or IP address of the server to enroll with
     * @param port the port that the specified server is configured to
     *             provide the enrollment API on
     * @param verifyHost true to verify that the server's SSL
     *                   certificate, provided during the https transaction,
     *                   matches the information provided in caCert
     * @param user username to use when authenticating to the server's
     *             enrollment process. 
     * @param password password to use when authenticating to the server's
     *             enrollment process when useTokenAuth is false, or the
     *             token to use for authentication when useTokenAuth is true
     * @param useTokenAuth specifies authentication mode and how the
     *             password parameter is interpreted.  Passing true will
     *             result in token based authentication being used and
     *             false will result in basic username/password authentication.
     * @param caCert a PKCS#12 certificate store to use when performing
     *               https transactions with the server. Supplying NULL
     *               will result in https operations not checking
     *               the server certificate
     * @param caCertLen length of caCert, in bytes
     * @param caCertPassword password used to decrypt caCert. May be NULL
     *               if (and only if) caCert is NULL
     * @param clientCertPassword password the enrollment operation should
     *             use to encrypt the client certificate resulting from the
     *             enrollment
     * @param enrolledTrustPassword password the enrollment operation should
     *             use to encrypt the trust/ca store resulting from the
     *             enrollment
     * @param keyPassword password the enrollment operation should use to
     *             encrypt the private key generated
     * @param keyLength length of private key to generate, in bits
     * @param clientVersionInfo version identifier the enrollment operation
     *             should present to the server, or NULL to not present
     *             an identifier
     * @return SUCCESS if the enrollment operation is successfully initialized
     *         and enrollmentId has been populated,
     *         INVALID_CACERT if caCert is not valid,
     *         INVALID_CACERT_PASSWORD if caCertPassword not correct for
     *         given caCert, or ILLEGAL_ARGUMENT if one of the required
     *         arguments was missing/NULL or invalid, or if this Commo
     *         instance has not yet had enrollment enabled via
     *         enableEnrollment().
     */
    CommoResult enrollmentInit(int *enrollmentId,
                               const char *host,
                               int port,
                               bool verifyHost,
                               const char *user,
                               const char *password,
                               bool useTokenAuth,
                               const uint8_t *caCert,
                               size_t caCertLen,
                               const char *caCertPassword,
                               const char *clientCertPassword,
                               const char *enrolledTrustPassword,
                               const char *keyPassword,
                               int keyLen,
                               const char *clientVersionInfo);

    /**
     * Commences an enrollment operation previously initialized 
     * via a call to enrollmentInit().
     * @param enrollmentId identifier of the previously initialized
     *        enrollment operation
     * @return SUCCESS if the enrollment operation successfully starts
     *        or ILLEGAL_ARGUMENT if the supplied id does not identify
     *        an initialized (but not already started) enrollment operation
     */
    CommoResult enrollmentStart(int enrollmentId);
    

    /**
     * Initiate a simple file transfer.  
     * Simple file transfers are transfers of files via traditional
     * client-server protocols (where commo is the client).
     * Transfer can be an upload from this device to the server
     * (forUpload = true) or a download from the server to this device
     * (forUpload = false).  Server file location is specified using
     * remoteURI while local file location is specified via localFile.
     * localFile must be able to be accessed (read/written) for the duration
     * of the transfer and assumes the transfer is the only thing accessing
     * the file. For downloads, localFile's parent directory must already
     * exist and be writable - the library will not create directories for you.
     * Existing files will be overwritten without warning; it is the calling
     * application's responsibility to verify localFile is the user's
     * intended location, including checking for existing files!
     * The given URL must include the protocol scheme.
     * Protocols currently supported are: ftp, ftps (ssl based ftp).
     * Other protocol support may be added in the future.
     * caCert is optional - if given (non-NULL), it is used in ssl-based
     * protocols to verify the server's certificate is signed by
     * the CA in the given cert. It must be in PKCS#12 format. If NULL,
     * no verification of the server's certificate will be performed.
     * User and password are optional; if given (non-NULL), they will be used
     * to attempt to login on the remote server. Do NOT put the
     * username/password in the URL!
     * A non-NULL password must be accompanied by a non-NULL user.
     * Upon successful return here, the transfer is configured and placed
     * in a waiting state.  The caller my commence the transfer by
     * invoking simpleTransferStart(), supplying the returned transfer id.
     *
     * @param xferId populated with unique transfer id on SUCCESS return
     * @param forUpload true to initiate upload, false for download
     * @param remoteURL URL of the resource on the server. This must be 
     *        a properly escaped/quoted URL
     * @param caCert optional CA certificate(s) to check server cert against
     * @param caCertLen length of caCert, in bytes
     * @param caCertPassword password for the CA cert data
     * @param remoteUsername optional username to log into remote server with
     * @param remotePassword optional password to log into the remote server with
     * @param localFileName local file to upload/local file location to write
     *        remote file to
     * @return SUCCESS if the transfer is initialzed successfully and
     *        xferId is populated, INVALID_CACERT if caCert is not valid,
     *        INVALID_CACERT_PASSWORD if caCertPassword
     *        not valid for caCert, ILLEGAL_ARGUMENT if remoteURL has
     *        an unsupported protocol, a password was given without a username,
     *        or that this Commo instance has not yet had SimpleFileIO enabled
     *        via enableSimpleFileIO().
     */
    CommoResult simpleFileTransferInit(int *xferId,
            bool forUpload,
            const char *remoteURL,
            const uint8_t *caCert, size_t caCertLen,
            const char *caCertPassword,
            const char *remoteUsername,
            const char *remotePassword,
            const char *localFileName);

    /**
     * Commences a simple file transfer previously initialized 
     * via a call to simpleFileTransferInit().
     * @param xferId id of the previously initialized transfer
     * @return SUCCESS if the transfer is valid and successfully started
     *        ILLEGAL_ARGUMENT if the supplied xferId does not identify
     *        an initialized (but not already started) transfer
     */
    CommoResult simpleFileTransferStart(int xferId);
    
    /**
     * Create a CloudClient to interact with a remote cloud server.
     * The client will remain valid until destroyed using destroyCloudClient()
     * or this Commo instance is shutdown.
     * The basePath is the path to the cloud application on the server.
     * If your cloud service is at the root of the server on the remote host
     * simply pass the empty string or "/" for the basePath.
     * The client uses the provided parameters to interact with the server
     * and the provided callback interface to report progress on operations
     * initiated using the Client's methods.
     * Any number of clients may be active at a given time.
     * caCerts is optional - if given (non-NULL), it is used in ssl-based
     * protocols to verify the server's certificate. It must be a valid
     * set of certs in PKCS#12 format.
     * If not provided (NULL) and an SSL protocol is in use, all remote
     * certificates will be accepted.
     * The user and password are optional; if given (non-NULL),
     * they will be used to attempt to login on the remote server.
     * A non-NULL password must be accompanied by a non-NULL user.
     * All arguments are required (non-NULL) unless otherwise noted.
     * With the exception of "io", all arguments need only be valid
     * for the duration of this call.  "io" must remain valid until this
     * client is destroyed or this Commo instance is shutdown.
     *
     * @param result populated with the new CloudClient on SUCCESS return
     * @param io CloudIO callback interface instance to report progress
     *           of all client operations to
     * @param proto Protocol used to interact with server
     * @param host hostname or IP of remote server
     * @param port port of remote server
     * @param basePath base path to remote cloud server on the given host.
     *                 MUST be properly URL encoded. Cannot be NULL!
     * @param user optional username to log into remote server with
     * @param password optional password to log into the remote server with
     * @param caCerts optional CA certificates to check server cert against
     * @param caCertsLen length of caCerts, in bytes
     * @param caCertsPassword password for the CA cert data
     * @return SUCCESS if the client is created and populated in "result",
     *        INVALID_CACERT if caCerts is not valid,
     *        INVALID_CACERT_PASSWORD if caCertsPassword
     *        not valid for caCert, ILLEGAL_ARGUMENT host, port,
     *        or any arguments are otherwise invalid
     */
    CommoResult createCloudClient(CloudClient **result, 
                         CloudIO *io,
                         CloudIOProtocol proto,
                         const char *host,
                         int port,
                         const char *basePath,
                         const char *user,
                         const char *password,
                         const uint8_t *caCerts,
                         size_t caCertsLen,
                         const char *caCertsPassword);

    /**
     * Destroy a CloudClient created by an earlier call to createCloudClient().
     * This will terminate all client operations, including ongoing transfers,
     * before completion.  Existing operations may or may not receive callbacks
     * during the destruction.
     * 
     * @param client the client to destroy
     * @return SUCCESS if client is successfully destroyed, ILLEGAL_ARGUMENT
     *         if an error occurs
     */
    CommoResult destroyCloudClient(CloudClient *client);

    /**
     * Initialize a Mission Package transfer of a file to the 
     * specified contact(s).  The list of contact(s) is updated
     * to indicate which contact(s) could not be sent to (considered "gone").
     * This call sets up the transfer and places
     * it into a pending state, returning an identifier that can be used
     * to correlate transfer status information back to this
     * request (it uniquely identifies this transfer).
     * To commence the actual transfer, call startMissionPackageSend() with
     * the returned id. It is guaranteed that no status info
     * will be fed back for the transfer until it has been started.
     * Once the send has been started, transmission will be initiated as
     * soon as possible, but the actual processing by and transfer to
     * the receiver will take place asynchronously in the background.
     * The file being transferred must remain available at the
     * specified location until the asynchronous transaction is
     * entirely complete.
     * If CONTACT_GONE is returned from this method, the references in the
     * "destinations" list are reordered and the size is updated to indicate
     * which and how many of the provided Contacts are considered 'gone'.
     * Note that this is still a successful initialization, xferId is still
     * populated, and the transfer is still ready and pending to start!
     * All arguments are required (non-NULL) and need only remain valid for
     * the duration of this call.
     *
     * @param xferId on CONTACT_GONE or SUCCESS return, this is
     *               populated with unique transfer identifier
     * @param destinations Contacts to send to. This list may be updated
     *                     during the call (see method description)
     * @param filePath the Mission Package file to send
     * @param xferFileName the name by which the receiving system should refer
     *                     to the file (no path, file name only). This name
     *                     does NOT have to be the same as the local file name.
     * @param xferName the name for the transfer, used to generically refer
     *                 to the transfer both locally and remotely
     * @param accessAttrib the value to use for the "access" attribute when
     *                     generating CoT messages associated with this transfer.
     *                     It is assumed the passed value is valid; no checks
     *                     are performed on the value.
     *                     NULL will be treated as "Undefined"
     * @param caveatAttrib the value to use for the "caveat" attribute when
     *                     generating CoT messages associated with this
     *                     transfer.
     *                     It is assumed the passed value is valid; no checks
     *                     are performed on the value.
     *                     NULL will omit the attribute.
     * @param relToAttrib the value to use for the "releasableTo" attribute
     *                    when generating CoT messages associated with this
     *                    transfer.
     *                    It is assumed the passed value is valid; no checks
     *                    are performed on the value.
     *                    NULL will omit the attribute.
     * @return SUCCESS if the transfer is initialize successfully,
     *         CONTACT_GONE if one or more of the 
     *         contacts in destination list are considered "gone" (in which
     *         case the destinations list is updated as described above),
     *         or ILLEGAL_ARGUMENT if the file is not readable, 
     *         setupMissionPackageIO() was not yet invoked successfully,
     *         all destinations are unreachable, or some other error occurs
     */
    CommoResult sendMissionPackageInit(int *xferId,
            ContactList *destinations,
            const char *filePath,
            const char *xferFileName,
            const char *xferName,
            const char *accessAttrib,
            const char *caveatAttrib,
            const char *relToAttrib);

    /**
     * Initialize a Mission Package transfer of a file to the 
     * specified contact(s).  The list of contact(s) is updated
     * to indicate which contact(s) could not be sent to (considered "gone").
     * This call sets up the transfer and places
     * it into a pending state, returning an identifier that can be used
     * to correlate transfer status information back to this
     * request (it uniquely identifies this transfer).
     * To commence the actual transfer, call startMissionPackageSend() with
     * the returned id. It is guaranteed that no status info
     * will be fed back for the transfer until it has been started.
     * Once the send has been started, transmission will be initiated as
     * soon as possible, but the actual processing by and transfer to
     * the receiver will take place asynchronously in the background.
     * The file being transferred must remain available at the
     * specified location until the asynchronous transaction is
     * entirely complete.
     * If CONTACT_GONE is returned from this method, the references in the
     * "destinations" list are reordered and the size is updated to indicate
     * which and how many of the provided Contacts are considered 'gone'.
     * Note that this is still a successful initialization, xferId is still
     * populated, and the transfer is still ready and pending to start!
     * All arguments are required (non-NULL) and need only remain valid for
     * the duration of this call.
     *
     * @param xferId on CONTACT_GONE or SUCCESS return, this is
     *               populated with unique transfer identifier
     * @param destinations Contacts to send to. This list may be updated
     *                     during the call (see method description)
     * @param filePath the Mission Package file to send
     * @param xferFileName the name by which the receiving system should refer
     *                     to the file (no path, file name only). This name
     *                     does NOT have to be the same as the local file name.
     * @param xferName the name for the transfer, used to generically refer
     *                 to the transfer both locally and remotely
     * @deprecated use the alternate version of this method which takes
     *             the three security attributes. This will be removed 
     * @return SUCCESS if the transfer is initialize successfully,
     *         CONTACT_GONE if one or more of the 
     *         contacts in destination list are considered "gone" (in which
     *         case the destinations list is updated as described above),
     *         or ILLEGAL_ARGUMENT if the file is not readable, 
     *         setupMissionPackageIO() was not yet invoked successfully,
     *         all destinations are unreachable, or some other error occurs
     */
    COMMO_DEPRECATED CommoResult sendMissionPackageInit(int *xferId,
            ContactList *destinations,
            const char *filePath,
            const char *xferFileName,
            const char *xferName);

    /**
     * Initialize a mission package file transfer to the specified TAK server.
     * This method simply initializes the transfer; use
     * sendMissionPackageStart() after a successful initialization to 
     * actually start the transfer.
     * Once the transfer is started the server is first queried to see
     * if the file exists on server already.
     * If not, the file is transmitted to the server.
     * The query and the transmission (if needed) are
     * initiated as soon as possible, but this takes place asynchronously 
     * in the background.  The returned ID can be used to correlate 
     * transfer status information back to this request (it
     * uniquely identifies this transfer).
     * The file being transfered must remain available at the
     * specified location until the asynchronous transaction is entirely
     * complete.
     * All arguments are required (non-NULL) and only need to remain valid
     * for the duration of this call.
     * 
     * @param xferId on SUCCESS return, populated with the unique remote
     *               identifier for the transfer
     * @param streamingRemoteId the identifier of the 
     *                 StreamingNetInterface to send to.
     *                 This must correspond to a currently
     *                 valid StreamingNetInterface
     * @param filePath the Mission Package file to send
     * @param xferFileName the name by which the receiving system should refer
     *                     to the file (no path, file name only). This name
     *                     does NOT have to be the same as the local file name.
     * @return SUCCESS if the transfer is successfully initialized and
     *         xferId populated, CONTACT_GONE if streamingRemoteId does not
     *         correspond to a currently valid StreamingNetInterface,
     *         or ILLEGAL_ARGUMENT if the file is not readable,
     *         setupMissionPackageIO has not yet been successfully invoked,
     *         or some other error occurs
     */
    CommoResult sendMissionPackageInit(int *xferId,
            const char *streamingRemoteId,
            const char *filePath,
            const char *xferFileName);

    /**
     * Begins the transfer process for a pending mission package send
     * initialized by a prior call to sendMissionPackageInit().
     * The transmission is initiated as soon as possible, but the
     * actual processing by and transfer to the receiver will take
     * place asynchronously in the background as described in
     * sendMissionPackageInit().
     *
     * @param xferId the identifier of the mission package send to start
     * @return SUCCESS if the xferId is valid and the send is started,
     *         ILLEGAL_ARGUMENT if the xferId is invalid
     */
    CommoResult sendMissionPackageStart(int xferId);



    /**
     * Returns the full list of Contacts currently known to the system.
     * Contacts generally remain valid targets for the entire life
     * of this Commo instance. However, Contacts known via streaming
     * connections may be considered "gone" if the streaming connection is
     * closed or lost.
     * This always returns a valid array; if no contacts are known,
     * a zero-length array is returned.
     * Caller must release the list when done with it by passing to
     * freeContactList (even if it contained 0 contacts).
     * Note that the contact list is never reclaimed via other means (including
     * deleting this Commo object).
     * 
     * @return list of all known Contacts
     */
    const ContactList *getContactList();

    /**
     * Frees a contact list and its elements which were
     * previously obtained via getContactList().
     *
     * @param contactList the contactList to free
     */
    static void freeContactList(const ContactList *contactList);


    /**
     * Configure and create a "known endpoint" contact. 
     * This is a non-discoverable contact for whom we already know
     * an endpoint and want to be able to communicate with them, possibly
     * unidirectionally.  The destination address must be specified in
     * "dotted decimal" IP address form; hostnames are not accepted.
     * If the address is a multicast address, messages sent to the created
     * Contact will be multicasted to all configured broadcast interfaces,
     * regardless of message type.
     * The port specifies a UDP port endpoint on the specified remote host.
     * The UID must be unique from existing known UIDs and should be chosen
     * to be unique from other potentially self-discovered contacts;
     * any message-based discovery for a contact with the same UID as the one
     * specified will be ignored - the endpoint remains fixed to the specified
     * one.
     * Specifying a UID of an already configured, known endpoint contact
     * allows it to be reconfigured to a new endpoint or callsign; specify
     * NULL for callsign and ipAddr (and any port number) to remove this
     * "contact". Specifying NULL for either callsign or ipAddr (but not both),
     * specifying a UID for an already known (via discovery) contact,
     * passing a NULL UID, passing a NULL ipAddr for a contact not previously
     * configured via this call, or providing an unparsable ipAddr is invalid
     * and will result in ILLEGAL_ARGUMENT return.
     * All arguments need remain valid only for the duration of this call.
     * @param contact uid for the contact
     * @param callsign callsign for the contact
     * @param ipAddr ip address in "dotted decimal" form
     * @param destPort the port to send to
     * @return SUCCESS if the contact is added, changed, or removed
     *         as specified, ILLEGAL_ARGUMENT for invalid combinations of 
     *         arguments
     */
    CommoResult configKnownEndpointContact(const ContactUID *contact,
                                           const char *callsign,
                                           const char *ipAddr,
                                           int destPort);

    /**
     * Registers a ContactPresenceListener to be notified when new Contacts
     * are discovered and no longer valid Contacts are removed.
     * @param listener ContactPresenceListener to register
     * @return SUCCESS if the listener is successfully registered,
     *         ILLEGAL_ARGUMENT if the specified listener
     *         was already added
     */
    CommoResult addContactPresenceListener(ContactPresenceListener *listener);

    /**
     * Remove a previously registered ContactPresenceListener; upon completion
     * of this method, no additional contact presence change messages will be sent to
     * the specified listener. Some messages may be delivered to the
     * listener during execution of this method, however.
     * 
     * @param listener the ContactPresenceListener to remove
     * @return SUCCESS if the listener is successfully removed,
     *         ILLEGAL_ARGUMENT if the specified listener was not
     *         previously added using addContactPresenceListener
     */
    CommoResult removeContactPresenceListener(ContactPresenceListener *listener);


    // Next 4 support CSR gen for tak server cert requests. Results
    // NULL for errors, requested string for success.  Free result
    // using freeCryptoString().
    // All of them are deprecated and replaced by the
    // enrollmentInit/enrollmentStart methods
    char *generateKeyCryptoString(const char *password, const int keyLen);
    char *generateCSRCryptoString(const char **dnEntryKeys, const char **dnEntryValues,
                                  size_t nDnEntries, const char *pkeyPem, 
                                  const char *password);
    char *generateKeystoreCryptoString(const char *certPem, const char **caPem, 
                           size_t nCa, const char *pkeyPem,
                           const char *password, 
                           const char *friendlyName);
    void freeCryptoString(char *cryptoString);
    
    
    /**
     * Generate a self-signed certificate with private key.
     * Values in the cert are filled with nonsense data.
     * Certificates from this cannot be used to interoperate with commerical
     * tools due to lack of signature by trusted CAs.
     * The returned data is in pkcs12 format protected by the supplied
     * password, which cannot be NULL.
     * The returned cert data must be freed when no longer needed using
     * freeSelfSignedCert()
     * @param cert populated with the pkcs12 self-signed certificate
     *             and private key generated
     * @param password the password used to protect the new certificate
     * @return length of the newly generated certificate in cert
     */
    size_t generateSelfSignedCert(uint8_t **cert, const char *password);
    
    /**
     * Frees a self-signed cert previously generated using
     * generateSelfSignedCert()
     * @param cert cert data buffer to deallocate
     */
    void freeSelfSignedCert(uint8_t *cert);


    
    /**
     * Convert cot in XML form to a specific version of the TAK protocol.
     * The tak protocol data is prefaced with the tak protocol
     * broadcast header.
     * NOTE: this method does not accept version = 0 (legacy XML) since
     * that would be a silly conversion!
     * Allocated data returned (on success) must be freed via takmessageFree()
     *
     * @param protodata populated with tak protocol data on SUCCESS return
     * @param dataLen populated with length (in bytes) of data in "protodata"
     *                on SUCCESS return
     * @param cotXml xml to convert
     * @param desiredVersion TAK protocol version to convert to
     * @return SUCCESS if the conversion is completed and results populated
     *         in protodata and dataLen, ILLEGAL_ARGUMENT on any error
     *         including invalid source XML CoT, invalid protocol version,
     *         or any conversion error
     */    
    CommoResult cotXmlToTakproto(char **protodata, size_t *dataLen,
                                 const char *cotXml, int desiredVersion);

    /**
     * Convert TAK protocol data (with TAK protocol header) to the
     * XML equivalent.
     * Data returned (on successful invocation) must be later deallocated using
     * takmessageFree().
     *
     * @param cotXml populated with a newly allocated, NULL terminated string
     *               containing the converted 
     *               CoT event portion of the TAK protocol message
     *               (on successful return)
     * @param protodata the TAK protocol data. It must begin with the
     *                  tak protocol broadcast header
     * @param dataLen length of the data in protodata
     * @return SUCCESS upon successful conversion and population of cotXml,
     *         ILLEGAL_ARGUMENT if the protodata is not valid TAK protocol
     *         data, it is for an unsupported version, the proto data does
     *         not contain a CoT Event, or if the conversion fails for any
     *         other reason 
     */
    CommoResult takprotoToCotXml(char **cotXml,
                                 const char *protodata,
                                 const size_t dataLen);

    /**
     * Deallocates a TAK message buffer returned from takprotoToCotXML()
     * or cotXmlToTakproto()
     * @param takmessage the buffer to deallocate
     */
    void takmessageFree(char *takmessage);
    
    /**
     * Obtain a string form version identifier for the version of Commo
     * in use at runtime. The returned string need not be deallocated by
     * the caller.
     * @return string identifier for the version of Commo in use
     */
    static const char *getVersionString();

private:
    COMMO_DISALLOW_COPY(Commo);


    atakmap::commoncommo::impl::CommoImpl *impl;
};


}
}

#endif /* COMMO_H_ */
