//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import "NSObject.h"

@interface JOiTunesMP4Utilities : NSObject
{
}

+ (_Bool)convertAsset:(id)arg1 dest:(id)arg2 metadata:(id)arg3 timeRange:(CDStruct_3c1748cc)arg4 error:(id *)arg5;
+ (_Bool)_assetIsVideo:(id)arg1;
+ (long long)_convertAsset:(id)arg1 outURL:(id)arg2 metadata:(id)arg3 outputType:(id)arg4 timeRange:(CDStruct_3c1748cc)arg5;
+ (id)_translatedMetadataKeysForAsset:(id)arg1 externalMetadata:(id)arg2;
+ (_Bool)_fileOutput:(id)arg1 supportedForSession:(id)arg2;
+ (unsigned int)_fileTypeForURL:(id)arg1;

@end
