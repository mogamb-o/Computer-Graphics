/*Developer: MUneeb Muzammal Email: muneebmuzammal92@gmail.com */

#define _USE_MATH_DEFINES M_PI
#include <cmath>
#include<GL/glut.h>


void display() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

	GLfloat x = 0.0f, 
			y = 0.0f,

			radius = 0.8f,
			angle = 0.0f,
			angle_step_size = 0.1f;


	glBegin(GL_QUAD_STRIP);
		while (angle < 2* M_PI) {
			x = radius * cos(angle);
			y = radius * sin(angle);
			angle += angle_step_size;
			glVertex2f(x, y);
		}
		// glVertex2f(radius, y);
	glEnd();

	glFlush();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Circle");
	glutDisplayFunc(display);
	glutMainLoop();
}