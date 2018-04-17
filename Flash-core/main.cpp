#include "src/graphic/window.hpp"
#include "src/graphic/shader.hpp"
#include "src/math/math.h"
#include "src/util/file_util.hpp"

int main()
{
    using namespace flash;
    using namespace graphic;
    using namespace math;
    using namespace util;
    using namespace std;

    Window window("hello world", 600, 400);

    double x, y;
    vector2 v;

    Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
    shader.enable();

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