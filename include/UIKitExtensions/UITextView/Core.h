// UIKitExtensions
//
// UIKitExtensions/UITextView/Core.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

@interface UITextView (Core)

- (CGRect)rectForStringInRange:(NSRange)stringRange;
@property (readonly) CGPoint firstCharacterOrigin;

@end
