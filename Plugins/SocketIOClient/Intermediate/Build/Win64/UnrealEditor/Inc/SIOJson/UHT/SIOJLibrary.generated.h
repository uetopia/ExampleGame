// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SIOJLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class FProperty;
class UObject;
class USIOJRequestJSON;
class USIOJsonObject;
class USIOJsonValue;
enum class ESIORequestContentType : uint8;
enum class ESIORequestVerb : uint8;
struct FLatentActionInfo;
#ifdef SIOJSON_SIOJLibrary_generated_h
#error "SIOJLibrary.generated.h already included, missing '#pragma once' in SIOJLibrary.h"
#endif
#define SIOJSON_SIOJLibrary_generated_h

#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_17_DELEGATE \
struct _Script_SIOJson_eventSIOJCallDelegate_Parms \
{ \
	USIOJRequestJSON* Request; \
}; \
static inline void FSIOJCallDelegate_DelegateWrapper(const FScriptDelegate& SIOJCallDelegate, USIOJRequestJSON* Request) \
{ \
	_Script_SIOJson_eventSIOJCallDelegate_Parms Parms; \
	Parms.Request=Request; \
	SIOJCallDelegate.ProcessDelegate<UObject>(&Parms); \
}


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSIOJCallResponse_Statics; \
	SIOJSON_API static class UScriptStruct* StaticStruct();


template<> SIOJSON_API UScriptStruct* StaticStruct<struct FSIOJCallResponse>();

#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_SPARSE_DATA
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetURLBinary); \
	DECLARE_FUNCTION(execCallURL); \
	DECLARE_FUNCTION(execConv_JsonValueToJsonObject); \
	DECLARE_FUNCTION(execConv_SIOJsonObjectToString); \
	DECLARE_FUNCTION(execConv_JsonValueToBytes); \
	DECLARE_FUNCTION(execConv_JsonValueToBool); \
	DECLARE_FUNCTION(execConv_JsonValueToFloat); \
	DECLARE_FUNCTION(execConv_JsonValueToInt); \
	DECLARE_FUNCTION(execConv_SIOJsonValueToString); \
	DECLARE_FUNCTION(execConv_BoolToJsonValue); \
	DECLARE_FUNCTION(execConv_FloatToJsonValue); \
	DECLARE_FUNCTION(execConv_IntToJsonValue); \
	DECLARE_FUNCTION(execConv_StringToJsonValue); \
	DECLARE_FUNCTION(execConv_BytesToJsonValue); \
	DECLARE_FUNCTION(execConv_JsonObjectToJsonValue); \
	DECLARE_FUNCTION(execConv_ArrayToJsonValue); \
	DECLARE_FUNCTION(execStringToJsonValueArray); \
	DECLARE_FUNCTION(execBase64DecodeBytes); \
	DECLARE_FUNCTION(execBase64Decode); \
	DECLARE_FUNCTION(execBase64EncodeBytes); \
	DECLARE_FUNCTION(execBase64Encode); \
	DECLARE_FUNCTION(execPercentEncode);


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetURLBinary); \
	DECLARE_FUNCTION(execCallURL); \
	DECLARE_FUNCTION(execConv_JsonValueToJsonObject); \
	DECLARE_FUNCTION(execConv_SIOJsonObjectToString); \
	DECLARE_FUNCTION(execConv_JsonValueToBytes); \
	DECLARE_FUNCTION(execConv_JsonValueToBool); \
	DECLARE_FUNCTION(execConv_JsonValueToFloat); \
	DECLARE_FUNCTION(execConv_JsonValueToInt); \
	DECLARE_FUNCTION(execConv_SIOJsonValueToString); \
	DECLARE_FUNCTION(execConv_BoolToJsonValue); \
	DECLARE_FUNCTION(execConv_FloatToJsonValue); \
	DECLARE_FUNCTION(execConv_IntToJsonValue); \
	DECLARE_FUNCTION(execConv_StringToJsonValue); \
	DECLARE_FUNCTION(execConv_BytesToJsonValue); \
	DECLARE_FUNCTION(execConv_JsonObjectToJsonValue); \
	DECLARE_FUNCTION(execConv_ArrayToJsonValue); \
	DECLARE_FUNCTION(execStringToJsonValueArray); \
	DECLARE_FUNCTION(execBase64DecodeBytes); \
	DECLARE_FUNCTION(execBase64Decode); \
	DECLARE_FUNCTION(execBase64EncodeBytes); \
	DECLARE_FUNCTION(execBase64Encode); \
	DECLARE_FUNCTION(execPercentEncode);


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_ACCESSORS
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSIOJLibrary(); \
	friend struct Z_Construct_UClass_USIOJLibrary_Statics; \
public: \
	DECLARE_CLASS(USIOJLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJLibrary)


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_INCLASS \
private: \
	static void StaticRegisterNativesUSIOJLibrary(); \
	friend struct Z_Construct_UClass_USIOJLibrary_Statics; \
public: \
	DECLARE_CLASS(USIOJLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJLibrary)


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJLibrary(USIOJLibrary&&); \
	NO_API USIOJLibrary(const USIOJLibrary&); \
public: \
	NO_API virtual ~USIOJLibrary();


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJLibrary(USIOJLibrary&&); \
	NO_API USIOJLibrary(const USIOJLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJLibrary) \
	NO_API virtual ~USIOJLibrary();


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_47_PROLOG
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_SPARSE_DATA \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_RPC_WRAPPERS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_ACCESSORS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_INCLASS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_SPARSE_DATA \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_ACCESSORS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_INCLASS_NO_PURE_DECLS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_50_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIOJSON_API UClass* StaticClass<class USIOJLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
