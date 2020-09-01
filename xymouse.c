#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

void main() {
	vec2 st = gl_FragCoord.xy/u_resolution;
    vec2 mu = gl_FragCoord.xy/u_mouse;
	gl_FragColor = vec4(st.x,(st.y*mu.y),mu.x,1.0);
}
