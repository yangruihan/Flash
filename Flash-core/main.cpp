#include <GLWF\glfw3.h>
#include <iostream>

#include "src\graphics\window.h"

int main()
{
    using namespace flash;
    using namespace graphics;

    Window window("hello world", 600, 400);

    while (!window.closed())
    {
        window.update();
    }

    system("PAUSE");

    return 0;
}