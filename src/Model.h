#pragma once
#include "config.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Mesh;
class TriangleMesh;

class Model{

    public:
        Model(std::string modelPath);
        ~Model();
        
        void Draw() const;

    private:
        std::vector<Mesh> m_meshList;
        std::string m_directory;

        //TriangleMesh* m_pTriangleMesh; //to test

        void LoadModel(const std::string& modelPath);
        void ProcessNode(aiNode* node, const aiScene* scene);
        Mesh ProcessMesh(aiMesh* mesh, const aiScene* scene);
};