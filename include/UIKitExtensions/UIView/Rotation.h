// UIKitExtensions
//
// UIKitExtensions/UIView/Rotation.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol UIViewRotation <NSObject>
- (void)handleRotation;
@end

@interface UIView (Rotation)
- (void)handleRotation;
@end
