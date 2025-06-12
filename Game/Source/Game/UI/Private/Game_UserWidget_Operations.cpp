// Required Includes
#include "Game_UserWidget_Operations.h"
#include "Game.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_Operations::UGame_UserWidget_Operations(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

bool UGame_UserWidget_Operations::GetStartTime(const FDateTime& date, const FString& time, FDateTime& startTime) const
{
	TArray<FString> timeColon;
	time.ParseIntoArray(timeColon, TEXT(":"));

	if (timeColon.Num() == 3)
	{
		// error check that time is in format HH:MM:SS
		for (const FString& timeEntry : timeColon)
		{
			if (timeEntry.Len() != 2)
			{
				return false;
			}
		}

		int32 hour = FCString::Atoi(*timeColon[0]);
		if (hour < 0 || hour > 23)
		{
			return false;
		}

		int32 minute = FCString::Atoi(*timeColon[1]);
		if (minute < 0 || minute > 59)
		{
			return false;
		}

		int32 second = FCString::Atoi(*timeColon[2]);
		if (second < 0 || second > 59)
		{
			return false;
		}

		// create timestamp
		startTime = FDateTime(date.GetYear(), date.GetMonth(), date.GetDay(), hour, minute, second, 0);

		return true;
	}

	return false;
}

