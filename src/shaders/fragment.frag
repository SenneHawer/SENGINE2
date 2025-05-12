#version 120

varying vec3 fragmentColor;
varying vec2 fragmentTexCoord;

uniform sampler2D textureSampler;

void main() {
    gl_FragColor = texture2D(textureSampler, fragmentTexCoord);
}
