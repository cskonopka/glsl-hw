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
  return  smoothstep( pct-2.0, pct, st.y*2.0) -
          smoothstep( pct, pct+2.3, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;

    // float y = pow(st.x*abs(sin(u_time))*1.0,5.0);
    // float y = sqrt(st.x*abs(sin(u_time*.0))*1.0);
    float y = log(st.x*1.20) - pow(st.x*0.2, 0.8);
    // float y = log(st.x*-(abs(sin(u_time*0.1))));

    vec3 color = vec3((y*1.29)*sin(u_time*0.20)*0.99);

    float pct = plot(st,y);
    // color = (1.0-pct*1.12)*color+pct*vec3(1.2*sin(u_time*0.20),sin(u_time*0.20),0.13);
    color = (1.0-pct*1.12)*color+pct*vec3(1.2*sin(u_time*0.20),sin(u_time*0.20),0.13);
    // color = (1.0-pct)*color+pct*(vec3(100.00,9.20,abs(sin(u_time)*0.2))*vec3(abs(sin(u_time)*0.10), 1.3, abs(sin(u_time)*0.28)));

    gl_FragColor = vec4(color,1.0);
}
