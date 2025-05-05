#include "config.h"
#include "Engine.h"

int main(){

    //std::ifstream file;
    //std::string line;
    //file.open ("../src/shaders/fragment.frag");
    //while(std::getline(file, line)){
    //    std::cout << line << std::endl;
    //}




    //till here in window

    //not yet
    //glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    //make shader
    //unsigned int shader = make_shader(
    //    "../src/shaders/vertex.vert",
    //    "../src/shaders/fragment.frag"
    //);


    //TriangleMesh* pTriangle = new TriangleMesh();

    // loop already in rederer
    //while (!glfwWindowShouldClose(window)){
    //    glfwPollEvents();


    //    glClear(GL_COLOR_BUFFER_BIT);
    //    glUseProgram(shader);
    //    pTriangle->Draw();
    //    glfwSwapBuffers(window);
    //}

    //till here

    //glDeleteShader(shader);
    //glfwTerminate();

    Engine engine;
    engine.Init();
    engine.Run();


    return 0;
}
