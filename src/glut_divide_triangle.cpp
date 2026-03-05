#include <windows.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

int screenWidth = 500, screenHeight = 500;

GLfloat v[3][2] = {
	{-1.0, -0.58},
	{1.0, -0.58},
	{0.0, 1.15}
};

int n;

typedef GLfloat point2[2];

void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m)
{
	point2 v0, v1, v2;
	int j;

	if(m > 0)
	{
		for(j = 0; j < 2; ++j) v0[j] = (a[j] + b[j])/2;
		for(j = 0; j < 2; ++j) v1[j] = (a[j] + c[j])/2;
		for(j = 0; j < 2; ++j) v2[j] = (b[j] + c[j])/2;
		divide_triangle(a, v0, v1, m-1);
		divide_triangle(c, v1, v2, m-1);
		divide_triangle(b, v2, v0, m-1);
	}
	else
	{
		triangle(a, b, c);
	}

}

void myInit()
{
}

void myDisplay()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0, 0, 0);

	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		//triangle(v[0], v[1], v[2]);
		divide_triangle(v[0], v[1], v[2], n);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	n = 4;
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//set the display mode

	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(200, 100); // set window position on screen

	glutCreateWindow("Simple"); // open the screen window

	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();
}
