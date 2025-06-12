#ifndef NETINTERFACE_H_
#define NETINTERFACE_H_


#include "commoutils.h"
#include <stdint.h>
#include <stddef.h>

namespace atakmap {
namespace commoncommo {

namespace netinterfaceenums {

    /**
     * Enumeration of various network-related error codes
     */
    typedef enum  {
        /** Name resolution for a hostname failed */
        ERR_CONN_NAME_RES_FAILED,
        /** Connection to remote host actively refused */
        ERR_CONN_REFUSED,
        /** Connection to remote host timed out */
        ERR_CONN_TIMEOUT,
        /** Remote host is known to be unreachable at this time */
        ERR_CONN_HOST_UNREACHABLE,
        /** Remote host was expected to present an SSL certificate but didn't */
        ERR_CONN_SSL_NO_PEER_CERT,
        /** Remote host's SSL certificate was not trusted */
        ERR_CONN_SSL_PEER_CERT_NOT_TRUSTED,
        /** SSL handshake with remote host encountered an error */
        ERR_CONN_SSL_HANDSHAKE,
        /**
         * Some other, non-specific, error occurred during attempting
         * to connect to a remote host
         */
        ERR_CONN_OTHER,
        /**
         * No data was received and the connection was considered
         * in error/timed out and is being reset
         */
        ERR_IO_RX_DATA_TIMEOUT,
        /** A general IO error occurred */
        ERR_IO,
        /** Some internal error occurred (out of memory, etc) */
        ERR_INTERNAL,
        /** Some unclassified error has occurred */
        ERR_OTHER
    } NetInterfaceErrorCode;

    /**
     * Enumeration of possible addressing modes used to identify
     * how HwAddress's are to be interpreted.  This is specified
     * to a Commo instance during creation (see Commo constructor)
     */
    typedef enum  {
        /** HwAddress's represent mac/ethernet addresses */
        MODE_PHYS_ADDR,
        /** HwAddress's represent interface names */
        MODE_NAME
    } NetInterfaceAddressMode;
    
    typedef enum {
        TRANSPORT_TCP,
        TRANSPORT_SSL,
        TRANSPORT_QUIC
    } StreamingTransport;
}



/**
 * A unique identifier for a network interface.  The data contained
 * within is interpreted according to the currently active
 * NetInterfaceAddressMode
 */
struct HwAddress
{
    /** Length of hwAddr, in bytes */
    const size_t addrLen;
    /** Unique address identifier of a network interface */
    const uint8_t * const hwAddr;
    
    /**
     * Creates an HwAddress encompassing the given address data.
     * @param hwAddr array of unique address data. The array must remain
     *               valid for the lifetime of this HwAddress instance
     * @param len length of hwAddr
     */
    HwAddress(const uint8_t *hwAddr, const size_t len) : addrLen(len), hwAddr(hwAddr) {
    }
private:
    COMMO_DISALLOW_COPY(HwAddress);
};



/**
 * Abstract base class for all Commo NetInterfaces.
 */
class NetInterface
{
protected:
    NetInterface() {};
    virtual ~NetInterface() {};
    COMMO_DISALLOW_COPY(NetInterface);
};



/**
 * Class representing a NetInterface for a network interface on the physical
 * device (ethernet port, wifi, etc).
 * PhysicalNetInterfaces are identified by a unique hardware address or
 * name, depending on the hardware address mode.
 */
class PhysicalNetInterface : public NetInterface
{
public:
    /**
     * The hardware address information
     * used to match this physical network interface.
     */    
    const HwAddress * const addr;

protected:
    PhysicalNetInterface(const HwAddress *addr) : addr(addr) {};
    virtual ~PhysicalNetInterface() {};
    COMMO_DISALLOW_COPY(PhysicalNetInterface);
};



/**
 * Class representing a peer-to-peer listening NetInterface.
 * InboundNetInterfaces listen on all local physical devices.
 */
class InboundNetInterface : public NetInterface
{
public:
    /**
     * The local port in use by this InboundNetInterface
     */
    const int port;

protected:
    InboundNetInterface(const int port) : port(port) {};
    virtual ~InboundNetInterface() {};
    COMMO_DISALLOW_COPY(InboundNetInterface);
};



/**
 * Class representing a tcp-based listening NetInterface.
 * TCP interfaces listen on all local physical devices and are
 * unique by local listening port number.
 */
class TcpInboundNetInterface : public InboundNetInterface
{
protected:
    TcpInboundNetInterface(const int port) : InboundNetInterface(port) {};
    virtual ~TcpInboundNetInterface() {};
    COMMO_DISALLOW_COPY(TcpInboundNetInterface);
};



/**
 * Class representing a Quic-based listening NetInterface.
 * Quic interfaces listen on all local physical devices and are
 * unique by local listening port number.
 */
class QuicInboundNetInterface : public InboundNetInterface
{
protected:
    QuicInboundNetInterface(const int port) : InboundNetInterface(port) {};
    virtual ~QuicInboundNetInterface() {};
    COMMO_DISALLOW_COPY(QuicInboundNetInterface);
};



/**
 * Class representing a NetInterface to a streaming server (TAK server).
 * StreamingNetInterfaces are unique in their "remote endpoint id" property.
 */
class StreamingNetInterface : public NetInterface
{
public:
    /**
     * Remote endpoint identifier string; NULL terminated for convenience,
     * which is not included in remoteEndpointLen
     */
    const char * const remoteEndpointId;
    
    /**
     * Length, in characters, of remoteEndpointId, not including
     * any NULL terminator.
     */
    const size_t remoteEndpointLen;

protected:
    StreamingNetInterface(const char *remoteEndpoint,
                          const size_t remoteEndpointLen) :
                              remoteEndpointId(remoteEndpoint),
                              remoteEndpointLen(remoteEndpointLen) {};
    virtual ~StreamingNetInterface() {};
    COMMO_DISALLOW_COPY(StreamingNetInterface);
};


/**
 * Interface that can be implemented and registered with a Commo instance
 * indicate interest in knowing about changes to the status of network
 * interfaces.
 */
class InterfaceStatusListener
{
public:
    /**
     * Invoked when a NetInterface is active and able to send or receive data.
     * For StreamingNetInterfaces, this is when the server connection is made.
     * @param iface the NetInterface whose status changed.
     */
    virtual void interfaceUp(NetInterface *iface) = 0;

    /**
     * Invoked when a NetInterface is no longer available and thus unable
     * to send or receive data. If it becomes available again in the future,
     * interfaceUp will be invoked with the same NetInterface as an argument.
     * For StreamingNetInterfaces, this is when the server connection is lost
     * or otherwise terminated.
     * @param iface the NetInterface whose status changed.
     */
    virtual void interfaceDown(NetInterface *iface) = 0;

    /**
     * Invoked when a NetInterface makes an attempt to come online
     * but fails for any reason, or when an interface that is up is forced
     * UNEXPECTEDLY into a down state. The error code gives the reason
     * for the error.
     * A callback to this does not imply a permanent error; attempts
     * will continue to be made to bring up the interface unless it is
     * removed.
     * @param iface the NetInterface on which the error occurred
     * @param err indication of the error that occurred
     */
    virtual void interfaceError(NetInterface *,
             netinterfaceenums::NetInterfaceErrorCode ) {};

protected:
    InterfaceStatusListener() {};
    virtual ~InterfaceStatusListener() {};

private:
    COMMO_DISALLOW_COPY(InterfaceStatusListener);
};


}
}




#endif /* NETINTERFACE_H_ */
