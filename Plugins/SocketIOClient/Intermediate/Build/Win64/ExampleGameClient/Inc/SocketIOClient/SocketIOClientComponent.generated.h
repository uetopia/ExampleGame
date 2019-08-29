// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USIOJsonValue;
class UObject;
class USIOJsonObject;
#ifdef SOCKETIOCLIENT_SocketIOClientComponent_generated_h
#error "SocketIOClientComponent.generated.h already included, missing '#pragma once' in SocketIOClientComponent.h"
#endif
#define SOCKETIOCLIENT_SocketIOClientComponent_generated_h

#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_15_DELEGATE \
struct _Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms \
{ \
	int32 Attempts; \
	int32 NextAttemptInMs; \
	float TimeSinceConnected; \
}; \
static inline void FSIOConnectionProblemSignature_DelegateWrapper(const FMulticastScriptDelegate& SIOConnectionProblemSignature, int32 Attempts, int32 NextAttemptInMs, float TimeSinceConnected) \
{ \
	_Script_SocketIOClient_eventSIOConnectionProblemSignature_Parms Parms; \
	Parms.Attempts=Attempts; \
	Parms.NextAttemptInMs=NextAttemptInMs; \
	Parms.TimeSinceConnected=TimeSinceConnected; \
	SIOConnectionProblemSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_14_DELEGATE \
struct _Script_SocketIOClient_eventSIOCEventJsonSignature_Parms \
{ \
	FString Event; \
	USIOJsonValue* MessageJson; \
}; \
static inline void FSIOCEventJsonSignature_DelegateWrapper(const FMulticastScriptDelegate& SIOCEventJsonSignature, const FString& Event, USIOJsonValue* MessageJson) \
{ \
	_Script_SocketIOClient_eventSIOCEventJsonSignature_Parms Parms; \
	Parms.Event=Event; \
	Parms.MessageJson=MessageJson; \
	SIOCEventJsonSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_13_DELEGATE \
struct _Script_SocketIOClient_eventSIOCCloseEventSignature_Parms \
{ \
	TEnumAsByte<ESIOConnectionCloseReason> Reason; \
}; \
static inline void FSIOCCloseEventSignature_DelegateWrapper(const FMulticastScriptDelegate& SIOCCloseEventSignature, ESIOConnectionCloseReason Reason) \
{ \
	_Script_SocketIOClient_eventSIOCCloseEventSignature_Parms Parms; \
	Parms.Reason=Reason; \
	SIOCCloseEventSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_12_DELEGATE \
struct _Script_SocketIOClient_eventSIOCOpenEventSignature_Parms \
{ \
	FString SessionId; \
	bool bIsReconnection; \
}; \
static inline void FSIOCOpenEventSignature_DelegateWrapper(const FMulticastScriptDelegate& SIOCOpenEventSignature, const FString& SessionId, bool bIsReconnection) \
{ \
	_Script_SocketIOClient_eventSIOCOpenEventSignature_Parms Parms; \
	Parms.SessionId=SessionId; \
	Parms.bIsReconnection=bIsReconnection ? true : false; \
	SIOCOpenEventSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_11_DELEGATE \
struct _Script_SocketIOClient_eventSIOCSocketEventSignature_Parms \
{ \
	FString Namespace; \
}; \
static inline void FSIOCSocketEventSignature_DelegateWrapper(const FMulticastScriptDelegate& SIOCSocketEventSignature, const FString& Namespace) \
{ \
	_Script_SocketIOClient_eventSIOCSocketEventSignature_Parms Parms; \
	Parms.Namespace=Namespace; \
	SIOCSocketEventSignature.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_10_DELEGATE \
static inline void FSIOCEventSignature_DelegateWrapper(const FMulticastScriptDelegate& SIOCEventSignature) \
{ \
	SIOCEventSignature.ProcessMulticastDelegate<UObject>(NULL); \
}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBindEventToFunction) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FunctionName); \
		P_GET_OBJECT(UObject,Z_Param_Target); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEventToFunction(Z_Param_EventName,Z_Param_FunctionName,Z_Param_Target,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBindEvent) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEvent(Z_Param_EventName,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEmitWithCallBack) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message); \
		P_GET_PROPERTY(UStrProperty,Z_Param_CallbackFunctionName); \
		P_GET_OBJECT(UObject,Z_Param_Target); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EmitWithCallBack(Z_Param_EventName,Z_Param_Message,Z_Param_CallbackFunctionName,Z_Param_Target,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEmit) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Emit(Z_Param_EventName,Z_Param_Message,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisconnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Disconnect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InAddressAndPort); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_Query); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_Headers); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Connect(Z_Param_InAddressAndPort,Z_Param_Query,Z_Param_Headers); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBindEventToFunction) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FunctionName); \
		P_GET_OBJECT(UObject,Z_Param_Target); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEventToFunction(Z_Param_EventName,Z_Param_FunctionName,Z_Param_Target,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBindEvent) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->BindEvent(Z_Param_EventName,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEmitWithCallBack) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message); \
		P_GET_PROPERTY(UStrProperty,Z_Param_CallbackFunctionName); \
		P_GET_OBJECT(UObject,Z_Param_Target); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->EmitWithCallBack(Z_Param_EventName,Z_Param_Message,Z_Param_CallbackFunctionName,Z_Param_Target,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEmit) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_EventName); \
		P_GET_OBJECT(USIOJsonValue,Z_Param_Message); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Namespace); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Emit(Z_Param_EventName,Z_Param_Message,Z_Param_Namespace); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDisconnect) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Disconnect(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConnect) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InAddressAndPort); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_Query); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_Headers); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Connect(Z_Param_InAddressAndPort,Z_Param_Query,Z_Param_Headers); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSocketIOClientComponent(); \
	friend struct Z_Construct_UClass_USocketIOClientComponent_Statics; \
public: \
	DECLARE_CLASS(USocketIOClientComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SocketIOClient"), NO_API) \
	DECLARE_SERIALIZER(USocketIOClientComponent)


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUSocketIOClientComponent(); \
	friend struct Z_Construct_UClass_USocketIOClientComponent_Statics; \
public: \
	DECLARE_CLASS(USocketIOClientComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/SocketIOClient"), NO_API) \
	DECLARE_SERIALIZER(USocketIOClientComponent)


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USocketIOClientComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USocketIOClientComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USocketIOClientComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USocketIOClientComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USocketIOClientComponent(USocketIOClientComponent&&); \
	NO_API USocketIOClientComponent(const USocketIOClientComponent&); \
public:


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USocketIOClientComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USocketIOClientComponent(USocketIOClientComponent&&); \
	NO_API USocketIOClientComponent(const USocketIOClientComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USocketIOClientComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USocketIOClientComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USocketIOClientComponent)


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_PRIVATE_PROPERTY_OFFSET
#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_17_PROLOG
#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_RPC_WRAPPERS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_INCLASS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h_20_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SocketIOClientComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOCKETIOCLIENT_API UClass* StaticClass<class USocketIOClientComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOClientComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
