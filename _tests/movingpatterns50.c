#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plot(vec2 st, float pct){
  return  smoothstep( pct-0.02, pct, st.y) -
          smoothstep( pct, pct+0.02, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;

    // Smooth interpolation between 0.1 and 0.9
    // float y = smoothstep(0.02,0.12,(st.x*0.2));

    float pct2 = 0.0;
    pct2 = distance(st,vec2(0.5));

    float y3 = sin(cos((st.y)*(cos((u_time*0.02)+0.10))));
    float y = smoothstep(0.2,0.5,st.x) - smoothstep(0.5,0.1,(st.x*0.2));
    float y2 = smoothstep(0.1,0.5,st.y) - smoothstep(0.1,0.18,st.y);
    vec3 colorA = vec3(y*y2)+(y3*(u_time*0.3));
    colorA = (1.0)*colorA*vec3(0.0,0.20,(0.0+(sin(y3+u_time))));




    gl_FragColor = vec4(colorA,1.0);
}
