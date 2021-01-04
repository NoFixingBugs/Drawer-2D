#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

namespace Drawer
{
    void frameBufferSizeCallback(GLFWwindow *window, int width, int height);

    class SceneWindow
    {
    public:
        SceneWindow(const char *windowTitle, unsigned int windowWidth, unsigned int windowHeight);
        void initialize();

    private:
        GLFWwindow *window = nullptr;
        void processingInput(GLFWwindow *window);
        const char *m_windowTitle;
        unsigned int m_windowWidth;
        unsigned int m_windowHeight;

        float r, g, b, a;
    };
} // namespace Drawer
