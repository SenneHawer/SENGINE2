#include "config.h"
#include "TriangleMesh.h"
#include "Material.h"

class Renderer{
    public:
        Renderer();
        ~Renderer();

        void Init();
        void Render(glm::mat4 modelMatrix);

    private:
        unsigned int m_shader;

        TriangleMesh* m_pTriangle;
        Material* m_pMaterial;
        Material* m_pMask;
        
        unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
        unsigned int make_module(const std::string& filepath, unsigned int module_type);

};
        