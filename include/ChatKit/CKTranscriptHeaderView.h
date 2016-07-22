/**
 * This header is generated by class-dump-z 0.1-11o.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 */

#import "ChatKit-Structs.h"
#import <UIKit/UIView.h>

@class UIPlacardButton;

@interface CKTranscriptHeaderView : UIView {
	id _delegate;
	UIPlacardButton* _firstButton;
	UIPlacardButton* _secondButton;
	UIPlacardButton* _loadMoreButton;
}
+(float)defaultHeight;
-(id)initWithFrame:(CGRect)frame withFirstTitle:(id)firstTitle withSecondTitle:(id)secondTitle displayLoadPrevious:(BOOL)previous;
-(void)dealloc;
-(void)setButtonsEnabled:(BOOL)enabled;
-(void)setDelegate:(id)delegate;
-(void)_buttonClicked:(id)clicked;
-(void)_loadMore;
@end
