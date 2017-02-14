//
//  TaskThreadController.h
//  StuffItHelper
//
//  Created by Wes Gilpin on 10/24/07.
//  Copyright 2007 Smith Micro, Inc.. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "BasicProgressTask.h"

const int kMaxRunningThreads = 4;

#define kAddTask 1
#define kCompletedTask 2


@interface TaskThreadController : NSObject 
{
	NSMutableArray *mPendingTasks;
	NSMutableArray *mRunningTasks;
	NSMutableArray *mCompletedTasks;
	NSPort *mThreadPort; // Used by the controller thread.
		
	BOOL mShouldExit;
	BOOL mControllerRunning;
}


+ (TaskThreadController *) sharedThreadController;

- (id) init;
- (void) addTask:(BasicProgressTask *)inTask;

- (BOOL) shouldExit;
- (void) setShouldExit:(BOOL)inValue;

@end
