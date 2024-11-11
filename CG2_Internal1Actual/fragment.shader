
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time; 

void main()
{
    float stripesPattern = abs(sin(TexCoord.y * 15.0 + time * 10.0));
    float colorOffset = 0.5 + 0.5 * sin(time * 1.0); // Smooth oscillation between 0 and 1
    vec3 color1 = mix(vec3(0.2, 0.2, 0.3), vec3(1.0, 0.0, 0.0), colorOffset); // Transition from dark blue to red
    vec3 color2 = mix(vec3(1.0, 1.0, 1.0), vec3(0.0, 1.0, 0.0), colorOffset);

    vec3 finalColor = mix(color1, color2, stripesPattern);
    FragColor = vec4(finalColor, 1.0);
}
