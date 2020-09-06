// Author: Inigo Quiles
// Title: Expo

#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plot(vec2 st, float pct){
  return  smoothstep( pct-0.02, pct, st.y*2.0) -
          smoothstep( pct, pct+0.02, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;

    // float y = pow(st.x*abs(sin(u_time))*1.0,5.0);
    float y = exp(st.x*-(abs(sin(u_time*0.1)*2.2)));

    vec3 color = vec3((y*1.1)*abs(sin(u_time)*0.19));

    float pct = plot(st,y);
    color = (1.0-pct*2.2)*color+pct*vec3(1,0.3,0.3);

    gl_FragColor = vec4(color,1.0);
}
