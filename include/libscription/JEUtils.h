//
//  JEUtils.h
//  JavaScriptCocoa
//
//  Created by Bailey Seymour on 1/14/15.
//  Copyright (c) 2015 Bailey Seymour. All rights reserved.
//
#import "JEObject.h"

//typedef void (^JEActionBlock)(NSArray *);

@protocol JEJSExport;

@protocol JEUtilsEx <JEJSExport, JSExport>

+ (void)createAction:(JSValue *)action withIdentifier:(NSString *)identifier listenFor:(NSString *)listenid;
+ (void)sendEventWithIdentifier:(NSString *)identifier;
+ (NSString *)dateWithFormat:(NSString *)format;
+ (NSString *)contentsOfFileAtPath:(NSString *)path;
+ (void)setBrightness:(NSNumber *)level;
+ (NSNumber *)brightness;

@end

@interface JEUtils : JEObject <JEUtilsEx>

+ (void)createAction:(JSValue *)action withIdentifier:(NSString *)identifier listenFor:(NSString *)listenid;
+ (void)sendEventWithIdentifier:(NSString *)identifier;
+ (NSString *)dateWithFormat:(NSString *)format;
+ (NSString *)contentsOfFileAtPath:(NSString *)path;
+ (void)setBrightness:(NSNumber *)level;
+ (NSNumber *)brightness;

@property (nonatomic, retain) NSMutableDictionary *blocks;

@end
