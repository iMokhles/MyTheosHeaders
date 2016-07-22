//
// iMoDevTools.h
// iMoDevTools
//
// Created by Mokhlas Hussein (@iMokhles) on 8 Sept 2014
// Licensed under a GNU GPL v 2.0
// Copyright 2014-2015 Mokhlas Hussein (@iMokhles). All rights reserved.
//

#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <Foundation/Foundation.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <MediaPlayer/MediaPlayer.h>
#import <CoreFoundation/CoreFoundation.h>
#import <AppSupport/CPDistributedMessagingCenter.h>
#import <AssetsLibrary/AssetsLibrary.h>
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
#import <LocalAuthentication/LocalAuthentication.h>

/// Production (default): Normal, live environment. Real money gets moved.
/// This environment MUST be used for App Store submissions.
extern NSString *const PayPalEnvironmentProduction;
/// Sandbox: Uses the PayPal sandbox for transactions. Useful for development.
extern NSString *const PayPalEnvironmentSandbox;
/// NoNetwork: Mock mode. Does not submit transactions to PayPal. Fakes successful responses. Useful for unit tests.
extern NSString *const PayPalEnvironmentNoNetwork;

UIKIT_EXTERN NSString *const IAProductPurchasedNotification; // Purchase completed 
UIKIT_EXTERN NSString *const IAFailedProductPurchasedNotification; // Purchase Failed ( check Syslog for more info )

UIKIT_EXTERN NSString *const IAProductPurchasedInfoSavedNotification; // info did save in your Parse account
UIKIT_EXTERN NSString *const IAProductPurchasedInfoFailedNotification; // info did't save in your Parse account

UIKIT_EXTERN NSString *const IADevicesLimitFailedNotification; // get the Notification when the users reach device limit ( while restoring purchase only :) )


// Block to check transaction later ;)
typedef void(^gotTransactionInfo)(NSDictionary *info, BOOL success);
typedef void(^restorePurchasesForTransaction)(BOOL success);
typedef void(^getParseFileObject)(NSData *objectData);
//typedef void(^saveParseFileObject)(BOOL success);
typedef void(^progressBlock)(NSUInteger percentDone);

typedef void(^finishedWithFilePath)(NSURL *url);
typedef void(^finishedWithImage)(UIImage *image);
typedef void(^iMoDevToolsTouchIDFinishedWithStatus)(BOOL success,NSError *err);

typedef void (^didCroppedBlock)(UIImage *cropImage, CGRect cropRect, NSInteger angle);

typedef void(^finishedTransalteWithText)(NSString *string);

@class PSViewController;

@interface iMoDevTools: NSObject <UIPopoverPresentationControllerDelegate> {
	CPDistributedMessagingCenter *center;
}
@property (nonatomic, strong) UIViewController *selfRootViewController;
@property (nonatomic, strong) NSString *lastImagePath;

+ (id)sharedInstance;

// setup your Parse IDs
+ (void)imo_setParseApplicationID:(NSString *)appID clientKey:(NSString *)clientKey className:(NSString *)cName devicesLimit:(NSInteger)dLimit launchingWithOptions:(NSDictionary *)launchOptions;

// checking transaction info
- (void)imo_checkTransactionInfo:(NSString *)inTweakID fromClass:(NSString *)className transInfo:(gotTransactionInfo)callBack;

// setup your paypal IDs and your UserDefault ID ( PurchaseID )
- (void)imo_initWithClienID:(NSString *)clientID clientIDSandbox:(NSString *)clientIDSandbox environment:(NSString *)envi andPurchaseID:(NSString *)purchaseID;

// create payment item
- (void)imo_presentPaypalViewControllerFromViewController:(id)target WithItemName:(NSString *)itemName andItemDataIfNedded:(NSData *)itemData inTweakID:(NSString *)inTweak Description:(NSString *)desc Quantity:(NSInteger)integer Price:(NSString *)price Currency:(NSString *)currency SKU:(NSString *)sku;

// retrieve file object from Parse
- (void)imo_getParseFileObjectWithBlock:(getParseFileObject)callBack progressBlock:(progressBlock)callBackProgress;

// restore purchases from transactions id
- (void)imo_restorePurchasesForTransaction:(NSString *)transID transInfo:(restorePurchasesForTransaction)callBack;

// setup notifications
- (void)setupNotificationsFromDeviceToken:(NSData *)token;

// handle push
- (void)handleParsePush:(NSDictionary *)userInfo;

