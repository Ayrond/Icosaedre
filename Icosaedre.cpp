#include "Icosaedre.h"

#define phi = (1+(5**(1/2))/2)

//double lenght=1, glm::vec3 origin=(glm::vec3) * (0,0,0), int sub_div=1

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
int Icosaedre::vertex_array_lenght(){
    return 0;
}
//(a/2,aL/2,0)
//(0,a/2,aL/2)
//(aL/2,0,a/2)
void Icosaedre::calc(){
    for(int i=0;i<20;i++){
            for(int j=0;i<3;j++){
                m_g_vertex_buffer_data[]+={(GLfloat)** (m_lenght/2),(GLfloat)** ((m_lenght*phi)/2),0.0f}
            }

    }

}

GLfloat* Icosaedre::get_vertex_array(){
    GLfloat* returned_array = m_g_vertex_buffer_data;
    return returned_array;
}
