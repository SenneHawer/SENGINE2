#include "Engine.h"
#include "RenderSystem.h"

Engine::Engine()
:m_pWindow(nullptr)  
{
    m_pWindow = new Window(500, 500, "SENGINE@TEST");
    m_pRenderer = new Renderer();
    m_pScene = new Scene();
}

Engine::~Engine(){
    delete m_pWindow;
    m_pWindow = nullptr;
    delete m_pRenderer;
    m_pRenderer = nullptr;
    delete m_pScene;
    m_pScene = nullptr;
}


void Engine::Init(){

    m_pWindow->Init();    
    m_pRenderer->Init();

    m_pScene->Init();
}

void Engine::Run(){
    while (!m_pWindow->isShouldClose()){
        Update();
    }

    glfwTerminate();
}

void Engine::Update(){
    m_pWindow->PollEvents();
    m_pWindow->Update();

    m_pScene->Update();

    //m_pRenderer->Render();
    RenderSystem::Render(m_pScene->GetRegistry(), *m_pRenderer);

    m_pWindow->SwapBuffers();
}
