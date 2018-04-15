#include "src/graphics/window.h"

int main()
{
    using namespace flash;
    using namespace graphics;

    Window window("hello world", 600, 400);

    double x, y;

    while (!window.closed())
    {
        window.getMousePos(x, y);
        std::cout << "(" << x << ", " << y << ")" << std::endl;

        window.clear();
        glBegin(GL_TRIANGLES);
        glVertex2f(-1, -1);
        glVertex2f(0, 1);
        glVertex2f(1, -1);
        glEnd();
        window.update();
    }

    return 0;
}