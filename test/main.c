// Mac OS compile: gcc -framework OpenGL -framework GLUT -lobjc simple.c 
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif
#include "../src/segmentDisplay.h"

void drawString(char *s)
{
 float distance=1.25;
  while(*s)
    {
      drawCharacter(*s++);
      glTranslatef(distance,0,0);
    }
}

void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-5,5,-3.5,3.5,-1,20);
  glMatrixMode(GL_MODELVIEW);
  glPointSize(6.0);

  glPushMatrix();
  glTranslatef(-4,2,0);
  drawString("abcdefg");
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-4,0,0);
  drawString("hijklmn");
  glPopMatrix();
    
  glPushMatrix();
  glTranslatef(-4,-2,0);
  drawString("opqrstu");
  glPopMatrix();

  glFlush();
}

int main(int argc, char **argv)
{
  glutInit(&argc,argv);
  glutInitWindowSize(800,600);
  glutCreateWindow("16 Segment Display");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
