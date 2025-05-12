#version 120

attribute vec3 vertexPos;
attribute float colorIndex;

varying vec3 fragmentColor;
varying vec2 fragmentTexCoord;

const vec3 colors[4] = vec3[4](
    vec3(1.0, 0.0, 0.0), // Red
    vec3(0.0, 1.0, 0.0), // Green
    vec3(0.0, 0.0, 1.0),  // Blue
    vec3(0.5, 0.5, 0.0)  // Gray
);

void main() {
    gl_Position = vec4(vertexPos, 1.0);
    fragmentColor = colors[int(colorIndex)];
    fragmentTexCoord = 0.5*vertexPos.xy + 0.5;
}