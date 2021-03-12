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
    st -= 1.80*cos(0.32);  // becomes -0.5 to 0.5
    st *= 12.0;
    float pct2 = 0.0;
    pct2 = distance(st,vec2(0.5));

    float y = (smoothstep((sin(+pct2+(sin(st.y+st.x))*(cos(u_time*0.13212))))*(tan((st.x)*0.20)),0.229005,0.32));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));

    float y2 = (smoothstep((sin(-pct2*(sin(st.y/st.x)*0.1321)-(sin(0.013212))))+(tan((st.x)*0.20)),0.229005,0.32/cos(-st.y+st.x))) / (smoothstep((cos(-pct2*(sin(st.y*(st.x*0.02))*0.1321)-(cos(u_time*0.13212))))+(sin((st.x)*0.20)),0.229005,0.32));

    vec3 colorB = vec3(y*y2)*1.0;
    colorB = (1.0)*colorB*vec3(.9281990,0.94120*cos((st.x*st.y)*0.02),(0.4139230*(sin(y2+st.y*(u_time*0.27012))+st.x)));
    colorB = (1.0)*colorB*vec3(.9281990,0.94120*tan((st.x*st.y)*0.02),(0.4139230*(sin(y2+st.y*(u_time*0.27012))+st.x)));


    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorB, colorB, 0.2);

    gl_FragColor = vec4(colorMix,1.0);
}
