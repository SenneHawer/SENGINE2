#include "Window.h"

Window::Window()
:m_width(640),
m_height(480),
m_title("SENGINE2"){

}

Window::~Window(){
    glfwDestroyWindow(m_pWindow);
    m_pWindow = nullptr;
    glfwTerminate();
}

void Window::Init(){

    //initialize GLFW
    if (!glfwInit()){
        std::cout << "GLFW could't start" << std::endl;
        exit(EXIT_FAILURE);
    }

    //create window
    m_pWindow = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
    if (!m_pWindow){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_pWindow);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //check OpenGL version
    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << version << std::endl;

    //check for OpenGL errors
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        std::cout << "OpenGL Error: " << err << std::endl;
    }

}

void Window::Update(){

}

void Window::PollEvents(){
    glfwPollEvents();
}

void Window::SwapBuffers(){
    glfwSwapBuffers(m_pWindow);
}

bool Window::isShouldClose(){
    return glfwWindowShouldClose(m_pWindow);
}
