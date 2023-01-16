// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SIOJson/Public/SIOJsonValue.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIOJsonValue() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonObject_NoRegister();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonValue();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonValue_NoRegister();
	SIOJSON_API UEnum* Z_Construct_UEnum_SIOJson_ESIOJson();
	UPackage* Z_Construct_UPackage__Script_SIOJson();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIOJson;
	static UEnum* ESIOJson_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIOJson.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIOJson.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SIOJson_ESIOJson, Z_Construct_UPackage__Script_SIOJson(), TEXT("ESIOJson"));
		}
		return Z_Registration_Info_UEnum_ESIOJson.OuterSingleton;
	}
	template<> SIOJSON_API UEnum* StaticEnum<ESIOJson::Type>()
	{
		return ESIOJson_StaticEnum();
	}
	struct Z_Construct_UEnum_SIOJson_ESIOJson_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SIOJson_ESIOJson_Statics::Enumerators[] = {
		{ "ESIOJson::None", (int64)ESIOJson::None },
		{ "ESIOJson::Null", (int64)ESIOJson::Null },
		{ "ESIOJson::String", (int64)ESIOJson::String },
		{ "ESIOJson::Number", (int64)ESIOJson::Number },
		{ "ESIOJson::Boolean", (int64)ESIOJson::Boolean },
		{ "ESIOJson::Array", (int64)ESIOJson::Array },
		{ "ESIOJson::Object", (int64)ESIOJson::Object },
		{ "ESIOJson::Binary", (int64)ESIOJson::Binary },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SIOJson_ESIOJson_Statics::Enum_MetaDataParams[] = {
		{ "Array.Name", "ESIOJson::Array" },
		{ "Binary.Name", "ESIOJson::Binary" },
		{ "BlueprintType", "true" },
		{ "Boolean.Name", "ESIOJson::Boolean" },
		{ "Comment", "/**\n * Represents all the types a Json Value can be.\n */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "None.Name", "ESIOJson::None" },
		{ "Null.Name", "ESIOJson::Null" },
		{ "Number.Name", "ESIOJson::Number" },
		{ "Object.Name", "ESIOJson::Object" },
		{ "String.Name", "ESIOJson::String" },
		{ "ToolTip", "Represents all the types a Json Value can be." },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SIOJson_ESIOJson_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SIOJson,
		nullptr,
		"ESIOJson",
		"ESIOJson::Type",
		Z_Construct_UEnum_SIOJson_ESIOJson_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIOJson_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Namespaced,
		METADATA_PARAMS(Z_Construct_UEnum_SIOJson_ESIOJson_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIOJson_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SIOJson_ESIOJson()
	{
		if (!Z_Registration_Info_UEnum_ESIOJson.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIOJson.InnerSingleton, Z_Construct_UEnum_SIOJson_ESIOJson_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIOJson.InnerSingleton;
	}
	DEFINE_FUNCTION(USIOJsonValue::execEncodeJson)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->EncodeJson();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execAsBinary)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=P_THIS->AsBinary();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execAsObject)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonObject**)Z_Param__Result=P_THIS->AsObject();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execAsArray)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<USIOJsonValue*>*)Z_Param__Result=P_THIS->AsArray();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execAsBool)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->AsBool();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execAsString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->AsString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execAsNumber)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->AsNumber();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execIsNull)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsNull();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execGetTypeString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetTypeString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execGetType)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TEnumAsByte<ESIOJson::Type>*)Z_Param__Result=P_THIS->GetType();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execValueFromJsonString)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_StringValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ValueFromJsonString(Z_Param_WorldContextObject,Z_Param_StringValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execConstructJsonValueBinary)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY(uint8,Z_Param_ByteArray);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueBinary(Z_Param_WorldContextObject,Z_Param_ByteArray);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execConstructJsonValueObject)
	{
		P_GET_OBJECT(USIOJsonObject,Z_Param_JsonObject);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueObject(Z_Param_JsonObject,Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execConstructJsonValueArray)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_TARRAY_REF(USIOJsonValue*,Z_Param_Out_InArray);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueArray(Z_Param_WorldContextObject,Z_Param_Out_InArray);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execConstructJsonValueBool)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_UBOOL(Z_Param_InValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueBool(Z_Param_WorldContextObject,Z_Param_InValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execConstructJsonValueString)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FStrProperty,Z_Param_StringValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueString(Z_Param_WorldContextObject,Z_Param_StringValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USIOJsonValue::execConstructJsonValueNumber)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Number);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USIOJsonValue**)Z_Param__Result=USIOJsonValue::ConstructJsonValueNumber(Z_Param_WorldContextObject,Z_Param_Number);
		P_NATIVE_END;
	}
	void USIOJsonValue::StaticRegisterNativesUSIOJsonValue()
	{
		UClass* Class = USIOJsonValue::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AsArray", &USIOJsonValue::execAsArray },
			{ "AsBinary", &USIOJsonValue::execAsBinary },
			{ "AsBool", &USIOJsonValue::execAsBool },
			{ "AsNumber", &USIOJsonValue::execAsNumber },
			{ "AsObject", &USIOJsonValue::execAsObject },
			{ "AsString", &USIOJsonValue::execAsString },
			{ "ConstructJsonValueArray", &USIOJsonValue::execConstructJsonValueArray },
			{ "ConstructJsonValueBinary", &USIOJsonValue::execConstructJsonValueBinary },
			{ "ConstructJsonValueBool", &USIOJsonValue::execConstructJsonValueBool },
			{ "ConstructJsonValueNumber", &USIOJsonValue::execConstructJsonValueNumber },
			{ "ConstructJsonValueObject", &USIOJsonValue::execConstructJsonValueObject },
			{ "ConstructJsonValueString", &USIOJsonValue::execConstructJsonValueString },
			{ "EncodeJson", &USIOJsonValue::execEncodeJson },
			{ "GetType", &USIOJsonValue::execGetType },
			{ "GetTypeString", &USIOJsonValue::execGetTypeString },
			{ "IsNull", &USIOJsonValue::execIsNull },
			{ "ValueFromJsonString", &USIOJsonValue::execValueFromJsonString },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USIOJsonValue_AsArray_Statics
	{
		struct SIOJsonValue_eventAsArray_Parms
		{
			TArray<USIOJsonValue*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventAsArray_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Returns this value as an array, throwing an error if this is not an Json Array */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Returns this value as an array, throwing an error if this is not an Json Array" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "AsArray", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::SIOJsonValue_eventAsArray_Parms), Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_AsArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_AsArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics
	{
		struct SIOJsonValue_eventAsBinary_Parms
		{
			TArray<uint8> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventAsBinary_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "//Convert message to binary data\n" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Convert message to binary data" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "AsBinary", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::SIOJsonValue_eventAsBinary_Parms), Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_AsBinary()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_AsBinary_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_AsBool_Statics
	{
		struct SIOJsonValue_eventAsBool_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SIOJsonValue_eventAsBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SIOJsonValue_eventAsBool_Parms), &Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Returns this value as a boolean, throwing an error if this is not an Json Bool */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Returns this value as a boolean, throwing an error if this is not an Json Bool" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "AsBool", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::SIOJsonValue_eventAsBool_Parms), Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_AsBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_AsBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics
	{
		struct SIOJsonValue_eventAsNumber_Parms
		{
			float ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventAsNumber_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Returns this value as a double, throwing an error if this is not an Json Number\n\x09 * Attn.!! float used instead of double to make the function blueprintable! */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Returns this value as a double, throwing an error if this is not an Json Number\nAttn.!! float used instead of double to make the function blueprintable!" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "AsNumber", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::SIOJsonValue_eventAsNumber_Parms), Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_AsNumber()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_AsNumber_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_AsObject_Statics
	{
		struct SIOJsonValue_eventAsObject_Parms
		{
			USIOJsonObject* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventAsObject_Parms, ReturnValue), Z_Construct_UClass_USIOJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Returns this value as an object, throwing an error if this is not an Json Object */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Returns this value as an object, throwing an error if this is not an Json Object" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "AsObject", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::SIOJsonValue_eventAsObject_Parms), Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_AsObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_AsObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_AsString_Statics
	{
		struct SIOJsonValue_eventAsString_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USIOJsonValue_AsString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventAsString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_AsString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_AsString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_AsString_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Returns this value as a string, throwing an error if this is not an Json String */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Returns this value as a string, throwing an error if this is not an Json String" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_AsString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "AsString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_AsString_Statics::SIOJsonValue_eventAsString_Parms), Z_Construct_UFunction_USIOJsonValue_AsString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_AsString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_AsString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_AsString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_AsString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics
	{
		struct SIOJsonValue_eventConstructJsonValueArray_Parms
		{
			UObject* WorldContextObject;
			TArray<USIOJsonValue*> InArray;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InArray_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InArray_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InArray;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueArray_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray_Inner = { "InArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray = { "InArray", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueArray_Parms, InArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueArray_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_InArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json Array value */" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Construct Json Array Value" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json Array value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ConstructJsonValueArray", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::SIOJsonValue_eventConstructJsonValueArray_Parms), Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics
	{
		struct SIOJsonValue_eventConstructJsonValueBinary_Parms
		{
			UObject* WorldContextObject;
			TArray<uint8> ByteArray;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ByteArray_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ByteArray;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueBinary_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_ByteArray_Inner = { "ByteArray", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_ByteArray = { "ByteArray", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueBinary_Parms, ByteArray), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueBinary_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_ByteArray_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_ByteArray,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json Binary value */" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Construct Json Binary Value" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json Binary value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ConstructJsonValueBinary", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::SIOJsonValue_eventConstructJsonValueBinary_Parms), Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics
	{
		struct SIOJsonValue_eventConstructJsonValueBool_Parms
		{
			UObject* WorldContextObject;
			bool InValue;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static void NewProp_InValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_InValue;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueBool_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_InValue_SetBit(void* Obj)
	{
		((SIOJsonValue_eventConstructJsonValueBool_Parms*)Obj)->InValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_InValue = { "InValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SIOJsonValue_eventConstructJsonValueBool_Parms), &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_InValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueBool_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_InValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json Bool value */" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Construct Json Bool Value" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json Bool value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ConstructJsonValueBool", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::SIOJsonValue_eventConstructJsonValueBool_Parms), Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics
	{
		struct SIOJsonValue_eventConstructJsonValueNumber_Parms
		{
			UObject* WorldContextObject;
			float Number;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Number;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueNumber_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::NewProp_Number = { "Number", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueNumber_Parms, Number), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueNumber_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::NewProp_Number,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json Number value\n\x09 * Attn.!! float used instead of double to make the function blueprintable! */" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Construct Json Number Value" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json Number value\nAttn.!! float used instead of double to make the function blueprintable!" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ConstructJsonValueNumber", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::SIOJsonValue_eventConstructJsonValueNumber_Parms), Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics
	{
		struct SIOJsonValue_eventConstructJsonValueObject_Parms
		{
			USIOJsonObject* JsonObject;
			UObject* WorldContextObject;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_JsonObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::NewProp_JsonObject = { "JsonObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueObject_Parms, JsonObject), Z_Construct_UClass_USIOJsonObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueObject_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueObject_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::NewProp_JsonObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json Object value */" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Construct Json Object Value" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json Object value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ConstructJsonValueObject", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::SIOJsonValue_eventConstructJsonValueObject_Parms), Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics
	{
		struct SIOJsonValue_eventConstructJsonValueString_Parms
		{
			UObject* WorldContextObject;
			FString StringValue;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StringValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_StringValue;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueString_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_StringValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_StringValue = { "StringValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueString_Parms, StringValue), METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_StringValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_StringValue_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventConstructJsonValueString_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_StringValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json String value */" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Construct Json String Value" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json String value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ConstructJsonValueString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::SIOJsonValue_eventConstructJsonValueString_Parms), Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics
	{
		struct SIOJsonValue_eventEncodeJson_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventEncodeJson_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "EncodeJson", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::SIOJsonValue_eventEncodeJson_Parms), Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_EncodeJson()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_EncodeJson_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_GetType_Statics
	{
		struct SIOJsonValue_eventGetType_Parms
		{
			TEnumAsByte<ESIOJson::Type> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_USIOJsonValue_GetType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventGetType_Parms, ReturnValue), Z_Construct_UEnum_SIOJson_ESIOJson, METADATA_PARAMS(nullptr, 0) }; // 3754310115
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_GetType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_GetType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_GetType_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Get type of Json value (Enum) */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Get type of Json value (Enum)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_GetType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "GetType", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_GetType_Statics::SIOJsonValue_eventGetType_Parms), Z_Construct_UFunction_USIOJsonValue_GetType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_GetType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_GetType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_GetType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_GetType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_GetType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics
	{
		struct SIOJsonValue_eventGetTypeString_Parms
		{
			FString ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventGetTypeString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Get type of Json value (String) */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Get type of Json value (String)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "GetTypeString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::SIOJsonValue_eventGetTypeString_Parms), Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_GetTypeString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_GetTypeString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_IsNull_Statics
	{
		struct SIOJsonValue_eventIsNull_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SIOJsonValue_eventIsNull_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SIOJsonValue_eventIsNull_Parms), &Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Returns true if this value is a 'null' */" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Returns true if this value is a 'null'" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "IsNull", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::SIOJsonValue_eventIsNull_Parms), Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_IsNull()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_IsNull_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics
	{
		struct SIOJsonValue_eventValueFromJsonString_Parms
		{
			UObject* WorldContextObject;
			FString StringValue;
			USIOJsonValue* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StringValue_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_StringValue;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventValueFromJsonString_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_StringValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_StringValue = { "StringValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventValueFromJsonString_Parms, StringValue), METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_StringValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_StringValue_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SIOJsonValue_eventValueFromJsonString_Parms, ReturnValue), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_StringValue,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::Function_MetaDataParams[] = {
		{ "Category", "SIOJ|Json" },
		{ "Comment", "/** Create new Json value from JSON encoded string*/" },
		{ "DefaultToSelf", "WorldContextObject" },
		{ "DisplayName", "Value From Json String" },
		{ "HidePin", "WorldContextObject" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Create new Json value from JSON encoded string" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USIOJsonValue, nullptr, "ValueFromJsonString", nullptr, nullptr, sizeof(Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::SIOJsonValue_eventValueFromJsonString_Parms), Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USIOJsonValue);
	UClass* Z_Construct_UClass_USIOJsonValue_NoRegister()
	{
		return USIOJsonValue::StaticClass();
	}
	struct Z_Construct_UClass_USIOJsonValue_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USIOJsonValue_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SIOJson,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USIOJsonValue_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USIOJsonValue_AsArray, "AsArray" }, // 116887861
		{ &Z_Construct_UFunction_USIOJsonValue_AsBinary, "AsBinary" }, // 794987815
		{ &Z_Construct_UFunction_USIOJsonValue_AsBool, "AsBool" }, // 4138201317
		{ &Z_Construct_UFunction_USIOJsonValue_AsNumber, "AsNumber" }, // 3923015862
		{ &Z_Construct_UFunction_USIOJsonValue_AsObject, "AsObject" }, // 310039901
		{ &Z_Construct_UFunction_USIOJsonValue_AsString, "AsString" }, // 990534664
		{ &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueArray, "ConstructJsonValueArray" }, // 2427209292
		{ &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBinary, "ConstructJsonValueBinary" }, // 3936508397
		{ &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueBool, "ConstructJsonValueBool" }, // 1644229095
		{ &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueNumber, "ConstructJsonValueNumber" }, // 2210157347
		{ &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueObject, "ConstructJsonValueObject" }, // 712272003
		{ &Z_Construct_UFunction_USIOJsonValue_ConstructJsonValueString, "ConstructJsonValueString" }, // 304379485
		{ &Z_Construct_UFunction_USIOJsonValue_EncodeJson, "EncodeJson" }, // 4111466900
		{ &Z_Construct_UFunction_USIOJsonValue_GetType, "GetType" }, // 4155295904
		{ &Z_Construct_UFunction_USIOJsonValue_GetTypeString, "GetTypeString" }, // 49471461
		{ &Z_Construct_UFunction_USIOJsonValue_IsNull, "IsNull" }, // 3764878929
		{ &Z_Construct_UFunction_USIOJsonValue_ValueFromJsonString, "ValueFromJsonString" }, // 1926583103
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USIOJsonValue_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * Blueprintable FJsonValue wrapper\n */" },
		{ "IncludePath", "SIOJsonValue.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SIOJsonValue.h" },
		{ "ToolTip", "Blueprintable FJsonValue wrapper" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USIOJsonValue_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USIOJsonValue>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USIOJsonValue_Statics::ClassParams = {
		&USIOJsonValue::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USIOJsonValue_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USIOJsonValue_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USIOJsonValue()
	{
		if (!Z_Registration_Info_UClass_USIOJsonValue.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USIOJsonValue.OuterSingleton, Z_Construct_UClass_USIOJsonValue_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USIOJsonValue.OuterSingleton;
	}
	template<> SIOJSON_API UClass* StaticClass<USIOJsonValue>()
	{
		return USIOJsonValue::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USIOJsonValue);
	USIOJsonValue::~USIOJsonValue() {}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics::EnumInfo[] = {
		{ ESIOJson_StaticEnum, TEXT("ESIOJson"), &Z_Registration_Info_UEnum_ESIOJson, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3754310115U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USIOJsonValue, USIOJsonValue::StaticClass, TEXT("USIOJsonValue"), &Z_Registration_Info_UClass_USIOJsonValue, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USIOJsonValue), 3842641367U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_650383802(TEXT("/Script/SIOJson"),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJsonValue_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
