R"(#version 300 es
precision mediump float;
out vec4 v_FragColor;
uniform vec4 uColor;
in vec4 v_color;
flat in float f_halfStrokeWidth;
in vec2 v_normal;
void main(void) {
  float antiAlias = smoothstep(-1.0, .25, f_halfStrokeWidth-length(v_normal));
  v_FragColor = uColor;
  // applies pattern/anti-alias only if not hit-testing
  v_FragColor.a = uColor.a*antiAlias;

})"