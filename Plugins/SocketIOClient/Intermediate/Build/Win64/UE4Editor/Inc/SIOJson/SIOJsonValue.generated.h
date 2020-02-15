// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class USIOJsonObject;
class USIOJsonValue;
class UObject;
#ifdef SIOJSON_SIOJsonValue_generated_h
#error "SIOJsonValue.generated.h already included, missing '#pragma once' in SIOJsonValue.h"
#endif
#define SIOJSON_SIOJsonValue_generated_h

#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_SPARSE_DATA
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEncodeJson) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->EncodeJson(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsBinary) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->AsBinary(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->AsObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<USIOJsonValue*>*)Z_Param__Result=P_THIS->AsArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsBool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AsBool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->AsString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsNumber) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->AsNumber(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsNull) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsNull(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTypeString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetTypeString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TEnumAsByte<ESIOJson::Type>*)Z_Param__Result=P_THIS->GetType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execValueFromJsonString) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_StringValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ValueFromJsonString(Z_Param_WorldContextObject,Z_Param_StringValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueBinary) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY(uint8,Z_Param_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueBinary(Z_Param_WorldContextObject,Z_Param_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueObject(Z_Param_JsonObject,Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueArray) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueArray(Z_Param_WorldContextObject,Z_Param_Out_InArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueBool) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL(Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueBool(Z_Param_WorldContextObject,Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueString) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_StringValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueString(Z_Param_WorldContextObject,Z_Param_StringValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueNumber) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueNumber(Z_Param_WorldContextObject,Z_Param_Number); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEncodeJson) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->EncodeJson(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsBinary) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->AsBinary(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsObject) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->AsObject(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsArray) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<USIOJsonValue*>*)Z_Param__Result=P_THIS->AsArray(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsBool) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->AsBool(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->AsString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execAsNumber) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->AsNumber(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIsNull) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->IsNull(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetTypeString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetTypeString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetType) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TEnumAsByte<ESIOJson::Type>*)Z_Param__Result=P_THIS->GetType(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execValueFromJsonString) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_StringValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ValueFromJsonString(Z_Param_WorldContextObject,Z_Param_StringValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueBinary) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY(uint8,Z_Param_ByteArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueBinary(Z_Param_WorldContextObject,Z_Param_ByteArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueObject(Z_Param_JsonObject,Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueArray) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueArray(Z_Param_WorldContextObject,Z_Param_Out_InArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueBool) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_UBOOL(Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueBool(Z_Param_WorldContextObject,Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueString) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UStrProperty,Z_Param_StringValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueString(Z_Param_WorldContextObject,Z_Param_StringValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonValueNumber) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueNumber(Z_Param_WorldContextObject,Z_Param_Number); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSIOJsonValue(); \
	friend struct Z_Construct_UClass_USIOJsonValue_Statics; \
public: \
	DECLARE_CLASS(USIOJsonValue, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJsonValue)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_INCLASS \
private: \
	static void StaticRegisterNativesUSIOJsonValue(); \
	friend struct Z_Construct_UClass_USIOJsonValue_Statics; \
public: \
	DECLARE_CLASS(USIOJsonValue, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJsonValue)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJsonValue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJsonValue) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJsonValue); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJsonValue); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJsonValue(USIOJsonValue&&); \
	NO_API USIOJsonValue(const USIOJsonValue&); \
public:


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJsonValue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJsonValue(USIOJsonValue&&); \
	NO_API USIOJsonValue(const USIOJsonValue&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJsonValue); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJsonValue); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJsonValue)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_PRIVATE_PROPERTY_OFFSET
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_70_PROLOG
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_RPC_WRAPPERS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_INCLASS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SIOJsonValue."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIOJSON_API UClass* StaticClass<class USIOJsonValue>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h


#define FOREACH_ENUM_ESIOJSON(op) \
	op(ESIOJson::None) \
	op(ESIOJson::Null) \
	op(ESIOJson::String) \
	op(ESIOJson::Number) \
	op(ESIOJson::Boolean) \
	op(ESIOJson::Array) \
	op(ESIOJson::Object) \
	op(ESIOJson::Binary) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
