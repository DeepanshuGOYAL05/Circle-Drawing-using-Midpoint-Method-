#include <stdio.h>
#include <GL/glut.h>
int pntX1, pntY1, r;
void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+pntX1, y+pntY1);
    glEnd();
}
void plots(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(0.5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320.0,320.0, -260.0,260.0);
}
void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);
    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    } }
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(4.0);
 glBegin(GL_LINES);
glVertex2f(300.0, 0.0);
glVertex2f(320.0, 0.0);
   midPointCircleAlgo();
    for(int i=-320;i<=320;i++)
     { plots(i,0);
plots(0,i);
       }
 glFlush ();
}
int main(int argc, char** argv)
{   
    printf("Enter the coordinates of the center:\n\n");
    printf("X-coordinate   : "); scanf("%d",&pntX1);
    printf("\nY-coordinate : "); scanf("%d",&pntY1);
    printf( "\nEnter radius : ");scanf("%d",&r);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 400);
    glutCreateWindow ("Line Drawing Alogrithms");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
return 0;  }
