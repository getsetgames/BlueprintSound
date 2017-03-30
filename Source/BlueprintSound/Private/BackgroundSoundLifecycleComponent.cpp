//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "BackgroundSoundLifecycleComponent.h"
#include "BlueprintSoundPrivatePCH.h"

void UBackgroundSoundLifecycleComponent::OnRegister()
{
	Super::OnRegister();
	
	UBackgroundSoundLifecycleComponent::AudioInterruptionBeganDelegate.AddUObject(this, &UBackgroundSoundLifecycleComponent::AudioInterruptionBegan_Handler);
	UBackgroundSoundLifecycleComponent::AudioInterruptionEndedDelegate.AddUObject(this, &UBackgroundSoundLifecycleComponent::AudioInterruptionEnded_Handler);
}

void UBackgroundSoundLifecycleComponent::OnUnregister()
{
	Super::OnUnregister();
	
	UBackgroundSoundLifecycleComponent::AudioInterruptionBeganDelegate.RemoveAll(this);
	UBackgroundSoundLifecycleComponent::AudioInterruptionEndedDelegate.RemoveAll(this);
}

// interstitials

UBackgroundSoundLifecycleComponent::FBackgroundSoundDelegate UBackgroundSoundLifecycleComponent::AudioInterruptionBeganDelegate;
UBackgroundSoundLifecycleComponent::FBackgroundSoundDelegate UBackgroundSoundLifecycleComponent::AudioInterruptionEndedDelegate;

#if PLATFORM_IOS
#import <AVFoundation/AVAudioSession.h>

@interface BackgroundSoundLifecycleDelegate : NSObject

@end

@implementation BackgroundSoundLifecycleDelegate

-(id)init
{
	self = [super init];
	
	if (self)
	{
		[AVAudioSession sharedInstance];
		[[NSNotificationCenter defaultCenter] addObserver:self
												 selector:@selector(audioInterruption:)
													 name:AVAudioSessionInterruptionNotification
												   object:nil];
	}
	
	return self;
}

-(void)audioInterruption:(NSNotification*)notification
{
	NSInteger InteruptionType = [[notification.userInfo valueForKey:AVAudioSessionInterruptionTypeKey] integerValue];
	switch (InteruptionType)
	{
		case AVAudioSessionInterruptionTypeBegan:
			UBackgroundSoundLifecycleComponent::AudioInterruptionBeganDelegate.Broadcast();
			break;
			
		case AVAudioSessionInterruptionTypeEnded:
			UBackgroundSoundLifecycleComponent::AudioInterruptionEndedDelegate.Broadcast();
			break;
			
		default:
			break;
	}
}

@end

static BackgroundSoundLifecycleDelegate *BackgroundSoundLifecycleDelegateSingleton = [[BackgroundSoundLifecycleDelegate alloc] init];

#endif
