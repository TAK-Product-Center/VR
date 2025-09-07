// Required Includes
#include "Game_MeshComponent_Ellipsoid.h"
#include "Game.h"

// Engine Includes
#include "Async/Async.h"

// Game Includes
#include "Game_PlayerController.h"
#include "Game_VirtualObjective.h"
#include "Game_GlobeReferenceActor_Ellipsoid.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MeshComponent_Ellipsoid::UGame_MeshComponent_Ellipsoid()
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_MeshComponent_Ellipsoid::ExecuteHelperThreadLogic()
{
	Super::ExecuteHelperThreadLogic();

	if (GetComponentStatus() == EComponentStatus::Initialized)
	{
		SetComponentStatus(EComponentStatus::HelperThreadStarted);

		// early out
		if (!Vertices.IsEmpty())
		{
			bDrawDistanceDirty = false;

			SetComponentStatus(EComponentStatus::HelperThreadFinished);

			return;
		}

		Async(EAsyncExecution::ThreadPool, [this]()
		{
			DestroyCounter.Increment();

			if (!IsSafeToExecute())
			{
				DestroyCounter.Decrement();
				return;
			}

			TArray<FVector> vertices;
			TArray<int32> triangles;
			TArray<FVector2D> uvs;

			AGame_GlobeReferenceActor_Ellipsoid* globeReferenceEllipsoid = nullptr;
			if (AGame_VirtualObjective* virtualObjective = AGame_PlayerController::GetPlayerActiveVO())
			{
				globeReferenceEllipsoid = Cast<AGame_GlobeReferenceActor_Ellipsoid>(virtualObjective->GetGlobeReference());
			}

			if (globeReferenceEllipsoid == nullptr)
			{
				return;
			}

			// bounded by 85.0511 and -85.0511 because mercator imagery doesn't cover poles (corresponds to bounds on imagery request in Game_TileManager for ellipsoid imagery)
			double topMercator = FMath::Loge(FMath::Tan((PI / 4.f) + (FMath::DegreesToRadians(85.0511 / 2.f))));
			double bottomMercator = FMath::Loge(FMath::Tan((PI / 4.f) + (FMath::DegreesToRadians(-85.0511 / 2.f))));
			double totalMercatorDistance = topMercator - bottomMercator;

			// northwest -> southeast
			for (int32 y = 90; y >= -90; y--)
			{
				double yDegreesClamp = FMath::Clamp<double>(y, -85.0511, 85.0511);
				double yRadians = FMath::DegreesToRadians(yDegreesClamp);
				double mercator = FMath::Loge(FMath::Tan((PI / 4.f) + (yRadians / 2.f)));

				// imagery has mercator projection, so transform uvY coord to offset distortion caused by mercator projection
				double uvY = (topMercator - mercator) / totalMercatorDistance;
				
				for (int32 x = -180; x <= 180; x++)
				{
					vertices.Add(globeReferenceEllipsoid->GeodeticToWorldDouble(FGeodeticCoord3D(x, y, 0)));

					// uvX is unaffected by mercator projection
					double uvX = FMath::Lerp<double>(0, 1, (x + 180) / 360.f);
					
					uvs.Add(FVector2D(uvX, uvY));

					// only 1 vertex at poles
					if (y == 90 || y == -90)
					{
						break;
					}
				}
			}

			// 64621 verts
			// 1 (index 0)
			// 361 (1 vertex overlaps)
			// 361
			// ... (179 of these in the middle)
			// 1 (index 64620)

			// northpole
			for (int32 x = 1; x <= 360; x++)
			{
				//	.	
				//	. .
				triangles.Add(0);
				triangles.Add(x);
				triangles.Add(x + 1);
			}

			// middle
			for (int32 y = 0; y < 178; y++)
			{
				int32 startingX = (y * 361) + 1;
				for (int32 x = 0; x < 360; x++)
				{
					// . .
					// .
					triangles.Add(startingX + x + 1 + 360);
					triangles.Add(startingX + x + 1);
					triangles.Add(startingX + x); 

					//   .
					// . .
					triangles.Add(startingX + x + 1 + 360);
					triangles.Add(startingX + x + 1 + 360 + 1);
					triangles.Add(startingX + x + 1);
				}
			}

			// southpole
			for (int32 x = 0; x < 360; x++)
			{
				int32 startingX = vertices.Num() - 361;

				//	. .	
				//	.
				triangles.Add(vertices.Num() - 1);
				triangles.Add(startingX + x + 1);
				triangles.Add(startingX + x);
			}

			{
				FScopeLock scopeLock(VerticesCritSection);
				Vertices.Empty();
				Vertices.Append(vertices);
			}

			{
				FScopeLock scopeLock(TrianglesCritSection);
				Triangles.Empty();
				Triangles.Append(triangles);
				TrianglesInRange.Append(triangles);
			}

			{
				FScopeLock scopeLock(UVsCritSection);
				UVs.Empty();
				UVs.Append(uvs);
			}

			bDrawDistanceDirty = false;

			SetComponentStatus(EComponentStatus::HelperThreadFinished);

			DestroyCounter.Decrement();
		});
	}
}