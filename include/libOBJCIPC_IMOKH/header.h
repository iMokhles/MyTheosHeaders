#define LOG_MESSAGE_BODY 0

#ifdef DEBUG
	#define IPCLOG(x,...) NSLog(@"*** libOBJCIPC_IMOKH: %@",[NSString stringWithFormat:(x), ##__VA_ARGS__])
#else
	// Replace with call to [NSString stringWithFormat:] so that any variables passed aren't marked as unused.
	#define IPCLOG(x,...) [NSString stringWithFormat:(x), ##__VA_ARGS__]
#endif

#define PrefPath @"/var/mobile/Library/Preferences/libOBJCIPC_IMOKH.plist"
#define XPCObjects "/System/Library/PrivateFrameworks/XPCObjects.framework/XPCObjects"
#define SpringBoardIdentifier @"com.apple.springboard"
#define OBJCIPC_IMOKHActivateAppNotification @"OBJCIPC_IMOKHActivateAppNotification"
#define OBJCIPC_IMOKHDeactivateAppNotification @"OBJCIPC_IMOKHDeactivateAppNotification"

@class OBJCIPC_IMOKH, OBJCIPC_IMOKHConnection, OBJCIPC_IMOKHMessage;

typedef NSDictionary *(^OBJCIPC_IMOKHIncomingMessageHandler)(NSDictionary *); // return NSDictionary or nil to reply
typedef void(^OBJCIPC_IMOKHReplyHandler)(NSDictionary *);

typedef struct {
	
	char magicNumber[3];
	BOOL replyFlag;
	char messageIdentifier[5];
	char messageName[256];
	int contentLength;
	
} OBJCIPC_IMOKHMessageHeader;