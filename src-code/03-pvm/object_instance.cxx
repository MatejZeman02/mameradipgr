#include "pgr.h"
module object_instance;

import std;
import object_list; // ObjectList

ObjectInstance::ObjectInstance( ShaderProgram *shaderProgram_p )
    : geometry_p( nullptr ), shaderProgram_p( shaderProgram_p )
{
}

void ObjectInstance::update( const float elapsedTime, const glm::mat4 *parentModelMatrix )
{
    if ( parentModelMatrix != nullptr )
        globalModelMatrix_p = *parentModelMatrix * localModelMatrix_p;
    else
        globalModelMatrix_p = localModelMatrix_p;

    for ( ObjectInstance *child : children_p )
    {
        if ( child != nullptr ) child->update( elapsedTime, &globalModelMatrix_p );
    }
}

void ObjectInstance::draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix )
{
    for ( ObjectInstance *child : children_p )
    {
        if ( child != nullptr ) child->draw( viewMatrix, projectionMatrix );
    }
}
