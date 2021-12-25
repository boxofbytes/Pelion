/*
								$									
							   #$$									
							  ##$$$									
							 ###$$$-								
							####$$$$-								
						   #####$$$$--								
						  ######$$$$---								
						 #######$$$$$---							
						########$$$$$----							
					   ########$$$$$$-----							
					  #######$$$$$$$-------							
					 #####$$$$$$$$$---------						
					#####$$$$$$$-------------						
				   ####$$$$$$-----------------						
				  ####$$$$---------------------						
				 ##$----------------------------
					   Pelion header file.
*/		

/* Include guard */
#ifndef PELION_HPP
#define PELION_HPP

/* C++ libraries */
#include <string>
#include <cstdint>
#include <cstddef>

/* Pelion namespace */
namespace Pelion {

   /* Shapes enum */
   enum Shapes {
      PELION_RECTANGLE,
      PELION_TRIANGLE,
      PELION_RIGHT_TRIANGLE
   };

   /* Keys enum */
   enum Keys {
      PELION_KEY_SPACE = 32,
      PELION_KEY_APOSTROPHE = 39,
      PELION_KEY_COMMA = 44,
      PELION_KEY_MINUS = 45,
      PELION_KEY_PERIOD = 46,
      PELION_KEY_SLASH = 47,
      PELION_KEY_0 = 48,
      PELION_KEY_1 = 49,
      PELION_KEY_2 = 50,
      PELION_KEY_3 = 51,
      PELION_KEY_4 = 52,
      PELION_KEY_5 = 53,
      PELION_KEY_6 = 54,
      PELION_KEY_7 = 55,
      PELION_KEY_8 = 56,
      PELION_KEY_9 = 57,
      PELION_KEY_SEMICOLON = 59,
      PELION_KEY_EQUAL = 61,
      PELION_KEY_A = 65,
      PELION_KEY_B = 66,
      PELION_KEY_C = 67,
      PELION_KEY_D = 68,
      PELION_KEY_E = 69,
      PELION_KEY_F = 70,
      PELION_KEY_G = 71,
      PELION_KEY_H = 72,
      PELION_KEY_I = 73,
      PELION_KEY_J = 74,
      PELION_KEY_K = 75,
      PELION_KEY_L = 76,
      PELION_KEY_M = 77,
      PELION_KEY_N = 78,
      PELION_KEY_O = 79,
      PELION_KEY_P = 80,
      PELION_KEY_Q = 81,
      PELION_KEY_R = 82,
      PELION_KEY_S = 83,
      PELION_KEY_T = 84,
      PELION_KEY_U = 85,
      PELION_KEY_V = 86,
      PELION_KEY_W = 87,
      PELION_KEY_X = 88,
      PELION_KEY_Y = 89,
      PELION_KEY_Z = 90,
      PELION_KEY_LEFT_BRACKET = 91,
      PELION_KEY_BACKSLASH = 92,
      PELION_KEY_RIGHT_BRACKET = 93,
      PELION_KEY_GRAVE_ACCENT = 96,
      PELION_KEY_ESCAPE = 256,
      PELION_KEY_ENTER = 257,
      PELION_KEY_TAB = 258,
      PELION_KEY_BACKSPACE = 259,
      PELION_KEY_INSERT = 260,
      PELION_KEY_DELETE = 261,
      PELION_KEY_RIGHT = 262,
      PELION_KEY_LEFT = 263,
      PELION_KEY_DOWN = 264,
      PELION_KEY_UP = 265,
      PELION_KEY_PAGE_UP = 266,
      PELION_KEY_PGAE_DOWN = 267,
      PELION_KEY_HOME = 268,
      PELION_KEY_END = 269,
      PELION_KEY_CAPS_LOCK = 280,
      PELION_KEY_SCROLL_LOCK = 281,
      PELION_KEY_NUM_LOCK = 282,
      PELION_KEY_PRINT_sCREEN = 283,
      PELION_KEY_PAUSE = 284,
      PELION_KEY_F1 = 290,
      PELION_KEY_F2 = 291,
      PELION_KEY_F3 = 292,
      PELION_KEY_F4 = 293,
      PELION_KEY_F5 = 294,
      PELION_KEY_F6 = 295,
      PELION_KEY_F7 = 296,
      PELION_KEY_F8 = 297,
      PELION_KEY_F9 = 298,
      PELION_KEY_F10 = 299,
      PELION_KEY_F11 = 300,
      PELION_KEY_F12 = 301,
      PELION_KEY_F13 = 302,
      PELION_KEY_F14 = 303,
      PELION_KEY_F15 = 304,
      PELION_KEY_NUMPAD_0 = 320,
      PELION_KEY_NUMPAD_1 = 321,
      PELION_KEY_NUMPAD_2 = 322,
      PELION_KEY_NUMPAD_3 = 323,
      PELION_KEY_NUMPAD_4 = 324,
      PELION_KEY_NUMPAD_5 = 325,
      PELION_KEY_NUMPAD_6 = 326,
      PELION_KEY_NUMPAD_7 = 327,
      PELION_KEY_NUMPAD_8 = 328,
      PELION_KEY_NUMPAD_9 = 329,
      PELION_KEY_NUMPAD_DECIMAL = 330,
      PELION_KEY_NUMPAD_DIVIDE = 331,
      PELION_KEY_NUMPAD_MULTIPLY = 332,
      PELION_KEY_NUMPAD_SUBTRACT = 333,
      PELION_KEY_NUMPAD_ADD = 334,
      PELION_KEY_NUMPAD_ENTER = 335,
      PELION_KEY_NUMPAD_EQUAL = 336,
      PELION_KEY_LEFT_SHIFT = 340,
      PELION_KEY_LEFT_CONTROL = 341,
      PELION_KEY_LEFT_ALT = 342,
      PELION_KEY_LEFT_SUPER = 343,
      PELION_KEY_RIGHT_SHIFT = 344,
      PELION_KEY_RIGHT_CONTROL = 345,
      PELION_KEY_RIGHT_ALT = 346,
      PELION_KEY_RIGHT_SUPER = 347,
      PELION_KEY_MENU = 348,
      PELION_KEY_UNKNOWN = -1
   };

   /* Pelion key states */
   enum KeyStates {
      PELION_KEYSTATE_RELEASED,
      PELION_KEYSTATE_PRESSED
   };

   /* 2D vector structure */
   struct Vec2 {
      double x, y = 0;
   };

   /* RGB structure */
   struct RGB {
      float r, g, b = 0;
   };

   /* Pelion object structure */
   struct Object {
      Shapes Shape = Pelion::PELION_RECTANGLE;
      RGB Color = {0, 0, 0};
      Vec2 Pivot = {0.5, 0.5};
      Vec2 Size = {0, 0};
      Vec2 Position = {0, 0};
      void Draw();
      float Angle = 0;
      bool Visible = true;
   };

   /* Window class */
   class Window {
      public:
         inline static int32_t Width = 800;
         inline static int32_t Height = 600;
         inline static uint32_t MSAASamples = 4;
         inline static bool Resizable = true;
         inline static std::string Title = "Pelion Window";
         inline static RGB Color = {255, 255, 255};
         Pelion::KeyStates GetKeyState(Pelion::Keys key);
         void Init();
         void Cleanup();
         void Render();
         bool Open();
         float Time(); 
   };
   
}

#endif
