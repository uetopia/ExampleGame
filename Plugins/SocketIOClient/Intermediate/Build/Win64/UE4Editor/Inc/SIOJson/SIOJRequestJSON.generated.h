// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USIOJRequestJSON;
class USIOJsonObject;
class UObject;
struct FLatentActionInfo;
enum class ESIORequestStatus : uint8;
enum class ESIORequestContentType : uint8;
enum class ESIORequestVerb : uint8;
#ifdef SIOJSON_SIOJRequestJSON_generated_h
#error "SIOJRequestJSON.generated.h already included, missing '#pragma once' in SIOJRequestJSON.h"
#endif
#define SIOJSON_SIOJRequestJSON_generated_h

#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_76_DELEGATE \
struct _Script_SIOJson_eventOnRequestFail_Parms \
{ \
	USIOJRequestJSON* Request; \
}; \
static inline void FOnRequestFail_DelegateWrapper(const FMulticastScriptDelegate& OnRequestFail, USIOJRequestJSON* Request) \
{ \
	_Script_SIOJson_eventOnRequestFail_Parms Parms; \
	Parms.Request=Request; \
	OnRequestFail.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_75_DELEGATE \
struct _Script_SIOJson_eventOnRequestComplete_Parms \
{ \
	USIOJRequestJSON* Request; \
}; \
static inline void FOnRequestComplete_DelegateWrapper(const FMulticastScriptDelegate& OnRequestComplete, USIOJRequestJSON* Request) \
{ \
	_Script_SIOJson_eventOnRequestComplete_Parms Parms; \
	Parms.Request=Request; \
	OnRequestComplete.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execHasTag) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasTag(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveTag) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RemoveTag(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddTag) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddTag(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyURL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_OBJECT_REF(USIOJsonObject,Z_Param_Out_Result); \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ApplyURL(Z_Param_Url,Z_Param_Out_Result,Z_Param_WorldContextObject,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProcessURL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ProcessURL(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllResponseHeaders) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetAllResponseHeaders(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_HeaderName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetResponseHeader(Z_Param_HeaderName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseCode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetResponseCode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ESIORequestStatus*)Z_Param__Result=P_THIS->GetStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetURL) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetURL(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetResponseObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetResponseObject(Z_Param_JsonObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->GetResponseObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRequestObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetRequestObject(Z_Param_JsonObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRequestObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->GetRequestObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Cancel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetResponseData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetResponseData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetRequestData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetRequestData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_HeaderName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_HeaderValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetHeader(Z_Param_HeaderName,Z_Param_HeaderValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBinaryRequestContent) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Content); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBinaryRequestContent(Z_Param_Out_Content); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBinaryContentType) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ContentType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBinaryContentType(Z_Param_ContentType); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentType) \
	{ \
		P_GET_ENUM(ESIORequestContentType,Z_Param_ContentType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentType(ESIORequestContentType(Z_Param_ContentType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCustomVerb) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Verb); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetCustomVerb(Z_Param_Verb); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVerb) \
	{ \
		P_GET_ENUM(ESIORequestVerb,Z_Param_Verb); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVerb(ESIORequestVerb(Z_Param_Verb)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructRequestExt) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_ENUM(ESIORequestVerb,Z_Param_Verb); \
		P_GET_ENUM(ESIORequestContentType,Z_Param_ContentType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJRequestJSON**)Z_Param__Result=USIOJRequestJSON::ConstructRequestExt(Z_Param_WorldContextObject,ESIORequestVerb(Z_Param_Verb),ESIORequestContentType(Z_Param_ContentType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructRequest) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJRequestJSON**)Z_Param__Result=USIOJRequestJSON::ConstructRequest(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHasTag) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasTag(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveTag) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->RemoveTag(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAddTag) \
	{ \
		P_GET_PROPERTY(UNameProperty,Z_Param_Tag); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->AddTag(Z_Param_Tag); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execApplyURL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_GET_OBJECT_REF(USIOJsonObject,Z_Param_Out_Result); \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ApplyURL(Z_Param_Url,Z_Param_Out_Result,Z_Param_WorldContextObject,Z_Param_LatentInfo); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProcessURL) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Url); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ProcessURL(Z_Param_Url); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetAllResponseHeaders) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetAllResponseHeaders(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_HeaderName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetResponseHeader(Z_Param_HeaderName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseCode) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=P_THIS->GetResponseCode(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStatus) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(ESIORequestStatus*)Z_Param__Result=P_THIS->GetStatus(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetURL) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetURL(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetResponseObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetResponseObject(Z_Param_JsonObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetResponseObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->GetResponseObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetRequestObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetRequestObject(Z_Param_JsonObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetRequestObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->GetRequestObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execCancel) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Cancel(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetResponseData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetResponseData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetRequestData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetRequestData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execResetData) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetData(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetHeader) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_HeaderName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_HeaderValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetHeader(Z_Param_HeaderName,Z_Param_HeaderValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBinaryRequestContent) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Content); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBinaryRequestContent(Z_Param_Out_Content); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBinaryContentType) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_ContentType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBinaryContentType(Z_Param_ContentType); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetContentType) \
	{ \
		P_GET_ENUM(ESIORequestContentType,Z_Param_ContentType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetContentType(ESIORequestContentType(Z_Param_ContentType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetCustomVerb) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Verb); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetCustomVerb(Z_Param_Verb); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetVerb) \
	{ \
		P_GET_ENUM(ESIORequestVerb,Z_Param_Verb); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetVerb(ESIORequestVerb(Z_Param_Verb)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructRequestExt) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_ENUM(ESIORequestVerb,Z_Param_Verb); \
		P_GET_ENUM(ESIORequestContentType,Z_Param_ContentType); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJRequestJSON**)Z_Param__Result=USIOJRequestJSON::ConstructRequestExt(Z_Param_WorldContextObject,ESIORequestVerb(Z_Param_Verb),ESIORequestContentType(Z_Param_ContentType)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructRequest) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJRequestJSON**)Z_Param__Result=USIOJRequestJSON::ConstructRequest(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSIOJRequestJSON(); \
	friend struct Z_Construct_UClass_USIOJRequestJSON_Statics; \
public: \
	DECLARE_CLASS(USIOJRequestJSON, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJRequestJSON)


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_INCLASS \
private: \
	static void StaticRegisterNativesUSIOJRequestJSON(); \
	friend struct Z_Construct_UClass_USIOJRequestJSON_Statics; \
public: \
	DECLARE_CLASS(USIOJRequestJSON, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJRequestJSON)


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJRequestJSON(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJRequestJSON) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJRequestJSON); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJRequestJSON); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJRequestJSON(USIOJRequestJSON&&); \
	NO_API USIOJRequestJSON(const USIOJRequestJSON&); \
public:


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJRequestJSON(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJRequestJSON(USIOJRequestJSON&&); \
	NO_API USIOJRequestJSON(const USIOJRequestJSON&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJRequestJSON); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJRequestJSON); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJRequestJSON)


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__RequestJsonObj() { return STRUCT_OFFSET(USIOJRequestJSON, RequestJsonObj); } \
	FORCEINLINE static uint32 __PPO__RequestBytes() { return STRUCT_OFFSET(USIOJRequestJSON, RequestBytes); } \
	FORCEINLINE static uint32 __PPO__BinaryContentType() { return STRUCT_OFFSET(USIOJRequestJSON, BinaryContentType); } \
	FORCEINLINE static uint32 __PPO__ResponseJsonObj() { return STRUCT_OFFSET(USIOJRequestJSON, ResponseJsonObj); }


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_85_PROLOG
#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_RPC_WRAPPERS \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_INCLASS \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h_88_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SIOJRequestJSON."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIOJSON_API UClass* StaticClass<class USIOJRequestJSON>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_23_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJRequestJSON_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
