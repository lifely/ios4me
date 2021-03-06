/* 
 * Copyright (C) 2009-2010 Smart&Soft.
 * All rights reserved.
 *
 * The code hereby is the full property of Smart&Soft, SIREN 517 961 744.
 * http://www.smartnsoft.com - contact@smartnsoft.com
 * 
 * You are not allowed to use the source code or the resulting binary code, nor to modify the source code, without prior permission of the owner.
 */

//
//  Constants.h
//  ___PROJECTNAMEASIDENTIFIER___
//
//  Created by ___FULLUSERNAME___ on ___DATE___.
//  Copyright ___YEAR___ ___ORGANIZATIONNAME___. All rights reserved.
//


#import <Foundation/Foundation.h>

#import "___PROJECTNAMEASIDENTIFIER___AppDelegate.h"

/** Fixed size **/
#define standardScreenWidth 320
#define standardScreenHeight 480
#define standardResolution 163 // in dpi
#define statusBarHeight 20
#define navigationBarHeight 44
#define keyboardHeight 216
#define tabBarHeight 49
#define switchWidth 94
#define standardSliderHeight 30

#define APP_DELEGATE ((___PROJECTNAMEASIDENTIFIER___AppDelegate *) [[UIApplication sharedApplication] delegate])

#ifdef __IPHONE_3_2
#define IS_RUNNING_ON_IPAD UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad
#else
#define IS_RUNNING_ON_IPAD NO
#endif

#define COLOR_FFFFFF COLOR_HEXA(@"#FFFFFF")
#define COLOR_333333 COLOR_HEXA(@"#333333")
#define COLOR_666666 COLOR_HEXA(@"#666666")
#define COLOR_CCCCCC COLOR_HEXA(@"#CCCCCC")
#define COLOR_999999 COLOR_HEXA(@"#999999")
#define COLOR_000000 COLOR_HEXA(@"#000000")

#define VIEW_X(v)			((v).frame.origin.x)
#define VIEW_Y(v)			((v).frame.origin.y)
#define VIEW_WIDTH(v)		((v).frame.size.width)
#define VIEW_HEIGHT(v)		((v).frame.size.height)

#define kSnSScreenWidth			[[UIScreen mainScreen] applicationFrame].size.width
#define kSnSScreenHeight		[[UIScreen mainScreen] applicationFrame].size.height
#define kSnSCurrentOrientation 	[[UIApplication sharedApplication] statusBarOrientation]

#define SnSLocalized(s) NSLocalizedString(s,@"")

#define DeviceOrientationSupported(orientation) UIDeviceOrientationIsPortrait(orientation) 
#define NavigationBarTintColor RGB(182, 16, 127)

/********************************** TRACKING ANALYTICS ********************************/
// Google Analytics
extern NSString * const GA_UID;
extern NSString * const PREFIX_TRACKING;

// Flurry Analytics
/*
 Application name: ___PROJECTNAMEASIDENTIFIER___
 Unique application Key: ???????
 AppStoreId: com.smartnsoft.standard
 */
extern NSString * const FLURRY_APPLICATION_KEY;


/*
extern NSString * const WEB_SERVICE_URL_PREFIX;
*/

extern NSString * const CREDITS_URL_PREFIX;

extern const NSTimeInterval DOWNLOAD_TIMEOUT_IN_SECOND;
