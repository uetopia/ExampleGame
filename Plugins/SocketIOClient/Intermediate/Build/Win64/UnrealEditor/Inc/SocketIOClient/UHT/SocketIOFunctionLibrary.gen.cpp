// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SocketIOClient/Public/SocketIOFunctionLibrary.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSocketIOFunctionLibrary() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	SIOJSON_API UClass* Z_Construct_UClass_USIOJsonValue_NoRegister();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOClientComponent_NoRegister();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOFunctionLibrary();
	SOCKETIOCLIENT_API UClass* Z_Construct_UClass_USocketIOFunctionLibrary_NoRegister();
	UPackage* Z_Construct_UPackage__Script_SocketIOClient();
// End Cross Module References
	DEFINE_FUNCTION(USocketIOFunctionLibrary::execCallFunctionByName)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_FunctionName);
		P_GET_OBJECT(UObject,Z_Param_Target);
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_GET_OBJECT(USIOJsonValue,Z_Param_Param);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=USocketIOFunctionLibrary::CallFunctionByName(Z_Param_FunctionName,Z_Param_Target,Z_Param_WorldContextObject,Z_Param_Param);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(USocketIOFunctionLibrary::execConstructSocketIOComponent)
	{
		P_GET_OBJECT(UObject,Z_Param_WorldContextObject);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(USocketIOClientComponent**)Z_Param__Result=USocketIOFunctionLibrary::ConstructSocketIOComponent(Z_Param_WorldContextObject);
		P_NATIVE_END;
	}
	void USocketIOFunctionLibrary::StaticRegisterNativesUSocketIOFunctionLibrary()
	{
		UClass* Class = USocketIOFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CallFunctionByName", &USocketIOFunctionLibrary::execCallFunctionByName },
			{ "ConstructSocketIOComponent", &USocketIOFunctionLibrary::execConstructSocketIOComponent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics
	{
		struct SocketIOFunctionLibrary_eventCallFunctionByName_Parms
		{
			FString FunctionName;
			UObject* Target;
			UObject* WorldContextObject;
			USIOJsonValue* Param;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FunctionName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_FunctionName;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Param;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName = { "FunctionName", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, FunctionName), METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName_MetaData)) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, Target), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Param = { "Param", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOFunctionLibrary_eventCallFunctionByName_Parms, Param), Z_Construct_UClass_USIOJsonValue_NoRegister, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((SocketIOFunctionLibrary_eventCallFunctionByName_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(SocketIOFunctionLibrary_eventCallFunctionByName_Parms), &Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_FunctionName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Target,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_Param,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Utility" },
		{ "Comment", "/** Call a function by name with SIOJsonValue signature. Utility for RPC in BPs*/" },
		{ "ModuleRelativePath", "Public/SocketIOFunctionLibrary.h" },
		{ "ToolTip", "Call a function by name with SIOJsonValue signature. Utility for RPC in BPs" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOFunctionLibrary, nullptr, "CallFunctionByName", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::SocketIOFunctionLibrary_eventCallFunctionByName_Parms), Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics
	{
		struct SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms
		{
			UObject* WorldContextObject;
			USocketIOClientComponent* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_WorldContextObject;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_WorldContextObject = { "WorldContextObject", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms, WorldContextObject), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms, ReturnValue), Z_Construct_UClass_USocketIOClientComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_WorldContextObject,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::Function_MetaDataParams[] = {
		{ "Category", "SocketIO Client Static" },
		{ "Comment", "/** Static function to spawn a component that doesn't attach */" },
		{ "ModuleRelativePath", "Public/SocketIOFunctionLibrary.h" },
		{ "ToolTip", "Static function to spawn a component that doesn't attach" },
		{ "WorldContext", "WorldContextObject" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_USocketIOFunctionLibrary, nullptr, "ConstructSocketIOComponent", nullptr, nullptr, sizeof(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::SocketIOFunctionLibrary_eventConstructSocketIOComponent_Parms), Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(USocketIOFunctionLibrary);
	UClass* Z_Construct_UClass_USocketIOFunctionLibrary_NoRegister()
	{
		return USocketIOFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_USocketIOFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_USocketIOFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_SocketIOClient,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_USocketIOFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_USocketIOFunctionLibrary_CallFunctionByName, "CallFunctionByName" }, // 3594494248
		{ &Z_Construct_UFunction_USocketIOFunctionLibrary_ConstructSocketIOComponent, "ConstructSocketIOComponent" }, // 2517686263
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_USocketIOFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * Static spawning support library\n */" },
		{ "IncludePath", "SocketIOFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/SocketIOFunctionLibrary.h" },
		{ "ToolTip", "Static spawning support library" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_USocketIOFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USocketIOFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_USocketIOFunctionLibrary_Statics::ClassParams = {
		&USocketIOFunctionLibrary::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_USocketIOFunctionLibrary_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_USocketIOFunctionLibrary_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_USocketIOFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_USocketIOFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USocketIOFunctionLibrary.OuterSingleton, Z_Construct_UClass_USocketIOFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_USocketIOFunctionLibrary.OuterSingleton;
	}
	template<> SOCKETIOCLIENT_API UClass* StaticClass<USocketIOFunctionLibrary>()
	{
		return USocketIOFunctionLibrary::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(USocketIOFunctionLibrary);
	USocketIOFunctionLibrary::~USocketIOFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_USocketIOFunctionLibrary, USocketIOFunctionLibrary::StaticClass, TEXT("USocketIOFunctionLibrary"), &Z_Registration_Info_UClass_USocketIOFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USocketIOFunctionLibrary), 3237029180U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_3321583262(TEXT("/Script/SocketIOClient"),
		Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_ExampleGame_5_1_0_Plugins_SocketIOClient_Source_SocketIOClient_Public_SocketIOFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
