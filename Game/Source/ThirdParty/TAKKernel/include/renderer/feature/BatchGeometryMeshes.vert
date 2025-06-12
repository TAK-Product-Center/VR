R"(#version 300 es

// !!! vvv DO NOT MODIFY vvv !!!
const int maxIgnoreIds = 0;
const float cMinLevelOfDetail = 0.0;
const float cMaxLevelOfDetail = 255.0;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

uniform mat4 uMvp;
uniform vec4 uIgnoreIds[128];
uniform float uLevelOfDetail;

// Mesh attributes
in vec3 aPosition;
in vec2 aTexPos;
in vec4 aVertColor;
in vec3 aNormals;

// Instance attributes
in vec3 aVertexCoord;
in vec2 aSpriteBottomLeft;
in vec2 aSpriteTopRight;
in vec4 aColor;
in mat4 aTransform;
in vec4 aId;

// !!! vvv DO NOT MODIFY vvv !!!
in float aMinLevelOfDetail;
in float aMaxLevelOfDetail;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

out vec2 vTexPos;
out vec4 vColor;
out vec3 vNormal;

void main() {
  // The world point
  vec4 vertexCoord = vec4(aVertexCoord, 1.0);
  // The model vertex
  vec4 positionCoord = aTransform * vec4(aPosition, 1.0);
  gl_Position = uMvp * (vertexCoord + positionCoord);

  vec2 dist = aSpriteTopRight - aSpriteBottomLeft;
  vTexPos = aSpriteBottomLeft + (aTexPos * dist);
  vColor = aColor * aVertColor;
  vNormal = normalize(mat3(uMvp) * aNormals);

  // check if geometry is marked as ignored and discard by degenerating
  float keep = 1.0;
  for(int i = 0; i < maxIgnoreIds; i++) {
    keep *= step(1.0 / 1024.0, length(aId-uIgnoreIds[i]));
  }
  // !!! vvv DO NOT MODIFY vvv !!!
  float minLevelOfDetail = cMinLevelOfDetail;
  float maxLevelOfDetail = cMaxLevelOfDetail;
  // !!! ^^^ DO NOT MODIFY ^^^ !!!

  float levelOfDetail = clamp(uLevelOfDetail, 0.0, cMaxLevelOfDetail - 1.0);

  // discard if current LOD less than min level of detail
  keep *= step(0.0, levelOfDetail-minLevelOfDetail);
  // discard if current LOD greater-than-or-equal-to max level of detail
  keep *= 1.0 - step(maxLevelOfDetail-1.0, levelOfDetail);

  gl_Position *= keep;
}
)"
