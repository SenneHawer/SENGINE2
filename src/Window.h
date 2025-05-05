#include "config.h"

class Window{
    public:

        Window();
        ~Window();

        void Init();
        void Update();

        void PollEvents();
        void SwapBuffers();
        bool isShouldClose();

        void  SetTitle(const std::string& title) { m_title = title; }
        void  SetSize(int width, int height) { m_width = width; m_height = height; }
        
    private:

        GLFWwindow* m_pWindow;
        int m_width, m_height;
        std::string m_title;

};