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

    // Constants
    default_random_engine generator(time(0));
    uniform_real_distribution<float> distribution(180.0f, 0.0f);
    double new_time;
    float new_angle = 0.0f;
    int counter = 0;

    int start_index = 0;
    int end_index = 0;

    int rod_render_number = 5;

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
    deque<float> vertices = {
        0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f
    };

    deque <unsigned int> indices = {
        0, 1
    };

    /*
    float vertices[rod_render_number * 6];
    vertices[0] = 0.0f;
    vertices[1] = 0.0f;
    vertices[2] = 0.0f;

    vertices[3] = 1.0f;
    vertices[4] = 1.0f;
    vertices[5] = 1.0f;

    vertices[6] = 0.0f;
    vertices[7] = 1.0f;
    vertices[8] = 0.0f;

    vertices[9] = 1.0f;
    vertices[10] = 1.0f;
    vertices[11] = 1.0f;

    unsigned int indices[20];
    for(int i = 0; i < 20; i++){
        indices[i] = i;
    }
    */

    // Main GL objects
    Shaders shader_obj;
    ElementsMath elementsmath;

    // Writing the shaders stringsm, creating and compile the shaders programs
    string fragmentShader = shader_obj.FragShader();
    string vertexShader =  shader_obj.VertexShader();
    unsigned int shader = shader_obj.CreateShader(vertexShader, fragmentShader);

    float last_endpoint[2] = {vertices[6], vertices[7]};
    float new_endpoint[2];

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
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Clear the previous frame
        glEnable(GL_DEPTH_TEST);

        // Timer Tick
        if((glfwGetTime() - new_time) > 0.01f){
            counter+=2;
            new_angle = (distribution(generator)/180)*acos(-1);
            new_time = glfwGetTime();

            new_endpoint[0] = last_endpoint[0] + 0.1f * cos(new_angle);
            new_endpoint[1] = last_endpoint[1] + 0.1f * sin(new_angle);

            if(new_endpoint[0] < 1.0f && new_endpoint[0] > -1.0f){

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

                /*
                // Adding new informations to the main array - new inverted rods
                vertices.push_back(last_endpoint[0]);
                vertices.push_back(last_endpoint[1]);
                vertices.push_back(0.0f);
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);

                vertices.push_back(-new_endpoint[0]);
                vertices.push_back(new_endpoint[1]);
                vertices.push_back(0.0f);
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);
                vertices.push_back(1.0f);
                */

                cout << "_______________________________" << endl;
                    cout << new_endpoint[0] << endl;
                    cout << new_endpoint[1] << endl;
                cout << "_______________________________" << endl;
            }

            // Update lastEndpoint
            last_endpoint[0] = new_endpoint[0];
            last_endpoint[1] = new_endpoint[1];

            //Update indices
            indices.push_back(indices[indices.size()-1] + 1);
            indices.push_back(indices[indices.size()-1] + 1);

            if(counter > 1000000){
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
                vertices.pop_front();
            }

            float vertices_arr[vertices.size()];
            copy(vertices.begin(), vertices.end(), vertices_arr);

            unsigned int indices_arr[indices.size()];
            copy(indices.begin(), indices.end(), indices_arr);

            elements.BindBuffer(GL_ARRAY_BUFFER, elements.VBO);
            elements.BufferData(GL_ARRAY_BUFFER, sizeof(vertices_arr), vertices_arr, GL_STATIC_DRAW);

            elements.BindBuffer(GL_ARRAY_BUFFER, elements.EBO);
            elements.BufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices_arr), indices_arr, GL_STATIC_DRAW);

            /*
            elements.BindBuffer(GL_ARRAY_BUFFER, elements.VBO);
            elements.BufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices, GL_STATIC_DRAW);

            elements.BindBuffer(GL_ARRAY_BUFFER, elements.EBO);
            elements.BufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices, GL_STATIC_DRAW);
            */

        }

        glUseProgram(shader);

        // Base rendering
        //elementsmath.rotate("model", new_angle, 0.0f, 0.0f, 1.0f);
        elementsmath.translate("view", 0.0f, -glfwGetTime() / 2.0f, 0.0f);
        elementsmath.MountTransformMatrix();

        shader_obj.UniformConfig("transform", shader, elementsmath.getTransformMatrix());

        elements.BindVertexArray(elements.VAO);
        glDrawElements(GL_LINES, counter, GL_UNSIGNED_INT, 0);
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

