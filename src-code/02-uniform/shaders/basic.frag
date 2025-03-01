#version 140
/*
* basic fragment shader, which just outputs a single color
*/

uniform vec4 testingColor; 

out vec4 fragmentColor;

void main()
{
    fragmentColor = testingColor; 

    // fragmentColor = vec4(0.56, 0.33, 0.14, 1.0); // brown
    // fragmentColor = vec4(1., 1., 1., 1.); // white
};
