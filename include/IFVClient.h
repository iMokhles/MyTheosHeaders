//
// IFVClient.h
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

@interface IFVClient: NSObject {
	CPDistributedMessagingCenter *center;
}

+ (id)sharedInstance;

- (NSString *)IFV_temporaryFile;
- (void)IFV_moveFile:(NSString *)file1 IFV_toFile:(NSString *)file2;
- (void)IFV_copyFile:(NSString *)file1 IFV_toFile:(NSString *)file2;
- (void)IFV_symlinkFile:(NSString *)file1 IFV_toFile:(NSString *)file2;
- (void)IFV_deleteFile:(NSString *)file;
- (NSDictionary *)IFV_attributesOfFile:(NSString *)file;
- (NSArray *)IFV_contentsOfDirectory:(NSString *)dir;
- (void)IFV_chmodFile:(NSString *)file mode:(mode_t)mode;
- (BOOL)IFV_fileExists:(NSString *)file;
- (BOOL)IFV_fileIsDirectory:(NSString *)file;
- (void)IFV_createDirectory:(NSString *)dir;

@end
