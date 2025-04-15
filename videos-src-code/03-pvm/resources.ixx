#include "pgr.h"
export module resources;
import std;

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

/* // XD 9 */
// default camera for looking around
export class CDefaultCamera
{
  private:
    glm::vec3 position_ = glm::vec3( 0.f, 0.f, -1.0f );
    glm::vec3 direction_ = glm::vec3( 0.f );

  public:
    float angleHorizontal_m = -90.0f;
    float angleVertical_m = 4.0f;

    glm::mat4 getView()
    {
        static const glm::vec3 axisX = glm::vec3( 1.0f, 0.0f, 0.0f ); // x axis
        static const glm::vec3 axisY = glm::vec3( 0.0f, 1.0f, 0.0f ); // y axis
        static const glm::vec3 axisZ = glm::vec3( 0.0f, 0.0f, 1.0f ); // z axis
        
        float angleH = glm::radians( angleHorizontal_m );
        float angleV = glm::radians( angleVertical_m );
        glm::mat4 matrixToRotate = glm::mat4( 1.0f );

        glm::mat3 rotateHorizontal = glm::rotate( matrixToRotate, angleH, axisY );
        glm::mat3 rotateVertical = glm::rotate( matrixToRotate, angleV, axisZ );

        glm::vec3 cameraUpVector =
            glm::normalize( rotateHorizontal * rotateVertical * axisY ); // axis vector just pics row of matrix
        // glm::vec3 cameraUpVector = glm::vec3( 0.0f, 1.0f, 0.0f ); // saying what is up in your world could be fixed

        direction_ = glm::normalize( rotateHorizontal * rotateVertical * axisX );
        glm::vec3 cameraViewCenter = position_ + direction_;
        glm::mat4 viewMatrix = glm::lookAt( position_, cameraViewCenter, cameraUpVector );
        return viewMatrix;
    }
};
/* // XD 9 */
