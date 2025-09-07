R"(#version 300 es
precision highp float;
uniform vec4 u_color;
uniform vec3 uLightingNormal;

in vec4 v_color;
in float vExteriorVertex;
in float vOutlineWidth;
in vec3 vWorldPosition;
in float vLightingFactor;

out vec4 fragColor;

// Polygon outline implementation taken from here:
// https://community.khronos.org/t/how-do-i-draw-a-polygon-with-a-1-2-or-n-pixel-inset-outline-in-opengl-4-1/104201

void main(void) {
  vec2 gradient = vec2(dFdx(vExteriorVertex), dFdy(vExteriorVertex));
  float distance = vExteriorVertex / length(gradient);
  vec4 polyColor = mix(u_color, v_color*u_color, step(vOutlineWidth, distance));

  // lighting
  vec3 dx = dFdx(vWorldPosition);
  vec3 dy = dFdy(vWorldPosition);
  vec3 vNormal = normalize(cross(dx, dy));

  vec3 sun_color = vec3(1.0, 1.0, 1.0);
  float lum = clamp(dot(vNormal, uLightingNormal), 0.0, 1.0);
  vec3 lighting = ((1.0-vLightingFactor) + (vLightingFactor*lum)) * sun_color;

  //fragColor = polyColor * mix(vec4(1.0), vec4(lighting, 1.0), step(0.01, vLightingFactor));
  fragColor = polyColor * vec4(lighting, 1.0);
}
)"