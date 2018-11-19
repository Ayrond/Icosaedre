#include "Icosaedre.h"
#include <math.h>

//double lenght=1, glm::vec3 origin=(glm::vec3) * (0,0,0), int sub_div=1

static const float phi = (1+sqrt(5))/2;

Icosaedre::Icosaedre(){
        m_lenght=1;
        m_origin= glm::vec3(0,0,0);
        m_sub_div=1;
}

Icosaedre::Icosaedre(double lenght, glm::vec3 origin, int sub_div):
    m_lenght(lenght),
    m_origin(origin),
    m_sub_div(sub_div)
{}

void Icosaedre::set_param(double lenght, glm::vec3 origin, int sub_div){
    m_lenght=lenght;
    m_origin=origin;
    m_sub_div=sub_div;
}

void Icosaedre::sub_divide(int nb_subdivision){
    m_sub_div=nb_subdivision;
    calc();
}
size_t Icosaedre::vertex_array_size(){
    return sizeof(m_g_vertex_buffer_data);
}
//(a/2,aL/2,0)
//(0,a/2,aL/2)
//(aL/2,0,a/2)
void Icosaedre::calc(){
    init();
//    m_g_vertex_buffer_data= (GLfloat*) malloc(3 * sizeof(GLfloat) * 20 * 3);
//    for(int i=0;i<(20*3);i=i+9){
//        for(int j=0;j<3;j++){
////            m_g_vertex_buffer_data[(i+1)]=value(i+j);
////            m_g_vertex_buffer_data[(i+2)]=value(i+j+1);
////            m_g_vertex_buffer_data[(i+3)]=value(i+j+2);
//        }

//    }

}

void Icosaedre::init(){
    GLfloat buffer_data[]={
        m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        0.0f, m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,

        0.0f, m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        -m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,
        -m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,

        0.0f, m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        0.0f, -m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,

        0.0f, m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        0.0f, -m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        -m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,

        m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        0.0f, -m_lenght/ 2.0f, m_lenght* phi/ 2.0f,
        m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,

        0.0f, m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        -m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,
        -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,

        m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        -m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        0.0f, m_lenght/ 2.0f, m_lenght* phi/ 2.0f,

        m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        -m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        0.0f, m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,

        m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        0.0f, -m_lenght/ 2.0f, m_lenght* phi/ 2.0f,

        m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        0.0f, -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,

        0.0f, m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        0.0f, -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        -m_lenght* phi/ 2.0f, 0.0f, -m_lenght/ 2.0f,

        0.0f, m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        0.0f, -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        m_lenght* phi/ 2.0f, 0.0f, m_lenght/ 2.0f,

        m_lenght* phi/ 2.0f, -m_lenght/ 2.0f, 0.0f,
        m_lenght* phi/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,

        m_lenght* phi/ 2.0f, -m_lenght/ 2.0f, 0.0f,
        m_lenght* phi/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,

        -m_lenght* phi/ 2.0f, -m_lenght/ 2.0f, 0.0f,
        -m_lenght* phi/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        -m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,

        -m_lenght* phi/ 2.0f, -m_lenght/ 2.0f, 0.0f,
        -m_lenght* phi/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,

        m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        0.0f, m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        m_lenght* phi/ 2.0f, 0.0f, -m_lenght/ 2.0f,

        m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        0.0f, -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        m_lenght* phi/ 2.0f, 0.0f, -m_lenght/ 2.0f,

        -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f, 0.0f,
        0.0f, -m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        -m_lenght* phi/ 2.0f, 0.0f, -m_lenght/ 2.0f,

        -m_lenght/ 2.0f, m_lenght* phi/ 2.0f, 0.0f,
        0.0f, m_lenght/ 2.0f, -m_lenght* phi/ 2.0f,
        -m_lenght* phi/ 2.0f, 0.0f, -m_lenght/ 2.0f
    };
    m_g_vertex_buffer_data=buffer_data;
}

GLfloat* Icosaedre::get_vertex_array(){
    GLfloat* returned_array = m_g_vertex_buffer_data;
//    GLfloat* returned_array = 0;
    return returned_array;
}
