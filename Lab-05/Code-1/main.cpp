#include <windows.h>
#include <stdio.h>
#include <GL/glut.h>

bool key[256];
double eye_x, eye_y, eye_z, center_x, center_y, center_z, up_x, up_y, up_z;
double scale_x, scale_y, scale_z;
double fovy_value, aspect_value, near_value, far_value;

void initialize(){
    for(int i=0; i<256; i++)
        key[i]=false;

    eye_x = 0.0;
    eye_y = 0.0;
    eye_z = 5.0;

    center_x = 0.0;
    center_y = 0.0;
    center_z = 0.0;

    up_x = 0.0;
    up_y = 1.0;
    up_z = 0.0;

    scale_x = 1.0;
    scale_y = 1.0;
    scale_z = 1.0;

    fovy_value = 45;
    aspect_value = 1.0;
    near_value = 1.0;
    far_value = 10.0;
}

void cube_design()
{
    // Ash - Back
    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.5, 0.5);
        glVertex3f(-1.0,-1.0,0.0);
        glVertex3f(1.0,-1.0,0.0);
        glVertex3f(1.0,1.0,0.0);
        glVertex3f(-1.0,1.0,0.0);
    glEnd();

    // Red - Front
    glBegin(GL_POLYGON);
        glColor3f(1.0,0.0,0.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
    glEnd();

    // Green - Up
    glBegin(GL_POLYGON);
        glColor3f(0.0,1.0,0.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(1.0,1.0,1.0);
        glVertex3f(1.0,1.0,0.0);
        glVertex3f(-1.0,1.0,0.0);
    glEnd();

    // Blue - Left
    glBegin(GL_POLYGON);
        glColor3f(0.0,0.0,1.0);
        glVertex3f(-1.0,-1.0,0.0);
        glVertex3f(-1.0,-1.0,1.0);
        glVertex3f(-1.0,1.0,1.0);
        glVertex3f(-1.0,1.0,0.0);
    glEnd();

    // Purple - Down
    glBegin(GL_POLYGON);
        glColor3f(0.5,0.0,0.5);
        glVertex3f(-1.0,-1.0,0.0);
        glVertex3f(1.0,-1.0,0.0);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(-1.0,-1.0,1.0);
    glEnd();

    // Right - Bluish Green
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.5, 0.5);
        glVertex3f(1.0,-1.0,1.0);
        glVertex3f(1.0,-1.0,0.0);
        glVertex3f(1.0,1.0,0.0);
        glVertex3f(1.0,1.0,1.0);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    gluLookAt(eye_x, eye_y, eye_z, center_x, center_y, center_z, up_x, up_y, up_z);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(fovy_value, aspect_value, near_value, far_value);
    glMatrixMode(GL_MODELVIEW);

    glScalef(scale_x, scale_y, scale_z);
    cube_design();
    glFlush ();
}

void Keyboard(unsigned char c, int x, int y)
{
    key[int(c)]=true;

    if(key['r'] && key['+']){
        fovy_value = fovy_value+1.0;
        glutPostRedisplay();
    }
    else if(key['r'] && key['-']){
        fovy_value = fovy_value-1.0;
        glutPostRedisplay();
    }
    else if(key['a'] && key['+']){
        aspect_value = aspect_value+0.1;
        glutPostRedisplay();
    }
    else if(key['a'] && key['-']){
        aspect_value = aspect_value-0.1;
        glutPostRedisplay();
    }
    else if(key['n'] && key['+']){
        near_value = near_value+0.1;
        glutPostRedisplay();
    }
    else if(key['n'] && key['-']){
        near_value = near_value-0.1;
        glutPostRedisplay();
    }
    else if(key['f'] && key['+']){
        far_value = far_value+0.1;
        glutPostRedisplay();
    }
    else if(key['f'] && key['-']){
        far_value = far_value-0.1;
        glutPostRedisplay();
    }
    else if(key['e'] && key['x'] && key['+']){
        eye_x = eye_x+0.1;
        glutPostRedisplay();
    }
    else if(key['e'] && key['x'] && key['-']){
        eye_x = eye_x-0.1;
        glutPostRedisplay();
    }
    else if(key['e'] && key['y'] && key['+']){
        eye_y = eye_y+0.1;
        glutPostRedisplay();
    }
    else if(key['e'] && key['y'] && key['-']){
        eye_y = eye_y-0.1;
        glutPostRedisplay();
    }
    else if(key['e'] && key['z'] && key['+']){
        eye_z = eye_z+0.1;
        glutPostRedisplay();
    }
    else if(key['e'] && key['z'] && key['-']){
        eye_z = eye_z-0.1;
        glutPostRedisplay();
    }
    else if(key['c'] && key['x'] && key['+']){
        center_x = center_x+0.1;
        glutPostRedisplay();
    }
    else if(key['c'] && key['x'] && key['-']){
        center_x = center_x-0.1;
        glutPostRedisplay();
    }
    else if(key['c'] && key['y'] && key['+']){
        center_y = center_y+0.1;
        glutPostRedisplay();
    }
    else if(key['c'] && key['y'] && key['-']){
        center_y = center_y-0.1;
        glutPostRedisplay();
    }
    else if(key['c'] && key['z'] && key['+']){
        center_z = center_z+0.1;
        glutPostRedisplay();
    }
    else if(key['c'] && key['z'] && key['-']){
        center_z = center_z-0.1;
        glutPostRedisplay();
    }
    else if(key['u'] && key['x'] && key['+']){
        up_x = up_x+0.1;
        glutPostRedisplay();
    }
    else if(key['u'] && key['x'] && key['-']){
        up_x = up_x-0.1;
        glutPostRedisplay();
    }
    else if(key['u'] && key['y'] && key['+']){
        up_y = up_y+0.1;
        glutPostRedisplay();
    }
    else if(key['u'] && key['y'] && key['-']){
        up_y = up_y-0.1;
        glutPostRedisplay();
    }
    else if(key['u'] && key['z'] && key['+']){
        up_z = up_z+0.1;
        glutPostRedisplay();
    }
    else if(key['u'] && key['z'] && key['-']){
        up_z = up_z-0.1;
        glutPostRedisplay();
    }
    else if(key['s'] && key['x'] && key['+']){
        scale_x = scale_x+0.1;
        glutPostRedisplay();
    }
    else if(key['s'] && key['x'] && key['-']){
        scale_x = scale_x-0.1;
        glutPostRedisplay();
    }
    else if(key['s'] && key['y'] && key['+']){
        scale_y = scale_y+0.1;
        glutPostRedisplay();
    }
    else if(key['s'] && key['y'] && key['-']){
        scale_y = scale_y-0.1;
        glutPostRedisplay();
    }
    else if(key['s'] && key['z'] && key['+']){
        scale_z = scale_z+0.1;
        glutPostRedisplay();
    }
    else if(key['s'] && key['z'] && key['m']){
        scale_z = scale_z-0.1;
        glutPostRedisplay();
    }
    else if(key['i']){
        initialize();
        glutPostRedisplay();
    }
    else if(key['X']){
        exit(1);
    }
}

void KeyUp(unsigned char c, int x, int y){
    key[int(c)]=false;
}

int main(int argc, char** argv)
{
    initialize();
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Lab-5, Code-1: Creating 3D cube manually and modifying parameters via keyboard");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);

    glutKeyboardFunc(Keyboard);
    glutKeyboardUpFunc(KeyUp);
    glutMainLoop();
    return 0;
}
