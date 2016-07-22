#import <iMoMacros.h>
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
#import <Photos/Photos.h>
#import <Accounts/Accounts.h>
#import <Social/Social.h>

// last image private API
@interface DCIMImageWellUtilities : NSObject
+ (id)cameraPreviewWellImage;
+ (id)cameraPreviewWellImageFileURL;
@end
typedef void(^finishedWithImage)(UIImage *image);


// Music Grabber
typedef void(^finishedWithMusicFilePath)(NSString *musicPath);

// result block
typedef void(^finishedWithResult)(BOOL isOK);

// array block
typedef void(^finishedArrayWithResult)(NSArray *array);

// string block
typedef void(^finishedStringWithResult)(NSString *string);

@interface iMoDevTools : NSObject
+ (id)sharedInstance;
// get the main View Controller
- (UIViewController *)imo_mainViewController;
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
// get last taken image
- (void)imo_getLastImageCompletion:(finishedWithImage)image;
// get music file from MediaItem
- (void)grabMusicFileFromMediaItem:(MPMediaItem *)mediaItem completion:(finishedWithMusicFilePath)musicPath;
// send email to dev
- (void)sendEmailTo:(NSString *)emailAddress subject:(NSString *)subject text:(NSString *)text attachment:(NSData *)attachment mimeType:(NSString *)mimeType fileName:(NSString *)filename;
// show twitter follow alert
- (void)showTwitterFollowAlertWithTweakName:(NSString *)tweakName message:(NSString *)message accountName:(NSString *)accountName;
@end

int main(int argc, char **argv, char **envp) {
	return 0;
}

// vim:ft=objc