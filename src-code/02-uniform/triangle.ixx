#include "pgr.h"
export module triangle;

// import std;

import object_instance;
import resources;

export class Triangle : public ObjectInstance
{
  public:
    Triangle( shaderProgram_p *shdrPrg = nullptr );
    ~Triangle();

    void update( float elapsedTime, const glm::mat4 *parentModelMatrix ) override;
    void draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix ) override;

  private:
    bool initialized_; ///< object has the shader with defined locations
};
