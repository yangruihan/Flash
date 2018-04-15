#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define MAX_KEY_COUNT           1024
#define MAX_MOUSE_BUTTON_COUNT  3

namespace flash
{
    namespace graphics
    {
        static void window_resize(GLFWwindow *window, int width, int height);
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

        /**
         * The class for window
         */
        class Window
        {
        private:
            const char *m_Title;
            int m_Width, m_Height;
            GLFWwindow *m_Window;
            bool m_Closed;
            
            static bool m_Keys[MAX_KEY_COUNT];
            static bool m_MouseButtons[MAX_MOUSE_BUTTON_COUNT];
            static double m_MouseX, m_MouseY;

        public:
            Window(const char *title, int width, int height);
            ~Window();

            void update() const;
            void clear() const;
            bool closed() const;

            bool isKeyPressed(unsigned int keyCode) const;
            bool isMouseButtonPressed(unsigned int mouseCode) const;

            inline int getWidth() const { return m_Width; }
            inline int getHeight() const { return m_Height; }

            inline double getMouseX() const { return m_MouseX; }
            inline double getMouseY() const { return m_MouseY; }
            inline void getMousePos(double& x, double& y) const { x = m_MouseX; y = m_MouseY; }

        private:
            bool init();

            friend static void window_resize(GLFWwindow *window, int width, int height);
            friend static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
            friend static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
            friend static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
        };
    }
}