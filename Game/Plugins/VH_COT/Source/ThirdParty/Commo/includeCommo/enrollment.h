#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include <stdint.h>
#include <stddef.h>

#include "simplefileio.h"

namespace atakmap {
namespace commoncommo {

enum EnrollmentStep {
    // fail - invalid args only?
    // done - give back key blob+len
    ENROLL_STEP_KEYGEN,
    // fail - unknown host, connect fail, ssl untrusted, ssl other,
    // auth/login, io error, timeout
    // done - nothing back
    ENROLL_STEP_CSR,
    // same as above
    // done - cert blob+len, trust blob+len
    ENROLL_STEP_SIGN
};

// Uses same semantics as it's superclass, but adds identifier of what 
// step of enrollment operation is in progress or finishing and
// data fields to supplement.
// Updates are issued for one EnrollmentStep at a time, with progress
// updates when applicable; success on a step will subsequently give updates
// on next step.
// bytes transferred info is indication of progress on each step.
// STEP_SIGN update with FILEIO_SUCCESS indicates final update/end
// of enrollment transaction.
// Any update that is NOT FILEIO_INPROGRESS or FILEIO_SUCCESS terminates
// entire enrollment operation.
struct COMMONCOMMO_API EnrollmentIOUpdate : public SimpleFileIOUpdate
{
    EnrollmentStep step;

    // KEYGEN SUCCESS: generated private key in PEM format
    // SIGN SUCCESS: signed client cert and associated CAs in p12 format
    // others: null
    // Valid only during callback, so copy to keep it
    const uint8_t *privResult;
    size_t privResultLen;
    
    // SIGN SUCCESS: CAs from signing request in p12 format if any were
    //               given by server in reply. May be null if none given.
    // others null
    // Valid only during callback, so copy to keep it
    const uint8_t *caResult;
    size_t caResultLen;
    
protected:
    EnrollmentIOUpdate(EnrollmentStep step,
            const int xferid,
            const SimpleFileIOStatus status,
            const char *additionalInfo,
            uint64_t bytesTransferred,
            uint64_t totalBytesToTransfer,
            uint8_t *privResult,
            size_t privResultLen,
            uint8_t *caResult,
            size_t caResultLen) : SimpleFileIOUpdate(
                                        xferid,
                                        status,
                                        additionalInfo,
                                        bytesTransferred,
                                        totalBytesToTransfer),
                                        step(step),
                                        privResult(privResult),
                                        privResultLen(privResultLen),
                                        caResult(caResult),
                                        caResultLen(caResultLen)
                                        {};
    virtual ~EnrollmentIOUpdate() {};

private:
    COMMO_DISALLOW_COPY(EnrollmentIOUpdate);
};

class COMMONCOMMO_API EnrollmentIO
{
public:
    virtual void enrollmentUpdate(const EnrollmentIOUpdate *update) = 0;

protected:
    EnrollmentIO() {};
    virtual ~EnrollmentIO() {};

private:
    COMMO_DISALLOW_COPY(EnrollmentIO);
};



}
}

#endif
