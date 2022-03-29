#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/quaternion.hpp>
#include <iostream>

#include "VertexBuffer.h"
#include "Camera.h"
#include "GLWindow.h"
#include "Renderer.h"
#include "Cube.h"
#include "Point.h"

glm::vec3 upVector = glm::vec3(0.0f, 0.0f, 1.0f);
glm::mat4 proj = glm::mat4(1.0f);
glm::mat4 view = glm::mat4(1.0f);

glm::mat4 modelCube = glm::mat4(1.0f);
glm::mat4 modelPoint = glm::mat4(1.0f);

glm::vec3 cubePos = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 pointPos = glm::vec3(40.0f, 0.0f, 0.0f);

glm::vec3 tempTranslation = { 0.0f, 0.0f, 0.0f };

bool CheckPointInTriangle(const Point& point, const Triangle& triangle);

int main(void)
{
    GLWindow gl_window;

    Camera camera(
        glm::vec3(100.0f, 0.0f, 200.0f),
        glm::vec3(0.0f, 0.0f, 0.0f),
        upVector, &gl_window.WIDTH, &gl_window.HEIGHT
    );


    Renderer cube(verticesCube, indicesCube);
    Renderer point(pointVertices, pointIndices);

    Point p;

    gl_window.InitCamera(&camera);

    Shader shaderBasic("Basic.shader");

    while (!glfwWindowShouldClose(gl_window.window))    
    {
        gl_window.Bind();
        shaderBasic.SetUniform3f("lightPos", 0.0f, 0.0f, 0.0f);
        shaderBasic.SetUniform3f("lightColor", 0.8f, 0.8f, 0.8f);

        cube.Clear();
        point.Clear();

        camera.UpdateProjMatrix();
        proj = camera.GetProjMatrix();
        view = camera.GetViewMatrix();

        if (glfwGetKey(gl_window.window, GLFW_KEY_W) == GLFW_PRESS) {
            pointPos.x += 0.1f;
        } 
        else if (glfwGetKey(gl_window.window, GLFW_KEY_S) == GLFW_PRESS) {
            pointPos.x -= 0.1f;
        }
        else if (glfwGetKey(gl_window.window, GLFW_KEY_A) == GLFW_PRESS) {
            pointPos.y += 0.1f;
        }
        else if (glfwGetKey(gl_window.window, GLFW_KEY_D) == GLFW_PRESS) {
            pointPos.y -= 0.1f;
        }
        else if (glfwGetKey(gl_window.window, GLFW_KEY_E) == GLFW_PRESS) {
            pointPos.z += 0.1f;
        }
        else if (glfwGetKey(gl_window.window, GLFW_KEY_Q) == GLFW_PRESS) {
            pointPos.z -= 0.1f;
        }
        
        p = pointPos;

        for (int i = 0; i < cube.m_triangles.size(); i++)
        {
            bool isCollided = CheckPointInTriangle(p, cube.m_triangles[i]);

            if (isCollided)
            {
                cube.m_triangles[i].aV.color = glm::vec3(1.0f, 1.0f, 1.0f);
                cube.m_triangles[i].bV.color = glm::vec3(1.0f, 1.0f, 1.0f);
                cube.m_triangles[i].cV.color = glm::vec3(1.0f, 1.0f, 1.0f);
            }
            else
            {
                cube.m_triangles[i].aV.color = glm::vec3(0.0f, 1.0f, 0.0f);
                cube.m_triangles[i].bV.color = glm::vec3(0.0f, 1.0f, 0.0f);
                cube.m_triangles[i].cV.color = glm::vec3(0.0f, 1.0f, 0.0f);
            }
        }

        glm::mat4 mvpCube = proj * view * modelCube;
        shaderBasic.SetUniformMat4f("u_MVP", mvpCube);
        cube.DrawTriangle(shaderBasic);

        modelPoint = glm::translate(glm::mat4(1.0f), pointPos);
        glm::mat4 mvpPoint = proj * view * modelPoint;
        shaderBasic.SetUniformMat4f("u_MVP", mvpPoint);
        point.DrawTriangle(shaderBasic);


        //gl_window.Unbind();

        glfwSwapBuffers(gl_window.window);
        glfwPollEvents();
    }

    return 0;
}

bool CheckPointInTriangle(const Point& point, const Triangle& triangle)
{
    glm::vec3 a = triangle.a - point;
    glm::vec3 b = triangle.b - point;
    glm::vec3 c = triangle.c - point;

    glm::vec3 normPBC = glm::cross(b, c);
    glm::vec3 normPCA = glm::cross(c, a);
    glm::vec3 normPAB = glm::cross(a, b);

    if (glm::dot(normPBC, normPCA) < 0.0f) {
        return false;
    }
    else if (glm::dot(normPBC, normPAB) < 0.0f) {
        return false;
    }

    return true;
}
