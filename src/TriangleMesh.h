
class TriangleMesh{
    public:
    TriangleMesh();
    ~TriangleMesh();

    void Draw();

    private:
    unsigned int m_VBO, m_vertexCount;
};