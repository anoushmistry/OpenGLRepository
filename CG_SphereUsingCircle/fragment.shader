#version 330 core

out vec4 FragColor;
in vec3 fCol;

uniform float timeT;
void main()
{
	//FragColor = vec4(fCol.x* (timeT) , fCol.y * (timeT) , fCol.z * (timeT), 1.0f);
	FragColor = vec4(fCol.xyz*timeT , 1.0f);
	
}