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

    float y = (smoothstep((sin(-pct2*((sin(st.y+st.x))*0.01)*(cos(0.913212))))*(tan((st.x)*00.20)),(0.229005),(0.32)))/(smoothstep((sin(pct2*((cos(st.y+st.x))*0.2001)*(cos(0.913212))))*(sin((st.x)*01.20)),(0.229005),(0.32)));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));

    float y2 = (smoothstep((sin(-pct2*(sin(st.y/st.x)*0.9591321)-(sin(.1913212))))*(tan((-st.x+st.y)*1.20)),0.229005,0.2832/cos(-st.y*st.x*0.020))) / (smoothstep((cos(-pct2*(sin(st.y*(st.x*0.02))*0.1321)-(tan(0.13212))))+(cos((st.y)*0.20)),0.229005,0.32));

    vec3 colorB = vec3(y*y2)*1.0;
    vec3 colorC = vec3(y-y2)*1.0;
    vec3 colorC2 = vec3(y+y2)*1.0;
    colorB = (1.0)*colorB*vec3(.189281990,0.294120*tan((st.x*st.y)*0.02),(0.084139230*(sin(y2-st.y*(0.7012))+st.x))+tan((12.0*u_time*(-st.y-st.x)))+ (12.0*u_time*(-st.y+st.x)));
    colorC = (1.0)*colorB*vec3(.149281990,0.14120*cos((st.x-sin(u_time*st.y+(st.x+tan(0.3))))*0.02),(0.4139230*(sin(y+st.y*(0.127012))+st.y)));


    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorC*0.0, colorB*0.93, (0.2*sin(u_time*0.02))*colorC2);

    gl_FragColor = vec4(colorMix,1.0);
}
