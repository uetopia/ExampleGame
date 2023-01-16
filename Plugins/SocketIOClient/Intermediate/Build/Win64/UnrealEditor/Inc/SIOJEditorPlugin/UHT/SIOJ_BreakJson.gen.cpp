// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SIOJEditorPlugin/Public/SIOJ_BreakJson.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIOJ_BreakJson() {}
// Cross Module References
	BLUEPRINTGRAPH_API UClass* Z_Construct_UClass_UK2Node();
	SIOJEDITORPLUGIN_API UClass* Z_Construct_UClass_USIOJ_BreakJson();
	SIOJEDITORPLUGIN_API UClass* Z_Construct_UClass_USIOJ_BreakJson_NoRegister();
	SIOJEDITORPLUGIN_API UEnum* Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType();
	SIOJEDITORPLUGIN_API UScriptStruct* Z_Construct_UScriptStruct_FSIOJ_NamedType();
	UPackage* Z_Construct_UPackage__Script_SIOJEditorPlugin();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIOJ_JsonType;
	static UEnum* ESIOJ_JsonType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIOJ_JsonType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIOJ_JsonType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType, Z_Construct_UPackage__Script_SIOJEditorPlugin(), TEXT("ESIOJ_JsonType"));
		}
		return Z_Registration_Info_UEnum_ESIOJ_JsonType.OuterSingleton;
	}
	template<> SIOJEDITORPLUGIN_API UEnum* StaticEnum<ESIOJ_JsonType>()
	{
		return ESIOJ_JsonType_StaticEnum();
	}
	struct Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::Enumerators[] = {
		{ "ESIOJ_JsonType::JSON_Bool", (int64)ESIOJ_JsonType::JSON_Bool },
		{ "ESIOJ_JsonType::JSON_Number", (int64)ESIOJ_JsonType::JSON_Number },
		{ "ESIOJ_JsonType::JSON_String", (int64)ESIOJ_JsonType::JSON_String },
		{ "ESIOJ_JsonType::JSON_Object", (int64)ESIOJ_JsonType::JSON_Object },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "JSON_Bool.Comment", "//JSON_Null UMETA(DisplayName = \"Null\"),\n" },
		{ "JSON_Bool.DisplayName", "Boolean" },
		{ "JSON_Bool.Name", "ESIOJ_JsonType::JSON_Bool" },
		{ "JSON_Bool.ToolTip", "JSON_Null UMETA(DisplayName = \"Null\")," },
		{ "JSON_Number.DisplayName", "Number" },
		{ "JSON_Number.Name", "ESIOJ_JsonType::JSON_Number" },
		{ "JSON_Object.DisplayName", "Object" },
		{ "JSON_Object.Name", "ESIOJ_JsonType::JSON_Object" },
		{ "JSON_String.DisplayName", "String" },
		{ "JSON_String.Name", "ESIOJ_JsonType::JSON_String" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SIOJEditorPlugin,
		nullptr,
		"ESIOJ_JsonType",
		"ESIOJ_JsonType",
		Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType()
	{
		if (!Z_Registration_Info_UEnum_ESIOJ_JsonType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIOJ_JsonType.InnerSingleton, Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIOJ_JsonType.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SIOJ_NamedType;
class UScriptStruct* FSIOJ_NamedType::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SIOJ_NamedType.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SIOJ_NamedType.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSIOJ_NamedType, Z_Construct_UPackage__Script_SIOJEditorPlugin(), TEXT("SIOJ_NamedType"));
	}
	return Z_Registration_Info_UScriptStruct_SIOJ_NamedType.OuterSingleton;
}
template<> SIOJEDITORPLUGIN_API UScriptStruct* StaticStruct<FSIOJ_NamedType>()
{
	return FSIOJ_NamedType::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Type_Underlying;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Type_MetaData[];
#endif
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Type;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsArray_MetaData[];
#endif
		static void NewProp_bIsArray_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsArray;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSIOJ_NamedType>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Name_MetaData[] = {
		{ "Category", "NamedType" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOJ_NamedType, Name), METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Name_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Name_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type_MetaData[] = {
		{ "Category", "NamedType" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOJ_NamedType, Type), Z_Construct_UEnum_SIOJEditorPlugin_ESIOJ_JsonType, METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type_MetaData)) }; // 2506965073
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray_MetaData[] = {
		{ "Category", "NamedType" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray_SetBit(void* Obj)
	{
		((FSIOJ_NamedType*)Obj)->bIsArray = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray = { "bIsArray", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(FSIOJ_NamedType), &Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Name,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_Type,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewProp_bIsArray,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SIOJEditorPlugin,
		nullptr,
		&NewStructOps,
		"SIOJ_NamedType",
		sizeof(FSIOJ_NamedType),
		alignof(FSIOJ_NamedType),
		Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSIOJ_NamedType()
	{
		if (!Z_Registration_Info_UScriptStruct_SIOJ_NamedType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SIOJ_NamedType.InnerSingleton, Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SIOJ_NamedType.InnerSingleton;
	}
	void USIOJ_BreakJson::StaticRegisterNativesUSIOJ_BreakJson()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USIOJ_BreakJson);
	UClass* Z_Construct_UClass_USIOJ_BreakJson_NoRegister()
	{
		return USIOJ_BreakJson::StaticClass();
	}
	struct Z_Construct_UClass_USIOJ_BreakJson_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Outputs_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Outputs_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_Outputs;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USIOJ_BreakJson_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UK2Node,
		(UObject* (*)())Z_Construct_UPackage__Script_SIOJEditorPlugin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USIOJ_BreakJson_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "SIOJ_BreakJson.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs_Inner = { "Outputs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FSIOJ_NamedType, METADATA_PARAMS(nullptr, 0) }; // 3082138665
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs_MetaData[] = {
		{ "Category", "PinOptions" },
		{ "ModuleRelativePath", "Public/SIOJ_BreakJson.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs = { "Outputs", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(USIOJ_BreakJson, Outputs), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs_MetaData)) }; // 3082138665
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_USIOJ_BreakJson_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_USIOJ_BreakJson_Statics::NewProp_Outputs,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_USIOJ_BreakJson_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USIOJ_BreakJson>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USIOJ_BreakJson_Statics::ClassParams = {
		&USIOJ_BreakJson::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_USIOJ_BreakJson_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_USIOJ_BreakJson_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USIOJ_BreakJson_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USIOJ_BreakJson_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USIOJ_BreakJson()
	{
		if (!Z_Registration_Info_UClass_USIOJ_BreakJson.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USIOJ_BreakJson.OuterSingleton, Z_Construct_UClass_USIOJ_BreakJson_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USIOJ_BreakJson.OuterSingleton;
	}
	template<> SIOJEDITORPLUGIN_API UClass* StaticClass<USIOJ_BreakJson>()
	{
		return USIOJ_BreakJson::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USIOJ_BreakJson);
	USIOJ_BreakJson::~USIOJ_BreakJson() {}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::EnumInfo[] = {
		{ ESIOJ_JsonType_StaticEnum, TEXT("ESIOJ_JsonType"), &Z_Registration_Info_UEnum_ESIOJ_JsonType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2506965073U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::ScriptStructInfo[] = {
		{ FSIOJ_NamedType::StaticStruct, Z_Construct_UScriptStruct_FSIOJ_NamedType_Statics::NewStructOps, TEXT("SIOJ_NamedType"), &Z_Registration_Info_UScriptStruct_SIOJ_NamedType, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSIOJ_NamedType), 3082138665U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USIOJ_BreakJson, USIOJ_BreakJson::StaticClass, TEXT("USIOJ_BreakJson"), &Z_Registration_Info_UClass_USIOJ_BreakJson, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USIOJ_BreakJson), 2135052118U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_4013059390(TEXT("/Script/SIOJEditorPlugin"),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJEditorPlugin_Public_SIOJ_BreakJson_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
