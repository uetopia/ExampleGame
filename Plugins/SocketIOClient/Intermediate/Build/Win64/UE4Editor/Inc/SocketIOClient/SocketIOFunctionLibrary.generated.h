// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UObject;
class USocketIOClientComponent;
#ifdef SOCKETIOCLIENT_SocketIOFunctionLibrary_generated_h
#error "SocketIOFunctionLibrary.generated.h already included, missing '#pragma once' in SocketIOFunctionLibrary.h"
#endif
#define SOCKETIOCLIENT_SocketIOFunctionLibrary_generated_h

#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_SPARSE_DATA
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execConstructSocketIOComponent) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USocketIOClientComponent**)Z_Param__Result=USocketIOFunctionLibrary::ConstructSocketIOComponent(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execConstructSocketIOComponent) \
	{ \
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(USocketIOClientComponent**)Z_Param__Result=USocketIOFunctionLibrary::ConstructSocketIOComponent(Z_Param_WorldContextObject); \
		P_NATIVE_END; \
	}


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUSocketIOFunctionLibrary(); \
	friend struct Z_Construct_UClass_USocketIOFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USocketIOFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SocketIOClient"), NO_API) \
	DECLARE_SERIALIZER(USocketIOFunctionLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUSocketIOFunctionLibrary(); \
	friend struct Z_Construct_UClass_USocketIOFunctionLibrary_Statics; \
public: \
	DECLARE_CLASS(USocketIOFunctionLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/SocketIOClient"), NO_API) \
	DECLARE_SERIALIZER(USocketIOFunctionLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USocketIOFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USocketIOFunctionLibrary) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USocketIOFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USocketIOFunctionLibrary); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USocketIOFunctionLibrary(USocketIOFunctionLibrary&&); \
	NO_API USocketIOFunctionLibrary(const USocketIOFunctionLibrary&); \
public:


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USocketIOFunctionLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API USocketIOFunctionLibrary(USocketIOFunctionLibrary&&); \
	NO_API USocketIOFunctionLibrary(const USocketIOFunctionLibrary&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USocketIOFunctionLibrary); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USocketIOFunctionLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USocketIOFunctionLibrary)


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_PRIVATE_PROPERTY_OFFSET
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_13_PROLOG
#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_RPC_WRAPPERS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_INCLASS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_PRIVATE_PROPERTY_OFFSET \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_SPARSE_DATA \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_INCLASS_NO_PURE_DECLS \
	ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> SOCKETIOCLIENT_API UClass* StaticClass<class USocketIOFunctionLibrary>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_24_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
