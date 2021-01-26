/*Ball Control (Game Physics)
Developer: Muneeb Muzammal Email: muneebmuzammal92@gmail.com

Consider a window in which an object is placed at the lower left corner of the screen.The object is initially
stationary.Use your keyboard RIGHT and LEFT button to control the object movement.With the right key, the
object should move right and keep on moving right till it reaches the right edge of the window with a minor
bounce.Likewise, with the left key, the object should move left and keep on moving left till it reaches the left edge
of the window with a minor bounce.Anytime during this movement, if the UP key is pressed, the object should
jump up with a certain force and bounce back to position.Note that if the UP and RIGHT, or UP and LEFT keys are
pressed in continuation, the ball should follow movement along both the directions.

*/
#include <windows.h>  
#include <GL/glut.h>  

float move_x = 1.0f;
float move_y = 0.49f;

int flag = 1;
void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-1.0, -0.5, 0);
	glVertex3f(1.0, -0.5, 0);
	glVertex3f(1.0, -1, 0);
	glVertex3f(-1.0, -1, 0);
	glEnd();


	glPointSize(9.0);
	glBegin(GL_POINTS);
	glPointSize(9.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(-move_x, -move_y, 0);
	glEnd();

	glFlush();


}

void timer(int x)
{
	if (x == 1)
	{
		move_x = move_x - 0.01;
		glutTimerFunc(1000 / 25., timer, 1);
	}
	if (x == 2)
	{
		move_x = move_x + 0.01;
		glutTimerFunc(1000 / 25., timer, 2);
	}
	if (x == 3)
	{
		move_y = move_y - 0.01;
		if (flag)
		{
			if (move_y < 0.1)
			{
				glutTimerFunc(1000 / 25., timer, 4);
			}

		}
		glutTimerFunc(1000 / 25., timer, 3);
	}
	if (x == 4)
	{
		move_y = move_y + 0.01;
		if (move_y > 0.49)
		{
			move_y = 0.49;
		}
		glutTimerFunc(1000 / 25., timer, 4);
	}
	glutPostRedisplay();

}

void keyboard(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_RIGHT:
		timer(1);

		break;
	case GLUT_KEY_LEFT:
		timer(2);

		break;
	case GLUT_KEY_UP:
		timer(3);

		break;
	case GLUT_KEY_DOWN:
		//move_y = move_y + 0.1; 
		break;
	}
	glutPostRedisplay();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Game Physics");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutSpecialFunc(keyboard);
	glutTimerFunc(1000 / 25., timer, 0);
	glutMainLoop();

}