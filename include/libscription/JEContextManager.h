//
//  JEContextManager.h
//  JavaScriptCocoa
//
//  Created by Bailey Seymour on 1/15/15.
//  Copyright (c) 2015 Bailey Seymour. All rights reserved.
//
#import "JEObject.h"

@class JEContext;

@interface JEContextManager : JEObject

- (NSString *)absolutePath:(NSString *)path;
- (void)runScriptWithName:(NSString *)fname;
- (id)initWithScriptsPath:(NSString *)spath;

@property (nonatomic, retain) JEContext *context;
@property (nonatomic, retain) NSString *scriptsPath;
@property (nonatomic, retain) NSString *bundleId;

@end
