// Required Includes
#include "Game_Subsystem_Help.h"
#include "Game.h"

// Engine Includes
#include "Http.h"
#include "Misc/FileHelper.h"
#include "Async/Async.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "Misc/Paths.h"

// VH Plugin Includes
#include "UI_Subsystem_Core.h"
#include "Developer_Statics.h"

// Game Includes
#include "Game_VideoPlayer_VLC.h"
#include "Game_Statics.h"
#include "Game_HelpVideo.h"
#include "Game_Subsystem_Help_Settings.h"

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_Subsystem_Help* UGame_Subsystem_Help::Get()
{
	if (UWorld* world = UDeveloper_Statics::GetVHWorld())
	{
		return world->GetSubsystem<UGame_Subsystem_Help>();
	}

	return nullptr;
}

// --------------------
// --- Inherited
// --------------------

void UGame_Subsystem_Help::Initialize(FSubsystemCollectionBase& collection)
{
	Super::Initialize(collection);

	if (const UGame_Subsystem_Help_Settings* settings = GetDefault<UGame_Subsystem_Help_Settings>())
	{
		ApplySettings(settings);
	}

	DeviceCodeExpiry = FDateTime::MinValue();
	AccessTokenExpiry = FDateTime::MinValue();

	bHasDeviceCodes = false;
	bHasAccessToken = false;
	bHasRefreshToken = false;
	bHasVideoPlaylist = false;

	if (FPaths::FileExists(FPaths::Combine(UGame_Statics::GetVTAKCommonAppDataPath(), TEXT("HelpVideos")) + TEXT("/key.vh")))
	{
		if (LoadRefreshToken(RefreshToken))
		{
			bHasRefreshToken = true;
		}
	}

	VideoPlayer = NewObject<UGame_VideoPlayer_VLC>();
}

// --------------------
// --- API
// --------------------

void UGame_Subsystem_Help::GetVideoURL(UGame_HelpVideo* helpVideo, FCallbackString callback)
{
	auto executeCallback = [this, helpVideo, callback]()
	{
		AsyncTask(ENamedThreads::GameThread, [this, callback, helpVideo]()
		{
			callback.ExecuteIfBound(helpVideo->RemoteFileLocation);
		});
	};

	auto afterPlaylist = [this, helpVideo, callback, executeCallback]()
	{
		if (HasVideoUri(helpVideo->LocalFileLocation))
		{
			executeCallback();
		}
		else
		{
			FCallbackBoolean uriCallback;
			uriCallback.BindLambda([this, executeCallback](bool bURISuccess)
			{
				if (bURISuccess)
				{
					executeCallback();
				}
			});

			GetVideoUri(uriCallback, helpVideo);
		}
	};

	auto afterAuthentication = [this, helpVideo, callback, afterPlaylist]()
	{
		if (bHasVideoPlaylist)
		{
			afterPlaylist();
		}
		else
		{
			FCallbackBoolean playlistCallback;
			playlistCallback.BindLambda([this, afterPlaylist](bool bPlaylistSuccess)
			{
				if (bPlaylistSuccess)
				{
					afterPlaylist();
				}
			});

			GetVideoPlaylist(playlistCallback, false);
		}
	};

	FString fullPathToFile = FString::Printf(TEXT("%s/HelpVideos/%s"), *UGame_Statics::GetVTAKCommonAppDataPath(), *helpVideo->LocalFileLocation);

	if (FPaths::FileExists(fullPathToFile))
	{
		callback.ExecuteIfBound(FString::Printf(TEXT("file:///%s"), *fullPathToFile));
	}
	else
	{
		// download from tak.gov
		bool bCanRefresh = false;
		if (IsAuthenticated(bCanRefresh))
		{
			afterAuthentication();
		}
		else
		{
			if (bCanRefresh)
			{
				FCallbackBoolean refreshCallback;
				refreshCallback.BindLambda([this, afterAuthentication](bool bRefreshSuccess)
				{
					if (bRefreshSuccess)
					{
						afterAuthentication();
					}
				});

				RefreshAuthentication(refreshCallback);
			}
			else
			{
				if (bHasDeviceCodes)
				{
					if (RequestAccessTokens())
					{
						afterAuthentication();
					}
				}
				else
				{
					FCallbackBoolean authenticateCallback;
					authenticateCallback.BindLambda([this](bool bSuccess)
					{
						if (bSuccess)
						{
							FPlatformProcess::LaunchURL(*GetVerificationUriComplete(), nullptr, nullptr);
						}
					});

					AuthenticateDevice(authenticateCallback, true);
				}
			}
		}
	}
}

