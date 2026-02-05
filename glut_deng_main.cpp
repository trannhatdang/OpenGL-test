#include <windows.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

const float DEG2RAD = 3.14159f / 180.0f;

int screenWidth = 500, screenHeight = 500;
float angle = 0.0f;

float tetra_vertices[][3] = {
	{0.0, 0.0, 1.0},
	{0.0, 0.942809, -0.333},
	{-0.816497, -0.471405, -0.333},
	{0.816497, 0.471405, -0.333}

};

void myInit()
{
//	float	fHalfSize = 5;

	glClearColor(0, 0, 0, 1.0f);

//	glFrontFace(GL_CCW);
//	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(
			-1.0,
			1.0,
			-1.0,
			1.0,
			2.0,
			10.0
	);

	glMatrixMode(GL_MODELVIEW);
	glClearColor(0.1f, 0.7f, 0.7f, 1.0f);

	
//	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}

void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(
			1.5,
			1.5,
			1.5,
			0.0,
			0.0,
			0.0,
			0.0,
			1.0,
			0.0
	);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	////////////////////////////////////////////////////
	///
	
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f, 0, 0);
		glVertex3fv(tetra_vertices[0]);
		glVertex3fv(tetra_vertices[2]);
		glVertex3fv(tetra_vertices[1]);

		glColor3f(0, 1.0f, 0);
		glVertex3fv(tetra_vertices[0]);
		glVertex3fv(tetra_vertices[1]);
		glVertex3fv(tetra_vertices[3]);

		glColor3f(0, 0, 1.0f);
		glVertex3fv(tetra_vertices[0]);
		glVertex3fv(tetra_vertices[3]);
		glVertex3fv(tetra_vertices[2]);

		glColor3f(1.0f, 0, 0);
		glVertex3fv(tetra_vertices[3]);
		glVertex3fv(tetra_vertices[1]);
		glVertex3fv(tetra_vertices[2]);

	glEnd();

	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	int size = std::min(width, height);
	glViewport(0, 0, size, size);
}

int main(int argc, char** argv)
{
	angle = 0.0f;
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
	glutReshapeFunc(reshape);

	glutMainLoop();
}
