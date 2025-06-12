// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_VehicleAIController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_VehicleAIController() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_VehicleAIController();
	VH_VEHICLE_API UClass* Z_Construct_UClass_AVH_VehicleAIController_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AVH_VehicleAIController::execOnNewPathSegment)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_PathPointIndex);
		P_GET_STRUCT(FVector,Z_Param_StartSegmentLocation);
		P_GET_STRUCT(FVector,Z_Param_TargetSegmentLocation);
		P_GET_OBJECT(UClass,Z_Param_AreaClass);
		P_GET_UBOOL(Z_Param_bIsOnNavLink);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->OnNewPathSegment_Implementation(Z_Param_PathPointIndex,Z_Param_StartSegmentLocation,Z_Param_TargetSegmentLocation,Z_Param_AreaClass,Z_Param_bIsOnNavLink);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AVH_VehicleAIController::execGetCustomDestination)
	{
		P_GET_STRUCT(FVector,Z_Param_CurrentMoveFocus);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetCustomDestination_Implementation(Z_Param_CurrentMoveFocus);
		P_NATIVE_END;
	}
	struct VH_VehicleAIController_eventGetCustomDestination_Parms
	{
		FVector CurrentMoveFocus;
		FVector ReturnValue;

		/** Constructor, initializes return property only **/
		VH_VehicleAIController_eventGetCustomDestination_Parms()
			: ReturnValue(ForceInit)
		{
		}
	};
	struct VH_VehicleAIController_eventOnNewPathSegment_Parms
	{
		int32 PathPointIndex;
		FVector StartSegmentLocation;
		FVector TargetSegmentLocation;
		const UClass* AreaClass;
		bool bIsOnNavLink;
		FVector ReturnValue;

		/** Constructor, initializes return property only **/
		VH_VehicleAIController_eventOnNewPathSegment_Parms()
			: ReturnValue(ForceInit)
		{
		}
	};
	static FName NAME_AVH_VehicleAIController_GetCustomDestination = FName(TEXT("GetCustomDestination"));
	FVector AVH_VehicleAIController::GetCustomDestination(FVector CurrentMoveFocus)
	{
		VH_VehicleAIController_eventGetCustomDestination_Parms Parms;
		Parms.CurrentMoveFocus=CurrentMoveFocus;
		ProcessEvent(FindFunctionChecked(NAME_AVH_VehicleAIController_GetCustomDestination),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AVH_VehicleAIController_OnNewPathSegment = FName(TEXT("OnNewPathSegment"));
	FVector AVH_VehicleAIController::OnNewPathSegment(int32 PathPointIndex, FVector StartSegmentLocation, FVector TargetSegmentLocation, const UClass* AreaClass, bool bIsOnNavLink)
	{
		VH_VehicleAIController_eventOnNewPathSegment_Parms Parms;
		Parms.PathPointIndex=PathPointIndex;
		Parms.StartSegmentLocation=StartSegmentLocation;
		Parms.TargetSegmentLocation=TargetSegmentLocation;
		Parms.AreaClass=AreaClass;
		Parms.bIsOnNavLink=bIsOnNavLink ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AVH_VehicleAIController_OnNewPathSegment),&Parms);
		return Parms.ReturnValue;
	}
	void AVH_VehicleAIController::StaticRegisterNativesAVH_VehicleAIController()
	{
		UClass* Class = AVH_VehicleAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCustomDestination", &AVH_VehicleAIController::execGetCustomDestination },
			{ "OnNewPathSegment", &AVH_VehicleAIController::execOnNewPathSegment },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_CurrentMoveFocus;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::NewProp_CurrentMoveFocus = { "CurrentMoveFocus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventGetCustomDestination_Parms, CurrentMoveFocus), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventGetCustomDestination_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::NewProp_CurrentMoveFocus,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom Path Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Change the current move destination than the one the pathfinding system is providing (In debug mode, this is a blue square). \n\x09* Useful for following a path precisely every frame, like a spline to navigate a difficult corner or obstacle.\n\x09* @param CurrentMoveFocus - The target that the pathfinding system has set, and the agent is currently moving towards\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Change the current move destination than the one the pathfinding system is providing (In debug mode, this is a blue square).\nUseful for following a path precisely every frame, like a spline to navigate a difficult corner or obstacle.\n@param CurrentMoveFocus - The target that the pathfinding system has set, and the agent is currently moving towards" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_VehicleAIController, nullptr, "GetCustomDestination", nullptr, nullptr, Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::PropPointers), sizeof(VH_VehicleAIController_eventGetCustomDestination_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_VehicleAIController_eventGetCustomDestination_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_PathPointIndex;
		static const UECodeGen_Private::FStructPropertyParams NewProp_StartSegmentLocation;
		static const UECodeGen_Private::FStructPropertyParams NewProp_TargetSegmentLocation;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AreaClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AreaClass;
		static void NewProp_bIsOnNavLink_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsOnNavLink;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_PathPointIndex = { "PathPointIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventOnNewPathSegment_Parms, PathPointIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_StartSegmentLocation = { "StartSegmentLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventOnNewPathSegment_Parms, StartSegmentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_TargetSegmentLocation = { "TargetSegmentLocation", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventOnNewPathSegment_Parms, TargetSegmentLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_AreaClass_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_AreaClass = { "AreaClass", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventOnNewPathSegment_Parms, AreaClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_AreaClass_MetaData), Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_AreaClass_MetaData) };
	void Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_bIsOnNavLink_SetBit(void* Obj)
	{
		((VH_VehicleAIController_eventOnNewPathSegment_Parms*)Obj)->bIsOnNavLink = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_bIsOnNavLink = { "bIsOnNavLink", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_VehicleAIController_eventOnNewPathSegment_Parms), &Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_bIsOnNavLink_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_VehicleAIController_eventOnNewPathSegment_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_PathPointIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_StartSegmentLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_TargetSegmentLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_AreaClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_bIsOnNavLink,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::Function_MetaDataParams[] = {
		{ "Category", "Custom Path Control" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n\x09* Allows you to change the current path point to a different location (Debug mode: Yellow square).\n\x09* This is executed once every time the vehicle reaches a new path point, so can be more optimial than GetCustomDestination (executed every frame)\n\x09* @param PathPointIndex - The index of this new path point, which can then be used to check other path points relative to this one\n\x09* @param StartSegmentLocation - The point which the vehicle reached when it triggered this event\n\x09* @param TargetSegmentLocation - The unchanged path point this vehicle is trying to reach\n\x09* @param AreaClass - The area class of the target segment\n\x09* @param bIsOnNavLink - Whether or not the target segment is on a nav link or not\n\x09* @return The new location for this path point to be set\n\x09*/" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Allows you to change the current path point to a different location (Debug mode: Yellow square).\nThis is executed once every time the vehicle reaches a new path point, so can be more optimial than GetCustomDestination (executed every frame)\n@param PathPointIndex - The index of this new path point, which can then be used to check other path points relative to this one\n@param StartSegmentLocation - The point which the vehicle reached when it triggered this event\n@param TargetSegmentLocation - The unchanged path point this vehicle is trying to reach\n@param AreaClass - The area class of the target segment\n@param bIsOnNavLink - Whether or not the target segment is on a nav link or not\n@return The new location for this path point to be set" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AVH_VehicleAIController, nullptr, "OnNewPathSegment", nullptr, nullptr, Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::PropPointers), sizeof(VH_VehicleAIController_eventOnNewPathSegment_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08820C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::Function_MetaDataParams), Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::PropPointers) < 2048);
	static_assert(sizeof(VH_VehicleAIController_eventOnNewPathSegment_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AVH_VehicleAIController);
	UClass* Z_Construct_UClass_AVH_VehicleAIController_NoRegister()
	{
		return AVH_VehicleAIController::StaticClass();
	}
	struct Z_Construct_UClass_AVH_VehicleAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AVH_VehicleAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_VehicleAIController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AVH_VehicleAIController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AVH_VehicleAIController_GetCustomDestination, "GetCustomDestination" }, // 2365291953
		{ &Z_Construct_UFunction_AVH_VehicleAIController_OnNewPathSegment, "OnNewPathSegment" }, // 461747696
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_VehicleAIController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AVH_VehicleAIController_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \n */" },
#endif
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "AI/Public/VH_VehicleAIController.h" },
		{ "ModuleRelativePath", "AI/Public/VH_VehicleAIController.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AVH_VehicleAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AVH_VehicleAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AVH_VehicleAIController_Statics::ClassParams = {
		&AVH_VehicleAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AVH_VehicleAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AVH_VehicleAIController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AVH_VehicleAIController()
	{
		if (!Z_Registration_Info_UClass_AVH_VehicleAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AVH_VehicleAIController.OuterSingleton, Z_Construct_UClass_AVH_VehicleAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AVH_VehicleAIController.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<AVH_VehicleAIController>()
	{
		return AVH_VehicleAIController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AVH_VehicleAIController);
	AVH_VehicleAIController::~AVH_VehicleAIController() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AVH_VehicleAIController, AVH_VehicleAIController::StaticClass, TEXT("AVH_VehicleAIController"), &Z_Registration_Info_UClass_AVH_VehicleAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AVH_VehicleAIController), 2663994778U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_1986762969(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_VehicleAIController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
