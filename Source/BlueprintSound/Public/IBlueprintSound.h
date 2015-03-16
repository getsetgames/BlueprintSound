//
//  Created by Derek van Vliet on 2015-03-16.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ModuleManager.h"

class IBlueprintSound : public IModuleInterface
{

public:

	static inline IBlueprintSound& Get()
	{
		return FModuleManager::LoadModuleChecked< IBlueprintSound >( "BlueprintSound" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "BlueprintSound" );
	}
};

