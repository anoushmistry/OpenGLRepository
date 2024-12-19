#version 330 core

out vec4 FragColor;

in vec3 ourColor;
in vec2 TextCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	FragColor = mix(texture(texture1, TextCoord), texture(texture2, TextCoord), 0.5f);
	// FragColor = texture(texture1, TextCoord) * vec4(ourColor, 1.0f);
	//FragColor = vec4(ourColor.xyz, 1.0f);
}