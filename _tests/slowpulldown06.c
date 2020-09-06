

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
    vec3 colormix = vec3(0.0);

    vec2 st = gl_FragCoord.xy/u_resolution;
    float y = exp(st.x*-(abs(sin(u_time*0.1)*2.2)));
    vec3 color = vec3((y*1.1)*abs(sin(u_time)*0.19));
    float pct = plot(st,y);
    color = (1.0-pct*2.2)*color+pct*vec3(1,0.3,0.3);

    // gl_FragColor = vec4(color,1.0);

    vec2 st2 = gl_FragCoord.xy/u_resolution;
    float y2 = exp(st2.x*-(abs(sin(u_time*0.01)*1.2)));
    vec3 color2 = vec3((y2*1.1)*abs(sin(u_time)*2.19));
    float pct2 = plot(st2,y2*sin(u_time)*0.819);
    color2 = (1.0-pct2*2.2)*color2+pct2*vec3((abs(sin(u_time*0.31))),0.3,0.3*abs(sin(u_time)*2.19));


    colormix = mix(color, color2, pct);

    gl_FragColor = vec4(colormix,1.0);


}
