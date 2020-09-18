// author --> cskonopka
// title ---> "thefallingtwinePushedByBlinds"
// format --> GLSL Sandbox
// link ----> http://glslsandbox.com/e#67721.0

#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 resolution;
uniform float time;

float plot(vec2 st, float pct){
  return  smoothstep( pct-0.02, pct, st.y) -
          smoothstep( pct, pct+0.02, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/resolution;
    float y4=sin(st.x*sin((time*0.20))*PI);
    // Step will return 0.0 unless the value is over 0.5,
    // in that case it will return 1.0
    float y = step(0.0,(st.x*1.3));
    float y2 = pow(st.x,(0.80*y4));
    float y3 = smoothstep(0.2,1.5,st.y) - smoothstep(0.5,0.8,st.x);


    vec3 color = vec3(y*(y3*2.0)*sin((time*st.x)*1.20));

    float pct = plot(st,y*y2);
    color = (1.0-pct)*color+pct*vec3(1.0,1.0*(time*0.2),0.0);

    gl_FragColor = vec4(color,1.0);
}
