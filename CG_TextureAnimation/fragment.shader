#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

uniform float time; // Time variable for animation

void main()
{
    // Offset the texture coordinates based on time to create animation
    vec2 animatedTexCoord = TexCoord  + vec2(sin(time) * 0.5, cos(time) * 0.5); 
    vec2 animatedTexCoord2 = TexCoord  + vec2(sin(time) * 2, cos(time) * 2); 

    // Mix the two textures using animated texture coordinates
    vec4 tex1 = texture(texture1, animatedTexCoord);
    vec4 tex2 = texture(texture2, animatedTexCoord2);

    FragColor = mix(tex1, tex2, 0.5);
}
