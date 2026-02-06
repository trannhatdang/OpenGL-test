#include <windows.h>
#include <GL/freeglut.h>
#include <bits/stdc++.h>

const float DEG2RAD = 3.14159f / 180.0f;

float colors[3][3] = {
	{1, 0, 0},
	{0, 1, 0},
	{0, 0, 1}
};

int screenWidth = 500, screenHeight = 500;
int angle = 0;

int pointsArr[36] = {};

void myInit()
{
	glClearColor(0, 0, 0, 1.0f);
}

void myDisplay()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	////////////////////////////////////////////////////
	///
	///
	
	glBegin(GL_POINTS);
		for(int i = 0; i < 3; ++i)
		{
			glVertex2f(0.8f * cos(DEG2RAD * pointsArr[(angle + i * 12) % 36]), 0.8f * sin(DEG2RAD * pointsArr[(angle + i * 12) % 36]));
		}
	glEnd();
	
	glBegin(GL_TRIANGLES);
		for(int i = 0; i < 3; ++i)
		{
			glColor3f(colors[i % 3][0], colors[i % 3][1], colors[i % 3][2]);
			glVertex2f(0.8f * cos(DEG2RAD * pointsArr[(angle + i * 12) % 36]),
				0.8f * sin(DEG2RAD * pointsArr[(angle + i * 12) % 36]));
			glVertex2f(0.8f * cos(DEG2RAD * pointsArr[(angle + i * 12 + 1) % 36]),
					0.8f * sin(DEG2RAD * pointsArr[(angle + i * 12 + 1) % 36]));
			glVertex2f(0, 0);
		}
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void processTimer(int val)
{
	angle = (angle - val);

	if(angle < 0)
	{
		angle = 36 + angle;
	}

	glutTimerFunc(100, processTimer, 1);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	for(int i = 0; i < 36; ++i)
	{
		pointsArr[i] = i * 10;
	}

	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);//set the display mode
				      //
	glutInitWindowSize(screenWidth, screenHeight); //set window size
	glutInitWindowPosition(200, 100); // set window position on screen
						  //
	glutCreateWindow("Simple"); // open the screen window
				      //
	myInit();
	glutTimerFunc(100, processTimer, 1);
	glutDisplayFunc(myDisplay);

	glutMainLoop();
}
