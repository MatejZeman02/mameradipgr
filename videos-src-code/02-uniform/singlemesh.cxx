#include "pgr.h"
module singlemesh;

import resources;
import object_instance;
import constants;
import std;

void SingleMesh::update( float elapsedTime, const glm::mat4 *parentModelMatrix )
{
    // instance specific stuff

    // propagate the update to children_p
    ObjectInstance::update( elapsedTime, parentModelMatrix );
}

void SingleMesh::draw( const glm::mat4 &viewMatrix, const glm::mat4 &projectionMatrix )
{
    if ( initialized_ && ( shaderProgram_p != nullptr ) )
    {
        glUseProgram( shaderProgram_p->program );

        glUniformMatrix4fv( shaderProgram_p->locations.PVMmatrix, 1, GL_FALSE,
                            glm::value_ptr( globalModelMatrix_p ) );

        glBindVertexArray( geometry_p->vertexArrayObject );
        glDrawElements( GL_TRIANGLES, geometry_p->numTriangles * 3, GL_UNSIGNED_INT, 0 );
        glBindVertexArray( 0 );
    }
    else
    {
        std::cerr << "SingleMesh::draw(): Can't draw, mesh not initialized_ properly!" << std::endl;
    }
}

/** Load one mesh using assimp library (vertices only, for more attributes see method extended version in
 * Asteroids)
 * \param fileName [in] file to open/load
 * \param shader [in] vao will connect loaded data to shader
 * \param geometry_p
 */
