#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

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

void display()
{
    triangle();
    glFlush();
}

void Keyboard(unsigned char c, int x, int y)
{
    //printf("%d\n",c);
    switch(c)
    {
        case 97:
            glClear(GL_COLOR_BUFFER_BIT);
            glTranslatef(0,0.2,0);
            glRotatef(45,0,0,1);
            glScalef(1.0,-1.0,1);
            glRotatef(-45,0,0,1);
            glTranslatef(0,-0.2,0);
            glutDisplayFunc(display);
            glutPostRedisplay();
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
    glutCreateWindow("Lab-4, Code-1: Press A to Rotate with respect to line");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return 0;
}