// // create a temp file
// - (NSString *)imo_temporaryFile;
// // moving file ( works even with sandbox )
// - (void)imo_moveFile:(NSString *)file1 imo_toFile:(NSString *)file2;
// // copying file ( works even with sandbox )
// - (void)imo_copyFile:(NSString *)file1 imo_toFile:(NSString *)file2;
// // symlink file ( works even with sandbox )
// - (void)imo_symlinkFile:(NSString *)file1 imo_toFile:(NSString *)file2;
// // delete file ( works even with sandbox )
// - (void)imo_deleteFile:(NSString *)file;
// // attributes file ( works even with sandbox )
// - (NSDictionary *)imo_attributesOfFile:(NSString *)file;
// // dir contents ( works even with sandbox )
// - (NSArray *)imo_contentsOfDirectory:(NSString *)dir;
// // change file's mode ( works even with sandbox )
// - (void)imo_chmodFile:(NSString *)file mode:(mode_t)mode;
// // check if file existe ( works even with sandbox )
// - (BOOL)imo_fileExists:(NSString *)file;
// // check if file is dir ( works even with sandbox )
// - (BOOL)imo_fileIsDirectory:(NSString *)file;
// // create dir ( works even with sandbox )
// - (void)imo_createDirectory:(NSString *)dir;
// get your device UDID
- (NSString *)imo_deviceUDIDValue;
// get your device sys name
- (NSString *)imo_deviceSysName;
// get your device sys version
- (NSString *)imo_deviceSysVersion;
// get your device hardware id
- (NSString *)imo_deviceHardware;
// share any file with other apps ( supports OpenIN )
- (void)imo_shareFileAtPath:(NSString *)path;
// share any text with other apps ( supports Speech )
- (void)imo_shareText:(NSString *)text;
// open file browser then use the delegates above to get the results
// - (void)imo_openDevlibFileBrowserWithDocumentPath:(NSString *)docPath;
// export an mp3 file from MPMediaItemCollection
- (void)imo_exportMp3FileFromMPMediaItems:(MPMediaItemCollection *)mediaItemCollection toFolder:(NSString *)folderName completion:(finishedWithFilePath)filePath;
// export an M4a file from MPMediaItemCollection
- (void)imo_exportM4aFileFromMPMediaItems:(MPMediaItemCollection *)mediaItemCollection toFolder:(NSString *)folderName completion:(finishedWithFilePath)filePath;
// get last taken image
- (void)imo_getLastImageCompletion:(finishedWithImage)image;
// color picker for preferences
- (PSViewController *)imo_ColorPickerWithTweakDefaults:(NSString *)tweakPrefsID notification:(NSString *)notify appToKill:(NSString *)appName saveKey:(NSString *)saveKey;
// send email to developer
- (void)imo_SendEmailTo:(NSString *)emailAddress subject:(NSString *)subject text:(NSString *)text attachment:(NSData *)attachment mimeType:(NSString *)mimeType fileName:(NSString *)filename;
//Returns YES if device has Touch ID
- (BOOL)imo_IsDeviceValidForTouchID; // i don't know why i use it while apple's check it in LAContext class
//Returns YES if device has Touch ID
- (BOOL)imo_CanUseTouchID;
//Callback block handles YES, if Touch ID validated. No if handled error.
- (void)imo_ValidateTouchID:(iMoDevToolsTouchIDFinishedWithStatus)callback;

/********* new methods *********/

// open links within apps
- (void)imo_browseLinkFromURL:(NSURL *)url;
// localize your strings
- (NSString *)imo_localizeString:(NSString *)string fromFile:(NSString *)tableFile inBundle:(NSBundle *)bundle withComment:(NSString *)comment;
// send device local notification NOTE ( section id is com.apple.reminders by default and vibrate = YES by default)
- (void)imo_showNotificationWithTitle:(NSString *)title message:(NSString *)message sectionID:(NSString *)secID subTitle:(NSString *)subString vibrate:(BOOL)bannerVibration;
// crop images easily with less codes (fromViewController if nil we will use the first viewcontroller from the app window)
- (void)imo_presentCropViewControllerWithImage:(UIImage *)image fromViewController:(UIViewController *)viewcontroller completion:(didCroppedBlock)croppedBlock;
/********* DataBase methods *********/
- (NSDictionary *)getDictionaryFromDataBase:(NSString *)dataBasePath fromSelectQuery:(NSString *)selectQuery;
- (NSArray *)getArrayFromDataBase:(NSString *)dataBasePath fromSelectQuery:(NSString *)selectQuery;
/********* Transalte methods *********/
- (void)imo_transalteText:(NSString *)textToTransalte completion:(finishedTransalteWithText)stringResult;
// - (void)imo_transalteText:(NSString *)textToTransalte fromLanguage:(NSString *)fromLang toLanguage:(NSString *)toLang autoDetect:(BOOL)detect completion:(finishedTransalteWithText)stringResult;
@end
