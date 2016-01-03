#include "graphics.hpp"

cGraphics::cGraphics() // default 800 x 600 x 32 windowed with title 'pxGL engine'
{
    isFullScreen = false; // windowed
    isVsync = false; // tearing on

    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create a GLFWwindow object that we can use for GLFW's functions
    mWindow = glfwCreateWindow(800, 600, "pxGL engine", nullptr, nullptr);
    if (mWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(mWindow); // Use the window we just created

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
    }

    // Use the whole screen
    glViewport(0, 0, 800, 600);

    // Turn on/off vsync
    glfwSwapInterval(isVsync);
}

cGraphics::cGraphics(GLint width, GLint height, std::string title)
{

    isFullScreen = false; // windowed
    isVsync = false; // tearing on

    mWidth = width;
    mHeight = height;
    mTitle = title;

    // Init GLFW
    glfwInit();
    // Set all the required options for GLFW
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // turn off maximize button

    // Turn on face culling and alpha blending ( for 2d )
    glEnable(GL_CULL_FACE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Create a GLFWwindow object that we can use for GLFW's functions
    if(!isFullScreen)
    {
    mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), nullptr, nullptr);
    if (mWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }
    }
    else // Fullscreen
{
    mWindow = glfwCreateWindow(mWidth, mHeight, mTitle.c_str(), glfwGetPrimaryMonitor(), nullptr);
    if (mWindow == nullptr)
    {
        std::cout << "Failed to create GLFW window fullscreen" << std::endl;
        glfwTerminate();
    }
    }
    glfwMakeContextCurrent(mWindow); // Use the window we just created

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
    }

    // Use the whole screen
    glViewport(0, 0, mWidth, mHeight);

    // Turn on vsync
    glfwSwapInterval(isVsync);

}

cGraphics::~cGraphics()
{
    // clear glfw resources
    glfwTerminate();
}

void cGraphics::clearBuffer(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
}

void cGraphics::clearBuffer(const GLfloat rgba[4])
{
        glClearColor(rgba[0],rgba[1],rgba[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
}
