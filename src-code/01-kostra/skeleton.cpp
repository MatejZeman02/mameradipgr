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


ObjectList objects;

// shared shader programs
ShaderProgram commonShaderProgram;

// -----------------------  OpenGL stuff ---------------------------------

/**
 * \brief Load and compile shader programs. Get attribute locations.
 */
void loadShaderPrograms()
{
    CHECK_GL_ERROR(); // clear the error flag
    // original method:
    // std::string vertexShaderSrc = "#version 330 core\n"
    //                               "in vec2 position;\n"
    //                               "uniform mat4 PVM;\n"
    //                               "void main() {\n"
    //                               "  gl_Position = PVM * vec4(position, 0.0f, 1.0f);\n"
    //                               "}\n";
    // std::string fragmentShaderSrc = "#version 330 core\n"
    //                                 "out vec4 fragmentColor;"
    //                                 "void main() {\n"
    //                                 "  fragmentColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
    //                                 "}\n";
    // GLuint shaders[] = { pgr::createShaderFromSource( GL_VERTEX_SHADER, vertexShaderSrc ),
    //                      pgr::createShaderFromSource( GL_FRAGMENT_SHADER, fragmentShaderSrc ), 0 };

    // using vector for shaders ids:
    std::vector<GLuint> shaders;

    shaders.push_back( pgr::createShaderFromFile( GL_VERTEX_SHADER, "shaders/basic.vert" ) );
    shaders.push_back( pgr::createShaderFromFile( GL_FRAGMENT_SHADER, "shaders/basic.frag" ) );

    commonShaderProgram.program = pgr::createProgram( shaders );
    commonShaderProgram.locations.position = glGetAttribLocation( commonShaderProgram.program, "position" );

    // other attributes and uniforms
    commonShaderProgram.locations.PVMmatrix = glGetUniformLocation( commonShaderProgram.program, "PVM" );

    // checking if the inputs initialized (not -1):
    assert( commonShaderProgram.locations.PVMmatrix != -1 );
    assert( commonShaderProgram.locations.position != -1 );
    // ...

    commonShaderProgram.initialized = true;
}

/**
 * \brief Delete all shader program objects.
 */
void cleanupShaderPrograms( void )
{
    pgr::deleteProgramAndShaders( commonShaderProgram.program );
}

/**
 * \brief Draw all scene objects.
 */
void drawScene( void )
{
    // count matrices based on your camera (right now no cam)
    glm::mat4 viewMatrix = glm::mat4( 1.0f );
    // glm::mat4 projectionMatrix = glm::mat4( 1.0f ); // default ortho matrix

    // TODO: compute perspective projection matrix by the window size for now:
    int win_width = glutGet( GLUT_WINDOW_WIDTH );
    int win_height = glutGet( GLUT_WINDOW_HEIGHT );
    glm::mat4 projectionMatrix =
        glm::perspective( glm::radians( 45.0f ), static_cast<float>( win_width ) / win_height, 0.1f, 100.0f );

    for ( ObjectInstance *object : objects )
    { // for (auto object : objects) {
        if ( object != nullptr ) object->draw( viewMatrix, projectionMatrix );
    }
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

    // mouse hovering over window

    // create display event to redraw window contents if needed (and not handled in the timer callback)
    // glutPostRedisplay();

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

    // TODO: count Y angle <= 90 degrees for natural looking camera movement

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
    loadShaderPrograms();

    objects.push_back( new Triangle( &commonShaderProgram ) );
    // objects.push_back(new SingleMesh(&commonShaderProgram));

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
    cleanupShaderPrograms();
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
        // glutPassiveMotionFunc( passiveMouseMotionCb ); // passive is stronger than normal mouseMotionCb()
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
