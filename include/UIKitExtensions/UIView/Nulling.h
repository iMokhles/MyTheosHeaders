// UIKitExtensions
//
// UIKitExtensions/UIView/Nulling.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

#import <Foundation/Foundation.h>

@protocol UINulling <NSObject>
- (void)nullify;
@end

@interface UIView (Nulling)
- (void)nullify;
@end
