#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 shadowProj;   // Shadow projection matrix

out vec2 TexCoord;
out vec4 ShadowPos;        // Position for shadow rendering
out vec3 FragPosWorld;     // Position in world space for checker pattern

void main()
{
    vec4 worldPosition = model * vec4(aPos, 1.0);
    ShadowPos = shadowProj * worldPosition;  // Apply shadow projection matrix
    FragPosWorld = worldPosition.xyz;        // Pass position for procedural texture

    gl_Position = projection * view * worldPosition;
    TexCoord = aTexCoord;
}
