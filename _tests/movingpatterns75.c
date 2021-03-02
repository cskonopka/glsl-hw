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

    float y3 = sin(cos((st.y)*(5.10)))*-sin(st.x*3.12) - sin(-cos((-st.x)*(-2.10)))*sin(st.x*-0.12);
    float y = (smoothstep(.02,0.05,st.x) );
    float y2 = (smoothstep(1.1,0.5,st.x));
    // vec3 colorA = vec3(y*y2)+(y3*(u_time*0.013)) * vec3(-y*-y2)-(-y3*(u_time*-0.013));
    vec3 colorA = vec3(y*y2)*(y3*(u_time*2.013));
    colorA = (1.0)*colorA*vec3(.90,0.920,(1.0+(sin(y3+(u_time*.012)))));

    float y4 = cos(cos((st.y-st.x)*(sin(u_time*0.1913))*cos(0.43*st.x+st.y)));
    float y5 = (smoothstep(0.19,0.295,st.x-st.y+cos(st.x*-st.y)) * smoothstep(0.4,0.1,st.x*st.y));
    float y6 = (smoothstep(0.1,0.8915,-st.y*cos((-st.x*-st.y))) * smoothstep(0.4,0.091,st.y-st.x))*smoothstep(0.151,0.915,st.y+cos(st.x*st.y)) - smoothstep(0.14,.291,st.y+st.x);
    vec3 colorB = (vec3((y4+y5)*st.y+st.x))+(y3*(0.913)) * ((vec3(-y4-y5)*(-y3+(0.23+(st.y*st.x)))));
    colorB = (1.0)*colorB*vec3(3.1755,0.147,(-1.20+(y6+(st.y*st.x)))) - (1.0)*colorB*vec3(-0.215,-0.1847,(0.20-(-y6-(st.y*st.x))));

    float y7 = (cos(cos((st.x)*y2)) * cos(cos((-st.x)*y2))- (cos(cos((st.y)*-y2)) * cos(cos((-st.y)*y2))));
    // a. The DISTANCE from the pixel to the center

    vec2 bl = step(vec2(0.5),(st+y7)) * step(vec2(-0.5),(-st-y7));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorA, colorB, ((sin(u_time+((y6*y2+(st.y*st.x))*1.174)-sin(u_time+((-y6*y2*(st.y-st.x))*0.74))+sin((cos((pct2*-0.192)+st.x*st.y)*0.0041))))) * ((-sin(u_time*((-y6*y2*(-st.y*st.x))*-0.174)+sin(u_time+((y6-y2-(st.y))*-0.74))*sin((cos(-pct2*0.92)))))));

    gl_FragColor = vec4(colorMix,1.0);
}
