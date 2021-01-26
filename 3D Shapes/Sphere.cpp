/* Developer: Muneeb Muzammal Email: muneebmuzammal92@gmail.com*/

#define _USE_MATH_DEFINES M_PI
#include<GL/glut.h>
#include<cmath>

float rotate_y = 0;
float rotate_x = 0;

void keyboard(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:	rotate_x += 1; break;
	case GLUT_KEY_LEFT:		rotate_x -= 1; break;
	case GLUT_KEY_UP:		rotate_y += 1; break;
	case GLUT_KEY_DOWN:		rotate_y -= 1; break;
	}

	glutPostRedisplay();
}

void display() {
	glRotatef(rotate_y, 1.0, 0.0, 0.0);
	glRotatef(rotate_x, 0.0, 1.0, 0.0);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glClearDepth(1.0f);

	int i;
	int points = 100;
	float x = 0.0, y = 0.0;

	GLfloat radius = 0.8f, z = -0.8f;
	// GLfloat radius = 0.0f, z = 0.0f;
	GLfloat twicePi = 2.0f * M_PI;


	for (radius; radius > 0.0; radius -= 0.05) {
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= points; i++) {
			glVertex3f(
				x + (radius * sin(i * twicePi / points)),
				y + (radius * cos(i * twicePi / points)),
				z + (radius * cos(i * twicePi / points))
			);
		}
		glEnd();
		z += 0.05;
	}

	radius = 0;
	z = 0;

	for (radius; radius <= 0.8; radius += 0.05) {
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= points; i++) {
			glVertex3f(
				x + (radius * sin(i * twicePi / points)),
				y + (radius * cos(i * twicePi / points)),
				z + (radius * cos(i * twicePi / points))
			);
		}
		glEnd();
		z += 0.05;
	}

	glFlush();
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Sphere (Mesh)");
	glutDisplayFunc(display);
	glutMainLoop();
}