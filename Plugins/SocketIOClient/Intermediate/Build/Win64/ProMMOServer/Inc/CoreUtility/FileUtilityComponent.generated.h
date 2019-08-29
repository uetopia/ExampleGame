// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COREUTILITY_FileUtilityComponent_generated_h
#error "FileUtilityComponent.generated.h already included, missing '#pragma once' in FileUtilityComponent.h"
#endif
#define COREUTILITY_FileUtilityComponent_generated_h

#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execReadBytesFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Directory); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReadBytesFromFile(Z_Param_Directory,Z_Param_FileName,Z_Param_Out_OutBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveBytesToFile) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Directory); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SaveBytesToFile(Z_Param_Out_Bytes,Z_Param_Directory,Z_Param_FileName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProjectSavedDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ProjectSavedDirectory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProjectDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ProjectDirectory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProjectContentsDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ProjectContentsDirectory(); \
		P_NATIVE_END; \
	}


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execReadBytesFromFile) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_Directory); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_OutBytes); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->ReadBytesFromFile(Z_Param_Directory,Z_Param_FileName,Z_Param_Out_OutBytes); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSaveBytesToFile) \
	{ \
		P_GET_TARRAY_REF(uint8,Z_Param_Out_Bytes); \
		P_GET_PROPERTY(UStrProperty,Z_Param_Directory); \
		P_GET_PROPERTY(UStrProperty,Z_Param_FileName); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=P_THIS->SaveBytesToFile(Z_Param_Out_Bytes,Z_Param_Directory,Z_Param_FileName); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProjectSavedDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ProjectSavedDirectory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProjectDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ProjectDirectory(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execProjectContentsDirectory) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(FString*)Z_Param__Result=P_THIS->ProjectContentsDirectory(); \
		P_NATIVE_END; \
	}


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUFileUtilityComponent(); \
	friend struct Z_Construct_UClass_UFileUtilityComponent_Statics; \
public: \
	DECLARE_CLASS(UFileUtilityComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CoreUtility"), NO_API) \
	DECLARE_SERIALIZER(UFileUtilityComponent)


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUFileUtilityComponent(); \
	friend struct Z_Construct_UClass_UFileUtilityComponent_Statics; \
public: \
	DECLARE_CLASS(UFileUtilityComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/CoreUtility"), NO_API) \
	DECLARE_SERIALIZER(UFileUtilityComponent)


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFileUtilityComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFileUtilityComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFileUtilityComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFileUtilityComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFileUtilityComponent(UFileUtilityComponent&&); \
	NO_API UFileUtilityComponent(const UFileUtilityComponent&); \
public:


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UFileUtilityComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UFileUtilityComponent(UFileUtilityComponent&&); \
	NO_API UFileUtilityComponent(const UFileUtilityComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UFileUtilityComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UFileUtilityComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UFileUtilityComponent)


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_PRIVATE_PROPERTY_OFFSET
#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_12_PROLOG
#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_RPC_WRAPPERS \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_INCLASS \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_PRIVATE_PROPERTY_OFFSET \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_INCLASS_NO_PURE_DECLS \
	ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h_15_ENHANCED_CONSTRUCTORS \
static_assert(false, "Unknown access specifier for GENERATED_BODY() macro in class FileUtilityComponent."); \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COREUTILITY_API UClass* StaticClass<class UFileUtilityComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ProMMO_4_22_2_Plugins_SocketIOClient_Source_CoreUtility_Public_FileUtilityComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
