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
    pct2 = distance(st,vec2(0.15));

    float y3 = sin(cos((st.y)*0.2));
    float y = smoothstep(0.2,0.5,st.x) - smoothstep(0.5,0.1,(st.x*0.2));
    float y2 = smoothstep(0.1,0.5,st.y) - smoothstep(0.1,0.18,st.y);
    vec3 colorA = vec3(y2*y3)+(y*(u_time*0.13));
    colorA = (1.0)*colorA*vec3(1.0,1.0,(0.8+(sin(y2+u_time))));

    float y4 = fract(cos((st.x)*(u_time*0.3)/18.0));
    float y5 = smoothstep(0.2,0.5,st.y) - smoothstep(0.15,0.1,(st.y*0.2));
    float y6 = smoothstep(0.1,0.15,st.x) - smoothstep(0.11,0.8,st.x);
    vec3 colorB = vec3(y4*y5)+(y3*(u_time*0.13));
    colorB = (1.0)*colorB*vec3(1.0,0.0,(0.120+y6));

    vec2 bl = step(vec2(0.5),st);
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorA, colorB, (sin(u_time*(y6*0.12))*pct2));

    gl_FragColor = vec4(colorMix,1.0);
}
