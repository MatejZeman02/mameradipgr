#include <iostream>
#include <string>
#include "pgr.h"

import std;
import constants;
import resources;
import object_list;
import object_instance;

import triangle;
import singlemesh;

// globals:
ObjectList objects;

ShaderProgram commonshaderProgram;
CDefaultCamera defaultCamera; // XD 8

// -----------------------  OpenGL stuff ---------------------------------

/**
 * \brief Load and compile shader programs. Get attribute locations.
 */
void loadshaderProgram_ps()
{
    CHECK_GL_ERROR(); // clear the error flag
    // using vector for shaders ids:
    std::vector<GLuint> shaders;

    shaders.push_back( pgr::createShaderFromFile( GL_VERTEX_SHADER, "shaders/pseudo.vert" ) );   // XD 5
    shaders.push_back( pgr::createShaderFromFile( GL_FRAGMENT_SHADER, "shaders/pseudo.frag" ) ); // XD 5
    // shaders.push_back( pgr::createShaderFromFile( GL_VERTEX_SHADER, "shaders/basic.vert" ) );
    // shaders.push_back( pgr::createShaderFromFile( GL_FRAGMENT_SHADER, "shaders/basic.frag" ) );

    commonshaderProgram.program = pgr::createProgram( shaders );
    commonshaderProgram.locations.position = glGetAttribLocation( commonshaderProgram.program, "position" );

    // other attributes and uniforms
    commonshaderProgram.locations.PVMmatrix = glGetUniformLocation( commonshaderProgram.program, "PVM" );

    // checking if the inputs initialized (not -1):
    assert( commonshaderProgram.locations.PVMmatrix != -1 );
    assert( commonshaderProgram.locations.position != -1 );
    // ...

    commonshaderProgram.initialized = true;
}

/**
 * \brief Delete all shader program objects.
 */
void cleanupshaderProgram_ps( void )
{
    pgr::deleteProgramAndShaders( commonshaderProgram.program );
}

/**
 * \brief Draw all scene objects.
 */
void drawScene( void )
{
    /* // XD 12 */
    // count matrices based on camera
    // glm::mat4 viewMatrix = glm::mat4( 1.0f ); // no transformation
    // glm::mat4 projectionMatrix = glm::mat4( 1.0f ); // default ortho matrix

    glm::mat4 viewMatrix = defaultCamera.getView();

    int win_width = glutGet( GLUT_WINDOW_WIDTH );
    int win_height = glutGet( GLUT_WINDOW_HEIGHT );

    float fov = glm::radians( 45.0f );
    float aspectRatio = (float)win_width / win_height;
    float nearClippingPlane = 0.1f;
    float farClippingPlane = 100.0f;
    glm::mat4 projectionMatrix = glm::perspective( fov, aspectRatio, nearClippingPlane, farClippingPlane );
    /* // XD 12 */

    for ( ObjectInstance *object : objects )
        if ( object != nullptr ) object->draw( viewMatrix, projectionMatrix );
}

// -----------------------  Window callbacks ---------------------------------

/**
 * \brief Draw the window contents.
 */
void displayCb()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    // draw the window contents (scene objects)
    drawScene();

    glutSwapBuffers();
}

/**
 * \brief Window was reshaped.
 * \param newWidth New window width
 * \param newHeight New window height
 */
void reshapeCb( int newWidth, int newHeight )
{
    //          x,  y,  width,    height
    glViewport( 0, 0, newWidth, newHeight );
};

// -----------------------  Keyboard ---------------------------------

/**
 * \brief Handle the key pressed event.
 * Called whenever a key on the keyboard was pressed. The key is given by the "keyPressed"
 * parameter, which is an ASCII character. It's often a good idea to have the escape key (ASCII value 27)
 * to call glutLeaveMainLoop() to exit the program.
 * \param keyPressed ASCII code of the key
 * \param mouseX mouse (cursor) X position
 * \param mouseY mouse (cursor) Y position
 */
void keyboardCb( unsigned char keyPressed, int mouseX, int mouseY )
{

    if ( keyPressed == ESC )
    {
        glutLeaveMainLoop();
        exit( EXIT_SUCCESS );
    }
}

// Called whenever a key on the keyboard was released. The key is given by
// the "keyReleased" parameter, which is in ASCII.
/**
 * \brief Handle the key released event.
 * \param keyReleased ASCII code of the released key
 * \param mouseX mouse (cursor) X position
 * \param mouseY mouse (cursor) Y position
 */
void keyboardUpCb( unsigned char keyReleased, int mouseX, int mouseY )
{
}

//
/**
 * \brief Handle the non-ASCII key pressed event (such as arrows or F1).
 *  The special keyboard callback is triggered when keyboard function (Fx) or directional
 *  keys are pressed.
 * \param specKeyPressed int value of a predefined glut constant such as GLUT_KEY_UP
 * \param mouseX mouse (cursor) X position
 * \param mouseY mouse (cursor) Y position
 */
void specialKeyboardCb( int specKeyPressed, int mouseX, int mouseY )
{
    // if ( specKeyPressed == GLUT_KEY_SHIFT_L )
    // {
    //     // ...
    // }
}

void specialKeyboardUpCb( int specKeyReleased, int mouseX, int mouseY )
{
    // if ( specKeyReleased == GLUT_KEY_SHIFT_L )
    // {
    //     // ...
    // }
} // key released

// -----------------------  Mouse ---------------------------------
// three events - mouse click, mouse drag, and mouse move with no button pressed

