#version 330 core

out vec4 FragColor;
in vec3 fCol;

uniform float timeT;
void main()
{
	//FragColor = vec4(fCol.xyz , 1.0f);
	FragColor = vec4(fCol.x * sin(timeT), fCol.y * cos(timeT), fCol.z / (timeT), 1.0f);
	//FragColor = vec4(fCol.xyz * timeT, 1.0f)
	
}