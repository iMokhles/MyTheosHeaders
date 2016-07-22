// UIKitExtensions
//
// UIKitExtensions/UIView/Blocks.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

@interface UIView (Blocks)

- (instancetype)initWithBlock:(void(^)(id))block;

- (instancetype)initWithFrame:(CGRect)frame andBlock:(void(^)(id))block;

- (instancetype)performBlockOnReceiver:(void(^)(id))block;

@end
