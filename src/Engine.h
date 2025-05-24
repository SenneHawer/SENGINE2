#include "config.h"
#include "Window.h"
#include "Renderer.h"
#include "Scene.h"
#include "glm/glm.hpp"

class Engine{
    public:
        Engine();
        ~Engine();

        void Init();
        void Run();
        
    private:

        //void setupEntities();
        void Update();

        //entt::registry m_registry;
        

        Window* m_pWindow;
        Renderer* m_pRenderer;
        Scene* m_pScene;

};