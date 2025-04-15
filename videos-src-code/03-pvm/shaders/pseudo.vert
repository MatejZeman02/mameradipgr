#version 450 core
/*
* define the output variable color based on gl_VertexID 
*/
// XD 6

uniform mat4 PVM;
in vec3 position;
out vec4 color; // based on the position

void main()
{
    gl_Position = PVM * vec4( position, 1.0 );
    color.rgb = vec3( 1.0 ) * ( gl_VertexID * 100 + 56  ) % 256 / 256.0;
    color.a = 1.0;
}
