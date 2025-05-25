#include "RenderSystem.h"
#include "Renderer.h"
#include "components/ModelComponent.h"
#include "Model.h"

void RenderSystem::Render(const entt::registry& registry, Renderer& renderer){
    renderer.RenderBeginFrame();

    auto view = registry.view<TransformComponent/*, ModelComponent*/>();
    
    view.each([&renderer](const TransformComponent& transform/*, const ModelComponent& model*/) {
        glm::mat4 modelMatrix = transform.GetModelMatrix();

        //renderer.Render(modelMatrix, *model.GetModel());
    });

    renderer.RenderEndFrame();
    //renderer.Render(); //delete once ecs is working
}