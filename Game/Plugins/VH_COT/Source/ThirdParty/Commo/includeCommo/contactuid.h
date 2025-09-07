#ifndef CONTACTUID_H_
#define CONTACTUID_H_


#include "commoutils.h"
#include <stddef.h>
#include <stdint.h>

namespace atakmap {
namespace commoncommo {

/**
 * A unique ID for a contact.  The unique ID's form and format is not
 * dictated by this class or library and is intentionally effectively
 * opaque in nature.
 */
struct COMMONCOMMO_API ContactUID
{
    /**
     * Length, in bytes, of the contactUID
     */
    const size_t contactUIDLen;

    /**
     * UID data
     */
    const uint8_t * const contactUID;

    /**
     * Create a new ContactUID.  The provided data is held as-is
     * and must remain valid for the life of this ContactUID.
     * @param contactUIDdata opaque UID data buffer
     * @param len length, in bytes, of the contactUIDdata
     */
    ContactUID(const uint8_t *contactUIDdata, size_t len) :
                contactUIDLen(len), contactUID(contactUIDdata) {
    }
private:
    COMMO_DISALLOW_COPY(ContactUID);
};

/**
 * A list of contacts identified by UID.
 */
struct COMMONCOMMO_API ContactList
{
    /**
     * Number of elements in contacts
     */
    size_t nContacts;

    /**
     * Array of contact's UIDs
     */
    const ContactUID **contacts;
    
    /**
     * Creates an empty contact list
     */
    ContactList() : nContacts(0), contacts(NULL)
    {
    }
    
    /**
     * Creates a new contact list wrapping up the given array.
     * @param nContacts number of contacts in the contacts array
     * @param contacts array of contacts. The array and the UIDs within
     *        must remain valid for the lifetime of the ContactList
     */
    ContactList(const size_t nContacts, const ContactUID **contacts) :
        nContacts(nContacts), contacts(contacts)
    {
    }
private:
    COMMO_DISALLOW_COPY(ContactList);
};


/**
 * Interface that can be registered with a Commo instance to 
 * be notified in changes to the available Contacts
 */
class COMMONCOMMO_API ContactPresenceListener
{
public:
    ContactPresenceListener() {};

    /**
     * Invoked when a contact is seen on the network.
     * If the contact later becomes known to be unreachable
     * a contactRemoved notification for the same UID will be sent.
     * This could be invoked for an entirely new Contact, or for one
     * that was removed due to a network failure or other event, and
     * then subsequently reappeared.
     * 
     * @param c the ContactUID for the newly relevant contact; 
     *          the UID object referenced is valid only for the
     *          duration of the call
     */
    virtual void contactAdded(const ContactUID *c) = 0;

    /**
     * Invoked when a contact is no longer relevant. This could be
     * because the network or server connection by which the contact
     * was known is no longer available or some other reason.
     * Contacts may once again become relevant and passed to contactAdded
     * if they reappear on the network.
     *  
     * @param c the ContactUID for the contact that is no longer accessible;
     *          the UID object referenced is valid only for the duration of
     *          the call
     */
    virtual void contactRemoved(const ContactUID *c) = 0;

protected:
    virtual ~ContactPresenceListener() {};

private:
    COMMO_DISALLOW_COPY(ContactPresenceListener);
};

}
}


#endif /* CONTACT_H_ */
