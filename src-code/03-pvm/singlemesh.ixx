#include "pgr.h"
export module singlemesh;

import std;
import resources;
import object_instance;

export class SingleMesh : public ObjectInstance
{
  public:
    SingleMesh( ShaderProgram *shdrPrg = nullptr );
    ~SingleMesh();

    void update( float elapsedTime, const glm::mat4 *parentModelMatrix ) override;
    void draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix ) override;

  private:
    bool loadSingleMesh( const std::string &fileName, ShaderProgram *shader, ObjectGeometry **geometry_p );

    bool initialized_; ///< object has the shader with defined locations
};
