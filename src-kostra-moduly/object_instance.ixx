#include "pgr.h"
export module object_instance;

import std;
import resources;
import object_list; // ObjectList

export class ObjectInstance
{
  protected:
    struct ObjectGeometry *geometry;
    glm::mat4 localModelMatrix;
    glm::mat4 globalModelMatrix;
    struct ShaderProgram *shaderProgram;
    ObjectList children;

  public:
    ObjectInstance( ShaderProgram *shaderProgram = nullptr );
    virtual ~ObjectInstance() = default;
    virtual void update( const float elapsedTime, const glm::mat4 *parentModelMatrix );
    virtual void draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix );
};
