// Required Includes
#include "Game_PresentationMode_ReplicatedWindowComponent.h"
#include "Game.h"

// Engine Includes
#include "Engine/Texture2D.h"
#include "IImageWrapperModule.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Net/UnrealNetwork.h"
#include "Rendering/Texture2DResource.h"
#include "TimerManager.h"
#include "Async/Async.h"
#include "RenderingThread.h"

#if WITH_OPENCV
#include "OpenCVHelper.h"
#include "PreOpenCVHeaders.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include "PostOpenCVHeaders.h"
#endif

// VH Plugin Includes
#include "Developer_Statics.h"
#include "Replication_DataChannel.h"
#include "Replication_Subsystem_Core.h"

// Game Includes
#include "Game_GameState.h"
#include "Game_Statics.h"
#include "Game_PlayerState.h"
#include "Game_CameraComponent.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_PresentationMode_ReplicatedWindowComponent::UGame_PresentationMode_ReplicatedWindowComponent(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	SetIsReplicatedByDefault(true);
}

// ---------------------------------
// --- Replication
// ---------------------------------

void UGame_PresentationMode_ReplicatedWindowComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UGame_PresentationMode_ReplicatedWindowComponent, ReplicationID);
}

void UGame_PresentationMode_ReplicatedWindowComponent::BeginPlay()
{
	Super::BeginPlay();

	LastCapturedPixelsCriticalSection = new FCriticalSection();

	ENetMode netMode = GetWorld()->GetNetMode();

	switch (netMode)
	{
		case NM_Client:
		case NM_Standalone:
		{
			Texture = UTexture2D::CreateTransient(1024, 1024, PF_B8G8R8A8);
			Texture->SRGB = 0;
			Texture->UpdateResource();
		}
		break;

		case NM_ListenServer:
		{
			Texture = UTexture2D::CreateTransient(1024, 1024, PF_B8G8R8A8);
			Texture->SRGB = 0;
			Texture->UpdateResource();

			CreateDataChannels();
		}
		break;

		case NM_DedicatedServer:
		{
			CreateDataChannels();
		}
		break;
	}

	if (Texture != nullptr)
	{
		// default to white
		TArray<uint8> pixelData;
		pixelData.AddZeroed(1024 * 1024 * sizeof(FColor));
		
		FMemory::Memset(pixelData.GetData(), 255, pixelData.Num());
		
		UpdateTexture(pixelData);
	}

	if (netMode != NM_Standalone)
	{
		if (UReplication_Subsystem_Core* subsystem = UReplication_Subsystem_Core::Get(GetWorld()))
		{
			subsystem->OnDataReceived.AddUObject(this, &UGame_PresentationMode_ReplicatedWindowComponent::HandleDataReceived);
		}
	}

	if (Cast<APawn>(GetOwner())->IsLocallyControlled())
	{
		FTimerHandle captureTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(captureTimerHandle, this, &UGame_PresentationMode_ReplicatedWindowComponent::PeriodicCapturePixels, 0.05, true);
	
		FTimerHandle sendTimerHandle;
		GetWorld()->GetTimerManager().SetTimer(sendTimerHandle, this, &UGame_PresentationMode_ReplicatedWindowComponent::PeriodicSendPixels, 0.05, true);
	}
}

