#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

vec3 colorA = vec3(0.149,0.141,0.912);
vec3 colorB = vec3(1.000,0.833,0.224);

#define PI 3.14159265359


float plot(vec2 st) {    
    return smoothstep(abs(sin(u_time)*0.02), 1.0, abs(cos(u_time*0.1)*st.y - sin(u_time*0.11)*st.x));
}

void main() {
	vec2 st = gl_FragCoord.xy/u_resolution;

    float y = st.x*cos(u_time)*-32.01;

    vec3 color = vec3(y);

    // plot with ABS sinewave
    float pct = plot(st);
    // float pct = sin(u_time)*0.2;
    color = (1.0-pct)*color+pct*(vec3(100.00,9.20,abs(sin(u_time)*0.2))*vec3(abs(sin(u_time)*0.10), 1.3, abs(sin(u_time)*122.28)));

    // vec3 color = vec3(0.0);



    // // Mix uses pct (a value from 0-1) to
    // // mix the two colors
    color = mix(colorA, colorB, pct);

    gl_FragColor = vec4(color,1.0);
}