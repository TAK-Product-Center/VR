#ifndef COMMOLOGGER_H_
#define COMMOLOGGER_H_

#include <cstdint>
#include <cstddef>

#include "commoutils.h"

namespace atakmap {
namespace commoncommo {


/**
 * Interface that the Commo library will deliver logging messages to.
 * An implementation of this must be registered with the Commo class;
 * see the Commo constructor.
 */
class COMMONCOMMO_API CommoLogger {
public:
    /**
     * Various level tags used to identify the severity class
     * of messages originating from within the Commo library.
     */
    typedef enum {
        LEVEL_VERBOSE,
        LEVEL_DEBUG,
        LEVEL_WARNING,
        LEVEL_INFO,
        LEVEL_ERROR,
    } Level;

    typedef enum
    {
        /**
         * A general case / catch all type of log message.
         * Will not have a detail (detail will be NULL)
         */
        TYPE_GENERAL,
        /**
         * Log message related to network message parsing.
         * Detail, if non-NULL, will be a ParsingDetail
         */
        TYPE_PARSING,
        /**
         * Log message related to network interfaces.
         * Detail, if non-NULL, will be a NetworkDetail
         */
        TYPE_NETWORK,
    } Type;

    struct COMMONCOMMO_API ParsingDetail
    {
        /** Binary message data received. Never NULL, but may be 0 length. */
        const uint8_t* const messageData;
        /** Length of message data. May be 0. */
        const size_t messageLen;
        /** Human-readable detail of why the parse failed */
        const char* const errorDetailString;
        /** Identifier of Network Interface where message was received */
        const char* const rxIfaceEndpointId;
    };

    /**
     * Detail on a TYPE_NETWORK log message. Currently
     * only used for non-tcp inbound network interfaces
     */
    struct COMMONCOMMO_API NetworkDetail
    {
        /**
         * Port number of the (non-tcp) inbound interface
         * issuing the log message
         */
        const int port;
    };

    CommoLogger() {};

    /**
     * Invoked by the Commo library to log a message. 
     * Note that implementations of this method must be prepared to be invoked
     * by multiple threads at once.
     * @param level the level/severity of the message
     * @param type the type of information being logged
     * @param message the message to log
     * @param detail additional detail whose type is indicated by the type
     *               parameter - may be NULL
     */
    virtual void log(Level level, Type type, const char* message, void* detail) = 0;


protected:
    virtual ~CommoLogger() {};

private:
    COMMO_DISALLOW_COPY(CommoLogger);
};


}
}


#endif /* COMMOLOGGER_H_ */
