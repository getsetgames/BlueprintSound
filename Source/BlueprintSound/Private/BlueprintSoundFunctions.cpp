//
//  Created by Derek van Vliet on 2015-03-16.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "BlueprintSoundPrivatePCH.h"

#if PLATFORM_IOS
#include <AVFoundation/AVAudioSession.h>
#elif PLATFORM_ANDROID

#endif

void UBlueprintSoundFunctions::SetSoundClassVolume(USoundClass* SoundClass, float Volume)
{
	if (SoundClass)
	{
		SoundClass->Properties.Volume = Volume;
	}
}

float UBlueprintSoundFunctions::GetSoundClassVolume(USoundClass* SoundClass)
{
	if (SoundClass)
	{
		return SoundClass->Properties.Volume;
	}
	
	return 0.0f;
}

void UBlueprintSoundFunctions::SetSoundClassPitch(USoundClass* SoundClass, float Pitch)
{
	if (SoundClass)
	{
		SoundClass->Properties.Pitch = Pitch;
	}
}

float UBlueprintSoundFunctions::GetSoundClassPitch(USoundClass* SoundClass)
{
	if (SoundClass)
	{
		return SoundClass->Properties.Pitch;
	}
	
	return 0.0f;
}

bool UBlueprintSoundFunctions::IsExternalBackgroundSoundActive()
{
#if PLATFORM_IOS
	return [[AVAudioSession sharedInstance] isOtherAudioPlaying];
#elif PLATFORM_ANDROID
	extern bool AndroidThunkCpp_IsMusicActive();
	return AndroidThunkCpp_IsMusicActive();
#endif
	
	return false;
}