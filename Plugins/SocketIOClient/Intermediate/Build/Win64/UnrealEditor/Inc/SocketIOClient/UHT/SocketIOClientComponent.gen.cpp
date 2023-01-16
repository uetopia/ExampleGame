// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SocketIOClientComponent.h"
#include "Engine/Classes/Engine/LatentActionManager.h"
#include "SocketIOClient/Public/SIOMessageConvert.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIOClientComponent() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonObject_NoRegister();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonValue_NoRegister();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOClientComponent();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOClientComponent_NoRegister();
	SOCKETIOCLIENT_API UEnum* Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason();
	SOCKETIOCLIENT_API UEnum* Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature();
	SOCKETIOCLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FSIOConnectParams();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCEventSignature__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCSocketEventSignature_Parms
		{
			FString Namespace;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCSocketEventSignature_Parms, Namespace), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCSocketEventSignature__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::_Script_SocketIOClient_eventSIOCSocketEventSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCOpenEventSignature_Parms
		{
			FString SocketId;
			FString SessionId;
			bool bIsReconnection;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_SocketId;
		static const UECodeGen_Private::FStrPropertyParams NewProp_SessionId;
		static void NewProp_bIsReconnection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsReconnection;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_SocketId = { "SocketId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms, SocketId), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms, SessionId), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection_SetBit(void* Obj)
	{
		((_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms*)Obj)->bIsReconnection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection = { "bIsReconnection", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms), &Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_SocketId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_SessionId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCOpenEventSignature__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCCloseEventSignature_Parms
		{
			TEnumAsByte<ESIOConnectionCloseReason> Reason;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_Reason;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCCloseEventSignature_Parms, Reason), Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason, METADATA_PARAMS(nullptr, 0) }; // 2130267029
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::NewProp_Reason,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCCloseEventSignature__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::_Script_SocketIOClient_eventSIOCCloseEventSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCEventJsonSignature_Parms
		{
			FString EventName;
			USIOJsonValue* EventData;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EventData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms, EventName), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms, EventData), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_EventData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCEventJsonSignature__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms
		{
			int32 Attempts;
			int32 NextAttemptInMs;
			float TimeSinceConnected;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_Attempts;
		static const UECodeGen_Private::FIntPropertyParams NewProp_NextAttemptInMs;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_TimeSinceConnected;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_Attempts = { "Attempts", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms, Attempts), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_NextAttemptInMs = { "NextAttemptInMs", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms, NextAttemptInMs), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_TimeSinceConnected = { "TimeSinceConnected", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms, TimeSinceConnected), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_Attempts,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_NextAttemptInMs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_TimeSinceConnected,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOConnectionProblemSignature__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOJsonValueSignature_Parms
		{
			USIOJsonValue* EventData;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_EventData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::NewProp_EventData = { "EventData", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOJsonValueSignature_Parms, EventData), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::NewProp_EventData,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//For Direct Delegate Event Bind\n" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "For Direct Delegate Event Bind" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOJsonValueSignature__DelegateSignature", nullptr, nullptr, sizeof(Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::_Script_SocketIOClient_eventSIOJsonValueSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execUnbindEvent)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnbindEvent(Z_Param_EventName,Z_Param_Namespace);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execBindEventToFunction)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_PROPERTY(FStrProperty,Z_Param_FunctionName);
		P_GET_OBJECT(UObject,Z_Param_Target);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_GET_PROPERTY(FByteProperty,Z_Param_ThreadOverride);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BindEventToFunction(Z_Param_EventName,Z_Param_FunctionName,Z_Param_Target,Z_Param_Namespace,ESIOThreadOverrideOption(Z_Param_ThreadOverride),Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execBindEventToGenericEvent)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BindEventToGenericEvent(Z_Param_EventName,Z_Param_Namespace);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execBindEventToDelegate)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_PROPERTY_REF(FDelegateProperty,Z_Param_Out_CallbackDelegate);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_GET_PROPERTY(FByteProperty,Z_Param_ThreadOverride);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BindEventToDelegate(Z_Param_EventName,FSIOJsonValueSignature(Z_Param_Out_CallbackDelegate),Z_Param_Namespace,ESIOThreadOverrideOption(Z_Param_ThreadOverride));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execEmitWithGraphCallBack)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_GET_OBJECT_REF(USIOJsonValue,Z_Param_Out_Result);
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EmitWithGraphCallBack(Z_Param_EventName,Z_Param_LatentInfo,Z_Param_Out_Result,Z_Param_Message,Z_Param_Namespace);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execEmitWithCallBack)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message);
		P_GET_PROPERTY(FStrProperty,Z_Param_CallbackFunctionName);
		P_GET_OBJECT(UObject,Z_Param_Target);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EmitWithCallBack(Z_Param_EventName,Z_Param_Message,Z_Param_CallbackFunctionName,Z_Param_Target,Z_Param_Namespace,Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execEmit)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_EventName);
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message);
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Emit(Z_Param_EventName,Z_Param_Message,Z_Param_Namespace);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execLeaveNamespace)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LeaveNamespace(Z_Param_Namespace);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execJoinNamespace)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Namespace);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinNamespace(Z_Param_Namespace);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execDisconnect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Disconnect();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execConnectWithParams)
	{
		P_GET_STRUCT_REF(FSIOConnectParams,Z_Param_Out_InURLParams);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ConnectWithParams(Z_Param_Out_InURLParams);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOClientComponent::execConnect)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InAddressAndPort);
		P_GET_PROPERTY(FStrProperty,Z_Param_InPath);
		P_GET_PROPERTY(FStrProperty,Z_Param_InAuthToken);
		P_GET_OBJECT(USIOJsonObject,Z_Param_Query);
		P_GET_OBJECT(USIOJsonObject,Z_Param_Headers);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Connect(Z_Param_InAddressAndPort,Z_Param_InPath,Z_Param_InAuthToken,Z_Param_Query,Z_Param_Headers);
		P_NATIVE_END;
	}
	void USocketIOClientComponent::StaticRegisterNativesUSocketIOClientComponent()
	{
		UClass* Class = USocketIOClientComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BindEventToDelegate", &USocketIOClientComponent::execBindEventToDelegate },
			{ "BindEventToFunction", &USocketIOClientComponent::execBindEventToFunction },
			{ "BindEventToGenericEvent", &USocketIOClientComponent::execBindEventToGenericEvent },
			{ "Connect", &USocketIOClientComponent::execConnect },
			{ "ConnectWithParams", &USocketIOClientComponent::execConnectWithParams },
			{ "Disconnect", &USocketIOClientComponent::execDisconnect },
			{ "Emit", &USocketIOClientComponent::execEmit },
			{ "EmitWithCallBack", &USocketIOClientComponent::execEmitWithCallBack },
			{ "EmitWithGraphCallBack", &USocketIOClientComponent::execEmitWithGraphCallBack },
			{ "JoinNamespace", &USocketIOClientComponent::execJoinNamespace },
			{ "LeaveNamespace", &USocketIOClientComponent::execLeaveNamespace },
			{ "UnbindEvent", &USocketIOClientComponent::execUnbindEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics
	{
		struct SocketIOClientComponent_eventBindEventToDelegate_Parms
		{
			FString EventName;
			FScriptDelegate CallbackDelegate;
			FString Namespace;
			TEnumAsByte<ESIOThreadOverrideOption> ThreadOverride;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallbackDelegate_MetaData[];
#endif
		static const UECodeGen_Private::FDelegatePropertyParams NewProp_CallbackDelegate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ThreadOverride;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToDelegate_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_EventName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_CallbackDelegate_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FDelegatePropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_CallbackDelegate = { "CallbackDelegate", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Delegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToDelegate_Parms, CallbackDelegate), Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_CallbackDelegate_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_CallbackDelegate_MetaData)) }; // 1907988879
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToDelegate_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_ThreadOverride = { "ThreadOverride", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToDelegate_Parms, ThreadOverride), Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption, METADATA_PARAMS(nullptr, 0) }; // 2897981721
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_CallbackDelegate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_Namespace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::NewProp_ThreadOverride,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Bind an event directly to a matching delegate. Drag off from red box or\n\x09* use create event option.\n\x09* \n\x09* @param EventName\x09""Event name\n\x09* @param CallbackDelegate Delegate that needs to be bound\n\x09* @param Namespace\x09Optional namespace, defaults to default namespace\n\x09* @param ThreadOverride\x09Optional override to receive event on specified thread. Note NETWORK thread is lower latency but unsafe for a lot of blueprint use. Use with CAUTION.\n\x09*/" },
		{ "CPP_Default_Namespace", "/" },
		{ "CPP_Default_ThreadOverride", "USE_DEFAULT" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Bind an event directly to a matching delegate. Drag off from red box or\nuse create event option.\n\n@param EventName      Event name\n@param CallbackDelegate Delegate that needs to be bound\n@param Namespace      Optional namespace, defaults to default namespace\n@param ThreadOverride Optional override to receive event on specified thread. Note NETWORK thread is lower latency but unsafe for a lot of blueprint use. Use with CAUTION." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "BindEventToDelegate", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::SocketIOClientComponent_eventBindEventToDelegate_Parms), Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics
	{
		struct SocketIOClientComponent_eventBindEventToFunction_Parms
		{
			FString EventName;
			FString FunctionName;
			UObject* Target;
			FString Namespace;
			TEnumAsByte<ESIOThreadOverrideOption> ThreadOverride;
			UObject* WorldContextObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FunctionName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FunctionName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ThreadOverride;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName = { "FunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, FunctionName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_ThreadOverride = { "ThreadOverride", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, ThreadOverride), Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption, METADATA_PARAMS(nullptr, 0) }; // 2897981721
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_ThreadOverride,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Bind an event to a function with the given name.\n\x09* Expects a String message signature which can be decoded from JSON into SIOJsonObject\n\x09*\n\x09* @param EventName\x09\x09""Event name\n\x09* @param FunctionName\x09The function that gets called when the event is received\n\x09* @param Target\x09\x09\x09Optional, defaults to caller self. Change to delegate to another class.\n\x09* @param Namespace\x09\x09Optional namespace, defaults to default namespace\n\x09* @param ThreadOverride\x09Optional override to receive event on specified thread. Note NETWORK thread is lower latency but unsafe for a lot of blueprint use. Use with CAUTION.\n\x09*/" },
		{ "CPP_Default_Namespace", "/" },
		{ "CPP_Default_ThreadOverride", "USE_DEFAULT" },
		{ "CPP_Default_WorldContextObject", "None" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Bind an event to a function with the given name.\nExpects a String message signature which can be decoded from JSON into SIOJsonObject\n\n@param EventName              Event name\n@param FunctionName   The function that gets called when the event is received\n@param Target                 Optional, defaults to caller self. Change to delegate to another class.\n@param Namespace              Optional namespace, defaults to default namespace\n@param ThreadOverride Optional override to receive event on specified thread. Note NETWORK thread is lower latency but unsafe for a lot of blueprint use. Use with CAUTION." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "BindEventToFunction", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::SocketIOClientComponent_eventBindEventToFunction_Parms), Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics
	{
		struct SocketIOClientComponent_eventBindEventToGenericEvent_Parms
		{
			FString EventName;
			FString Namespace;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToGenericEvent_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_EventName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToGenericEvent_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Bind an event, then respond to it with 'OnGenericEvent' multi-cast delegate.\n\x09* If you want functions or custom events to receive the event, use Bind Event To Function.\n\x09*\n\x09* @param EventName\x09""Event name\n\x09* @param Namespace\x09Optional namespace, defaults to default namespace\n\x09*/" },
		{ "CPP_Default_Namespace", "/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Bind an event, then respond to it with 'OnGenericEvent' multi-cast delegate.\nIf you want functions or custom events to receive the event, use Bind Event To Function.\n\n@param EventName      Event name\n@param Namespace      Optional namespace, defaults to default namespace" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "BindEventToGenericEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::SocketIOClientComponent_eventBindEventToGenericEvent_Parms), Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics
	{
		struct SocketIOClientComponent_eventConnect_Parms
		{
			FString InAddressAndPort;
			FString InPath;
			FString InAuthToken;
			USIOJsonObject* Query;
			USIOJsonObject* Headers;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InAddressAndPort_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_InAddressAndPort;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InPath_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_InPath;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InAuthToken_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_InAuthToken;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Query;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Headers;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort = { "InAddressAndPort", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, InAddressAndPort), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InPath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InPath = { "InPath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, InPath), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InPath_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InPath_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAuthToken_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAuthToken = { "InAuthToken", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, InAuthToken), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAuthToken_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAuthToken_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Query = { "Query", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, Query), Z_Construct_UClass_USIOJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Headers = { "Headers", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, Headers), Z_Construct_UClass_USIOJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InPath,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAuthToken,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Query,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Headers,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Connect to a socket.io server, optional method if auto-connect is set to true.\n\x09* Query and headers are defined by a {'stringKey':'stringValue'} SIOJson Object\n\x09*\n\x09* @param AddressAndPort\x09the address in URL format with port, if left empty it will\n\x09*\x09\x09\x09\x09\x09\x09use current URLParams for all inputs.\n\x09* @param Path optional ws:// trailing path for socket.io connection\n\x09* @param Query http query as a SIOJsonObject with string keys and values\n\x09* @param Headers http header as a SIOJsonObject with string keys and values\n\x09* @param Auth socket.io authorization option as a SIOJsonObject with string keys and values\n\x09*\n\x09*/" },
		{ "CPP_Default_Headers", "None" },
		{ "CPP_Default_InAddressAndPort", "" },
		{ "CPP_Default_InAuthToken", "" },
		{ "CPP_Default_InPath", "socket.io" },
		{ "CPP_Default_Query", "None" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Connect to a socket.io server, optional method if auto-connect is set to true.\nQuery and headers are defined by a {'stringKey':'stringValue'} SIOJson Object\n\n@param AddressAndPort the address in URL format with port, if left empty it will\n                                              use current URLParams for all inputs.\n@param Path optional ws:// trailing path for socket.io connection\n@param Query http query as a SIOJsonObject with string keys and values\n@param Headers http header as a SIOJsonObject with string keys and values\n@param Auth socket.io authorization option as a SIOJsonObject with string keys and values" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "Connect", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::SocketIOClientComponent_eventConnect_Parms), Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_Connect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics
	{
		struct SocketIOClientComponent_eventConnectWithParams_Parms
		{
			FSIOConnectParams InURLParams;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InURLParams_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_InURLParams;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::NewProp_InURLParams_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::NewProp_InURLParams = { "InURLParams", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventConnectWithParams_Parms, InURLParams), Z_Construct_UScriptStruct_FSIOConnectParams, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::NewProp_InURLParams_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::NewProp_InURLParams_MetaData)) }; // 1720379169
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::NewProp_InURLParams,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Connect to a socket.io server, optional method if auto-connect is set to true.\n\x09*\n\x09* @param InURLParams - A struct holding address&port, path, headers, query, and auth params\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Connect to a socket.io server, optional method if auto-connect is set to true.\n\n@param InURLParams - A struct holding address&port, path, headers, query, and auth params" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "ConnectWithParams", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::SocketIOClientComponent_eventConnectWithParams_Parms), Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Disconnect from current socket.io server. This is an asynchronous action,\n\x09* subscribe to OnDisconnected to know when you can safely continue from a \n\x09* disconnected state.\n\x09*\n\x09* @param AddressAndPort\x09the address in URL format with port\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Disconnect from current socket.io server. This is an asynchronous action,\nsubscribe to OnDisconnected to know when you can safely continue from a\ndisconnected state.\n\n@param AddressAndPort the address in URL format with port" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "Disconnect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_Disconnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics
	{
		struct SocketIOClientComponent_eventEmit_Parms
		{
			FString EventName;
			USIOJsonValue* Message;
			FString Namespace;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Message;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmit_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmit_Parms, Message), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmit_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Emit an event with a JsonValue message\n\x09*\n\x09* @param Name\x09\x09""Event name\n\x09* @param Message\x09SIOJJsonValue\n\x09* @param Namespace\x09Namespace within socket.io\n\x09*/" },
		{ "CPP_Default_Message", "None" },
		{ "CPP_Default_Namespace", "/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Emit an event with a JsonValue message\n\n@param Name           Event name\n@param Message        SIOJJsonValue\n@param Namespace      Namespace within socket.io" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "Emit", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::SocketIOClientComponent_eventEmit_Parms), Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_Emit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics
	{
		struct SocketIOClientComponent_eventEmitWithCallBack_Parms
		{
			FString EventName;
			USIOJsonValue* Message;
			FString CallbackFunctionName;
			UObject* Target;
			FString Namespace;
			UObject* WorldContextObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Message;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CallbackFunctionName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_CallbackFunctionName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, Message), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName = { "CallbackFunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, CallbackFunctionName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Emit an event with a JsonValue message with a callback function defined by CallBackFunctionName\n\x09*\n\x09* @param Name\x09\x09\x09\x09\x09""Event name\n\x09* @param Message\x09\x09\x09\x09SIOJsonValue\n\x09* @param CallbackFunctionName\x09Name of the optional callback function with signature (String, SIOJsonValue)\n\x09* @param Target\x09\x09\x09\x09\x09Optional, defaults to caller self. Change to delegate function callback to another class.\n\x09* @param Namespace\x09\x09\x09\x09Namespace within socket.io\n\x09*/" },
		{ "CPP_Default_CallbackFunctionName", "" },
		{ "CPP_Default_Message", "None" },
		{ "CPP_Default_Namespace", "/" },
		{ "CPP_Default_Target", "None" },
		{ "CPP_Default_WorldContextObject", "None" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Emit an event with a JsonValue message with a callback function defined by CallBackFunctionName\n\n@param Name                                   Event name\n@param Message                                SIOJsonValue\n@param CallbackFunctionName   Name of the optional callback function with signature (String, SIOJsonValue)\n@param Target                                 Optional, defaults to caller self. Change to delegate function callback to another class.\n@param Namespace                              Namespace within socket.io" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "EmitWithCallBack", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::SocketIOClientComponent_eventEmitWithCallBack_Parms), Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics
	{
		struct SocketIOClientComponent_eventEmitWithGraphCallBack_Parms
		{
			FString EventName;
			FLatentActionInfo LatentInfo;
			USIOJsonValue* Result;
			USIOJsonValue* Message;
			FString Namespace;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Result;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Message;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithGraphCallBack_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_EventName_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithGraphCallBack_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Result = { "Result", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithGraphCallBack_Parms, Result), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithGraphCallBack_Parms, Message), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithGraphCallBack_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_LatentInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Result,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Message,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Emit an event with a JsonValue message with a result callback directly into the event graph. This cannot be called from within blueprint functions.\n\x09*\n\x09* @param Name\x09\x09\x09\x09\x09""Event name\n\x09* @param LatentInfo\x09\x09\x09\x09Graph callback reference\n\x09* @param Result\x09\x09\x09\x09\x09Graph callback result SIOJsonValue\n\x09* @param Message\x09\x09\x09\x09SIOJsonValue\n\x09* @param Namespace\x09\x09\x09\x09Namespace within socket.io\n\x09*/" },
		{ "CPP_Default_Message", "None" },
		{ "CPP_Default_Namespace", "/" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Emit an event with a JsonValue message with a result callback directly into the event graph. This cannot be called from within blueprint functions.\n\n@param Name                                   Event name\n@param LatentInfo                             Graph callback reference\n@param Result                                 Graph callback result SIOJsonValue\n@param Message                                SIOJsonValue\n@param Namespace                              Namespace within socket.io" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "EmitWithGraphCallBack", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::SocketIOClientComponent_eventEmitWithGraphCallBack_Parms), Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics
	{
		struct SocketIOClientComponent_eventJoinNamespace_Parms
		{
			FString Namespace;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventJoinNamespace_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Join a desired namespace. Keep in mind that emitting to a namespace will auto-join it\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Join a desired namespace. Keep in mind that emitting to a namespace will auto-join it" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "JoinNamespace", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::SocketIOClientComponent_eventJoinNamespace_Parms), Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics
	{
		struct SocketIOClientComponent_eventLeaveNamespace_Parms
		{
			FString Namespace;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventLeaveNamespace_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/** \n\x09* Leave a specified namespace. Should stop listening to events on given namespace.\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Leave a specified namespace. Should stop listening to events on given namespace." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "LeaveNamespace", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::SocketIOClientComponent_eventLeaveNamespace_Parms), Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics
	{
		struct SocketIOClientComponent_eventUnbindEvent_Parms
		{
			FString EventName;
			FString Namespace;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_EventName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventUnbindEvent_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_EventName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_EventName_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOClientComponent_eventUnbindEvent_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_Namespace_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_Namespace_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_EventName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "Comment", "/**\n\x09* Unbind an event from whatever it was bound to (safe to call if not already bound)\n\x09*\n\x09* @param EventName\x09""Event name\n\x09* @param Namespace\x09Optional namespace, defaults to default namespace\n\x09*/" },
		{ "CPP_Default_Namespace", "/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Unbind an event from whatever it was bound to (safe to call if not already bound)\n\n@param EventName      Event name\n@param Namespace      Optional namespace, defaults to default namespace" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "UnbindEvent", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::SocketIOClientComponent_eventUnbindEvent_Parms), Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USocketIOClientComponent);
	UClass* Z_Construct_UClass_USocketIOClientComponent_NoRegister()
	{
		return USocketIOClientComponent::StaticClass();
	}
	struct Z_Construct_UClass_USocketIOClientComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnGenericEvent_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnGenericEvent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnConnected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnDisconnected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDisconnected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnConnectionProblems_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectionProblems;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSocketNamespaceConnected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocketNamespaceConnected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSocketNamespaceDisconnected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocketNamespaceDisconnected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnFail_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFail;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_URLParams_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_URLParams;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bForceTLS_MetaData[];
#endif
		static void NewProp_bForceTLS_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bForceTLS;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bUnbindEventsOnDisconnect_MetaData[];
#endif
		static void NewProp_bUnbindEventsOnDisconnect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bUnbindEventsOnDisconnect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShouldVerifyTLSCertificate_MetaData[];
#endif
		static void NewProp_bShouldVerifyTLSCertificate_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldVerifyTLSCertificate;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShouldAutoConnect_MetaData[];
#endif
		static void NewProp_bShouldAutoConnect_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldAutoConnect;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReconnectionDelayInMs_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReconnectionDelayInMs;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxReconnectionAttempts_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_MaxReconnectionAttempts;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReconnectionTimeout_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReconnectionTimeout;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bVerboseConnectionLog_MetaData[];
#endif
		static void NewProp_bVerboseConnectionLog_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bVerboseConnectionLog;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bLimitConnectionToGameWorld_MetaData[];
#endif
		static void NewProp_bLimitConnectionToGameWorld_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bLimitConnectionToGameWorld;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPluginScopedConnection_MetaData[];
#endif
		static void NewProp_bPluginScopedConnection_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPluginScopedConnection;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PluginScopedId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_PluginScopedId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsConnected_MetaData[];
#endif
		static void NewProp_bIsConnected_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsConnected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SessionId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SocketId_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_SocketId;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsHavingConnectionProblems_MetaData[];
#endif
		static void NewProp_bIsHavingConnectionProblems_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsHavingConnectionProblems;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bStaticallyInitialized_MetaData[];
#endif
		static void NewProp_bStaticallyInitialized_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bStaticallyInitialized;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USocketIOClientComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketIOClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USocketIOClientComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USocketIOClientComponent_BindEventToDelegate, "BindEventToDelegate" }, // 3181325235
		{ &Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction, "BindEventToFunction" }, // 2093544288
		{ &Z_Construct_UFunction_USocketIOClientComponent_BindEventToGenericEvent, "BindEventToGenericEvent" }, // 3675786843
		{ &Z_Construct_UFunction_USocketIOClientComponent_Connect, "Connect" }, // 449687511
		{ &Z_Construct_UFunction_USocketIOClientComponent_ConnectWithParams, "ConnectWithParams" }, // 676291593
		{ &Z_Construct_UFunction_USocketIOClientComponent_Disconnect, "Disconnect" }, // 4099314219
		{ &Z_Construct_UFunction_USocketIOClientComponent_Emit, "Emit" }, // 240302504
		{ &Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack, "EmitWithCallBack" }, // 2161907899
		{ &Z_Construct_UFunction_USocketIOClientComponent_EmitWithGraphCallBack, "EmitWithGraphCallBack" }, // 1079050863
		{ &Z_Construct_UFunction_USocketIOClientComponent_JoinNamespace, "JoinNamespace" }, // 2449080365
		{ &Z_Construct_UFunction_USocketIOClientComponent_LeaveNamespace, "LeaveNamespace" }, // 546239798
		{ &Z_Construct_UFunction_USocketIOClientComponent_UnbindEvent, "UnbindEvent" }, // 394374347
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "BlueprintType", "true" },
		{ "ClassGroupNames", "Networking" },
		{ "IncludePath", "SocketIOClientComponent.h" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnGenericEvent_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** On generic bound event received. Requires Bind Event to Generic Event to be called before. Will not receive Bind Event To Function events. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "On generic bound event received. Requires Bind Event to Generic Event to be called before. Will not receive Bind Event To Function events." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnGenericEvent = { "OnGenericEvent", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnGenericEvent), Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnGenericEvent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnGenericEvent_MetaData)) }; // 104895173
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** Received on socket.io connection established. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on socket.io connection established." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected = { "OnConnected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnConnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected_MetaData)) }; // 2926940331
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** \n\x09* Received on socket.io connection disconnected. This may never get \n\x09* called in default settings, see OnConnectionProblems event for details. \n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on socket.io connection disconnected. This may never get\ncalled in default settings, see OnConnectionProblems event for details." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected = { "OnDisconnected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnDisconnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected_MetaData)) }; // 667357992
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** \n\x09* Received when connection problems arise. In default settings the\n\x09* connection will keep repeating trying to reconnect an infinite\n\x09* amount of times and you may never get OnDisconnected callback\n\x09* unless you call it.\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received when connection problems arise. In default settings the\nconnection will keep repeating trying to reconnect an infinite\namount of times and you may never get OnDisconnected callback\nunless you call it." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems = { "OnConnectionProblems", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnConnectionProblems), Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems_MetaData)) }; // 2900652617
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** Received on having joined namespace. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on having joined namespace." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected = { "OnSocketNamespaceConnected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnSocketNamespaceConnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected_MetaData)) }; // 2221852564
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** Received on having left namespace. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on having left namespace." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected = { "OnSocketNamespaceDisconnected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnSocketNamespaceDisconnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected_MetaData)) }; // 2221852564
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "Comment", "/** Received on connection failure. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on connection failure." },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail = { "OnFail", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, OnFail), Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail_MetaData)) }; // 3015707012
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_URLParams_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/**\n\x09* Default connection params used on e.g. on begin play. Can be updated and re-used on custom connection.\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Default connection params used on e.g. on begin play. Can be updated and re-used on custom connection." },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_URLParams = { "URLParams", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, URLParams), Z_Construct_UScriptStruct_FSIOConnectParams, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_URLParams_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_URLParams_MetaData)) }; // 1720379169
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/**\n\x09* Will force using TLS even if url doesn't have https:// prepend.\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Will force using TLS even if url doesn't have https:// prepend." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bForceTLS = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS = { "bForceTLS", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/**\n\x09* If true, all your bound events will unbind on disconnect. \n\x09* Useful for cleanup if typically binding on connection and there\n\x09* are no early event binds (before connection).\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If true, all your bound events will unbind on disconnect.\nUseful for cleanup if typically binding on connection and there\nare no early event binds (before connection)." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bUnbindEventsOnDisconnect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect = { "bUnbindEventsOnDisconnect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/**\n\x09* If using a TLS url (or if forced) and setting this to false will not verify \n\x09* the authenticity of the SSL certificate (i.e. asio::ssl::verify_none).\n\x09* \n\x09* NOTE: Certification verification is currently not implemented; setting to true will\n\x09* always fail verification.\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If using a TLS url (or if forced) and setting this to false will not verify\nthe authenticity of the SSL certificate (i.e. asio::ssl::verify_none).\n\nNOTE: Certification verification is currently not implemented; setting to true will\nalways fail verification." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bShouldVerifyTLSCertificate = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate = { "bShouldVerifyTLSCertificate", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/** If true will auto-connect on begin play to address specified in AddressAndPort. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If true will auto-connect on begin play to address specified in AddressAndPort." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bShouldAutoConnect = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect = { "bShouldAutoConnect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/** Delay between reconnection attempts */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Delay between reconnection attempts" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs = { "ReconnectionDelayInMs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, ReconnectionDelayInMs), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/**\n\x09* Number of times the connection should try before giving up.\n\x09* Default: infinity, this means you never truly disconnect, just suffer connection problems \n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Number of times the connection should try before giving up.\nDefault: infinity, this means you never truly disconnect, just suffer connection problems" },
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts = { "MaxReconnectionAttempts", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, MaxReconnectionAttempts), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/** Optional parameter to limit reconnections by elapsed time. Default: infinity. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Optional parameter to limit reconnections by elapsed time. Default: infinity." },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout = { "ReconnectionTimeout", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, ReconnectionTimeout), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bVerboseConnectionLog = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog = { "bVerboseConnectionLog", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_MetaData[] = {
		{ "Category", "SocketIO Scope Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bLimitConnectionToGameWorld = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld = { "bLimitConnectionToGameWorld", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_MetaData[] = {
		{ "Category", "SocketIO Scope Properties" },
		{ "Comment", "/** \n\x09* Toggle which enables plugin scoped connections. \n\x09* If you enable this the connection will remain until you manually call disconnect\n\x09* or close the app. The latest connection with the same PluginScopedId will use the same connection\n\x09* as the previous one and receive the same events.\n\x09*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Toggle which enables plugin scoped connections.\nIf you enable this the connection will remain until you manually call disconnect\nor close the app. The latest connection with the same PluginScopedId will use the same connection\nas the previous one and receive the same events." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bPluginScopedConnection = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection = { "bPluginScopedConnection", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId_MetaData[] = {
		{ "Category", "SocketIO Scope Properties" },
		{ "Comment", "/** If you leave this as is all plugin scoped connection components will share same connection*/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If you leave this as is all plugin scoped connection components will share same connection" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId = { "PluginScopedId", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, PluginScopedId), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bIsConnected = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected = { "bIsConnected", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/** When connected this session id will be valid and contain a unique Id. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "When connected this session id will be valid and contain a unique Id." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, SessionId), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SocketId_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/** Each new connection is assigned a random 20-characters identifier. This identifier is synced with the value on the client-side. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Each new connection is assigned a random 20-characters identifier. This identifier is synced with the value on the client-side." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SocketId = { "SocketId", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USocketIOClientComponent, SocketId), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SocketId_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SocketId_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bIsHavingConnectionProblems = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems = { "bIsHavingConnectionProblems", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "Comment", "/** If this component has been statically initialized. Largely exposed for traceability. */" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If this component has been statically initialized. Largely exposed for traceability." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bStaticallyInitialized = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized = { "bStaticallyInitialized", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USocketIOClientComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnGenericEvent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_URLParams,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bForceTLS,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bUnbindEventsOnDisconnect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldVerifyTLSCertificate,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SocketId,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bStaticallyInitialized,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USocketIOClientComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USocketIOClientComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USocketIOClientComponent_Statics::ClassParams = {
		&USocketIOClientComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USocketIOClientComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USocketIOClientComponent()
	{
		if (!Z_Registration_Info_UClass_USocketIOClientComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USocketIOClientComponent.OuterSingleton, Z_Construct_UClass_USocketIOClientComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USocketIOClientComponent.OuterSingleton;
	}
	template<> SOCKETIOCLIENT_API UClass* StaticClass<USocketIOClientComponent>()
	{
		return USocketIOClientComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USocketIOClientComponent);
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USocketIOClientComponent, USocketIOClientComponent::StaticClass, TEXT("USocketIOClientComponent"), &Z_Registration_Info_UClass_USocketIOClientComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USocketIOClientComponent), 3398515149U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_2743642920(TEXT("/Script/SocketIOClient"),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
