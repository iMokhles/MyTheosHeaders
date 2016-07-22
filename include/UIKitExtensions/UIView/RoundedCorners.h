// UIKitExtensions
//
// UIKitExtensions/UIView/RoundedCorners.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

#ifdef QUARTZCORE_H

@interface UIView (RoundedCorners)

// http://stackoverflow.com/questions/4847163/round-two-corners-in-uiview
- (void)applyRoundedCorners:(UIRectCorner)cornersToRoundify radii:(CGSize)radii;

@end

#endif
