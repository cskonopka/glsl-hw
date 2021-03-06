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

    float y3 = sin(cos((st.y)*(0.10)))-sin(st.x*0.12);
    float y = (smoothstep(1.2,0.5,st.x) - smoothstep(0.5,0.91,(st.x*-0.12)))+smoothstep(1.2,0.5,st.x) * smoothstep(0.5,0.91,(st.x*-0.12));
    float y2 = smoothstep(1.1,0.5,st.y) - smoothstep(0.1,0.18,st.y);
    vec3 colorA = vec3(y*y2)+(y3*(u_time*0.013));
    colorA = (1.0)*colorA*vec3(0.0,0.920,(0.0+(sin(y3+(u_time*0.2)))));

    float y4 = cos(cos((st.y-st.x)*(sin(u_time*0.1913))*cos(0.43*st.x+st.y))) * cos(cos((-st.y+st.x)*(sin(u_time*-0.1913))*cos(9.3)));
    float y5 = (smoothstep(0.91,0.295,st.x-st.y+cos(st.x*-st.y)) * smoothstep(0.4,0.1,st.x))*smoothstep(0.91,0.15,st.y-cos(st.y)) + smoothstep(0.4,0.1,-st.x);

    float y6 = (smoothstep(0.91,0.15,-st.y+cos(-st.y)) - smoothstep(0.4,0.1,st.y-st.x))*smoothstep(0.91,0.15,st.y+cos(st.y)) - smoothstep(0.4,0.1,st.x);
    vec3 colorB = vec3(y4+y5)+(y3*(u_time*0.13)) * vec3(y4*y5)+(y3+(u_time*-0.93));
    colorB = (1.0)*colorB*vec3(1.0,1.0,(-0.20+y6));

    float y7 = cos(cos((st.x)*-y2));
    // a. The DISTANCE from the pixel to the center

    vec2 bl = step(vec2(0.5),(st+y7));
    float pct = bl.x * bl.y;
    vec3 colorMix = vec3(0.0);
    colorMix = mix(colorA, colorB, (sin(u_time*((y6+y2)*0.74))*(cos(pct2*-0.92))));

    gl_FragColor = vec4(colorMix,1.0);
}
