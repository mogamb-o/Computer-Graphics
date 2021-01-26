/*Developer: Muneeb Muzammal 
Email: muneebmuzammal92@gmail.com
*/

#include <windows.h>  
#include <GL/glut.h>  

float move_x = 0.5f;
float move_y = 0.5f;
float move_z = 0.5f;
float move_z1 = 0.0f;

void display() {

	glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();
	glRotatef(0, 0, 0, 0);

	glBegin(GL_TRIANGLES);
	//front
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, 0.5f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	//front
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, 0.5f);

	glEnd();

	glPopMatrix();


	glPushMatrix();
	glRotatef(180, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	//front
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, 0.5f);

	glEnd();

	glPopMatrix();

	glPushMatrix();
	glRotatef(270, 0, 1, 0);

	glBegin(GL_TRIANGLES);
	//front
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, 0.0f, 0.5f);
	glVertex3f(-0.5f, 0.0f, 0.5f);

	glEnd();

	glPopMatrix();


	glFlush();


}

void timer(int x)
{
	glPopMatrix();
	glRotatef(5, 0.5, 0, 0);
	glutPostRedisplay();
	glutTimerFunc(1000 / 25., timer, 0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Pyramid with rotation");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutTimerFunc(1000 / 25., timer, 0);
	glutMainLoop();

}