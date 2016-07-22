//
//  JEDictionary.h
//  JavaScriptCocoa
//
//  Created by Bailey Seymour on 1/16/15.
//  Copyright (c) 2015 Bailey Seymour. All rights reserved.
//

#import "JEObject.h"

@protocol JEDictionaryEx <JEJSExport, JSExport>

+ (NSDictionary *)createFromString:(NSString *)string;

@end

@interface JEDictionary : JEObject <JEDictionaryEx>

+ (NSDictionary *)createFromString:(NSString *)string;

@end
