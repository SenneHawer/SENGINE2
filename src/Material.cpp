#include "Material.h"
#include "stb_image.h"

Material::Material(const char* filename){
    int width, height, channels;
    unsigned char* data = stbi_load(filename, &width, &height, &channels, STBI_rgb_alpha);
    if (!data) {
        std::cerr << "Failed to load texture: " << filename << std::endl;
        return;
    }
    
    // Generate texture
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    //Upload texture data
    glTexImage2D(GL_TEXTURE_2D,
    0, GL_RGBA, width, height, 0,
    GL_RGBA, GL_UNSIGNED_BYTE, data);



    //free data
    stbi_image_free(data);

}

Material::~Material(){
    glDeleteTextures(1, &m_texture);
    
}

void Material::Use(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, m_texture);

}