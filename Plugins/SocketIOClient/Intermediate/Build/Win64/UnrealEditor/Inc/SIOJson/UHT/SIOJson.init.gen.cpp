// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIOJson_init() {}
	SIOJSON_API UFunction* Z_Construct_UDelegateFunction_SIOJson_OnRequestComplete__DelegateSignature();
	SIOJSON_API UFunction* Z_Construct_UDelegateFunction_SIOJson_OnRequestFail__DelegateSignature();
	SIOJSON_API UFunction* Z_Construct_UDelegateFunction_SIOJson_SIOJCallDelegate__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SIOJson;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SIOJson()
	{
		if (!Z_Registration_Info_UPackage__Script_SIOJson.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SIOJson_OnRequestComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SIOJson_OnRequestFail__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SIOJson_SIOJCallDelegate__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SIOJson",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0xF6D6FC37,
				0x9C575898,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SIOJson.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SIOJson.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SIOJson(Z_Construct_UPackage__Script_SIOJson, TEXT("/Script/SIOJson"), Z_Registration_Info_UPackage__Script_SIOJson, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0xF6D6FC37, 0x9C575898));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
