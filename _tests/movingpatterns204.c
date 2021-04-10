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

    float y = (smoothstep((sin(-pct2*((cos(sin(st.x)))*tan(0.19022231))+(cos(0.991913212))))*(cos((st.y)*0.20)),(0.0033229005),(0.9132)))/(smoothstep((tan(pct2*((-cos(st.y-st.x))*0.42001)*(cos(2.13212))))*(sin((-st.x+st.y)*.1820)),(0.8229005),(.1732*((cos(-st.y-st.x)*tan(2.93))+(cos(-st.x/st.y)*0.13)))));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));

    float y2 = (smoothstep((-pct2*(sin(st.y/st.x*0.120)*.1519591321)+(sin(.19149913212)))/(tan((-st.x+st.y)*0.20)),0.9229005,0.212832*cos(sin(-st.y+st.x)*0.25020))) / (smoothstep((cos((sin(st.y*(st.x*0.02))*0.1321)+((tan(0.193913212))*cos(u_time)*0.2)))+(cos((st.y)*0.20)),st.y*0.19229005,(.91732*((sin(sin(-st.y-st.x)*u_time)*sin(0.1293))*(sin(-st.x+st.y)*0.13)))));


    vec3 colorA = vec3(y/(sin(st.x*st.y))*1.0);
    vec3 colorB =  colorA + (vec3(y*y2)*1.0);
    
    vec3 colorC = vec3(y-y2)*1.0;
    vec3 colorC2 = vec3(y+y2)*1.0;
    colorB = (1.0)*colorB*vec3(.01289281990*(st.y+(cos(st.x)+cos(st.y*(0.082*cos(-st.y*sin(st.y)))))),0.01294120*sin((st.x*(st.y+(-0.12013+-st.y)))*0.9802),(0.084139230*(cos(y2+st.y*(01.97012))+(-st.y*st.x)))*(asin((1.0+(-st.y*-st.x)))*(.20*cos(-st.y+st.x))));
    // colorC = (1.0)*colorB*vec3(.149281990,0.14120*sin((y*sin(st.y/(st.x+tan(0.3))))*0.02),(0.4139230*(sin(colorC-st.y*(0.1127012))*-st.y)*cos(u_time*(st.y+colorB))));

    vec3 colorSubMix = vec3(0.0);

    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = smoothstep(colorC2*0.1910, (cos(colorC2*0.00193)/tan(colorC2*0.2893))*cos(u_time*.003), (0.92*colorB+(cos(0.0919202)))*sin(u_time*0.193003));


    gl_FragColor = vec4(colorMix,1.0);
}
