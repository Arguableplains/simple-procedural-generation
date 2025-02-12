#include <iostream>
#include <iomanip>
#include "Shaders.h"
#include "ElementsMath.h"
#include "Elements.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <random>
#include <deque>

using namespace std;

int main(){

    // Random Generation
    default_random_engine generator(time(0));
    uniform_real_distribution<float> distribution(-0.2f, 0.2f);

    // Important Variables
    double currentTime;
    double lastTime = 0;
    float new_x1, new_y1, new_x2, new_y2, last_x, last_y, new_value;
    deque<pair<float, float>> endpoints;

    if (!glfwInit())
        return -1;

    // Window Object
    GLFWwindow* window = glfwCreateWindow(700, 600, "pg_simple", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewInit();

    // Elements vertices and indices to draw
    deque<float> vertices = {
        0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f
    };

    deque <unsigned int> indices = {
        0, 1
    };

    // Main GL objects
    Shaders shader_obj;
    ElementsMath elementsmath;

    // Writing the shaders stringsm, creating and compile the shaders programs
    string fragmentShader = shader_obj.FragShader();
    string vertexShader =  shader_obj.VertexShader();
    unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);

    // Elements object
    float vertices_arr[vertices.size()];
    copy(vertices.begin(), vertices.end(), vertices_arr);

    unsigned int indices_arr[indices.size()];
    copy(indices.begin(), indices.end(), indices_arr);

    Elements elements(vertices_arr, indices_arr, sizeof(vertices_arr), sizeof(indices_arr));

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window)){

        // Render
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        // Clear the previous frame
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);


        // Timer Tick
        currentTime = glfwGetTime();
        if((currentTime - lastTime) > 0.35f){
            lastTime = glfwGetTime();

            endpoints.clear();
             // Fiding where the new rods gonna be putted
            for (int i = (vertices.size() - 5); i > 0; i -= 24) {

                // Getting all y's values
                endpoints.push_back({vertices[i-1],vertices[i]});

            }

            // Creating new vertices for the rods
            for (int j = 0; j < 6; j++) {
                last_x = endpoints[j].first;
                last_y = endpoints[j].second;

                new_value = distribution(generator);

                // First mirrored direction
                new_x1 = last_x + new_value;
                new_y1 = last_y + 0.2f;

                // Second mirrored direction
                new_x2 = last_x - new_value;
                new_y2 = last_y + 0.2f;

                // Ensure they are within bounds
                if (new_x1 < 1.0f && new_x1 > -1.0f){

                    vertices.push_back(last_x);
                    vertices.push_back(last_y);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    vertices.push_back(new_x1);
                    vertices.push_back(new_y1);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    vertices.push_back(new_x1);
                    vertices.push_back(new_y1);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    vertices.push_back(new_x1);
                    vertices.push_back(new_y1 + 0.2f);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    indices.push_back(indices.back() + 1);
                    indices.push_back(indices.back() + 1);
                    indices.push_back(indices.back() + 1);
                    indices.push_back(indices.back() + 1);
                }

                if (new_x2 < 1.0f && new_x2 > -1.0f) {
                    vertices.push_back(last_x);
                    vertices.push_back(last_y);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    vertices.push_back(new_x2);
                    vertices.push_back(new_y2);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    vertices.push_back(new_x2);
                    vertices.push_back(new_y2);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    vertices.push_back(new_x2);
                    vertices.push_back(new_y2 + 0.2f);
                    vertices.push_back(0.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);
                    vertices.push_back(1.0f);

                    indices.push_back(indices.back() + 1);
                    indices.push_back(indices.back() + 1);
                    indices.push_back(indices.back() + 1);
                    indices.push_back(indices.back() + 1);
                }
            }

            if(vertices.size() > 100){
                for(int i = 0; i < (24); i++){
                    vertices.pop_front();
                }
            }

            float vertices_arr[vertices.size()];
            copy(vertices.begin(), vertices.end(), vertices_arr);

            unsigned int indices_arr[indices.size()];
            copy(indices.begin(), indices.end(), indices_arr);

            elements.BindBuffer(GL_ARRAY_BUFFER, elements.VBO);
            elements.BufferData(GL_ARRAY_BUFFER, sizeof(vertices_arr), vertices_arr, GL_STATIC_DRAW);

            elements.BindBuffer(GL_ELEMENT_ARRAY_BUFFER, elements.EBO);
            elements.BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_arr), indices_arr, GL_STATIC_DRAW);

        }

        glUseProgram(shader);

        // Base rendering
        elementsmath.translate("view", 0.0f, (-glfwGetTime() / 1.0f), 0.0f);
        elementsmath.MountTransformMatrix();

        shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());

        elements.BindVertexArray(elements.VAO);
        glDrawElements(GL_LINES, indices.size(), GL_UNSIGNED_INT, 0);
        elementsmath.Reset();

        // Swap front and back buffers
        glfwSwapBuffers(window);
        //Poll for and process events
        glfwPollEvents();
        glFlush();
    }


    glfwTerminate();
    return 0;
}

