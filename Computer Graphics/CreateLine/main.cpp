
#include <GL/glut.h>
#include <stdlib.h>

/* Program entry point */
void init() //for setting background color for window
{
 glClearColor(1,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT);
 glFlush();
}
void display() //creates horizontal line
{
 glColor3f(1,0,0);
 glLineWidth(3);
 glBegin(GL_LINES);
 glVertex2f(1,0);
 glVertex2f(-1,0);
 glEnd();
 glFlush();
}
void display2() //creates vertical line
{
 glColor3f(1,0,0);
 glLineWidth(3);
 glBegin(GL_LINES);
 glVertex2f(0,1);
 glVertex2f(0,-1);
 glEnd();
 glFlush();
}

void display3() //creates + shape(combination of horizontal and vertical lines)
{
 glColor3f(1,0,0);
 glLineWidth(3);
 glBegin(GL_LINES);
 glVertex2f(0.5,0);
 glVertex2f(-0.5,0);
 glVertex2f(0,0.5);
 glVertex2f(0,-0.5);
 glEnd();
 glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Demo");

    init();
    glutDisplayFunc(display);//not there in lab. in lab directly call display
    //put the name of required display function as argument above(display,display2,display3)
    glutMainLoop();

    return EXIT_SUCCESS; //not there in lab. in lab return 0 is enough or no need to put.
}
