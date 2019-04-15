<h1>Computer Graphics and Animation Codes and Description</h1>
<p>In today's world, computer graphics is a common phenomenon. Computer graphics are used almost everywhere. For example, in 2D and 3D games, computer software, UI and UX design, camera positioning, clipping and so on. But how well do we know about the very basic concepts of computer graphics? How these complex structures are built? How the camera is set and what will be the effects of clipping? This repository contains codes of different concepts from Computer Graphics and step by step explanation for better understanding. You don't need to know any additional coding skills rather than simple C++ syntaxes to get started.</p>

<p>Here is the list of the labs and tasks which are covered in this repository:</p>
<ul>
    <li><b><a href="#lab01">Lab-01:</a></b></li>
    <ul>
        <li><b><a href="#lab01-00">Task-00:</a></b> Installation</li>
        <li><b><a href="#lab01-01">Task-01:</a></b> Basic code to draw a Triangle using Glut</li>
    </ul>
</ul>

<ul>
    <li><b><a href="#lab02">Lab-02:</a></b></li>
    <ul>
        <li><b><a href="#lab02-01">Task-01:</a></b> Create a leaf</li>
        <li><b><a href="#lab02-02">Task-02:</a></b> Color the leaf</li>
        <li><b><a href="#lab02-03">Task-03:</a></b> Create the same leave for 5 times to make a Star</li>
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
    <li>Copy the "glut.h" file to the include directory <code>C:\Program Files (x86)\CodeBlocks\MinGW\include\GL</code> (Choose your installation directory).</li>
    <li>Copy the "" file to the lib directory <code>C:\Program Files (x86)\CodeBlocks\MinGW\lib</code> (Choose your installation directory).</li>
    <li>Copy "glut32.dll" to the directory <code>C:\Windows\System</code></li>
</ol>

<p>Now you've successfully installed glut package for CodeBlocks. If you're using Microsoft Visual Studio. Just follow the same steps as showed above for visiual studio directory. Now, run CodeBlocks, Go to File->New->Project..., Select "glut" and continue by clicking next. If you're asked to give mingw directory, just select the directory of mingw folder. After that, your project will be created, open main.cpp located in project_name/sources. Write the line following line on top:</p>

<code>
    #include "windows.h"
</code>

<p></p>
<p>Now run the program and it should run without any error.</p>

<h3 id="lab01-01"><b>Task-01:</b></h3>

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
<p>Here, <code>glutInit()</code> is used to initialize the GLUT library. <code>glutInitDisplayMode()</code> is used to declare various modes of display. You can add multiple modes using '|'. When using <code>GL_SINGLE</code>, you can picture your code drawing directly to the display having no buffers. If you use <code>GL_DOUBLE</code>, then you've double buffer and you can swap between buffers for smooth transition in case of rotation or movement. In case of movement you need to handle frames and <code>GL_DOUBLE</code> is the best option among these two for smooth transition.</p>

<p><code>glutInitWindowSize()</code> is used for initializing the window size having two paramenters: height and width. <code>glutInitWindowPosition()</code> is used to initialize the initial position of the window. <code>glutCreateWindow()</code> is used for creating the window with the name given inside the function.</p>

<p><code>glMatrixMode()</code> specifies which matrix is the current matrix. It can have different parameters. Here, we will learn two of them: <code>GL_MODELVIEW</code> and <code>GL_PROJECTION</code>. <code>GL_PROJECTION</code> is used for setting your viewing volume. As for the <code>GL_MODELVIEW</code> matrix, it is used to make various transformations to the oject. <code>glLoadIdentity()</code> replaces the current matrix with an identity matrix. <code>glutDisplayFunc()</code> function displays whatever is defined inside the function called from it. <code>glutMainLoop()</code> enters the GLUT event processing loop. Now let's move towards display function:</p>

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
<p>Here, inside the display function, we define what we want to display. In this example, a triangle has been created with the corresponding functions where <code>glBegin()</code> denotes starting of the drawing and <code>glEnd()</code> denotes end of the drawing. GL_TRIANGLES refers to creating triangles. <code>glColor3f()</code> sets the color in RGB format where 0 denotes no color or black and 1 denotes full color or white for the three parameters Red, Green and Blue. <code>glVertex2f()</code> defines the point in 2D co-ordinate. The <code>glFlush()</code> function forces execution of OpenGL functions in finite time</p>


