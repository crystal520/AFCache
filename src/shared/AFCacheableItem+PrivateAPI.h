//
//  AFCacheableItem_Private.h
//  AFCache-iOS
//
//  Created by Christian Menschel on 23.04.13.
//  Copyright (c) 2013 Artifacts - Fine Software Development. All rights reserved.
//

#import "AFCache.h"
#import "AFCacheableItem.h"

@interface AFCacheableItem ()
@property (nonatomic, retain) AFCache *cache;
@property (nonatomic, retain) NSURL *url;
@property (nonatomic, retain) NSData *data;

@property (nonatomic, assign) id <AFCacheableItemDelegate> delegate;
@property (nonatomic, retain) NSError *error;
@property (nonatomic, retain) NSDate *validUntil;


@property (nonatomic, assign) SEL connectionDidFinishSelector;
@property (nonatomic, assign) SEL connectionDidFailSelector;
@property (nonatomic, assign) int cacheStatus;
@property (nonatomic, retain) AFCacheableItemInfo *info;

@property (nonatomic, retain) NSFileHandle* fileHandle;

@property (nonatomic, assign) BOOL persistable;
@property (nonatomic, assign) BOOL ignoreErrors;
@property (nonatomic, assign) BOOL justFetchHTTPHeader;

@property (nonatomic, assign)   BOOL isRevalidating;
@property (nonatomic, readonly) BOOL canMapData;
@property (nonatomic, assign)   BOOL isPackageArchive;
@property (nonatomic, assign)   BOOL servedFromCache;
@property (nonatomic, assign)   BOOL URLInternallyRewritten;

@property (nonatomic, assign) uint64_t currentContentLength;

@property (nonatomic, retain) NSURLRequest *IMSRequest;


@property (nonatomic, assign) int tag;

- (void)setDownloadStartedFileAttributes;
- (void)setDownloadFinishedFileAttributes;
- (BOOL)isDownloading;
- (BOOL)hasDownloadFileAttribute;
- (BOOL)hasValidContentLength;
- (uint64_t)getContentLengthFromFile;
- (void)appendData:(NSData*)newData;
- (void)signalItems:(NSArray*)items usingSelector:(SEL)selector;
- (void)signalItems:(NSArray*)items usingSelector:(SEL)selector usingBlock:(void (^)(void))block;
- (void)signalItemsDidFinish:(NSArray*)items;
- (void)signalItemsDidFail:(NSArray*)items;



#if NS_BLOCKS_AVAILABLE
@property (nonatomic, copy) AFCacheableItemBlock completionBlock;
@property (nonatomic, copy) AFCacheableItemBlock failBlock;
@property (nonatomic, copy) AFCacheableItemBlock progressBlock;
#endif




#ifdef USE_TOUCHXML
- (CXMLDocument *)asXMLDocument;
#endif

@end

@protocol AFCacheableItemDelegate < NSObject >


@optional
- (void) connectionDidFail: (AFCacheableItem *) cacheableItem;
- (void) connectionDidFinish: (AFCacheableItem *) cacheableItem;
- (void) connectionHasBeenRedirected: (AFCacheableItem *) cacheableItem;

- (void) packageArchiveDidReceiveData: (AFCacheableItem *) cacheableItem;
- (void) packageArchiveDidFinishLoading: (AFCacheableItem *) cacheableItem;
- (void) packageArchiveDidFinishExtracting: (AFCacheableItem *) cacheableItem;
- (void) packageArchiveDidFailExtracting: (AFCacheableItem *) cacheableItem;
- (void) packageArchiveDidFailLoading: (AFCacheableItem *) cacheableItem;

- (void) cacheableItemDidReceiveData: (AFCacheableItem *) cacheableItem;

@end
