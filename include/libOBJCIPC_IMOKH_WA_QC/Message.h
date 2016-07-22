//
//  libOBJCIPC_IMOKH_WA_QC
//  Message.h
//
//  Created by Alan Yip on 6 Feb 2014
//  Copyright 2014 Alan Yip. All rights reserved.
//

#import "header.h"

@interface OBJCIPC_IMOKH_WA_QCMessage : NSObject {
	
	BOOL _isReply;
	NSString *_messageIdentifier;
	OBJCIPC_IMOKH_WA_QCReplyHandler _replyHandler;
	NSString *_messageName;
	NSDictionary *_dictionary;
}

@property(nonatomic) BOOL isReply;
@property(nonatomic, copy) NSString *messageIdentifier;
@property(nonatomic, copy) OBJCIPC_IMOKH_WA_QCReplyHandler replyHandler;
@property(nonatomic, copy) NSString *messageName;
@property(nonatomic, retain) NSDictionary *dictionary;

// construct new messages
+ (instancetype)handshakeMessageWithDictionary:(NSDictionary *)dictionary;
+ (instancetype)outgoingMessageWithMessageName:(NSString *)messageName dictionary:(NSDictionary *)dictionary messageIdentifier:(NSString *)messageIdentifier isReply:(BOOL)isReply replyHandler:(OBJCIPC_IMOKH_WA_QCReplyHandler)handler;

// retrieve message data with header and content
- (NSData *)messageData;

@end