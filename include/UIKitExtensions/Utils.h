// UIKitExtensions
//
// UIKitExtensions/Utils.h
//
// Copyright (c) 2013 Stanislaw Pankevich
// Released under the MIT license

#ifndef UIKitExtensionsApp_Utils_h
#define UIKitExtensionsApp_Utils_h

// https://github.com/stanislaw/FoundationExtensions/blob/master/FoundationExtensions/NSObjCRuntime.h
#define UIKE_NSStringFromMethodForEnumType(_name, _type, _components...) static inline NSString *NSStringFrom##_name(_type value) { \
    NSArray *componentsStrings = [@(#_components) componentsSeparatedByString:@", "]; \
    \
    int N = (sizeof((_type[]){0, ##_components})/sizeof(_type) - 1); \
    _type componentsCArray[] = { _components }; \
    \
    for (int i = 0; i < N; i++) { \
        if (componentsCArray[i] == value) return [componentsStrings objectAtIndex:i]; \
    } \
    \
    return nil; \
}

#endif
