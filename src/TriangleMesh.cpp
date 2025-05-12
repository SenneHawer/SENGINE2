#include "TriangleMesh.h"
#include <glad/glad.h>
#include <iostream>

TriangleMesh::TriangleMesh(){
    std::vector<float> positions = {
        -1.f, -1.f, 0.0f, 
        1.f, -1.f, 0.0f, 
        -1.f, 1.f, 0.0f,
        1.f, 1.f, 0.0f
    };
    std::vector<float> colorIndices = {
        0, 1, 2, 3
    }; 
    std::vector<GLuint> elementIndicis = {
        0, 1, 2, 2, 1, 3
    }; 

    m_vertexCount = 6;

    m_VBOList.resize(2);

    glGenBuffers(2, m_VBOList.data());

    //positions
    glBindBuffer(GL_ARRAY_BUFFER, m_VBOList[0]);
    glBufferData(GL_ARRAY_BUFFER, positions.size() * sizeof(float), positions.data(), GL_STATIC_DRAW);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error binding VBO: " << error << std::endl;
    }

    //colors
    glBindBuffer(GL_ARRAY_BUFFER, m_VBOList[1]);
    glBufferData(GL_ARRAY_BUFFER, colorIndices.size() * sizeof(float), colorIndices.data(), GL_STATIC_DRAW);
    error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error binding VBO2: " << error << std::endl;
    }
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    //glEnableVertexAttribArray(0);

    //elements
    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementIndicis.size() * sizeof(float), elementIndicis.data(), GL_STATIC_DRAW);
    error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error binding VBO3: " << error << std::endl;
    }
    //glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0);
    //glEnableVertexAttribArray(1);

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
    //glEnableVertexAttribArray(0);

    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)12);
    //glEnableVertexAttribArray(1);

}

TriangleMesh::~TriangleMesh(){
    //glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(2, m_VBOList.data());
    glDeleteBuffers(1, &m_EBO);
}

void TriangleMesh::Draw(){
    //glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBOList[0]);

    //setup vertex position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBOList[1]);

    //setup vertex color
    glVertexAttribPointer(1, 1, GL_FLOAT, GL_FALSE, sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

    //elements
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);

    //draw
    //glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);
    glDrawElements(GL_TRIANGLES, m_vertexCount, GL_UNSIGNED_INT, 0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}