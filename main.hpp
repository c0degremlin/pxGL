/*


*/

#ifndef _MAIN_HPP
#define _MAIN_HPP

#include "graphics.hpp"
#include "sprite.hpp"

#include <ctime>

void init();
void loop();
void shutdown();


Shader ourShader;

cGraphics gfx(720,320,"GLelda");
cTexture tex1, tex2;
cSprite sprite;

glm::mat4 trans;
glm::mat4 model;
glm::vec2 position;
glm::vec2 size;
GLfloat rotate;
glm::vec3 color;

    GLuint quadVAO;
    GLuint VBO;
    GLuint EBO;


#endif // _MAIN_HPP
