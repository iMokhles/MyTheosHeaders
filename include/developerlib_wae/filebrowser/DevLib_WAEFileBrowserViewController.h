#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
#include <objc/runtime.h>
#include <dlfcn.h>

@class DevLib_WAEFileBrowserViewController;

@protocol DevLib_WAEFileBrowserViewControllerDelegate <NSObject>
- (void)didSelectFile:(NSString *)path;
- (BOOL)shouldDeleteFileAtPath:(NSString *)path;
@optional
- (void)didLoadDirectory:(NSString *)path;
- (void)fileBrowserDidCancelled;
@end

@interface DevLib_WAEFileBrowserViewController: UITableViewController {
	NSFileManager *fileManager;
	NSString *path;
	NSMutableArray *contents;
	id <DevLib_WAEFileBrowserViewControllerDelegate> _delegate;
}

@property (nonatomic, readonly) NSString *path;
@property (nonatomic, strong) NSString *documentPath;
@property (nonatomic, assign) id <DevLib_WAEFileBrowserViewControllerDelegate> delegate;

@end