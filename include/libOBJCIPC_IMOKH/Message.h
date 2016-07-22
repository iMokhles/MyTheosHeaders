//
//  libOBJCIPC_IMOKH
//  Message.h
//
//  Created by Alan Yip on 6 Feb 2014
//  Copyright 2014 Alan Yip. All rights reserved.
//

#import "header.h"

@interface OBJCIPC_IMOKHMessage : NSObject {
	
	BOOL _isReply;
	NSString *_messageIdentifier;
	OBJCIPC_IMOKHReplyHandler _replyHandler;
	NSString *_messageName;
	NSDictionary *_dictionary;
}

@property(nonatomic) BOOL isReply;
@property(nonatomic, copy) NSString *messageIdentifier;
@property(nonatomic, copy) OBJCIPC_IMOKHReplyHandler replyHandler;
@property(nonatomic, copy) NSString *messageName;
@property(nonatomic, retain) NSDictionary *dictionary;

// construct new messages
+ (instancetype)handshakeMessageWithDictionary:(NSDictionary *)dictionary;
+ (instancetype)outgoingMessageWithMessageName:(NSString *)messageName dictionary:(NSDictionary *)dictionary messageIdentifier:(NSString *)messageIdentifier isReply:(BOOL)isReply replyHandler:(OBJCIPC_IMOKHReplyHandler)handler;

// retrieve message data with header and content
- (NSData *)messageData;

@end