#pragma once
#include <includes.h>
#include <data/Edge.h>
#include <model/Vertex.h>

class Node
{
private:
	unsigned int id_;
	Vertex position_;
	std::vector<Edge> edges_;
public:
	unsigned int GetId() const noexcept { return id_; }
	const Vertex& GetPosition() const noexcept { return position_; }
	Node(unsigned int id, Vertex position) : id_{ id }, position_{ position } {};
};

