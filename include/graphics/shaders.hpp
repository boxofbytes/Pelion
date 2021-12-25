/* Header file for modifying or initializing the Pelion */
/* OpenGL shaders.                                      */

/* Include guard */
#ifndef SHADERS_HPP
#define SHADERS_HPP

/* Pelion headers */
#include <graphics.hpp>

/* C++ libraries */
#include <string>

/* Variables */
inline GLuint shader_program;
inline std::string vertex_shader_src;
inline std::string fragment_shader_src;

/* Functions */
void shaders_init();
void shaders_set_mat4(glm::mat4 matrix, std::string uniform);
void shaders_set_vec3(glm::vec3 vector, std::string uniform);

#endif