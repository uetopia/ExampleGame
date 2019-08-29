// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SocketIOClientComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIOClientComponent() {}
// Cross Module References
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonValue_NoRegister();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UEnum* Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOClientComponent_NoRegister();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOClientComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEvent();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UFunction_USocketIOClientComponent_Connect();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonObject_NoRegister();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UFunction_USocketIOClientComponent_Disconnect();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UFunction_USocketIOClientComponent_Emit();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms
		{
			int32 Attempts;
			int32 NextAttemptInMs;
			float TimeSinceConnected;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_TimeSinceConnected;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_NextAttemptInMs;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_Attempts;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_TimeSinceConnected = { "TimeSinceConnected", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms, TimeSinceConnected), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_NextAttemptInMs = { "NextAttemptInMs", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms, NextAttemptInMs), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_Attempts = { "Attempts", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms, Attempts), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_TimeSinceConnected,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_NextAttemptInMs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::NewProp_Attempts,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOConnectionProblemSignature__DelegateSignature", sizeof(_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCEventJsonSignature_Parms
		{
			FString Event;
			USIOJsonValue* MessageJson;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MessageJson;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Event;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_MessageJson = { "MessageJson", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms, MessageJson), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_Event = { "Event", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms, Event), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_MessageJson,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::NewProp_Event,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCEventJsonSignature__DelegateSignature", sizeof(_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCCloseEventSignature_Parms
		{
			TEnumAsByte<ESIOConnectionCloseReason> Reason;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Reason;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::NewProp_Reason = { "Reason", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCCloseEventSignature_Parms, Reason), Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::NewProp_Reason,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCCloseEventSignature__DelegateSignature", sizeof(_Script_SocketIOClient_eventSIOCCloseEventSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCOpenEventSignature_Parms
		{
			FString SessionId;
			bool bIsReconnection;
		};
		static void NewProp_bIsReconnection_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsReconnection;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SessionId;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection_SetBit(void* Obj)
	{
		((_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms*)Obj)->bIsReconnection = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection = { "bIsReconnection", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms), &Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms, SessionId), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_bIsReconnection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::NewProp_SessionId,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCOpenEventSignature__DelegateSignature", sizeof(_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics
	{
		struct _Script_SocketIOClient_eventSIOCSocketEventSignature_Parms
		{
			FString Namespace;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_SocketIOClient_eventSIOCSocketEventSignature_Parms, Namespace), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::NewProp_Namespace,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCSocketEventSignature__DelegateSignature", sizeof(_Script_SocketIOClient_eventSIOCSocketEventSignature_Parms), Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient, nullptr, "SIOCEventSignature__DelegateSignature", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	void USocketIOClientComponent::StaticRegisterNativesUSocketIOClientComponent()
	{
		UClass* Class = USocketIOClientComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BindEvent", &USocketIOClientComponent::execBindEvent },
			{ "BindEventToFunction", &USocketIOClientComponent::execBindEventToFunction },
			{ "Connect", &USocketIOClientComponent::execConnect },
			{ "Disconnect", &USocketIOClientComponent::execDisconnect },
			{ "Emit", &USocketIOClientComponent::execEmit },
			{ "EmitWithCallBack", &USocketIOClientComponent::execEmitWithCallBack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics
	{
		struct SocketIOClientComponent_eventBindEvent_Parms
		{
			FString EventName;
			FString Namespace;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Namespace;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventBindEvent_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_Namespace_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_Namespace_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventBindEvent_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_EventName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_EventName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_Namespace,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::NewProp_EventName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "CPP_Default_Namespace", "/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Bind an event, then respond to it with 'On' multi-cast delegate\n\n@param EventName      Event name\n@param Namespace      Optional namespace, defaults to default namespace" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "BindEvent", sizeof(SocketIOClientComponent_eventBindEvent_Parms), Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_BindEvent_Statics::FuncParams);
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
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FunctionName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FunctionName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName = { "FunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, FunctionName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventBindEventToFunction_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Namespace,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_Target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_FunctionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::NewProp_EventName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "CPP_Default_Namespace", "/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Bind an event to a function with the given name.\nExpects a String message signature which can be decoded from JSON into SIOJsonObject\n\n@param EventName              Event name\n@param FunctionName   The function that gets called when the event is received\n@param Target                 Optional, defaults to owner. Change to delegate to another class." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "BindEventToFunction", sizeof(SocketIOClientComponent_eventBindEventToFunction_Parms), Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics
	{
		struct SocketIOClientComponent_eventConnect_Parms
		{
			FString InAddressAndPort;
			USIOJsonObject* Query;
			USIOJsonObject* Headers;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Headers;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Query;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_InAddressAndPort_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_InAddressAndPort;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Headers = { "Headers", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, Headers), Z_Construct_UClass_USIOJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Query = { "Query", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, Query), Z_Construct_UClass_USIOJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort = { "InAddressAndPort", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventConnect_Parms, InAddressAndPort), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Headers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_Query,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::NewProp_InAddressAndPort,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "CPP_Default_Headers", "None" },
		{ "CPP_Default_Query", "None" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Connect to a socket.io server, optional method if auto-connect is set to true.\nQuery and headers are defined by a {'stringKey':'stringValue'} SIOJson Object\n\n@param AddressAndPort the address in URL format with port\n@param Query http query as a SIOJsonObject with string keys and values\n@param Headers http header as a SIOJsonObject with string keys and values" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "Connect", sizeof(SocketIOClientComponent_eventConnect_Parms), Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_Connect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_Connect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Disconnect from current socket.io server. This is an asynchronous action,\nsubscribe to OnDisconnected to know when you can safely continue from a\ndisconnected state.\n\n@param AddressAndPort the address in URL format with port" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "Disconnect", 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_Disconnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_Disconnect_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Message;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmit_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmit_Parms, Message), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmit_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Namespace,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_Message,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::NewProp_EventName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "CPP_Default_Message", "None" },
		{ "CPP_Default_Namespace", "/" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Emit an event with a JsonValue message\n\n@param Name           Event name\n@param Message        SIOJJsonValue\n@param Namespace      Namespace within socket.io" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "Emit", sizeof(SocketIOClientComponent_eventEmit_Parms), Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_Emit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_Emit_Statics::FuncParams);
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
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Namespace_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Namespace;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CallbackFunctionName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CallbackFunctionName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Message;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EventName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_EventName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace = { "Namespace", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, Namespace), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName = { "CallbackFunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, CallbackFunctionName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Message = { "Message", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, Message), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName = { "EventName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(SocketIOClientComponent_eventEmitWithCallBack_Parms, EventName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Namespace,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_CallbackFunctionName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_Message,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::NewProp_EventName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Functions" },
		{ "CPP_Default_CallbackFunctionName", "" },
		{ "CPP_Default_Message", "None" },
		{ "CPP_Default_Namespace", "/" },
		{ "CPP_Default_Target", "None" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Emit an event with a JsonValue message with a callback function defined by CallBackFunctionName\n\n@param Name                                   Event name\n@param Message                                SIOJsonValue\n@param CallbackFunctionName   Name of the optional callback function with signature (String, SIOJsonValue)\n@param Target                                 CallbackFunction target object, typically self where this is called.\n@param Namespace                              Namespace within socket.io" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOClientComponent, nullptr, "EmitWithCallBack", sizeof(SocketIOClientComponent_eventEmitWithCallBack_Parms), Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_USocketIOClientComponent_NoRegister()
	{
		return USocketIOClientComponent::StaticClass();
	}
	struct Z_Construct_UClass_USocketIOClientComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsHavingConnectionProblems_MetaData[];
#endif
		static void NewProp_bIsHavingConnectionProblems_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsHavingConnectionProblems;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SessionId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_SessionId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bIsConnected_MetaData[];
#endif
		static void NewProp_bIsConnected_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bIsConnected;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PluginScopedId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_PluginScopedId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bPluginScopedConnection_MetaData[];
#endif
		static void NewProp_bPluginScopedConnection_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bPluginScopedConnection;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bLimitConnectionToGameWorld_MetaData[];
#endif
		static void NewProp_bLimitConnectionToGameWorld_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bLimitConnectionToGameWorld;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bVerboseConnectionLog_MetaData[];
#endif
		static void NewProp_bVerboseConnectionLog_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bVerboseConnectionLog;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReconnectionTimeout_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReconnectionTimeout;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxReconnectionAttempts_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxReconnectionAttempts;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReconnectionDelayInMs_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReconnectionDelayInMs;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bShouldAutoConnect_MetaData[];
#endif
		static void NewProp_bShouldAutoConnect_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShouldAutoConnect;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AddressAndPort_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AddressAndPort;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnFail_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnFail;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSocketNamespaceDisconnected_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocketNamespaceDisconnected;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnSocketNamespaceConnected_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSocketNamespaceConnected;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConnectionProblems_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectionProblems;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnDisconnected_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnDisconnected;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConnected_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnected;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnEvent_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEvent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USocketIOClientComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketIOClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USocketIOClientComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USocketIOClientComponent_BindEvent, "BindEvent" }, // 3018766862
		{ &Z_Construct_UFunction_USocketIOClientComponent_BindEventToFunction, "BindEventToFunction" }, // 3989394601
		{ &Z_Construct_UFunction_USocketIOClientComponent_Connect, "Connect" }, // 3439124411
		{ &Z_Construct_UFunction_USocketIOClientComponent_Disconnect, "Disconnect" }, // 3274970405
		{ &Z_Construct_UFunction_USocketIOClientComponent_Emit, "Emit" }, // 286537140
		{ &Z_Construct_UFunction_USocketIOClientComponent_EmitWithCallBack, "EmitWithCallBack" }, // 3100077099
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Networking" },
		{ "IncludePath", "SocketIOClientComponent.h" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bIsHavingConnectionProblems = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems = { "bIsHavingConnectionProblems", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "When connected this session id will be valid and contain a unique Id." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId = { "SessionId", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, SessionId), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bIsConnected = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected = { "bIsConnected", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId_MetaData[] = {
		{ "Category", "SocketIO Scope Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If you leave this as is all plugin scoped connection components will share same connection" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId = { "PluginScopedId", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, PluginScopedId), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_MetaData[] = {
		{ "Category", "SocketIO Scope Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Toggle which enables plugin scoped connections.\nIf you enable this the connection will remain until you manually call disconnect\nor close the app. The latest connection with the same PluginScopedId will use the same connection\nas the previous one and receive the same events." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bPluginScopedConnection = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection = { "bPluginScopedConnection", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_MetaData[] = {
		{ "Category", "SocketIO Scope Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bLimitConnectionToGameWorld = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld = { "bLimitConnectionToGameWorld", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bVerboseConnectionLog = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog = { "bVerboseConnectionLog", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Optional parameter to limit reconnections by elapsed time. Default: infinity." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout = { "ReconnectionTimeout", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, ReconnectionTimeout), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Number of times the connection should try before giving up.\nDefault: infinity, this means you never truly disconnect, just suffer connection problems" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts = { "MaxReconnectionAttempts", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, MaxReconnectionAttempts), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Delay between reconnection attempts" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs = { "ReconnectionDelayInMs", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, ReconnectionDelayInMs), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "If true will auto-connect on begin play to address specified in AddressAndPort." },
	};
#endif
	void Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_SetBit(void* Obj)
	{
		((USocketIOClientComponent*)Obj)->bShouldAutoConnect = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect = { "bShouldAutoConnect", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(USocketIOClientComponent), &Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_SetBit, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_AddressAndPort_MetaData[] = {
		{ "Category", "SocketIO Connection Properties" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Default connection address string in form e.g. http://localhost:80." },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_AddressAndPort = { "AddressAndPort", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, AddressAndPort), METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_AddressAndPort_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_AddressAndPort_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on connection failure." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail = { "OnFail", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnFail), Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on having left namespace." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected = { "OnSocketNamespaceDisconnected", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnSocketNamespaceDisconnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on having joined namespace." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected = { "OnSocketNamespaceConnected", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnSocketNamespaceConnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received when connection problems arise. In default settings the\nconnection will keep repeating trying to reconnect an infinite\namount of times and you may never get OnDisconnected callback\nunless you call it." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems = { "OnConnectionProblems", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnConnectionProblems), Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on socket.io connection disconnected. This may never get\ncalled in default settings, see OnConnectionProblems event for details." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected = { "OnDisconnected", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnDisconnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "Received on socket.io connection established." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected = { "OnConnected", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnConnected), Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnEvent_MetaData[] = {
		{ "Category", "SocketIO Events" },
		{ "ModuleRelativePath", "Public/SocketIOClientComponent.h" },
		{ "ToolTip", "On bound event received." },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnEvent = { "OnEvent", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::MulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(USocketIOClientComponent, OnEvent), Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnEvent_MetaData, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnEvent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USocketIOClientComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsHavingConnectionProblems,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_SessionId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bIsConnected,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_PluginScopedId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bPluginScopedConnection,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bLimitConnectionToGameWorld,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bVerboseConnectionLog,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionTimeout,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_MaxReconnectionAttempts,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_ReconnectionDelayInMs,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_bShouldAutoConnect,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_AddressAndPort,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnFail,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceDisconnected,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnSocketNamespaceConnected,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnectionProblems,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnDisconnected,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnConnected,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USocketIOClientComponent_Statics::NewProp_OnEvent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USocketIOClientComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USocketIOClientComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USocketIOClientComponent_Statics::ClassParams = {
		&USocketIOClientComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_USocketIOClientComponent_Statics::PropPointers,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_USocketIOClientComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_USocketIOClientComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USocketIOClientComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USocketIOClientComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USocketIOClientComponent, 403777085);
	template<> SOCKETIOCLIENT_API UClass* StaticClass<USocketIOClientComponent>()
	{
		return USocketIOClientComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USocketIOClientComponent(Z_Construct_UClass_USocketIOClientComponent, &USocketIOClientComponent::StaticClass, TEXT("/Script/SocketIOClient"), TEXT("USocketIOClientComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USocketIOClientComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
