// UIKitExtensions
//
// UIKitExtensions/UIGeometry.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#ifndef UIKitExtensions_UIGeometry_h
#define UIKitExtensions_UIGeometry_h

#import <UIKit/UIGeometry.h>

static inline CGPoint CGRectGetCenter(CGRect frame) {
    return CGPointMake(CGRectGetMidX(frame), CGRectGetMidY(frame));
}

#endif
