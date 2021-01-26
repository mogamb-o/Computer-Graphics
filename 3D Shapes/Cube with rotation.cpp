/* Cube with rotation
Developer: Muneeb Muzammal Email:muneebmuzammal92@gmail.com */

#include <windows.h>  
#include <GL/glut.h>  

float move_x = 0.5f;
float move_y = 0.5f;
float move_z = 0.5f;

void display() {

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();
	glRotatef(0, 0, 0, 0);

	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glEnd();

	glPopMatrix();



	glPushMatrix();
	glRotatef(90, 0, 1, 0);

	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 0, 1, 0);

	glBegin(GL_QUADS);
	glColor3f(0, 0, 1);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);

	glBegin(GL_QUADS);
	glColor3f(0, 1, 1);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(270, 1, 0, 0);

	glBegin(GL_QUADS);
	glColor3f(1, 1, 1);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glEnd();

	glPopMatrix();


	glPushMatrix();
	glRotatef(-90, 1, 0, 0);

	glBegin(GL_QUADS);
	glColor3f(1.0, 0.5, 0.0);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glEnd();

	glPopMatrix();

	glFlush();


}

void timer(int x)
{
	glPopMatrix();
	glRotatef(5, 0.1, 0.1, 0.1);
	glutPostRedisplay();
	glutTimerFunc(1000 / 25., timer, 0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Cube with rotation");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutTimerFunc(1000 / 25., timer, 0);
	glutMainLoop();

}