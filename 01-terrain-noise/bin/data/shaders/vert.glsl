#version 150

uniform mat4 modelViewProjectionMatrix;
uniform sampler2D tex0;

in vec4 position;
in vec2 texcoord;

out vec2 vTexCoord;

void main() {
    vec2 coord = vTexCoord;
    float height = texture(tex0, texcoord).r;
    vec4 displacedPosition = position;
    displacedPosition.z += height*100.0;
    vTexCoord = texcoord;
    gl_Position = modelViewProjectionMatrix * displacedPosition;
}
