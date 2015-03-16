//
//  Created by Derek van Vliet on 2015-03-16.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "BlueprintSoundPrivatePCH.h"

DEFINE_LOG_CATEGORY(LogBlueprintSound);

class FBlueprintSound : public IBlueprintSound
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FBlueprintSound, BlueprintSound )



void FBlueprintSound::StartupModule()
{
}


void FBlueprintSound::ShutdownModule()
{
}



