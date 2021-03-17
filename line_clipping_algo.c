#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#define TOP 8
#define BOTTOM 4
#define RIGHT 2
#define LEFT 1
#define TRUE 1
#define FALSE 0
double x0=70,y0=30,x1=70,y1=250;
int xmin=50,ymin=50,xmax=200,ymax=200;
void init()
{
     glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,600,0,600);
    glFlush();
}
void draw_rectangle(int xmin,int ymin,int xmax,int ymax)
{
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(xmin,ymin);
    glVertex2i(xmax,ymin);
    glVertex2i(xmax,ymax);
    glVertex2i(xmin,ymax);
    glEnd();
    glFlush();
}
void draw_line(double x0,double y0,double x1,double y1)
{
    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2d(x0,y0);
    glVertex2d(x1,y1);
    glEnd();
    glFlush();
}
int Compute_Code(double x,double y,int xmin,int ymin,int xmax,int ymax)
{
    int Code=0;
    if(y>ymax)
        Code=Code|TOP;
    if(y<ymin)
        Code=Code|BOTTOM;
    if(x>xmax)
        Code=Code|RIGHT;
    if(x<xmin)
        Code=Code|LEFT;
    return Code;
}
void Cohen_line_clip(double x0,double y0,double x1,double y1,int xmin,int ymin,int xmax,int ymax)
{
    int outCode0=Compute_Code(x0,y0,xmin,ymin,xmax,ymax);
     int outCode1=Compute_Code(x0,y0,xmin,ymin,xmax,ymax);
     int accept=FALSE;
     int done=FALSE;
     int outCode;
     double x,y;
     do
     {
         if((outCode0|outCode1)==0)
         {
             accept=TRUE;
             done=FALSE;
         }
         else if((outCode0&outCode1)!=0)
         {
             done=TRUE;
         }
         else
         {
             if(outCode0)
             {
                 outCode=outCode0;
             }
             else
             {
                 outCode=outCode1;
             }
             if(outCode&TOP)
             {
                 y=ymax;
                 x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
             }
                if(outCode&BOTTOM)
             {
                 y=ymin;
                 x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
             }
                if(outCode&RIGHT)
             {
                 x=xmax;
                 y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
             }
                 if(outCode&LEFT)
             {
                 x=xmin;
                 y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
             }
         }
     }while(!done);
     if(accept)
     {
         draw_rectangle(xmin,ymin,xmax,ymax);
         draw_line(x0,y0,x1,y1);
     }

}
void display()
{
 draw_rectangle(xmin,ymin,xmax,ymax);
 draw_line(x0,y0,x1,y1);
 Cohen_line_clip(x0,y0,x1,y1,xmin,ymin,xmax,ymax);
}
int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("demo");
    init();
    glutMainLoop();
    }
    glutDisplayFunc(display);
    glutMainLoop();

}
