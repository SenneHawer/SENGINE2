#include "Renderer.h"

Renderer::Renderer(){

}

Renderer::~Renderer(){
    glDeleteShader(m_shader);
    delete m_pTriangle;
    m_pTriangle = nullptr;
    delete m_pMaterial;
    m_pMaterial = nullptr;
}

void Renderer::Init(){

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.25f, 0.5f, 0.75f, 1.0f);

    m_shader = make_shader(
        "./src/shaders/vertex.vert",
        "./src/shaders/fragment.frag"
    );

    m_pTriangle = new TriangleMesh();
    m_pMaterial = new Material("img/texture.png");

}

void Renderer::Render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_shader);

    //DRAW OBJECTS
    m_pMaterial->Use();
    m_pTriangle->Draw();

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
