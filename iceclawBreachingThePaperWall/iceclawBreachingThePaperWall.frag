// author --> cskonopka
// title ---> "blueiceclawBreachingThePaperWall"
// format --> Fragment Shader
// link ----> http://glslsandbox.com/e#72178.1

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;

float plot(vec2 st, float pct){
  return  smoothstep( pct-0.02, pct, st.y) -
          smoothstep( pct, pct+0.02, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/resolution;
    st -= 1.80*cos(0.32);  // becomes -0.5 to 0.5
    st *= 12.0;
    float pct2 = 0.0;
    pct2 = distance(st,vec2(0.5));

    float y = (smoothstep((sin(-pct2*((sin(st.y+st.x))*0.231)/(cos(0.91913212))))/(tan((-st.y)*0.20)),(0.133229005),(0.9132)))/(smoothstep((sin(pct2*((-cos(st.y-st.x))*0.42001)*(asin(2.13212))))*(sin((-st.x+st.y)*.1820)),(0.8229005),(.1732*((cos(st.x/-st.y)*cos(2.93))/(cos(-st.x+st.y)*0.3)))));
    float y2 = (smoothstep((tan(-pct2*(sin(st.y/st.x*2.0)*.01519591321)/(sin(.1149913212))))*(tan((-st.x/st.y)*0.10)),0.9229005,0.12832*cos(-st.y*st.x*0.5020))) / (smoothstep((cos(-pct2*(sin(st.y*(st.x*0.02))*0.1321)-(tan(0.1913212))))+(tan((st.y)*0.20)),st.y/0.19229005,(.1732*((cos(-st.y-st.x)*cos(2.293))/(cos(-st.x+st.y)*0.3)))));

    vec3 colorB = vec3(y*y2)*1.0;
    
    vec3 colorC = vec3(y-y2)*1.0;
    vec3 colorC2 = vec3(y+y2)*1.0;
    colorB = (1.0)*colorB*vec3(.289281990*(st.y+(tan(st.x)+cos(st.y*(0.082*cos(-st.y*cos(st.y)))))),0.01294120*tan((st.x-(st.y-st.x*(-0.92013+-st.y)))*0.02),(0.084139230*(sin(y2-st.y*(01.97012))+(-st.y*-st.x)))-(tan((1.0*(-st.y*-st.x)))*(1.20*cos(-st.y*st.x))));

    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = smoothstep(colorC*0.01910, (cos(colorC2*0.10193)*tan(colorC2*0.893))*cos(time*.003), (0.92*colorB+(cos(0.1919202)))*sin(time*0.003));


    gl_FragColor = vec4(colorMix,1.0);
}
