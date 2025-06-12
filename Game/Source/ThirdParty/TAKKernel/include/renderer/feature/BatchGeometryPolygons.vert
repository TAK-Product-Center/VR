R"(#version 300 es

// !!! vvv DO NOT MODIFY vvv !!!
const int maxIgnoreIds = 0;
const float cMinLevelOfDetail = 0.0;
const float cMaxLevelOfDetail = 255.0;
const float cLightingFactor = 0.0;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

uniform mat4 u_mvp;
uniform vec2 uViewport;
uniform vec4 uIgnoreIds[128];
uniform float uLevelOfDetail;
uniform float uLightingFactor;

in vec3 aPosition;
in vec4 a_color;
in vec4 aId;
in float aExteriorVertex;
in float aOutlineWidth;

// !!! vvv DO NOT MODIFY vvv !!!
in float aMinLevelOfDetail;
in float aMaxLevelOfDetail;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

out vec4 v_color;
out float vExteriorVertex;
out float vOutlineWidth;
out vec3 vWorldPosition;
out float vLightingFactor;

void main() {
  gl_Position = u_mvp * vec4(aPosition, 1.0);
  vWorldPosition = aPosition;
  v_color = a_color;
  vExteriorVertex = aExteriorVertex;
  vOutlineWidth = aOutlineWidth;

  // check if geometry is marked as ignored and discard by degenerating
  float keep = 1.0;
  for(int i = 0; i < maxIgnoreIds; i++) {
    keep *= step(1.0 / 1024.0, length(aId-uIgnoreIds[i]));
  }
  // !!! vvv DO NOT MODIFY vvv !!!
  float minLevelOfDetail = cMinLevelOfDetail;
  float maxLevelOfDetail = cMaxLevelOfDetail;
  vLightingFactor = cLightingFactor;
  // !!! ^^^ DO NOT MODIFY ^^^ !!!

  float levelOfDetail = clamp(uLevelOfDetail, 0.0, cMaxLevelOfDetail - 1.0);

  // discard if current LOD less than min level of detail
  keep *= step(0.0, levelOfDetail-minLevelOfDetail);
  // discard if current LOD greater-than-or-equal-to max level of detail
  keep *= 1.0 - step(maxLevelOfDetail-1.0, levelOfDetail);

  gl_Position *= keep;
}
)"
