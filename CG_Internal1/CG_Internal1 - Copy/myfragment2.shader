#version 330 core

out vec4 myFragColor;

void main()
{
	myFragColor = vec4(0.3f, 0.6f, 0.3f, 1.0f); //R,G,B, (W has to be 1 always)
}