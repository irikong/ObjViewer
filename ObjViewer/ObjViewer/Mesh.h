#include<iostream>
#include<GL/glut.h>
#include<string>
#include<vector>

using namespace std;

struct Vertex {
	float x, y, z;
};
struct Texture {
	float u, v;
};
struct Normal {
	float x, y, z;
};

class Mesh {
private:
	vector<Vertex> vertices;
	vector<Texture> textures;
	vector<Normal> normals;
	vector<vector<int>> vertexIndices;
	vector<vector<int>> textureIndices;
	vector<vector<int>> normalIndices;

public:
	Mesh() {}
	~Mesh() { ClearObj(); }
	void ClearObj();
	void Read(const char* filename);
	void Draw();
};