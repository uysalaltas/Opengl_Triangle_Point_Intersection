#pragma once
#include <glm/glm.hpp> 
#include "VertexBuffer.h"

typedef glm::vec3 Point;

struct Triangle
{
	Point a;
	Point b;
	Point c;

	Vertex& aV;
	Vertex& bV;
	Vertex& cV;
};