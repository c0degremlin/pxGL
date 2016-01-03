/*


*/

#ifndef _GL_GRAPHICS_H
#define _GL_GRAPHICS_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

// Math headers
#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "helper.hpp"
#include "shader.hpp"

// Color defines

class cGraphics
{
public:
    cGraphics();
    cGraphics(GLint width, GLint height, std::string title);
    ~cGraphics();

    // Buffer functions
    void flipBuffer() { glfwSwapBuffers(mWindow); }
    void clearBuffer(GLfloat r, GLfloat g, GLfloat b, GLfloat a = 1.0f); // Specify clear color
    void clearBuffer(const GLfloat rgba[3]);
    void flipVsync() { isVsync = !isVsync; glfwSwapInterval(isVsync); }
    void flipWireFrame() { isWireFrame = !isWireFrame; if( isWireFrame) { } else { } }

    // Accesors
    GLFWwindow* getWindowPtr() { return mWindow; }

private:
    GLFWwindow* mWindow;
    GLint mWidth;
    GLint mHeight;
    GLint mBPP;

    std::string mTitle;
    GLboolean isFullScreen;
    GLboolean isVsync;
    GLboolean isWireFrame;
};

#endif // _GL_GRAPHICS_H
