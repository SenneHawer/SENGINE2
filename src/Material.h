#include "config.h"

class Material{
    public:
    Material(const char* filename);
    ~Material();

    void Use();

    private:
    unsigned int m_texture;
};