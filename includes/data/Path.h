#pragma once

#include <includes.h>
#include <data/Node.h>

class Path
{
private:
public:
	std::vector<unsigned int> node_ids_;
	std::vector<glm::uvec2> edges_;
	Path(const std::vector<unsigned int>& node_ids);
};
