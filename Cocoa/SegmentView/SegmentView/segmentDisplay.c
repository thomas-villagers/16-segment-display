/* thomas@friendlyvillagers.com  November 2014
     0    1 
   +----+----+           +            +       +
   | \  |  / | 2         | A         F \     / C
 7 |  \ | /  |       8   |              \   /
   +----+----+      +----+----+           +
   |  / | \  | 3         |   9          /   \
 6 | /  |  \ |         B |           E /     \ D
   +----+----+           +            +       +
      5    4
*/
#ifndef __SEGMENTDISPLAY_H__
#define __SEGMENTDISPLAY_H__
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include "segmentDisplay.h"

GLfloat background[] = {0.3,0.3,0.3};
GLfloat foreground[] = {0,0.9,0};

const float thickness = 0.3; /* segment thickness */

const int characterTable[] = { 0,      /*   */ 0x1000C, /* ! */ 0x404,  /* " */ 0xFC0,  /* # */ 0XFBB,   /* $ */
			       0X5F99, /* % */ 0,       /* & */ 0x400,  /* ' */ 0x3000, /* ( */ 0xC000,  /* ) */
			       0xFF00, /* * */ 0xF00,   /* + */ 0x4000, /* , */ 0x300,  /* - */ 0x10000, /* . */ 
			       0x5000, /* / */ 0x50FF,  /* 0 */ 0x100C, /* 1 */ 0x377,  /* 2 */ 0x23F,   /* 3 */
			       0x38C,  /* 4 */ 0x3BB,	/* 5 */ 0x3F9,  /* 6 */ 0xF,    /* 7 */ 0X3FF,   /* 8 */
			       0X39F,  /* 9 */ 0xC00,   /* : */ 0x4400, /* ; */ 0x3100, /* < */ 0x330,   /* = */
			       0xC200, /* > */ 0x10A07, /* ? */ 0x12F7, /* @ */ 0x3CF,  /* A */ 0xE3F,   /* B */
			       0xF3,   /* C */ 0xC3F,   /* D */ 0x1F3,  /* E */ 0x1C3,  /* F */ 0x2FB,   /* G */
			       0x3CC,  /* H */ 0xC33,	/* I */ 0x7C,   /* J */ 0x31C0, /* K */ 0xF0,    /* L */
			       0x90CC, /* M */ 0xA0CC,  /* N */ 0xFF,   /* O */ 0x3C7,  /* P */ 0x20FF,  /* Q */
			       0x23C7, /* R */ 0x3BB,   /* S */ 0xC03,  /* T */ 0xFC,   /* U */ 0x50C0,  /* V */
			       0x60CC, /* W */ 0xF000,  /* X */ 0xB84,  /* Y */ 0x5033, /* Z */ 0xC12,   /* [ */
			       0xA000, /* \ */ 0xC21,   /* ] */ 0x6000, /* ^ */ 0x30,   /* _ */ 0x8000,  /* ` */
			       0x8960, /* a */ 0x9E0,   /* b */ 0x160,  /* c */ 0xD60,  /* d */ 0x4170,  /* e */ 
			       0xF02,  /* f */ 0xDA1,   /* g */ 0x9C0,  /* h */ 0x800,  /* i */ 0xC60,   /* j */ 
			       0x3C00, /* k */ 0xC00,   /* l */ 0xB48,  /* m */ 0x940,  /* n */ 0x960,   /* o */
			       0x5C1,  /* p */ 0xD81,   /* q */ 0x140,  /* r */ 0x9A1,  /* s */ 0XF00,   /* t */
			       0x860,  /* u */ 0x4040,  /* v */ 0x6048, /* w */ 0xF000, /* x */	0xB84,   /* y */
			       0x4120, /* z */ 0xD12,   /* { */ 0xC0,   /* | */	0xE21,  /* } */ 0x9000,  /* ~ */
};

void drawPolygon(GLfloat vertices[], int n)
{
  const GLuint indices[] = { 0, 1, 2, 3, 4, 5};
  glVertexPointer(2, GL_FLOAT, 0, vertices);
  glDrawElements(GL_POLYGON, n, GL_UNSIGNED_INT, indices);
}

void drawHorizontalSegment(float length)
{
  length=0.5*length;
  GLfloat vertices[] = { length,thickness, 
			 length+0.25,0,
			 length,-thickness,
			 -length,-thickness,
			 -length-0.25,0,
			 -length,thickness };
  drawPolygon(vertices, 6);
}

