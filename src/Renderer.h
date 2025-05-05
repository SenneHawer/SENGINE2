#include "config.h"
#include "TriangleMesh.h"

class Renderer{
    public:
        Renderer();
        ~Renderer();

        void Init();
        void Render();

    private:
        unsigned int m_shader;

        TriangleMesh* m_pTriangle;
        
        unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
        unsigned int make_module(const std::string& filepath, unsigned int module_type);

};
        