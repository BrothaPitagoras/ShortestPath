#include <model/Model.h>

Model::Model(const Mesh& mesh)
{
	this->meshes_.push_back(mesh);
}

Model::Model(Mesh mesh)
{
	this->meshes_.push_back(mesh);
}

Model::Model(std::vector<Vertex> vertices, std::vector<glm::uvec2> edges)
{
	this->meshes_.emplace_back(vertices, edges);
}

Model::Model(std::vector<Mesh> meshes) : meshes_{meshes} {}

void Model::Draw(Shader& shader)
{
	for (Mesh& mesh : meshes_)
	{
		mesh.Draw(shader);
	}
}

void Model::Draw(Shader& shader, glm::vec3 color)
{
	shader.setVec3("color", color);
	for (Mesh& mesh : meshes_)
	{
		mesh.Draw(shader);
	}
}