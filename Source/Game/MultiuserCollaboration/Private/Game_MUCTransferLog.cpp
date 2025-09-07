#include "Game_MUCTransferLog.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_MUCTransferLog::UGame_MUCTransferLog()
{

}

// ---------------------------------
// --- Static Functions
// ---------------------------------

UGame_MUCTransferLog* UGame_MUCTransferLog::CreateMUCTransferLog(const FSpatialiteResult_BP& result)
{
	return CreateMUCTransferLog(result.Result);
}

UGame_MUCTransferLog* UGame_MUCTransferLog::CreateMUCTransferLog(const SpatialiteResult& result)
{
	UGame_MUCTransferLog* transferLog = NewObject<UGame_MUCTransferLog>();
	transferLog->SetResult(result);

	return transferLog;
}

// ---------------------------------
// --- API
// ---------------------------------

FDateTime UGame_MUCTransferLog::GetTimestamp() const
{
	return Timestamp;
}

FSpatialiteResult_BP UGame_MUCTransferLog::GetResult() const
{
	FSpatialiteResult_BP result;
	result.Result = Result;

	return result;
}

FString UGame_MUCTransferLog::GetEntityUID() const
{
	return EntityUID;
}

FString UGame_MUCTransferLog::GetCategoryID() const
{
	return CategoryID;
}

void UGame_MUCTransferLog::SetResult(const SpatialiteResult& result)
{
	Timestamp = FDateTime::Now();

	Result = result;

	EntityUID = UDatabase_Spatialite::GetString(TEXT("entityUID"), result);

	CategoryID = UDatabase_Spatialite::GetString(TEXT("categoryID"), result);
}

bool UGame_MUCTransferLog::IsRepeat(UGame_MUCTransferLog* otherLog)
{
	if (EntityUID.Equals(otherLog->GetEntityUID()))
	{
		FDateTime otherTimestamp = otherLog->GetTimestamp();

		return Timestamp > otherTimestamp && (Timestamp - otherTimestamp).GetTotalSeconds() <= 2.f;
	}

	return false;
}