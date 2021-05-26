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
	char line[256];
	char symbol[5];
	Vertex v;
	Texture vt;
	Normal vn;

	vector<int> vertexIndex, textureIndex, normalIndex;
	int vIndex, vtIndex, vnIndex;

	FILE* fp = fopen(filename, "r");
	if (!fp) {
		cout << "Couldn't open the file!" << endl;
		exit(1);
	}

	while (fgets(line, 256, fp)) {
		sscanf_s(line, "%s", symbol, sizeof(symbol));

		if (!strcmp(symbol, "v")) {
			sscanf(line, "%*s %f %f %f", &v.x, &v.y, &v.z);
			vertices.push_back(v);
		}
		else if (!strcmp(symbol, "vt")) {
			sscanf(line, "%*s %f %f", &vt.u, &vt.v);
			textures.push_back(vt);
		}
		else if (!strcmp(symbol, "vn")) {
			sscanf(line, "%*s %f %f %f", &vn.x, &vn.y, &vn.z);
			normals.push_back(vn);
		}
		else if (!strcmp(symbol, "f")) {
			char* token = strtok(line, " "); // remove f

			while (token = strtok(NULL, " ")) {
				if (sscanf(token, "%d/%d/%d", &vIndex, &vtIndex, &vnIndex) == 3) {
					vertexIndex.push_back(vIndex);
					textureIndex.push_back(vtIndex);
					normalIndex.push_back(vnIndex);
				}
			}
			vertexIndices.push_back(vertexIndex);
			textureIndices.push_back(textureIndex);
			normalIndices.push_back(normalIndex);

			vertexIndex.clear();
			textureIndex.clear();
			normalIndex.clear();
		}
		else {
			continue;
		}
	}
}

void Mesh::Draw()
{
	glColor3d(0, 0, 0);
	glBegin(GL_TRIANGLES);
	glEnd();
}
