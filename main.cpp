#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "shader.hpp"

using namespace glm;
using namespace std;

bool quit=true;

static const int WINDOW_WIDTH=640;
static const int WINDOW_HEIGHT=480;

static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, // triangle 1 : end
    1.0f, 1.0f,-1.0f, // triangle 2 : begin
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f, // triangle 2 : end
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};
static const GLfloat g_uv_buffer_data[] = {
		0.0f, 1.0f-0.000004f,
		1.0f, 1.0f-0.336048f,
		0.0f, 1.0f-0.335903f,
		0.0f, 1.0f-0.000013f,
		1.0f, 1.0f-0.335851f,
		0.0f, 1.0f-0.336064f,
		0.0f, 1.0f-0.335851f,
		1.0f, 1.0f-0.671877f,
		0.0f, 1.0f-0.671889f,
		0.0f, 1.0f-0.000013f,
		1.0f, 1.0f-0.000013f,
		0.0f, 1.0f-0.335851f,
		0.0f, 1.0f-0.000004f,
		1.0f, 1.0f-0.335903f,
		0.0f, 1.0f-0.000071f,
		0.0f, 1.0f-0.335851f,
		1.0f, 1.0f-0.335903f,
		0.0f, 1.0f-0.671877f,
		0.0f, 1.0f-0.671847f,
		1.0f, 1.0f-0.336064f,
		0.0f, 1.0f-0.335851f,
		0.0f, 1.0f-0.000013f,
		1.0f, 1.0f-0.335903f,
		0.0f, 1.0f-0.335851f,
		0.0f, 1.0f-0.335903f,
		1.0f, 1.0f-0.000013f,
		0.0f, 1.0f-0.000071f,
		0.0f, 1.0f-0.336048f,
		1.0f, 1.0f-0.671870f,
		0.0f, 1.0f-0.671877f,
		0.0f, 1.0f-0.336048f,
		1.0f, 1.0f-0.671877f,
		0.0f, 1.0f-0.335903f,
		0.0f, 1.0f-0.671889f,
		1.0f, 1.0f-0.671847f,
		0.0f, 1.0f-0.335851f
	};

int main(){

    if( !glfwInit() )
    {
        cerr << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Pour rendre MacOS heureux ; ne devrait pas être nécessaire
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // On ne veut pas l'ancien OpenGL

    GLFWwindow* window;
    window = glfwCreateWindow( WINDOW_WIDTH, WINDOW_HEIGHT, "OpenGL Render", NULL, NULL);
    if( window == NULL ){
        cerr << "Failed to open GLFW window." << endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // Initialise GLEW
    glewExperimental=true; // Nécessaire dans le profil de base
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to initialize GLEW" << endl;
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

    GLuint uvbuffer;
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    GLuint programID = LoadShaders( "Shaders/SimpleVertex.shader", "Shaders/SimpleFragment.shader" );


    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, 0.1f, 100.0f);
    //glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
    glm::mat4 View = glm::lookAt(
                   glm::vec3(4,3,3), // Camera is at (4,3,3), in World Space
                   glm::vec3(0,0,0), // and looks at the origin
                   glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                   );
    glm::mat4 Model = glm::mat4(1.0f);

    glm::mat4 mvp = Projection * View * Model;

    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

//    GLuint Texture = loadDDS("Textures/2k_earth_clouds.dds");

    GLuint Texture = loadBMP_custom("Textures/2k_earth_daymap.bmp");
    GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(programID);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

        glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
		glUniform1i(TextureID, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           0,                  // stride
           (void*)0            // array buffer offset
        );
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            2,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
        );

        glDrawArrays(GL_TRIANGLES, 0, 3*12);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

        if(glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS || glfwWindowShouldClose(window) == 1){
            quit=false;
        }

    }
    while(quit);

    glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteVertexArrays(1, &VertexArrayID);

    glfwTerminate();
    return 0;
}