TArray<UGame_HelpVideo*> UGame_Subsystem_Help::GetHelpVideos() const
{
	return HelpVideos;
}

// --------------------
// --- Implementation
// --------------------

void UGame_Subsystem_Help::ApplySettings(const UGame_Subsystem_Help_Settings* settings)
{
	for (TSubclassOf<UGame_HelpVideo> baseHelpVideo : settings->CoreHelpVideos)
	{
		if (baseHelpVideo != nullptr)
		{
			UGame_HelpVideo* newHelpVideo = NewObject<UGame_HelpVideo>(this, baseHelpVideo);

			HelpVideos.Add(newHelpVideo);
		}
	}
}

FString UGame_Subsystem_Help::RunCurlCommand(const FString& command)
{
	FString program = FPaths::Combine(FPaths::RootDir(), TEXT("Tools/Curl/bin/curl.exe"));
	FString params = command;

	void* readPipe = nullptr;
	void* writePipe = nullptr;
	FPlatformProcess::CreatePipe(readPipe, writePipe);

	FProcHandle processHandle = FPlatformProcess::CreateProc(*program, *params, true, false, false, nullptr, 0, nullptr, writePipe, readPipe);

	FString result;

	if (processHandle.IsValid())
	{
		while (FPlatformProcess::IsProcRunning(processHandle))
		{
			FPlatformProcess::Sleep(0.01);

			result += FPlatformProcess::ReadPipe(readPipe);
		}

		FPlatformProcess::ClosePipe(writePipe, readPipe);
	}

	FPlatformProcess::CloseProc(processHandle);

	return result;
}

void UGame_Subsystem_Help::ProcessDeviceCodeResponse(TSharedPtr<FJsonObject> jsonObject)
{
	DeviceCode = jsonObject->GetStringField(TEXT("device_code"));
	UserCode = jsonObject->GetStringField(TEXT("user_code"));
	VerificationUri = jsonObject->GetStringField(TEXT("verification_uri"));
	VerificationUriComplete = jsonObject->GetStringField(TEXT("verification_uri_complete"));
	int expirySeconds = jsonObject->GetIntegerField(TEXT("expires_in"));
	DeviceCodeExpiry = FDateTime::UtcNow() + FTimespan::FromSeconds(expirySeconds);

	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessDeviceCodeResponse device_code: %s"), *DeviceCode);
	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessDeviceCodeResponse user_code: %s"), *UserCode);
	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessDeviceCodeResponse verification_uri: %s"), *VerificationUri);
	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessDeviceCodeResponse verification_uri_complete: %s"), *VerificationUriComplete);
	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessDeviceCodeResponse expires at: %s"), *DeviceCodeExpiry.ToString(TEXT("%H:%M:%S")));
}

void UGame_Subsystem_Help::ProcessAccessTokenResponse(TSharedPtr<FJsonObject> jsonObject)
{
	AccessToken = jsonObject->GetStringField(TEXT("access_token"));
	RefreshToken = jsonObject->GetStringField(TEXT("refresh_token"));
	int32 expirySeconds = jsonObject->GetIntegerField(TEXT("expires_in"));
	AccessTokenExpiry = FDateTime::UtcNow() + FTimespan::FromSeconds(expirySeconds);

	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessAccessTokenResponse access_token: %s"), *AccessToken);
	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessAccessTokenResponse refresh_token: %s"), *RefreshToken);
	UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessAccessTokenResponse expires at: %s"), *AccessTokenExpiry.ToString(TEXT("%H:%M:%S")));

	SaveRefreshToken(RefreshToken);
}

bool UGame_Subsystem_Help::ProcessVideoPlaylistResponse(TSharedPtr<FJsonObject> jsonObject)
{
	TArray<TSharedPtr<FJsonValue>> videoArray = jsonObject->GetArrayField(TEXT("videos"));

	for (TSharedPtr<FJsonValue>& property : videoArray)
	{
		TSharedPtr<FJsonObject> propertyObject = property->AsObject();

		FString uuid = propertyObject->GetStringField(TEXT("uuid"));
		FString name = propertyObject->GetStringField(TEXT("name"));

		TSharedPtr<FJsonObject> file = propertyObject->GetObjectField(TEXT("file"));
		FString apiSrc = file->GetStringField(TEXT("src"));
		FString fileName;

		int32 lastSlashIndex;
		if (apiSrc.FindLastChar('/', lastSlashIndex))
		{
			fileName = apiSrc.RightChop(lastSlashIndex + 1);
		}

		VideoApiDataMap.Add(fileName, VideoApiData(uuid, name, fileName, apiSrc));

		UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessVideoPlaylistResponse video uuid: %s"), *uuid);
		UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessVideoPlaylistResponse video name: %s"), *name);
		UE_LOG(Game, Verbose, TEXT("Game_Subsystem_Help::ProcessVideoPlaylistResponse video src: %s"), *apiSrc);
	}

	return !VideoApiDataMap.IsEmpty();
}

