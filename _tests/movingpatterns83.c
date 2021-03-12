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
    st -= 0.5*cos(0.32);  // becomes -0.5 to 0.5
    st *= 12.0;
    float pct2 = 0.0;
    pct2 = distance(st,vec2(0.5));

    float y3 = sin(cos((st.y)*(5.10)))*sin(st.x*3.12) - tan(sin((st.y)*(-1.10)))*sin(st.x*1.12);
    float y = (smoothstep(.402,0.05,(st.y/st.x)));
    float y2 = (smoothstep(1.1,0.5,(st.y*st.x)+1.2));
    // vec3 colorA = vec3(y*y2)+(y3*(u_time*0.013)) * vec3(-y*-y2)-(-y3*(u_time*-0.013));
    vec3 colorA = vec3(y+y2)+(y3*(cos(u_time*.0113)));
    colorA = (1.0)*colorA*vec3(.81990,0.420,(0.39230+(sin(y3*(u_time*.17012)))));

    float y7 = (cos(acos((st.x)*y2)) * cos(asin((-st.x)*y2))- (cos(cos((st.y)*-y2)) * cos(cos((st.y)+y2))));
    // a. The DISTANCE from the pixel to the center

    vec2 bl = step(vec2(0.5),(st/y7)) * step(vec2(-0.5),(-st*y7));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorA, colorA, ((sin(u_time+((y7*y2+(st.y*st.x))*1.174)-sin(u_time+((-y7*y2*(st.y-st.x))*0.174))+sin((cos((pct2*-0.192)+st.x*st.y)*0.0041))))) + ((sin(u_time*((-y3*y2*(-st.y+st.x))*-0.5174)+sin(u_time+((y7-y2-(st.y))*-0.74))*sin((cos(-pct2*0.92)))))));

    gl_FragColor = vec4(colorMix,1.0);
}
