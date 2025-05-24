#include "RenderSystem.h"
#include "Renderer.h"

void RenderSystem::Render(const entt::registry& registry, Renderer& renderer){
    auto view = registry.view<TransformComponent>();

    for (auto entity : view) {
        auto& transform = view.get<TransformComponent>(entity);
        

        renderer.Render(transform.GetModelMatrix());
    }
    //renderer.Render(); //delete once ecs is working
}