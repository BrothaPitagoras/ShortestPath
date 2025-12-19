#pragma once

#include <includes.h>
#include <glm/glm.hpp>
#include <render/Shader.h>
#include <model/Vertex.h>

class Mesh
{
public:

	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	unsigned int vao_;

	Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);

	void Draw(Shader& shader);

private:
	unsigned int vbo_, ebo_;
	void setupMesh();
};
