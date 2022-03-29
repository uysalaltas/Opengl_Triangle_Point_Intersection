#pragma once
#include <vector>
#include "VertexBuffer.h"

std::vector<Vertex> verticesCube = {
	Vertex{glm::vec3(0.0f, 0.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 20.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 20.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 0.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 20.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 20.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 0.0f, 20.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 0.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 20.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 20.0f, 20.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 20.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 0.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},

	Vertex{glm::vec3(20.0f, 20.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(0.0f, 20.0f, 20.0f) , glm::vec3(0.0f, 1.0f, 0.0f)},
	Vertex{glm::vec3(20.0f, 0.0f, 20.0f), glm::vec3(0.0f, 1.0f, 0.0f)},
};

std::vector<GLuint> indicesCube
{
	0, 1, 2,
	3, 4, 5,
	6, 7, 8,
	9, 10, 11,
	12, 13, 14,
	15, 16, 17,
	18, 19, 20,
	21, 22, 23,
	24, 25, 26, 
	27, 28, 29,
	30, 31, 32
};