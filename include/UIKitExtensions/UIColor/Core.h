// UIKitExtensions
//
// UIKitExtensions/UIColor/Core.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

@interface UIColor (Core)

// http://stackoverflow.com/questions/1560081/how-can-i-create-a-uicolor-from-a-hex-string
+ (UIColor *)colorWithHexRGB:(NSUInteger)hexRGBValue alpha:(CGFloat)alpha;
+ (UIColor *)colorFromHexString:(NSString *)hexString alpha:(CGFloat)alpha;

@end
