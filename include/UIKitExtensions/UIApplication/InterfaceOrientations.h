// UIKitExtensions
//
// UIKitExtensions/UIApplication/InterfaceOrientations.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIApplication.h>

#import "../Utils.h"

static inline UIInterfaceOrientation interfaceOrientation() {
    return UIApplication.sharedApplication.statusBarOrientation;
}

static inline BOOL isPortraitOrientation() {
    return UIInterfaceOrientationIsPortrait(interfaceOrientation());
}

// Preprocessor macros: defines "NSStringFromUIDeviceOrientation()"
UIKE_NSStringFromMethodForEnumType(UIInterfaceOrientation,
                                   NSInteger,

                                   UIInterfaceOrientationPortrait,
                                   UIInterfaceOrientationPortraitUpsideDown,
                                   UIInterfaceOrientationLandscapeLeft,
                                   UIInterfaceOrientationLandscapeRight);

