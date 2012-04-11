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
 * Creator:
 *     Johan Attali
 */

#import "SnSScrollFollower.h"

#define VIEW_X(v)			((v).frame.origin.x)
#define VIEW_Y(v)			((v).frame.origin.y)
#define VIEW_WIDTH(v)		((v).frame.size.width)
#define VIEW_HEIGHT(v)		((v).frame.size.height)

@implementation SnSScrollFollower
@synthesize scrollFollowed = scrollFollowed_;

#pragma mark -
#pragma mark ScollFollower
#pragma mark -

- (void)updateDisplay
{
	
}

#pragma mark -
#pragma mark SnSViewControllerLifeCycle
#pragma mark -

/**
 * Called after the loadView call
 */
- (void)onRetrieveDisplayObjects:(UIView *)view
{
	[super onRetrieveDisplayObjects:view];
	
	// -------------------------
	// Setup View
	// -------------------------
	self.view.frame				= CGRectMake(0, 0, SnSScollFollowerDefaultSize.width, SnSScollFollowerDefaultSize.height);
	self.view.center			= CGPointMake(VIEW_WIDTH(scrollFollowed_)-VIEW_WIDTH(self.view), 0);
	self.view.backgroundColor	= [UIColor clearColor];
	self.view.clipsToBounds		= YES;
	
	// -------------------------
	// SnSScrollFollowerView
	// -------------------------
	SnSScrollFollowerView* v = [[[SnSScrollFollowerView alloc] initWithFrame:CGRectMake(0,
																						0, //-VIEW_HEIGHT(self.view)*.5f,
																						VIEW_WIDTH(self.view),
																						VIEW_HEIGHT(self.view))] autorelease];
	
	v.autoresizingMask = UIViewAutoresizingFlexibleHeight|UIViewAutoresizingFlexibleWidth;
	[self.view addSubview:v];
	
	// -------------------------
	// Gesture Recognizer
	// -------------------------
	UIPanGestureRecognizer* pan = [[[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(onPan:)] autorelease];
	pan.maximumNumberOfTouches = 1;
	pan.minimumNumberOfTouches = 1;
	
	[v addGestureRecognizer:pan];
}

/**
 * Called after the viewDidLoad call
 */
- (void)onRetrieveBusinessObjects
{	
	[super onRetrieveBusinessObjects];
	
}

/**
 * Called after the viewWillAppear call
 */
- (void)onFulfillDisplayObjects
{
	[super onFulfillDisplayObjects];
	
		
}

/**
 * Called after the viewDidAppear call
 */
- (void)onSynchronizeDisplayObjects
{
	[super onSynchronizeDisplayObjects];
	
}

/**
 * Called after the viewDidUnload call
 */
- (void)onDiscarded
{
	[super onDiscarded];
}

#pragma mark -
#pragma mark Events
#pragma mark -

- (void)onPan:(UIPanGestureRecognizer *)iPanRecognizer
{
	SnSLogD(@"");
}

#pragma mark -
#pragma mark Scroll Follower 
#pragma mark -

- (void)follow
{
	// No need to go further if the scroll view is not set
	if (!scrollFollowed_)
		return;
	
	// the ratio will depend on the view relative position to its window
	CGFloat ratio = [self ratio];
	
	// Calculate the indictor length
	CGFloat length = [self indicatorLength];
	
	CGFloat shift = -length*ratio + length*0.5f;
	
	// calculate the new y position
	CGFloat y = ratio * scrollFollowed_.bounds.size.height + shift;
	
	// Readjust position if overflow
	if (y < VIEW_HEIGHT(self.view)*0.5f)
		y = VIEW_HEIGHT(self.view)*0.5f;
	else if (y+VIEW_HEIGHT(self.view)*0.5f > VIEW_HEIGHT(scrollFollowed_))
		y = VIEW_HEIGHT(scrollFollowed_)-VIEW_HEIGHT(self.view)*0.5f;
	
	
	// update the view position
	self.view.center = CGPointMake(self.view.center.x, y);
	
}



#pragma mark -
#pragma mark Scroll Math Calculation
#pragma mark -

-(CGFloat)ratio
{
	// should return 0 when the user hasen't scrolled and 1 when the view is completely scrolled
	return scrollFollowed_.contentOffset.y/(scrollFollowed_.contentSize.height-scrollFollowed_.bounds.size.height);
	
}

- (CGFloat)indicatorLength
{
	// Calculate the indicator length
	CGFloat length = scrollFollowed_.bounds.size.height/scrollFollowed_.contentSize.height*scrollFollowed_.bounds.size.height;
	
	// Minimum size is 35px (beware this might change in next version of iOS)
	length = length < 35.f ? 35.f : length;
	
	return length;
}



#pragma mark -
#pragma mark UIViewController
#pragma mark -

#pragma mark Basics

- (void)dealloc
{
	[super dealloc];
}

- (void)didReceiveMemoryWarning
{
	SnSLogW(@"");
	
	[super didReceiveMemoryWarning];
	
}

#pragma mark Rotation

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation 
{
	return YES;
}

- (void)willRotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation duration:(NSTimeInterval)duration
{
	SnSLogD(@"");
}

- (void)didRotateFromInterfaceOrientation:(UIInterfaceOrientation)fromInterfaceOrientation
{
	SnSLogD(@"");
}





@end