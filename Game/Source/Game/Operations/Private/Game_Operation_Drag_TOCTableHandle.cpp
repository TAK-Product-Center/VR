// Required Includes
#include "Game_Operation_Drag_TOCTableHandle.h"
#include "Game.h"

// VH Plugin Includes
#include "VR_TraceComponent.h"

// Game Includes
#include "Game_Tool.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_Operation_Drag_TOCTableHandle::UGame_Operation_Drag_TOCTableHandle(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- Inherited
// ---------------------------------

void UGame_Operation_Drag_TOCTableHandle::StartDrag(AActor* actor, AGame_Tool* tool, double delaySeconds)
{
	Super::StartDrag(actor, tool, delaySeconds);

	DragOffset = FVector(0, 0, 0);
}

bool UGame_Operation_Drag_TOCTableHandle::GetDragLocation(FVector& dragLocation) const
{
	// determine intersection with flat plane
	FVector planeNormal = FVector(0, 0, 1);
	
	FPlane plane(planeNormal, FVector::PointPlaneDist(DraggedActor->GetActorLocation(), FVector::ZeroVector, planeNormal));

	FTransform localToWorld = DraggingTool->VRTrace->GetComponentTransform();

	FVector traceEnd = localToWorld.TransformPosition(FVector(10000, 0, 0));

	dragLocation = FMath::LinePlaneIntersection(localToWorld.GetLocation(), traceEnd, plane);

	return true;
}