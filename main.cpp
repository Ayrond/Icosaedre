#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "shader.hpp"
#include "Icosaedre.h"

using namespace glm;
using namespace std;

bool quit=true;

static const int WINDOW_WIDTH=640;
static const int WINDOW_HEIGHT=480;

const float r2 = sqrt(2);

//static const GLfloat g_vertex_buffer_data[] = {0.5f,0.809017f,0f,0f,0.5f,0.809017f,0.809017f,0f,0.5f,0f,0.5f,0.809017f,-0.809017f,0f,0.5f,-0.5f,0.809017f,0f,0f,0.5f,0.809017f,0f,-0.5f,0.809017f,0.809017f,0f,0.5f,0f,0.5f,0.809017f,0f,-0.5f,0.809017f,-0.809017f,0f,0.5f,0.5f,-0.809017f,0f,0f,-0.5f,0.809017f,0.809017f,0f,0.5f,0f,0.5f,-0.809017f,-0.809017f,0f,0.5f,-0.5f,-0.809017f,0f,0.5f,0.809017f,0f,-0.5f,0.809017f,0f};
static const GLfloat g_vertex_buffer_data[] = {
    1,1,0,-1,1,0,0,0,r2,
    1,1,0,-1,1,0,0,0,-r2,
    1,1,0,1,-1,0,0,0,r2,
    1,1,0,1,-1,0,0,0,-r2,
    1,-1,0,-1,-1,0,0,0,r2,
    1,-1,0,-1,-1,0,0,0,-r2,
    -1,-1,0,-1,1,0,0,0,r2,
    -1,-1,0,-1,1,0,0,0,-r2
};
//static const GLfloat g_vertex_buffer_data[] = {0.5, 0.809017, 0, 0, 0.5, 0.809017, 0.809017, 0, 0.5, 0, 0.5, 0.809017, -0.809017, 0, 0.5, -0.5, 0.809017, 0, 0, 0.5, 0.809017, 0, -0.5, 0.809017, 0.809017, 0, 0.5, 0, 0.5, 0.809017, 0, -0.5, 0.809017, -0.809017, 0, 0.5, 0.5, -0.809017, 0, 0, -0.5, 0.809017, 0.809017, 0, 0.5, 0, 0.5, -0.809017, -0.809017, 0, 0.5, -0.5, -0.809017, 0, 0.5, 0.809017, 0, -0.5, 0.809017, 0};
//static const GLfloat g_vertex_buffer_data[] = {
//    -1.0f,-1.0f,-1.0f, // triangle 1 : begin
//    -1.0f,-1.0f, 1.0f,
//    -1.0f, 1.0f, 1.0f, // triangle 1 : end
//    1.0f, 1.0f,-1.0f, // triangle 2 : begin
//    -1.0f,-1.0f,-1.0f,
//    -1.0f, 1.0f,-1.0f, // triangle 2 : end
//    1.0f,-1.0f, 1.0f,
//    -1.0f,-1.0f,-1.0f,
//    1.0f,-1.0f,-1.0f,
//    1.0f, 1.0f,-1.0f,
//    1.0f,-1.0f,-1.0f,
//    -1.0f,-1.0f,-1.0f,
//    -1.0f,-1.0f,-1.0f,
//    -1.0f, 1.0f, 1.0f,
//    -1.0f, 1.0f,-1.0f,
//    1.0f,-1.0f, 1.0f,
//    -1.0f,-1.0f, 1.0f,
//    -1.0f,-1.0f,-1.0f,
//    -1.0f, 1.0f, 1.0f,
//    -1.0f,-1.0f, 1.0f,
//    1.0f,-1.0f, 1.0f,
//    1.0f, 1.0f, 1.0f,
//    1.0f,-1.0f,-1.0f,
//    1.0f, 1.0f,-1.0f,
//    1.0f,-1.0f,-1.0f,
//    1.0f, 1.0f, 1.0f,
//    1.0f,-1.0f, 1.0f,
//    1.0f, 1.0f, 1.0f,
//    1.0f, 1.0f,-1.0f,
//    -1.0f, 1.0f,-1.0f,
//    1.0f, 1.0f, 1.0f,
//    -1.0f, 1.0f,-1.0f,
//    -1.0f, 1.0f, 1.0f,
//    1.0f, 1.0f, 1.0f,
//    -1.0f, 1.0f, 1.0f,
//    1.0f,-1.0f, 1.0f
//};

