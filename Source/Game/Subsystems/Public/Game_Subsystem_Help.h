#pragma once

// Parent Includes
#include "Subsystems/WorldSubsystem.h"

// Engine Includes
#include "Dom/JsonObject.h"

// Game Includes
#include "Game_Subsystem_Help.generated.h"

class UGame_HelpVideo;
class UGame_VideoPlayer_VLC;
class UGame_Subsystem_Help_Settings;

/**
 *  Stores and manages references to help videos and help video player
 */
UCLASS()
class GAME_API UGame_Subsystem_Help : public UWorldSubsystem
{
	GENERATED_BODY()


	// -------------------
	// --- Delegates
	// -------------------

public:
	DECLARE_DELEGATE_OneParam(FCallbackString, const FString&);

private:
	DECLARE_DELEGATE_OneParam(FCallbackBoolean, bool);


	// -------------------
	// --- Variables
	// -------------------

public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UGame_VideoPlayer_VLC* VideoPlayer;

private:
	struct VideoApiData
	{
		FString UUID;
		FString Name;
		FString FileName;
		FString ApiSrc;
		FString DownloadSrc;

		VideoApiData(const FString& inUUID, const FString& inName, const FString& inFileName, const FString& inApiSrc) :
			UUID(inUUID), 
			Name(inName),
			FileName(inFileName), 
			ApiSrc(inApiSrc) 
		{

		}
	};

	UPROPERTY()
	TArray<UGame_HelpVideo*> HelpVideos;

	FString DeviceCode;

	FString UserCode;

	FString VerificationUri;

	FString VerificationUriComplete;

	FString AccessToken;

	FString RefreshToken;

	FDateTime DeviceCodeExpiry;
	FDateTime AccessTokenExpiry;

	bool bHasDeviceCodes;
	bool bHasAccessToken;
	bool bHasRefreshToken;
	bool bHasVideoPlaylist;

	// Video file names -> VideoApiData struct
	TMap<FString, VideoApiData> VideoApiDataMap;


	// ---------------------------------
	// --- Static Functions
	// ---------------------------------

public:
	static UGame_Subsystem_Help* Get();


	// --------------------
	// --- Inherited
	// --------------------
	
public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;


	// --------------------
	// --- API
	// --------------------

public:
	// can be web URL or file://
	// callback is on game thread
	void GetVideoURL(UGame_HelpVideo* helpVideo, FCallbackString callback);

	UFUNCTION(BlueprintPure)
	TArray<UGame_HelpVideo*> GetHelpVideos() const;

	
	// --------------------
	// --- Implementation
	// --------------------

private:
	void ApplySettings(const UGame_Subsystem_Help_Settings* settings);

	FString RunCurlCommand(const FString &command);

	void ProcessDeviceCodeResponse(TSharedPtr<FJsonObject> jsonObject);

	void ProcessAccessTokenResponse(TSharedPtr<FJsonObject> jsonObject);

	bool ProcessVideoPlaylistResponse(TSharedPtr<FJsonObject> jsonObject);

	FString ProcessVideoUriResponse(const FString& response);

	// Requests a single video uri using the sources from the response from RequestVideoPlaylist()
	// The resulting uri is hosted on AWS servers, and doesn't require HTTP2 or an access token to download/stream
	bool RequestVideoUri(const VideoApiData& data);

	bool SaveRefreshToken(const FString& token);

	bool LoadRefreshToken(FString& outRefreshToken);

	bool CanRefreshToken();

	bool IsAuthenticated(bool& outCanRefresh);

	bool IsDeviceCodeExpired();

	bool IsAccessTokenExpired();

	////////////////////////////////////
	//  EUD API Authentication
	////////////////////////////////////

	void AuthenticateDevice(FCallbackBoolean callback, bool bForce);

	void RefreshAuthentication(FCallbackBoolean callback);

	// Requests the device and user codes
	bool RequestDeviceCodes();

	bool RequestAccessTokens();

	// Requests a new access token using the refresh token granted in RequestAccessTokens()
	bool RequestAccessTokenRefresh();

	////////////////////////////////////
	//  EUD API Media Requests
	////////////////////////////////////

	bool HasVideoUri(const FString& videoName) const;

	void GetVideoPlaylist(FCallbackBoolean callback, bool bForceRefresh);

	void GetVideoUri(FCallbackBoolean callback, UGame_HelpVideo* helpVideo);

	// Requests the VR-TAK help video playlist from the tak.gov website
	bool RequestVideoPlaylist();

	// Register non-core help videos to the subsystem
	void RegisterPluginVideo(UGame_HelpVideo* newPluginVideo);
	
	FString GetVerificationUriComplete();

	FString GetUserCode();
};
