#include "TriangleMesh.h"
#include <glad/glad.h>
#include <vector>
#include <iostream>

TriangleMesh::TriangleMesh(){
    std::cout << "Start" << std::endl;
    std::vector<float> data = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, //x,y,z,r,g,b
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };
    m_vertexCount = 3;

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cout << "Error binding VBO: " << error << std::endl;
    }
    std::cout << "End2" << std::endl;

    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 24, (void*)0);
    //glEnableVertexAttribArray(0);

    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 24, (void*)12);
    //glEnableVertexAttribArray(1);


}

TriangleMesh::~TriangleMesh(){
    //glDeleteVertexArrays(1, &m_VAO);
    glDeleteBuffers(1, &m_VBO);
}

void TriangleMesh::Draw(){
    //glBindVertexArray(m_VAO);

    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);;

    //setup vertex position
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //setup vertex color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //draw
    glDrawArrays(GL_TRIANGLES, 0, m_vertexCount);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

