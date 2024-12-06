#version 330 core
out vec4 FragColor;

in vec3 ourColor;

uniform float timeT;
void main()
{
	float redValue = ourColor.x + (sin(timeT));
	float greenValue = ourColor.y + (sin(timeT + 2.0f));
	float blueValue = ourColor.z +  (sin(timeT + 4.0f));

	vec3 dynamicColor = vec3(redValue,greenValue,blueValue);
	FragColor = vec4(dynamicColor,1.0f);
}