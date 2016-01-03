/******************************************************************/
#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#define GLM_FORCE_RADIANS

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "texture.hpp"
#include "shader.hpp"


class cSprite
{
public:
    cSprite();
    ~cSprite();

    void init();
    void draw();
    // Renders a defined quad textured with given sprite
    void DrawSprite(cTexture &texture, glm::vec2 position, glm::vec2 size = glm::vec2(10, 10), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
    GLuint quadVAO;
    GLuint VBO;
    GLuint EBO;

    // Initializes and configures the quad's buffer and vertex attributes

};

#endif
