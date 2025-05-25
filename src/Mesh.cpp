#include "Mesh.h"

Mesh::Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices)
: m_vertices(vertices),
  m_indices(indices) {
    SetupMesh();
}

Mesh::~Mesh() {
    glDeleteBuffers(1, &m_VBO);
    glDeleteBuffers(1, &m_EBO);
}

void Mesh::SetupMesh() {
    glGenBuffers(1, &m_VBO);
    if (m_VBO == 0) {
        std::cerr << "Failed to generate VBO!" << std::endl;
    }

    //Load vertex data
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), m_vertices.data(), GL_STATIC_DRAW);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error binding VBO: " << error << std::endl;
    }
    m_vertexCount = static_cast<unsigned int>(m_vertices.size());

    glGenBuffers(1, &m_EBO);
    if (m_EBO == 0) {
        std::cerr << "Failed to generate EBO!" << std::endl;
    }
    //Load index data
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);
    error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error binding EBO: " << error << std::endl;
    }

    //Position attribute
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));
    
    //Normal attribute
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    
    //Texture coordinate attribute
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
}

void Mesh::Draw() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    
//Position attribute
glEnableVertexAttribArray(0);
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

//Normal attribute
glEnableVertexAttribArray(1);
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

//Texture coordinate attribute
glEnableVertexAttribArray(2);
glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));

//std::cout << "Index count: " << m_indices.size() << ", VBO: " << m_VBO << ", EBO: " << m_EBO << std::endl;

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(m_indices.size()), GL_UNSIGNED_INT, 0);
    //glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);


    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error drawing mesh: " << error << std::endl;
    }
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
}
