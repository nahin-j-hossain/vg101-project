#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;


float xr = 0, yr = 0; // to control the movement

//user keyboard commands
// all keys are arrow keys on the keyboard
void specialkey (int key, int x, int y)

{
    switch (key)
    {
        case GLUT_KEY_UP:
            yr = yr +1;
            cout << y <<endl;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            yr--;
            cout<<y<<endl;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            xr--;
            cout<<x<<endl;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            xr++;
            cout<<x<<endl;
            glutPostRedisplay();
            break;

    }
}

void display(void)
{
    glClear( GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); //square color
    glBegin(GL_POLYGON);
    glVertex3f(0.0+xr, 2.0+yr, 0.0); //bottom-right
    glVertex3f(2.0+xr, 2.0+yr, 0.0); //top-right
    glVertex3f(2.0+xr, 0.0+yr, 0.0); //top-left
    glVertex3f(0.0+xr, 0.0+yr, 0.0); //bottom-left
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("hello world\n");
    glutInit(&argc, argv);
    glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100); //position of the window on the screen
    glutInitWindowSize(500,500); //size of the window
    glutCreateWindow ("square");

    glClearColor(0.0, 0.0, 0.0, 0.0);         // background color
    glMatrixMode(GL_PROJECTION);              // setup viewing projection
    glLoadIdentity();
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world

    glutDisplayFunc(display);
    glutSpecialFunc(specialkey); //call-back keyboard
    glutMainLoop();

    return 0;
}