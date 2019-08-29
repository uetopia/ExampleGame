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
#ifdef SIOJSON_SIOJsonObject_generated_h
#error "SIOJsonObject.generated.h already included, missing '#pragma once' in SIOJsonObject.h"
#endif
#define SIOJSON_SIOJsonObject_generated_h

#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetObjectArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(USIOJsonObject*,Z_Param_Out_ObjectArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetObjectArrayField(Z_Param_FieldName,Z_Param_Out_ObjectArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<USIOJsonObject*>*)Z_Param__Result=P_THIS->GetObjectArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoolArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(bool,Z_Param_Out_BoolArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBoolArrayField(Z_Param_FieldName,Z_Param_Out_BoolArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBoolArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStringArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetStringArrayField(Z_Param_FieldName,Z_Param_Out_StringArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumberArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(float,Z_Param_Out_NumberArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNumberArrayField(Z_Param_FieldName,Z_Param_Out_NumberArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetNumberArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBinaryField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBinaryField(Z_Param_FieldName,Z_Param_Out_Bytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBinaryField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetBinaryField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetObjectField(Z_Param_FieldName,Z_Param_JsonObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->GetObjectField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoolField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_UBOOL(Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBoolField(Z_Param_FieldName,Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStringField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_StringValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetStringField(Z_Param_FieldName,Z_Param_StringValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetStringField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumberField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNumberField(Z_Param_FieldName,Z_Param_Number); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNumberField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMergeJsonObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_InJsonObject); \
		P_GET_UBOOL(Z_Param_Overwrite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MergeJsonObject(Z_Param_InJsonObject,Z_Param_Overwrite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetArrayField(Z_Param_FieldName,Z_Param_Out_InArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<USIOJsonValue*>*)Z_Param__Result=P_THIS->GetArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_OBJECT(USIOJsonValue,Z_Param_JsonValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetField(Z_Param_FieldName,Z_Param_JsonValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=P_THIS->GetField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RemoveField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFieldNames) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetFieldNames(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDecodeJson) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_JsonString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DecodeJson(Z_Param_JsonString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEncodeJsonToSingleString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->EncodeJsonToSingleString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEncodeJson) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->EncodeJson(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=USIOJsonObject::ConstructJsonObject(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetObjectArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(USIOJsonObject*,Z_Param_Out_ObjectArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetObjectArrayField(Z_Param_FieldName,Z_Param_Out_ObjectArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<USIOJsonObject*>*)Z_Param__Result=P_THIS->GetObjectArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoolArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(bool,Z_Param_Out_BoolArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBoolArrayField(Z_Param_FieldName,Z_Param_Out_BoolArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<bool>*)Z_Param__Result=P_THIS->GetBoolArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStringArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(FString,Z_Param_Out_StringArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetStringArrayField(Z_Param_FieldName,Z_Param_Out_StringArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetStringArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumberArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(float,Z_Param_Out_NumberArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNumberArrayField(Z_Param_FieldName,Z_Param_Out_NumberArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<float>*)Z_Param__Result=P_THIS->GetNumberArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBinaryField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBinaryField(Z_Param_FieldName,Z_Param_Out_Bytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBinaryField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=P_THIS->GetBinaryField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetObjectField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetObjectField(Z_Param_FieldName,Z_Param_JsonObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetObjectField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=P_THIS->GetObjectField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetBoolField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_UBOOL(Z_Param_InValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetBoolField(Z_Param_FieldName,Z_Param_InValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetBoolField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->GetBoolField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetStringField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_StringValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetStringField(Z_Param_FieldName,Z_Param_StringValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetStringField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->GetStringField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetNumberField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Number); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetNumberField(Z_Param_FieldName,Z_Param_Number); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetNumberField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=P_THIS->GetNumberField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execMergeJsonObject) \
	{ \
		P_GET_OBJECT(USIOJsonObject,Z_Param_InJsonObject); \
		P_GET_UBOOL(Z_Param_Overwrite); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->MergeJsonObject(Z_Param_InJsonObject,Z_Param_Overwrite); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetArrayField(Z_Param_FieldName,Z_Param_Out_InArray); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetArrayField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<USIOJsonValue*>*)Z_Param__Result=P_THIS->GetArrayField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_GET_OBJECT(USIOJsonValue,Z_Param_JsonValue); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->SetField(Z_Param_FieldName,Z_Param_JsonValue); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonValue**)Z_Param__Result=P_THIS->GetField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execRemoveField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->RemoveField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execHasField) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_FieldName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->HasField(Z_Param_FieldName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetFieldNames) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<FString>*)Z_Param__Result=P_THIS->GetFieldNames(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execDecodeJson) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_JsonString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->DecodeJson(Z_Param_JsonString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEncodeJsonToSingleString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->EncodeJsonToSingleString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execEncodeJson) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->EncodeJson(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execReset) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->Reset(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConstructJsonObject) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USIOJsonObject**)Z_Param__Result=USIOJsonObject::ConstructJsonObject(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSIOJsonObject(); \
	friend struct Z_Construct_UClass_USIOJsonObject_Statics; \
public: \
	DECLARE_CLASS(USIOJsonObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJsonObject)


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_INCLASS \
private: \
	static void StaticRegisterNativesUSIOJsonObject(); \
	friend struct Z_Construct_UClass_USIOJsonObject_Statics; \
public: \
	DECLARE_CLASS(USIOJsonObject, UObject, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SIOJson"), NO_API) \
	DECLARE_SERIALIZER(USIOJsonObject)


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJsonObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJsonObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJsonObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJsonObject); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJsonObject(USIOJsonObject&&); \
	NO_API USIOJsonObject(const USIOJsonObject&); \
public:


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USIOJsonObject(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USIOJsonObject(USIOJsonObject&&); \
	NO_API USIOJsonObject(const USIOJsonObject&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USIOJsonObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USIOJsonObject); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USIOJsonObject)


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_PRIVATE_PROPERTY_OFFSET
#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_17_PROLOG
#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_RPC_WRAPPERS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_INCLASS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h_20_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class SIOJsonObject."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SIOJSON_API UClass* StaticClass<class USIOJsonObject>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_22_2_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonObject_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
