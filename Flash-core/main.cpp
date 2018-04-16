#include "src/graphics/window.h"
#include "src/math/math.h"

int main()
{
    using namespace flash;
    using namespace graphics;
    using namespace math;

    Window window("hello world", 600, 400);

    double x, y;
    vector2 v;

    vector2 v1(1, 3);
    vector2 v2(2, 4);

    std::cout << v1 + v2 << " " << v1 << v2;
    std::cout << v1 - v2 << " " << v1 << v2;
    std::cout << v1 * v2 << " " << v1 << v2;
    std::cout << v1 / v2 << " " << v1 << v2;

    matrix4 position = matrix4::translation(vector3(2, 3, 4));
    position *= matrix4::identity();

    while (!window.closed())
    {
        window.getMousePos(x, y);
        v.setX(x);
        v.setY(y);
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