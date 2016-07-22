// UIKitExtensions
//
// UIKitExtensions/UIImage/RoundedCorners.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

@interface UIImage (RoundedCorners)

- (UIImage *)applyRoundedCorners:(UIRectCorner)cornersToRoundify radii:(CGSize)radii;

@end
