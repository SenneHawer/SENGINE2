#include "config.h"
#include "Window.h"
#include "Renderer.h"

class Engine{
    public:
        Engine();
        ~Engine();

        void Init();
        void Run();
        
    private:

        void Update();

        Window* m_pWindow;
        Renderer* m_pRenderer;

};