//
//  JEObject.h
//  JavaScriptCocoa
//
//  Created by Bailey Seymour on 1/14/15.
//  Copyright (c) 2015 Bailey Seymour. All rights reserved.
//

@protocol JEJSExport <JSExport>
+ (id)create;
+ (BOOL)available;
@end

@interface JEObject : NSObject

+ (id)create;
+ (BOOL)available;

@end
