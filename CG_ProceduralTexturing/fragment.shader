
//------ Checker Pattern ------

// #version 330 core
// out vec4 FragColor;

// in vec2 TexCoord;

// uniform float time; // Time uniform for potential animation

// void main()
// {
//     // Procedural checkerboard texture
//     float scale = 10.0; // Controls the size of the checkers
//     float checker = mod(floor(TexCoord.x * scale) + floor(TexCoord.y * scale), 2.0);

//     // Alternate colors for the checkers
//     vec3 color1 = vec3(1.0, 0.5, 0.0); // Orange
//     vec3 color2 = vec3(0.2, 0.2, 0.2); // Dark gray

//     // Mix between the two colors based on checker pattern
//     vec3 finalColor = mix(color1, color2, checker);

//     FragColor = vec4(finalColor, 1.0); // Output final color with full opacity
// }


//------ Strips Pattern --------

#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time; // Time uniform for animation

void main()
{
    // Stripes along the x-axis
    float stripes = abs(sin(TexCoord.x * 20.0 + time));

    // Alternate between two colors based on the stripe intensity
    vec3 color1 = vec3(0.0, 0.0, 1.0); // Blue
    vec3 color2 = vec3(1.0, 1.0, 1.0); // White

    vec3 finalColor = mix(color1, color2, stripes);
    FragColor = vec4(finalColor, 1.0);
}

//-------- Radial Gradient Pattern -------
/*
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time;

void main()
{
    // Calculate distance from the center (0.5, 0.5)
    vec2 center = vec2(0.5, 0.5);
    float dist = distance(TexCoord, center);

    // Create a radial gradient based on the distance
    vec3 color1 = vec3(0.0, 0.0, 1.0); // Blue at center
    vec3 color2 = vec3(1.0, 1.0, 1.0); // White at edges

    vec3 finalColor = mix(color1, color2, dist);
    FragColor = vec4(finalColor, 1.0);
}
*/


//------- Circular Wave Pattern (Animated) --------

// #version 330 core
// out vec4 FragColor;

// in vec2 TexCoord;

// uniform float time;

// void main()
// {
//     // Calculate distance from the center
//     vec2 center = vec2(0.5, 0.5);
//     float dist = distance(TexCoord, center);

//     // Create circular waves based on distance and time
//     float wave = sin(dist * 40.0 - time * 5.0);

//     // Color pattern
//     vec3 color1 = vec3(0.0, 1.0, 1.0); // Cyan
//     vec3 color2 = vec3(0.0, 0.0, 0.0); // Black

//     vec3 finalColor = mix(color1, color2, wave);
//     FragColor = vec4(finalColor, 1.0);
// }


//------- Checkerboard with Circular Gradient -------
/*
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time;

void main()
{
    // Checkerboard pattern
    float scale = 10.0;
    float checker = mod(floor(TexCoord.x * scale) + floor(TexCoord.y * scale), 2.0);

    // Circular gradient based on distance from center
    vec2 center = vec2(0.5, 0.5);
    float dist = distance(TexCoord, center);

    // Mix colors based on checker and radial gradient
    vec3 color1 = vec3(0.0, 0.8, 0.2); // Green
    vec3 color2 = vec3(0.2, 0.0, 0.5); // Purple

    vec3 finalColor = mix(color1, color2, checker * dist);
    FragColor = vec4(finalColor, 1.0);
}
*/

//------- Noise-Like Pattern ---------
/*
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time;

// Simple hash function for noise generation
float hash(vec2 p) {
    return fract(sin(dot(p ,vec2(12.9898,78.233))) * 43758.5453);
}

void main()
{
    // Scale texture coordinates for finer noise
    vec2 scaledCoord = TexCoord * 10.0;

    // Calculate noise by hashing the texture coordinates
    float noiseValue = hash(scaledCoord + time);

    // Use noise value to generate color
    vec3 finalColor = vec3(noiseValue);

    FragColor = vec4(finalColor, 1.0);
}
*/

//------ Marble Pattern -------
/*
#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time;

void main()
{
    // Distort the texture coordinates to create a marble effect
    vec2 coord = TexCoord * 10.0;
    float marble = sin(coord.x + sin(coord.y + time) * 2.0);

    // Map the result to colors
    vec3 color1 = vec3(0.8, 0.8, 0.8); // Light gray
    vec3 color2 = vec3(0.1, 0.1, 0.1); // Dark gray

    vec3 finalColor = mix(color1, color2, marble);
    FragColor = vec4(finalColor, 1.0);
}
*/


//------- Wood Grain Pattern -------

/*#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform float time;

void main()
{
    // Calculate distance from the center to simulate rings
    vec2 center = vec2(0.5, 0.5);
    float dist = distance(TexCoord, center) * 10.0;

    // Create rings by using sine of distance
    float rings = sin(dist - time);

    // Simulate wood grain by combining sine waves
    float grain = rings + 0.1 * sin(dist * 10.0);

    // Color based on wood grain effect
    vec3 color1 = vec3(0.6, 0.4, 0.1); // Brown
    vec3 color2 = vec3(0.4, 0.2, 0.05); // Darker brown

    vec3 finalColor = mix(color1, color2, grain);
    FragColor = vec4(finalColor, 1.0);
}*/
