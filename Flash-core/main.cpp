#include "src/graphics/window.h"
#include "src/math/math.h"
#include "src/util/file_util.hpp"

int main()
{
    using namespace flash;
    using namespace graphics;
    using namespace math;
    using namespace util;
    using namespace std;

    Window window("hello world", 600, 400);

    double x, y;
    vector2 v;

    vector2 v1(1, 3);
    vector2 v2(2, 4);

    while (!window.closed())
    {
        window.getMousePos(x, y);
        v.x = x;
        v.y = y;
        std::cout << v;

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