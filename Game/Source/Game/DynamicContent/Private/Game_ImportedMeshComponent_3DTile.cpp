// Required Includes
#include "Game_ImportedMeshComponent_3DTile.h"
#include "Game.h"

// VH Plugin Includes
#include "VH_GlobeReferenceActor.h"
#include "VH_GlobeCoordConverter.h"
#include "VH_MeshInfo.h"

// Game Includes
#include "Game_VirtualObjective.h"
#include "Game_Statics.h"
#include "Game_Actor_3DTile.h"

#include <string>

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_ImportedMeshComponent_3DTile::UGame_ImportedMeshComponent_3DTile() :
	HAEBounds(FVector2D(9999999.0, -9999999.0))
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_ImportedMeshComponent_3DTile::UpdateBBFromBounds()
{
	// purposefully not allowing
}

// copied from Super except relative transform is ECEF with y and z flipped
void UGame_ImportedMeshComponent_3DTile::AddNodeToAsyncData(FVH_MeshImportMeshNode& meshNode, USceneComponent* parentComponent)
{
	RelativeTransform = meshNode.RelativeTransform;

	// pull ECEF from meshNode.RelativeTransform
	FVector ecef;
	ecef.X = meshNode.RelativeTransform.GetTranslation().X;
	ecef.Y = meshNode.RelativeTransform.GetTranslation().Z;
	ecef.Z = meshNode.RelativeTransform.GetTranslation().Y;

	FTransform updatedWorldTransform = FTransform(FRotator(0, 0, 0), FVector(0, 0, 0), FVector(1, 1, 1));

	if (ecef.Size() == 0)
	{
		// see if b3dm exists (looking for RTC_CENTER)
		FString fullPathToB3DM = FString::Printf(TEXT("%s/%s.%s"), *FPaths::GetPath(MeshInfo->FullFilename), *FPaths::GetBaseFilename(MeshInfo->FullFilename), TEXT("b3dm"));
		if (FPaths::FileExists(fullPathToB3DM))
		{
			TArray<uint8> data;
			FFileHelper::LoadFileToArray(data, *fullPathToB3DM);

			if (data.Num() < 28)
			{
				// bad b3dm file; abort
				UE_LOG(Game, Warning, TEXT("-- UGame_ImportedMeshComponent_3DTile::AddNodeToAsyncData | %s | data size < 28 | aborting"), *fullPathToB3DM);
				return;
			}

			const std::string cstr(reinterpret_cast<const char*>(data.GetData() + 28), data.Num() - 28);
			FString frameAsFString = cstr.c_str();

			int32 index = frameAsFString.Find(TEXT("RTC_CENTER"));
			if (index != INDEX_NONE)
			{
				FString rightChop = frameAsFString.RightChop(index);

				TArray<FString> parsed;
				rightChop.ParseIntoArray(parsed, TEXT("["));

				TArray<FString> parsed2;
				parsed[1].ParseIntoArray(parsed2, TEXT("]"));

				TArray<FString> parsedComma;
				parsed2[0].ParseIntoArray(parsedComma, TEXT(","));

				ecef.X = FCString::Atod(*parsedComma[0]);
				ecef.Y = FCString::Atod(*parsedComma[1]);
				ecef.Z = FCString::Atod(*parsedComma[2]);

				RelativeTransform.SetTranslation(FVector(ecef.X, ecef.Z, ecef.Y));
			}
		}
	}

	USceneComponent* groupComponent = nullptr;

	if (meshNode.ChildNodes.Num() > 0 || meshNode.Meshes.Num() > 1)
	{
		// Insert a SceneComponent into the hierarchy, if NOT a leaf node with exactly 1 mesh. This will serve as a mesh/node "group" component.

		FString compBaseName = FString(TEXT("(SceneComp)") + meshNode.Name).Left(32);
		FName compName = MakeUniqueObjectName(parentComponent->GetOuter(), USceneComponent::StaticClass(), FName(*compBaseName));
		groupComponent = NewObject<USceneComponent>(parentComponent, compName);

		groupComponent->SetWorldTransform(updatedWorldTransform);
		if (parentComponent != nullptr)
		{
			groupComponent->AttachToComponent(parentComponent, FAttachmentTransformRules::KeepRelativeTransform);
		}
		groupComponent->RegisterComponent();

		// Update 'parentComponent' for submeshes and/or child nodes
		parentComponent = groupComponent;
	}

	for (int32 meshDataIndex : meshNode.Meshes)
	{
		if (MeshInfo->MeshDataList[meshDataIndex].Triangles.Num() % 3 == 0)
		{
			FAsyncMeshData asyncMeshData;
			// NOTE: Only apply RelativeTransform here if not already applied to groupComponent
			asyncMeshData.RelativeTransform = (groupComponent == nullptr) ? updatedWorldTransform : FTransform::Identity;
			asyncMeshData.MeshData = MeshInfo->MeshDataList[meshDataIndex];
			asyncMeshData.TriangleIndex = 0;
			asyncMeshData.SceneComponent = parentComponent;

			FString materialName = MeshInfo->MaterialList[asyncMeshData.MeshData.MaterialIndex];
			if (!materialName.IsEmpty() && !materialName.Equals(TEXT("<default>"), ESearchCase::IgnoreCase))
			{
				// handle redirect from TextureResourceMap
				materialName = TextureResourceMap.Contains(materialName) ? TextureResourceMap[materialName] : materialName;

				asyncMeshData.FullPathToTexture = FPaths::Combine(FPaths::GetPath(FullPathToFile), materialName);
			}
			else
			{
				asyncMeshData.FullPathToTexture = TEXT("<default>");
			}

			AsyncMeshDatas.Add(asyncMeshData);
		}
		else
		{
			UE_LOG(Game, Warning, TEXT("-- triangle entries not a multiple of 3: %d"), MeshInfo->MeshDataList[meshDataIndex].Triangles.Num());
		}
	}

	for (const int32 childNodeIndex : meshNode.ChildNodes)
	{
		AddNodeToAsyncData(MeshInfo->NodeList[childNodeIndex], parentComponent);
	}

	// set owner location based on ECEF
	if (ecef.Size() != 0)
	{
		if (AGame_VirtualObjective* virtualObjective = GetVirtualObjective())
		{
			if (AVH_GlobeReferenceActor* globeReference = virtualObjective->GetGlobeReference())
			{
				FGeodeticCoord3D coordinate = globeReference->GetGlobeCoordConverter()->ECEFToGeodetic(ecef);

				GetOwner()->SetActorLocation(globeReference->GeodeticToWorldDouble(coordinate));

				// attach owner (Game_OWTActor) to owner's owner (terrain tile)
				GetOwner()->AttachToActor(GetOwner()->GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
			}
		}
	}
}

void UGame_ImportedMeshComponent_3DTile::PostAddNodesToAsyncData()
{
	if (AVH_GlobeReferenceActor* globeReference = GetVirtualObjective()->GetGlobeReference())
	{
		HAEBounds = FVector2D(9999999.0, -9999999.0);
		bValidHAEBounds = false;

		for (FAsyncMeshData& asyncMeshData : AsyncMeshDatas)
		{
			for (int32 i = 0; i < asyncMeshData.MeshData.Vertices.Num(); i++)
			{
				FVector vert = asyncMeshData.MeshData.Vertices[i];

				FVector vertECEF;
				if (RelativeTransform.GetLocation().Size() == 0)
				{
					FMatrix yToZ;
					yToZ.M[0][0] = 1; yToZ.M[0][1] = 0; yToZ.M[0][2] = 0; yToZ.M[0][3] = 0;
					yToZ.M[1][0] = 0; yToZ.M[1][1] = 0; yToZ.M[1][2] = 1; yToZ.M[1][3] = 0;
					yToZ.M[2][0] = 0; yToZ.M[2][1] = 1; yToZ.M[2][2] = 0; yToZ.M[2][3] = 0;
					yToZ.M[3][0] = 0; yToZ.M[3][1] = 0; yToZ.M[3][2] = 0; yToZ.M[3][3] = 1;

					FMatrix vertMatrix;
					vertMatrix.SetIdentity();
					vertMatrix.M[0][0] = vert.X;
					vertMatrix.M[1][0] = vert.Y;
					vertMatrix.M[2][0] = vert.Z;
					vertMatrix.M[3][0] = 1;

					FMatrix result = ImportOptions.Matrix * yToZ * vertMatrix;

					vertECEF.X = result.M[0][0];
					vertECEF.Y = result.M[1][0];
					vertECEF.Z = result.M[2][0];
				}
				else
				{
					vertECEF = RelativeTransform.TransformPosition(vert);

					double y = vertECEF.Y;
					vertECEF.Y = vertECEF.Z;
					vertECEF.Z = y;
				}
				
				FGeodeticCoord3D vertCoordinate = globeReference->GetGlobeCoordConverter()->ECEFToGeodetic(vertECEF);

				HAEBounds.X = FMath::Min<double>(HAEBounds.X, vertCoordinate.Altitude);
				HAEBounds.Y = FMath::Max<double>(HAEBounds.Y, vertCoordinate.Altitude);

				OnHAEBoundsUpdated.ExecuteIfBound(HAEBounds, GetOwner());

				bValidHAEBounds = true;
				
				FVector vertWorldLocation = globeReference->GeodeticToWorldDouble(vertCoordinate);

				FTransform newTransform;
				newTransform.SetLocation(GetOwner()->GetActorLocation());
				newTransform.SetRotation(FRotator(0, 0, 0).Quaternion());
				newTransform.SetScale3D(FVector(1, 1, 1));

				FVector localSpaceNoRotation = newTransform.InverseTransformPosition(vertWorldLocation);
				asyncMeshData.MeshData.Vertices[i] = localSpaceNoRotation;

				//UE_LOG(LogTemp, Warning, TEXT("-- world: %s | %s"), *vertWorldLocation.ToString(), *asyncMeshData.MeshData.Vertices[i].ToString());
			}
		}

		//if (!GetCullForDrawDistance())
		{
			bool bReverseVertOrder = Cast<AGame_Actor_3DTile>(GetOwner())->bReverseVertOrder;

			for (FAsyncMeshData& asyncMeshData : AsyncMeshDatas)
			{
				for (int32 i = 0; i < asyncMeshData.MeshData.Triangles.Num(); i += 3)
				{
					FTriangle triangle;

					if (bReverseVertOrder)
					{
						triangle.Vert3 = asyncMeshData.MeshData.Triangles[i];
						triangle.Vert2 = asyncMeshData.MeshData.Triangles[i + 1];
						triangle.Vert1 = asyncMeshData.MeshData.Triangles[i + 2];
					}
					else
					{
						triangle.Vert1 = asyncMeshData.MeshData.Triangles[i];
						triangle.Vert2 = asyncMeshData.MeshData.Triangles[i + 1];
						triangle.Vert3 = asyncMeshData.MeshData.Triangles[i + 2];
					}

					asyncMeshData.TrianglesToBuild.Add(triangle);
				}
			}
		}
	}
}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_ImportedMeshComponent_3DTile::GetHAEBounds(FVector2D& haeBounds) const
{
	if (bValidHAEBounds)
	{
		haeBounds = HAEBounds;
	}

	return bValidHAEBounds;
}
