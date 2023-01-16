// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CoreUtility/Public/CUBlueprintLibrary.h"
#include "Engine/Classes/Engine/LatentActionManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCUBlueprintLibrary() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	COREUTILITY_API UClass* Z_Construct_UClass_UCUBlueprintLibrary();
	COREUTILITY_API UClass* Z_Construct_UClass_UCUBlueprintLibrary_NoRegister();
	COREUTILITY_API UEnum* Z_Construct_UEnum_CoreUtility_EImageFormatBPType();
	COREUTILITY_API UEnum* Z_Construct_UEnum_CoreUtility_ESIOCallbackType();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	ENGINE_API UClass* Z_Construct_UClass_USoundWave_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USoundWaveProcedural_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FLatentActionInfo();
	UPackage* Z_Construct_UPackage__Script_CoreUtility();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EImageFormatBPType;
	static UEnum* EImageFormatBPType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EImageFormatBPType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EImageFormatBPType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CoreUtility_EImageFormatBPType, Z_Construct_UPackage__Script_CoreUtility(), TEXT("EImageFormatBPType"));
		}
		return Z_Registration_Info_UEnum_EImageFormatBPType.OuterSingleton;
	}
	template<> COREUTILITY_API UEnum* StaticEnum<EImageFormatBPType>()
	{
		return EImageFormatBPType_StaticEnum();
	}
	struct Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::Enumerators[] = {
		{ "EImageFormatBPType::Invalid", (int64)EImageFormatBPType::Invalid },
		{ "EImageFormatBPType::PNG", (int64)EImageFormatBPType::PNG },
		{ "EImageFormatBPType::JPEG", (int64)EImageFormatBPType::JPEG },
		{ "EImageFormatBPType::GrayscaleJPEG", (int64)EImageFormatBPType::GrayscaleJPEG },
		{ "EImageFormatBPType::BMP", (int64)EImageFormatBPType::BMP },
		{ "EImageFormatBPType::ICO", (int64)EImageFormatBPType::ICO },
		{ "EImageFormatBPType::EXR", (int64)EImageFormatBPType::EXR },
		{ "EImageFormatBPType::ICNS", (int64)EImageFormatBPType::ICNS },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::Enum_MetaDataParams[] = {
		{ "BMP.Comment", "/** Windows Bitmap. */" },
		{ "BMP.Name", "EImageFormatBPType::BMP" },
		{ "BMP.ToolTip", "Windows Bitmap." },
		{ "Comment", "/** Wrapper for EImageFormat::Type for BP */" },
		{ "EXR.Comment", "/** OpenEXR (HDR) image file format. */" },
		{ "EXR.Name", "EImageFormatBPType::EXR" },
		{ "EXR.ToolTip", "OpenEXR (HDR) image file format." },
		{ "GrayscaleJPEG.Comment", "/** Single channel JPEG. */" },
		{ "GrayscaleJPEG.Name", "EImageFormatBPType::GrayscaleJPEG" },
		{ "GrayscaleJPEG.ToolTip", "Single channel JPEG." },
		{ "ICNS.Comment", "/** Mac icon. */" },
		{ "ICNS.Name", "EImageFormatBPType::ICNS" },
		{ "ICNS.ToolTip", "Mac icon." },
		{ "ICO.Comment", "/** Windows Icon resource. */" },
		{ "ICO.Name", "EImageFormatBPType::ICO" },
		{ "ICO.ToolTip", "Windows Icon resource." },
		{ "Invalid.Comment", "/** Invalid or unrecognized format. */" },
		{ "Invalid.Name", "EImageFormatBPType::Invalid" },
		{ "Invalid.ToolTip", "Invalid or unrecognized format." },
		{ "JPEG.Comment", "/** Joint Photographic Experts Group. */" },
		{ "JPEG.Name", "EImageFormatBPType::JPEG" },
		{ "JPEG.ToolTip", "Joint Photographic Experts Group." },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "PNG.Comment", "/** Portable Network Graphics. */" },
		{ "PNG.Name", "EImageFormatBPType::PNG" },
		{ "PNG.ToolTip", "Portable Network Graphics." },
		{ "ToolTip", "Wrapper for EImageFormat::Type for BP" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_CoreUtility,
		nullptr,
		"EImageFormatBPType",
		"EImageFormatBPType",
		Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_CoreUtility_EImageFormatBPType()
	{
		if (!Z_Registration_Info_UEnum_EImageFormatBPType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EImageFormatBPType.InnerSingleton, Z_Construct_UEnum_CoreUtility_EImageFormatBPType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EImageFormatBPType.InnerSingleton;
	}
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_ESIOCallbackType;
	static UEnum* ESIOCallbackType_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_ESIOCallbackType.OuterSingleton)
		{
			Z_Registration_Info_UEnum_ESIOCallbackType.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_CoreUtility_ESIOCallbackType, Z_Construct_UPackage__Script_CoreUtility(), TEXT("ESIOCallbackType"));
		}
		return Z_Registration_Info_UEnum_ESIOCallbackType.OuterSingleton;
	}
	template<> COREUTILITY_API UEnum* StaticEnum<ESIOCallbackType>()
	{
		return ESIOCallbackType_StaticEnum();
	}
	struct Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::Enumerators[] = {
		{ "CALLBACK_GAME_THREAD", (int64)CALLBACK_GAME_THREAD },
		{ "CALLBACK_BACKGROUND_THREADPOOL", (int64)CALLBACK_BACKGROUND_THREADPOOL },
		{ "CALLBACK_BACKGROUND_TASKGRAPH", (int64)CALLBACK_BACKGROUND_TASKGRAPH },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::Enum_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "CALLBACK_BACKGROUND_TASKGRAPH.Name", "CALLBACK_BACKGROUND_TASKGRAPH" },
		{ "CALLBACK_BACKGROUND_THREADPOOL.Name", "CALLBACK_BACKGROUND_THREADPOOL" },
		{ "CALLBACK_GAME_THREAD.Name", "CALLBACK_GAME_THREAD" },
		{ "Comment", "/** Callback threading option */" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Callback threading option" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_CoreUtility,
		nullptr,
		"ESIOCallbackType",
		"ESIOCallbackType",
		Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::Enumerators,
		UE_ARRAY_COUNT(Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::Enumerators),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::Regular,
		METADATA_PARAMS(Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::Enum_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::Enum_MetaDataParams))
	};
	UEnum* Z_Construct_UEnum_CoreUtility_ESIOCallbackType()
	{
		if (!Z_Registration_Info_UEnum_ESIOCallbackType.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_ESIOCallbackType.InnerSingleton, Z_Construct_UEnum_CoreUtility_ESIOCallbackType_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_ESIOCallbackType.InnerSingleton;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execCallFunctionOnThreadGraphReturn)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Function);
		P_GET_PROPERTY(FByteProperty,Z_Param_ThreadType);
		P_GET_STRUCT(FLatentActionInfo,Z_Param_LatentInfo);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCUBlueprintLibrary::CallFunctionOnThreadGraphReturn(Z_Param_Function,ESIOCallbackType(Z_Param_ThreadType),Z_Param_LatentInfo,Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execCallFunctionOnThread)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Function);
		P_GET_PROPERTY(FByteProperty,Z_Param_ThreadType);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCUBlueprintLibrary::CallFunctionOnThread(Z_Param_Function,ESIOCallbackType(Z_Param_ThreadType),Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execMeasureTimerStop)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Category);
		P_GET_UBOOL(Z_Param_bShouldLogResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=UCUBlueprintLibrary::MeasureTimerStop(Z_Param_Category,Z_Param_bShouldLogResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execMeasureTimerStart)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_Category);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCUBlueprintLibrary::MeasureTimerStart(Z_Param_Category);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execToHashCode)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_String);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UCUBlueprintLibrary::ToHashCode(Z_Param_String);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execGetLoginId)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UCUBlueprintLibrary::GetLoginId();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execNowUTCString)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UCUBlueprintLibrary::NowUTCString();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_TextureToBytes)
	{
		P_GET_OBJECT(UTexture2D,Z_Param_Texture);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBuffer);
		P_GET_ENUM(EImageFormatBPType,Z_Param_Format);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UCUBlueprintLibrary::Conv_TextureToBytes(Z_Param_Texture,Z_Param_Out_OutBuffer,EImageFormatBPType(Z_Param_Format));
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execSetSoundWaveFromWavBytes)
	{
		P_GET_OBJECT(USoundWaveProcedural,Z_Param_InSoundWave);
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCUBlueprintLibrary::SetSoundWaveFromWavBytes(Z_Param_InSoundWave,Z_Param_Out_InBytes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_CompactPositionBytesToTransforms)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InCompactBytes);
		P_GET_TARRAY_REF(FTransform,Z_Param_Out_OutTransforms);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCUBlueprintLibrary::Conv_CompactPositionBytesToTransforms(Z_Param_Out_InCompactBytes,Z_Param_Out_OutTransforms);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_CompactBytesToTransforms)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InCompactBytes);
		P_GET_TARRAY_REF(FTransform,Z_Param_Out_OutTransforms);
		P_FINISH;
		P_NATIVE_BEGIN;
		UCUBlueprintLibrary::Conv_CompactBytesToTransforms(Z_Param_Out_InCompactBytes,Z_Param_Out_OutTransforms);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_SoundWaveToWavBytes)
	{
		P_GET_OBJECT(USoundWave,Z_Param_SoundWave);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=UCUBlueprintLibrary::Conv_SoundWaveToWavBytes(Z_Param_SoundWave);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_WavBytesToSoundWave)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USoundWave**)Z_Param__Result=UCUBlueprintLibrary::Conv_WavBytesToSoundWave(Z_Param_Out_InBytes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_WavBytesToOpus)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=UCUBlueprintLibrary::Conv_WavBytesToOpus(Z_Param_Out_InBytes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_OpusBytesToWav)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=UCUBlueprintLibrary::Conv_OpusBytesToWav(Z_Param_Out_InBytes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_BytesToTexture)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UTexture2D**)Z_Param__Result=UCUBlueprintLibrary::Conv_BytesToTexture(Z_Param_Out_InBytes);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_StringToBytes)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_InString);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<uint8>*)Z_Param__Result=UCUBlueprintLibrary::Conv_StringToBytes(Z_Param_InString);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UCUBlueprintLibrary::execConv_BytesToString)
	{
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UCUBlueprintLibrary::Conv_BytesToString(Z_Param_Out_InBytes);
		P_NATIVE_END;
	}
	void UCUBlueprintLibrary::StaticRegisterNativesUCUBlueprintLibrary()
	{
		UClass* Class = UCUBlueprintLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CallFunctionOnThread", &UCUBlueprintLibrary::execCallFunctionOnThread },
			{ "CallFunctionOnThreadGraphReturn", &UCUBlueprintLibrary::execCallFunctionOnThreadGraphReturn },
			{ "Conv_BytesToString", &UCUBlueprintLibrary::execConv_BytesToString },
			{ "Conv_BytesToTexture", &UCUBlueprintLibrary::execConv_BytesToTexture },
			{ "Conv_CompactBytesToTransforms", &UCUBlueprintLibrary::execConv_CompactBytesToTransforms },
			{ "Conv_CompactPositionBytesToTransforms", &UCUBlueprintLibrary::execConv_CompactPositionBytesToTransforms },
			{ "Conv_OpusBytesToWav", &UCUBlueprintLibrary::execConv_OpusBytesToWav },
			{ "Conv_SoundWaveToWavBytes", &UCUBlueprintLibrary::execConv_SoundWaveToWavBytes },
			{ "Conv_StringToBytes", &UCUBlueprintLibrary::execConv_StringToBytes },
			{ "Conv_TextureToBytes", &UCUBlueprintLibrary::execConv_TextureToBytes },
			{ "Conv_WavBytesToOpus", &UCUBlueprintLibrary::execConv_WavBytesToOpus },
			{ "Conv_WavBytesToSoundWave", &UCUBlueprintLibrary::execConv_WavBytesToSoundWave },
			{ "GetLoginId", &UCUBlueprintLibrary::execGetLoginId },
			{ "MeasureTimerStart", &UCUBlueprintLibrary::execMeasureTimerStart },
			{ "MeasureTimerStop", &UCUBlueprintLibrary::execMeasureTimerStop },
			{ "NowUTCString", &UCUBlueprintLibrary::execNowUTCString },
			{ "SetSoundWaveFromWavBytes", &UCUBlueprintLibrary::execSetSoundWaveFromWavBytes },
			{ "ToHashCode", &UCUBlueprintLibrary::execToHashCode },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics
	{
		struct CUBlueprintLibrary_eventCallFunctionOnThread_Parms
		{
			FString Function;
			TEnumAsByte<ESIOCallbackType> ThreadType;
			UObject* WorldContextObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Function;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ThreadType;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_Function_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThread_Parms, Function), METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_Function_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_Function_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_ThreadType = { "ThreadType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThread_Parms, ThreadType), Z_Construct_UEnum_CoreUtility_ESIOCallbackType, METADATA_PARAMS(nullptr, 0) }; // 1557208721
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThread_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_Function,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_ThreadType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Threading" },
		{ "Comment", "/** \n\x09*\x09""Calls function by name given calling context on thread specified. Use e.g. delay (0) to return to game thread\n\x09*\x09or use game thread callback for threadtype. This allows you to run certain functions on a background thread or\n\x09*\x09taskgraph in blueprints. Keep in mind that you should not create or destroy UObjects non-game threads.\n\x09*/" },
		{ "CPP_Default_WorldContextObject", "None" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Calls function by name given calling context on thread specified. Use e.g. delay (0) to return to game thread\nor use game thread callback for threadtype. This allows you to run certain functions on a background thread or\ntaskgraph in blueprints. Keep in mind that you should not create or destroy UObjects non-game threads." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "CallFunctionOnThread", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::CUBlueprintLibrary_eventCallFunctionOnThread_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics
	{
		struct CUBlueprintLibrary_eventCallFunctionOnThreadGraphReturn_Parms
		{
			FString Function;
			TEnumAsByte<ESIOCallbackType> ThreadType;
			FLatentActionInfo LatentInfo;
			UObject* WorldContextObject;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Function_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Function;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ThreadType;
		static const UECodeGen_Private::FStructPropertyParams NewProp_LatentInfo;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_Function_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_Function = { "Function", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThreadGraphReturn_Parms, Function), METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_Function_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_Function_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_ThreadType = { "ThreadType", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThreadGraphReturn_Parms, ThreadType), Z_Construct_UEnum_CoreUtility_ESIOCallbackType, METADATA_PARAMS(nullptr, 0) }; // 1557208721
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_LatentInfo = { "LatentInfo", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThreadGraphReturn_Parms, LatentInfo), Z_Construct_UScriptStruct_FLatentActionInfo, METADATA_PARAMS(nullptr, 0) }; // 2194022737
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventCallFunctionOnThreadGraphReturn_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_Function,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_ThreadType,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_LatentInfo,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::NewProp_WorldContextObject,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Threading" },
		{ "Comment", "/**\n\x09*\x09""Calls specified function on thread type with a latent graph return. This allows you to run certain functions on a background thread or\n\x09*\x09taskgraph in blueprints. Keep in mind that you should not create or destroy UObjects non-game threads.\n\x09*/" },
		{ "CPP_Default_WorldContextObject", "None" },
		{ "Latent", "" },
		{ "LatentInfo", "LatentInfo" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Calls specified function on thread type with a latent graph return. This allows you to run certain functions on a background thread or\ntaskgraph in blueprints. Keep in mind that you should not create or destroy UObjects non-game threads." },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "CallFunctionOnThreadGraphReturn", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::CUBlueprintLibrary_eventCallFunctionOnThreadGraphReturn_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics
	{
		struct CUBlueprintLibrary_eventConv_BytesToString_Parms
		{
			TArray<uint8> InBytes;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_BytesToString_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes_MetaData)) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_BytesToString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_InBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Convert any unicode bytes to string\n\x09*/" },
		{ "DisplayName", "To String (Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Convert any unicode bytes to string" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_BytesToString", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::CUBlueprintLibrary_eventConv_BytesToString_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics
	{
		struct CUBlueprintLibrary_eventConv_BytesToTexture_Parms
		{
			TArray<uint8> InBytes;
			UTexture2D* ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_BytesToTexture_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_BytesToTexture_Parms, ReturnValue), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_InBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Convert bytes to UTexture2D using auto-detection - optimized, but can still have performance implication\n\x09*/" },
		{ "DisplayName", "To Texture2D (Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Convert bytes to UTexture2D using auto-detection - optimized, but can still have performance implication" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_BytesToTexture", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::CUBlueprintLibrary_eventConv_BytesToTexture_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics
	{
		struct CUBlueprintLibrary_eventConv_CompactBytesToTransforms_Parms
		{
			TArray<uint8> InCompactBytes;
			TArray<FTransform> OutTransforms;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InCompactBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InCompactBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InCompactBytes;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransforms_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutTransforms;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes_Inner = { "InCompactBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes = { "InCompactBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_CompactBytesToTransforms_Parms, InCompactBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_OutTransforms_Inner = { "OutTransforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_OutTransforms = { "OutTransforms", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_CompactBytesToTransforms_Parms, OutTransforms), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_InCompactBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_OutTransforms_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::NewProp_OutTransforms,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/** \n\x09* Compact Transform bytes are [[pitch,yaw,roll,x,y,z,sx,sy,sz],...]\n\x09*/" },
		{ "DisplayName", "To Transforms (Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Compact Transform bytes are [[pitch,yaw,roll,x,y,z,sx,sy,sz],...]" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_CompactBytesToTransforms", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::CUBlueprintLibrary_eventConv_CompactBytesToTransforms_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics
	{
		struct CUBlueprintLibrary_eventConv_CompactPositionBytesToTransforms_Parms
		{
			TArray<uint8> InCompactBytes;
			TArray<FTransform> OutTransforms;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InCompactBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InCompactBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InCompactBytes;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutTransforms_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutTransforms;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes_Inner = { "InCompactBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes = { "InCompactBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_CompactPositionBytesToTransforms_Parms, InCompactBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes_MetaData)) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_OutTransforms_Inner = { "OutTransforms", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_OutTransforms = { "OutTransforms", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_CompactPositionBytesToTransforms_Parms, OutTransforms), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_InCompactBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_OutTransforms_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::NewProp_OutTransforms,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/** \n\x09* Compact Position bytes are [[x,y,z],...]\n\x09*/" },
		{ "DisplayName", "To Transforms (Location Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Compact Position bytes are [[x,y,z],...]" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_CompactPositionBytesToTransforms", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::CUBlueprintLibrary_eventConv_CompactPositionBytesToTransforms_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics
	{
		struct CUBlueprintLibrary_eventConv_OpusBytesToWav_Parms
		{
			TArray<uint8> InBytes;
			TArray<uint8> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_OpusBytesToWav_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_OpusBytesToWav_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_InBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Audio compression - Convert opus (currently raw serialized) to pcm\n\x09*/" },
		{ "DisplayName", "To Wav Bytes (Opus Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Audio compression - Convert opus (currently raw serialized) to pcm" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_OpusBytesToWav", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::CUBlueprintLibrary_eventConv_OpusBytesToWav_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics
	{
		struct CUBlueprintLibrary_eventConv_SoundWaveToWavBytes_Parms
		{
			USoundWave* SoundWave;
			TArray<uint8> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SoundWave;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::NewProp_SoundWave = { "SoundWave", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_SoundWaveToWavBytes_Parms, SoundWave), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_SoundWaveToWavBytes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::NewProp_SoundWave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""convert a soundwave into wav bytes\n\x09*/" },
		{ "DisplayName", "To Bytes (SoundWave)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "convert a soundwave into wav bytes" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_SoundWaveToWavBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::CUBlueprintLibrary_eventConv_SoundWaveToWavBytes_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics
	{
		struct CUBlueprintLibrary_eventConv_StringToBytes_Parms
		{
			FString InString;
			TArray<uint8> ReturnValue;
		};
		static const UECodeGen_Private::FStrPropertyParams NewProp_InString;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::NewProp_InString = { "InString", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_StringToBytes_Parms, InString), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_StringToBytes_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::NewProp_InString,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Convert string to UTF8 bytes\n\x09*/" },
		{ "DisplayName", "To Bytes (String)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Convert string to UTF8 bytes" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_StringToBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::CUBlueprintLibrary_eventConv_StringToBytes_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics
	{
		struct CUBlueprintLibrary_eventConv_TextureToBytes_Parms
		{
			UTexture2D* Texture;
			TArray<uint8> OutBuffer;
			EImageFormatBPType Format;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Texture;
		static const UECodeGen_Private::FBytePropertyParams NewProp_OutBuffer_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutBuffer;
		static const UECodeGen_Private::FBytePropertyParams NewProp_Format_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_Format;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_Texture = { "Texture", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_TextureToBytes_Parms, Texture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_OutBuffer_Inner = { "OutBuffer", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_OutBuffer = { "OutBuffer", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_TextureToBytes_Parms, OutBuffer), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_Format_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_Format = { "Format", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_TextureToBytes_Parms, Format), Z_Construct_UEnum_CoreUtility_EImageFormatBPType, METADATA_PARAMS(nullptr, 0) }; // 1958437916
	void Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((CUBlueprintLibrary_eventConv_TextureToBytes_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(CUBlueprintLibrary_eventConv_TextureToBytes_Parms), &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_Texture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_OutBuffer_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_OutBuffer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_Format_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_Format,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Convert UTexture2D to bytes in given format - can have performance implication\n\x09*/" },
		{ "CPP_Default_Format", "PNG" },
		{ "DisplayName", "To Bytes (Texture2D)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Convert UTexture2D to bytes in given format - can have performance implication" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_TextureToBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::CUBlueprintLibrary_eventConv_TextureToBytes_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics
	{
		struct CUBlueprintLibrary_eventConv_WavBytesToOpus_Parms
		{
			TArray<uint8> InBytes;
			TArray<uint8> ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
		static const UECodeGen_Private::FBytePropertyParams NewProp_ReturnValue_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_WavBytesToOpus_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes_MetaData)) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_WavBytesToOpus_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_InBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Audio decompression - Convert wav to opus (currently raw serialized)\n\x09*/" },
		{ "DisplayName", "To Opus Bytes (Wav Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Audio decompression - Convert wav to opus (currently raw serialized)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_WavBytesToOpus", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::CUBlueprintLibrary_eventConv_WavBytesToOpus_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics
	{
		struct CUBlueprintLibrary_eventConv_WavBytesToSoundWave_Parms
		{
			TArray<uint8> InBytes;
			USoundWave* ReturnValue;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_WavBytesToSoundWave_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventConv_WavBytesToSoundWave_Parms, ReturnValue), Z_Construct_UClass_USoundWave_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_InBytes,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::Function_MetaDataParams[] = {
		{ "BlueprintAutocast", "" },
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09""Assumes .wav chunks - handles async alloc, callable from any thread\n\x09*/" },
		{ "DisplayName", "To SoundWave (Wav Bytes)" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Assumes .wav chunks - handles async alloc, callable from any thread" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "Conv_WavBytesToSoundWave", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::CUBlueprintLibrary_eventConv_WavBytesToSoundWave_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics
	{
		struct CUBlueprintLibrary_eventGetLoginId_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventGetLoginId_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Misc" },
		{ "Comment", "/**\n\x09* Returns a type of Unique Hardware ID\n\x09*/" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Returns a type of Unique Hardware ID" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "GetLoginId", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::CUBlueprintLibrary_eventGetLoginId_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics
	{
		struct CUBlueprintLibrary_eventMeasureTimerStart_Parms
		{
			FString Category;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::NewProp_Category_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventMeasureTimerStart_Parms, Category), METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::NewProp_Category_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::NewProp_Category_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::NewProp_Category,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Misc" },
		{ "Comment", "/**\n\x09* Time inter-tick durations for simple\n\x09*/" },
		{ "CPP_Default_Category", "TimeTaken" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Time inter-tick durations for simple" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "MeasureTimerStart", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::CUBlueprintLibrary_eventMeasureTimerStart_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics
	{
		struct CUBlueprintLibrary_eventMeasureTimerStop_Parms
		{
			FString Category;
			bool bShouldLogResult;
			float ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Category_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_Category;
		static void NewProp_bShouldLogResult_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShouldLogResult;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_Category_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_Category = { "Category", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventMeasureTimerStop_Parms, Category), METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_Category_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_Category_MetaData)) };
	void Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_bShouldLogResult_SetBit(void* Obj)
	{
		((CUBlueprintLibrary_eventMeasureTimerStop_Parms*)Obj)->bShouldLogResult = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_bShouldLogResult = { "bShouldLogResult", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(CUBlueprintLibrary_eventMeasureTimerStop_Parms), &Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_bShouldLogResult_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventMeasureTimerStop_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_Category,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_bShouldLogResult,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Misc" },
		{ "Comment", "/** \n\x09* Stops the timer started for this category and returns the duration taken in milliseconds \n\x09*/" },
		{ "CPP_Default_bShouldLogResult", "true" },
		{ "CPP_Default_Category", "TimeTaken" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Stops the timer started for this category and returns the duration taken in milliseconds" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "MeasureTimerStop", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::CUBlueprintLibrary_eventMeasureTimerStop_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics
	{
		struct CUBlueprintLibrary_eventNowUTCString_Parms
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
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventNowUTCString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Misc" },
		{ "Comment", "/**\n\x09*\x09""Current UTC time in string format\n\x09*/" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Current UTC time in string format" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "NowUTCString", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::CUBlueprintLibrary_eventNowUTCString_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics
	{
		struct CUBlueprintLibrary_eventSetSoundWaveFromWavBytes_Parms
		{
			USoundWaveProcedural* InSoundWave;
			TArray<uint8> InBytes;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InSoundWave;
		static const UECodeGen_Private::FBytePropertyParams NewProp_InBytes_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InBytes_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InBytes;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InSoundWave = { "InSoundWave", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventSetSoundWaveFromWavBytes_Parms, InSoundWave), Z_Construct_UClass_USoundWaveProcedural_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes_Inner = { "InBytes", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes = { "InBytes", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventSetSoundWaveFromWavBytes_Parms, InBytes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InSoundWave,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::NewProp_InBytes,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Conversion" },
		{ "Comment", "/**\n\x09*\x09Sets and updates soundwave if needed from incoming bytes. Callable on background threads\n\x09*/" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Sets and updates soundwave if needed from incoming bytes. Callable on background threads" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "SetSoundWaveFromWavBytes", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::CUBlueprintLibrary_eventSetSoundWaveFromWavBytes_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics
	{
		struct CUBlueprintLibrary_eventToHashCode_Parms
		{
			FString String;
			int32 ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_String_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_String;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_String_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_String = { "String", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventToHashCode_Parms, String), METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_String_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_String_MetaData)) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(CUBlueprintLibrary_eventToHashCode_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_String,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::Function_MetaDataParams[] = {
		{ "Category", "CoreUtility|Misc" },
		{ "Comment", "/** \n\x09* Return a somewhat unique int for given string\n\x09*/" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Return a somewhat unique int for given string" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCUBlueprintLibrary, nullptr, "ToHashCode", nullptr, nullptr, sizeof(Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::CUBlueprintLibrary_eventToHashCode_Parms), Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCUBlueprintLibrary);
	UClass* Z_Construct_UClass_UCUBlueprintLibrary_NoRegister()
	{
		return UCUBlueprintLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UCUBlueprintLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCUBlueprintLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_CoreUtility,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UCUBlueprintLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThread, "CallFunctionOnThread" }, // 328418004
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_CallFunctionOnThreadGraphReturn, "CallFunctionOnThreadGraphReturn" }, // 3529146088
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToString, "Conv_BytesToString" }, // 2998466251
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_BytesToTexture, "Conv_BytesToTexture" }, // 1952912162
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactBytesToTransforms, "Conv_CompactBytesToTransforms" }, // 2642532528
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_CompactPositionBytesToTransforms, "Conv_CompactPositionBytesToTransforms" }, // 701991390
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_OpusBytesToWav, "Conv_OpusBytesToWav" }, // 1380564726
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_SoundWaveToWavBytes, "Conv_SoundWaveToWavBytes" }, // 494662131
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_StringToBytes, "Conv_StringToBytes" }, // 3927817281
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_TextureToBytes, "Conv_TextureToBytes" }, // 258764319
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToOpus, "Conv_WavBytesToOpus" }, // 2661646646
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_Conv_WavBytesToSoundWave, "Conv_WavBytesToSoundWave" }, // 2003763617
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_GetLoginId, "GetLoginId" }, // 3348935402
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStart, "MeasureTimerStart" }, // 3881759645
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_MeasureTimerStop, "MeasureTimerStop" }, // 2360454829
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_NowUTCString, "NowUTCString" }, // 1420582068
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_SetSoundWaveFromWavBytes, "SetSoundWaveFromWavBytes" }, // 1987366196
		{ &Z_Construct_UFunction_UCUBlueprintLibrary_ToHashCode, "ToHashCode" }, // 3851712973
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCUBlueprintLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Useful generic blueprint functions, mostly conversion\n */" },
		{ "IncludePath", "CUBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/CUBlueprintLibrary.h" },
		{ "ToolTip", "Useful generic blueprint functions, mostly conversion" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCUBlueprintLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCUBlueprintLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCUBlueprintLibrary_Statics::ClassParams = {
		&UCUBlueprintLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UCUBlueprintLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UCUBlueprintLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UCUBlueprintLibrary()
	{
		if (!Z_Registration_Info_UClass_UCUBlueprintLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCUBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UCUBlueprintLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCUBlueprintLibrary.OuterSingleton;
	}
	template<> COREUTILITY_API UClass* StaticClass<UCUBlueprintLibrary>()
	{
		return UCUBlueprintLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCUBlueprintLibrary);
	UCUBlueprintLibrary::~UCUBlueprintLibrary() {}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics::EnumInfo[] = {
		{ EImageFormatBPType_StaticEnum, TEXT("EImageFormatBPType"), &Z_Registration_Info_UEnum_EImageFormatBPType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1958437916U) },
		{ ESIOCallbackType_StaticEnum, TEXT("ESIOCallbackType"), &Z_Registration_Info_UEnum_ESIOCallbackType, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 1557208721U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCUBlueprintLibrary, UCUBlueprintLibrary::StaticClass, TEXT("UCUBlueprintLibrary"), &Z_Registration_Info_UClass_UCUBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCUBlueprintLibrary), 1752464376U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_3588609594(TEXT("/Script/CoreUtility"),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
