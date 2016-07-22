//
// DevLibClient.h
// Unbox
//
// Created by Árpád Goretity on 07/11/2011
// Licensed under a CreativeCommons Attribution 3.0 Unported License
//

#import <unistd.h>
#import <stdlib.h>
#import <sys/types.h>
#import <sys/stat.h>
#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <AppSupport/CPDistributedMessagingCenter.h>

@interface DevLibClient: NSObject {
	CPDistributedMessagingCenter *center;
}

+ (id)sharedInstance;

- (NSString *)DevLib_temporaryFile;
- (void)DevLib_moveFile:(NSString *)file1 DevLib_toFile:(NSString *)file2;
- (void)DevLib_copyFile:(NSString *)file1 DevLib_toFile:(NSString *)file2;
- (void)DevLib_symlinkFile:(NSString *)file1 DevLib_toFile:(NSString *)file2;
- (void)DevLib_deleteFile:(NSString *)file;
- (NSDictionary *)DevLib_attributesOfFile:(NSString *)file;
- (NSArray *)DevLib_contentsOfDirectory:(NSString *)dir;
- (void)DevLib_chmodFile:(NSString *)file mode:(mode_t)mode;
- (BOOL)DevLib_fileExists:(NSString *)file;
- (BOOL)DevLib_fileIsDirectory:(NSString *)file;
- (void)DevLib_createDirectory:(NSString *)dir;

@end
