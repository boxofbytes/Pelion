/* Header file for OpenGL buffer object related stuff. */
/*-----------------------------------------------------*/

/* Include guard */
#ifndef BUFFEROBJ_HPP
#define BUFFEROBJ_HPP

/* Pelion headers */
#include <graphics.hpp>

/* Variables */
inline GLfloat vertices[] = {
    /* Position  |  Texture */
    /* Coords    |  Coords */

    /*     Rectangle     */
    1.0f, 1.0f, //1.0f, 1.0f,
    0.0f, 1.0f, //0.0f, 1.0f,
    1.0f, 0.0f, //1.0f, 0.0f,
    0.0f, 0.0f, //0.0f, 0.0f, 

    /*     Triangle    */
    0.0f, 1.0f, //0.0f, 1.0f,
    1.0f, 1.0f, //1.0f, 1.0f,
    0.5f, 0.0f, //0.5f, 0.0f

    /*   Half-Triangle    */
    0.0f, 1.0f, //0.0f, 1.0f,
    1.0f, 1.0f, //1.0f, 1.0f,
    0.0f, 0.0f, //0.5f, 0.0f
};

/* Functions */
GLuint get_vao();
void bufferobj_init();

#endif