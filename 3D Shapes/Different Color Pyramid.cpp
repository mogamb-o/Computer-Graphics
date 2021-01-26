//Developer: Muneeb Muzammal Email: muneebmuzammal92@gmail.com//
#include<GL/glut.h>

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
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_LINE_STIPPLE);

	glLineWidth(3.0);
	glLineStipple(1, 0xF0F0);

	// side - base
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// side - front
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.0, 0.5, 0.0);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();


	// side - back
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(0.0, 0.5, 0.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();

	// side - right
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.0, 0.5, 0.0);
	glColor3f(0.0, 1.0, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glEnd();

	// side - left
	glBegin(GL_TRIANGLE_STRIP);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.0, 0.5, 0.0);
	glColor3f(0.0, 1.0, 0.8);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Pyramid");
	glutDisplayFunc(display);
	glutSpecialFunc(keyboard);
	glutMainLoop();
}