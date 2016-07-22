/**
 * This header is generated by class-dump-z 0.1-11o.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 */

#import <Availability2.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_3_2

#include_next <UIKit/UITapGestureRecognizer.h>

@interface UITapGestureRecognizer (UITapGestureRecognizerPrivate)
@property(assign, nonatomic) float allowableMovement;
@property(assign, nonatomic) double maximumSingleTapDuration;
@property(assign, nonatomic) double maximumIntervalBetweenSuccessiveTaps;
// inherited: -(void)_appendSubclassDescription:(id)description;
@end

@interface UITapGestureRecognizer()
@property(readonly, assign, nonatomic) CGPoint centroid;
-(void)clearTapTimer;
-(void)startTapTimer:(double)timer;
-(void)tooSlow:(id)slow;
// inherited: -(BOOL)canPreventGestureRecognizer:(id)recognizer;
// inherited: -(CGPoint)locationInView:(id)view;
// inherited: -(unsigned)numberOfTouches;
// inherited: -(CGPoint)locationOfTouch:(unsigned)touch inView:(id)view;

#else

#import "UIKit-Structs.h"
#import "UIGestureRecognizer.h"

@class NSArray, NSMutableArray;

@interface UITapGestureRecognizer : UIGestureRecognizer {
	int _numberOfFingers;
	int _numberOfTaps;
	CGPoint _location;
	int _touchesAtMaxTaps;
	BOOL _gotEnoughTouches;
	NSMutableArray* _touches;
}
@property(assign, nonatomic) int numberOfTaps;
@property(assign, nonatomic) int numberOfFingers;
-(void)_tapTooSlow;
-(void)_doubleTapTooSlow;
#endif
@property(readonly, assign, nonatomic) CGPoint location;
@property(readonly, assign, nonatomic) NSArray* touches;
// inherited: -(id)initWithTarget:(id)target action:(SEL)action;
// inherited: -(void)dealloc;
// inherited: -(void)reset;
// inherited: -(void)touchesBegan:(id)began withEvent:(id)event;
// inherited: -(void)touchesMoved:(id)moved withEvent:(id)event;
// inherited: -(void)touchesEnded:(id)ended withEvent:(id)event;
// inherited: -(void)touchesCancelled:(id)cancelled withEvent:(id)event;
@end