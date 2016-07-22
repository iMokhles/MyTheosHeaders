// UIKitExtensions
//
// UIKitExtensions/UIImage/ScalingAndCropping.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

@interface UIImage (ScalingAndCropping)

- (UIImage *)imageByScalingAndCroppingForSize:(CGSize)targetSize;

@end
