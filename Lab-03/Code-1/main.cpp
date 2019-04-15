#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void triangle(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.3, 0.31);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.3, 0.31);
    glEnd();
}

void quad(){
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.59, 0.61);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0, 0.31);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.59, 0.61);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0, 0.91);
    glEnd();
}

void polygon1(){
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0, 0.91);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(1.07, 1.1);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.37, 1.33);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.37, 1.33);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-1.07, 1.1);
    glEnd();
}

void polygon2(){
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.37, 1.33);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.6, 1.51);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0, 1.94);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.6, 1.51);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.37, 1.33);
    glEnd();
}

void leaf()
{
    triangle();
    quad();
    polygon1();
    polygon2();
    glFlush();
}

void display(){
    for(int i=0; i<=360; i+=72){
        glPushMatrix();
        glRotatef(i,0,0,1);
        glScalef(0.152,0.4,1);
        leaf();
        glPopMatrix();
    }
}

void rotated(){
    for(double i=0.0; ; i=i+0.1){
        glClear(GL_COLOR_BUFFER_BIT);
        glPushMatrix();
        glRotatef(i,0,0,1);
        display();
        glPopMatrix();
        glutSwapBuffers();
        glFlush();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Lab-3, Code-1: Rotating the star");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(rotated);
    glutMainLoop();
    return 0;
}
