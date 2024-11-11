
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time; 

void main()
{
    float stripesPattern = abs(sin(TexCoord.y * 15.0 + time * 5.0));
    vec3 color1 = vec3(0.2, 0.2, 0.3); 
    vec3 color2 = vec3(1.0, 1.0, 1.0); 

    vec3 finalColor = mix(color1, color2, stripesPattern);
    FragColor = vec4(finalColor, 1.0);
}
