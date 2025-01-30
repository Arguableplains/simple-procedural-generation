#include <iostream>
#include <iomanip>
#include "Shaders.h"
#include "ElementsMath.h"
#include "Elements.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(){

    // Constants
    srand(time(0));
    double old_time;
    double new_time;

    if (!glfwInit())
        return -1;

    // Window Object
    GLFWwindow* window = glfwCreateWindow(600, 600, "pg_simple", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // Elements vertices and indices to draw

    float vertices[] = {
        0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1
    };

    // Main GL objects
    Shaders shader_obj;
    ElementsMath elementsmath;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){

        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Clear the previous frame
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST | GL_DEPTH_BUFFER_BIT);

        // Elements object

        if ((int)glfwGetTime() % 2 == 0)  {
            vertices[7] = glfwGetTime();
            vertices[6] = -glfwGetTime();
        }
        else {
            vertices[7] = glfwGetTime();
            vertices[6] = glfwGetTime();
        }

        Elements elements(vertices, indices, sizeof(vertices), sizeof(indices));

        // Writing the shaders stringsm, creating and compile the shaders programs
        std::string fragmentShader = shader_obj.FragShader();
        std::string vertexShader =  shader_obj.VertexShader();
        unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);
        glUseProgram(shader);

        // Base rendering
        elementsmath.MountTransformMatrix();
        shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());
        glDrawElements(GL_LINES, 11, GL_UNSIGNED_INT, 0);


        // Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();

        glFlush();
    }

    glfwTerminate();
    return 0;
}

