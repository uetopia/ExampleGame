// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USIOJRequestJSON;
class UObject;
enum class ESIORequestVerb : uint8;
enum class ESIORequestContentType : uint8;
class USIOJsonObject;
class USIOJsonValue;
class UProperty;
#ifdef SIOJSON_SIOJLibrary_generated_h
#error "SIOJLibrary.generated.h already included, missing '#pragma once' in SIOJLibrary.h"
#endif
#define SIOJSON_SIOJLibrary_generated_h

#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_21_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FSIOJCallResponse_Statics; \
	SIOJSON_API static class UScriptStruct* StaticStruct();


template<> SIOJSON_API UScriptStruct* StaticStruct<struct FSIOJCallResponse>();

#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_16_DELEGATE \
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


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_SPARSE_DATA
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCallURL) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_URL); \
		P_GET_ENUM(ESIORequestVerb,Z_Param_Verb); \
		P_GET_ENUM(ESIORequestContentType,Z_Param_ContentType); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_SIOJJson); \
		P_GET_PROPERTY_REF(UDelegateProperty,Z_Param_Out_Callback); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USIOJLibrary::CallURL(Z_Param_WorldContextObject,Z_Param_URL,ESIORequestVerb(Z_Param_Verb),ESIORequestContentType(Z_Param_ContentType),Z_Param_SIOJJson,FSIOJCallDelegate(Z_Param_Out_Callback)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToJsonObject) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=USIOJLibrary::Conv_JsonValueToJsonObject(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonObjectToString) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_InObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=USIOJLibrary::Conv_JsonObjectToString(Z_Param_InObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToBytes) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToBytes(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToBool) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToBool(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToFloat) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToFloat(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToInt) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToInt(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BoolToJsonValue) \
	{ \
		P_GET_UBOOL(Z_Param_InBool); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_BoolToJsonValue(Z_Param_InBool); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_FloatToJsonValue) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InFloat); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_FloatToJsonValue(Z_Param_InFloat); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_IntToJsonValue) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_InInt); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_IntToJsonValue(Z_Param_InInt); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_StringToJsonValue) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_StringToJsonValue(Z_Param_InString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BytesToJsonValue) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_BytesToJsonValue(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonObjectToJsonValue) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_InObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_JsonObjectToJsonValue(Z_Param_InObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_ArrayToJsonValue) \
	{ \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_ArrayToJsonValue(Z_Param_Out_InArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToJsonValueArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_JsonString); \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_OutJsonValueArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USIOJLibrary::StringToJsonValueArray(Z_Param_JsonString,Z_Param_Out_OutJsonValueArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64Decode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Dest); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USIOJLibrary::Base64Decode(Z_Param_Source,Z_Param_Out_Dest); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64Encode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=USIOJLibrary::Base64Encode(Z_Param_Source); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPercentEncode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=USIOJLibrary::PercentEncode(Z_Param_Source); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCallURL) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_URL); \
		P_GET_ENUM(ESIORequestVerb,Z_Param_Verb); \
		P_GET_ENUM(ESIORequestContentType,Z_Param_ContentType); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_SIOJJson); \
		P_GET_PROPERTY_REF(UDelegateProperty,Z_Param_Out_Callback); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		USIOJLibrary::CallURL(Z_Param_WorldContextObject,Z_Param_URL,ESIORequestVerb(Z_Param_Verb),ESIORequestContentType(Z_Param_ContentType),Z_Param_SIOJJson,FSIOJCallDelegate(Z_Param_Out_Callback)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToJsonObject) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=USIOJLibrary::Conv_JsonValueToJsonObject(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonObjectToString) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_InObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=USIOJLibrary::Conv_JsonObjectToString(Z_Param_InObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToBytes) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToBytes(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToBool) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToBool(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToFloat) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToFloat(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonValueToInt) \
	{ \
		P_GET_OBJECT(USIOJsonValue,Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(int32*)Z_Param__Result=USIOJLibrary::Conv_JsonValueToInt(Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BoolToJsonValue) \
	{ \
		P_GET_UBOOL(Z_Param_InBool); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_BoolToJsonValue(Z_Param_InBool); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_FloatToJsonValue) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_InFloat); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_FloatToJsonValue(Z_Param_InFloat); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_IntToJsonValue) \
	{ \
		P_GET_PROPERTY(UIntProperty,Z_Param_InInt); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_IntToJsonValue(Z_Param_InInt); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_StringToJsonValue) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_StringToJsonValue(Z_Param_InString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BytesToJsonValue) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_BytesToJsonValue(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_JsonObjectToJsonValue) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_InObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_JsonObjectToJsonValue(Z_Param_InObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_ArrayToJsonValue) \
	{ \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJLibrary::Conv_ArrayToJsonValue(Z_Param_Out_InArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStringToJsonValueArray) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_JsonString); \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_OutJsonValueArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USIOJLibrary::StringToJsonValueArray(Z_Param_JsonString,Z_Param_Out_OutJsonValueArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64Decode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_Dest); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=USIOJLibrary::Base64Decode(Z_Param_Source,Z_Param_Out_Dest); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execBase64Encode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=USIOJLibrary::Base64Encode(Z_Param_Source); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execPercentEncode) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Source); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=USIOJLibrary::PercentEncode(Z_Param_Source); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSIOJLibrary(); \
	friend struct Z_Construct_UClass_USIOJLibrary_Statics; \
public: \
	DECLARE_CLASS(USIOJLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_INCLASS \
private: \
	static void StaticRegisterNativesUSIOJLibrary(); \
	friend struct Z_Construct_UClass_USIOJLibrary_Statics; \
public: \
	DECLARE_CLASS(USIOJLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJLibrary(USIOJLibrary&&); \
	NO_API USIOJLibrary(const USIOJLibrary&); \
public:


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJLibrary(USIOJLibrary&&); \
	NO_API USIOJLibrary(const USIOJLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_PRIVATE_PROPERTY_OFFSET
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_46_PROLOG
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_RPC_WRAPPERS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_INCLASS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h_49_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIOJSON_API UClass* StaticClass<class USIOJLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
