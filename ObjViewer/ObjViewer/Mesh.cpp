#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Mesh.h"
#include <iostream>
#include <gl/glut.h>

using namespace std;

void Mesh::ClearObj()
{
}

void Mesh::Read(const char* filename)
{
}

void Mesh::Draw()
{
	glColor3d(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glEnd();
}
