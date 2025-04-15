#include "pgr.h"
module triangle;

import std;

import object_instance;
import resources;
import constants;

// import triangle_mesh; // XD 1

Triangle::Triangle( ShaderProgram *shdrPrg ) : ObjectInstance( shdrPrg ), initialized_( false )
{
    geometry_p = new ObjectGeometry;

    /*  // XD 1 */
    // Define vertices in object space (3D)
    static constexpr float vertices[] = {
        0.0f,  0.5f,  0.0f, // Top vertex
        -0.5f, -0.5f, 0.0f, // Bottom-left vertex
        0.5f,  -0.5f, 0.0f  // Bottom-right vertex
    };
    /*  // XD 1 */

    geometry_p->numTriangles = 1;
    geometry_p->elementBufferObject = 0;

    glGenVertexArrays( 1, &geometry_p->vertexArrayObject );
    glBindVertexArray( geometry_p->vertexArrayObject );

    glGenBuffers( 1, &geometry_p->vertexBufferObject );
    glBindBuffer( GL_ARRAY_BUFFER, geometry_p->vertexBufferObject );
    glBufferData( GL_ARRAY_BUFFER, sizeof( vertices ), vertices, GL_STATIC_DRAW );

    if ( ( shaderProgram_p != nullptr ) && shaderProgram_p->initialized &&
         ( shaderProgram_p->locations.position != -1 ) && ( shaderProgram_p->locations.PVMmatrix != -1 ) )
    {
        glEnableVertexAttribArray( shaderProgram_p->locations.position );
        // glVertexAttribPointer( shaderProgram_p->locations.position, 2, GL_FLOAT, GL_FALSE, 0, (void *)0 );
        glVertexAttribPointer( shaderProgram_p->locations.position, 3, GL_FLOAT, GL_FALSE, 0, (void *)0 ); // XD 2

        initialized_ = true;
    }
    else
    {
        std::cerr << "Triangle::Triangle(): shaderProgram_p struct not initialized_!" << std::endl;
    }
}

Triangle::~Triangle()
{
    glDeleteVertexArrays( 1, &( geometry_p->vertexArrayObject ) );
    glDeleteBuffers( 1, &( geometry_p->elementBufferObject ) );
    glDeleteBuffers( 1, &( geometry_p->vertexBufferObject ) );

    delete geometry_p;
    geometry_p = nullptr;

    initialized_ = false;
}

void Triangle::update( float elapsedTime, const glm::mat4 *parentModelMatrix )
{
    // instance specific stuff

    // propagate the update to children_p
    ObjectInstance::update( elapsedTime, parentModelMatrix );
}

void Triangle::draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix )
{
    if ( initialized_ && ( shaderProgram_p != nullptr ) )
    {
        glm::mat4 PVMmatrix = projectionMatrix * viewMatrix * globalModelMatrix_p; // XD 3
        glUseProgram( shaderProgram_p->program );
        // glUniformMatrix4fv( shaderProgram_p->locations.PVMmatrix, 1, GL_FALSE,
        //                     glm::value_ptr( globalModelMatrix_p ) );
        glUniformMatrix4fv( shaderProgram_p->locations.PVMmatrix, 1, GL_FALSE,
                            glm::value_ptr( PVMmatrix ) ); // XD 3

        glBindVertexArray( geometry_p->vertexArrayObject );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray( 0 );
    }
    else
    {
        std::cerr << "Triangle::draw(): Can't draw, triangle not initialized_ properly!" << std::endl;
    }
}
