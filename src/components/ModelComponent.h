#pragma once
#include "../config.h"

class Model;

class ModelComponent{
    public:
        ModelComponent(std::shared_ptr<Model> m_pModel);
        ~ModelComponent();

        std::shared_ptr<Model> GetModel() const;

    private:
        std::shared_ptr<Model> m_pModel;  
};