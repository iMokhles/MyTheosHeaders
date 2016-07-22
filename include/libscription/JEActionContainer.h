#import "JEObject.h"
#import "JEUtils.h"

#import <libactivator/libactivator.h>

@interface JEActionContainer : JEObject <LAListener>

- (void)run:(LAActivator *)activator activatorEvent:(LAEvent *)activatorEvent info:(NSDictionary *)infoDict;
- (void)activator:(LAActivator *)activator receiveEvent:(LAEvent *)event;
- (void)scription:(NSObject *)scription info:(NSDictionary *)infoDict;

@property (nonatomic, retain) JSValue *actionBlock;
@property (nonatomic, retain) NSString *identifier;

@end
