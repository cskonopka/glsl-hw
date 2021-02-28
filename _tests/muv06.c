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
    float pct2 = 0.0;
    pct2 = distance(st,vec2(0.5));
    float y = (smoothstep(0.2,0.95,st.x) - smoothstep(0.15,0.1,(st.x*0.32))) * (smoothstep(0.2,0.95,st.y-st.x) - smoothstep(0.15,0.1,(st.y-st.x*0.532)));
    float y2 = (smoothstep(0.1,0.15,st.y) - smoothstep(0.1,0.918,st.y));
    vec3 colorA = vec3((y2+y)*(y2-y));
    colorA = (1.0)*colorA*vec3(0.8,0.1520,(0.140+((sin(y+u_time)+(sin(-y+u_time))))));
    gl_FragColor = vec4(colorA,1.0);
}