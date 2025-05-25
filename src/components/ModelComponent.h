#pragma once
#include "../config.h"

class Model;

class ModelComponent{
    public:
        ModelComponent() = default;
        ~ModelComponent() = default;

        void SetModel(const std::shared_ptr<Model>& pModel) {
            m_pModel = pModel;
        }

        std::shared_ptr<Model> GetModel() const {
            return m_pModel;
        }

    private:
        std::shared_ptr<Model> m_pModel;      
};