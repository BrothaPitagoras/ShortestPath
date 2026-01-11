#include <model/Matrix.h>
#include <model/Mesh.h>


Matrix::Matrix(const unsigned int rows, const unsigned int cols)
    : Model(std::vector<Mesh>{}), rows_{ rows }, cols_{ cols }
{
    generateMesh(rows, cols);
}


void Matrix::generateMesh(const unsigned int rows, const unsigned int cols)
{
	std::vector<Vertex> vertices{};
	std::vector<glm::uvec2> indices{};

	unsigned int row_draw_lines = rows + 1;
	unsigned int col_draw_lines = cols + 1;

	float step_x = 2.0f / static_cast<float> (cols);
	float step_y = 2.0f / static_cast<float> (rows);

	for (float i = 0; i < row_draw_lines; i++)
	{
		unsigned int indice_start = static_cast<unsigned int>(vertices.size());
		vertices.emplace_back((glm::vec3(0.0f, i * step_y, 0.0f) - glm::vec3(1.0f, 1.0f, 1.0f)) * MAX_MATRIX_BOUNDARY);
		vertices.emplace_back((glm::vec3(2.0f, i * step_y, 0.0f) - glm::vec3(1.0f, 1.0f, 1.0f)) * MAX_MATRIX_BOUNDARY);
	
		indices.emplace_back(indice_start, indice_start + 1);
	}

	for (float i = 0; i < col_draw_lines; i++)
	{ 
		unsigned int indice_start = static_cast<unsigned int>(vertices.size());
		vertices.emplace_back((glm::vec3(i* step_x, 0.0f, 0.0f) - glm::vec3(1.0f, 1.0f, 1.0f)) * MAX_MATRIX_BOUNDARY);
		vertices.emplace_back((glm::vec3(i* step_x, 2.0f, 0.0f) - glm::vec3(1.0f, 1.0f, 1.0f)) * MAX_MATRIX_BOUNDARY);

		indices.emplace_back(indice_start, indice_start + 1);
	}

	this->GetMeshes().emplace_back(Mesh(vertices, indices));

}