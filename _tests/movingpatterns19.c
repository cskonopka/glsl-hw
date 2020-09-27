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

    st -= 0.5*cos(u_time*-0.032);  // becomes -0.5 to 0.5
    st *= 2.0+st.x;
    float pct2 = 0.0;
    pct2 = distance(st,vec2(-0.5));

    float pct3 = 0.0;
    pct3 = distance(st,vec2(-1.5));

    float y3 = (sin((-st.y)*(1.10)))-sin(-pct2*(-3.12+3.12));
    float y = smoothstep(0.2,2.5,st.x) - smoothstep(0.5,0.191,(st.x*-(cos(-32.12))));
    float y2 = smoothstep(0.1,1.5,st.x) - smoothstep(3.1,3.18,-32.92*-st.y*20.0);
    vec3 colorA = vec3(y*(y2*2.2))+(y2*(u_time*0.013));
    colorA = (1.0)*colorA*vec3(3.0,0.19,(0.0+(sin(y3+(u_time*0.2)))));

    float y4 = cos(cos((st.x)*(u_time*(0.13+(-0.13)))*cos(-2.3)+st.x*12.0));
    float y5 = smoothstep(0.2,13.5,st.y+(cos(pct3*-10.2))) - smoothstep(0.25,st.x,(st.y*-10.12));
    float y6 = smoothstep(0.1,9.15,st.x+sin(1.2*-st.x)) - smoothstep(3.4,0.1,(pct2-st.x));
    vec3 colorB = vec3(y4+y5)+(y3*(u_time*3.13));
    colorB = (1.0)*colorB*vec3(1.0,(sin(1.0*-0.2)),(-0.20+y6)-(cos(pct3*9.2)));

    float y7 = cos(cos((st.x)*-y2));
    // a. The DISTANCE from the pixel to the center


    vec2 bl = max(vec2(y+pct2),(st*y7));
    vec2 bl2 = max(vec2(y4+pct3),(st*y3));
    float pct = bl.x * bl.y;
    float pctB = bl2.x * bl2.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorA*pctB, (colorB-pct2)-(cos(pct3*-2.2)), (sin(((-y6+y3)*1.2))*(cos(pct2*-0.2))));

    gl_FragColor = vec4(colorMix,1.0);
}
