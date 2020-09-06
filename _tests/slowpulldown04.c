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
  return  smoothstep( pct-0.3, pct, st.y*2.0) -
          smoothstep( pct, pct+0.3, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;

    float y = step(st.y*0.40,0.20);
        float y2 = step(st.y*-0.40,3.20);
    // float y = sqrt(st.x*abs(sin(u_time))*1.0);
    // float y = log(st.x*abs(sin(u_time))*10.20);
    // float y = log(st.x*-(abs(sin(u_time*0.1))));

    vec3 color = vec3((y*1.2));

    float pct = plot(st,y);
    color = (1.0-pct*0.12)*color+pct*vec3(1,0.63,0.13);

    gl_FragColor = vec4(color,1.0);
}
