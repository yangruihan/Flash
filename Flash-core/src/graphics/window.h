#pragma once

#include <iostream>
#include <GLWF\glfw3.h>

namespace flash
{
    namespace graphics
    {
        class Window
        {
        private:
            const char *m_Title;
            int m_Width, m_Height;
            GLFWwindow *m_Window;
            bool m_Closed;
            
        public:
            Window(const char *title, int width, int height);
            ~Window();
            void update() const;
            bool closed() const;

        private:
            bool init();
        };
    }
}