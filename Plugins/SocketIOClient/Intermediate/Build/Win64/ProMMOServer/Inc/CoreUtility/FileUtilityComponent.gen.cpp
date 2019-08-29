// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CoreUtility/Public/FileUtilityComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFileUtilityComponent() {}
// Cross Module References
	COREUTILITY_API UClass* Z_Construct_UClass_UFileUtilityComponent_NoRegister();
	COREUTILITY_API UClass* Z_Construct_UClass_UFileUtilityComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_CoreUtility();
	COREUTILITY_API UFunction* Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory();
	COREUTILITY_API UFunction* Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory();
	COREUTILITY_API UFunction* Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory();
	COREUTILITY_API UFunction* Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile();
	COREUTILITY_API UFunction* Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile();
// End Cross Module References
	void UFileUtilityComponent::StaticRegisterNativesUFileUtilityComponent()
	{
		UClass* Class = UFileUtilityComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ProjectContentsDirectory", &UFileUtilityComponent::execProjectContentsDirectory },
			{ "ProjectDirectory", &UFileUtilityComponent::execProjectDirectory },
			{ "ProjectSavedDirectory", &UFileUtilityComponent::execProjectSavedDirectory },
			{ "ReadBytesFromFile", &UFileUtilityComponent::execReadBytesFromFile },
			{ "SaveBytesToFile", &UFileUtilityComponent::execSaveBytesToFile },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics
	{
		struct FileUtilityComponent_eventProjectContentsDirectory_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventProjectContentsDirectory_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::Function_MetaDataParams[] = {
		{ "Category", "FileUtility" },
		{ "ModuleRelativePath", "Public/FileUtilityComponent.h" },
		{ "ToolTip", "Get the current project contents directory path" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileUtilityComponent, nullptr, "ProjectContentsDirectory", sizeof(FileUtilityComponent_eventProjectContentsDirectory_Parms), Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics
	{
		struct FileUtilityComponent_eventProjectDirectory_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventProjectDirectory_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::Function_MetaDataParams[] = {
		{ "Category", "FileUtility" },
		{ "ModuleRelativePath", "Public/FileUtilityComponent.h" },
		{ "ToolTip", "Get the current project directory path" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileUtilityComponent, nullptr, "ProjectDirectory", sizeof(FileUtilityComponent_eventProjectDirectory_Parms), Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics
	{
		struct FileUtilityComponent_eventProjectSavedDirectory_Parms
		{
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventProjectSavedDirectory_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::Function_MetaDataParams[] = {
		{ "Category", "FileUtility" },
		{ "ModuleRelativePath", "Public/FileUtilityComponent.h" },
		{ "ToolTip", "Get the current project saved directory path" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileUtilityComponent, nullptr, "ProjectSavedDirectory", sizeof(FileUtilityComponent_eventProjectSavedDirectory_Parms), Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics
	{
		struct FileUtilityComponent_eventReadBytesFromFile_Parms
		{
			FString Directory;
			FString FileName;
			TArray<uint8> OutBytes;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutBytes;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_OutBytes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Directory_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Directory;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FileUtilityComponent_eventReadBytesFromFile_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FileUtilityComponent_eventReadBytesFromFile_Parms), &Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_OutBytes = { "OutBytes", nullptr, (EPropertyFlags)0x0010000000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventReadBytesFromFile_Parms, OutBytes), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_OutBytes_Inner = { "OutBytes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventReadBytesFromFile_Parms, FileName), METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_FileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_FileName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_Directory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventReadBytesFromFile_Parms, Directory), METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_Directory_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_Directory_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_OutBytes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_OutBytes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_FileName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::NewProp_Directory,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "FileUtility" },
		{ "ModuleRelativePath", "Public/FileUtilityComponent.h" },
		{ "ToolTip", "Read array of bytes from file at specified directory" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileUtilityComponent, nullptr, "ReadBytesFromFile", sizeof(FileUtilityComponent_eventReadBytesFromFile_Parms), Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics
	{
		struct FileUtilityComponent_eventSaveBytesToFile_Parms
		{
			TArray<uint8> Bytes;
			FString Directory;
			FString FileName;
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FileName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FileName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Directory_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Directory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Bytes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Bytes;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Bytes_Inner;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FileUtilityComponent_eventSaveBytesToFile_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FileUtilityComponent_eventSaveBytesToFile_Parms), &Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_FileName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_FileName = { "FileName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventSaveBytesToFile_Parms, FileName), METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_FileName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_FileName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Directory_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Directory = { "Directory", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventSaveBytesToFile_Parms, Directory), METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Directory_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Directory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes = { "Bytes", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FileUtilityComponent_eventSaveBytesToFile_Parms, Bytes), METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes_MetaData, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes_Inner = { "Bytes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_FileName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Directory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::NewProp_Bytes_Inner,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::Function_MetaDataParams[] = {
		{ "Category", "FileUtility" },
		{ "ModuleRelativePath", "Public/FileUtilityComponent.h" },
		{ "ToolTip", "Save array of bytes to file at specified directory" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFileUtilityComponent, nullptr, "SaveBytesToFile", sizeof(FileUtilityComponent_eventSaveBytesToFile_Parms), Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFileUtilityComponent_NoRegister()
	{
		return UFileUtilityComponent::StaticClass();
	}
	struct Z_Construct_UClass_UFileUtilityComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFileUtilityComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_CoreUtility,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFileUtilityComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFileUtilityComponent_ProjectContentsDirectory, "ProjectContentsDirectory" }, // 3161017070
		{ &Z_Construct_UFunction_UFileUtilityComponent_ProjectDirectory, "ProjectDirectory" }, // 412593675
		{ &Z_Construct_UFunction_UFileUtilityComponent_ProjectSavedDirectory, "ProjectSavedDirectory" }, // 1663658188
		{ &Z_Construct_UFunction_UFileUtilityComponent_ReadBytesFromFile, "ReadBytesFromFile" }, // 3052797175
		{ &Z_Construct_UFunction_UFileUtilityComponent_SaveBytesToFile, "SaveBytesToFile" }, // 1310397160
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFileUtilityComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Utility" },
		{ "IncludePath", "FileUtilityComponent.h" },
		{ "ModuleRelativePath", "Public/FileUtilityComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFileUtilityComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFileUtilityComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFileUtilityComponent_Statics::ClassParams = {
		&UFileUtilityComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UFileUtilityComponent_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_UFileUtilityComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFileUtilityComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFileUtilityComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFileUtilityComponent, 886538857);
	template<> COREUTILITY_API UClass* StaticClass<UFileUtilityComponent>()
	{
		return UFileUtilityComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFileUtilityComponent(Z_Construct_UClass_UFileUtilityComponent, &UFileUtilityComponent::StaticClass, TEXT("/Script/CoreUtility"), TEXT("UFileUtilityComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFileUtilityComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
