/**
 * This header is generated by class-dump-z 0.1-11o.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 */

#import <Foundation/NSObject.h>

@class NSIndexPath;

@interface UIUpdateItem : NSObject {
	int _action;
	NSIndexPath* _indexPath;
	int _animation;
	float _offset;
}
@property(readonly, assign, nonatomic) int action;
@property(readonly, assign, nonatomic) NSIndexPath* indexPath;
@property(readonly, assign, nonatomic) int animation;
@property(assign, nonatomic) float offset;
-(id)initWithAction:(int)action forIndexPath:(id)indexPath animation:(int)animation;
-(void)dealloc;
-(id)_actionDescription;
-(BOOL)isSectionOperation;
-(int)compareIndexPaths:(id)paths;
-(int)inverseCompareIndexPaths:(id)paths;
@end
