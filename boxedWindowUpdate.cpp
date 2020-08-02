#include <stdio.h>

#include <GL/glut.h>

#include <iostream>

using namespace std;





float xr = 0, yr = 0; // to control the movement
float width = 500, height = 500; // control window size
float stepsize = 20; // control how many steps it takes to go from one end to another (resizes the sprite)



//user keyboard commands

// all keys are arrow keys on the keyboard

void specialkey (int key, int x, int y)



{

    switch (key)

    {

        case GLUT_KEY_UP:
            if (yr<(stepsize-1)) {
                yr++;
            }
            cout << y <<endl;

            glutPostRedisplay();

            break;

        case GLUT_KEY_DOWN:
            if (yr>0) {
                yr--;
            }
            cout<<y<<endl;

            glutPostRedisplay();

            break;

        case GLUT_KEY_LEFT:
            if (xr>0) {
                xr--;
            }

            cout<<x<<endl;

            glutPostRedisplay();

            break;

        case GLUT_KEY_RIGHT:
            if (xr<(stepsize-1)) {
                xr++;
            }

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

    glVertex3f(0.0+xr, 1.0+yr, 0.0); //bottom-right

    glVertex3f(1.0+xr, 1.0+yr, 0.0); //top-right

    glVertex3f(1.0+xr, 0.0+yr, 0.0); //top-left

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

    glutInitWindowSize(int(width),int(height)); //size of the window

    glutCreateWindow ("square");



    glClearColor(0.0, 0.0, 0.0, 0.1);         // background color

    glMatrixMode(GL_PROJECTION);              // setup viewing projection

    glLoadIdentity();

    glOrtho(0.0, stepsize, 0.0, stepsize, -1.0, 1.0);  



    glutDisplayFunc(display);

    glutSpecialFunc(specialkey); //call-back keyboard

    glutMainLoop();



    return 0;

}
