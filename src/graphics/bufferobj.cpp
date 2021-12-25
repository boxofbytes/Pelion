/* Source file for OpenGL buffer object related things. */
/*------------------------------------------------------*/

/* Pelion headers */
#include <Pelion.hpp>
#include <graphics.hpp>
#include <graphics/bufferobj.hpp>

/* Variables */
GLuint vertex_array_object;

/* Function that returns the current VAO */
GLuint get_vao() {
   return vertex_array_object;
}

/* Function that initializes the VBO, VAO, vertex attributes... */
void bufferobj_init() {
   GLuint vertex_buffer_object;
   glGenBuffers(1, &vertex_buffer_object);
   glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_object);
   glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

   glGenVertexArrays(1, &vertex_array_object);
   glBindVertexArray(vertex_array_object);

   glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (void*)0);
   glEnableVertexAttribArray(0);
}