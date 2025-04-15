#version 450 core
/*
* basic vertex shader, which just sets a position.
*/

uniform mat4 PVM;

// in vec2 position;
in vec3 position; // XD 4

void main()
{
    gl_Position = PVM * vec4( position, 1.0 ); // XD 4
    // gl_Position = PVM * vec4( position, 0.0, 1.0 );
};
