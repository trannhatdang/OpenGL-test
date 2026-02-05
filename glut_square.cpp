#include <windows.h>
#include <GL/freeglut.h>

int screenWidth = 500, screenHeight = 500;

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
	glBegin(GL_POLYGON);
		glColor3f(1.0f, 0, 0);
		glVertex2f(-0.5, -0.5);
		glVertex2f(-0.5, 0.5);
		glVertex2f(0.5, 0.5);
		glVertex2f(0.5, -0.5);

	glEnd();

	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, (char**)argv); //initialize the tool kit
	glutInitDisplayMode(GLUT_RGB);//set the display mode
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