//
/**
 * \brief React to mouse button press and release (mouse click).
 * When the user presses and releases mouse buttons in the window, each press
 * and each release generates a mouse callback (including release after dragging).
 *
 * \param buttonPressed button code (GLUT_LEFT_BUTTON, GLUT_MIDDLE_BUTTON, or GLUT_RIGHT_BUTTON)
 * \param buttonState GLUT_DOWN when pressed, GLUT_UP when released
 * \param mouseX mouse (cursor) X position
 * \param mouseY mouse (cursor) Y position
 */
void mouseCb( int buttonPressed, int buttonState, int mouseX, int mouseY )
{
}

/**
 * \brief Handle mouse dragging (mouse move with any button pressed).
 *        This event follows the glutMouseFunc(mouseCb) event.
 * \param mouseX mouse (cursor) X position
 * \param mouseY mouse (cursor) Y position
 */
void mouseMotionCb( int mouseX, int mouseY )
{
}

/**
 * \brief Handle mouse movement over the window (with no button pressed).
 * \param mouseX mouse (cursor) X position
 * \param mouseY mouse (cursor) Y position
 */
void passiveMouseMotionCb( int mouseX, int mouseY )
{
    static bool warpPointer = false;
    if ( warpPointer ) // Prevent recursion from glutWarpPointer
    {
        warpPointer = false;
        return;
    }

    int middleX = glutGet( GLUT_WINDOW_WIDTH ) / 2;
    int middleY = glutGet( GLUT_WINDOW_HEIGHT ) / 2;
    float deltaX = static_cast<float>( mouseX - middleX );
    float deltaY = static_cast<float>( mouseY - middleY );

    /* // XD 11 */
    // |angleVertical| <= 90 degrees for natural looking camera movement
    defaultCamera.angleVertical_m = std::clamp( defaultCamera.angleVertical_m - deltaY, -90.0f, 90.0f );

    // Modulo 360 for horizontal rotation
    defaultCamera.angleHorizontal_m -= deltaX;
    defaultCamera.angleHorizontal_m = fmod( defaultCamera.angleHorizontal_m, 360.0f );
    if ( defaultCamera.angleHorizontal_m < 0.0f ) defaultCamera.angleHorizontal_m += 360.0f;
    /* // XD 11 */

    // Set mouse pointer to the window center
    warpPointer = true;
    glutWarpPointer( middleX, middleY );
}

// -----------------------  Timer ---------------------------------

/**
 * \brief Callback responsible for the scene update.
 */
void timerCb( int )
{
    const glm::mat4 sceneRootMatrix = glm::mat4( 1.0f );

    float elapsedTime = 0.001f * static_cast<float>( glutGet( GLUT_ELAPSED_TIME ) ); // milliseconds => seconds

    // update the application state
    for ( ObjectInstance *object : objects )
    { // for (auto object : objects) {
        if ( object != nullptr ) object->update( elapsedTime, &sceneRootMatrix );
    }

    // and plan a new event every 16 ms
    // 1000 ms // 60 FPS = 16 ms
    glutTimerFunc( MILISECONDS, timerCb, 0 ); // takes uint

    // create display event
    glutPostRedisplay();
}

// -----------------------  Application ---------------------------------

/**
 * \brief Initialize application data and OpenGL stuff.
 */
void initApplication()
{
    // init OpenGL
    // - all programs (shaders), buffers, textures, ...
    loadshaderProgram_ps();

    objects.push_back( new Triangle( &commonshaderProgram ) );
    // objects.push_back( new SingleMesh( &commonshaderProgram ) ); // XD 7

    // init your Application
    // - setup the initial application state
}

/**
 * \brief Delete all OpenGL objects and application data.
 */
void finalizeApplication( void )
{
    // cleanUpObjects();

    // delete buffers
    // cleanupModels();

    // delete shaders
    cleanupshaderProgram_ps();
}

// ----------------------------------------------  Main ----------------------------------------------

/**
 * \brief Entry point of the application.
 * \param argc number of command line arguments
 * \param argv array with argument strings
 * \return 0 if OK, <> elsewhere
 */
int main( int argc, char **argv )
{

    // initialize the GLUT library (windowing system)
    glutInit( &argc, argv );

    glutInitContextVersion( pgr::OGL_VER_MAJOR, pgr::OGL_VER_MINOR );
    glutInitContextFlags( GLUT_FORWARD_COMPATIBLE );

    glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH );

    // for each window
    {
        //   initial window size + title
        glutInitWindowSize( INITIAL_WIDTH, INITIAL_HEIGHT );
        glutCreateWindow( WINDOW_TITLE );

        // callbacks - use only those you need
        glutDisplayFunc( displayCb );
        glutReshapeFunc( reshapeCb );
        glutKeyboardFunc( keyboardCb );
        // glutKeyboardUpFunc(keyboardUpCb);
        // glutSpecialFunc(specialKeyboardCb);     // key pressed
        // glutSpecialUpFunc(specialKeyboardUpCb); // key released
        // glutMouseFunc(mouseCb);
        // glutMotionFunc(mouseMotionCb);
        glutPassiveMotionFunc( passiveMouseMotionCb ); // passive is stronger than normal mouseMotionCb() // XD 10
        glutTimerFunc( MILISECONDS, timerCb, 0 );
    }
    // end for each window

    // initialize pgr-framework (GL, DevIl, etc.)
    if ( !pgr::initialize( pgr::OGL_VER_MAJOR, pgr::OGL_VER_MINOR ) )
        pgr::dieWithError( "pgr init failed, required OpenGL not supported?" );

    // init your stuff - shaders & program, buffers, locations, state of the application
    initApplication();

    // handle window close by the user
    glutCloseFunc( finalizeApplication );

    // Infinite loop handling the events
    glutMainLoop();

    // code after glutLeaveMainLoop()
    // cleanup

    return EXIT_SUCCESS;
}
