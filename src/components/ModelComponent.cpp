#include "ModelComponent.h"
#include "../Model.h"

ModelComponent::ModelComponent(std::shared_ptr<Model> pModel)
: m_pModel(pModel) {
    if (!m_pModel) {
        std::cerr << "ModelComponent: Model pointer is null!" << std::endl;
    }
}

ModelComponent::~ModelComponent() {
}

std::shared_ptr<Model> ModelComponent::GetModel() const {
    if (m_pModel) {
        return m_pModel;
    } else {
        std::cerr << "ModelComponent: Model pointer is null!" << std::endl;
        return nullptr;
    }
}