FString UGame_Subsystem_Help::ProcessVideoUriResponse(const FString& response)
{
	TArray<FString> headerLines;
	response.ParseIntoArrayLines(headerLines);
	FString key = TEXT("location: ");
	FString value;

	for (FString& line : headerLines)
	{
		if (line.StartsWith(key))
		{
			value = line.Mid(key.Len()).TrimStartAndEnd();
		}
	}

	return value;
}

bool UGame_Subsystem_Help::RequestVideoUri(const VideoApiData& data)
{
	// The video location is stored neatly in the headers, so use -I to only receive the header data
	FString command = TEXT("-s -I -X GET ") + data.ApiSrc + TEXT(" -H \"Authorization: Bearer ") + AccessToken + TEXT("\"");
	FString result = RunCurlCommand(command);

	FString videoDownloadSrc = ProcessVideoUriResponse(result);
	if (!videoDownloadSrc.IsEmpty())
	{
		VideoApiDataMap[data.FileName].DownloadSrc = videoDownloadSrc;
		return true;
	}

	return false;
}

bool UGame_Subsystem_Help::SaveRefreshToken(const FString& tokenString)
{
	FString filePath = FPaths::Combine(UGame_Statics::GetVTAKCommonAppDataPath(), TEXT("HelpVideos")) + TEXT("/key.vh");
	return !tokenString.IsEmpty() && FFileHelper::SaveStringToFile(*tokenString, *filePath);
}

bool UGame_Subsystem_Help::LoadRefreshToken(FString& OutRefreshToken)
{
	FString filePath = FPaths::Combine(UGame_Statics::GetVTAKCommonAppDataPath(), TEXT("HelpVideos")) + TEXT("/key.vh");
	if (!FFileHelper::LoadFileToString(OutRefreshToken, *filePath))
	{
		UE_LOG(Game, Error, TEXT("UGame_Subsystem_Help::LoadRefreshToken - failed to load refresh token"));
		return false;
	}
	return true;
}

bool UGame_Subsystem_Help::CanRefreshToken()
{
	return bHasRefreshToken && (!bHasAccessToken || IsAccessTokenExpired());
}

bool UGame_Subsystem_Help::IsAuthenticated(bool& outCanRefresh)
{
	// If a refresh token was loaded from disk, notify the calling function
	if (!bHasAccessToken && CanRefreshToken())
	{
		outCanRefresh = true;
	}

	return bHasAccessToken && !IsAccessTokenExpired();
}

bool UGame_Subsystem_Help::IsDeviceCodeExpired()
{
	return FDateTime::UtcNow() > DeviceCodeExpiry;
}

bool UGame_Subsystem_Help::IsAccessTokenExpired()
{
	return FDateTime::UtcNow() > AccessTokenExpiry;
}

void UGame_Subsystem_Help::AuthenticateDevice(FCallbackBoolean callback, bool bForce)
{
	AsyncTask(ENamedThreads::AnyThread, [this, callback, bForce]()
	{
		bool result = true;
		if (bForce || (!bHasDeviceCodes && !bHasRefreshToken) || (IsDeviceCodeExpired() && !bHasAccessToken && !bHasRefreshToken))
		{
			result = RequestDeviceCodes();
		}

		AsyncTask(ENamedThreads::GameThread, [this, callback, result]()
		{
			callback.ExecuteIfBound(result);
		});
	});
}

void UGame_Subsystem_Help::RefreshAuthentication(FCallbackBoolean callback)
{
	AsyncTask(ENamedThreads::AnyThread, [this, callback]()
	{
		bool result = true;
		if (CanRefreshToken())
		{
			result = RequestAccessTokenRefresh();
		}

		AsyncTask(ENamedThreads::GameThread, [this, callback, result]()
		{
			callback.ExecuteIfBound(result);
		});
	});
}

bool UGame_Subsystem_Help::RequestDeviceCodes()
{
	bHasDeviceCodes = false;

	FString command = TEXT("-s -X POST https://auth.tak.gov/auth/realms/TPC/protocol/openid-connect/auth/device -H \"Content-Type: application/x-www-form-urlencoded\" -d \"client_id=tak-gov-eud\" -d \"scope=openid offline_access email profile\"");
	FString result = RunCurlCommand(command);

	TSharedPtr<FJsonObject> jsonObject;
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(result);

	if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
	{
		ProcessDeviceCodeResponse(jsonObject);
		bHasDeviceCodes = true;
	}

	return bHasDeviceCodes;
}

