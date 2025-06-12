R"(#version 300 es
precision mediump float;
uniform bool u_hitTest;
uniform vec4 uColor;
in vec4 v_color;
in vec4 v_outlineColor;
in float v_mix;
flat in int f_pattern;
flat in float f_factor;
flat in highp float f_dist;
flat in vec2 f_p0;
flat in vec2 f_p1;
flat in vec2 f_cap;
flat in float f_halfStrokeWidth;
flat in float f_outlineWidth;
in float v_along;
in vec2 v_cross;
out vec4 v_FragColor;
void main(void) {
  highp float d = (f_dist*v_mix);
  int idist0 = int(d/f_factor);
  int idist1 = int((d+1.0)/f_factor);
  float b0 = float((f_pattern>>(idist0%16))&0x1);
  float b1 = float((f_pattern>>(idist1%16))&0x1);
  float patternMaskAlpha = mix(1.0, mix(b0, b1, fract(d)), sign(abs(f_factor)));

  float radius = f_halfStrokeWidth+f_outlineWidth;
  float cross = length(v_cross);

  // stroke anti-alias based on cross distance
  float antiAlias = smoothstep(-1.0, 0.25, radius-cross);
  antiAlias = min(antiAlias,
    min(step(0.0, v_along), step(0.0, f_dist-v_along))); // mask off leading and trailing ends

  float cap0 = smoothstep(-1.0, 0.25, radius-length(f_p0-gl_FragCoord.xy));
  float cap1 = smoothstep(-1.0, 0.25, radius-length(f_p1-gl_FragCoord.xy));

  // p0 cap/join
  antiAlias = mix(f_cap.x, antiAlias, step(radius, length(f_p0-gl_FragCoord.xy)));
  // p1 cap/join
  antiAlias = mix(f_cap.y, antiAlias, step(radius, length(f_p1-gl_FragCoord.xy)));

  vec4 color = mix(v_outlineColor, v_color, smoothstep(-0.5, 0.5, f_halfStrokeWidth-cross));
  // applies pattern/anti-alias only if not hit-testing
  color.a = v_color.a*antiAlias*patternMaskAlpha;
  color *= uColor;

  // output color; original if hit-testing
  v_FragColor = mix(color, v_color, float(u_hitTest));
}
)"