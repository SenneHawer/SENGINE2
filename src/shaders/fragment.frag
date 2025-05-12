#version 120

varying vec3 fragmentColor;
varying vec2 fragmentTexCoord;

uniform sampler2D material;   //0
uniform sampler2D mask;             //1

void main() {
    vec3 baseColor = texture2D(material, fragmentTexCoord).rgb;
    float alpha = texture2D(mask, fragmentTexCoord).r;
    gl_FragColor = vec4(baseColor, alpha);
}
