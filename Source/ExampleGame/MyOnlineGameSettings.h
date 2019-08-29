// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Online.h"

/**
*
*/
/**
* General session settings 
*/
class FMyOnlineSessionSettings : public FOnlineSessionSettings
{
public:

	FMyOnlineSessionSettings(bool bIsLAN = false, bool bIsPresence = false, int32 MaxNumPlayers = 4);
	virtual ~FMyOnlineSessionSettings() {}
};

/**
* General search setting 
*/
class FMyOnlineSearchSettings : public FOnlineSessionSearch
{
public:
	FMyOnlineSearchSettings(bool bSearchingLAN = false, bool bSearchingPresence = false);

	virtual ~FMyOnlineSearchSettings() {}
};

/**
* Search settings for an empty dedicated server to host a match
*/
class FMyOnlineSearchSettingsEmptyDedicated : public FMyOnlineSearchSettings
{
public:
	FMyOnlineSearchSettingsEmptyDedicated(bool bSearchingLAN = false, bool bSearchingPresence = false);

	virtual ~FMyOnlineSearchSettingsEmptyDedicated() {}
};