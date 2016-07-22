/**
 * This header is generated by class-dump-z 0.2-0.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/PhotoLibrary.framework/PhotoLibrary
 */

#import <MusicLibrary/MLPhoto.h>

@class NSString, PLVideoFileGroup, NSURL;

@interface PLAudioInternal : MLPhoto {
@private
	NSURL* _url;
	NSString* _title;
	PLVideoFileGroup* _videoFileGroup;
	NSString* _temporaryPath;
}
// inherited: -(void)dealloc;
// inherited: -(BOOL)isVideo;
// inherited: -(BOOL)isAudio;
// inherited: -(id)title;
-(id)fileGroup;
// inherited: -(id)pathForVideoFile;
@end
