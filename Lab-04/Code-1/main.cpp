/*
Author: Azmain Yakin Srizon
Controls:
    Down: 2     |    Rotate: R        |    Triangle: T    |    Leaf: M
    Left: 4     |    AntiRotate: E    |    Quad: Q        |    Quit: X
    Right: 6    |    ScaleUp: S       |    Polygon1: O    |
    Up: 8       |    ScaleDown: D     |    Polygon2: P    |
*/

#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

void Keyboard(unsigned char c, int x, int y);
void Keyboard1(unsigned char c, int x, int y);
void Keyboard2(unsigned char c, int x, int y);
void Keyboard3(unsigned char c, int x, int y);
void Keyboard4(unsigned char c, int x, int y);
void display();
void display1();
void display2();
void display3();
void display4();

void triangle(){
    glBegin(GL_TRIANGLES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.3*0.152, 0.31*0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0*0.152, 0.0*0.4);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.3*0.152, 0.31*0.4);
    glEnd();
}

void quad(){
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.59*0.152, 0.61*0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.0*0.152, 0.31*0.4);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.59*0.152, 0.61*0.4);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.0*0.152, 0.91*0.4);
    glEnd();
}

void polygon1(){
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0*0.152, 0.91*0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(1.07*0.152, 1.1*0.4);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.37*0.152, 1.33*0.4);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(-0.37*0.152, 1.33*0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-1.07*0.152, 1.1*0.4);
    glEnd();
}

void polygon2(){
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(0.37*0.152, 1.33*0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(0.6*0.152, 1.51*0.4);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(0.0*0.152, 1.94*0.4);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2f(-0.6*0.152, 1.51*0.4);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-0.37*0.152, 1.33*0.4);
    glEnd();
}

void display()
{
    triangle();
    quad();
    polygon1();
    polygon2();
    glFlush();
}

void display1(){
    triangle();
    glFlush();
}

void display2()
{
    quad();
    glFlush();
}

void display3(){
    polygon1();
    glFlush();
}

void display4(){
    polygon2();
    glFlush();
}

void Keyboard(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
        case 50:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,-.1,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 52:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(-.1,0,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 54:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(.1,0,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 56:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,.1,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 114:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(15,0,0,1);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 101:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(-15,0,0,1);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 115:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1.5,1.5,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 100:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1/1.5,1/1.5,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
            break;
        case 116:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard1);
            break;
        case 113:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard2);
            break;
        case 111:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard3);
            break;
        case 112:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard4);
            break;
        case 109:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard);
            break;
        case 120:
            exit(1);
    }
}

void Keyboard1(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
        case 50:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,-.1,0);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 52:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(-.1,0,0);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 54:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(.1,0,0);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 56:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,.1,0);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 114:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(15,0,0,1);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 101:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(-15,0,0,1);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 115:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1.5,1.5,0);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 100:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1/1.5,1/1.5,0);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            break;
        case 116:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard1);
            break;
        case 113:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard2);
            break;
        case 111:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard3);
            break;
        case 112:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard4);
            break;
        case 109:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard);
            break;
        case 120:
            exit(1);
    }
}

void Keyboard2(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
        case 50:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,-.1,0);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 52:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(-.1,0,0);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 54:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(.1,0,0);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 56:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,.1,0);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 114:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(15,0,0,1);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 101:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(-15,0,0,1);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 115:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1.5,1.5,0);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 100:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1/1.5,1/1.5,0);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            break;
        case 116:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard1);
            break;
        case 113:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard2);
            break;
        case 111:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard3);
            break;
        case 112:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard4);
            break;
        case 109:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard);
            break;
        case 120:
            exit(1);
    }
}

void Keyboard3(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
        case 50:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,-.1,0);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 52:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(-.1,0,0);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 54:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(.1,0,0);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 56:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,.1,0);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 114:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(15,0,0,1);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 101:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(-15,0,0,1);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 115:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1.5,1.5,0);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 100:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1/1.5,1/1.5,0);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            break;
        case 116:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard1);
            break;
        case 113:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard2);
            break;
        case 111:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard3);
            break;
        case 112:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard4);
            break;
        case 109:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard);
            break;
        case 120:
            exit(1);
    }
}

void Keyboard4(unsigned char c, int x, int y)
{
    printf("%d\n",c);
    switch(c)
    {
        case 50:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,-.1,0);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 52:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(-.1,0,0);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 54:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(.1,0,0);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 56:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,.1,0);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 114:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(15,0,0,1);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 101:
            glClear(GL_COLOR_BUFFER_BIT);
            glRotatef(-15,0,0,1);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 115:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1.5,1.5,0);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 100:
            glClear(GL_COLOR_BUFFER_BIT);
            glScalef(1/1.5,1/1.5,0);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            break;
        case 116:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display1);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard1);
            break;
        case 113:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display2);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard2);
            break;
        case 111:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display3);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard3);
            break;
        case 112:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display4);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard4);
            break;
        case 109:
            glClear(GL_COLOR_BUFFER_BIT);
            glutDisplayFunc(display);
            glutPostRedisplay();
            glutKeyboardFunc(Keyboard);
            break;
        case 120:
            exit(1);
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Lab-4, Code-1: Keyboard Interaction");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return 0;
}
