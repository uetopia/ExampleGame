// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SIOMessageConvert.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIOMessageConvert() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USIOMessageConvert();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USIOMessageConvert_NoRegister();
	SOCKETIOCLIENT_API UScriptStruct* Z_Construct_UScriptStruct_FSIOConnectParams();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_SIOConnectParams;
class UScriptStruct* FSIOConnectParams::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_SIOConnectParams.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_SIOConnectParams.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSIOConnectParams, Z_Construct_UPackage__Script_SocketIOClient(), TEXT("SIOConnectParams"));
	}
	return Z_Registration_Info_UScriptStruct_SIOConnectParams.OuterSingleton;
}
template<> SOCKETIOCLIENT_API UScriptStruct* StaticStruct<FSIOConnectParams>()
{
	return FSIOConnectParams::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FSIOConnectParams_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AddressAndPort_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AddressAndPort;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Query_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Query_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Query_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Query;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Headers_ValueProp;
		static const UECodeGen_Private::FStrPropertyParams NewProp_Headers_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Headers_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_Headers;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AuthToken_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_AuthToken;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Path_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Path;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOConnectParams_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** \n* All params defining a connection URL.\n*/" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "All params defining a connection URL." },
	};
#endif
	void* Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSIOConnectParams>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AddressAndPort_MetaData[] = {
		{ "Category", "SocketIOConnectionParams" },
		{ "Comment", "/** Default connection address string in form e.g. http://localhost:80. */" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "Default connection address string in form e.g. http://localhost:80." },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AddressAndPort = { "AddressAndPort", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOConnectParams, AddressAndPort), METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AddressAndPort_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AddressAndPort_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_ValueProp = { "Query", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_Key_KeyProp = { "Query_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_MetaData[] = {
		{ "Category", "SocketIOConnectionParams" },
		{ "Comment", "/** A map of query parameters to be added to connection url*/" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "A map of query parameters to be added to connection url" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query = { "Query", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOConnectParams, Query), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_ValueProp = { "Headers", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_Key_KeyProp = { "Headers_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_MetaData[] = {
		{ "Category", "SocketIOConnectionParams" },
		{ "Comment", "/** A map of headers to be added to connection url*/" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "A map of headers to be added to connection url" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers = { "Headers", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOConnectParams, Headers), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AuthToken_MetaData[] = {
		{ "Category", "SocketIOConnectionParams" },
		{ "Comment", "/** Optional authorization JSON to send to the server upon initial connection*/" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "Optional authorization JSON to send to the server upon initial connection" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AuthToken = { "AuthToken", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOConnectParams, AuthToken), METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AuthToken_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AuthToken_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Path_MetaData[] = {
		{ "Category", "SocketIOConnectionParams" },
		{ "Comment", "/** Optional path part of URL string. Default is 'socket.io'*/" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "Optional path part of URL string. Default is 'socket.io'" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Path = { "Path", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(FSIOConnectParams, Path), METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Path_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Path_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSIOConnectParams_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AddressAndPort,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Query,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Headers,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_AuthToken,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewProp_Path,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSIOConnectParams_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_SocketIOClient,
		nullptr,
		&NewStructOps,
		"SIOConnectParams",
		sizeof(FSIOConnectParams),
		alignof(FSIOConnectParams),
		Z_Construct_UScriptStruct_FSIOConnectParams_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000201),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSIOConnectParams_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FSIOConnectParams()
	{
		if (!Z_Registration_Info_UScriptStruct_SIOConnectParams.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_SIOConnectParams.InnerSingleton, Z_Construct_UScriptStruct_FSIOConnectParams_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_SIOConnectParams.InnerSingleton;
	}
	void USIOMessageConvert::StaticRegisterNativesUSIOMessageConvert()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USIOMessageConvert);
	UClass* Z_Construct_UClass_USIOMessageConvert_NoRegister()
	{
		return USIOMessageConvert::StaticClass();
	}
	struct Z_Construct_UClass_USIOMessageConvert_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USIOMessageConvert_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketIOClient,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USIOMessageConvert_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Static Conversion Utilities\n */" },
		{ "IncludePath", "SIOMessageConvert.h" },
		{ "ModuleRelativePath", "Public/SIOMessageConvert.h" },
		{ "ToolTip", "Static Conversion Utilities" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USIOMessageConvert_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USIOMessageConvert>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USIOMessageConvert_Statics::ClassParams = {
		&USIOMessageConvert::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_USIOMessageConvert_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USIOMessageConvert_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USIOMessageConvert()
	{
		if (!Z_Registration_Info_UClass_USIOMessageConvert.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USIOMessageConvert.OuterSingleton, Z_Construct_UClass_USIOMessageConvert_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USIOMessageConvert.OuterSingleton;
	}
	template<> SOCKETIOCLIENT_API UClass* StaticClass<USIOMessageConvert>()
	{
		return USIOMessageConvert::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USIOMessageConvert);
	USIOMessageConvert::~USIOMessageConvert() {}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics::ScriptStructInfo[] = {
		{ FSIOConnectParams::StaticStruct, Z_Construct_UScriptStruct_FSIOConnectParams_Statics::NewStructOps, TEXT("SIOConnectParams"), &Z_Registration_Info_UScriptStruct_SIOConnectParams, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSIOConnectParams), 1720379169U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USIOMessageConvert, USIOMessageConvert::StaticClass, TEXT("USIOMessageConvert"), &Z_Registration_Info_UClass_USIOMessageConvert, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USIOMessageConvert), 1376561220U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_263549292(TEXT("/Script/SocketIOClient"),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SIOMessageConvert_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
