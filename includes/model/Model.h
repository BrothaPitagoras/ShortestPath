#pragma once

#include <includes.h>
#include <model/Mesh.h>
#include <render/Shader.h>

class Model
{
private:
	std::vector<Mesh> meshes_;
public:

	Model(const Mesh& mesh);
	Model(Mesh mesh);
	Model(std::vector<Vertex> vertices, std::vector<glm::uvec2> edges);
	Model(std::vector<Mesh>& meshes);
	Model(std::vector<Mesh> meshes);
	void Draw(Shader& shader);
	void Draw(Shader& shader, glm::vec3 color);

	const std::vector<Mesh>& GetMeshes() const noexcept { return meshes_; }
	std::vector<Mesh>& GetMeshes() noexcept { return meshes_; }
};