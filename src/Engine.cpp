#include "Engine.h"

Engine::Engine()
:m_pWindow(nullptr)  
{
    m_pWindow = new Window(500, 500, "SENGINE@TEST");
    m_pRenderer = new Renderer();
}

Engine::~Engine(){
    delete m_pWindow;
    m_pWindow = nullptr;
    delete m_pRenderer;
    m_pRenderer = nullptr;
}


void Engine::Init(){
    m_pWindow->Init();

    m_pRenderer->Init();

    
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

    m_pRenderer->Render();

    m_pWindow->SwapBuffers();
}
