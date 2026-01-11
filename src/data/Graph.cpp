#include <data/Graph.h>

Graph::Graph(const unsigned int rows, const unsigned int cols)
{
	GenerateMatrixGraph(rows, cols);
}

void Graph::GenerateMatrixGraph(const unsigned int rows, const unsigned int cols)
{

	float step_x = 2.0f / static_cast<float> (cols);
	float step_y = 2.0f / static_cast<float> (rows);

	for (unsigned int i = 0; i < rows; i++)
	{
		for (unsigned int j = 0; j < cols; j++)
		{
			unsigned int node_id = i * cols + j;
			glm::vec3 pos = glm::vec3(
				j * step_x + step_x * 0.5f,
				i * step_y + step_y * 0.5f,
				0.0f
			);
			nodes_.emplace_back(node_id, (pos - glm::vec3(1.0f, 1.0f, 0.0f)) * MAX_MATRIX_BOUNDARY);
		}
	}
}