#pragma once

#include <includes.h>
#include <data/Node.h>


class Graph
{
private:
	std::vector<Node> nodes_;
public:
	Graph(const unsigned int rows, const unsigned int cols);
	const std::vector<Node>& GetNodes() const noexcept { return nodes_; }
	void GenerateMatrixGraph(const unsigned int rows, const unsigned int cols);
};