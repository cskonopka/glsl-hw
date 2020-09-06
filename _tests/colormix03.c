#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

vec3 colorA = vec3(0.149,0.141,0.912);
vec3 colorB = vec3(1.000,0.833,0.224);

void main() {
    vec3 color,colormiddle = vec3(0.0);

    float pct = abs(sin(u_time));
    float pct2 = abs(sin(u_time)*0.03);

    // Mix uses pct (a value from 0-1) to
    // mix the two colors
    color = mix(colorA, colorB, pct);

    colormiddle = mix(color, colorB, pct2*0.3);

    gl_FragColor = vec4(colormiddle,1.0);
}