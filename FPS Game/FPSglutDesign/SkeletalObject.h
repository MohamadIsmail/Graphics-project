    #pragma comment( lib, "SOIL.lib" )
    #pragma comment(lib , "lib3ds")
    #include<iostream>
    #include "lib3ds/file.h"
    #include "lib3ds/mesh.h"
    #include "lib3ds/material.h"
    #include "Soil/SOIL.h"
    #include "3dmath.h"
     
    using namespace std;
     
    class SkeletalObject
    {
    public:
    SkeletalObject(const char* filename);
    virtual ~SkeletalObject();
    virtual void Draw() const;
    virtual void CreateVBO();
    void applyTexture(const char*texfilename);
     
    protected:
    void GetFaces();
    unsigned int m_TotalFaces;
    Lib3dsFile * m_model;
     
    Lib3dsMesh* Mesh;
    GLuint textureObject;
    GLuint m_VertexVBO, m_NormalVBO, m_TexCoordVBO;
    GLuint texture[1];
    };