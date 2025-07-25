#include "Renderer.h"
#include <glm/gtc/type_ptr.hpp>
#include "Model.h"

Renderer::Renderer(){

}

Renderer::~Renderer(){
    glDeleteShader(m_shader);
    //delete m_pTriangle;
    //m_pTriangle = nullptr;
    delete m_pMaterial;
    m_pMaterial = nullptr;
    //delete m_pMask;
    //m_pMask = nullptr;
}

void Renderer::Init(const Window& window){

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    m_shader = make_shader(
        "./src/shaders/vertex.vert",
        "./src/shaders/fragment.frag"
    );

    glUseProgram(m_shader);
    glUniform1i(glGetUniformLocation(m_shader, "material"), 0); 
    //glUniform1i(glGetUniformLocation(m_shader, "mask"), 1); 

    //enable blending
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //m_pTriangle = new TriangleMesh();
    m_pMaterial = new Material("img/stargirl.png");
    //m_pMask = new Material("img/vignette.png");

    m_aspectRatio = window.GetAspectRatio();
}

void Renderer::Render(const glm::mat4& modelMatrix, const Model& model){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_shader);

    glm::mat4 newModelMatrix = modelMatrix;
    newModelMatrix = glm::rotate(newModelMatrix, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f)); //

    unsigned int modelLocation = glGetUniformLocation(m_shader, "model");
    glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(newModelMatrix));

    glm::vec3 camPos = glm::vec3(5.0f, 0.0f, 3.0f);
    glm::vec3 camTarget = glm::vec3(0.0f, 0.0f, 0.0f);

    glm::mat4 view = glm::lookAt(camPos, camTarget, glm::vec3(0.0f, 0.0f, 1.0f));
        
    unsigned int viewLocation = glGetUniformLocation(m_shader, "view");
    glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(view));


    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f), //field of view
        m_aspectRatio, //aspect ratio
        0.1f, //near plane
        100.0f //far plane
    );
    unsigned int projectionLocation = glGetUniformLocation(m_shader, "projection");
    glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projection));

    //DRAW OBJECTS
    m_pMaterial->Use(0);
    //m_pMask->Use(1);
    //m_pTriangle->Draw();

    //draw model

    model.Draw();
}

void Renderer::RenderBeginFrame(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::RenderEndFrame(){
    //swap buffers, etc.
    //glfwSwapBuffers(m_window);
    //glfwPollEvents();
    glFlush();
}

unsigned int Renderer::make_shader(const std::string& vertex_filepath, const std::string& fragment_filepath){
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
        glGetProgramInfoLog(shader, 1024, NULL, errorLog);
        std::cout << "RENDERER: Shader compilation error:\n" << errorLog << std::endl;
        return 0;
    }

    for (unsigned int shaderModule : modules){ //delete modules
        glDeleteShader(shaderModule);
    }

    return shader;
}

unsigned int Renderer::make_module(const std::string& filepath, unsigned int module_type){
    std::ifstream file;
    std::stringstream bufferedLines;
    std::string line;

    //load file
    file.open(filepath);
    if (!file.is_open()) {
        std::cerr << "Error opening shader file: " << filepath << std::endl;
        return 0; // Return 0 if the file can't be opened
    }

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
        std::cout << "RENDERER: Shader Module compilation error:\n" <<errorLog << std::endl;
        return 0;
    }

    return shaderModule;
}