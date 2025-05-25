#include "config.h"
#include "TriangleMesh.h"
#include "Material.h"
#include "Window.h"

class Model;

class Renderer{
    public:
        Renderer();
        ~Renderer();

        void Init( const Window& window);
        void RenderBeginFrame();
        void Render(const glm::mat4& modelMatrix, const Model& model);
        void RenderEndFrame();
    private:
        unsigned int m_shader;

        //TriangleMesh* m_pTriangle;
        Material* m_pMaterial;
        Material* m_pMask;

        float m_aspectRatio;
        
        unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
        unsigned int make_module(const std::string& filepath, unsigned int module_type);

};
        