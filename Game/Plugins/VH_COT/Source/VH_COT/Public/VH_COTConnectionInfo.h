#pragma once

#include "VH_COT.h"
#include "HAL/ThreadSafeCounter.h"
#include "Runtime/Online/HTTP/Public/Http.h"

#include "VH_COTConnectionInfo.generated.h"

namespace atakmap
{
    namespace commoncommo
    {
		class Commo;
		class StreamingNetInterface;
        class NetInterface;
    }
}  // namespace atakmap

class FXmlNode;
class UVH_COTConnectionInfo;

// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class ECOTConnectionType : uint8
{
    ECT_Broadcast,
    ECT_Inbound,
    ECT_Stream
};

UENUM(BlueprintType)
enum class ECOTMessageTypes : uint8
{
    ECMT_SituationalAwareness,
    ECMT_Chat
};

UENUM(BlueprintType)
enum class EConnectionProtocolTypes : uint8
{
	E_SSL,
	E_TCP,
	E_QUIC
};

UCLASS(Blueprintable, BlueprintType)
class VH_COT_API UVH_COTConnectionInfo : public UObject
{
    GENERATED_BODY()

	// ---------------------------------
	// --- Constructors
	// ---------------------------------
public:
	UVH_COTConnectionInfo();

	// ---------------------------------
	// --- Delegates
	// ---------------------------------
private:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedConnectionError, UVH_COTConnectionInfo*, connectionInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FReceivedConnectionStatusUpdate, UVH_COTConnectionInfo*, connectionInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FConnectionUpdated, UVH_COTConnectionInfo*, connectionInfo);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConnectionDeleted);

	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	UPROPERTY(BlueprintAssignable)
	FReceivedConnectionError OnReceivedConnectionError;

	UPROPERTY(BlueprintAssignable)
	FReceivedConnectionStatusUpdate OnReceivedConnectionStatusUpdate;

	UPROPERTY(BlueprintAssignable)
	FConnectionUpdated OnConnectionUpdated;

	UPROPERTY(BlueprintAssignable)
	FConnectionDeleted OnConnectionDeleted;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bConnectAtInitialization;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    bool bConnected;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString ConnectionError;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    ECOTConnectionType ConnectionType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EConnectionProtocolTypes ConnectionProtocol;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString DisplayName;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString Host;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    TArray<ECOTMessageTypes> MessageTypes;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    FString MulticastAddress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere)
    int32 Port;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Username;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString Password;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bEnrollForCert;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bQUIC;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString CertificateAuthorityName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CertificateAuthorityPassword;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FString ClientCertificateName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ClientCertificatePassword;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString CertificateAuthorityPath;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ClientCertificatePath;

	atakmap::commoncommo::NetInterface* Interface;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString RootDirectory;

private:
	FThreadSafeCounter DestroyCounter;

	// true if connection is in progress
	FThreadSafeBool bConnecting;

	// true if disconnection is in progress
	FThreadSafeBool bDisconnecting;

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------
public:
	static UVH_COTConnectionInfo* CreateNewConnectionInfo(const FString& rootDirectory);

	// ---------------------------------
	// --- Inherited
	// ---------------------------------
public:
	bool IsReadyForFinishDestroy() override;

	// ---------------------------------
	// --- API
	// ---------------------------------
public:
	/* Copies this object and returns a pointer to the newly constructed object.
	 *
	 * @return UVH_COTConnectionInfo pointer to new object.
	 */
	UFUNCTION(BlueprintPure)
	UVH_COTConnectionInfo* Copy() const;

	UFUNCTION(BlueprintPure)
	FString GetCommoEndpoint() const;

	UFUNCTION(BlueprintCallable)
	void HandleLDAPCredentials(const FString& ldapUsername, const FString& ldapPassword);

	/* disconnect connection in connectionInfo; bSynchronous false means queue on separate thread */
	UFUNCTION(BlueprintCallable)
	void Disconnect(bool bSynchronous = false);

	/* create connection from info in connectionInfo; bSynchronous false means queue on separate thread */
	UFUNCTION(BlueprintCallable)
	void CreateConnection(bool bSynchronous = false);

	bool IsDisconnected() const;

	void PopulateFromXML(FXmlNode* rootNode);

	FString ToXML() const;

	void WriteXMLToFile(const FString& fullPathOnDisk) const;

	// ---------------------------------
	// --- Implementation
	// ---------------------------------
private:
	bool IsSafeToExecute();

	void HandleLDAPSignClientResponse(const FString& fullPathToP12, const FString& privateKey, const FString& keystorePassword);

	void HandleLDAPConfigResponse(const FString& originalXML);

	void CreateConnection_Stream();

	atakmap::commoncommo::Commo* GetCommo() const;

	FString GetAuthorizationHeaderValue() const;

	void CreatePEMs() const;
};