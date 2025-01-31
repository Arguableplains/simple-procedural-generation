#include <iostream>
#include <iomanip>
#include "Shaders.h"
#include "ElementsMath.h"
#include "Elements.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>

using namespace std;

int main(){

    // Constants
    default_random_engine generator((unsigned)time(0));
    uniform_real_distribution<float> distribution(-90.0f, 90.0f);
    double new_time;
    float new_angle = 0.0f;

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
        0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f
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

        // Rotate Tick
        if((glfwGetTime() - new_time) > 1.0){
            new_angle = distribution(generator);
            new_time = glfwGetTime();
        }

        vertices[7] = (glfwGetTime() - new_time);

        // Elements object
        Elements elements(vertices, indices, sizeof(vertices), sizeof(indices));

        // Writing the shaders stringsm, creating and compile the shaders programs
        string fragmentShader = shader_obj.FragShader();
        string vertexShader =  shader_obj.VertexShader();
        unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);
        glUseProgram(shader);

        // Base rendering
        elementsmath.rotate("model", new_angle, 0.0f, 0.0f, 1.0f);
        elementsmath.translate("view", 0.0f, -glfwGetTime() / 10.0f, 0.0f);
        elementsmath.MountTransformMatrix();
        elementsmath.Reset();

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

