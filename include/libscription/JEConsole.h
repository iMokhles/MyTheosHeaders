//
//  JEConsole.h
//  JavaScriptCocoa
//
//  Created by Bailey Seymour on 1/14/15.
//  Copyright (c) 2015 Bailey Seymour. All rights reserved.
//
#import "JEObject.h"

@protocol JEJSExport;

@protocol JEConsoleEx <JEJSExport, JSExport>

+ (void)log:(id)object;

@end

@interface JEConsole : JEObject <JEConsoleEx>

+ (void)log:(id)object;

@end
