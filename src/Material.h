#include "config.h"

class Material{
    public:
    Material(const char* filename);
    ~Material();

    void Use(int unit);

    private:
    unsigned int m_texture;
};