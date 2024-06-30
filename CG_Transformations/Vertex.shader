#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aCol;
layout(location = 2) in vec2 aTex;

uniform mat4 transform;

out vec3 ourColor;
out vec2 TextCoord;

void main()
{
	gl_Position = transform *  vec4(aPos, 1.0f);
	ourColor = aCol;
	TextCoord = vec2(aTex.x, aTex.y);
}
	