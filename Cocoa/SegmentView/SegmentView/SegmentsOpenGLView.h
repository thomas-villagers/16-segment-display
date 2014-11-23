//
//  SegmentsOpenGLView.h
//  avcontrol
//
//  Created by thomas on 01/11/14.
//  Copyright (c) 2014 thomas. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface SegmentsOpenGLView : NSOpenGLView

- (void) drawRect: (NSRect) bounds;
- (void) setText : (NSString*) str;
@end
