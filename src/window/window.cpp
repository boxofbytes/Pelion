/* Source file for creating and initializing a window. */
/*-----------------------------------------------------*/

/* Pelion headers */
#include <Pelion.hpp>
#include <graphics.hpp>
#include <window/window.hpp>
#include <graphics/shaders.hpp>
#include <graphics/bufferobj.hpp>

/* C++ libraries */
#include <string>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include <cstring>
#include <iostream>

/* Variables */
static GLFWwindow* main_window = 0;
static bool window_is_open = false;
static bool glfw_initialized = false;

/* Function for initializing GLFW window hints */
inline void window_hints(uint32_t msaa_sampling, bool resizable) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    glfwWindowHint(GLFW_RESIZABLE, resizable);
    glfwWindowHint(GLFW_SAMPLES, msaa_sampling);
}

/* Resize function */
void resize_callback(GLFWwindow* window_argument, int32_t width, int32_t height) {
    glViewport(0, 0, width, height);
}

/* Window class constructor */
void Pelion::Window::Init() {
    glfwDestroyWindow(main_window);
    if(!glfw_initialized)
        assert(glfwInit());
    glfw_initialized = true;

    window_hints(Pelion::Window::MSAASamples, Pelion::Window::Resizable);

    main_window = glfwCreateWindow(Pelion::Window::Width, Pelion::Window::Height, Pelion::Window::Title.c_str(), NULL, NULL);
    assert(main_window != NULL);
    window_is_open = true;
 
    glfwSetFramebufferSizeCallback(main_window, resize_callback);
    glfwMakeContextCurrent(main_window);
    glViewport(0, 0, Pelion::Window::Width, Pelion::Window::Height);

    bufferobj_init();
    shaders_init();

    glEnable(GL_MULTISAMPLE);
}

/* Function for getting the window connected to the current context */
GLFWwindow* get_window() {
    return main_window;
}

/* Function for checking if current window is open */
bool Pelion::Window::Open() {
    return !glfwWindowShouldClose(get_window());
}

/* Function for cleaning up the window */
void Pelion::Window::Cleanup() {
    if(glfw_initialized) {
        glfwSetWindowShouldClose(get_window(), true);
        glfwMakeContextCurrent(0);
    }
    glfwDestroyWindow(get_window());
}

/* Function that returns time in miliseconds since */
/* window has been created                         */
float Pelion::Window::Time() {
    return glfwGetTime();
}