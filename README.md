<h1>Computer Graphics and Animation Codes and Description</h1>
<p>In today's world, computer graphics is a common phenomenon. Computer graphics are used almost everywhere. For example, in 2D and 3D games, computer software, UI and UX design, camera positioning, clipping and so on. But how well do we know about the very basic concepts of computer graphics? How these complex structures are built? How the camera is set and what will be the effects of clipping? This repository contains codes of different concepts from Computer Graphics and step by step explanation for better understanding. You don't need to know any additional coding skills rather than simple C++ syntaxes to get started.</p>

<p>Here is the list of the labs and tasks which are covered in this repository:</p>
<ul>
    <li><b><a href="#lab01">Lab-01:</a></b></li>
    <ul>
        <li><b><a href="#lab01-00">Task-00:</a></b> Installation</li>
        <li><b>Task-01:</b> Basic code to draw a Triangle using Glut</li>
    </ul>
</ul>

<ul>
    <li><b>Lab-02:</b></li>
    <ul>
        <li><b>Task-01:</b> Create a leaf</li>
        <li><b>Task-02:</b> Color the leaf</li>
        <li><b>Task-03:</b> Create the same leave for 5 times to make a Star</li>
    </ul>
</ul>

<ul>
    <li><b>Lab-03:</b></li>
    <ul>
        <li><b>Task-01:</b> Rotate the star of the last lab continuously</li>
    </ul>
</ul>

<ul>
    <li><b>Lab-04:</b></li>
    <ul>
        <li><b>Task-01:</b> Show individual shapes of a leaf and Rotate, Scale or Translate them via keyboard</li>
        <li><b>Task-02:</b> Rotate an object with respect to a line via keyboard</li>
    </ul>
</ul>

<ul>
    <li><b>Lab-05:</b></li>
    <ul>
        <li><b>Task-01:</b> Create a 3D cube manually, set up the "gluLookAt" and "gluPerspective" functions and modify each value of these functions via keyboard</li>
    </ul>
</ul>


<h2 id="lab01"><b>Lab-01</b></h2>
<p>In the very first lab, our focus is to install necessary files and execute an example file which is creating a triangle and displaying it.</p>

<h3 id="lab01-00"><b>Task-00:</b></h3>
<p>Follow these steps:</p>

<ol>
    <li>Download and intall CodeBlocks from their <a href="http://www.codeblocks.org/downloads">official site.</a> Choose the version you need. If you don't know which one to choose, simply download Codeblocks *.* mingw setup.exe where *.* refers to the latest version of CodeBlocks.</li>
    <li>Now go to "glut-3.7.6-bin" folder which is attached in this repository.</li>
    <li>Copy the "glut.h" file to the include directory "C:\Program Files (x86)\CodeBlocks\MinGW\include\GL" (Choose your installation directory).</li>
    <li>Copy the "" file to the lib directory "C:\Program Files (x86)\CodeBlocks\MinGW\lib" (Choose your installation directory).</li>
    <li>Copy "glut32.dll" to the directory "C:\Windows\System"</li>
</ol>

<p>Now you've successfully installed glut package for CodeBlocks. If you're using Microsoft Visual Studio. Just follow the same steps as showed above for visiual studio directory. Now, run CodeBlocks, Go to File->New->Project..., Select "glut" and continue by clicking next. If you're asked to give mingw directory, just select the directory of mingw folder. After that, your project will be created, open main.cpp located in project_name/sources. Write the line following line on top:</p>

<code>
    #include "windows.h"
</code>

<p></p>
<p>Now run the program and it should run without any error.</p>

<h3 id="lab01-00"><b>Task-01:</b></h3>

<p>This is our first code for this topic. First let's break down the main function. The main function looks like this:</p>

<pre>
<code>
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(500,0);
    glutCreateWindow("Lab-1, Code 1: Creating a triangle and displaying it.");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
</code>
</pre>

<p></p>
<p>Here, glutInit() is used to initialize the GLUT library. glutInitDisplayMode() is used to declare variousmodes of display. You can add multiple modes using '|'. When using GL_SINGLE, you can picture your code drawing directly to the display having no buffers. If you use GL_DOUBLE, then you've double buffer and you can swap between buffer for smooth transition in case of rotation of movement. In case of movement you need to handle frames and GL_DOUBLE is the best option among these two for smooth transition. glutInitWindowSize() is used for initializing the window size having two paramenters: windows height and width. glutInitWindowPosition() is used to initialize the initial position of the window. glutCreateWindow() is used for creating the window with the name given inside the function. glMatrixMode() specify which matrix is the current matrix. It can have different parameters. Here, we will learn two of them: GL_MODELVIEW and GL_PROJECTION. GL_PROJECTION is used for setting your viewing volume. As for the GL_MODELVIEW matrix, it is used to make various transformations to the oject. glLoadIdentity() replaces the current matrix with an identity matrix. glutDisplayFunc() function displays whatever is defined inside the function called inside this as parameter. glutMainLoop() enters the GLUT event processing loop. Now let's move towards display function:</p>

<pre>
    <code>
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
    </code>
</pre>

<p></p>
<p>Here, inside the display function, we define what we want to display. In this example, a triangle has been created with the corresponding functions where glBegin() denotes starting of the drawing and glEnd() denotes end of the drawing. GL_TRIANGLES refers to creating triangles. glColor3f() sets the color in RGB format where 0 denotes no color or black and 1 denotes full color or white for the three parameters R, G and B. glVertex2f() defines the point in 2D co-ordinate.</p>


<p>That's all you needed to know for this lab. Moving onto next one.</p>


