#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
double A[2]={200,100};
double B[2]={100,200};
double C[2]={200,300};
double D[2]={300,200};

double le[500];
double re[500];

void init()
{
     glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glFlush();
}


void draw_polygon(double A[],double B[],double C[],double D[])
{
 glColor3f(1,0,0);
 glBegin(GL_LINE_LOOP);
 glVertex2dv(A);
 glVertex2dv(B);
 glVertex2dv(C);
 glVertex2dv(D);
 glEnd();
 glFlush();
}
void display()
{
    draw_polygon(A,B,C,D);
    poly_fill(A,B,C,D);

}

void init_array(double le[],double re[])
{
    int i;
    for(i=0;i<500;i++)
    {
        le[i]=999;
        re[i]=0;
    }

}

void edge_detect(double v1[],double v2[])
{
    double x0,y0,x1,y1,x,m;
    int y;
    x0=v1[0];
    y0=v1[1];
    x1=v2[0];
    y1=v2[1];

    if(y0>y1)
    {
        int temp=x0;
        x0=x1;
        x1=temp;
        temp=y0;
        y0=y1;
        y1=temp;
    }

    if((y1-y0)==0)
    {
        m=1/(x1-x0);
    }
    else
    {
        m=(y1-y0)/(x1-x0);
    }
    x=x0;
    for(y=y0;y<=y1;y++)
    {
        if(x<le[y])
            le[y]=x;
        if(x>re[y])
            re[y]=x;
        x=x+(1/m);
    }

}
void poly_fill(double A[],double B[],double C[],double D[])
{
    init_array(le,re);
    edge_detect(A,B);
    edge_detect(B,C);
    edge_detect(C,D);
    edge_detect(D,A);
    fill_pixel(le,re);
}

void fill_pixel(double le[],double re[])
{
    int i,j;
    for(i=0;i<500;i++)
    {
        if(le[i]<re[i])
        {
         for(j=le[i];j<=re[i];j++)
         {
             glBegin(GL_POINTS);
             glVertex2d(j,i);
             glEnd();
             glFlush();
         }

        }
    }

}
int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("demo");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

}
