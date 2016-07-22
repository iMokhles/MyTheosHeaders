//
// DevelopersLib.h
// DevelopersLib
//
// Created by Mokhlas Hussein (@iMokhles) on 21 May 2015
// Licensed under a GNU GPL v 2.0
// Copyright 2015 Mokhlas Hussein (@iMokhles). All rights reserved.
//

#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <MediaPlayer/MediaPlayer.h>
#import <CoreFoundation/CoreFoundation.h>
#import <AppSupport/CPDistributedMessagingCenter.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <MessageUI/MessageUI.h>
#import "LocalAuthentication/LocalAuthentication.h"

// #import "filebrowser/DevLib_WAEFileBrowserViewController.h"

typedef void(^finishedWithFilePath)(NSURL *);
typedef void(^finishedWithImage)(UIImage *);
typedef void(^DevLib_WAETouchIDFinishedWithStatus)(BOOL success,NSError *err);

// Dec
@class PSViewController;

// File Browser Delegates
// @protocol DevLib_WAEFilesBrowserVCDelegate <NSObject>
// - (void)filebrowser_didSelectFile:(NSString *)path;
// - (BOOL)filebrowser_shouldDeleteFileAtPath:(NSString *)path;
// @optional
// - (void)filebrowser_didLoadDirectory:(NSString *)path;
// - (void)filebrowser_fileBrowserDidCancelled;
// @end

@interface DevelopersLib_WAE : NSObject <UIPopoverPresentationControllerDelegate> {
//    __unsafe_unretained id <DevLib_WAEFilesBrowserVCDelegate> _delegate;
}
//@property (nonatomic, assign) id <DevLib_WAEFilesBrowserVCDelegate> delegate;
@property (nonatomic, strong) UIViewController *selfRootViewController;
// @property (nonatomic, strong) DevLib_WAEFileBrowserViewController *fileBrowser;
@property (nonatomic, strong) NSString *lastImagePath;

+ (id)sharedInstance;

// create a temp file
- (NSString *)DevLib_WAE_temporaryFile;
// moving file ( works even with sandbox )
- (void)DevLib_WAE_moveFile:(NSString *)file1 DevLib_WAE_toFile:(NSString *)file2;
// copying file ( works even with sandbox )
- (void)DevLib_WAE_copyFile:(NSString *)file1 DevLib_WAE_toFile:(NSString *)file2;
// symlink file ( works even with sandbox )
- (void)DevLib_WAE_symlinkFile:(NSString *)file1 DevLib_WAE_toFile:(NSString *)file2;
// delete file ( works even with sandbox )
- (void)DevLib_WAE_deleteFile:(NSString *)file;
// attributes file ( works even with sandbox )
- (NSDictionary *)DevLib_WAE_attributesOfFile:(NSString *)file;
// dir contents ( works even with sandbox )
- (NSArray *)DevLib_WAE_contentsOfDirectory:(NSString *)dir;
// change file's mode ( works even with sandbox )
- (void)DevLib_WAE_chmodFile:(NSString *)file mode:(mode_t)mode;
// check if file existe ( works even with sandbox )
- (BOOL)DevLib_WAE_fileExists:(NSString *)file;
// check if file is dir ( works even with sandbox )
- (BOOL)DevLib_WAE_fileIsDirectory:(NSString *)file;
// create dir ( works even with sandbox )
- (void)DevLib_WAE_createDirectory:(NSString *)dir;
// get your device UDID
- (NSString *)DevLib_WAE_deviceUDIDValue;
// get your device sys name
- (NSString *)DevLib_WAE_deviceSysName;
// get your device sys version
- (NSString *)DevLib_WAE_deviceSysVersion;
// get your device hardware id
- (NSString *)DevLib_WAE_deviceHardware;
// share any file with other apps ( supports OpenIN )
- (void)DevLib_WAE_shareFileAtPath:(NSString *)path;
// share any text with other apps ( supports Speech )
- (void)DevLib_WAE_shareText:(NSString *)text;
// open file browser then use the delegates above to get the results
- (void)DevLib_WAE_openDevLib_WAEFileBrowserWithDocumentPath:(NSString *)docPath;
// export an mp3 file from MPMediaItemCollection
- (void)DevLib_WAE_exportMp3FileFromMPMediaItems:(MPMediaItemCollection *)mediaItemCollection toFolder:(NSString *)folderName completion:(finishedWithFilePath)filePath;
// export an M4a file from MPMediaItemCollection
- (void)DevLib_WAE_exportM4aFileFromMPMediaItems:(MPMediaItemCollection *)mediaItemCollection toFolder:(NSString *)folderName completion:(finishedWithFilePath)filePath;
// get last taken image
- (void)DevLib_WAE_getLastImageCompletion:(finishedWithImage)image;
// color picker for preferences
- (PSViewController *)DevLib_WAE_ColorPickerWithTweakDefaults:(NSString *)tweakPrefsID notification:(NSString *)notify appToKill:(NSString *)appName saveKey:(NSString *)saveKey;
// send email to developer
- (void)DevLib_WAE_SendEmailTo:(NSString *)emailAddress subject:(NSString *)subject text:(NSString *)text attachment:(NSData *)attachment mimeType:(NSString *)mimeType fileName:(NSString *)filename;
//Returns YES if device has Touch ID
- (BOOL)DevLib_WAE_IsDeviceValidForTouchID; // i don't know why i use it while apple's check it in LAContext class
//Returns YES if device has Touch ID
- (BOOL)DevLib_WAE_CanUseTouchID;

//Callback block handles YES, if Touch ID validated. No if handled error.
- (void)DevLib_WAE_ValidateTouchID:(DevLib_WAETouchIDFinishedWithStatus)callback;
@end