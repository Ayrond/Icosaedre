#ifndef SHADER_HPP
#define SHADER_HPP

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);

GLuint loadDDS(const char * imagepath);
GLuint loadBMP_custom(const char * imagepath);
#endif
