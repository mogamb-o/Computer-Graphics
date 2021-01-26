/* Developer: Muneeb Muzammal Email: muneebmuzammal92@gmail.com */

/*Create two similar objects of your choice that appear at a random position in a 500x500
window.Each object moves in a random direction and keeps on moving in that direction until it collides with the
window boundary, or another object.*/

#include <windows.h>  
#include <GL/glut.h>  


float x_position = -10.0f;
float y_position = 10.0f;


void display() {



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();



	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0);
	glVertex2f(x_position, 1.0);
	glVertex2f(x_position, -1.0);
	glVertex2f(x_position + 2.0, -1.0);
	glVertex2f(x_position + 2.0, 1.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(-5.5, y_position);
	glVertex2f(-3.5, y_position);
	glVertex2f(-3.5, y_position - 2.0);
	glVertex2f(-5.5, y_position - 2.0);
	glEnd();

	glutSwapBuffers();
	glFlush();


}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
}
void timer(int x)
{

	glutPostRedisplay();
	glutTimerFunc(1000 / 25., timer, 0);
	if (x_position < 8)
	{
		x_position += 0.15;
	}
	if (y_position > -8)
	{
		y_position -= 0.15;
	}

}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("OpenGL Setup Test");
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(200, 100);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutReshapeWindow(500, 500);
	glutTimerFunc(1000 / 25., timer, 0);
	glutMainLoop();

}