/**
 * This header is generated by class-dump-z 0.2-1.
 * class-dump-z is Copyright (C) 2009 by KennyTM~, licensed under GPLv3.
 *
 * Source: /System/Library/PrivateFrameworks/AccountSettings.framework/AccountSettings
 */

#import "AccountsManager.h"
#import <Foundation/NSObject.h>

@class NSMutableArray, NSArray, NSMutableDictionary;

@interface AccountsManager : NSObject {
@private
	NSMutableArray* _accounts;
	NSMutableDictionary* _accountsByID;
	unsigned _dataVersion;
	NSArray* _runtimeFixers;
}
+(void)_migrateAccountsIfNeeded;
+(id)displayNameForGroupOfAccountType:(id)accountType forBeginningOfSentence:(BOOL)sentence;
-(id)_initInsideOfMigration;
// inherited: -(id)init;
// inherited: -(void)dealloc;
-(id)accountWithIdentifier:(id)identifier;
-(id)accountWithSyncIdentifier:(id)syncIdentifier;
-(id)allBasicAccounts;
-(unsigned)countOfBasicAccountsWithTypes:(id)types;
-(id)displayNameForAccountWithIdentifier:(id)identifier;
-(id)displayNameForAccountWithSyncIdentifier:(id)syncIdentifier;
-(id)legacyAccounts;
-(void)setLegacyAccounts:(id)accounts;
-(id)fullDeviceLocalAccount;
-(id)fullAccountWithIdentifier:(id)identifier;
-(id)allMailAccounts;
-(id)allExchangeAccounts;
-(id)accountsWithTypes:(id)types;
-(unsigned)count;
-(void)updateAccount:(id)account;
-(void)insertAccount:(id)account;
-(void)deleteAccount:(id)account;
-(void)deleteAccountWithIdentifier:(id)identifier;
-(void)replaceExchangeAccountsWith:(id)with;
-(void)replaceAccountsWithTypes:(id)types withAccounts:(id)accounts;
-(void)saveAllAccounts;
-(id)_initWithAccountsInfo:(id)accountsInfo;
-(id)_createRuntimeFixers;
@end

@interface AccountsManager (MigrationSupport)
+(id)createAndLockMigrationLockToPerformMigration:(BOOL)performMigration;
+(void)releaseMigrationLock:(id)lock;
+(void)waitForMigrationToFinish;
+(void)removeNewAccountSettingsToMigrateOldAccountInformation;
+(void)shouldMigrateOldMailAccounts:(BOOL*)accounts oldDAAccounts:(BOOL*)accounts2 newAccountSettings:(BOOL*)settings;
+(BOOL)accountSettingsNeedsToBeMigrated;
+(BOOL)_oldDAAccountsInformationFound;
+(BOOL)_oldMailAccountsInformationFound;
-(void)setDataVersion:(unsigned)version;
@end

@interface AccountsManager (Private)
+(unsigned)currentVersion;
+(id)fullPathToAccountSettingsPlist;
-(id)initWithAccounsInfoArray:(id)accounsInfoArray;
-(unsigned)dataVersion;
@end