void UGame_PresentationMode_ReplicatedWindowComponent::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);

	delete LastCapturedPixelsCriticalSection;
	LastCapturedPixelsCriticalSection = nullptr;

	if (GetWorld()->GetNetMode() != NM_Standalone)
	{
		if (UReplication_Subsystem_Core* subsystem = UReplication_Subsystem_Core::Get(GetWorld()))
		{
			subsystem->OnDataReceived.RemoveAll(this);
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

UTexture2D* UGame_PresentationMode_ReplicatedWindowComponent::GetTexture() const
{
	return Texture;
}

// ---------------------------------
// --- Implementation
// ---------------------------------

void UGame_PresentationMode_ReplicatedWindowComponent::UpdateTexture(const TArray<uint8>& pixelData)
{
	UDeveloper_Statics::UpdateTexture2DPixels(Texture, 0, pixelData);
}

void UGame_PresentationMode_ReplicatedWindowComponent::CreateDataChannels()
{
	if (UReplication_Subsystem_Core* subsystem = UReplication_Subsystem_Core::Get(GetWorld()))
	{
		ReplicationID = FGuid::NewGuid().ToString();

		subsystem->AddChannels(ReplicationID, 0);
	}
}

bool UGame_PresentationMode_ReplicatedWindowComponent::IsClientReadyToSend() const
{
	bool bPresenting = false;
	if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
	{
		if (gameState->GetPresentingPlayerState() == nullptr)
		{
			return false;
		}
		
		if (gameState->GetPresentingPlayerState() == UGame_Statics::GetVHPlayerPawn()->GetPlayerState())
		{
			bPresenting = true;
		}
	}

	if (bPresenting && bPixelsDirty && LastCapturedPixels.Num() > 0 && !ReplicationID.IsEmpty())
	{
		if (UReplication_Subsystem_Core* subsystem = UReplication_Subsystem_Core::Get(GetWorld()))
		{
			if (subsystem->GetChannels(ReplicationID).Num() > 0 && !subsystem->IsSending(ReplicationID))
			{
				return true;
			}
		}
	}

	if (ReplicationID.IsEmpty())
	{
		UE_LOG(Game, Warning, TEXT("-- UGame_PresentationMode_ReplicatedWindowComponent::IsClientReadyToSend | ReplicationID is empty, be sure that the component's owning actor is set to replicate"));
	}

	return false;
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void UGame_PresentationMode_ReplicatedWindowComponent::HandleDataReceived(const TArray<uint8>& data, UReplication_DataChannel* channel)
{
	if (channel->GetOwnerID().Equals(ReplicationID))
	{
		ENetMode netMode = GetWorld()->GetNetMode();

		bool bPresenter = false;
		if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
		{
			bPresenter = gameState->GetPresentingPlayerState() == UGame_Statics::GetVHPlayerPawn()->GetPlayerState();
		}

		// presenter updates local texture in PeriodicSendPixels
		if (!bPresenter)
		{
			if (netMode == NM_Client || netMode == NM_ListenServer)
			{
				Async(EAsyncExecution::ThreadPool, [this, data]()
				{
					IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));

					auto imageWrapper = imageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
					if (imageWrapper->SetCompressed(data.GetData(), data.Num()))
					{
						TArray<uint8> decodedPixels;
						if (imageWrapper->GetRaw(ERGBFormat::BGRA, 8, decodedPixels))
						{
							AsyncTask(ENamedThreads::GameThread, [this, decodedPixels]()
							{
								UpdateTexture(decodedPixels);
							});
						}
					}
				});
			}
		}

		if (netMode == NM_ListenServer || netMode == NM_DedicatedServer)
		{
			if (UReplication_Subsystem_Core* subsystem = UReplication_Subsystem_Core::Get(GetWorld()))
			{
				subsystem->SendData(ReplicationID, data);
			}
		}
	}
}

void UGame_PresentationMode_ReplicatedWindowComponent::PeriodicCapturePixels()
{
	if (RenderTarget2D != nullptr)
	{
		bool bCapture = false;
		if (AGame_GameState* gameState = UGame_Statics::GetVHGameState())
		{
			if (gameState->GetPresentingPlayerState() == UGame_Statics::GetVHPlayerPawn()->GetPlayerState())
			{
				bCapture = true;
			}
		}

		if (bCapture)
		{
			FTransform currentCameraTransform = UGame_Statics::GetVHPlayerPawn()->Camera->GetComponentTransform();
			double timeSeconds = GetWorld()->GetTimeSeconds();

			if (!LastCaptureTransform.Equals(currentCameraTransform) || timeSeconds - LastCaptureTime > 1)
			{
				LastCaptureTransform = currentCameraTransform;
				LastCaptureTime = timeSeconds;

				// based on FRenderTarget::ReadPixels	
				ENQUEUE_RENDER_COMMAND(ReadSurfaceCommand)([this](FRHICommandListImmediate& RHICmdList)
				{
					LastCapturedPixelsCriticalSection->Lock();

					LastCapturedPixels.Reset();
					RHICmdList.ReadSurfaceData(
						RenderTarget2D->GetRenderTargetResource()->GetRenderTargetTexture(),
						FIntRect(0, 0, RenderTarget2D->SizeX, RenderTarget2D->SizeY),
						LastCapturedPixels,
						FReadSurfaceDataFlags(RCM_UNorm, CubeFace_MAX)
					);

					for (int32 i = 0; i < LastCapturedPixels.Num(); i++)
					{
						LastCapturedPixels[i].A = 255;
					}

					// update local texture
					FTexture2DResource* textureResource = (FTexture2DResource*)Texture->GetResource();

					uint32 destStride;
					uint64 bytesLocked;
					uint8* lockedMipData = (uint8*)RHILockTexture2D(textureResource->GetTexture2DRHI(), 0, RLM_WriteOnly, destStride, false, false, &bytesLocked);
					if (lockedMipData)
					{
						FMemory::Memcpy(lockedMipData, LastCapturedPixels.GetData(), LastCapturedPixels.Num() * sizeof(FColor));

						RHIUnlockTexture2D(textureResource->GetTexture2DRHI(), 0, false);
					}

					bPixelsDirty = true;

					LastCapturedPixelsCriticalSection->Unlock();
				});
			}
		}
	}
}

void UGame_PresentationMode_ReplicatedWindowComponent::PeriodicSendPixels()
{
	if (IsClientReadyToSend())
	{
		bPixelsDirty = false;
		
		int32 textureWidth = Texture->GetSizeX();
		int32 textureHeight = Texture->GetSizeY();
		
		Async(EAsyncExecution::ThreadPool, [this, textureWidth, textureHeight]()
		{
			TArray<uint8> encodedPixels;

			if (LastCapturedPixelsCriticalSection->TryLock())
			{
				TArray<FColor> pixels;
				pixels.Append(LastCapturedPixels);

				LastCapturedPixelsCriticalSection->Unlock();

				try
				{
					// encode as png
					int32 numPixels = pixels.Num();
					cv::Mat bitmapMat(textureHeight, textureWidth, CV_8UC4, (void*)pixels.GetData());

					std::vector<int> encodeFlags;

					std::vector<unsigned char> encodedBuffer(numPixels);
					if (cv::imencode(".jpg", bitmapMat, encodedBuffer, encodeFlags))
					{
						encodedPixels.Empty();

						// add pixel data
						encodedPixels.Append(&encodedBuffer[0], encodedBuffer.size());
					}

					bitmapMat.release();
					encodedBuffer.clear();
				}
				catch (cv::Exception& e)
				{
					const char* err_msg = e.what();
					UE_LOG(Game, Warning, TEXT("-- convert error | %s"), ANSI_TO_TCHAR(err_msg));
				}
			}
			else
			{
				// could not acquire lock | abort
				return;
			}

			if (UReplication_Subsystem_Core* subsystem = UReplication_Subsystem_Core::Get(GetWorld()))
			{
				subsystem->SendData(ReplicationID, encodedPixels);
			}
		});
	}
}