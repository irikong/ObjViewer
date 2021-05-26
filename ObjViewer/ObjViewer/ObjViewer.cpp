#include <iostream>
#include <gl/glut.h>
#include "Mesh.h"

int cnt = 0;

const int winW = 500, winH = 500;

Mesh mesh;
void Display() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	//mesh.Draw();

	glFlush();
}

void myTimer(int value) {
	cnt = (cnt + 1) % 10;

	glutTimerFunc(1000, myTimer, 1);
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(winW, winH);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Init");

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	//glutDisplayFunc(myDisplay);
	glutTimerFunc(1000, myTimer, 1);
	mesh.Read("among us.obj");
	glutDisplayFunc(Display);
	glutMainLoop();

	return 0;
}