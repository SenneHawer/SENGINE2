#include "Scene.h"

Scene::Scene(){

}

Scene::~Scene(){

}

void Scene::Init(){
    createEntities();
}

void Scene::Update(){
    //transform system update

}

const entt::registry& Scene::GetRegistry(){
    return m_registry;
}

void Scene::createEntities(){
    auto entity = m_registry.create();
    auto& transform = m_registry.emplace<TransformComponent>(entity);
    transform.position = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
}

