// Required Includes
#include "Game_UserWidget_DatePicker.h"
#include "Game.h"

// Game Includes
#include "Game_Statics.h"

// ---------------------------------
// --- Constructors
// ---------------------------------

UGame_UserWidget_DatePicker::UGame_UserWidget_DatePicker(const FObjectInitializer& objectInitializer) :
	Super(objectInitializer)
{

}

// ---------------------------------
// --- API
// ---------------------------------

void UGame_UserWidget_DatePicker::PopulateDays(const FDateTime& selectedDate)
{
	int32 daysInMonth = FDateTime::DaysInMonth(selectedDate.GetYear(), selectedDate.GetMonth());


	int32 firstDay = 0;
	for (int32 i = 1; i <= daysInMonth; i++)
	{
		FDateTime dateTime = FDateTime(selectedDate.GetYear(), selectedDate.GetMonth(), i, 0, 0, 0, 0);

		EDayOfWeek dayOfWeek = dateTime.GetDayOfWeek();

		if (i == 1)
		{
			firstDay = ((int32)dayOfWeek + 1) % 7;
		}

		int32 column = ((int32)dayOfWeek + 1) % 7;
		int32 row = FMath::Floor<int32>((firstDay + i - 1) / 7.f);

		ReceiveDay(column, row, dateTime);
	}
}

void UGame_UserWidget_DatePicker::SetToPreviousMonth(UPARAM(ref) FDateTime& date)
{
	int32 daysInMonth = FDateTime::DaysInMonth(date.GetYear(), date.GetMonth());

	date -= FTimespan(date.GetDay() + 1, 0, 0, 0);
}

void UGame_UserWidget_DatePicker::SetToNextMonth(UPARAM(ref) FDateTime& date)
{
	int32 daysInMonth = FDateTime::DaysInMonth(date.GetYear(), date.GetMonth());

	date += FTimespan(daysInMonth - date.GetDay() + 1, 0, 0, 0);
}
