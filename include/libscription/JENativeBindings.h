#import <libactivator/libactivator.h>

@protocol LAEventExport <JSExport>

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *mode;
@property (nonatomic, getter=isHandled) BOOL handled;
@property (nonatomic, copy) NSDictionary *userInfo;

@end

@protocol LAActivatorExport <JSExport>
+ (LAActivator *)sharedInstance;

@property (nonatomic, readonly) LAActivatorVersion version;
@property (nonatomic, readonly, getter=isRunningInsideSpringBoard) BOOL runningInsideSpringBoard;
@property (nonatomic, readonly, getter=isDangerousToSendEvents) BOOL dangerousToSendEvents;

// Listeners

- (id<LAListener>)listenerForEvent:(LAEvent *)event;
- (void)sendEventToListener:(LAEvent *)event;
- (void)sendEvent:(LAEvent *)event toListenerWithName:(NSString *)listenerName;
- (void)sendEvent:(LAEvent *)event toListenersWithNames:(NSArray *)listenerNames;
- (void)sendAbortToListener:(LAEvent *)event;
- (void)sendAbortEvent:(LAEvent *)event toListenerWithName:(NSString *)listenerName;
- (void)sendAbortEvent:(LAEvent *)event toListenersWithNames:(NSArray *)listenerNames;
- (void)sendPreviewEventToListenerWithName:(NSString *)listenerName;
- (void)sendDeactivateEventToListeners:(LAEvent *)event;

- (id<LAListener>)listenerForName:(NSString *)name;
- (BOOL)hasListenerWithName:(NSString *)name;
- (void)registerListener:(id<LAListener>)listener forName:(NSString *)name; // Only available in SpringBoard
- (void)unregisterListenerWithName:(NSString *)name; // Only available in SpringBoard

- (BOOL)hasSeenListenerWithName:(NSString *)name;

// Assignments

- (void)assignEvent:(LAEvent *)event toListenerWithName:(NSString *)listenerName;
- (void)assignEvent:(LAEvent *)event toListenersWithNames:(NSArray *)listenerNames;
- (void)addListenerAssignment:(NSString *)listenerName toEvent:(LAEvent *)event;
- (void)removeListenerAssignment:(NSString *)listenerName fromEvent:(LAEvent *)event;
- (void)unassignEvent:(LAEvent *)event;
- (NSString *)assignedListenerNameForEvent:(LAEvent *)event;
- (NSArray *)assignedListenerNamesForEvent:(LAEvent *)event;
- (NSArray *)eventsAssignedToListenerWithName:(NSString *)listenerName;

// Events

@property (nonatomic, readonly) NSArray *availableEventNames;
- (BOOL)eventWithNameIsHidden:(NSString *)name;
- (BOOL)eventWithNameRequiresAssignment:(NSString *)name;
- (NSArray *)compatibleModesForEventWithName:(NSString *)name;
- (BOOL)eventWithName:(NSString *)eventName isCompatibleWithMode:(NSString *)eventMode;
- (BOOL)eventWithNameSupportsUnlockingDeviceToSend:(NSString *)eventName;

- (BOOL)eventWithNameSupportsConfiguration:(NSString *)eventName;
- (NSString *)configurationViewControllerClassNameForEventWithName:(NSString *)eventName bundle:(NSBundle **)bundle;
- (Class)configurationViewControllerClassForEventWithName:(NSString *)eventName;
- (BOOL)eventWithNameSupportsRemoval:(NSString *)eventName;
- (void)removeEventWithName:(NSString *)eventName;

- (void)registerEventDataSource:(id<LAEventDataSource>)dataSource forEventName:(NSString *)eventName;
- (void)unregisterEventDataSourceWithEventName:(NSString *)eventName;

// Listener Metadata

@property (nonatomic, readonly) NSArray *availableListenerNames;
- (id)infoDictionaryValueOfKey:(NSString *)key forListenerWithName:(NSString *)name;
- (BOOL)listenerWithNameRequiresAssignment:(NSString *)name;
- (NSArray *)compatibleEventModesForListenerWithName:(NSString *)name;
- (BOOL)listenerWithName:(NSString *)listenerName isCompatibleWithMode:(NSString *)eventMode;
- (BOOL)listenerWithName:(NSString *)listenerName isCompatibleWithEventName:(NSString *)eventName;
- (BOOL)listenerWithNameNeedsPoweredDisplay:(NSString *)listenerName;
- (NSArray *)exclusiveAssignmentGroupsForListenerName:(NSString *)listenerName;
- (BOOL)listenerNamesAreMutuallyCompatible:(NSArray *)listenerNames;
- (UIImage *)iconForListenerName:(NSString *)listenerName;
- (UIImage *)smallIconForListenerName:(NSString *)listenerName;

// Event Modes

@property (nonatomic, readonly) NSArray *availableEventModes;
@property (nonatomic, readonly) NSString *currentEventMode;
@property (nonatomic, readonly) NSString *currentEventModeUnderneathLockScreen;
@property (nonatomic, readonly) BOOL supportsUnlockingDeviceToSendEvents;

// Blacklisting

@property (nonatomic, readonly) NSString *displayIdentifierForCurrentApplication;
- (BOOL)applicationWithDisplayIdentifierIsBlacklisted:(NSString *)displayIdentifier;
- (void)setApplicationWithDisplayIdentifier:(NSString *)displayIdentifier isBlacklisted:(BOOL)blacklisted;

@end
