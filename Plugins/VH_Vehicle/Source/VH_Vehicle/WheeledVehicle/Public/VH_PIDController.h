#pragma once

#include "UObject/NoExportTypes.h"
#include "VH_PIDController.generated.h"

USTRUCT()
struct FPIDError
{
	GENERATED_BODY()

	float MeasuredValue;
	float DeltaTime;

	FPIDError()
	{
	}

	FPIDError(float NewMeasuredValue, float NewDeltaTime)
	{
		MeasuredValue = NewMeasuredValue;
		DeltaTime = NewDeltaTime;
	}

};

USTRUCT(BlueprintType)
struct FPIDCoefficients
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PID Coefficients")
	float ProportionalCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PID Coefficients")
	float IntegralCoefficient;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PID Coefficients")
	float DerivativeCoefficient;

	FPIDCoefficients()
	{
		ProportionalCoefficient = 0;
		IntegralCoefficient = 0;
		DerivativeCoefficient = 0;
	}

	FPIDCoefficients(float Proportional, float Integral, float Derivative)
	{
		ProportionalCoefficient = Proportional;
		IntegralCoefficient = Integral;
		DerivativeCoefficient = Derivative;
	}
};

USTRUCT()
struct FPIDController
{
	GENERATED_BODY()

	float ProportionalCoefficient;

	float IntegralCoefficient;

	float DerivativeCoefficient;

	TArray<FPIDError> Errors;

	float ProportionalError;
	float IntegralError;
	float DerivativeError;

	int NumberOfErrors = 4;

	FPIDController()
	{
		Errors.Init(FPIDError(), NumberOfErrors);
	}

	float GetPIDValue()
	{
		ProportionalError = 0.f;
		IntegralError = 0.f;
		DerivativeError = 0.f;

		if (Errors.Num() >= 2)
		{
			if (Errors.IsValidIndex(0))
			{
				ProportionalError = Errors[0].MeasuredValue;
			}

			for (FPIDError Value : Errors)
			{
				IntegralError = Value.MeasuredValue * Value.DeltaTime + IntegralError;
			}

			if (Errors.IsValidIndex(0) && Errors.IsValidIndex(1))
			{
				DerivativeError = (Errors[0].MeasuredValue - Errors[1].MeasuredValue) / Errors[0].DeltaTime;
			}

		}

		ProportionalError *= ProportionalCoefficient;
		IntegralError *= IntegralCoefficient;
		DerivativeError *= DerivativeCoefficient;

		return ProportionalError + IntegralError + DerivativeError;
	}

	void ResetController(FPIDCoefficients Coefficients)
	{
		ProportionalCoefficient = Coefficients.ProportionalCoefficient;
		IntegralCoefficient = Coefficients.IntegralCoefficient;
		DerivativeCoefficient = Coefficients.DerivativeCoefficient;

		Errors.Empty();

		Errors.Init(FPIDError(), NumberOfErrors);
	}

	void AddMeasuredValue(float MeasuredValue, float DeltaTime)
	{
		if (Errors.IsValidIndex(0))
		{
			Errors.Insert(FPIDError(MeasuredValue, DeltaTime), 0);

			if (Errors.Num() > NumberOfErrors)
			{
				Errors.RemoveAt(Errors.Num() - 1);
			}

		}
	}
};