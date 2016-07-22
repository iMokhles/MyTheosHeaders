// UIKitExtensions
//
// UIKitExtensions/UIView/DynamicProperties.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

@interface UIView (DynamicProperties)

@property (copy, nonatomic) void(^dynamicProperties)(id view);

- (instancetype)defineDynamicPropertiesWithBlock:(void(^)(id view))viewPropertiesBlock;
- (instancetype)applyDynamicProperties;

@end
