#version 150

uniform sampler2D tex0;
in vec2 vTexCoord;

uniform vec2 uMousePos;
uniform vec2 uResolution;
out vec4 outputColor;

void main(){
    // draw texture, usefull for debug
    vec2 coord = vTexCoord;
    outputColor = texture(tex0, coord);
}
