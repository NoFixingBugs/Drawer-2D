#include "SceneWindow.h"

namespace Drawer
{
    SceneWindow::SceneWindow(const char *windowTitle, unsigned int windowWidth, unsigned int windowHeight)
    {
        m_windowTitle = windowTitle;
        m_windowWidth = windowWidth;
        m_windowHeight = windowHeight;
    }
    void SceneWindow::initialize()
    {
        //Initialize GLFW.
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

        //Creating GFLW window.
        window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_windowTitle, NULL, NULL);
        if (window == NULL)
        {
            std::cout << "Failed to creating GLFW Window!" << std::endl;
            glfwTerminate();
        }
        glfwMakeContextCurrent(window);
        glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

        //Setting up GLAD to load all function pointers.
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD" << std::endl;
            glfwTerminate();
        }

        //The Render loop
        while (!glfwWindowShouldClose(window))
        {
            //Process the input from user (e.g. keyboard, mouse, etc.).
            processingInput(window);

            //Render here
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT);

            //Swap the buffers and poll input output events (e.g. keyboard, mouse, etc.).
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }
    void frameBufferSizeCallback(GLFWwindow *window, int width, int height)
    {
        /*
            Make sure the viewport matches the new window dimensions.
            NOTE: That width and height will be significantly larger than specified on retina displays.
        */
        glViewport(0, 0, width, height);
    }
    void SceneWindow::processingInput(GLFWwindow *window)
    {
        if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        {
            r = 1;
            b = 0;
            g = 0;
            a = 0;
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        {
            r = 0;
            b = 0;
            g = 0;
            a = 0;
        }
    }
} // namespace Drawer