//GLfloat g_uv_buffer_data[] = {
//		545.0f,620.0f,545.0f,12.0f,1074.0f,316.0f,
//545,620,545,12,17,315,
//545,620,1074,925,1074,316,
//545,620,1074,925,545,1231,
//1074,925,1604,620,1074,316,
//1074,925,1604,620,1600,1230,
//1604,620,545,12,1074,316,
//1604,620,545,12,2130,315
//
//};
//GLfloat g_uv_buffer_data[] = {
//		0,0,2142,0,2142/2,1265,
//545,620,545,12,17,315,
//545,620,1074,925,1074,316,
//545,620,1074,925,545,1231,
//1074,925,1604,620,1074,316,
//1074,925,1604,620,1600,1230,
//1604,620,545,12,1074,316,
//1604,620,545,12,2130,315
//
//};
	GLfloat g_uv_buffer_data[] = {
		545,620,545,12,1074,316,
        545,620,545,12,1074,315,
        545,620,1074,925,1074,316,
        545,620,1074,925,545,1231,
        1074,925,1604,620,1074,316,
        1074,925,1604,620,1600,1230,
        1604,620,545,12,1074,316,
        1604,620,545,12,2130,315

	};


int main(){

//    Icosaedre Ico = Icosaedre(1.0,glm::vec3(0,0,0),1);
//    Ico.set_param(1.0,glm::vec3(0,0,0), 1);
//    Ico.calc();
////    GLfloat* g_vertex_buffer_data=(GLfloat*) malloc(Ico.vertex_array_size());
////    g_vertex_buffer_data=Ico.get_vertex_array();
//    GLfloat* g_vertex_buffer_data=Ico.get_vertex_array();
//    for(int i =0;i<60;i++){cout << g_vertex_buffer_data[i] << endl;}
//    for(int i =0;i<48;i++){cout << g_uv_buffer_data[i] << endl;}
    for(int i=0;i<48;i=i+2){g_uv_buffer_data[i]=g_uv_buffer_data[i]/2142;g_uv_buffer_data[i+1]=g_uv_buffer_data[i+1]/1265;}
    for(int i =0;i<48;i++){cout << g_uv_buffer_data[i] << endl;}
    cout << "Size Array:" << sizeof(g_vertex_buffer_data) << endl;
    cout << "Triangles:" << (sizeof(g_vertex_buffer_data)/(sizeof(float)*3)) << endl;

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

    GLuint MatrixID = glGetUniformLocation(programID, "MVP");

//    GLuint Texture = loadBMP_custom("Textures/2k_earth_clouds.bmp");

    GLuint Texture = loadBMP_custom("Textures/Earth_Tetra3.bmp");
    GLuint TextureID  = glGetUniformLocation(programID, "myTextureSampler");

    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glm::mat4 ProjectionMatrix;
    glm::mat4 ViewMatrix;
    glm::mat4 ModelMatrix = glm::mat4(1.0);

    double currentTime,lastTime,deltaTime;

    glm::vec3 position = glm::vec3( 0, 0, 5);
    // horizontal angle : toward -Z
    float horizontalAngle = -3.14f;
    // vertical angle : 0, look at the horizon
    float verticalAngle = 0.0f;
    // Initial Field of View
    float initialFoV = 45.0f;

    float speed = 3.0f; // 3 units / second
    float mouseSpeed = 0.01f;

    do{
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        double xpos, ypos, xcpos, ycpos, Cursor_Wheel_pos;
        glfwGetCursorPos(window, &xpos, &ypos);
        glfwSetCursorPos(window, WINDOW_HEIGHT/2, WINDOW_WIDTH/2);

        currentTime= glfwGetTime();
        deltaTime= currentTime-lastTime;
        lastTime=currentTime;

        horizontalAngle += mouseSpeed * deltaTime * float(WINDOW_HEIGHT/2 - xpos );
        verticalAngle   += mouseSpeed * deltaTime * float( WINDOW_WIDTH/2 - ypos );

        glm::vec3 direction(
            cos(verticalAngle) * sin(horizontalAngle),
            sin(verticalAngle),
            cos(verticalAngle) * cos(horizontalAngle)
        );

        glm::vec3 right = glm::vec3(
            sin(horizontalAngle - 3.14f/2.0f),
            0,
            cos(horizontalAngle - 3.14f/2.0f)
        );

        glm::vec3 up = glm::cross( right, direction );

        if (glfwGetKey(window, GLFW_KEY_UP ) == GLFW_PRESS){
            position = position + glm::mat3(deltaTime * speed)* direction;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN ) == GLFW_PRESS){
            position -= glm::mat3(deltaTime * speed)* direction;
        }
        if (glfwGetKey(window, GLFW_KEY_RIGHT ) == GLFW_PRESS){
            position += glm::mat3(deltaTime * speed)* right;
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT ) == GLFW_PRESS){
            position -= glm::mat3(deltaTime * speed)* right;
        }

        float FoV = initialFoV - 5 * Cursor_Wheel_pos;

        ProjectionMatrix= glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);

        ViewMatrix=glm::lookAt(
            position,
            position+direction,
            up
        );

        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

        glUseProgram(programID);
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
		glUniform1i(TextureID, 0);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size();
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

        glDrawArrays(GL_TRIANGLES, 0, (sizeof(g_vertex_buffer_data)/(sizeof(float)*3)));
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
