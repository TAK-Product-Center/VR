#include "VH_COTChat.h"
#include "Database_Spatialite.h"

UVH_COTChat::UVH_COTChat() :
    Message(TEXT("")),
    OtherCallsign(TEXT("")),
    OtherUID(NAME_None),
    bSending(false)
{
}

void UVH_COTChat::PopulateFromDB(const SpatialiteResult& result)
{
    OtherUID = FName(*UDatabase_Spatialite::GetString(TEXT("otherUID"), result));
    OtherCallsign = UDatabase_Spatialite::GetString(TEXT("otherName"), result);

	FString timestamp = UDatabase_Spatialite::GetString(TEXT("timestamp"), result);
    timestamp.ReplaceInline(TEXT("-"), TEXT("."));
    timestamp.ReplaceInline(TEXT(":"), TEXT("."));
    timestamp.ReplaceInline(TEXT(" "), TEXT("-"));
    const TCHAR* timestampPtr = *timestamp;
    Timestamp.ImportTextItem(timestampPtr, 0, nullptr, nullptr);

    Message = UDatabase_Spatialite::GetString(TEXT("message"), result);
    bSending = UDatabase_Spatialite::GetBool(TEXT("sending"), result);
}

void UVH_COTChat::AddToDatabase(UDatabase_Spatialite* database) const
{
    FString timestamp = Timestamp.ToString(TEXT("%Y-%m-%d %H:%M:%S"));

    FString query = FString::Printf(TEXT("insert into chats (otherUID, otherName, timestamp, message, sending) values (\"%s\", \"%s\", \"%s\", \"%s\", %d)"), *OtherUID.ToString(), *OtherCallsign, *timestamp, *Message, bSending ? 1 : 0);
    database->SyncQuery(query);
}