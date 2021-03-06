/* 
 * Copyright (C) 2009 Smart&Soft.
 * All rights reserved.
 *
 * The code hereby is the full property of Smart&Soft, SIREN 517 961 744.
 * http://www.smartnsoft.com - contact@smartnsoft.com
 * 
 * You are not allowed to use the source code or the resulting binary code, nor to modify the source code, without prior permission of the owner.
 *
 * This library is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 */

//
//  SnSURLCache.h
//  SnSFramework
//
//  Created by Édouard Mercier on 10/9/2009.
//

#import <Foundation/Foundation.h>

#import "SnSDelegate.h"

#pragma mark -
#pragma mark SnSURLCacheData

/**
 * Stores some data associated to an object.
 */
@interface SnSURLCacheData : NSObject
{
  NSData * data;
  id object;
}

@property(nonatomic, retain) NSData * data;
@property(nonatomic, retain) id object;

/**
 * @return a newly created object which holds the provided data and its associated object.
 */
+ (id) cacheDataWith:(NSData *)theData andObject:(id)theObject;

@end

#pragma mark -
#pragma mark SnSURLCacheException

/**
 * An exception which may be thrown by the SnSURLCache methods.
 */
@interface SnSURLCacheException : NSException
{
  id cause;
}

/**
 * The cause of the exception: may be <code>nil</code>
 */
@property(nonatomic, retain, readonly) id cause;

/**
 * @throws SnSURLCacheException an exception built from the provided error
 */
+ (void) raise:(NSError *)error;
- (id) initWithError:(NSError *)error;

@end

#pragma mark -
#pragma mark SnSURLCache

/**
 * Proposes a simple persistent cache based on the file system.
 */
@interface SnSURLCache : NSURLCache
{
  @private NSString * cacheDirectoryPath;
  @private NSString * indexFilePath;
  @private NSMutableDictionary * cache;
  @private SnSDelegate * urlRequestMatcher;
  @private SnSDelegate * localUriMatcher;
}

@property(nonatomic, retain, readonly) NSString * cacheDirectoryPath;
@property(nonatomic, retain, readonly) NSString * indexFilePath;
@property(nonatomic, retain, readonly) NSMutableDictionary * cache;
@property(nonatomic, retain, readonly) SnSDelegate * urlRequestMatcher;
@property(nonatomic, retain, readonly) SnSDelegate * localUriMatcher;

/**
 * Indicates how many cache instances should be created.
 *
 * <p>
 * Should be invoked only once, before using the cache! If this method is not called, only one instance is available.
 * </p>
 *
 * @param count the number of instances to create
 */
+ (void) setInstances:(NSUInteger)count andMemoryCapacities:(NSUInteger [])memoryCapacities andDiskCapacities:(NSUInteger [])diskCapacities andDiskPaths:(NSString * [])diskPaths;

/**
 * @return the single instance of the class
 */
+ (SnSURLCache *) instance;

/**
 * @param index the position of the instance to return
 * @return a valid instance of the class, corresponding to the provided index
 */
+ (SnSURLCache *) instance:(NSUInteger)index;

/**
 * @throws SnSURLCacheException if the data is not available according to the cache policy asked for
 */
- (NSData *) getFromCache:(NSURLRequest *)urlRequest;

- (NSData *) getFromCache:(NSString *)url cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeoutInterval;

/**
 * Retrieves some data from the cache in two phases: the data is returned from the cache if available, and then updated from Internet.
 *
 * The method returns as soon as the potential local cache has been retrieved, and will perform the data reloading from Internet in
 * a detached separate thread.
 *
 * @param delegate the object that will trigger its underlying selector when the data have been updated from Internet. The selector
 * must have the following signature: <code>(void) selector:(SnSURLCacheData *)urlCacheData</code>
 * @return the cached data; may be <code>nil</code> if the cache does not already contain the data
 * @throws SnSURLCacheException if the data is not available according to the cache policy asked for
 */
- (NSData *) getFromCache:(NSString *)url timeoutInterval:(NSTimeInterval)timeoutInterval andDelegate:(SnSDelegateWithObject *)delegate;

- (NSData *) getFromCache:(NSString *)url timeoutInterval:(NSTimeInterval)timeoutInterval andDelegate:(id)delegate andSelector:(SEL)selector andObject:(id)object;

/**
 * @return a local file URL corresponding to the provided URL, if already in cache; if not, <code>nil</code> is returned
 */
- (NSURL *) getCachedURL:(NSString *)url;

/**
 * Totally empties the cache.
 *
 * The cached persisted files are destroyed as well, not only the indexes.
 */
- (void) empty;

/**
 * Enables to control the mapping between the cached URLs and their local file counterpart.
 *
 * @param delegate the delegate method that will be invoked, and which takes two arguments: the first one is a <code>NSURL *</code> containing the URL, the second is a <code>NString **</code> which should contain the result
 */
- (void) setURLRequestMatcher:(SnSDelegate *)delegate;

/**
 * Enables to control the mapping between the cached URLs and their local file counterpart.
 *
 * @param delegate the delegate method that will be invoked, and which takes two arguments: the first one is a <code>NSString *</code> containing the URL, the second is a <code>NSString *</code> which contains the local file name, the third is a <code>NString **</code> which should contain the result
 */
- (void) setLocalURIMatcher:(SnSDelegate *)delegate;

@end
