#include <iostream>
#include <gl/glut.h>

int cnt = 0;

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	switch (cnt % 3) {
	case 0:
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case 1:
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case 2:
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	}

	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5f, -0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(-0.5f, 0.5f);
	glEnd();

	//glFlush();
	glFinish();
}

void myTimer(int value) {
	cnt = (cnt + 1) % 10;

	glutTimerFunc(1000, myTimer, 1);
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Init");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glutDisplayFunc(display);
	glutTimerFunc(1000, myTimer, 1);
	glutMainLoop();

	return 0;
}