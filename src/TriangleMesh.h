
#include <vector>

class TriangleMesh{
    public:
    TriangleMesh();
    ~TriangleMesh();

    void Draw();

    private:
    unsigned int m_EBO, m_vertexCount;
    std::vector<unsigned int> m_VBOList;
};