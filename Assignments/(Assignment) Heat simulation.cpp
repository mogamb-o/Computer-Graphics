/*
Developer: Muneeb Muzammal Email: muneebmuzammal92@gmail.com
Assignment: HEAT SIMULATION
*/

#include <windows.h>  
#include <GL/glut.h>  
#include<iostream>
#include<math.h>

float red = 0, blue = 1, green = 0;
int alpha = 1;
int a, b, c = 0;
float energy = 0.5;
float u[10][10][10];
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	bool f = false;

	for (float i = -0.5; i < 0.4; i = i + 0.1)
	{
		for (float y = -0.5; y < 0.4; y = y + 0.1)
		{
			for (float z = -0.5; z < 0.4; z = z + 0.1)
			{
				if (f)
				{
					glColor3f(0, 0, 0);
					f = !f;
				}
				else
				{
					glColor3f(red, green, blue);
					f = !f;
				}
				glBegin(GL_QUADS);
				//glColor3f(red, green, blue);
				glVertex3f(i, y, z); //
				glVertex3f(i, y + 0.1, z); //+++
				glVertex3f(i + 0.1, y + 0.1, z); //+-+
				glVertex3f(i + 0.1, y, z); //--+

				glVertex3f(i, y, -z); //-++
				glVertex3f(i, y + 0.1, -z); //+++
				glVertex3f(i + 0.1, y + 0.1, -z); //+-+
				glVertex3f(i + 0.1, y, -z); //--+

				glVertex3f(i, y, z); //
				glVertex3f(i, y, -z); //-++
				glVertex3f(i, y + 0.1, -z); //
				glVertex3f(i, y + 0.1, z); //+++

				glVertex3f(i + 0.1, y + 0.1, z); //+-+
				glVertex3f(i + 0.1, y + 0.1, -z); //+-+
				glVertex3f(i + 0.1, y, -z); //--+
				glVertex3f(i + 0.1, y, z); //--+


				glVertex3f(i, y, z); //
				glVertex3f(i, y, -z); //
				glVertex3f(i + 0.1, y, -z); //+-+
				glVertex3f(i + 0.1, y, z); //+-+

				glVertex3f(i, y + 0.1, z); //+++
				glVertex3f(i, y + 0.1, -z); //+++
				glVertex3f(i + 0.1, y + 0.1, -z); //+-+
				glVertex3f(i + 0.1, y + 0.1, z); //+-+



				glEnd();
				// u[a][b][c] = energy;
				c++;
			}
			c = 0;
			b++;
		}
		c = 0;
		b = 0;
		a++;
	}

	printf("Decimals: %d %ld\n", red, blue);
	glFlush();


}
void update_color(int x)
{
	glRotatef(2, 1.0, 1, 0.0);
	red += 0.01;
	blue -= 0.01;

	glutPostRedisplay();
	glutTimerFunc(1000 / 25., update_color, 0);
}



void heat()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (i = 0, j = 0, k = 0)
				{
					u[i][j][k] = u[i][j][k] + alpha * (u[i + 2][j][k] - 2 * u[i + 1][j][k] + u[i][j][k] + u[i][j + 2][k] - 2 * u[i][j][k] + u[i][j][k] + u[i][j][k + 2] - 2 * u[i][j][k + 1] + u[i][j][k]);

				}
				if (i = 1, j = 0, k = 0)
				{
					u[i][j][k] = u[i][j][k] + alpha * (u[i][j][k] - 2 * u[i - 1][j][k] + u[i - 2][j][k] + u[i][j + 2][k] - 2 * u[i][j + 1][k] + u[i][j][k] + u[i][j][k + 2] - 2 * u[i][j][k + 1] + u[i][j][k]);

				}
				if (i = 0, j = 1, k = 0)
				{
					u[i][j][k] = u[i][j][k] + alpha * (u[i + 2][j][k] - 2 * u[i + 1][j][k] + u[i][j][k] + u[i][j][k] - 2 * u[i][j - 1][k] + u[i][j - 2][k] + u[i][j][k + 2] - 2 * u[i][j][k + 1] + u[i][j][k]);

				}
				if (i = 0, j = 0, k = 1)
				{
					u[i][j][k] = u[i][j][k] + alpha * (u[i + 2][j][k] - 2 * u[i + 1][j][k] + u[i][j][k] + u[i][j + 2][k] - 2 * u[i][j + 1][k] + u[i][j][k] + u[i][j][k] - 2 * u[i][j][k - 1] + u[i][j][k - 2]);

				}
				if (i = 1, j = 1, k = 0)
				{
					u[i][j][k] = u[i][j][k] + alpha * (u[i][j][k] - 2 * u[i - 1][j][k] + u[i - 2][j][k] + u[i][j][k] - 2 * u[i][j - 1][k] + u[i][j - 2][k] + u[i][j][k + 1] - 2 * u[i][j][k + 1] + u[i][j][k]);

				}
				if (i = 1, j = 1, k = 1)
				{
					u[i][j][k] = u[i][j][k] + alpha * (u[i][j][k] - 2 * u[i - 1][j][k] + u[i - 2][j][k] + u[i][j][k] - 2 * u[i][j - 1][k] + u[i][j - 2][k] + u[i][j][k] - 2 * u[i][j][k - 1] + u[i][j][k - 2]);

				}
			}

		}


	}

}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Heat Simulation");
	glutInitWindowSize(320, 320);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutTimerFunc(1000 / 25., update_color, 0);
	glutMainLoop();

}