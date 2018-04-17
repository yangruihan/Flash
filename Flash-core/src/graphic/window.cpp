#include "window.hpp"

namespace flash
{
    namespace graphic
    {
        bool    Window::m_Keys[MAX_KEY_COUNT];
        bool    Window::m_MouseButtons[MAX_MOUSE_BUTTON_COUNT];
        double  Window::m_MouseX;
        double  Window::m_MouseY;

        Window::Window(const char *title, int width, int height)
        {
            m_Title = title;
            m_Width = width;
            m_Height = height;

            // init key flag
            for (size_t i = 0; i < MAX_KEY_COUNT; i++)
                m_Keys[i] = false;

            // init mouse button flag
            for (size_t i = 0; i < MAX_MOUSE_BUTTON_COUNT; i++)
                m_MouseButtons[i] = false;

            m_MouseX = 0.0;
            m_MouseY = 0.0;

            if (!init())
                glfwTerminate();
        }

        Window::~Window()
        {
            glfwTerminate();
        }

        void Window::update() const
        {
            glfwPollEvents();
            glfwSwapBuffers(m_Window);
        }

        void Window::clear() const
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        bool Window::closed() const
        {
            return glfwWindowShouldClose(m_Window) == 1;
        }

        bool Window::isKeyPressed(unsigned int keyCode) const
        {
            if (keyCode > MAX_KEY_COUNT)
                return false;

            return m_Keys[keyCode];
        }

        bool Window::isMouseButtonPressed(unsigned int mouseCode) const
        {
            if (mouseCode > MAX_MOUSE_BUTTON_COUNT)
                return false;

            return m_MouseButtons[mouseCode];
        }

        bool Window::init()
        {
            if (!glfwInit())
            {
                std::cout << "Window init error: Failed to init GLFW" << std::endl;
                return false;
            }

            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
            if (!m_Window)
            {
                glfwTerminate();
                std::cout << "Window init error: Failed to create GLFW window!" << std::endl;
                return false;
            }
            glfwMakeContextCurrent(m_Window);
            glfwSetWindowSizeCallback(m_Window, window_resize);
            glfwSetKeyCallback(m_Window, key_callback);

            glfwSetCursorPosCallback(m_Window, cursor_position_callback);

            if (glewInit() != GLEW_OK)
            {
                std::cout << "Window init error: Failed to init GLEW" << std::endl;
                return false;
            }

            return true;
        }

        static void window_resize(GLFWwindow *window, int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key > MAX_KEY_COUNT)
            {
                std::cout << "Key callback error: keycode out of MAX_KEY_COUNT " << MAX_KEY_COUNT << std::endl;
                return;
            }

            Window::m_Keys[key] = action != GLFW_RELEASE;
        }

        static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
        {
            if (button > MAX_KEY_COUNT)
            {
                std::cout << "Mouse button callback error: keycode out of MAX_MOUSE_BUTTON_COUNT " << MAX_MOUSE_BUTTON_COUNT << std::endl;
                return;
            }

            Window::m_MouseButtons[button] = action != GLFW_RELEASE;
        }

        static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
        {
            Window::m_MouseX = xpos;
            Window::m_MouseY = ypos;
        }
    }
}