void drawInnerHorizontalSegment(float sx, float sy)
{
  glPushMatrix();
  glScalef(sx,sy,1);
  glTranslatef(-1.25,0,0);
  drawHorizontalSegment(2);
  glPopMatrix();
}

void drawInnerVerticalSegment(float sx, float sy)
{
  const float length = 8*0.5;
  GLfloat vertices[] = { 0,0,
			 thickness,0.25,
			 thickness,length,
			 -thickness,length,
			 -thickness,0.25 };
  glPushMatrix();
  glScalef(sx,sy,1);
  glTranslatef(0,0.25,0);
  drawPolygon(vertices, 5);
  glPopMatrix();
}

void drawOuterHorizontalSegment(float sx, float sy)
{
  const float length=2.5;
  GLfloat vertices[] = { 0.075, -thickness,
			 length, -thickness,
			 length + 0.25, 0,
			 length, thickness,
			 0.075, thickness };
  glPushMatrix();
  glScalef(sx,sy,1);
  glTranslatef(0,4.7,0);
  drawPolygon(vertices, 5);
  glPopMatrix();
}

void drawSkewedSegment(float sx, float sy)
{
  GLfloat vertices[] = { 0.5, 1,
			 0.5,0.5,
			 0.75,0.5,
			 2.25,3.75,
			 2.25,4.25,
			 2,4.25 };
  glPushMatrix();
  glScalef(sx,sy,1);
  drawPolygon(vertices, 6);
  glPopMatrix();
}

void drawVerticalSegment(float sx, float sy)
{
  glPushMatrix();
  glScalef(sx,sy,1);
  glTranslatef(2.7,2.3,0);
  glRotatef(90,0,0,1);
  drawHorizontalSegment(4);
  glPopMatrix();
}

void drawSegment1()
{
  drawOuterHorizontalSegment(1,1);
}

void drawSegment0()
{
  drawOuterHorizontalSegment(-1,1);
}

void drawSegment2()
{
  drawVerticalSegment(1,1);
}

void drawSegment3()
{
  drawVerticalSegment(1,-1);
}

void drawSegment4()
{
  drawOuterHorizontalSegment(1,-1);
}

void drawSegment5()
{
  drawOuterHorizontalSegment(-1,-1);
}

void drawSegment6()
{
  drawVerticalSegment(-1,-1);
}

void drawSegment7()
{
  drawVerticalSegment(-1,1);
}

void drawSegment8()
{
  drawInnerHorizontalSegment(1,1);
}

void drawSegment9()
{
  drawInnerHorizontalSegment(-1,1);
}

void drawSegmentA()
{
  drawInnerVerticalSegment(1,1);
}

void drawSegmentB()
{
  drawInnerVerticalSegment(1,-1);
}

void drawSegmentC()
{
  drawSkewedSegment(1,1);
}

void drawSegmentD()
{
  drawSkewedSegment(1,-1);
}

void drawSegmentE()
{
  drawSkewedSegment(-1,-1);
}

void drawSegmentF()
{
  drawSkewedSegment(-1,1);
}

void drawDot()
{
  glBegin(GL_POINTS);
  glVertex2f(0.6,-0.8);
  glEnd();
}

void setColor(int segment, char c)
{
  int index = (int)c - 32;
  if ((1 << segment) & characterTable[index])
    glColor3fv(foreground);
  else
    glColor3fv(background);
}

void (*drawSegment_[])() = { drawSegment0, drawSegment1, drawSegment2, drawSegment3,
			     drawSegment4, drawSegment5, drawSegment6, drawSegment7,
			     drawSegment8, drawSegment9, drawSegmentA, drawSegmentB,
			     drawSegmentC, drawSegmentD, drawSegmentE, drawSegmentF
};

void drawSegment(int segment, char c)
{
  setColor(segment, c);
  drawSegment_[segment]();
}

void drawCharacter(char c)
{
  glPushMatrix();
  glScalef(1.0/6.0, 1/6.0, 1.0);
  glEnableClientState(GL_VERTEX_ARRAY);
  for (int i = 0; i < 0x10; i++)
    drawSegment(i, c);
  glDisableClientState(GL_VERTEX_ARRAY);
  glPopMatrix();

  setColor(0x10, c);
  drawDot();
}

#endif
