#define LOG_MESSAGE_BODY 0

#ifdef DEBUG
	#define IPCLOG(x,...) NSLog(@"*** libOBJCIPC_IMOKH_WA_QC: %@",[NSString stringWithFormat:(x), ##__VA_ARGS__])
#else
	// Replace with call to [NSString stringWithFormat:] so that any variables passed aren't marked as unused.
	#define IPCLOG(x,...) [NSString stringWithFormat:(x), ##__VA_ARGS__]
#endif

#define PrefPath @"/var/mobile/Library/Preferences/libOBJCIPC_IMOKH_WA_QC.plist"
#define XPCObjects "/System/Library/PrivateFrameworks/XPCObjects.framework/XPCObjects"
#define SpringBoardIdentifier @"com.apple.springboard"
#define OBJCIPC_IMOKH_WA_QCActivateAppNotification @"OBJCIPC_IMOKH_WA_QCActivateAppNotification"
#define OBJCIPC_IMOKH_WA_QCDeactivateAppNotification @"OBJCIPC_IMOKH_WA_QCDeactivateAppNotification"

@class OBJCIPC_IMOKH_WA_QC, OBJCIPC_IMOKH_WA_QCConnection, OBJCIPC_IMOKH_WA_QCMessage;

typedef NSDictionary *(^OBJCIPC_IMOKH_WA_QCIncomingMessageHandler)(NSDictionary *); // return NSDictionary or nil to reply
typedef void(^OBJCIPC_IMOKH_WA_QCReplyHandler)(NSDictionary *);

typedef struct {
	
	char magicNumber[3];
	BOOL replyFlag;
	char messageIdentifier[5];
	char messageName[256];
	int contentLength;
	
} OBJCIPC_IMOKH_WA_QCMessageHeader;