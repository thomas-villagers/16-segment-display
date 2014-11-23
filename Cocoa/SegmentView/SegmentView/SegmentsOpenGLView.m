//
//  SegmentsOpenGLView.m
//  avcontrol
//
//  Created by thomas on 01/11/14.
//  Copyright (c) 2014 thomas. All rights reserved.
//

#import "SegmentsOpenGLView.h"
#import <OpenGL/gl.h>
#import "segmentDisplay.h"


@implementation SegmentsOpenGLView

NSString *myString = @"Test";

-(void) setText: (NSString*) str
{
    myString = [NSString stringWithString:str];
    [ self setNeedsDisplay: YES ] ;
}

char getCharAt(int i)
{
    return (i < [myString length]) ? [myString characterAtIndex:i] :' ';
}

-(void) drawRect: (NSRect) bounds
{
    float spacing = 1.1;
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glScalef(0.25,1,1);
    
    glTranslatef(-3.3,0,0);
    int nChars=7;
    for (int i = 0; i < nChars; i++)
    {
        drawCharacter(getCharAt(i));
        glTranslatef(spacing,0,0);
    }
    glPopMatrix();
    glFlush();
}
@end
