// author --> cskonopka
// title ---> "thehandlemalfunctionedOnYourBackWatchingThePropeller"
// link ----> http://glslsandbox.com/e#67435.2

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 resolution;
uniform float time;

float plot(vec2 st) {    
    return smoothstep(abs(sin(time)*0.02), 1.0, abs(cos(time*0.1)*st.y - sin(time*0.11)*st.x));
}

void main() {
	vec2 st = gl_FragCoord.xy/resolution;
    float y = st.x*cos(time)*0.01;
    vec3 color = vec3(y);
    float pct = plot(st);
    color = (1.0-pct)*color+pct*(vec3(100.00,9.20,abs(sin(time)*0.2))*vec3(abs(sin(time)*0.10),1.3,abs(sin(time)*122.28)));
	gl_FragColor = vec4(color,1.0);
}
