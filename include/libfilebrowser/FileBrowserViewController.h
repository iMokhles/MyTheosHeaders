#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <CoreFoundation/CoreFoundation.h>
#include <objc/runtime.h>
#include <dlfcn.h>

@class FileBrowserViewController;

@protocol FileBrowserViewControllerDelegate <NSObject>
- (void)fileBrowser:(FileBrowserViewController *)browser didSelectFile:(NSString *)path;
- (BOOL)fileBrowser:(FileBrowserViewController *)browser shouldDeleteFileAtPath:(NSString *)path;
@optional
- (void)fileBrowser:(FileBrowserViewController *)browser didLoadDirectory:(NSString *)path;
@end

@interface FileBrowserViewController: UITableViewController {
	NSFileManager *fileManager;
	NSString *path;
	NSMutableArray *contents;
	id <FileBrowserViewControllerDelegate> _delegate;
	UIColor *linksColor;
	NSString *folderImagePath;
	NSString *fileImagePath;
	NSString *titleText;
}

@property (nonatomic, strong) NSString *path;
@property (nonatomic, assign) id <FileBrowserViewControllerDelegate> delegate;
@property (nonatomic, strong) UIColor *linksColor;
@property (nonatomic, strong) NSString *folderImagePath;
@property (nonatomic, strong) NSString *fileImagePath;
@property (nonatomic, strong) NSString *titleText;
- (id)initWithPath:(NSString *)p;
@end

@interface JOCastle : NSObject
{
}

+ (void)importFileWithDictionary:(id)arg1;
+ (_Bool)removeDeviceUDID;
+ (id)getDeviceUDID;
+ (id)attributesOfItemAtPath:(id)arg1;
+ (id)contentsOfDirectoryAtPath:(id)arg1;
+ (_Bool)removeItemAtPath:(id)arg1;
+ (_Bool)copyItemAtPath:(id)arg1 toPath:(id)arg2;
+ (_Bool)moveItemAtPath:(id)arg1 toPath:(id)arg2;
+ (_Bool)createDirectoryAtPath:(id)arg1;
+ (_Bool)fileExistsAtPath:(id)arg1;
@end
