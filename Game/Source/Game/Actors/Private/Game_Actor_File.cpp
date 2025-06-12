// Required Includes
#include "Game_Actor_File.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_FileIOTypes.h"
#include "VH_GeodeticCoord.h"
#include "VH_MeshInfo.h"
#include "TimerManager.h"
#include "Engine/World.h"

// Game Includes
#include "Game_AdjustableModelImportComponent.h"
#include "Game_ImportedMeshComponent.h"
#include "Game_PlayerController.h"
#include "Game_VirtualObjectiveManager.h"
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_Pawn.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

AGame_Actor_File::AGame_Actor_File(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{
	ImportedMesh = CreateDefaultSubobject<UGame_ImportedMeshComponent>(TEXT("ImportedMesh"));
	SetRootComponent(ImportedMesh);

	AdjustableModelImportComponent = CreateDefaultSubobject<UGame_AdjustableModelImportComponent>(TEXT("AdjustableModelImportComponent"));
	AdjustableModelImportComponent->SetupAttachment(RootComponent);
}

void AGame_Actor_File::BeginPlay()
{
	Super::BeginPlay();

	ImportedMesh->OnImportedMeshInfo.AddUObject(this, &AGame_Actor_File::HandleImportedMeshInfo);

	FTimerHandle timerHandle;
	GetWorldTimerManager().SetTimer(timerHandle, this, &AGame_Actor_File::PeriodicCheckLOD, 1, true);
}

void AGame_Actor_File::EndPlay(const EEndPlayReason::Type endPlayReason)
{
	Super::EndPlay(endPlayReason);
	
	if (IsValid(LowLODActor))
	{
		LowLODActor->Destroy();
		LowLODActor = nullptr;
	}
}

// ---------------------------------
// --- API
// ---------------------------------

void AGame_Actor_File::LoadFromFile(const FString& fullPathToFile, const FVH_MeshImportOptions& importOptions)
{
	ImportedMesh->ImportOptions = importOptions;

	ImportedMesh->LoadFromFile(fullPathToFile);
}

void AGame_Actor_File::SetMaterialOverride(UMaterialInstance* materialOverride)
{
	ImportedMesh->MaterialOverride = materialOverride;
}

AVH_GlobeReferenceActor* AGame_Actor_File::GetGlobeReference() const
{
	if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
	{
		return virtualObjective->GetGlobeReference();
	}

	return nullptr;
}

bool AGame_Actor_File::GetModelLocationWithoutTag(FGeodeticCoord3D& coordinate)
{
	return UGame_AdjustableModelImportComponent::GetUnloadedEntityGeoLocation(ImportedMesh->FullPathToFile, coordinate);
}

// ---------------------------------
// --- Event Handlers
// ---------------------------------

void AGame_Actor_File::HandleImportedMeshInfo(UGame_ImportedMeshComponent* importedMeshComponent, UVH_MeshInfo* meshInfo)
{
	AdjustableModelImportComponent->ApplySettings(GetGlobeReference());
}

void AGame_Actor_File::PeriodicCheckLOD()
{
	// 0 don't load; 1 load low LOD; 2 load normal LOD
	int32 loadType = 0;

	if (LowLODActorClass != nullptr && !UGame_Statics::IsLocalPlayerInTOC())
	{
		if (AGame_VirtualObjective* virtualObjective = UGame_VirtualObjectiveManager::GetObjectVO(this))
		{
			if (AGame_Pawn* playerPawn = UGame_Statics::GetVHPlayerPawn())
			{
				double distanceMeters = FVector::Distance(playerPawn->GetActorLocation(), GetActorLocation()) / virtualObjective->GetUnrealUnitsPerMeter();

				loadType = distanceMeters > virtualObjective->GetViewDistance() ? 1 : 2;
			}
		}
	}
	else
	{
		loadType = 2;
	}
		
	if (loadType == 1)
	{
		// load low LOD
		if (!IsValid(LowLODActor))
		{
			// destroy mesh
			ImportedMesh->DestroyGeneratedMesh();

			// spawn low LOD actor (hide if no LOD'd geometry)
			FActorSpawnParameters spawnParameters;
			spawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			FTransform transform;
			transform.SetLocation(GetActorLocation());

			LowLODActor = GetWorld()->SpawnActor(LowLODActorClass, &transform, spawnParameters);

			bLoadedOnce = true;
		}
	}
	else if (loadType == 2)
	{
		// load normal LOD
		bool bValidLowLODActor = IsValid(LowLODActor);
		if (bValidLowLODActor || !bLoadedOnce)
		{
			if (!ImportedMesh->HasCurrentOrPendingMesh())
			{
				if (bValidLowLODActor)
				{
					LowLODActor->Destroy();
					LowLODActor = nullptr;
				}
				
				ImportedMesh->LoadFromFile(ImportedMesh->FullPathToFile);
			}
				
			bLoadedOnce = true;
		}
	}
}