#include "object.h"

ObjectInstance::ObjectInstance( ShaderProgram *shdrPrg )
    : geometry( nullptr ), shaderProgram( shdrPrg )
{
}

void ObjectInstance::update( const float elapsedTime, const glm::mat4 *parentModelMatrix )
{
    // update model matrix - localModelMatrix - of the instance
    // ...

    // if we have parent, multiply parent's matrix with ours
    if ( parentModelMatrix != nullptr )
        globalModelMatrix = *parentModelMatrix * localModelMatrix;
    else
        globalModelMatrix = localModelMatrix;

    // update all children
    for ( ObjectInstance *child : children )
    {
        if ( child != nullptr ) child->update( elapsedTime, &globalModelMatrix );
    }
}

void ObjectInstance::draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix )
{
    // draw instance geometry using globalModelMatrix
    // ...

    // process all children
    for ( ObjectInstance *child : children )
    { // for (auto child : children) {
        if ( child != nullptr ) child->draw( viewMatrix, projectionMatrix );
    }
}
