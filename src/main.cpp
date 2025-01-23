#include <iostream>
#include <iomanip>
#include "Shaders.h"
#include "ElementsMath.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

int main(){

    // Constants

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
    };

    unsigned int indices[] = {
    };

    // Main GL objects
    Shaders shader_obj;
    ElementsMath elementsmath;

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){

        // Render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Clear the previous frame
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST | GL_DEPTH_BUFFER_BIT);

        // Writing the shaders stringsm, creating and compile the shaders programs
        std::string fragmentShader = shader_obj.FragShader();
        std::string vertexShader =  shader_obj.VertexShader();
        unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);
        glUseProgram(shader);

        // Base rendering
        //glDrawElements(GL_TRIANGLE_FAN, 11, GL_UNSIGNED_INT, 0);
        elementsmath.Reset();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        //Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

