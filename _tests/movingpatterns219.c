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

    float y = (smoothstep((tan(-pct2*((cos(sin(st.x)))*tan(0.19022231))+(cos(0.2091913212))))*(tan((st.y)*0.20)),(0.90033229005),(2.9132)))/(smoothstep((tan(pct2*((-cos(st.y-st.x))*0.042001)*(cos(2.13212))))*(sin((-st.x+st.y)*.820)),(0.8229005),(.1732*((cos(-st.y-st.x)*tan(0.93))+(cos(-st.x/st.y)*0.13)))));

    vec3 colorA = vec3(y/(sin(st.x*st.y))*1.0);
    vec3 colorB =  colorA + (vec3(y)*1.0);
    
    vec3 colorC = vec3(y-colorA)*1.0;
    colorB = (1.0)*colorB*vec3(.301289281990*(st.y+(cos(st.x)+cos(st.y*(0.082*cos(-st.y*sin(st.y)))))),0.01294120*sin((st.x*(st.y+(-0.92013+-st.y)))*0.1802),(0.084139230*(cos(y+st.y*(01.97012))+(-st.y*st.x)))+(tan((1.0*(-st.y*-st.x)))*(.20*cos(-st.y+st.x))));

    vec3 colorSubMix = vec3(0.0);

    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = smoothstep(colorC*0.01910, (cos(colorC*0.10193)/cos(colorC*0.1893))*cos(u_time*.3003), (0.192*colorB+(cos(0.1919202)))*sin(u_time*0.193003));


    gl_FragColor = vec4(colorMix,1.0);
}
