// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef SIOJSON_SIOJTypes_generated_h
#error "SIOJTypes.generated.h already included, missing '#pragma once' in SIOJTypes.h"
#endif
#define SIOJSON_SIOJTypes_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID ExampleGame_4_24_Plugins_SocketIOClient_Source_SIOJson_Public_SIOJTypes_h


#define FOREACH_ENUM_ESIOREQUESTSTATUS(op) \
	op(ESIORequestStatus::NotStarted) \
	op(ESIORequestStatus::Processing) \
	op(ESIORequestStatus::Failed) \
	op(ESIORequestStatus::Failed_ConnectionError) \
	op(ESIORequestStatus::Succeeded) 

enum class ESIORequestStatus : uint8;
template<> SIOJSON_API UEnum* StaticEnum<ESIORequestStatus>();

#define FOREACH_ENUM_ESIOREQUESTCONTENTTYPE(op) \
	op(ESIORequestContentType::x_www_form_urlencoded_url) \
	op(ESIORequestContentType::x_www_form_urlencoded_body) \
	op(ESIORequestContentType::json) \
	op(ESIORequestContentType::binary) 

enum class ESIORequestContentType : uint8;
template<> SIOJSON_API UEnum* StaticEnum<ESIORequestContentType>();

#define FOREACH_ENUM_ESIOREQUESTVERB(op) \
	op(ESIORequestVerb::GET) \
	op(ESIORequestVerb::POST) \
	op(ESIORequestVerb::PUT) \
	op(ESIORequestVerb::DEL) \
	op(ESIORequestVerb::CUSTOM) 

enum class ESIORequestVerb : uint8;
template<> SIOJSON_API UEnum* StaticEnum<ESIORequestVerb>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
