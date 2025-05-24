#include "config.h"

class Renderer;

class Scene{
    public:
        Scene();
        ~Scene();

        void Init();
        void Update();
        
        //void AddEntity(const std::string& name);
        //void RemoveEntity(const std::string& name);

        const entt::registry& GetRegistry();

    private:

        entt::registry m_registry;

    //test
        void createEntities();
};