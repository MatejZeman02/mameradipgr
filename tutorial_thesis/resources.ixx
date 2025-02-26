#include "pgr.h"
export module resources;

/**
 * \brief Shader program related stuff (id, locations, ...).
 */
export struct ShaderProgram
{
    /// identifier for the shader program
    unsigned program;

    bool initialized;

    /**
     * \brief Indices of the vertex shader inputs (locations)
     */
    struct
    {
        // vertex attributes locations
        GLint position;
        // uniforms locations
        GLint PVMmatrix;
        GLint testingColor; // XD
    } locations = { -1 };

    ShaderProgram() : program( 0 ), initialized( false )
    {
    }
};

/**
 * \brief Geometry of an object (vertices, triangles).
 */
export struct ObjectGeometry
{
    unsigned vertexBufferObject;  ///< identifier for the vertex buffer object
    unsigned elementBufferObject; ///< identifier for the element buffer object
    unsigned vertexArrayObject;   ///< identifier for the vertex array object
    unsigned int numTriangles;    ///< number of triangles in the mesh
};
