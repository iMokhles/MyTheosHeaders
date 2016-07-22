//
//  JEContext.h
//  JavaScriptCocoa
//
//  Created by Bailey Seymour on 1/15/15.
//  Copyright (c) 2015 Bailey Seymour. All rights reserved.
//

@class JEContextManager;

@interface JEContext : JSContext

- (id)initWithManager:(JEContextManager *)manager;

@property (nonatomic, assign) JEContextManager *manager;
@property (nonatomic, retain) NSDictionary *info;

@end
