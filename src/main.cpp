#include "config.h"
#include "TriangleMesh.h"

unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath);
unsigned int make_module(const std::string& filepath, unsigned int module_type);

int main(){

    //std::ifstream file;
    //std::string line;
    //file.open ("../src/shaders/fragment.frag");
    //while(std::getline(file, line)){
    //    std::cout << line << std::endl;
    //}


    std::cout << "hello world" << std::endl;

    GLFWwindow* window;

    if (!glfwInit()){
        std::cout << "GLFW could't start" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -1;
    }

    const GLubyte* version = glGetString(GL_VERSION);
    std::cout << "OpenGL Version: " << version << std::endl;

    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR) {
        std::cout << "OpenGL Error: " << err << std::endl;
    }

    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    //make shader
    unsigned int shader = make_shader(
        "../src/shaders/vertex.vert",
        "../src/shaders/fragment.frag"
    );


    TriangleMesh* pTriangle = new TriangleMesh();

    while (!glfwWindowShouldClose(window)){
        glfwPollEvents();


        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shader);
        pTriangle->Draw();
        glfwSwapBuffers(window);
    }



    glDeleteShader(shader);
    glfwTerminate();

    return 0;
}

unsigned int make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath){
    //create modules
    std::vector<unsigned int> modules;
    modules.push_back(make_module(vertex_filepath, GL_VERTEX_SHADER));
    modules.push_back(make_module(fragment_filepath, GL_FRAGMENT_SHADER));

    //create shader program
    unsigned int shader = glCreateProgram();
    for (unsigned int shaderModule : modules){ //attach modules
        glAttachShader(shader, shaderModule);
    }

    //bind attributes
    glBindAttribLocation(shader, 0, "vertexPos");
    glBindAttribLocation(shader, 1, "vertexColor");

    glLinkProgram(shader);

    int success;
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success){
        char errorLog[1024];
        glGetShaderInfoLog(shader, 1024, NULL, errorLog);
        std::cout << "Shader Module compilation error:\n" << errorLog << std::endl;
    }

    for (unsigned int shaderModule : modules){ //delete modules
        glDeleteShader(shaderModule);
    }

    return shader;
}

unsigned int make_module(const std::string& filepath, unsigned int module_type){
    std::ifstream file;
    std::stringstream bufferedLines;
    std::string line;

    //load file
    file.open(filepath);
    while(std::getline(file, line)){
        bufferedLines << line << "\n";
    }

    //collect data into one string
    std::string shaderSource = bufferedLines.str();
    const char* shaderSrc = shaderSource.c_str();
    bufferedLines.str(""); //erase string stream
    file.close();

    //create shader module
    unsigned int shaderModule = glCreateShader(module_type);
    glShaderSource(shaderModule, 1, &shaderSrc, NULL);
    glCompileShader(shaderModule);

    //compile shader
    int success;
    glGetShaderiv(shaderModule, GL_COMPILE_STATUS, &success);
    if (!success){
        char errorLog[1024];
        glGetShaderInfoLog(shaderModule, 1024, NULL, errorLog);
        std::cout << "Shader Module compilation error:\n" <<errorLog << std::endl;
    }

    return shaderModule;
}
