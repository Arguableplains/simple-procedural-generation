#include <iostream>
#include <iomanip>
#include "Shaders.h"
#include "ElementsMath.h"
#include "Elements.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
#include <vector>

using namespace std;

int main(){

    // Constants
    default_random_engine generator(time(0));
    uniform_real_distribution<float> distribution(180.0f, 0.0f);
    double new_time;
    float new_angle = 0.0f;
    int counter = 0;

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

    vector<float> vertices = {
        0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f
    };

    vector <unsigned int> indices = {
        0, 1
    };

    // Main GL objects
    Shaders shader_obj;
    ElementsMath elementsmath;

    float last_endpoint[2] = {vertices[6], vertices[7]};
    float new_endpoint[2];

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){

        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Clear the previous frame
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_DEPTH_TEST | GL_DEPTH_BUFFER_BIT);

        // Timer Tick
        if((glfwGetTime() - new_time) > 1.0){
            counter+=2;
            new_angle = (distribution(generator)/180)*acos(-1);
            new_time = glfwGetTime();

            new_endpoint[0] = last_endpoint[0] + 0.5f * cos(new_angle);
            new_endpoint[1] = last_endpoint[1] + 0.5f * sin(new_angle);

            // Adding new informations to the main array - new rods
            vertices.push_back(last_endpoint[0]);
            vertices.push_back(last_endpoint[1]);
            vertices.push_back(0.0f);
            vertices.push_back(1.0f);
            vertices.push_back(1.0f);
            vertices.push_back(1.0f);

            vertices.push_back(new_endpoint[0]);
            vertices.push_back(new_endpoint[1]);
            vertices.push_back(0.0f);
            vertices.push_back(1.0f);
            vertices.push_back(1.0f);
            vertices.push_back(1.0f);

            // Update lastEndpoint
            last_endpoint[0] = new_endpoint[0];
            last_endpoint[1] = new_endpoint[1];

            //Update indices
            indices.push_back(indices[indices.size()-1] + 1);
            indices.push_back(indices[indices.size()-1] + 1);

        }

        // Elements object
        float vertices_arr[vertices.size()];
        copy(vertices.begin(), vertices.end(), vertices_arr);

        unsigned int indices_arr[indices.size()];
        copy(indices.begin(), indices.end(), indices_arr);

        Elements elements(vertices_arr, indices_arr, sizeof(vertices_arr), sizeof(indices_arr));

        // Writing the shaders stringsm, creating and compile the shaders programs
        string fragmentShader = shader_obj.FragShader();
        string vertexShader =  shader_obj.VertexShader();
        unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);
        glUseProgram(shader);

        // Base rendering
        //elementsmath.rotate("model", new_angle, 0.0f, 0.0f, 1.0f);
        elementsmath.translate("view", 0.0f, -glfwGetTime() / 5.0f, 0.0f);
        elementsmath.MountTransformMatrix();

        shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());
        glDrawElements(GL_LINES, counter, GL_UNSIGNED_INT, 0);
        elementsmath.Reset();

        cout << "new_indice_numbers:" << endl;
        cout << counter << endl;

        // Swap front and back buffers
        glfwSwapBuffers(window);
        //Poll for and process events
        glfwPollEvents();
        glFlush();
    }

    glfwTerminate();
    return 0;
}

