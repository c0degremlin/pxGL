#include "texture.hpp"


cTexture::cTexture()
{
    mWidth = mHeight = 0;
    Internal_Format = Image_Format = 0;

    Wrap_S = GL_REPEAT;
    Wrap_T = GL_REPEAT;

    Filter_Min = GL_LINEAR;
    Filter_Max = GL_LINEAR;
}

cTexture::~cTexture()
{
    glDeleteTextures( 1, &mTexture );
}

void cTexture::load(std::string file, GLboolean alpha)
{
    mFilename = file;
    hasAlpha = alpha;

    if (this->hasAlpha)
    {
        this->Internal_Format = GL_RGBA;
        this->Image_Format = GL_RGBA;
    }
    else
    {
        this->Internal_Format = GL_RGB;
        this->Image_Format = GL_RGB;
    }



    glGenTextures(1, &mTexture);
    glBindTexture(GL_TEXTURE_2D, mTexture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
    // Set our texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // Set texture filtering
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load, create texture and generate mipmaps
    unsigned char *image = SOIL_load_image(mFilename.c_str(), &mWidth, &mHeight, 0, SOIL_LOAD_RGB);


    // check for an error during the load process
    if(image == 0)
	    std::cout << "SOIL loading error: " << SOIL_last_result() << std::endl;
    else
        this->isLoaded = true;

    std::cout << &image << std::endl;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    glGenerateMipmap(GL_TEXTURE_2D);
    SOIL_free_image_data(image);
    glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.

}
