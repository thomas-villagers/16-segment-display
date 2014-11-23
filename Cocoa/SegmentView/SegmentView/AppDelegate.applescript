--
--  AppDelegate.applescript
--  SegmentView
--
--  Created by thomas on 23/11/14.
--  Copyright (c) 2014 thomas. All rights reserved.
--

script AppDelegate
	property parent : class "NSObject"
    property oglView : missing value
    
	-- IBOutlets
	property theWindow : missing value
	
	on applicationWillFinishLaunching_(aNotification)
		-- Insert code here to initialize your application before any files are opened
        oglView's setText_("1234567")
	end applicationWillFinishLaunching_
	
	on applicationShouldTerminate_(sender)
		-- Insert code here to do any housekeeping before your application quits 
		return current application's NSTerminateNow
	end applicationShouldTerminate_
	
end script