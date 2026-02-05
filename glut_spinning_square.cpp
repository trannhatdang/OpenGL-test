#include <windows.h>
#include <math.h>
#include <GL/freeglut.h>

const float DEG2RAD = 3.14159f / 180.0f;

int screenWidth = 500, screenHeight = 500;
float angle = 0.0f;



void myInit()
{
//float	fHalfSize = 5;

	glClearColor(0, 0, 0, 1.0f);

//	glFrontFace(GL_CCW);
//	glEnable(GL_DEPTH_TEST);

//	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glOrtho(-fHalfSize, fHalfSize, -fHalfSize, fHalfSize, -1000, 1000);
}

void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();


	////////////////////////////////////////////////////
	///
	
	float cx, cy;
	cx = 0.5*cos(DEG2RAD*angle); cy = 0.5*sin(DEG2RAD*angle);
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0, 0);
		glVertex2f(-0.5 + cx, -0.5 + cy);
		glVertex2f(-0.5 + cx, 0.5 + cy);
		glVertex2f(0.5 + cx, 0.5 + cy);
		glVertex2f(0.5 + cx, -0.5 + cy);

	glEnd();

	glFlush();
	glutSwapBuffers();
}

void processTimer(int val)
{
	angle += (float)val;
	if (angle > 360)
	{
		angle = angle - 360.0f;
	}

	glutTimerFunc(10, processTimer, 10);
	glutPostRedisplay();

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
	glutTimerFunc(10, processTimer, 1);

	glutMainLoop();
}



