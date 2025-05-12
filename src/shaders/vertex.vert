#version 120

attribute vec3 vertexPos;
attribute float colorIndex;

varying vec3 fragmentColor;

const vec3 colors[3] = vec3[3](
    vec3(1.0, 0.0, 0.0), // Red
    vec3(0.0, 1.0, 0.0), // Green
    vec3(0.0, 0.0, 1.0)  // Blue
);

void main() {
    gl_Position = vec4(vertexPos, 1.0);
    fragmentColor = colors[int(colorIndex)];
}