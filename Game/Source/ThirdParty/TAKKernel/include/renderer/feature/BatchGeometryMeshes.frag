R"(#version 300 es
precision mediump float;
uniform sampler2D uTexture;

uniform vec4 uColor;
uniform float uLightingFactor;

in vec2 vTexPos;
in vec4 vColor;
in vec3 vNormal;

out vec4 fragColor;

void main(void) {
  vec3 sun_position = vec3(3.0, 10.0, -5.0);
  vec3 sun_color = vec3(1.0, 1.0, 1.0);
  float lum = max(dot(vNormal, normalize(sun_position)), 0.0);
  vec4 lighting = vec4((0.6 + 0.4 * lum) * sun_color, 1.0);
  lighting = mix(vec4(1.0), lighting, uLightingFactor);

  fragColor = uColor * vColor * lighting * texture(uTexture, vTexPos);
}
)"