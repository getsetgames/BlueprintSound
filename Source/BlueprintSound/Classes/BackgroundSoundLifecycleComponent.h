//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "BackgroundSoundLifecycleComponent.generated.h"

UCLASS(ClassGroup=Advertising, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UBackgroundSoundLifecycleComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	DECLARE_MULTICAST_DELEGATE(FBackgroundSoundDelegate);
	
	static FBackgroundSoundDelegate AudioInterruptionBeganDelegate;
	static FBackgroundSoundDelegate AudioInterruptionEndedDelegate;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBackgroundSoundDynDelegate);
	
	UPROPERTY(BlueprintAssignable)
	FBackgroundSoundDynDelegate AudioInterruptionBegan;
	
	UPROPERTY(BlueprintAssignable)
	FBackgroundSoundDynDelegate AudioInterruptionEnded;
	
	void OnRegister() override;
	void OnUnregister() override;
	
private:
	
	void AudioInterruptionBegan_Handler() { AudioInterruptionBegan.Broadcast(); }
	void AudioInterruptionEnded_Handler() { AudioInterruptionEnded.Broadcast(); }
};
