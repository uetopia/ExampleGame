// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "SIOJsonValue.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class USIOJsonObject;
class USIOJsonValue;
#ifdef SIOJSON_SIOJsonValue_generated_h
#error "SIOJsonValue.generated.h already included, missing '#pragma once' in SIOJsonValue.h"
#endif
#define SIOJSON_SIOJsonValue_generated_h

#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_SPARSE_DATA
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execEncodeJson); \
	DECLARE_FUNCTION(execAsBinary); \
	DECLARE_FUNCTION(execAsObject); \
	DECLARE_FUNCTION(execAsArray); \
	DECLARE_FUNCTION(execAsBool); \
	DECLARE_FUNCTION(execAsString); \
	DECLARE_FUNCTION(execAsNumber); \
	DECLARE_FUNCTION(execIsNull); \
	DECLARE_FUNCTION(execGetTypeString); \
	DECLARE_FUNCTION(execGetType); \
	DECLARE_FUNCTION(execValueFromJsonString); \
	DECLARE_FUNCTION(execConstructJsonValueBinary); \
	DECLARE_FUNCTION(execConstructJsonValueObject); \
	DECLARE_FUNCTION(execConstructJsonValueArray); \
	DECLARE_FUNCTION(execConstructJsonValueBool); \
	DECLARE_FUNCTION(execConstructJsonValueString); \
	DECLARE_FUNCTION(execConstructJsonValueNumber);


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execEncodeJson); \
	DECLARE_FUNCTION(execAsBinary); \
	DECLARE_FUNCTION(execAsObject); \
	DECLARE_FUNCTION(execAsArray); \
	DECLARE_FUNCTION(execAsBool); \
	DECLARE_FUNCTION(execAsString); \
	DECLARE_FUNCTION(execAsNumber); \
	DECLARE_FUNCTION(execIsNull); \
	DECLARE_FUNCTION(execGetTypeString); \
	DECLARE_FUNCTION(execGetType); \
	DECLARE_FUNCTION(execValueFromJsonString); \
	DECLARE_FUNCTION(execConstructJsonValueBinary); \
	DECLARE_FUNCTION(execConstructJsonValueObject); \
	DECLARE_FUNCTION(execConstructJsonValueArray); \
	DECLARE_FUNCTION(execConstructJsonValueBool); \
	DECLARE_FUNCTION(execConstructJsonValueString); \
	DECLARE_FUNCTION(execConstructJsonValueNumber);


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_ACCESSORS
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSIOJsonValue(); \
	friend struct Z_Construct_UClass_USIOJsonValue_Statics; \
public: \
	DECLARE_CLASS(USIOJsonValue, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJsonValue)


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_INCLASS \
private: \
	static void StaticRegisterNativesUSIOJsonValue(); \
	friend struct Z_Construct_UClass_USIOJsonValue_Statics; \
public: \
	DECLARE_CLASS(USIOJsonValue, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJsonValue)


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJsonValue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJsonValue) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJsonValue); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJsonValue); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJsonValue(USIOJsonValue&&); \
	NO_API USIOJsonValue(const USIOJsonValue&); \
public: \
	NO_API virtual ~USIOJsonValue();


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJsonValue(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJsonValue(USIOJsonValue&&); \
	NO_API USIOJsonValue(const USIOJsonValue&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJsonValue); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJsonValue); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJsonValue) \
	NO_API virtual ~USIOJsonValue();


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_73_PROLOG
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_SPARSE_DATA \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_RPC_WRAPPERS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_ACCESSORS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_INCLASS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_SPARSE_DATA \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_ACCESSORS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_INCLASS_NO_PURE_DECLS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_76_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SIOJsonValue."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIOJSON_API UClass* StaticClass<class USIOJsonValue>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h


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
