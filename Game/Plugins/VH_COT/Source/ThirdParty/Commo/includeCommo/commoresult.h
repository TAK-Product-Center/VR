#ifndef COMMORESULT_H_
#define COMMORESULT_H_


namespace atakmap {
namespace commoncommo {


/**
 * enum of result codes used by various Commo methods
 */
enum CommoResult {
    /**
     * Indicates success of the invoked operation
     */
    COMMO_SUCCESS,

    /**
     * One or more arguments was invalid and caused the operation to fail.
     */
    COMMO_ILLEGAL_ARGUMENT,
    
    /**
     * One or more contacts specified were no longer reachable/valid.
     * This may be a fatal error or a partial failure; see the API docs
     * for the invoked method for the specific severity of the error.
     */
    COMMO_CONTACT_GONE,
    
    /**
     * An invalid client certificate was specified
     */
    COMMO_INVALID_CERT,

    /**
     * An invalid CA certificate was specified
     */
    COMMO_INVALID_CACERT,

    /**
     * An incorrect password for the given certificate was specified
     */
    COMMO_INVALID_CERT_PASSWORD,

    /**
     * An incorrect password for the given CA certificate was specified
     */
    COMMO_INVALID_CACERT_PASSWORD,
};

}
}


#endif /* COMMORESULT_H_ */
