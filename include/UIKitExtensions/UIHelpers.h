// UIKitExtensions
//
// UIKitExtensions/UIHelpers.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#import <UIKit/UIKit.h>

#define UI_NULL_VALUE_TO_BE_CHANGED_LATER 0

#define UI_DESIGNATED_VALUE(value) (CGFloat)value
#define UI_CONTEXT_VALUE(value) (CGFloat)value
#define UI_CONTEXT_OFFSET(offset) (CGFloat)offset

static inline UIView * topMostView() {
    return UIApplication.sharedApplication.windows.lastObject;
}
