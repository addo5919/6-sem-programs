#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
double house[9][3]={{150,150,1},
{350,150,1},
{350,300,1},
{150,300,1},
{250,400,1},
{225,150,1},
{225,225,1},
{275,225,1},
{275,150,1}};

double result[9][3]; //final rotated matrix/house
double degree=45; //angle to be rotated(anticlockwise), for clockwise, degree=-45



void init()
{
     glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    glFlush();
}

void draw_house(double house[9][3])
{
    glColor3f(1,0,0);
    glBegin(GL_LINE_LOOP);
    glVertex2dv(house[0]); //first outer rectangle
    glVertex2dv(house[1]);
    glVertex2dv(house[2]);
    glVertex2dv(house[3]);
    glEnd();

    glBegin(GL_LINE_STRIP); //now triangle(roof)
    glVertex2dv(house[2]);
     glVertex2dv(house[4]);
      glVertex2dv(house[3]);
    glEnd();

    glBegin(GL_LINE_STRIP); //now inner rectangle(door)
     glVertex2dv(house[5]);
      glVertex2dv(house[6]);
       glVertex2dv(house[7]);
         glVertex2dv(house[8]);
         glEnd();
         glFlush();
}

void rotate_house(double house[9][3]) //rotates house at point 0 (150,150)
{
    double xp=150;
    double yp=150;
    double theta=(3.142/180)*degree; //for performing trignometric operations angle should be in radians
    double Ra[3][3]={{cos(theta),sin(theta),0}
    ,{-sin(theta),cos(theta),0},
    {-xp*cos(theta)+yp*sin(theta)+xp,-xp*sin(theta)-yp*cos(theta)+yp,1}};

    int i,j,k; //multiplication of matrices
    for(i=0;i<9;i++)//no of rows of house
    {
        for(j=0;j<3;j++)//no of columns of matrix Ra
      {
          result[i][j]=0;
        for(k=0;k<3;k++)
        {
            result[i][j]=result[i][j]+house[i][k]*Ra[k][j];

        }
    }
    }
}

void display()
{
 draw_house(house);
 glClear(GL_COLOR_BUFFER_BIT);
 //rotate_house(house);
 //draw_house(result);
}

void mouse(int btn,int state,int x,int y)
{
    if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        degree=45;
        rotate_house(house);
        draw_house(result);
    }

    if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        degree=-45;
        rotate_house(house);
        draw_house(result);
    }
}

void keyboard(unsigned char c,int x,int y)
{
    if(c=='r'||c=='R')
    {
        degree=45;
        rotate_house(house);
        draw_house(result);
    }
    if(c=='q'||c=='Q')
    {
        exit(0);
    }
}

void special(int key,int x,int y)
{
    if(key==GLUT_KEY_LEFT)
    {
        degree=45;
        rotate_house(house);
        draw_house(result);
    }
    if(key==GLUT_KEY_RIGHT)
    {
        degree=-45;
        rotate_house(house);
        draw_house(result);
    }
    if(key==GLUT_KEY_END)
    {
     exit(0);
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
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
    glutMainLoop();

}
