/*Create a 10 x 10 x 10 stack of cubes anywhere in a 500x500 window.The gap between cubes should be equal to
two cubes.Each cube should be of a random color. */

/*Developer: Muneeb Muzammal Email: muneebmuzammal92@gmail.com */

#include <windows.h>  
#include <GL/glut.h>  
#include<math.h>

float move_x = 0.5f;
float move_y = 0.5f;
float move_z = 0.5f;

void makecube()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glBegin(GL_QUADS);
	glVertex3f(move_x, move_y, -move_z);
	glVertex3f(-move_x, move_y, -move_z);
	glVertex3f(-move_x, move_y, move_z);
	glVertex3f(move_x, move_y, move_z);

	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(-move_x, -move_y, -move_z);
	glVertex3f(move_x, -move_y, -move_z);

	glColor3f(1.0f, 0.0f, 0.0f);     // Red
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(-move_x, move_y, move_z);
	glVertex3f(-move_x, -move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);

	glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
	glVertex3f(move_x, -move_y, -move_z);
	glVertex3f(-move_x, -move_y, -move_z);
	glVertex3f(-move_x, move_y, -move_z);
	glVertex3f(move_x, move_y, -move_z);

	glColor3f(0.0f, 0.0f, 1.0f);     // Blue
	glVertex3f(-move_x, move_y, move_z);
	glVertex3f(-move_x, move_y, -move_z);
	glVertex3f(-move_x, -move_y, -move_z);
	glVertex3f(-move_x, -move_y, move_z);

	glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
	glVertex3f(move_x, move_y, -move_z);
	glVertex3f(move_x, move_y, move_z);
	glVertex3f(move_x, -move_y, move_z);
	glVertex3f(move_x, -move_y, -move_z);

	glEnd();

	glFlush();

}

void display() {


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5, 5, -5, 5);

	glPushMatrix();
	glTranslatef(0, 4.5, 0);
	glColor3f(1, 1, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 3.5, 0);
	glColor3f(0, 1, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.5, 0);
	glColor3f(1, 0, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glColor3f(1, 1, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glColor3f(1, 0, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	glColor3f(0, 1, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.5, 0);
	glColor3f(0, 0, 1);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.5, 0);
	glColor3f(1.5, 0, 1.5);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.5, 0);
	glColor3f(1.89, 1.89, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4.5, 0);
	glColor3f(1.89, 1.89, 0);
	glutSolidCube(0.5);
	//makecube();
	glPopMatrix();



	//glFlush();
	glutSwapBuffers();
}

void timer(int x)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPopMatrix();
	glRotatef(10, 1.0, 1.0, 0.0);

	glutPostRedisplay();
	glutTimerFunc(1000 / 25., timer, 0);
}




int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutTimerFunc(1000 / 25., timer, 0);
	glutReshapeWindow(500, 500);
	glutMainLoop();

}