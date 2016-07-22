//
// TGClient.h
// TGEnhancer
//
// (Unbox) Created by Mokhlas Hussein on 26/11/2014 
// Licensed under a CreativeCommons Attribution 3.0 Unported License
//

#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
// #import <AppSupport/CPDistributedMessagingCenter.h>
#import <Rocket/rocketbootstrap.h>
// #import "TGDelegate.h"

@class CPDistributedMessagingCenter;
@class TGDelegate;

// @interface CPDistributedMessagingCenter : NSObject {
// }
// - (id)_initWithServerName:(id)serverName;
// - (void)_dispatchMessageNamed:(id)named userInfo:(id)info reply:(id *)reply auditToken:(void *)token; //token being a XXStruct_kUSYWB
// - (BOOL)_sendMessage:(id)message userInfo:(id)info receiveReply:(id *)reply error:(id *)error toTarget:(id)target selector:(SEL)selector context:(void *)context;
// - (BOOL)_sendMessage:(id)message userInfoData:(id)data oolKey:(id)key oolData:(id)data4 receiveReply:(id *)reply error:(id *)error;
// - (void)registerForMessageName:(id)messageName target:(id)target selector:(SEL)selector;
// - (id)sendMessageAndReceiveReplyName:(id)name userInfo:(id)info;
// - (id)sendMessageAndReceiveReplyName:(id)name userInfo:(id)info error:(id *)error;
// - (void)sendMessageAndReceiveReplyName:(id)name userInfo:(id)info toTarget:(id)target selector:(SEL)selector context:(void *)context;
// - (BOOL)sendMessageName:(id)name userInfo:(id)info;
// -(void)runServerOnCurrentThread;
// @end

@interface TGClient: NSObject {
	CPDistributedMessagingCenter *center;
}

+ (id)sharedInstance;

- (NSString *)temporaryFile;
- (void)sendFileWithPath:(NSString *)filePath fileName:(NSString *)fileName fileType:(NSString *)fileType;

@end
