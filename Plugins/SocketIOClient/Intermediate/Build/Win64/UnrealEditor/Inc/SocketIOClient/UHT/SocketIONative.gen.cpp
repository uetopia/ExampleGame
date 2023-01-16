// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SocketIONative.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIONative() {}
// Cross Module References
	SOCKETIOCLIENT_API UEnum* Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason();
	SOCKETIOCLIENT_API UEnum* Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIOConnectionCloseReason;
	static UEnum* ESIOConnectionCloseReason_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIOConnectionCloseReason.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIOConnectionCloseReason.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason, Z_Construct_UPackage__Script_SocketIOClient(), TEXT("ESIOConnectionCloseReason"));
		}
		return Z_Registration_Info_UEnum_ESIOConnectionCloseReason.OuterSingleton;
	}
	template<> SOCKETIOCLIENT_API UEnum* StaticEnum<ESIOConnectionCloseReason>()
	{
		return ESIOConnectionCloseReason_StaticEnum();
	}
	struct Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::Enumerators[] = {
		{ "CLOSE_REASON_NORMAL", (int64)CLOSE_REASON_NORMAL },
		{ "CLOSE_REASON_DROP", (int64)CLOSE_REASON_DROP },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CLOSE_REASON_DROP.Name", "CLOSE_REASON_DROP" },
		{ "CLOSE_REASON_NORMAL.Name", "CLOSE_REASON_NORMAL" },
		{ "ModuleRelativePath", "Public/SocketIONative.h" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient,
		nullptr,
		"ESIOConnectionCloseReason",
		"ESIOConnectionCloseReason",
		Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason()
	{
		if (!Z_Registration_Info_UEnum_ESIOConnectionCloseReason.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIOConnectionCloseReason.InnerSingleton, Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIOConnectionCloseReason.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIOThreadOverrideOption;
	static UEnum* ESIOThreadOverrideOption_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIOThreadOverrideOption.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIOThreadOverrideOption.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption, Z_Construct_UPackage__Script_SocketIOClient(), TEXT("ESIOThreadOverrideOption"));
		}
		return Z_Registration_Info_UEnum_ESIOThreadOverrideOption.OuterSingleton;
	}
	template<> SOCKETIOCLIENT_API UEnum* StaticEnum<ESIOThreadOverrideOption>()
	{
		return ESIOThreadOverrideOption_StaticEnum();
	}
	struct Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::Enumerators[] = {
		{ "USE_DEFAULT", (int64)USE_DEFAULT },
		{ "USE_GAME_THREAD", (int64)USE_GAME_THREAD },
		{ "USE_NETWORK_THREAD", (int64)USE_NETWORK_THREAD },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/SocketIONative.h" },
		{ "USE_DEFAULT.Name", "USE_DEFAULT" },
		{ "USE_GAME_THREAD.Name", "USE_GAME_THREAD" },
		{ "USE_NETWORK_THREAD.Name", "USE_NETWORK_THREAD" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient,
		nullptr,
		"ESIOThreadOverrideOption",
		"ESIOThreadOverrideOption",
		Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption()
	{
		if (!Z_Registration_Info_UEnum_ESIOThreadOverrideOption.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIOThreadOverrideOption.InnerSingleton, Z_Construct_UEnum_SocketIOClient_ESIOThreadOverrideOption_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIOThreadOverrideOption.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIONative_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIONative_h_Statics::EnumInfo[] = {
		{ ESIOConnectionCloseReason_StaticEnum, TEXT("ESIOConnectionCloseReason"), &Z_Registration_Info_UEnum_ESIOConnectionCloseReason, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2130267029U) },
		{ ESIOThreadOverrideOption_StaticEnum, TEXT("ESIOThreadOverrideOption"), &Z_Registration_Info_UEnum_ESIOThreadOverrideOption, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 2897981721U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIONative_h_1674234479(TEXT("/Script/SocketIOClient"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIONative_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIONative_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
