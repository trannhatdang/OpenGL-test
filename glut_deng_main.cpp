#include <windows.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

int screenWidth = 500, screenHeight = 500;

typedef struct{
	float x;
	float y;
} Vector2;

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
		for(j = 0; j < 2; ++j) v0[j] = (a[j] + c[j])/2;
		for(j = 0; j < 2; ++j) v0[j] = (b[j] + c[j])/2;
		divide_triangle(a, v0, v1, m-1);
		divide_triangle(a, v1, v2, m-1);
		divide_triangle(a, v2, v0, m-1);
	}
	else
	{
		triangle(a, b, c);
	}

}

void myInit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(0, 0, 0, 1.0f);
	glColor3f(0.0, 0.0, 0.0);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		divide_triangle(v[0], v[1], v[2], n);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	n = 4;
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//set the display mode
				      //
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(200, 100); // set window position on screen
						  //
	glutCreateWindow("Simple"); // open the screen window
				      //
	myInit();
	glutDisplayFunc(myDisplay);

	glutMainLoop();
}
