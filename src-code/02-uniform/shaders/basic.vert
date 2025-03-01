#version 330 core
/*
* basic vertex shader, which just outputs a position.
*/

in vec2 position;
uniform mat4 PVM;

void main()
{
    gl_Position = PVM * vec4(position, 0.0f, 1.0f);
};
