#version 330 core
/*
* define the output variable color based on gl_VertexID 
*/

uniform mat4 PVM;
in vec3 position;
out vec4 color; // based on the position

void main()
{
    gl_Position = PVM * vec4(position, 1.0f);
    color.rgb = float(gl_VertexID % 256) / 256.0 * vec3(1.0);
    color.a = 1.;
}
