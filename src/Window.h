#include "config.h"

class Window{
    public:

        Window(int width, int height, const std::string& title);
        ~Window();

        void Init();
        void Update();

        void PollEvents();
        void SwapBuffers();
        bool isShouldClose();

    private:

        GLFWwindow* m_pWindow;
        int m_width, m_height;
        std::string m_title;

};