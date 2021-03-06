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
#pragma mark SnsBusinessObjectsRetrievalAsynchronousPolicy

/**
 * Should be used only on a <code>UIViewController</code>, and indicates that the loading of the business objects should be loaded asynchronously or not.
 */
@protocol SnsBusinessObjectsRetrievalAsynchronousPolicy

@end

#pragma mark -
#pragma mark SnSViewControllerLifeCycle

/**
 * Indicates the main events of a <code>UIViewController</code>, in order to framework its life cycle.
 *
 * <p>Those events apply to an entity, which is stored in memory through business objects (one, or multiple), and graphically as well
 * by various components/widgets.</p>
 *
 * <p>You should never call those methods explicitly, but let the framework invoke them for you!</p>
 */
@protocol SnSViewControllerLifeCycle

/**
 * Responsible for computing the GUI objects associated to the current entity, and for adding
 * it to the parent view.
 *
 * @param view the parent view the current entity should be represented on
 */
@required - (void) onRetrieveDisplayObjects:(UIView *)view;

/**
 * In charge of retrieving the business objects that represent in memory the entity.
 *
 * <p>That method will not necessarily be invoked from the GUI thread.</p>
 */
@required - (void) onRetrieveBusinessObjects;

/**
 * In charge of binding the business objects with their GUI representation.
 *
 * Will be invoked only the first time the entity is displayed on the screen.
 * <p>It is ensured that this method will be invoked from the GUI thread.</p>
 */
@required - (void) onFulfillDisplayObjects;

/**
 * In charge of binding the business objects with their GUI representation.
 *
 * Will be invoked everytime the entity is displayed on the screen.
 * <p>It is ensured that this method will be invoked from the GUI thread.</p>
 */
@optional - (void) onSynchronizeDisplayObjects;

/**
 * In charge of cleaning up the memory associated with the business objects and the GUI elements.
 */
@required - (void) onDiscarded;

/**
 * Obtain extra param for analytics trackers
 */
@optional - (NSString *) trackerInfos;

@end

#pragma mark -
#pragma mark SnSAggregateViewController

/**
 * An entity which follows the SnSViewControllerLifeCycle life cycle, and which can be aggregated.
 */
@interface SnSAggregateViewController : NSObject<SnSViewControllerLifeCycle>
@end

#pragma mark -
#pragma mark SnSLifeCycleException

extern NSString * const BAD_USAGE_SNSCODE;

/**
 * The basis class for all exceptions related to the SnSViewControllerLifeCycle protocol.
 */
@interface SnSLifeCycleException : NSException

+ (void) raise:(NSString *)name format:(NSString *)format, ...;

@end

#pragma mark -
#pragma mark SnSBusinessException

/**
 * Should be triggered whenever a business object is not available or accessible in the SnSViewControllerLifeCycle::onRetrieveBusinessObjects protocol method.
 */
@interface SnSBusinessObjectException : SnSLifeCycleException
@end
