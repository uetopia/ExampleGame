// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class UTexture2D;
enum class EImageFormatBPType : uint8;
class USoundWaveProcedural;
class USoundWave;
#ifdef COREUTILITY_CoreUtilityBPLibrary_generated_h
#error "CoreUtilityBPLibrary.generated.h already included, missing '#pragma once' in CoreUtilityBPLibrary.h"
#endif
#define COREUTILITY_CoreUtilityBPLibrary_generated_h

#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_SPARSE_DATA
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCallFunctionOnThread) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Function); \
		P_GET_PROPERTY(UByteProperty,Z_Param_ThreadType); \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCoreUtilityBPLibrary::CallFunctionOnThread(Z_Param_Function,ESIOCallbackType(Z_Param_ThreadType),Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLoginId) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UCoreUtilityBPLibrary::GetLoginId(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNowUTCString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UCoreUtilityBPLibrary::NowUTCString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_TextureToBytes) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBuffer); \
		P_GET_ENUM(EImageFormatBPType,Z_Param_Format); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_TextureToBytes(Z_Param_Texture,Z_Param_Out_OutBuffer,EImageFormatBPType(Z_Param_Format)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSoundWaveFromWavBytes) \
	{ \
		P_GET_OBJECT(USoundWaveProcedural,Z_Param_InSoundWave); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCoreUtilityBPLibrary::SetSoundWaveFromWavBytes(Z_Param_InSoundWave,Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_SoundWaveToWavBytes) \
	{ \
		P_GET_OBJECT(USoundWave,Z_Param_SoundWave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_SoundWaveToWavBytes(Z_Param_SoundWave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_WavBytesToSoundWave) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundWave**)Z_Param__Result=UCoreUtilityBPLibrary::Conv_WavBytesToSoundWave(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_WavBytesToOpus) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_WavBytesToOpus(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_OpusBytesToWav) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_OpusBytesToWav(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BytesToTexture) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=UCoreUtilityBPLibrary::Conv_BytesToTexture(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_StringToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_StringToBytes(Z_Param_InString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BytesToString) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_BytesToString(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCallFunctionOnThread) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Function); \
		P_GET_PROPERTY(UByteProperty,Z_Param_ThreadType); \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCoreUtilityBPLibrary::CallFunctionOnThread(Z_Param_Function,ESIOCallbackType(Z_Param_ThreadType),Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetLoginId) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UCoreUtilityBPLibrary::GetLoginId(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execNowUTCString) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UCoreUtilityBPLibrary::NowUTCString(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_TextureToBytes) \
	{ \
		P_GET_OBJECT(UTexture2D,Z_Param_Texture); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBuffer); \
		P_GET_ENUM(EImageFormatBPType,Z_Param_Format); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_TextureToBytes(Z_Param_Texture,Z_Param_Out_OutBuffer,EImageFormatBPType(Z_Param_Format)); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetSoundWaveFromWavBytes) \
	{ \
		P_GET_OBJECT(USoundWaveProcedural,Z_Param_InSoundWave); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		UCoreUtilityBPLibrary::SetSoundWaveFromWavBytes(Z_Param_InSoundWave,Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_SoundWaveToWavBytes) \
	{ \
		P_GET_OBJECT(USoundWave,Z_Param_SoundWave); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_SoundWaveToWavBytes(Z_Param_SoundWave); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_WavBytesToSoundWave) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USoundWave**)Z_Param__Result=UCoreUtilityBPLibrary::Conv_WavBytesToSoundWave(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_WavBytesToOpus) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_WavBytesToOpus(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_OpusBytesToWav) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_OpusBytesToWav(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BytesToTexture) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(UTexture2D**)Z_Param__Result=UCoreUtilityBPLibrary::Conv_BytesToTexture(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_StringToBytes) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_InString); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(TArray<uint8>*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_StringToBytes(Z_Param_InString); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execConv_BytesToString) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_InBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=UCoreUtilityBPLibrary::Conv_BytesToString(Z_Param_Out_InBytes); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCoreUtilityBPLibrary(); \
	friend struct Z_Construct_UClass_UCoreUtilityBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UCoreUtilityBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CoreUtility"), NO_API) \
	DECLARE_SERIALIZER(UCoreUtilityBPLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_INCLASS \
private: \
	static void StaticRegisterNativesUCoreUtilityBPLibrary(); \
	friend struct Z_Construct_UClass_UCoreUtilityBPLibrary_Statics; \
public: \
	DECLARE_CLASS(UCoreUtilityBPLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CoreUtility"), NO_API) \
	DECLARE_SERIALIZER(UCoreUtilityBPLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCoreUtilityBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCoreUtilityBPLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCoreUtilityBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCoreUtilityBPLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCoreUtilityBPLibrary(UCoreUtilityBPLibrary&&); \
	NO_API UCoreUtilityBPLibrary(const UCoreUtilityBPLibrary&); \
public:


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCoreUtilityBPLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCoreUtilityBPLibrary(UCoreUtilityBPLibrary&&); \
	NO_API UCoreUtilityBPLibrary(const UCoreUtilityBPLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCoreUtilityBPLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCoreUtilityBPLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCoreUtilityBPLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_PRIVATE_PROPERTY_OFFSET
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_51_PROLOG
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_RPC_WRAPPERS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_INCLASS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h_54_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COREUTILITY_API UClass* StaticClass<class UCoreUtilityBPLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_24_Plugins_SocketIOClient_Source_CoreUtility_Public_CoreUtilityBPLibrary_h


#define FOREACH_ENUM_ESIOCALLBACKTYPE(op) \
	op(CALLBACK_GAME_THREAD) \
	op(CALLBACK_BACKGROUND_THREADPOOL) \
	op(CALLBACK_BACKGROUND_TASKGRAPH) 
#define FOREACH_ENUM_EIMAGEFORMATBPTYPE(op) \
	op(EImageFormatBPType::Invalid) \
	op(EImageFormatBPType::PNG) \
	op(EImageFormatBPType::JPEG) \
	op(EImageFormatBPType::GrayscaleJPEG) \
	op(EImageFormatBPType::BMP) \
	op(EImageFormatBPType::ICO) \
	op(EImageFormatBPType::EXR) \
	op(EImageFormatBPType::ICNS) 

enum class EImageFormatBPType : uint8;
template<> COREUTILITY_API UEnum* StaticEnum<EImageFormatBPType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
