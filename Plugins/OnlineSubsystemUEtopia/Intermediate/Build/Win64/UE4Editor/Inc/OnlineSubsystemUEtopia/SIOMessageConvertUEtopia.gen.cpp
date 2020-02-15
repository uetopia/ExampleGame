// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineSubsystemUEtopia/Public/SIOMessageConvertUEtopia.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSIOMessageConvertUEtopia() {}
// Cross Module References
	ONLINESUBSYSTEMUETOPIA_API UClass* Z_Construct_UClass_USIOMessageConvertUEtopia_NoRegister();
	ONLINESUBSYSTEMUETOPIA_API UClass* Z_Construct_UClass_USIOMessageConvertUEtopia();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_OnlineSubsystemUEtopia();
// End Cross Module References
	void USIOMessageConvertUEtopia::StaticRegisterNativesUSIOMessageConvertUEtopia()
	{
	}
	UClass* Z_Construct_UClass_USIOMessageConvertUEtopia_NoRegister()
	{
		return USIOMessageConvertUEtopia::StaticClass();
	}
	struct Z_Construct_UClass_USIOMessageConvertUEtopia_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineSubsystemUEtopia,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "SIOMessageConvertUEtopia.h" },
		{ "ModuleRelativePath", "Public/SIOMessageConvertUEtopia.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USIOMessageConvertUEtopia>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::ClassParams = {
		&USIOMessageConvertUEtopia::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USIOMessageConvertUEtopia()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_USIOMessageConvertUEtopia_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(USIOMessageConvertUEtopia, 3362652800);
	template<> ONLINESUBSYSTEMUETOPIA_API UClass* StaticClass<USIOMessageConvertUEtopia>()
	{
		return USIOMessageConvertUEtopia::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_USIOMessageConvertUEtopia(Z_Construct_UClass_USIOMessageConvertUEtopia, &USIOMessageConvertUEtopia::StaticClass, TEXT("/Script/OnlineSubsystemUEtopia"), TEXT("USIOMessageConvertUEtopia"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(USIOMessageConvertUEtopia);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
