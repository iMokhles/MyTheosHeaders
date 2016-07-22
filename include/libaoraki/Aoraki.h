#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import <Accounts/Accounts.h>
#import <Twitter/Twitter.h>
#include <objc/runtime.h>
#import <Social/Social.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <MediaPlayer/MediaPlayer.h>
#import <mach/mach_time.h>
#import <IOKit/hid/IOHIDEvent.h>

@class CNPGridMenuItem;
typedef void (^SelectionHandler)(CNPGridMenuItem *item);

@interface CNPGridMenuItem : NSObject

@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) UIImage *icon;
@property (nonatomic, copy) SelectionHandler selectionHandler;
- (instancetype)initWithTitle:(NSString *)title iconName:(UIImage *)iconName;
@end

@interface Aoraki : NSObject
@property (strong, nonatomic) UIViewController *mainViewController;
@property (nonatomic, assign) BOOL isViewControllerVisible;
+(id)sharedAoraki;
- (void)openAorakiPage;
@end
