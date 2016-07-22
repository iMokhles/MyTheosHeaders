// UIKitExtensions
//
// UIKitExtensions/UIView/Framing.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license
//
// Inspired by FrameAccessor
// https://github.com/AlexDenisov/FrameAccessor/

#import <UIKit/UIKit.h>

@interface UIView (Framing)

// http://stackoverflow.com/questions/16118106/uitextview-strange-text-clipping
// https://github.com/genericspecific/CKUITools/issues/8
@property CGPoint viewOrigin;
@property CGSize  viewSize;

@property CGFloat x;
@property CGFloat y;
@property CGFloat height;
@property CGFloat width;

@property CGFloat centerX;
@property CGFloat centerY;

@end

