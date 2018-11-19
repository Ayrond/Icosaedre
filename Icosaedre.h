#ifndef ICOSAEDRE_H_INCLUDED
#define ICOSAEDRE_H_INCLUDED

//#include <iostream>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Icosaedre
{
    public :

        Icosaedre();
        Icosaedre(double lenght, glm::vec3 origin, int sub_div);

        void set_param(double lenght, glm::vec3 origin, int sub_div);

        void sub_divide(int nb_subdivision=1);
        int vertex_array_lenght();

        void calc();

        GLfloat* get_vertex_array();


    private :
        double m_lenght;
        glm::vec3 m_origin;
        int m_sub_div;
        GLfloat m_g_vertex_buffer_data[];
};

#endif // ICOSAEDRE_H_INCLUDED
