#version 150

uniform sampler2D uTex0;
in vec2 vTexCoord;
in vec3 vNormal;

out vec4 outputColor;

vec3 lightDirection = vec3(0.702, 1.9686, 0.6745);

float clampeddot(vec3 a, vec3 b){
    return max(0.,dot(a, b));
}

float diffuse(vec3 normal){
    float ambient = 0.8;
    return clamp( clampeddot(normal, lightDirection) * ambient + ambient, 0.0, 1.0 );
}


void main(){
    float diffLight = diffuse(vNormal);
    // draw texture, usefull for debug
    vec2 coord = vTexCoord;

    vec4 texColor = texture(uTex0, coord);
    outputColor = vec4(texColor.xyz * diffLight, 1.0);
}
