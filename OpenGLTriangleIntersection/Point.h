#pragma once
#include <vector>
#include "VertexBuffer.h"

std::vector<float> pointAABB{ 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f };

std::vector<Vertex> pointVertices
{
    Vertex{glm::vec3(pointAABB[0], pointAABB[2], pointAABB[5]), glm::vec3(1.0f, 1.0f, 0.0f)},
    Vertex{glm::vec3(pointAABB[1], pointAABB[2], pointAABB[5]), glm::vec3(1.0f, 1.0f, 0.0f)},
    Vertex{glm::vec3(pointAABB[1], pointAABB[3], pointAABB[5]), glm::vec3(1.0f, 1.0f, 0.0f)},
    Vertex{glm::vec3(pointAABB[0], pointAABB[3], pointAABB[5]), glm::vec3(1.0f, 1.0f, 0.0f)},

    Vertex{glm::vec3(pointAABB[0], pointAABB[2], pointAABB[4]), glm::vec3(1.0f, 1.0f, 0.0f)},
    Vertex{glm::vec3(pointAABB[1], pointAABB[2], pointAABB[4]), glm::vec3(1.0f, 1.0f, 0.0f)},
    Vertex{glm::vec3(pointAABB[1], pointAABB[3], pointAABB[4]), glm::vec3(1.0f, 1.0f, 0.0f)},
    Vertex{glm::vec3(pointAABB[0], pointAABB[3], pointAABB[4]), glm::vec3(1.0f, 1.0f, 0.0f)},

};
std::vector<GLuint> pointIndices
{
    // front
    0, 1, 2,
    2, 3, 0,
    // right
    1, 5, 6,
    6, 2, 1,
    // back
    7, 6, 5,
    5, 4, 7,
    // left
    4, 0, 3,
    3, 7, 4,
    // bottom
    4, 5, 1,
    1, 0, 4,
    // top
    3, 2, 6,
    6, 7, 3,
};