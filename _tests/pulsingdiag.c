#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

// Plot a line on Y using a value between 0.0-1.0
float plot(vec2 st) {    
    return smoothstep(abs(sin(u_time)*0.2), 2.0, abs(cos(u_time*0.1)*st.y - sin(u_time*0.01)*st.x));
}

void main() {
	vec2 st = gl_FragCoord.xy/u_resolution;

    float y = st.x*cos(u_time)*0.01;

    vec3 color = vec3(y);

    // Plot a line
    float pct = plot(st);
    color = (1.0-pct)*color+pct*(vec3(abs(cos(u_time)*100.0),9.20,abs(sin(u_time)*0.2))*vec3(abs(sin(u_time)*1.0),1.3,abs(sin(u_time)*0.28)));

	gl_FragColor = vec4(color,1.0);
}
