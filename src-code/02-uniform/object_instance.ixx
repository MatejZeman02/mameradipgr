#include "pgr.h"
export module object_instance;

import std;
import resources;
import object_list; // ObjectList

export class ObjectInstance
{
  protected:
    struct ObjectGeometry *geometry_p;
    glm::mat4 localModelMatrix_p;
    glm::mat4 globalModelMatrix_p;
    struct shaderProgram_p *shaderProgram_p;
    ObjectList children_p;

  public:
    ObjectInstance( shaderProgram_p *shaderProgram_p = nullptr );
    virtual ~ObjectInstance() = default;
    virtual void update( const float elapsedTime, const glm::mat4 *parentModelMatrix );
    virtual void draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix );
};
