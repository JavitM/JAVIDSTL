// JAVIDSTL. Created By Javid Mamedov.
#pragma once

template<typename T>
class Edge
{
public:

	T* GetstartVertex()
	{
		return startVertex;
	}

	T* GetendVertex()
	{
		return endVertex;
	}

private;
	T* startVertex;
	T* endVertex;
};

// string vertex_list[MAX_SIZE]
// Edge edge_list[MAX_SIZE]
