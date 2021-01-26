/*Developer: Muneeb Muzammal
Email: muneebmuzammal92@gmail.com
Multiple cubes within cube
*/

#include<GL/glut.h>
#include <windows.h>  
#include<iostream>

void cubeInCubes() {

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);				// Show cube lines not filled with color


	for (float i = -0.5; i < 0.4; i = i + 0.1)				//Making cubes within Cube 
	{
		for (float j = -0.5; j < 0.4; j = j + 0.1)			//nested loops
		{
			for (float k = -0.5; k < 0.4; k = k + 0.1)
			{
				glBegin(GL_QUADS);
				glColor3f(0, 0, 1);
				glVertex3f(i, j, k);
				glColor3f(1, 0, 0);
				glVertex3f(i, j + 0.1, k);
				glColor3f(0, 1, 0);
				glVertex3f(i + 0.1, j + 0.1, k);
				glColor3f(0, 1, 1);
				glVertex3f(i + 0.1, j, k);


				glColor3f(1, 0, 1);
				glVertex3f(i, j, -k);
				glColor3f(0, 1, 1);
				glVertex3f(i, j + 0.1, -k);
				glColor3f(1, 1, 1);
				glVertex3f(i + 0.1, j + 0.1, -k);
				glColor3f(0, 0, .1);
				glVertex3f(i + 0.1, j, -k);


				glColor3f(0.1, 0, 0);
				glVertex3f(i, j, k);
				glColor3f(0, 0.1, .1);
				glVertex3f(i, j, -k);
				glColor3f(0.1, 0, 0.1);
				glVertex3f(i, j + 0.1, -k);
				glColor3f(0.1, 0.1, 0.1);
				glVertex3f(i, j + 0.1, k);


				glColor3f(0, 0.1, 1);
				glVertex3f(i + 0.1, j + 0.1, k);
				glColor3f(0.1, 0, 0.1);
				glVertex3f(i + 0.1, j + 0.1, -k);
				glColor3f(0, 0, .2);
				glVertex3f(i + 0.1, j, -k);
				glColor3f(0, 0.4, .3);
				glVertex3f(i + 0.1, j, k);


				glColor3f(0.6, 0.2, 1);
				glVertex3f(i, j, k);
				glColor3f(0.3, 0.2, .1);
				glVertex3f(i, j, -k);
				glColor3f(0.5, 0.9, .3);
				glVertex3f(i + 0.1, j, -k);
				glColor3f(0.6, 0.6, .6);
				glVertex3f(i + 0.1, j, k);


				glColor3f(0.5, 0.5, 0.5);
				glVertex3f(i, j + 0.1, k);
				glColor3f(0.6, 0.6, .6);
				glVertex3f(i, j + 0.1, -k);
				glColor3f(0.8, 0.8, .8);
				glVertex3f(i + 0.1, j + 0.1, -k);
				glColor3f(0, 1, 1);
				glVertex3f(i + 0.1, j + 0.1, k);


				glEnd();


			}


		}


	}

	glBegin(GL_QUADS);
	glEnd();
	glFlush();
}



void timerFunc(int x)		//Timer function for transformations
{

	glRotatef(3, 1, 1, 1);
	//glTranslatef(0.0, 0.5, 0.0);
	//glScalef(0.9, 0.9, 0.9);
	glutPostRedisplay();
	glutTimerFunc(1000 / 20., timerFunc, 0);
}



int main(int argc, char** argv) {

	// Initialize GLUT
	glutInit(&argc, argv);
	glutCreateWindow("Multiple Cubes");	// Create the window with the title "Heat GL 3D"
	glutInitWindowSize(320, 320);	// Set the window size
	glutInitWindowPosition(50, 50);	// Set the window position
	glutDisplayFunc(cubeInCubes);	//Display Function
	glutTimerFunc(1000 / 20., timerFunc, 0);	//Timer Function for Transformation
	glutMainLoop();

}