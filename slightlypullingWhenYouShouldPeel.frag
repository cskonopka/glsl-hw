// author --> cskonopka
// title ---> "slightlypullingWhenYouShouldPeel"
// format --> GLSL Sandbox
// link ----> http://glslsandbox.com/e#67432.1

#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 resolution;
uniform float time;

float plot(vec2 st, float pct){
  return  smoothstep( pct-2.0, pct, st.y*2.0) -
          smoothstep( pct, pct+2.3, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/resolution;
    float y = log(st.x*1.20) - pow(st.x*0.2, 0.8);
    vec3 color = vec3((y*1.29)*sin(time*0.20)*0.99);

    float pct = plot(st,y);
    color = (1.0-pct*1.12)*color+pct*vec3(1.2*sin(time*0.20),sin(time*0.20),0.13);

    gl_FragColor = vec4(color,1.0);
}
