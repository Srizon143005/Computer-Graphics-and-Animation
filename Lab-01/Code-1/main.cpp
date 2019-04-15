#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void display(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.5,-0.25);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.5,-0.25);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0, 0.25);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Lab-1, Code-1: Creating a triangle and displaying it.");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