bool UGame_Subsystem_Help::RequestAccessTokens()
{
	bHasAccessToken = false;

	FString command = TEXT("-s -X POST https://auth.tak.gov/auth/realms/TPC/protocol/openid-connect/token -H \"Content-Type: application/x-www-form-urlencoded\" -d \"client_id=tak-gov-eud\" -d \"grant_type=urn:ietf:params:oauth:grant-type:device_code\" -d \"device_code=") + DeviceCode + TEXT("\"");
	FString result = RunCurlCommand(command);

	TSharedPtr<FJsonObject> jsonObject;
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(result);

	if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
	{
		ProcessAccessTokenResponse(jsonObject);
		bHasAccessToken = true;
	}
	return bHasAccessToken;
}

bool UGame_Subsystem_Help::RequestAccessTokenRefresh()
{
	bHasAccessToken = false;
	FString command = TEXT("-s -X POST https://auth.tak.gov/auth/realms/TPC/protocol/openid-connect/token -H \"Content-Type: application/x-www-form-urlencoded\" -d \"client_id=tak-gov-eud\" -d \"grant_type=refresh_token\" -d \"refresh_token=") + RefreshToken + TEXT("\"");
	FString result = RunCurlCommand(command);

	TSharedPtr<FJsonObject> jsonObject;
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(result);

	if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
	{
		ProcessAccessTokenResponse(jsonObject);
		bHasAccessToken = true;
	}
	return bHasAccessToken;
}

bool UGame_Subsystem_Help::HasVideoUri(const FString& videoName) const
{
	if (VideoApiDataMap.Contains(videoName))
	{
		return !VideoApiDataMap[videoName].DownloadSrc.IsEmpty();
	}

	return false;
}

void UGame_Subsystem_Help::GetVideoPlaylist(FCallbackBoolean callback, bool bForceRefresh)
{
	AsyncTask(ENamedThreads::AnyThread, [this, callback, bForceRefresh]()
	{
		if (!bHasVideoPlaylist || bForceRefresh)
		{
			// Request the video playlist from the server, populating the VideoApiDataMap
			bHasVideoPlaylist = false;
			if (RequestVideoPlaylist())
			{
				UE_LOG(Game, Verbose, TEXT("UGame_Subsystem_Help::GetVideoPlaylist received %d videos"), VideoApiDataMap.Num());
			}
			else
			{
				UE_LOG(Game, Error, TEXT("UGame_Subsystem_Help::GetVideoPlaylist no videos received from tak.gov api"));
			}
		}

		AsyncTask(ENamedThreads::GameThread, [this, callback]()
		{
			callback.ExecuteIfBound(bHasVideoPlaylist);
		});
	});
}

void UGame_Subsystem_Help::GetVideoUri(FCallbackBoolean callback, UGame_HelpVideo* helpVideo)
{
	AsyncTask(ENamedThreads::AnyThread, [this, callback, helpVideo]()
	{
		bool bSuccess = false;

		if (VideoApiData* dataPtr = VideoApiDataMap.Find(helpVideo->LocalFileLocation))
		{
			bSuccess = RequestVideoUri(*dataPtr);
			if (bSuccess)
			{
				helpVideo->RemoteFileLocation = dataPtr->DownloadSrc;
			}
		}

		AsyncTask(ENamedThreads::GameThread, [this, callback, bSuccess]()
		{
			callback.ExecuteIfBound(bSuccess);
		});
	});
}

bool UGame_Subsystem_Help::RequestVideoPlaylist()
{
	VideoApiDataMap.Empty();

	FString command = TEXT("-s -X GET https://tak.gov/eud_api/media/v1/video_playlists/vr-tak-user-guides -H \"Authorization: Bearer ") + AccessToken + TEXT("\"");
	FString result = RunCurlCommand(command);

	TSharedPtr<FJsonObject> jsonObject;
	TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(result);

	if (FJsonSerializer::Deserialize(jsonReader, jsonObject))
	{
		bHasVideoPlaylist = ProcessVideoPlaylistResponse(jsonObject);
	}

	return bHasVideoPlaylist;
}

void UGame_Subsystem_Help::RegisterPluginVideo(UGame_HelpVideo* newPluginVideo)
{
	HelpVideos.Add(newPluginVideo);
}

FString UGame_Subsystem_Help::GetVerificationUriComplete()
{
	return VerificationUriComplete;
}

FString UGame_Subsystem_Help::GetUserCode()
{
	return UserCode;
}