/* Header file for platform specific header files. */
/*-------------------------------------------------*/

/* Include guard */
#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

/* Definition for additional OpenGL functions */
#define GL_GLEXT_PROTOTYPES

/* Header files for OpenGL tools */
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/* Platform specific stuff */
#if defined(WIN32) || defined(_WIN32) || defined(__WIN__32) || defined(__NT__)
   #include <Windows.h>
   #include <GL/gl.h>
#elif __APPLE__
   #include <OpenGL/gl.h>
#elif __linux__ || __unix__
   #include <GL/gl.h>
#endif

#endif