#include "pgr.h"
module object_instance;

import std;
import object_list; // ObjectList

ObjectInstance::ObjectInstance( ShaderProgram *shaderProgram )
    : geometry( nullptr ), shaderProgram( shaderProgram )
{
}

void ObjectInstance::update( const float elapsedTime, const glm::mat4 *parentModelMatrix )
{
    if ( parentModelMatrix != nullptr )
        globalModelMatrix = *parentModelMatrix * localModelMatrix;
    else
        globalModelMatrix = localModelMatrix;

    for ( ObjectInstance *child : children )
    {
        if ( child != nullptr ) child->update( elapsedTime, &globalModelMatrix );
    }
}

void ObjectInstance::draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix )
{
    for ( ObjectInstance *child : children )
    {
        if ( child != nullptr ) child->draw( viewMatrix, projectionMatrix );
    }
}
