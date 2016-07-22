// UIKitExtensions
//
// UIKitExtensions/UIImage/Clipping.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

#ifdef COREGRAPHICS_H_

@interface UIImage (Clipping)

- (UIImage *)imageClippedWithBounds:(CGRect)bounds;

@end

#else
//#pragma message("CoreGraphics framework not found in project, or not included in precompiled header. Image clipping functionality (UIImage/Clipping) will not be available.")
#endif
