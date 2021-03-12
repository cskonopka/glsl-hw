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

    float y = (smoothstep((sin((sin(st.y*st.x))*(PI*cos(u_time*0.13212))))*(sin((st.x)*0.20)),2.29005,0.32));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));
    float y2 = cos((smoothstep(1.1,0.5,(st.y/st.x)+1.2)));
    float y3 = sin(tan((st.y+(PI*sin(u_time*0.242)+st.x)*0.94)+(0.590)))+sin(st.x*0.12) + cos(sin((st.y)*(-2.13)))+sin(PI*st.y*1.12);
    // vec3 colorA = vec3(y)*1.0;
    vec3 colorA = vec3(y+y2+y3)*1.0;
    colorA = (1.0)*colorA*vec3(.281990,0.4120*+cos(st.x),(0.139230*(sin(y3+st.y*(u_time*0.27012)))));

    float y4 = (smoothstep((sin((sin(st.y*st.x))*(PI*cos(u_time*0.13212))))*(sin((st.x)*0.20)),20.29005,0.32));
    // float y = (smoothstep((cos((sin(st.y))+u_time*0.3212))/(cos((st.x)*0.2301)),0.9005,(sin((st.y)*3.301))/sin((st.x)*.301)));
    float y5 = (smoothstep(1.1,0.5,(st.y/st.x)+1.2));
    float y6 = cos(((st.y+(sin(u_time*0.242)+st.x)*2.94)+(0.590)))*sin(st.x*2.12) + cos(sin((st.y)*(-2.13)))+sin(PI*st.y*1.12);


    vec3 colorB = vec3(y4+y5+y6)*1.0;
    colorB = (1.0)*colorB*vec3(0.8281990,0.404120*cos(st.x*st.y),(1.139230*(cos(y3+st.y*(u_time*0.27012)))));


    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorB, colorA*2.2, 0.2);

    gl_FragColor = vec4(colorMix,1.0);
}
