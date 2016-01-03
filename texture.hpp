/*



*/
#ifndef _TEXTURE_HPP
#define _TEXTURE_HPP

#include <iostream> // for errors
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>


class cTexture
{
public:
    cTexture();
    ~cTexture();
    void load( std::string file, GLboolean alpha = false);
    void use() { glBindTexture(GL_TEXTURE_2D, mTexture); }
    inline GLuint getTextureID() { return mTexture; }
private:

    // Holds the ID of the texture object, used for all texture operations to reference to this particular texture
    GLuint mTexture;

    // Texture image dimensions
    GLint mWidth;
    GLint mHeight;

    // Texture Format
    GLint Internal_Format; // Format of texture object
    GLint Image_Format; // Format of loaded image

    // Texture configuration
    GLuint Wrap_S; // Wrapping mode on S axis
    GLuint Wrap_T; // Wrapping mode on T axis
    GLuint Filter_Min; // Filtering mode if texture pixels < screen pixels
    GLuint Filter_Max; // Filtering mode if texture pixels > screen pixels


    std::string mFilename;

    GLboolean isLoaded;
    GLboolean hasAlpha;
};
#endif // _TEXTURE_HPP
