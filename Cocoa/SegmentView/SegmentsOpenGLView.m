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

char getNextChar(int i)
{
    return (i < [myString length]) ? [myString characterAtIndex:i] :' ';
}

-(void) drawRect: (NSRect) bounds
{
    float spacing = 6.75;
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glScalef(0.0575,0.15,1);
    glTranslatef(-13.5,0,0);
    int nChars=5;
    for (int i = 0; i < nChars; i++)
    {
        drawCharacter(getNextChar(i));
        glTranslatef(spacing,0,0);
    }
    glPopMatrix();
    glFlush();
}
@end