<p>That's all you needed to know for this lab. Moving onto next one.</p>




<h2 id="lab02"><b>Lab-02</b></h2>
<p>In this lab, we'll create leaf both: white and colored. Then we'll create a star of 5 leaves and try to display it.</p>

<h3 id="lab02-01"><b>Task-01:</b></h3>
<p>Let's start by creating a white leaf. The main function is almost same as before although there're some major lines written before calling the main function:</p>


<pre>
    <code>
glScalef(0.8,0.8,1);
glTranslatef(0,-1.0,0);
glutDisplayFunc(display);
    </code>
</pre>


<p></p>
<p><code>glScalef()</code> scales the whole object declared inside the display function. <code>glTranslatef()</code> will translate the whole object as specified either. But here, first <code>glTranslatef()</code> will do its job, then <code>glScalef()</code> will do its part. The reason is that in OpenGL the transformations, which are done on the object, are declared before the display function and they are executed in the reverse order. Now, let's talk about how to create the leaf. Here, in this example, we've created the leaf by the combination of a triangle, a quad and two polygons. Let's see the display function:</p>

<pre>
    <code>
void display()
{
    triangle();
    quad();
    polygon1();
    polygon2();
    glFlush();
}
    </code>
</pre>

<p></p>
<p>Each of these functions have been declared by defining the structure of the shape. For example, let's look at the polygon1's vertexes:</p>

<pre>
    <code>
void polygon1(){
    glBegin(GL_POLYGON);
        glVertex2f(0.0, 0.91);
        glVertex2f(1.07, 1.1);
        glVertex2f(0.37, 1.33);
        glVertex2f(-0.37, 1.33);
        glVertex2f(-1.07, 1.1);
    glEnd();
}
    </code>
</pre>

<p></p>
<p>As we didn't set any color the leaf is white. The picture of the white leaf, colored leaf and star of leaves has been provided inside the Lab-02 folder for understanding and practising purposes.</p>


<h3 id="lab02-02"><b>Task-02:</b></h3>
<p>Now that we've created a white leaf, it's time for creating a colored leaf. Color leaf making is easy. Everything will remain same as before, the only difference is that we need to add color. For example, let's consider the polygon1:</p>


<pre>
    <code>
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
    </code>
</pre>


<p></p>
<p>That's how, you can create a colored leaf. There's only one thing you should bear in mind. If you use multiple colors in a polygon-type shape, all the colors of the edges will move towards the color of that edge with which you started to draw the polygon.</p>


<h3 id="lab02-03"><b>Task-03:</b></h3>
<p>So, we've created a white leaf, a colored leaf. It's time for making a star. All the codes are almost same, but notice that <code>glScalef()</code> and <code>glTranslatef()</code> functions are missing from the main function. Don't worry. They'll eventually show up. Also, notice that, the leaf has been created inside a <code>leaf()</code> function and it has been called from the <code>display()</code> function. And inside display function, you'll find:</p>


<pre>
    <code>
void display(){
    for(int i=0; i<=360; i+=72){
        glPushMatrix();
        glRotatef(i,0,0,1);
        glScalef(0.152,0.4,1);
        leaf();
        glPopMatrix();
    }

    glFlush();
}
    </code>
</pre>


<p></p>
<p>Here, first we created the leaf, adjusted its position by scaling and rotating. And then we used <code>glPushMatrix()</code> and <code>glPopMatrix()</code> each time while creating a new leaf. The main idea is: when you use <code>glTranslate()</code> or <code>glRotate()</code> you affect the modelview matrix. This means that when you apply several transformations (translations &amp; rotations) this matrix changes too. So, the plan is to save the old matrix into the stack, draw the object and then pop the old matrix. Notice that, we haven't used <code>glTranslatef()</code> function and the reason is that the object was created in that manner. But you can obviously translate the object if needed while using <code>glPushMatrix()</code> and <code>glPopMatrix()</code> functions.</p>
