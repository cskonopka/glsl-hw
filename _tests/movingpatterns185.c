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

    float y = (smoothstep((sin(-pct2*((sin(st.y+st.x))*0.01)*(cos(0.913212))))*(cos((st.y)*1.20)),(0.1229005),(0.0132)))/(smoothstep((sin(pct2*((cos(st.y-(st.x*st.y)))*0.00942001)/(cos(.0013212))))*(sin((st.x+st.y)*.20)),(0.229005),(.1732*((cos(-st.y-st.x)*sin(20.93))/(cos(-st.x+st.y)*0.3)))));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));

    float y2 = (smoothstep((sin(-pct2*(sin(st.y/st.x)*0.9591321)-(sin(.019913212))))*(tan((-st.x*st.y)*0.20)),0.229005,0.2832/tan(-st.y*st.x*0.020))) / (smoothstep((cos(-pct2*(sin((st.y+st.x)+((st.x+st.y)*0.02))*0.1321)-(tan(0.91913212))))+(cos((st.y)*0.20)),0.9229005*(sin(u_time*0.3)),0.132/(sin(u_time*0.13+st.x)*0.90132/(sin(u_time*0.013+st.y)))));

    vec3 colorB = vec3(y*y2)*1.0;
    vec3 colorC = vec3(y-y2)*1.0;
    vec3 colorC2 = vec3(y+y2)*1.0;
    colorB = (1.0)*colorB*vec3(.089281990*(st.y/(tan(st.x)+cos(st.y*(0.082*cos(-st.y*sin(-st.y)))))),0.01294120*tan((st.x-(st.y+st.x*(-0.92013+-st.y)))*0.02),(0.084139230*(sin(y2-st.y*(01.97012))+(-st.y*st.x)))-(tan((1.0*(-st.y*-st.x)))*(1.20*cos(-st.y*st.x))));
    // colorC = (1.0)*colorB*vec3(.149281990,0.14120*sin((y*sin(st.y/(st.x+tan(0.3))))*0.02),(0.4139230*(sin(colorC-st.y*(0.1127012))*-st.y)*cos(u_time*(st.y+colorB))));


    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix((colorC*0.910)*(sin(u_time*0.21)), (cos(colorC2*0.0193)*tan(colorC2*0.293))*cos(sin(0.91003)*20.3), (0.92*colorB+(cos(0.1919202)))*sin(u_time*0.003));

    gl_FragColor = vec4(colorMix,1.0);
}
