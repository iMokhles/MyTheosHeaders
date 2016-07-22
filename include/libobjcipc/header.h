#define LOG_MESSAGE_BODY 0

#ifdef DEBUG
	#define IPCLOG(x,...) NSLog(@"*** libOBJCIPC_iMokh: %@",[NSString stringWithFormat:(x), ##__VA_ARGS__])
#else
	// Replace with call to [NSString stringWithFormat:] so that any variables passed aren't marked as unused.
	#define IPCLOG(x,...) [NSString stringWithFormat:(x), ##__VA_ARGS__]
#endif

#define PrefPath @"/var/mobile/Library/Preferences/libOBJCIPC_iMokh.plist"
#define XPCObjects "/System/Library/PrivateFrameworks/XPCObjects.framework/XPCObjects"
#define SpringBoardIdentifier @"com.apple.springboard"
#define OBJCIPC_iMokhActivateAppNotification @"OBJCIPC_iMokhActivateAppNotification"
#define OBJCIPC_iMokhDeactivateAppNotification @"OBJCIPC_iMokhDeactivateAppNotification"

@class OBJCIPC_iMokh, OBJCIPC_iMokhConnection, OBJCIPC_iMokhMessage;

typedef NSDictionary *(^OBJCIPC_iMokhIncomingMessageHandler)(NSDictionary *); // return NSDictionary or nil to reply
typedef void(^OBJCIPC_iMokhReplyHandler)(NSDictionary *);

typedef struct {
	
	char magicNumber[3];
	BOOL replyFlag;
	char messageIdentifier[5];
	char messageName[256];
	int contentLength;
	
} OBJCIPC_iMokhMessageHeader;