#version 330 core
/*
* define the output variable color based on gl_VertexID 
*/

in vec4 color;
out vec4 fragmentColor;

void main()
{
    fragmentColor = color;
}
