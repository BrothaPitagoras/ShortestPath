#pragma once

#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 Position;
	// Vertex can have normals, texture coordinates, tangents, bitangents, bone IDs, weights, etc.
	// but here we only want position for simplicity.

	Vertex(glm::vec3 position) : Position(position) {}
	Vertex(float x, float y, float z) : Position(glm::vec3(x,y,z)) {}
};
