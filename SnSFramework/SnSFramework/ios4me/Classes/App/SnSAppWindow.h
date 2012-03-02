/*
 * (C) Copyright 2009-2011 Smart&Soft SAS (http://www.smartnsoft.com/) and contributors.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 3.0 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * Contributors:
 *     Smart&Soft - initial API and implementation
 */

#import <UIKit/UIKit.h>

#pragma mark -
#pragma mark SnSAppWindowDelegate
#pragma mark -

@protocol SnSAppWindowDelegate <NSObject>

@optional

- (void)willSendEvent:(UIEvent*)iEvent;
- (void)didSendEvent:(UIEvent*)iEvent;

@end

#pragma mark -
#pragma mark SnSAppWindow
#pragma mark -

@interface SnSAppWindow : UIWindow
{
	id<SnSAppWindowDelegate> _eventDelegate;
}

@property (nonatomic, assign) id<SnSAppWindowDelegate> eventDelegate;

@end
