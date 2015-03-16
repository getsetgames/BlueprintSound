//
//  Created by Derek van Vliet on 2015-03-16.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "BlueprintSoundFunctions.generated.h"

UCLASS(NotBlueprintable)
class UBlueprintSoundFunctions : public UObject {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, meta = (Keywords = "sound sfx music audio volume"), Category = Sound)
	static void SetSoundClassVolume(USoundClass* SoundClass, float Volume);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "sound sfx music audio volume"), Category = Sound)
	static float GetSoundClassVolume(USoundClass* SoundClass);
};