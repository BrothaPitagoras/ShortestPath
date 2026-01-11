#pragma once

#include <includes.h>

class Edge
{
private:
	float cost_;
	unsigned int to_;
public:	

	Edge(float cost, unsigned int node_id) : cost_{ cost }, to_{ node_id } {};

};