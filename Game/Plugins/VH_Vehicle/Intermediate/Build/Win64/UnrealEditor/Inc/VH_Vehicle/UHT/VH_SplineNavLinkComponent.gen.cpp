// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VH_SplineNavLinkComponent.h"
#include "../../Source/Runtime/Engine/Classes/AI/Navigation/NavigationTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVH_SplineNavLinkComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USplineComponent();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ENavLinkDirection();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FNavLinkId();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavArea_NoRegister();
	NAVIGATIONSYSTEM_API UClass* Z_Construct_UClass_UNavLinkCustomInterface_NoRegister();
	UPackage* Z_Construct_UPackage__Script_VH_Vehicle();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_SplineNavLinkComponent();
	VH_VEHICLE_API UClass* Z_Construct_UClass_UVH_SplineNavLinkComponent_NoRegister();
	VH_VEHICLE_API UFunction* Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics
	{
		struct _Script_VH_Vehicle_eventOnMoveReachedLink_Parms
		{
			UVH_SplineNavLinkComponent* ThisComp;
			AActor* Agent;
			FVector DestPoint;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ThisComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ThisComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Agent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DestPoint_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_DestPoint;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_ThisComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_ThisComp = { "ThisComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_Vehicle_eventOnMoveReachedLink_Parms, ThisComp), Z_Construct_UClass_UVH_SplineNavLinkComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_ThisComp_MetaData), Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_ThisComp_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_Agent = { "Agent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_Vehicle_eventOnMoveReachedLink_Parms, Agent), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_DestPoint_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_DestPoint = { "DestPoint", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_VH_Vehicle_eventOnMoveReachedLink_Parms, DestPoint), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_DestPoint_MetaData), Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_DestPoint_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_ThisComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_Agent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::NewProp_DestPoint,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// ---------------------------------\n// --- Delegates\n// ---------------------------------\n" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "--- Delegates" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_VH_Vehicle, nullptr, "OnMoveReachedLink__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::_Script_VH_Vehicle_eventOnMoveReachedLink_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::_Script_VH_Vehicle_eventOnMoveReachedLink_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnMoveReachedLink_DelegateWrapper(const FMulticastScriptDelegate& OnMoveReachedLink, UVH_SplineNavLinkComponent* ThisComp, AActor* Agent, FVector const& DestPoint)
{
	struct _Script_VH_Vehicle_eventOnMoveReachedLink_Parms
	{
		UVH_SplineNavLinkComponent* ThisComp;
		AActor* Agent;
		FVector DestPoint;
	};
	_Script_VH_Vehicle_eventOnMoveReachedLink_Parms Parms;
	Parms.ThisComp=ThisComp;
	Parms.Agent=Agent;
	Parms.DestPoint=DestPoint;
	OnMoveReachedLink.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVH_SplineNavLinkComponent::execSetAllowTraverse)
	{
		P_GET_UBOOL(Z_Param_bAllow);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetAllowTraverse(Z_Param_bAllow);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_SplineNavLinkComponent::execResumePathFollowing)
	{
		P_GET_OBJECT(AActor,Z_Param_Agent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResumePathFollowing(Z_Param_Agent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVH_SplineNavLinkComponent::execCanTraverseLink)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CanTraverseLink();
		P_NATIVE_END;
	}
	void UVH_SplineNavLinkComponent::StaticRegisterNativesUVH_SplineNavLinkComponent()
	{
		UClass* Class = UVH_SplineNavLinkComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CanTraverseLink", &UVH_SplineNavLinkComponent::execCanTraverseLink },
			{ "ResumePathFollowing", &UVH_SplineNavLinkComponent::execResumePathFollowing },
			{ "SetAllowTraverse", &UVH_SplineNavLinkComponent::execSetAllowTraverse },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics
	{
		struct VH_SplineNavLinkComponent_eventCanTraverseLink_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VH_SplineNavLinkComponent_eventCanTraverseLink_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_SplineNavLinkComponent_eventCanTraverseLink_Parms), &Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::Function_MetaDataParams[] = {
		{ "Category", "Spline Nav Link" },
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_SplineNavLinkComponent, nullptr, "CanTraverseLink", nullptr, nullptr, Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::VH_SplineNavLinkComponent_eventCanTraverseLink_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::VH_SplineNavLinkComponent_eventCanTraverseLink_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics
	{
		struct VH_SplineNavLinkComponent_eventResumePathFollowing_Parms
		{
			AActor* Agent;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Agent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::NewProp_Agent = { "Agent", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VH_SplineNavLinkComponent_eventResumePathFollowing_Parms, Agent), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::NewProp_Agent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::Function_MetaDataParams[] = {
		{ "Category", "Spline Nav Link" },
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_SplineNavLinkComponent, nullptr, "ResumePathFollowing", nullptr, nullptr, Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::VH_SplineNavLinkComponent_eventResumePathFollowing_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::VH_SplineNavLinkComponent_eventResumePathFollowing_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics
	{
		struct VH_SplineNavLinkComponent_eventSetAllowTraverse_Parms
		{
			bool bAllow;
		};
		static void NewProp_bAllow_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAllow;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::NewProp_bAllow_SetBit(void* Obj)
	{
		((VH_SplineNavLinkComponent_eventSetAllowTraverse_Parms*)Obj)->bAllow = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::NewProp_bAllow = { "bAllow", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VH_SplineNavLinkComponent_eventSetAllowTraverse_Parms), &Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::NewProp_bAllow_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::NewProp_bAllow,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::Function_MetaDataParams[] = {
		{ "Category", "Spline Nav Link" },
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVH_SplineNavLinkComponent, nullptr, "SetAllowTraverse", nullptr, nullptr, Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::VH_SplineNavLinkComponent_eventSetAllowTraverse_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::VH_SplineNavLinkComponent_eventSetAllowTraverse_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVH_SplineNavLinkComponent);
	UClass* Z_Construct_UClass_UVH_SplineNavLinkComponent_NoRegister()
	{
		return UVH_SplineNavLinkComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinkRelativeStart_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LinkRelativeStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinkRelativeEnd_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_LinkRelativeEnd;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NavLinkUserId_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_NavLinkUserId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EnabledAreaClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_EnabledAreaClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DisabledAreaClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_DisabledAreaClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LinkDirection_MetaData[];
#endif
		static const UECodeGen_Private::FBytePropertyParams NewProp_LinkDirection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLinkEnabled_MetaData[];
#endif
		static void NewProp_bLinkEnabled_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLinkEnabled;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnMoveReachedLink_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnMoveReachedLink;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_USplineComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_Vehicle,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVH_SplineNavLinkComponent_CanTraverseLink, "CanTraverseLink" }, // 2513269229
		{ &Z_Construct_UFunction_UVH_SplineNavLinkComponent_ResumePathFollowing, "ResumePathFollowing" }, // 2584679376
		{ &Z_Construct_UFunction_UVH_SplineNavLinkComponent_SetAllowTraverse, "SetAllowTraverse" }, // 2411336149
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Custom" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * A spline link works like a smart NavLink, except it sets the start and end points of the link to the start and end of the spline instead \n */" },
#endif
		{ "HideCategories", "Physics Collision Lighting Rendering Mobile Trigger VirtualTexture" },
		{ "IncludePath", "AI/Public/VH_SplineNavLinkComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "A spline link works like a smart NavLink, except it sets the start and end points of the link to the start and end of the spline instead" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeStart_MetaData[] = {
		{ "Category", "Default" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** start point, relative to owner */" },
#endif
		{ "MakeEditWidget", "" },
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "start point, relative to owner" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeStart = { "LinkRelativeStart", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, LinkRelativeStart), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeStart_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeStart_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeEnd_MetaData[] = {
		{ "Category", "Default" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** end point, relative to owner */" },
#endif
		{ "MakeEditWidget", "" },
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "end point, relative to owner" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeEnd = { "LinkRelativeEnd", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, LinkRelativeEnd), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeEnd_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeEnd_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_NavLinkUserId_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** link Id assigned by navigation system */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "link Id assigned by navigation system" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_NavLinkUserId = { "NavLinkUserId", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, NavLinkUserId), Z_Construct_UScriptStruct_FNavLinkId, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_NavLinkUserId_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_NavLinkUserId_MetaData) }; // 1738334255
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_EnabledAreaClass_MetaData[] = {
		{ "Category", "SmartLink" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** area class to use when link is enabled */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "area class to use when link is enabled" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_EnabledAreaClass = { "EnabledAreaClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, EnabledAreaClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNavArea_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_EnabledAreaClass_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_EnabledAreaClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_DisabledAreaClass_MetaData[] = {
		{ "Category", "SmartLink" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** area class to use when link is disabled */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "area class to use when link is disabled" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_DisabledAreaClass = { "DisabledAreaClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, DisabledAreaClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UNavArea_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_DisabledAreaClass_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_DisabledAreaClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkDirection_MetaData[] = {
		{ "Category", "SmartLink" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** direction of link */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "direction of link" },
#endif
	};
#endif
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkDirection = { "LinkDirection", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, LinkDirection), Z_Construct_UEnum_Engine_ENavLinkDirection, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkDirection_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkDirection_MetaData) }; // 2374282288
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled_MetaData[] = {
		{ "Category", "SmartLink" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** is link currently in enabled state? (area class) */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "is link currently in enabled state? (area class)" },
#endif
	};
#endif
	void Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled_SetBit(void* Obj)
	{
		((UVH_SplineNavLinkComponent*)Obj)->bLinkEnabled = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled = { "bLinkEnabled", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool , RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(uint8), sizeof(UVH_SplineNavLinkComponent), &Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_OnMoveReachedLink_MetaData[] = {
		{ "Category", "Spline Nav Link" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** delegate to call when link is reached */" },
#endif
		{ "ModuleRelativePath", "AI/Public/VH_SplineNavLinkComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "delegate to call when link is reached" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_OnMoveReachedLink = { "OnMoveReachedLink", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVH_SplineNavLinkComponent, OnMoveReachedLink), Z_Construct_UDelegateFunction_VH_Vehicle_OnMoveReachedLink__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_OnMoveReachedLink_MetaData), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_OnMoveReachedLink_MetaData) }; // 2303997796
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkRelativeEnd,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_NavLinkUserId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_EnabledAreaClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_DisabledAreaClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_LinkDirection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_bLinkEnabled,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::NewProp_OnMoveReachedLink,
	};
		const UECodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UNavLinkCustomInterface_NoRegister, (int32)VTABLE_OFFSET(UVH_SplineNavLinkComponent, INavLinkCustomInterface), false },  // 511666681
		};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::InterfaceParams) < 64);
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVH_SplineNavLinkComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::ClassParams = {
		&UVH_SplineNavLinkComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::PropPointers,
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVH_SplineNavLinkComponent()
	{
		if (!Z_Registration_Info_UClass_UVH_SplineNavLinkComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVH_SplineNavLinkComponent.OuterSingleton, Z_Construct_UClass_UVH_SplineNavLinkComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVH_SplineNavLinkComponent.OuterSingleton;
	}
	template<> VH_VEHICLE_API UClass* StaticClass<UVH_SplineNavLinkComponent>()
	{
		return UVH_SplineNavLinkComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVH_SplineNavLinkComponent);
	UVH_SplineNavLinkComponent::~UVH_SplineNavLinkComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVH_SplineNavLinkComponent, UVH_SplineNavLinkComponent::StaticClass, TEXT("UVH_SplineNavLinkComponent"), &Z_Registration_Info_UClass_UVH_SplineNavLinkComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVH_SplineNavLinkComponent), 1945145703U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_1199629938(TEXT("/Script/VH_Vehicle"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_Vehicle_Source_VH_Vehicle_AI_Public_VH_SplineNavLinkComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
