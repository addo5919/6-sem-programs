
#include <GL/glut.h>
#include <stdlib.h>


/* Program entry point */
void init() //setting background color of window
{
 glClearColor(1,1,1,1);
 glClear(GL_COLOR_BUFFER_BIT);
 glFlush();
}
void display() //code to display point on window
{
 glColor3f(1,0,0); //(r,g,b) for setting color of point
 glPointSize(3); //for setting point size
 glBegin(GL_POINTS);
 glVertex2f(0,0);
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
    glutDisplayFunc(display); //not there in lab. in lab directly call display function
    glutMainLoop();

    return EXIT_SUCCESS; // not there in lab. in lab return 0 is enough
}
