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
        <li><b><a href="#lab02-03">Task-03:</a></b> Create the same leaf for 5 times to make a Star</li>
    </ul>
</ul>

<ul>
    <li><b><a href="#lab03">Lab-03:</a></b></li>
    <ul>
        <li><b><a href="#lab03-01">Task-01:</a></b> Rotate the star of the last lab continuously</li>
    </ul>
</ul>

<ul>
    <li><b><a href="#lab04">Lab-04:</a></b></li>
    <ul>
        <li><b><a href="#lab04-01">Task-01:</a></b> Show individual shapes of a leaf and Rotate, Scale or Translate them via keyboard</li>
        <li><b><a href="#lab04-02">Task-02:</a></b> Rotate an object with respect to a line via keyboard</li>
    </ul>
</ul>

<ul>
    <li><b><a href="#lab05">Lab-05:</a></b></li>
    <ul>
        <li><b><a href="#lab05-01">Task-01:</a></b> Create a 3D cube manually, set up the <code>gluLookAt()</code> and <code>gluPerspective()</code> functions and modify each value of these functions via keyboard</li>
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




<h2 id="lab03"><b>Lab-03</b></h2>
<p>In this lab, we'll rotate the star which was created in last lab.</p>

<h3 id="lab03-01"><b>Task-01:</b></h3>
<p>To achieve our goal, we will call <code>glutDisplayFunc(rotated)</code> instead of calling <code>glutDisplayFunc(display)</code>. <code>rotated()</code> function will rotate the star. Let's see:</p>


<pre>
    <code>
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
    </code>
</pre>


<p></p>
<p>So, here we're creating frames and rotating it by 0.1 degree each time with basic logic and <code>glRotatef()</code> function. <code>glPushMatrix()</code> and <code>glPopMatrix()</code> have been used here, we already know the reason behind this.</p>

<p><code>glClear(GL_COLOR_BUFFER_BIT)</code> has been used to clear the window, otherwise the drawing of previous frame will be overlapped by the new ones. Also, notice that we've used <code>GLUT_DOUBLE</code> for smooth transition inside main function. That's why <code>glutSwapBuffers()</code> function has been used to swap the buffers whenever a frame making is complete.</p>


<h2 id="lab04"><b>Lab-04</b></h2>
<p>In this lab, we'll try to understand and implement different operations using keyboard buttons.</p>

<h3 id="lab04-01"><b>Task-01:</b></h3>
<p>First of all let's create a leaf. The leaf is created in the same way as before. Then to interact by keyboard, keyboard function has been called inside the main function: <code>glutKeyboardFunc(Keyboard)</code>. The keyboard function looks like this:</p>


<pre>
    <code>
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
    </code>
</pre>


<p></p>
<p><code>Keyboard()</code> function has three parameters built in. x and y are reserved for spacial purposes and c is the charecter that has been pressed via keyboard. Now, the case numbers denote the ASCII value of the keys. As usual, we're clearing the window whenever the buton is pressed and then we're applying translation, scaling or rotation on the object. Finally, we're displaying the updated object with the help of <code>glutPostRedisplay()</code> function. Notice that, for some keys the <code>Keyboard()</code> function calls <code>Keyboard1()</code>, <code>Keyboard2()</code>, <code>Keyboard3()</code>, <code>Keyboard4()</code> functions. The work of these functions are to handle the 4 shapes of the object individually. I suppose, no more description is needed on this topic. But before moving towards the next task, please be sure to have a detailed and clear idea about the keyboard handling.</p>


<h3 id="lab04-02"><b>Task-02:</b></h3>
<p>It's an interesting problem. So, first we've created an object. Now, we need to reflect the object with respect to a line. Suppose that, the line creates 45 degree angle with the X-axis and goes through (0,0.2) point. The reflection can be done in this manner: translate by (0,-0.2), rotate 45 degree clockwise, reflect with respect to X-axis which is basically scaling, rotate 45 degree anti-clockwise, translate by (0,0.2). Hence, it'll look like:</p>


<pre>
    <code>
void Keyboard(unsigned char c, int x, int y)
{
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
    </code>
</pre>


<p></p>
<p>Notice that here we've done the exact same thing as described but in reverse order. I've already described the cause of that. We've also used 'A' key to reflect with respect to the line. And that's the end of this lab.</p>


<h2 id="lab05"><b>Lab-05</b></h2>
<p>Finally, we've moved towards the last lab. In this lab, we'll create a 3D cube manually and will change differenet parameters with the help of keyboard.</p>

<h3 id="lab05-01"><b>Task-01:</b></h3>
<p>First things first. We'll need to create the 3D cube manually. To do so, we'll just consider that cube is nothing but a collection of six polygons. So, we'll create six polygons one by one and our 3D cube is ready. Pretty easy, right? I'm not citing that code here (as it's huge!). The next thing is to display the cube. Here is the display function:</p>


<pre>
    <code>
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
    </code>
</pre>


<p></p>
<p>So, as usual we're clearing the buffer, setting the color, loading identity matrix. Now, we'll set up the camera with the help of <code>gluLookAt()</code> function. It has 9 parameters. The first 3 parameters are X, Y, Z co-ordinates of camera position, next 3 denotes object center and the final 3 parameters denotes the direction of up vector. We already know the work of <code>glMatrixMode()</code> function. Now, we need to apply <code>gluPerspective()</code> function to set up the field volume, aspect ratio, near point and far point to display the cube. There's also a scaling factor available either. As for the keyboard interaction, I'm leaving that matter to you. All you need to do is to modify the values of the parameters of <code>gluLookAt()</code> and <code>gluPerspective()</code> functions via keyboard. However, in my code, I've implemented the parameter-modification via keyboard with the help of key buffers. If you wish, you can go through my code to understand how it works.</p>


<h2><b>Conclusion</b></h2>
<p>So, that's it. If you've read the whole article and solved all the problems, then congratulations. Now, you know how to create 2D and 3D objects, transform them (translate, rotate, scale), modify parameters using keyboards, modify positions and parameters of camera and object in OpenGL.</p>
