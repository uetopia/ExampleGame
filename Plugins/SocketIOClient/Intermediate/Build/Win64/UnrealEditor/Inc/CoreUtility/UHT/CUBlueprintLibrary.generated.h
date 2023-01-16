// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CUBlueprintLibrary.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class USoundWave;
class USoundWaveProcedural;
class UTexture2D;
enum class EImageFormatBPType : uint8;
struct FLatentActionInfo;
#ifdef COREUTILITY_CUBlueprintLibrary_generated_h
#error "CUBlueprintLibrary.generated.h already included, missing '#pragma once' in CUBlueprintLibrary.h"
#endif
#define COREUTILITY_CUBlueprintLibrary_generated_h

#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_SPARSE_DATA
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execCallFunctionOnThreadGraphReturn); \
	DECLARE_FUNCTION(execCallFunctionOnThread); \
	DECLARE_FUNCTION(execMeasureTimerStop); \
	DECLARE_FUNCTION(execMeasureTimerStart); \
	DECLARE_FUNCTION(execToHashCode); \
	DECLARE_FUNCTION(execGetLoginId); \
	DECLARE_FUNCTION(execNowUTCString); \
	DECLARE_FUNCTION(execConv_TextureToBytes); \
	DECLARE_FUNCTION(execSetSoundWaveFromWavBytes); \
	DECLARE_FUNCTION(execConv_CompactPositionBytesToTransforms); \
	DECLARE_FUNCTION(execConv_CompactBytesToTransforms); \
	DECLARE_FUNCTION(execConv_SoundWaveToWavBytes); \
	DECLARE_FUNCTION(execConv_WavBytesToSoundWave); \
	DECLARE_FUNCTION(execConv_WavBytesToOpus); \
	DECLARE_FUNCTION(execConv_OpusBytesToWav); \
	DECLARE_FUNCTION(execConv_BytesToTexture); \
	DECLARE_FUNCTION(execConv_StringToBytes); \
	DECLARE_FUNCTION(execConv_BytesToString);


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execCallFunctionOnThreadGraphReturn); \
	DECLARE_FUNCTION(execCallFunctionOnThread); \
	DECLARE_FUNCTION(execMeasureTimerStop); \
	DECLARE_FUNCTION(execMeasureTimerStart); \
	DECLARE_FUNCTION(execToHashCode); \
	DECLARE_FUNCTION(execGetLoginId); \
	DECLARE_FUNCTION(execNowUTCString); \
	DECLARE_FUNCTION(execConv_TextureToBytes); \
	DECLARE_FUNCTION(execSetSoundWaveFromWavBytes); \
	DECLARE_FUNCTION(execConv_CompactPositionBytesToTransforms); \
	DECLARE_FUNCTION(execConv_CompactBytesToTransforms); \
	DECLARE_FUNCTION(execConv_SoundWaveToWavBytes); \
	DECLARE_FUNCTION(execConv_WavBytesToSoundWave); \
	DECLARE_FUNCTION(execConv_WavBytesToOpus); \
	DECLARE_FUNCTION(execConv_OpusBytesToWav); \
	DECLARE_FUNCTION(execConv_BytesToTexture); \
	DECLARE_FUNCTION(execConv_StringToBytes); \
	DECLARE_FUNCTION(execConv_BytesToString);


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_ACCESSORS
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCUBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UCUBlueprintLibrary_Statics; \
public: \
	DECLARE_CLASS(UCUBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CoreUtility"), NO_API) \
	DECLARE_SERIALIZER(UCUBlueprintLibrary)


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_INCLASS \
private: \
	static void StaticRegisterNativesUCUBlueprintLibrary(); \
	friend struct Z_Construct_UClass_UCUBlueprintLibrary_Statics; \
public: \
	DECLARE_CLASS(UCUBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/CoreUtility"), NO_API) \
	DECLARE_SERIALIZER(UCUBlueprintLibrary)


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCUBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCUBlueprintLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCUBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCUBlueprintLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCUBlueprintLibrary(UCUBlueprintLibrary&&); \
	NO_API UCUBlueprintLibrary(const UCUBlueprintLibrary&); \
public: \
	NO_API virtual ~UCUBlueprintLibrary();


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCUBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCUBlueprintLibrary(UCUBlueprintLibrary&&); \
	NO_API UCUBlueprintLibrary(const UCUBlueprintLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCUBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCUBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCUBlueprintLibrary) \
	NO_API virtual ~UCUBlueprintLibrary();


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_52_PROLOG
#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_SPARSE_DATA \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_RPC_WRAPPERS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_ACCESSORS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_INCLASS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_SPARSE_DATA \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_ACCESSORS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_INCLASS_NO_PURE_DECLS \
	FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h_55_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COREUTILITY_API UClass* StaticClass<class UCUBlueprintLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_CoreUtility_Public_CUBlueprintLibrary_h


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
template<> struct TIsUEnumClass<EImageFormatBPType> { enum { Value = true }; };
template<> COREUTILITY_API UEnum* StaticEnum<EImageFormatBPType>();

#define FOREACH_ENUM_ESIOCALLBACKTYPE(op) \
	op(CALLBACK_GAME_THREAD) \
	op(CALLBACK_BACKGROUND_THREADPOOL) \
	op(CALLBACK_BACKGROUND_TASKGRAPH) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
