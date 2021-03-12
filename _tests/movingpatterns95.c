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

    float y = (smoothstep((cos((st.y)*0.301))/cos((st.x)*0.2301),0.9005,(sin((st.y)*3.301))/sin((st.x)*3.301)));
    float y2 = (smoothstep(1.1,0.5,(st.y*st.x)+1.2));
    float y3 = sin(tan((st.y+(sin(u_time*0.242)+st.x)*0.94)*(0.590)))+sin(st.x*0.12) - tan(sin((st.y)*(-2.13)))+sin(st.y*1.12);
    vec3 colorA = vec3(y)*1.0;
    // vec3 colorA = vec3(y+y2+y3)*1.0;
    // colorA = (1.0)*colorA*vec3(.81990,0.420*cos(st.x),(0.39230+(sin(y3*st.y+(u_time*3.7012)))*PI));

    vec2 bl = step(vec2(0.5),(st));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorA, colorA*0.2, 0.2);

    gl_FragColor = vec4(colorMix,1.0);
}
