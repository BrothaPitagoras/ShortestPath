#include <data/Path.h>

Path::Path(const std::vector<unsigned int>& node_ids) : node_ids_{ node_ids }
{
	// Create edges based on node IDs
	for (unsigned int i = 0; i < node_ids.size() - 1; i++)
	{
		edges_.emplace_back(i, i + 1);
	}
};