// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SIOJson/Public/SIOJTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIOJTypes() {}
// Cross Module References
	SIOJSON_API UEnum* Z_Construct_UEnum_SIOJson_ESIORequestContentType();
	SIOJSON_API UEnum* Z_Construct_UEnum_SIOJson_ESIORequestStatus();
	SIOJSON_API UEnum* Z_Construct_UEnum_SIOJson_ESIORequestVerb();
	UPackage* Z_Construct_UPackage__Script_SIOJson();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIORequestVerb;
	static UEnum* ESIORequestVerb_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIORequestVerb.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIORequestVerb.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SIOJson_ESIORequestVerb, Z_Construct_UPackage__Script_SIOJson(), TEXT("ESIORequestVerb"));
		}
		return Z_Registration_Info_UEnum_ESIORequestVerb.OuterSingleton;
	}
	template<> SIOJSON_API UEnum* StaticEnum<ESIORequestVerb>()
	{
		return ESIORequestVerb_StaticEnum();
	}
	struct Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::Enumerators[] = {
		{ "ESIORequestVerb::GET", (int64)ESIORequestVerb::GET },
		{ "ESIORequestVerb::POST", (int64)ESIORequestVerb::POST },
		{ "ESIORequestVerb::PUT", (int64)ESIORequestVerb::PUT },
		{ "ESIORequestVerb::DEL", (int64)ESIORequestVerb::DEL },
		{ "ESIORequestVerb::CUSTOM", (int64)ESIORequestVerb::CUSTOM },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Verb (GET, PUT, POST) used by the request */" },
		{ "CUSTOM.Comment", "/** Set CUSTOM verb by SetCustomVerb() function */" },
		{ "CUSTOM.Name", "ESIORequestVerb::CUSTOM" },
		{ "CUSTOM.ToolTip", "Set CUSTOM verb by SetCustomVerb() function" },
		{ "DEL.DisplayName", "DELETE" },
		{ "DEL.Name", "ESIORequestVerb::DEL" },
		{ "GET.Name", "ESIORequestVerb::GET" },
		{ "ModuleRelativePath", "Public/SIOJTypes.h" },
		{ "POST.Name", "ESIORequestVerb::POST" },
		{ "PUT.Name", "ESIORequestVerb::PUT" },
		{ "ToolTip", "Verb (GET, PUT, POST) used by the request" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SIOJson,
		nullptr,
		"ESIORequestVerb",
		"ESIORequestVerb",
		Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SIOJson_ESIORequestVerb()
	{
		if (!Z_Registration_Info_UEnum_ESIORequestVerb.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIORequestVerb.InnerSingleton, Z_Construct_UEnum_SIOJson_ESIORequestVerb_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIORequestVerb.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIORequestContentType;
	static UEnum* ESIORequestContentType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIORequestContentType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIORequestContentType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SIOJson_ESIORequestContentType, Z_Construct_UPackage__Script_SIOJson(), TEXT("ESIORequestContentType"));
		}
		return Z_Registration_Info_UEnum_ESIORequestContentType.OuterSingleton;
	}
	template<> SIOJSON_API UEnum* StaticEnum<ESIORequestContentType>()
	{
		return ESIORequestContentType_StaticEnum();
	}
	struct Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::Enumerators[] = {
		{ "ESIORequestContentType::x_www_form_urlencoded_url", (int64)ESIORequestContentType::x_www_form_urlencoded_url },
		{ "ESIORequestContentType::x_www_form_urlencoded_body", (int64)ESIORequestContentType::x_www_form_urlencoded_body },
		{ "ESIORequestContentType::json", (int64)ESIORequestContentType::json },
		{ "ESIORequestContentType::binary", (int64)ESIORequestContentType::binary },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::Enum_MetaDataParams[] = {
		{ "binary.Name", "ESIORequestContentType::binary" },
		{ "BlueprintType", "true" },
		{ "Comment", "/** Content type (json, urlencoded, etc.) used by the request */" },
		{ "json.Name", "ESIORequestContentType::json" },
		{ "ModuleRelativePath", "Public/SIOJTypes.h" },
		{ "ToolTip", "Content type (json, urlencoded, etc.) used by the request" },
		{ "x_www_form_urlencoded_body.DisplayName", "x-www-form-urlencoded (Request Body)" },
		{ "x_www_form_urlencoded_body.Name", "ESIORequestContentType::x_www_form_urlencoded_body" },
		{ "x_www_form_urlencoded_url.DisplayName", "x-www-form-urlencoded (URL)" },
		{ "x_www_form_urlencoded_url.Name", "ESIORequestContentType::x_www_form_urlencoded_url" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SIOJson,
		nullptr,
		"ESIORequestContentType",
		"ESIORequestContentType",
		Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SIOJson_ESIORequestContentType()
	{
		if (!Z_Registration_Info_UEnum_ESIORequestContentType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIORequestContentType.InnerSingleton, Z_Construct_UEnum_SIOJson_ESIORequestContentType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIORequestContentType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIORequestStatus;
	static UEnum* ESIORequestStatus_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIORequestStatus.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIORequestStatus.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_SIOJson_ESIORequestStatus, Z_Construct_UPackage__Script_SIOJson(), TEXT("ESIORequestStatus"));
		}
		return Z_Registration_Info_UEnum_ESIORequestStatus.OuterSingleton;
	}
	template<> SIOJSON_API UEnum* StaticEnum<ESIORequestStatus>()
	{
		return ESIORequestStatus_StaticEnum();
	}
	struct Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::Enumerators[] = {
		{ "ESIORequestStatus::NotStarted", (int64)ESIORequestStatus::NotStarted },
		{ "ESIORequestStatus::Processing", (int64)ESIORequestStatus::Processing },
		{ "ESIORequestStatus::Failed", (int64)ESIORequestStatus::Failed },
		{ "ESIORequestStatus::Failed_ConnectionError", (int64)ESIORequestStatus::Failed_ConnectionError },
		{ "ESIORequestStatus::Succeeded", (int64)ESIORequestStatus::Succeeded },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Enumerates the current state of an Http request */" },
		{ "Failed.Comment", "/** Finished but failed */" },
		{ "Failed.Name", "ESIORequestStatus::Failed" },
		{ "Failed.ToolTip", "Finished but failed" },
		{ "Failed_ConnectionError.Comment", "/** Failed because it was unable to connect (safe to retry) */" },
		{ "Failed_ConnectionError.Name", "ESIORequestStatus::Failed_ConnectionError" },
		{ "Failed_ConnectionError.ToolTip", "Failed because it was unable to connect (safe to retry)" },
		{ "ModuleRelativePath", "Public/SIOJTypes.h" },
		{ "NotStarted.Comment", "/** Has not been started via ProcessRequest() */" },
		{ "NotStarted.Name", "ESIORequestStatus::NotStarted" },
		{ "NotStarted.ToolTip", "Has not been started via ProcessRequest()" },
		{ "Processing.Comment", "/** Currently being ticked and processed */" },
		{ "Processing.Name", "ESIORequestStatus::Processing" },
		{ "Processing.ToolTip", "Currently being ticked and processed" },
		{ "Succeeded.Comment", "/** Finished and was successful */" },
		{ "Succeeded.Name", "ESIORequestStatus::Succeeded" },
		{ "Succeeded.ToolTip", "Finished and was successful" },
		{ "ToolTip", "Enumerates the current state of an Http request" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_SIOJson,
		nullptr,
		"ESIORequestStatus",
		"ESIORequestStatus",
		Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_SIOJson_ESIORequestStatus()
	{
		if (!Z_Registration_Info_UEnum_ESIORequestStatus.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIORequestStatus.InnerSingleton, Z_Construct_UEnum_SIOJson_ESIORequestStatus_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIORequestStatus.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJTypes_h_Statics::EnumInfo[] = {
		{ ESIORequestVerb_StaticEnum, TEXT("ESIORequestVerb"), &Z_Registration_Info_UEnum_ESIORequestVerb, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3403366913U) },
		{ ESIORequestContentType_StaticEnum, TEXT("ESIORequestContentType"), &Z_Registration_Info_UEnum_ESIORequestContentType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3220947699U) },
		{ ESIORequestStatus_StaticEnum, TEXT("ESIORequestStatus"), &Z_Registration_Info_UEnum_ESIORequestStatus, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3705329646U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJTypes_h_2857355322(TEXT("/Script/SIOJson"),
		nullptr, 0,
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
