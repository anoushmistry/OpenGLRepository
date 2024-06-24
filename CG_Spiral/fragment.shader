#version 330 core

out vec4 FragColor;
in vec3 fcol;
uniform float timeH;
void main()
{
    FragColor = vec4(fcol.x *timeH, fcol.y *timeH, fcol.z * timeH, 1.0f);
}