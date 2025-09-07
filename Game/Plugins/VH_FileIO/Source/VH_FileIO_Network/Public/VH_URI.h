// Developed by Virtual Heroes, 2019-2020

#pragma once

// Generated includes
#include "VH_URI.generated.h"

// ---------------------------------
// --- Enumerator
// ---------------------------------

UENUM(BlueprintType)
enum class ESchemeTypeEnum : uint8
{
	EST_UNKNOWN,
	EST_UDP,
	EST_RTSP,
	EST_HTTP,
	EST_HTTPS,
	EST_TCP,
	EST_RTMP,
	EST_RTMPS,
	EST_RTP,
	EST_SRT,
	EST_FTP,
	EST_FILE,
	EST_DIRECTORY,
	EST_RAW
};

/**
 * This class is designed to take a URI (which is pretty much a URL) and turn it into manangable segments
 */
UCLASS(Blueprintable, BlueprintType)
class VH_FILEIO_NETWORK_API UVH_URI : public UObject
{
	GENERATED_BODY()

	// ---------------------------------
	// --- Member
	// ---------------------------------

protected:

	FString AbsolutePath;

	FString Filename;

	FString Fragment;

	FString Host;

	FString OriginalURI;

	FString Path;

	FString Query;

	ESchemeTypeEnum Scheme;

	int16 Port;

	TMap<FString, FString> QueryFieldValues;

	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:

	UVH_URI();

	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:

	static ESchemeTypeEnum GetProtocolFromString(const FString& protocol);

	static FString GetStringFromProtocol(const ESchemeTypeEnum& protocol);

	// ---------------------------------
	// --- Public Methods
	// ---------------------------------

public:

	void SetFromString(FString url);

	FString GetAbsolutePath() const;

	FString GetFilename() const;

	FString GetFragment() const;

	FString GetHost() const;

	FString GetOriginalURI() const;

	FString GetPath() const;

	int16 GetPort() const;

	FString GetQuery() const;

	ESchemeTypeEnum GetScheme() const;

	bool SetAbsolutePath(FString absolutePath);

	bool SetFilename(FString filename);

	bool SetFragment(FString fragment);

	bool SetHost(FString host);

	bool SetPath(FString path);

	bool SetPort(int16 port);

	bool SetQuery(FString query);

	bool SetScheme(ESchemeTypeEnum scheme);

	bool IsAbsolutePathNull() const;

	bool IsFilenameNull() const;

	bool IsFragmentNull() const;

	bool IsHostNull() const;

	bool IsOriginalURINull() const;

	bool IsPathNull() const;

	bool IsPortNull() const;

	bool IsQueryNull() const;

};
