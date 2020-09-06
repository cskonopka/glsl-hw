#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plot(vec2 st) {    
    return smoothstep(abs(sin(u_time)*0.02), 1.0, abs(cos(u_time*0.1)*st.y - sin(u_time*0.11)*st.x));
}

void main() {
	vec2 st = gl_FragCoord.xy/u_resolution;

    float y = st.x*cos(u_time)*0.01;

    vec3 color = vec3(y);
    // plot with ABS sinewave
    float pct = plot(st);
    color = (1.0-pct)*color+pct*(vec3(100.00,9.20,abs(sin(u_time)*0.2))*vec3(abs(sin(u_time)*0.10), 1.3, abs(sin(u_time)*122.28)));

	gl_FragColor = vec4(color,1.0);
}
