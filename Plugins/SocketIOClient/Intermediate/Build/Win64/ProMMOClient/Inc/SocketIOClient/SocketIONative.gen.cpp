// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SocketIONative.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIONative() {}
// Cross Module References
	SOCKETIOCLIENT_API UEnum* Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
// End Cross Module References
	static UEnum* ESIOConnectionCloseReason_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason, Z_Construct_UPackage__Script_SocketIOClient(), TEXT("ESIOConnectionCloseReason"));
		}
		return Singleton;
	}
	template<> SOCKETIOCLIENT_API UEnum* StaticEnum<ESIOConnectionCloseReason>()
	{
		return ESIOConnectionCloseReason_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ESIOConnectionCloseReason(ESIOConnectionCloseReason_StaticEnum, TEXT("/Script/SocketIOClient"), TEXT("ESIOConnectionCloseReason"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Hash() { return 2604996341U; }
	UEnum* Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_SocketIOClient();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ESIOConnectionCloseReason"), 0, Get_Z_Construct_UEnum_SocketIOClient_ESIOConnectionCloseReason_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "CLOSE_REASON_NORMAL", (int64)CLOSE_REASON_NORMAL },
				{ "CLOSE_REASON_DROP", (int64)CLOSE_REASON_DROP },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/SocketIONative.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_SocketIOClient,
				nullptr,
				"ESIOConnectionCloseReason",
				"ESIOConnectionCloseReason",
				Enumerators,
				ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
