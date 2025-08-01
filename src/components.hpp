#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>



struct TransformComponent{
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;


    glm::mat4& GetModelMatrix() const {
        if (isDirty) {
            RecalculateModelMatrix();
        }
        return modelMatrix;
    }

    private:
    mutable glm::mat4 modelMatrix;
    mutable bool isDirty{true};

     void RecalculateModelMatrix() const {
        modelMatrix = glm::mat4(1.0f);
        modelMatrix = glm::translate(modelMatrix, position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        modelMatrix = glm::scale(modelMatrix, scale);

        isDirty = false;
    }
};

//struct ModelComponent {
    //std::shared_ptr<Model> model;
//};