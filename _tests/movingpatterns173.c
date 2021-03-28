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

    float y = (smoothstep((tan(-pct2*((cos(sin(st.x)))*tan(0.022231))+(cos(0.091913212))))*(tan((st.y)*0.20)),(0.133229005),(1.09132)))/(smoothstep((tan(pct2*((-cos(st.y-st.x))*0.142001)*(cos(2.13212))))*(sin((-st.x+st.y)*.820)),(0.18229005),(.1732*((cos(-st.y/st.x)*tan(0.093))+(cos(-st.x/st.y)*.013)))));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));

    float y2 = (smoothstep((-pct2*(sin(st.y/st.x*0.20)*.1519591321)+(sin(.249913212)))+(tan((-st.x+st.y)*0.120)),0.19229005,0.32*cos(-st.y*st.x*0.01125020))) / (smoothstep((cos((sin(-st.y+(st.x+0.02))*0.1321)+((tan(0.93913212))*cos(u_time)*0.2)))+(cos((st.y)*0.120)),st.y*0.019229005,(.1732*((cos(-st.y-st.x)*tan(0.293))+(sin(-st.x+st.y)*0.13)))));


    // vec3 colorA = vec3(y*y2)*1.0;
    vec3 colorB = vec3(y*y2)*1.0;
    
    vec3 colorC = vec3(y-y2)*1.0;
    vec3 colorC2 = vec3(y+y2)*1.0;
    colorB = (1.0)*colorB*vec3(.0289281990*(st.y+(cos(st.x)+cos(st.y*(0.082*cos(-st.y*sin(st.x)))))),0.01294120*((st.x*(st.y+(-0.092013+-st.y)))*0.01802),(0.084139230*(tan(y2+st.y*(01.97012))+(-st.y*st.x)))*(tan((1.0*(-st.y*-st.x)))*(.020*sin(-st.y+st.x))));
    // colorC = (1.0)*colorB*vec3(.149281990,0.14120*sin((y*sin(st.y/(st.x+tan(0.3))))*0.02),(0.4139230*(sin(colorC-st.y*(0.1127012))*-st.y)*cos(u_time*(st.y+colorB))));

    vec3 colorSubMix = vec3(0.0);

    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = smoothstep(colorC2*0.01910, (cos(colorC2*0.10193)/tan(colorC2*0.893))*cos(u_time*.003), (0.92*colorB+(cos(0.01919202)))*sin(u_time*0.193003));


    gl_FragColor = vec4(colorMix,1.0);
}