bool SingleMesh::loadSingleMesh( const std::string &fileName, shaderProgram_p *shader,
                                 ObjectGeometry **geometry_p )
{
    Assimp::Importer importer;

    // unitize object in size (scale the model to fit into (-1..1)^3)
    importer.SetPropertyInteger( AI_CONFIG_PP_PTV_NORMALIZE, 1 );

    // load asset from the file - you can play with various processing steps
    const aiScene *scn = importer.ReadFile(
        fileName.c_str(), 0 | aiProcess_Triangulate            // triangulate polygons (if any)
                              | aiProcess_PreTransformVertices // transforms scene hierarchy into one root with
                                                               // geometry_p-leafs only, for more see Doc
                              | aiProcess_GenSmoothNormals     // calculate normals per vertex
                              | aiProcess_JoinIdenticalVertices );

    // abort if the loader fails
    if ( scn == NULL )
    {
        std::cerr << "SingleMesh::loadSingleMesh(): assimp error - " << importer.GetErrorString() << std::endl;
        *geometry_p = NULL;
        return false;
    }

    // some formats store whole scene (multiple meshes and materials, lights, cameras, ...) in one file, we cannot
    // handle that in our simplified example
    if ( scn->mNumMeshes != 1 )
    {
        std::cerr
            << "SingleMesh::loadSingleMesh(): this simplified loader can only process files with only one mesh"
            << std::endl;
        *geometry_p = NULL;
        return false;
    }

    // in this phase we know we have one mesh in our loaded scene, we can directly copy its data to OpenGL ...
    const aiMesh *mesh = scn->mMeshes[0];

    *geometry_p = new ObjectGeometry;

    // vertex buffer object, store all vertex positions
    glGenBuffers( 1, &( ( *geometry_p )->vertexBufferObject ) );
    glBindBuffer( GL_ARRAY_BUFFER, ( *geometry_p )->vertexBufferObject );
    glBufferData( GL_ARRAY_BUFFER, 3 * sizeof( float ) * mesh->mNumVertices, 0,
                  GL_STATIC_DRAW ); // allocate memory for vertices
    glBufferSubData( GL_ARRAY_BUFFER, 0, 3 * sizeof( float ) * mesh->mNumVertices,
                     mesh->mVertices ); // store all vertices

    // copy all mesh faces into one big array (assimp supports faces with ordinary number of vertices, we use only
    // 3 -> triangles)
    unsigned int *indices = new unsigned int[mesh->mNumFaces * 3];
    for ( unsigned int f = 0; f < mesh->mNumFaces; ++f )
    {
        indices[f * 3 + 0] = mesh->mFaces[f].mIndices[0];
        indices[f * 3 + 1] = mesh->mFaces[f].mIndices[1];
        indices[f * 3 + 2] = mesh->mFaces[f].mIndices[2];
    }

    // copy our temporary index array to OpenGL and free the array
    glGenBuffers( 1, &( ( *geometry_p )->elementBufferObject ) );
    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, ( *geometry_p )->elementBufferObject );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 3 * sizeof( unsigned int ) * mesh->mNumFaces, indices, GL_STATIC_DRAW );

    delete[] indices;

    // copy the material info to MeshGeometry structure
    const aiMaterial *mat = scn->mMaterials[mesh->mMaterialIndex];
    aiColor4D color;
    aiString name;
    aiReturn retValue = AI_SUCCESS;

    // get returns: aiReturn_SUCCESS 0 | aiReturn_FAILURE -1 | aiReturn_OUTOFMEMORY -3
    mat->Get( AI_MATKEY_NAME, name ); // may be "" after the input mesh processing, must be aiString type!

    if ( ( retValue = aiGetMaterialColor( mat, AI_MATKEY_COLOR_DIFFUSE, &color ) ) != AI_SUCCESS )
        color = aiColor4D( 0.0f, 0.0f, 0.0f, 0.0f );

    glGenVertexArrays( 1, &( ( *geometry_p )->vertexArrayObject ) );
    glBindVertexArray( ( *geometry_p )->vertexArrayObject );

    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER,
                  ( *geometry_p )->elementBufferObject ); // bind our element array buffer (indices) to vao
    glBindBuffer( GL_ARRAY_BUFFER, ( *geometry_p )->vertexBufferObject );

    bool validInit = false;

    if ( ( shaderProgram_p != nullptr ) && shaderProgram_p->initialized_ &&
         ( shaderProgram_p->locations.position != -1 ) )
    {

        glEnableVertexAttribArray( shader->locations.position );
        glVertexAttribPointer( shader->locations.position, 3, GL_FLOAT, GL_FALSE, 0, 0 );

        CHECK_GL_ERROR();

        validInit = true;
    }

    glBindVertexArray( 0 );

    ( *geometry_p )->numTriangles = mesh->mNumFaces;

    return validInit;
}

SingleMesh::SingleMesh( shaderProgram_p *shdrPrg ) : ObjectInstance( shdrPrg ), initialized_( false )
{
    const char *MODEL_FILE_NAME = "data/shape.obj";

    if ( !loadSingleMesh( MODEL_FILE_NAME, shdrPrg, &geometry_p ) )
    {
        if ( geometry_p == nullptr )
        {
            std::cerr << "SingleMesh::SingleMesh(): geometry_p not initialized_!" << std::endl;
        }
        else
        {
            std::cerr << "SingleMesh::SingleMesh(): shaderProgram_p struct not initialized_!" << std::endl;
        }
    }
    else
    {
        if ( ( shaderProgram_p != nullptr ) && shaderProgram_p->initialized_ &&
             ( shaderProgram_p->locations.PVMmatrix != -1 ) )
        {
            initialized_ = true;
        }
        else
        {
            std::cerr << "SingleMesh::SingleMesh(): shaderProgram_p struct not initialized_!" << std::endl;
        }
    }
}

SingleMesh::~SingleMesh()
{

    if ( geometry_p != nullptr )
    {
        glDeleteVertexArrays( 1, &( geometry_p->vertexArrayObject ) );
        glDeleteBuffers( 1, &( geometry_p->elementBufferObject ) );
        glDeleteBuffers( 1, &( geometry_p->vertexBufferObject ) );

        delete geometry_p;
        geometry_p = nullptr;
    }

    initialized_ = false;
}
