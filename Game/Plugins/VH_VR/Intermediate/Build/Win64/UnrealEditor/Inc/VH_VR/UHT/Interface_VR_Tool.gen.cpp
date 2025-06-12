// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "../../Core/Public/Interface_VR_Tool.h"
#include "InputAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeInterface_VR_Tool() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UInterface();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionInstance();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_VR_API UClass* Z_Construct_UClass_UInterface_VR_Tool();
	VH_VR_API UClass* Z_Construct_UClass_UInterface_VR_Tool_NoRegister();
	VH_VR_API UClass* Z_Construct_UClass_UVR_MotionControllerComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(IInterface_VR_Tool::execGetRelativeTransformForNonVRPositioning)
	{
		P_GET_STRUCT_REF(FTransform,Z_Param_Out_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetRelativeTransformForNonVRPositioning_Implementation(Z_Param_Out_transform);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_VR_Tool::execActionInput)
	{
		P_GET_STRUCT_REF(FInputActionInstance,Z_Param_Out_inputActionInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ActionInput_Implementation(Z_Param_Out_inputActionInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_VR_Tool::execInputToolStackIndexChanged)
	{
		P_GET_OBJECT(UVR_MotionControllerComponent,Z_Param_motionControllerComponent);
		P_GET_PROPERTY(FIntProperty,Z_Param_index);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->InputToolStackIndexChanged_Implementation(Z_Param_motionControllerComponent,Z_Param_index);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_VR_Tool::execRemovedFromInputToolStack)
	{
		P_GET_OBJECT(UVR_MotionControllerComponent,Z_Param_motionControllerComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemovedFromInputToolStack_Implementation(Z_Param_motionControllerComponent);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(IInterface_VR_Tool::execAddedToInputToolStack)
	{
		P_GET_OBJECT(UVR_MotionControllerComponent,Z_Param_motionControllerComponent);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddedToInputToolStack_Implementation(Z_Param_motionControllerComponent);
		P_NATIVE_END;
	}
	struct Interface_VR_Tool_eventActionInput_Parms
	{
		FInputActionInstance inputActionInstance;
	};
	struct Interface_VR_Tool_eventAddedToInputToolStack_Parms
	{
		UVR_MotionControllerComponent* motionControllerComponent;
	};
	struct Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms
	{
		FTransform transform;
		bool ReturnValue;

		/** Constructor, initializes return property only **/
		Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms()
			: ReturnValue(false)
		{
		}
	};
	struct Interface_VR_Tool_eventInputToolStackIndexChanged_Parms
	{
		UVR_MotionControllerComponent* motionControllerComponent;
		int32 index;
	};
	struct Interface_VR_Tool_eventRemovedFromInputToolStack_Parms
	{
		UVR_MotionControllerComponent* motionControllerComponent;
	};
	void IInterface_VR_Tool::ActionInput(FInputActionInstance const& inputActionInstance)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_ActionInput instead.");
	}
	void IInterface_VR_Tool::AddedToInputToolStack(UVR_MotionControllerComponent* motionControllerComponent)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_AddedToInputToolStack instead.");
	}
	bool IInterface_VR_Tool::GetRelativeTransformForNonVRPositioning(FTransform& transform) const
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_GetRelativeTransformForNonVRPositioning instead.");
		Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms Parms;
		return Parms.ReturnValue;
	}
	void IInterface_VR_Tool::InputToolStackIndexChanged(UVR_MotionControllerComponent* motionControllerComponent, int32 index)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_InputToolStackIndexChanged instead.");
	}
	void IInterface_VR_Tool::RemovedFromInputToolStack(UVR_MotionControllerComponent* motionControllerComponent)
	{
		check(0 && "Do not directly call Event functions in Interfaces. Call Execute_RemovedFromInputToolStack instead.");
	}
	void UInterface_VR_Tool::StaticRegisterNativesUInterface_VR_Tool()
	{
		UClass* Class = UInterface_VR_Tool::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ActionInput", &IInterface_VR_Tool::execActionInput },
			{ "AddedToInputToolStack", &IInterface_VR_Tool::execAddedToInputToolStack },
			{ "GetRelativeTransformForNonVRPositioning", &IInterface_VR_Tool::execGetRelativeTransformForNonVRPositioning },
			{ "InputToolStackIndexChanged", &IInterface_VR_Tool::execInputToolStackIndexChanged },
			{ "RemovedFromInputToolStack", &IInterface_VR_Tool::execRemovedFromInputToolStack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_inputActionInstance_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_inputActionInstance;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::NewProp_inputActionInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::NewProp_inputActionInstance = { "inputActionInstance", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_VR_Tool_eventActionInput_Parms, inputActionInstance), Z_Construct_UScriptStruct_FInputActionInstance, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::NewProp_inputActionInstance_MetaData), Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::NewProp_inputActionInstance_MetaData) }; // 2153033866
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::NewProp_inputActionInstance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Core/Public/Interface_VR_Tool.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_VR_Tool, nullptr, "ActionInput", nullptr, nullptr, Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::PropPointers), sizeof(Interface_VR_Tool_eventActionInput_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_VR_Tool_eventActionInput_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_VR_Tool_ActionInput()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_VR_Tool_ActionInput_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_motionControllerComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_motionControllerComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::NewProp_motionControllerComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::NewProp_motionControllerComponent = { "motionControllerComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_VR_Tool_eventAddedToInputToolStack_Parms, motionControllerComponent), Z_Construct_UClass_UVR_MotionControllerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::NewProp_motionControllerComponent_MetaData), Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::NewProp_motionControllerComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::NewProp_motionControllerComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called when self is added to motionControllerComponent's InputToolStack.  Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_VR_Tool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called when self is added to motionControllerComponent's InputToolStack.  Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_VR_Tool, nullptr, "AddedToInputToolStack", nullptr, nullptr, Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::PropPointers), sizeof(Interface_VR_Tool_eventAddedToInputToolStack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_VR_Tool_eventAddedToInputToolStack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics
	{
		static const UECodeGen_Private::FStructPropertyParams NewProp_transform;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms), &Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::NewProp_transform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief VR_MotionControllerComponent will attempt to position itself to face the mouse position in desktop and VREmulation.\n\x09*\x09     This gives the transform of the position to use as the origin location when determining that position.\n\x09* \\return False uses identity transform\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_VR_Tool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief VR_MotionControllerComponent will attempt to position itself to face the mouse position in desktop and VREmulation.\n*            This gives the transform of the position to use as the origin location when determining that position.\n* \\return False uses identity transform" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_VR_Tool, nullptr, "GetRelativeTransformForNonVRPositioning", nullptr, nullptr, Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::PropPointers), sizeof(Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x48C20C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_motionControllerComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_motionControllerComponent;
		static const UECodeGen_Private::FIntPropertyParams NewProp_index;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_motionControllerComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_motionControllerComponent = { "motionControllerComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_VR_Tool_eventInputToolStackIndexChanged_Parms, motionControllerComponent), Z_Construct_UClass_UVR_MotionControllerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_motionControllerComponent_MetaData), Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_motionControllerComponent_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_index = { "index", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_VR_Tool_eventInputToolStackIndexChanged_Parms, index), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_motionControllerComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::NewProp_index,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called when self's index in motionControllerComponent's InputToolStack changes.  Tool receives input when at 0th index of motionControllerComponent's InputToolStack.  \n\x09*        Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_VR_Tool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called when self's index in motionControllerComponent's InputToolStack changes.  Tool receives input when at 0th index of motionControllerComponent's InputToolStack.\n*        Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_VR_Tool, nullptr, "InputToolStackIndexChanged", nullptr, nullptr, Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::PropPointers), sizeof(Interface_VR_Tool_eventInputToolStackIndexChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_VR_Tool_eventInputToolStackIndexChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_motionControllerComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_motionControllerComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::NewProp_motionControllerComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::NewProp_motionControllerComponent = { "motionControllerComponent", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(Interface_VR_Tool_eventRemovedFromInputToolStack_Parms, motionControllerComponent), Z_Construct_UClass_UVR_MotionControllerComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::NewProp_motionControllerComponent_MetaData), Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::NewProp_motionControllerComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::NewProp_motionControllerComponent,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Called when self is removed from motionControllerComponent's InputToolStack.  Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Core/Public/Interface_VR_Tool.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Called when self is removed from motionControllerComponent's InputToolStack.  Called on NM_DedicatedServer, NM_ListenServer, and NM_Standalone." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UInterface_VR_Tool, nullptr, "RemovedFromInputToolStack", nullptr, nullptr, Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::PropPointers), sizeof(Interface_VR_Tool_eventRemovedFromInputToolStack_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::Function_MetaDataParams), Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::PropPointers) < 2048);
	static_assert(sizeof(Interface_VR_Tool_eventRemovedFromInputToolStack_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UInterface_VR_Tool);
	UClass* Z_Construct_UClass_UInterface_VR_Tool_NoRegister()
	{
		return UInterface_VR_Tool::StaticClass();
	}
	struct Z_Construct_UClass_UInterface_VR_Tool_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UInterface_VR_Tool_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UInterface,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_VR_Tool_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UInterface_VR_Tool_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UInterface_VR_Tool_ActionInput, "ActionInput" }, // 1147034535
		{ &Z_Construct_UFunction_UInterface_VR_Tool_AddedToInputToolStack, "AddedToInputToolStack" }, // 1046076009
		{ &Z_Construct_UFunction_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning, "GetRelativeTransformForNonVRPositioning" }, // 2868836980
		{ &Z_Construct_UFunction_UInterface_VR_Tool_InputToolStackIndexChanged, "InputToolStackIndexChanged" }, // 1428961212
		{ &Z_Construct_UFunction_UInterface_VR_Tool_RemovedFromInputToolStack, "RemovedFromInputToolStack" }, // 3304041561
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_VR_Tool_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UInterface_VR_Tool_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Core/Public/Interface_VR_Tool.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UInterface_VR_Tool_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<IInterface_VR_Tool>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UInterface_VR_Tool_Statics::ClassParams = {
		&UInterface_VR_Tool::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001040A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UInterface_VR_Tool_Statics::Class_MetaDataParams), Z_Construct_UClass_UInterface_VR_Tool_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UInterface_VR_Tool()
	{
		if (!Z_Registration_Info_UClass_UInterface_VR_Tool.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UInterface_VR_Tool.OuterSingleton, Z_Construct_UClass_UInterface_VR_Tool_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UInterface_VR_Tool.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UInterface_VR_Tool>()
	{
		return UInterface_VR_Tool::StaticClass();
	}
	UInterface_VR_Tool::UInterface_VR_Tool(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UInterface_VR_Tool);
	UInterface_VR_Tool::~UInterface_VR_Tool() {}
	static FName NAME_UInterface_VR_Tool_ActionInput = FName(TEXT("ActionInput"));
	void IInterface_VR_Tool::Execute_ActionInput(UObject* O, FInputActionInstance const& inputActionInstance)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_VR_Tool::StaticClass()));
		Interface_VR_Tool_eventActionInput_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_VR_Tool_ActionInput);
		if (Func)
		{
			Parms.inputActionInstance=inputActionInstance;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_VR_Tool*)(O->GetNativeInterfaceAddress(UInterface_VR_Tool::StaticClass())))
		{
			I->ActionInput_Implementation(inputActionInstance);
		}
	}
	static FName NAME_UInterface_VR_Tool_AddedToInputToolStack = FName(TEXT("AddedToInputToolStack"));
	void IInterface_VR_Tool::Execute_AddedToInputToolStack(UObject* O, UVR_MotionControllerComponent* motionControllerComponent)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_VR_Tool::StaticClass()));
		Interface_VR_Tool_eventAddedToInputToolStack_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_VR_Tool_AddedToInputToolStack);
		if (Func)
		{
			Parms.motionControllerComponent=motionControllerComponent;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_VR_Tool*)(O->GetNativeInterfaceAddress(UInterface_VR_Tool::StaticClass())))
		{
			I->AddedToInputToolStack_Implementation(motionControllerComponent);
		}
	}
	static FName NAME_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning = FName(TEXT("GetRelativeTransformForNonVRPositioning"));
	bool IInterface_VR_Tool::Execute_GetRelativeTransformForNonVRPositioning(const UObject* O, FTransform& transform)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_VR_Tool::StaticClass()));
		Interface_VR_Tool_eventGetRelativeTransformForNonVRPositioning_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_VR_Tool_GetRelativeTransformForNonVRPositioning);
		if (Func)
		{
			Parms.transform=transform;
			const_cast<UObject*>(O)->ProcessEvent(Func, &Parms);
			transform=Parms.transform;
		}
		else if (auto I = (const IInterface_VR_Tool*)(O->GetNativeInterfaceAddress(UInterface_VR_Tool::StaticClass())))
		{
			Parms.ReturnValue = I->GetRelativeTransformForNonVRPositioning_Implementation(transform);
		}
		return Parms.ReturnValue;
	}
	static FName NAME_UInterface_VR_Tool_InputToolStackIndexChanged = FName(TEXT("InputToolStackIndexChanged"));
	void IInterface_VR_Tool::Execute_InputToolStackIndexChanged(UObject* O, UVR_MotionControllerComponent* motionControllerComponent, int32 index)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_VR_Tool::StaticClass()));
		Interface_VR_Tool_eventInputToolStackIndexChanged_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_VR_Tool_InputToolStackIndexChanged);
		if (Func)
		{
			Parms.motionControllerComponent=motionControllerComponent;
			Parms.index=index;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_VR_Tool*)(O->GetNativeInterfaceAddress(UInterface_VR_Tool::StaticClass())))
		{
			I->InputToolStackIndexChanged_Implementation(motionControllerComponent,index);
		}
	}
	static FName NAME_UInterface_VR_Tool_RemovedFromInputToolStack = FName(TEXT("RemovedFromInputToolStack"));
	void IInterface_VR_Tool::Execute_RemovedFromInputToolStack(UObject* O, UVR_MotionControllerComponent* motionControllerComponent)
	{
		check(O != NULL);
		check(O->GetClass()->ImplementsInterface(UInterface_VR_Tool::StaticClass()));
		Interface_VR_Tool_eventRemovedFromInputToolStack_Parms Parms;
		UFunction* const Func = O->FindFunction(NAME_UInterface_VR_Tool_RemovedFromInputToolStack);
		if (Func)
		{
			Parms.motionControllerComponent=motionControllerComponent;
			O->ProcessEvent(Func, &Parms);
		}
		else if (auto I = (IInterface_VR_Tool*)(O->GetNativeInterfaceAddress(UInterface_VR_Tool::StaticClass())))
		{
			I->RemovedFromInputToolStack_Implementation(motionControllerComponent);
		}
	}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UInterface_VR_Tool, UInterface_VR_Tool::StaticClass, TEXT("UInterface_VR_Tool"), &Z_Registration_Info_UClass_UInterface_VR_Tool, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UInterface_VR_Tool), 2560431168U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_3767346056(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Core_Public_Interface_VR_Tool_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
