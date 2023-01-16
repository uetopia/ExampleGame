// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIOClient_init() {}
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature();
	SOCKETIOCLIENT_API UFunction* Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_SocketIOClient;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_SocketIOClient()
	{
		if (!Z_Registration_Info_UPackage__Script_SocketIOClient.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOCCloseEventSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventJsonSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOCEventSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOConnectionProblemSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOCOpenEventSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOCSocketEventSignature__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SocketIOClient_SIOJsonValueSignature__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/SocketIOClient",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x3E74AF50,
				0x2637AFC2,
				METADATA_PARAMS(nullptr, 0)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_SocketIOClient.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_SocketIOClient.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_SocketIOClient(Z_Construct_UPackage__Script_SocketIOClient, TEXT("/Script/SocketIOClient"), Z_Registration_Info_UPackage__Script_SocketIOClient, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x3E74AF50, 0x2637AFC2));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
