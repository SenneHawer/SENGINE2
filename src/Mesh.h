#pragma once
#include "config.h"

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

class Mesh{

    public:
        Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
        ~Mesh();

        void Draw() const;

    private:
        unsigned int m_EBO, m_VBO;
        unsigned int m_vertexCount;

        std::vector<Vertex> m_vertices;
        std::vector<unsigned int> m_indices;
        
        void SetupMesh();

};