/* Source file for modifying or initializing the Pelion */
/* OpenGL shaders.                                      */

/* Pelion headers */
#include <Pelion.hpp>
#include <graphics.hpp>
#include <graphics/shaders.hpp>

/* C++ libraries */
#include <cassert>
#include <cstring>
#include <iostream>

/* Initialize vertex and fragment shader and combine them */
/* into the shader program                                */
void shaders_init() {
   vertex_shader_src = "#version 330 core\n"
   "layout(location = 0) in vec2 vec_pos;\n"

   "uniform mat4 model;\n"
   "uniform mat4 projection;\n"

   "void main() {\n"
      "gl_Position = projection * model * vec4(vec_pos.xy, 0.0, 1.0);\n"
   "}\0";

   fragment_shader_src = "#version 330 core\n"
   "out vec4 frag_color;\n"
   "uniform vec3 color;\n"
   "void main() {\n"
      "frag_color = vec4(color, 1.0);"
   "}\0";

   GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
   const char* const_vertex_shader_src = vertex_shader_src.c_str();
   glShaderSource(vertex_shader, 1, &const_vertex_shader_src, NULL);
   glCompileShader(vertex_shader);

   GLint vertex_shader_compilation_success;
   glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &vertex_shader_compilation_success);
   //assert(!vertex_shader_compilation_success);

   GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
   const char* const_fragment_shader_src = fragment_shader_src.c_str();
   glShaderSource(fragment_shader, 1, &const_fragment_shader_src, NULL);
   glCompileShader(fragment_shader);

   GLint fragment_shader_compilation_success;
   glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &fragment_shader_compilation_success);
   //assert(!fragment_shader_compilation_success);

   shader_program = glCreateProgram();
   glAttachShader(shader_program, vertex_shader);
   glAttachShader(shader_program, fragment_shader);
   glLinkProgram(shader_program);

   GLint shader_program_link_success;
   glGetProgramiv(shader_program, GL_LINK_STATUS, &shader_program_link_success);
   //assert(!shader_program_link_success);
}

/* Set 4x4 glm matrix in the shader program */
void shaders_set_mat4(glm::mat4 matrix, std::string uniform_name) {
   GLuint uniform_location = glGetUniformLocation(shader_program, uniform_name.c_str());
   glUniformMatrix4fv(uniform_location, 1, GL_FALSE, glm::value_ptr(matrix));
}

/* Set 3D glm vector in the shader program */
void shaders_set_vec3(glm::vec3 vector, std::string uniform_name) {
   GLuint uniform_location = glGetUniformLocation(shader_program, uniform_name.c_str());
   glUniform3fv(uniform_location, 1, glm::value_ptr(vector));
}