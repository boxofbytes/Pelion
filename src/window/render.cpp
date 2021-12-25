/* Source file for rendering Pelion objects. */
/*-------------------------------------------*/

/* Pelion headers */
#include <Pelion.hpp>
#include <graphics.hpp>
#include <window/window.hpp>
#include <window/render.hpp>
#include <graphics/bufferobj.hpp>
#include <graphics/shaders.hpp>

/* C++ libraries */
#include <iostream>
#include <vector>
#include <functional>
#include <memory>

/* Variables */
glm::mat4 orthographic_projection;
int32_t width, height = 0;

/* Function for rendering a Pelion object */
void Pelion::Object::Draw() {
   if(this->Visible) {
      float angle = this->Angle;

      glm::vec3 size = glm::vec3(
         this->Size.x,
         this->Size.y,
         1.0f
      );
      glm::vec3 position = glm::vec3(
         (width / 2) - (size.x / 2) + this->Position.x,
         (height / 2) - (size.y / 2) + -this->Position.y,
         0.0f
      );
      glm::vec3 color = glm::vec3(
         this->Color.r / 255,
         this->Color.g / 255,
         this->Color.b / 255
      );

      glm::mat4 model = glm::mat4(1.0f);
      model = glm::translate(model, position);
      model = glm::translate(model, glm::vec3(this->Pivot.x * size.x, this->Pivot.y  * size.y, 0.0f));
      model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
      model = glm::translate(model, glm::vec3(-this->Pivot.x * size.x, -this->Pivot.y * size.y, 0.0f));
      model = glm::scale(model, size);

      shaders_set_mat4(model, "model");
      shaders_set_vec3(color, "color");

      switch(this->Shape) {
         case Pelion::PELION_RECTANGLE : glDrawArrays(GL_TRIANGLE_STRIP, 0, 4); break;
         case Pelion::PELION_TRIANGLE : glDrawArrays(GL_TRIANGLES, 4, 3); break;
         case Pelion::PELION_RIGHT_TRIANGLE : glDrawArrays(GL_TRIANGLES, 7, 3); break;
      }
   }
}

/* Function for rendering the current Pelion window */
void Pelion::Window::Render() {
   glfwPollEvents();
   glfwSwapBuffers(get_window());

   glClearColor(Pelion::Window::Color.r / 255, 
   Pelion::Window::Color.g / 255,
   Pelion::Window::Color.b / 255, 1);
   glClear(GL_COLOR_BUFFER_BIT);

   glBindVertexArray(get_vao());
   glUseProgram(shader_program);

   glfwGetWindowSize(get_window(), &Pelion::Window::Width, &Pelion::Window::Height);
   orthographic_projection = glm::mat4(1.0f);
   orthographic_projection = glm::ortho(0.0f, float(Pelion::Window::Width), float(Pelion::Window::Height), 0.0f, -1.0f, 1.0f);
   shaders_set_mat4(orthographic_projection, "projection");

   width = Pelion::Window::Width;
   height = Pelion::Window::Height;
}
