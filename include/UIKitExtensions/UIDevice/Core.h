// UIKitExtensions
//
// UIKitExtensions/UIDevice/Core.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIDevice.h>

#import "../Utils.h"

// Preprocessor macros: defines "NSStringFromUIDeviceOrientation()"
UIKE_NSStringFromMethodForEnumType(UIDeviceOrientation, NSInteger,

                                   UIDeviceOrientationUnknown,
                                   UIDeviceOrientationPortrait,
                                   UIDeviceOrientationPortraitUpsideDown,
                                   UIDeviceOrientationLandscapeLeft,
                                   UIDeviceOrientationLandscapeRight,
                                   UIDeviceOrientationFaceUp,
                                   UIDeviceOrientationFaceDown);
