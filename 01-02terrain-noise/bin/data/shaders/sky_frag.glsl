#version 150

uniform vec2 uResolution;
out vec4 outputColor;

float circleSmooth(in vec2 st, in vec2 pos, in float begin, in float end) {
    float pct = 0.0;
    pct = 1. - smoothstep(begin, end, distance(st, pos));
    return pct;
}


void main(){
    vec2 sunPos = vec2(0.9,0.9);
    vec2 uv = gl_FragCoord.xy / uResolution.xy;
    uv.x *= uResolution.x / uResolution.y;
    vec3 color = vec3(0.1, 0.4, 0.9);
    color += vec3(0.5,0.6-uv.y, 0.9);
    color.rg += circleSmooth(uv, vec2(sunPos), 0.05, 0.15 + 0.2);
    outputColor = vec4(color, 1.0);
}
