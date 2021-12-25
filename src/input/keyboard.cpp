/* Source file for keyboard input detection. */
/*-------------------------------------------*/

/* Pelion headers */
#include <Pelion.hpp>
#include <graphics.hpp>
#include <input/keyboard.hpp>
#include <window/window.hpp>

/* Functions */
Pelion::KeyStates Pelion::Window::GetKeyState(Pelion::Keys key) {
    return (Pelion::KeyStates)glfwGetKey(get_window(), key);
}
