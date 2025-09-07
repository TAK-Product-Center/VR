#pragma once

#include "Game_Point_Icon.h"
#include "Game_Point_2525.generated.h"

UCLASS(Blueprintable, BlueprintType)
class GAME_API AGame_Point_2525 : public AGame_Point_Icon
{
	GENERATED_BODY()


	// ---------------------------------
	// --- Variables
	// ---------------------------------
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<UObject>> GhostContextOptionClasses;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* AttachmentComponent;

private:
	UPROPERTY()
	UMaterialInstanceDynamic* AttachmentMID;

	FVector AttachmentDefaultRelativeScale;


	// ---------------------------------
	// --- Constructors
	// ---------------------------------

public:
	AGame_Point_2525(const FObjectInitializer& objectInitializer);


	// ---------------------------------
	// --- Inherited
	// ---------------------------------

public:
	virtual void BeginPlay() override;

	virtual void SetType(const FName& type) override;

private:
	virtual bool PostClickPressed(AActor* actor, const FKey& buttonPressed) override;

	// ---------------------------------
	// --- API
	// ---------------------------------

public:
	UFUNCTION(BlueprintCallable)
	virtual void SetAuthor(const FString& author);


	// ---------------------------------
	// --- Implementation
	// ---------------------------------

private:
	void SyncToAttachments();


	// ---------------------------------
	// --- Event Handlers
	// ---------------------------------

private:
	UFUNCTION()
	void HandleUpdateContacts();

	UFUNCTION()
	void HandleAttachmentsModified(const FString& entityUID);
};
