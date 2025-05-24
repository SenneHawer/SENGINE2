#include "config.h"

class Renderer;

class RenderSystem{

    public:

    static void Render(const entt::registry& registry, Renderer& renderer);

};