#pragma once

// Parent Includes
#include "Subsystems/GameInstanceSubsystem.h"

// Generated Includes
#include "Developer_Subsystem_BuildInfo.generated.h"


// ---------------------------------
// --- Enums
// ---------------------------------

UENUM(BlueprintType)
enum class EBuildInfo : uint8
{
	ProjectName,
	ProjectVersion,
	BuildType,
	BuildNumber,
	BuildDateTime,

	COUNT			UMETA(Hidden)
};

/*
 * \brief: Stores information about current project name, project version, and build details
 */
UCLASS()
class VH_DEVELOPER_API UDeveloper_Subsystem_BuildInfo : public UGameInstanceSubsystem
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------

protected:
	TMap<EBuildInfo, FString> BuildInfoMap;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	UDeveloper_Subsystem_BuildInfo();


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void Initialize(FSubsystemCollectionBase& collection) override;
	
	 
	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintPure)
	FString GetInfo(EBuildInfo requestedInfo) const;
};
