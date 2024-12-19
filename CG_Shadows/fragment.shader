#version 330 core
out vec4 FragColor;

in vec2 TexCoord;
in vec4 ShadowPos;
in vec3 FragPosWorld;

uniform vec3 color1;          // Light checker color
uniform vec3 color2;          // Dark checker color
uniform vec3 shadowColor;     // Color to darken shadowed areas
uniform vec2 checkerSize;     // Size of checker squares

void main()
{
    // Checker pattern calculation
    float patternX = floor(FragPosWorld.x / checkerSize.x);
    float patternZ = floor(FragPosWorld.z / checkerSize.y);
    float checker = mod(patternX + patternZ, 2.0);

    // Base color from checker pattern
    vec3 baseColor = mix(color1, color2, checker);

    // Check if the fragment is in shadow by looking at shadow projection
    bool isInShadow = ShadowPos.y < 0.01 && ShadowPos.z < 0.0; // Ensure y close to ground and z in valid range

    // Apply shadow color if in shadow, otherwise regular checker color
    if (isInShadow)
    {
        FragColor = vec4(baseColor * shadowColor, 1.0); // Darken checker color in shadow
    }
    else
    {
        FragColor = vec4(baseColor, 1.0);
    }
}
