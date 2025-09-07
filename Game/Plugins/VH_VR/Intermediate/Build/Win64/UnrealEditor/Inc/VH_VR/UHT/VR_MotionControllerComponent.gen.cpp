// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VR_MotionControllerComponent.h"
#include "InputAction.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeVR_MotionControllerComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UInputComponent_NoRegister();
	ENGINE_API UEnum* Z_Construct_UEnum_Engine_ECollisionChannel();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UScriptStruct* Z_Construct_UScriptStruct_FInputActionInstance();
	HEADMOUNTEDDISPLAY_API UClass* Z_Construct_UClass_UMotionControllerComponent();
	UPackage* Z_Construct_UPackage__Script_VH_VR();
	VH_DEVELOPER_API UEnum* Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode();
	VH_VR_API UClass* Z_Construct_UClass_UVR_MotionControllerComponent();
	VH_VR_API UClass* Z_Construct_UClass_UVR_MotionControllerComponent_NoRegister();
	VH_VR_API UFunction* Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics
	{
		struct VR_MotionControllerComponent_eventInputStackTopChanged_Parms
		{
			AActor* tool;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tool;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::NewProp_tool = { "tool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventInputStackTopChanged_Parms, tool), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::NewProp_tool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "InputStackTopChanged__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::VR_MotionControllerComponent_eventInputStackTopChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::VR_MotionControllerComponent_eventInputStackTopChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void UVR_MotionControllerComponent::FInputStackTopChanged_DelegateWrapper(const FMulticastScriptDelegate& InputStackTopChanged, AActor* tool)
{
	struct VR_MotionControllerComponent_eventInputStackTopChanged_Parms
	{
		AActor* tool;
	};
	VR_MotionControllerComponent_eventInputStackTopChanged_Parms Parms;
	Parms.tool=tool;
	InputStackTopChanged.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execHandleInputAction)
	{
		P_GET_STRUCT_REF(FInputActionInstance,Z_Param_Out_inputActionInstance);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleInputAction(Z_Param_Out_inputActionInstance);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execHandleHardwareInterfaceModeChanged)
	{
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_newMode);
		P_GET_ENUM(EHardwareInterfaceMode,Z_Param_previousMode);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleHardwareInterfaceModeChanged(EHardwareInterfaceMode(Z_Param_newMode),EHardwareInterfaceMode(Z_Param_previousMode));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execHasTool)
	{
		P_GET_OBJECT(AActor,Z_Param_toolToFind);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->HasTool(Z_Param_toolToFind);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execGetInputToolStackTop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(AActor**)Z_Param__Result=P_THIS->GetInputToolStackTop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execRemoveAllTools)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveAllTools();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execRemoveTool)
	{
		P_GET_OBJECT(AActor,Z_Param_tool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RemoveTool(Z_Param_tool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execAddToolByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_toolClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddToolByClass(Z_Param_toolClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execAddTool)
	{
		P_GET_OBJECT(AActor,Z_Param_tool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddTool(Z_Param_tool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execOnRep_InputToolStackTop)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_InputToolStackTop();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execOnRep_RelativeTransform)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_RelativeTransform();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execServer_SetToolsVisibility)
	{
		P_GET_UBOOL(Z_Param_bVisibleArg);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetToolsVisibility_Implementation(Z_Param_bVisibleArg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execServer_RemoveAllTools)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_RemoveAllTools_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execServer_RemoveTool)
	{
		P_GET_OBJECT(AActor,Z_Param_tool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_RemoveTool_Implementation(Z_Param_tool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execServer_AddToolByClass)
	{
		P_GET_OBJECT(UClass,Z_Param_toolClass);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_AddToolByClass_Implementation(Z_Param_toolClass);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execServer_AddTool)
	{
		P_GET_OBJECT(AActor,Z_Param_tool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_AddTool_Implementation(Z_Param_tool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UVR_MotionControllerComponent::execServer_SetRelativeTransform)
	{
		P_GET_STRUCT(FTransform,Z_Param_transform);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Server_SetRelativeTransform_Implementation(Z_Param_transform);
		P_NATIVE_END;
	}
	struct VR_MotionControllerComponent_eventServer_AddTool_Parms
	{
		AActor* tool;
	};
	struct VR_MotionControllerComponent_eventServer_AddToolByClass_Parms
	{
		TSubclassOf<AActor>  toolClass;
	};
	struct VR_MotionControllerComponent_eventServer_RemoveTool_Parms
	{
		AActor* tool;
	};
	struct VR_MotionControllerComponent_eventServer_SetRelativeTransform_Parms
	{
		FTransform transform;
	};
	struct VR_MotionControllerComponent_eventServer_SetToolsVisibility_Parms
	{
		bool bVisibleArg;
	};
	static FName NAME_UVR_MotionControllerComponent_Server_AddTool = FName(TEXT("Server_AddTool"));
	void UVR_MotionControllerComponent::Server_AddTool(AActor* tool)
	{
		VR_MotionControllerComponent_eventServer_AddTool_Parms Parms;
		Parms.tool=tool;
		ProcessEvent(FindFunctionChecked(NAME_UVR_MotionControllerComponent_Server_AddTool),&Parms);
	}
	static FName NAME_UVR_MotionControllerComponent_Server_AddToolByClass = FName(TEXT("Server_AddToolByClass"));
	void UVR_MotionControllerComponent::Server_AddToolByClass(TSubclassOf<AActor>  toolClass)
	{
		VR_MotionControllerComponent_eventServer_AddToolByClass_Parms Parms;
		Parms.toolClass=toolClass;
		ProcessEvent(FindFunctionChecked(NAME_UVR_MotionControllerComponent_Server_AddToolByClass),&Parms);
	}
	static FName NAME_UVR_MotionControllerComponent_Server_RemoveAllTools = FName(TEXT("Server_RemoveAllTools"));
	void UVR_MotionControllerComponent::Server_RemoveAllTools()
	{
		ProcessEvent(FindFunctionChecked(NAME_UVR_MotionControllerComponent_Server_RemoveAllTools),NULL);
	}
	static FName NAME_UVR_MotionControllerComponent_Server_RemoveTool = FName(TEXT("Server_RemoveTool"));
	void UVR_MotionControllerComponent::Server_RemoveTool(AActor* tool)
	{
		VR_MotionControllerComponent_eventServer_RemoveTool_Parms Parms;
		Parms.tool=tool;
		ProcessEvent(FindFunctionChecked(NAME_UVR_MotionControllerComponent_Server_RemoveTool),&Parms);
	}
	static FName NAME_UVR_MotionControllerComponent_Server_SetRelativeTransform = FName(TEXT("Server_SetRelativeTransform"));
	void UVR_MotionControllerComponent::Server_SetRelativeTransform(FTransform const& transform)
	{
		VR_MotionControllerComponent_eventServer_SetRelativeTransform_Parms Parms;
		Parms.transform=transform;
		ProcessEvent(FindFunctionChecked(NAME_UVR_MotionControllerComponent_Server_SetRelativeTransform),&Parms);
	}
	static FName NAME_UVR_MotionControllerComponent_Server_SetToolsVisibility = FName(TEXT("Server_SetToolsVisibility"));
	void UVR_MotionControllerComponent::Server_SetToolsVisibility(bool bVisibleArg)
	{
		VR_MotionControllerComponent_eventServer_SetToolsVisibility_Parms Parms;
		Parms.bVisibleArg=bVisibleArg ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_UVR_MotionControllerComponent_Server_SetToolsVisibility),&Parms);
	}
	void UVR_MotionControllerComponent::StaticRegisterNativesUVR_MotionControllerComponent()
	{
		UClass* Class = UVR_MotionControllerComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddTool", &UVR_MotionControllerComponent::execAddTool },
			{ "AddToolByClass", &UVR_MotionControllerComponent::execAddToolByClass },
			{ "GetInputToolStackTop", &UVR_MotionControllerComponent::execGetInputToolStackTop },
			{ "HandleHardwareInterfaceModeChanged", &UVR_MotionControllerComponent::execHandleHardwareInterfaceModeChanged },
			{ "HandleInputAction", &UVR_MotionControllerComponent::execHandleInputAction },
			{ "HasTool", &UVR_MotionControllerComponent::execHasTool },
			{ "OnRep_InputToolStackTop", &UVR_MotionControllerComponent::execOnRep_InputToolStackTop },
			{ "OnRep_RelativeTransform", &UVR_MotionControllerComponent::execOnRep_RelativeTransform },
			{ "RemoveAllTools", &UVR_MotionControllerComponent::execRemoveAllTools },
			{ "RemoveTool", &UVR_MotionControllerComponent::execRemoveTool },
			{ "Server_AddTool", &UVR_MotionControllerComponent::execServer_AddTool },
			{ "Server_AddToolByClass", &UVR_MotionControllerComponent::execServer_AddToolByClass },
			{ "Server_RemoveAllTools", &UVR_MotionControllerComponent::execServer_RemoveAllTools },
			{ "Server_RemoveTool", &UVR_MotionControllerComponent::execServer_RemoveTool },
			{ "Server_SetRelativeTransform", &UVR_MotionControllerComponent::execServer_SetRelativeTransform },
			{ "Server_SetToolsVisibility", &UVR_MotionControllerComponent::execServer_SetToolsVisibility },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics
	{
		struct VR_MotionControllerComponent_eventAddTool_Parms
		{
			AActor* tool;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tool;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::NewProp_tool = { "tool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventAddTool_Parms, tool), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::NewProp_tool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Adds specified tool to InputToolStack.  RPC's to server when called without authority.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Adds specified tool to InputToolStack.  RPC's to server when called without authority." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "AddTool", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::VR_MotionControllerComponent_eventAddTool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::VR_MotionControllerComponent_eventAddTool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics
	{
		struct VR_MotionControllerComponent_eventAddToolByClass_Parms
		{
			TSubclassOf<AActor>  toolClass;
		};
		static const UECodeGen_Private::FClassPropertyParams NewProp_toolClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::NewProp_toolClass = { "toolClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventAddToolByClass_Parms, toolClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::NewProp_toolClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Spawns actor via toolClass, then adds actor to InputToolStack.  RPC's to server when called without authority.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Spawns actor via toolClass, then adds actor to InputToolStack.  RPC's to server when called without authority." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "AddToolByClass", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::VR_MotionControllerComponent_eventAddToolByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::VR_MotionControllerComponent_eventAddToolByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics
	{
		struct VR_MotionControllerComponent_eventGetInputToolStackTop_Parms
		{
			AActor* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventGetInputToolStackTop_Parms, ReturnValue), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* \n\x09* \\brief Returns top of InputToolStack. This actor receives input.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Returns top of InputToolStack. This actor receives input." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "GetInputToolStackTop", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::VR_MotionControllerComponent_eventGetInputToolStackTop_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::VR_MotionControllerComponent_eventGetInputToolStackTop_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics
	{
		struct VR_MotionControllerComponent_eventHandleHardwareInterfaceModeChanged_Parms
		{
			EHardwareInterfaceMode newMode;
			EHardwareInterfaceMode previousMode;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_newMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_newMode;
		static const UECodeGen_Private::FBytePropertyParams NewProp_previousMode_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_previousMode;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode = { "newMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventHandleHardwareInterfaceModeChanged_Parms, newMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode = { "previousMode", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventHandleHardwareInterfaceModeChanged_Parms, previousMode), Z_Construct_UEnum_VH_Developer_EHardwareInterfaceMode, METADATA_PARAMS(0, nullptr) }; // 2688149405
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_newMode,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::NewProp_previousMode,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "HandleHardwareInterfaceModeChanged", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::VR_MotionControllerComponent_eventHandleHardwareInterfaceModeChanged_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::VR_MotionControllerComponent_eventHandleHardwareInterfaceModeChanged_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics
	{
		struct VR_MotionControllerComponent_eventHandleInputAction_Parms
		{
			FInputActionInstance inputActionInstance;
		};
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::NewProp_inputActionInstance_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::NewProp_inputActionInstance = { "inputActionInstance", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventHandleInputAction_Parms, inputActionInstance), Z_Construct_UScriptStruct_FInputActionInstance, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::NewProp_inputActionInstance_MetaData), Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::NewProp_inputActionInstance_MetaData) }; // 2153033866
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::NewProp_inputActionInstance,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "HandleInputAction", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::VR_MotionControllerComponent_eventHandleInputAction_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00440401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::VR_MotionControllerComponent_eventHandleInputAction_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics
	{
		struct VR_MotionControllerComponent_eventHasTool_Parms
		{
			AActor* toolToFind;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_toolToFind;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::NewProp_toolToFind = { "toolToFind", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventHasTool_Parms, toolToFind), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((VR_MotionControllerComponent_eventHasTool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VR_MotionControllerComponent_eventHasTool_Parms), &Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::NewProp_toolToFind,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "HasTool", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::VR_MotionControllerComponent_eventHasTool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::VR_MotionControllerComponent_eventHasTool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "OnRep_InputToolStackTop", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "OnRep_RelativeTransform", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Removes all tools from InputToolStack.  RPC's to server when called without authority.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Removes all tools from InputToolStack.  RPC's to server when called without authority." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "RemoveAllTools", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics
	{
		struct VR_MotionControllerComponent_eventRemoveTool_Parms
		{
			AActor* tool;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tool;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::NewProp_tool = { "tool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventRemoveTool_Parms, tool), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::NewProp_tool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/*\n\x09* \\brief Removes specified tool from InputToolStack.  RPC's to server when called without authority.\n\x09*/" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "* \\brief Removes specified tool from InputToolStack.  RPC's to server when called without authority." },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "RemoveTool", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::PropPointers), sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::VR_MotionControllerComponent_eventRemoveTool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::VR_MotionControllerComponent_eventRemoveTool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tool;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::NewProp_tool = { "tool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventServer_AddTool_Parms, tool), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::NewProp_tool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "Server_AddTool", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::PropPointers), sizeof(VR_MotionControllerComponent_eventServer_AddTool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::PropPointers) < 2048);
	static_assert(sizeof(VR_MotionControllerComponent_eventServer_AddTool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics
	{
		static const UECodeGen_Private::FClassPropertyParams NewProp_toolClass;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::NewProp_toolClass = { "toolClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventServer_AddToolByClass_Parms, toolClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::NewProp_toolClass,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "Server_AddToolByClass", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::PropPointers), sizeof(VR_MotionControllerComponent_eventServer_AddToolByClass_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::PropPointers) < 2048);
	static_assert(sizeof(VR_MotionControllerComponent_eventServer_AddToolByClass_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "Server_RemoveAllTools", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics
	{
		static const UECodeGen_Private::FObjectPropertyParams NewProp_tool;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::NewProp_tool = { "tool", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventServer_RemoveTool_Parms, tool), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::NewProp_tool,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "Server_RemoveTool", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::PropPointers), sizeof(VR_MotionControllerComponent_eventServer_RemoveTool_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::PropPointers) < 2048);
	static_assert(sizeof(VR_MotionControllerComponent_eventServer_RemoveTool_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_transform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_transform;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::NewProp_transform_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::NewProp_transform = { "transform", nullptr, (EPropertyFlags)0x0010000008000082, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(VR_MotionControllerComponent_eventServer_SetRelativeTransform_Parms, transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::NewProp_transform_MetaData), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::NewProp_transform_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::NewProp_transform,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "Server_SetRelativeTransform", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::PropPointers), sizeof(VR_MotionControllerComponent_eventServer_SetRelativeTransform_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00A40C41, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::PropPointers) < 2048);
	static_assert(sizeof(VR_MotionControllerComponent_eventServer_SetRelativeTransform_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics
	{
		static void NewProp_bVisibleArg_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVisibleArg;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::NewProp_bVisibleArg_SetBit(void* Obj)
	{
		((VR_MotionControllerComponent_eventServer_SetToolsVisibility_Parms*)Obj)->bVisibleArg = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::NewProp_bVisibleArg = { "bVisibleArg", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(VR_MotionControllerComponent_eventServer_SetToolsVisibility_Parms), &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::NewProp_bVisibleArg_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::NewProp_bVisibleArg,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UVR_MotionControllerComponent, nullptr, "Server_SetToolsVisibility", nullptr, nullptr, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::PropPointers), sizeof(VR_MotionControllerComponent_eventServer_SetToolsVisibility_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00240CC1, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::Function_MetaDataParams), Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::PropPointers) < 2048);
	static_assert(sizeof(VR_MotionControllerComponent_eventServer_SetToolsVisibility_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UVR_MotionControllerComponent);
	UClass* Z_Construct_UClass_UVR_MotionControllerComponent_NoRegister()
	{
		return UVR_MotionControllerComponent::StaticClass();
	}
	struct Z_Construct_UClass_UVR_MotionControllerComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnInputStackTopChanged_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnInputStackTopChanged;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputActions_ElementProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputActions_MetaData[];
#endif
		static const UECodeGen_Private::FSetPropertyParams NewProp_InputActions;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_VREmulationRelativeLocation_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_VREmulationRelativeLocation;
		static const UECodeGen_Private::FBytePropertyParams NewProp_NonVRCollisionChannels_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NonVRCollisionChannels_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_NonVRCollisionChannels;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RelativeTransform_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RelativeTransform;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputToolStack_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputToolStack_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InputToolStack;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputToolStackTop_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputToolStackTop;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InputComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UVR_MotionControllerComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UMotionControllerComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_VH_VR,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UVR_MotionControllerComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_AddTool, "AddTool" }, // 3061093738
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_AddToolByClass, "AddToolByClass" }, // 4047899770
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_GetInputToolStackTop, "GetInputToolStackTop" }, // 1093176074
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_HandleHardwareInterfaceModeChanged, "HandleHardwareInterfaceModeChanged" }, // 937013601
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_HandleInputAction, "HandleInputAction" }, // 517261558
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_HasTool, "HasTool" }, // 1103784757
		{ &Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature, "InputStackTopChanged__DelegateSignature" }, // 266547575
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_InputToolStackTop, "OnRep_InputToolStackTop" }, // 3688746391
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_OnRep_RelativeTransform, "OnRep_RelativeTransform" }, // 2921456397
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveAllTools, "RemoveAllTools" }, // 2234472992
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_RemoveTool, "RemoveTool" }, // 562533318
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddTool, "Server_AddTool" }, // 1775367972
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_AddToolByClass, "Server_AddToolByClass" }, // 3644314773
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveAllTools, "Server_RemoveAllTools" }, // 1588837021
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_RemoveTool, "Server_RemoveTool" }, // 2330487419
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetRelativeTransform, "Server_SetRelativeTransform" }, // 1375775735
		{ &Z_Construct_UFunction_UVR_MotionControllerComponent_Server_SetToolsVisibility, "Server_SetToolsVisibility" }, // 2359121416
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "HideCategories", "Mobility VirtualTexture Trigger" },
		{ "IncludePath", "Components/Public/VR_MotionControllerComponent.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
		{ "ObjectInitializerConstructorDeclared", "" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_OnInputStackTopChanged_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_OnInputStackTopChanged = { "OnInputStackTopChanged", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, OnInputStackTopChanged), Z_Construct_UDelegateFunction_UVR_MotionControllerComponent_InputStackTopChanged__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_OnInputStackTopChanged_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_OnInputStackTopChanged_MetaData) }; // 266547575
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions_ElementProp = { "InputActions", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions_MetaData[] = {
		{ "Category", "VR_MotionControllerComponent" },
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FSetPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions = { "InputActions", nullptr, (EPropertyFlags)0x0010000000010005, UECodeGen_Private::EPropertyGenFlags::Set, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, InputActions), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_VREmulationRelativeLocation_MetaData[] = {
		{ "Category", "VR_MotionControllerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* Relative location to use for VR Emulation */" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Relative location to use for VR Emulation" },
#endif
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_VREmulationRelativeLocation = { "VREmulationRelativeLocation", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, VREmulationRelativeLocation), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_VREmulationRelativeLocation_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_VREmulationRelativeLocation_MetaData) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels_Inner = { "NonVRCollisionChannels", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UEnum_Engine_ECollisionChannel, METADATA_PARAMS(0, nullptr) }; // 1822723181
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels_MetaData[] = {
		{ "Category", "VR_MotionControllerComponent" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* prioritized list of collision channels to trace to find end point for rotation during non-VR */" },
#endif
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "prioritized list of collision channels to trace to find end point for rotation during non-VR" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels = { "NonVRCollisionChannels", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, NonVRCollisionChannels), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels_MetaData) }; // 1822723181
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_RelativeTransform_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_RelativeTransform = { "RelativeTransform", "OnRep_RelativeTransform", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, RelativeTransform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_RelativeTransform_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_RelativeTransform_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack_Inner = { "InputToolStack", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack = { "InputToolStack", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, InputToolStack), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStackTop_MetaData[] = {
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStackTop = { "InputToolStackTop", "OnRep_InputToolStackTop", (EPropertyFlags)0x0040000100000020, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, InputToolStackTop), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStackTop_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStackTop_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Components/Public/VR_MotionControllerComponent.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputComponent = { "InputComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UVR_MotionControllerComponent, InputComponent), Z_Construct_UClass_UInputComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputComponent_MetaData), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UVR_MotionControllerComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_OnInputStackTopChanged,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions_ElementProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputActions,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_VREmulationRelativeLocation,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_NonVRCollisionChannels,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_RelativeTransform,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStack,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputToolStackTop,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UVR_MotionControllerComponent_Statics::NewProp_InputComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UVR_MotionControllerComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UVR_MotionControllerComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UVR_MotionControllerComponent_Statics::ClassParams = {
		&UVR_MotionControllerComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UVR_MotionControllerComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UVR_MotionControllerComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UVR_MotionControllerComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UVR_MotionControllerComponent()
	{
		if (!Z_Registration_Info_UClass_UVR_MotionControllerComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UVR_MotionControllerComponent.OuterSingleton, Z_Construct_UClass_UVR_MotionControllerComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UVR_MotionControllerComponent.OuterSingleton;
	}
	template<> VH_VR_API UClass* StaticClass<UVR_MotionControllerComponent>()
	{
		return UVR_MotionControllerComponent::StaticClass();
	}

	void UVR_MotionControllerComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_RelativeTransform(TEXT("RelativeTransform"));
		static const FName Name_InputToolStackTop(TEXT("InputToolStackTop"));

		const bool bIsValid = true
			&& Name_RelativeTransform == ClassReps[(int32)ENetFields_Private::RelativeTransform].Property->GetFName()
			&& Name_InputToolStackTop == ClassReps[(int32)ENetFields_Private::InputToolStackTop].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UVR_MotionControllerComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UVR_MotionControllerComponent);
	UVR_MotionControllerComponent::~UVR_MotionControllerComponent() {}
	struct Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UVR_MotionControllerComponent, UVR_MotionControllerComponent::StaticClass, TEXT("UVR_MotionControllerComponent"), &Z_Registration_Info_UClass_UVR_MotionControllerComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UVR_MotionControllerComponent), 1180382214U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_1328502150(TEXT("/Script/VH_VR"),
		Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Game_Plugins_VH_VR_Source_VH_VR_Components_Public_VR_MotionControllerComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
