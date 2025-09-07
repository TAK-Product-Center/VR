R"(#version 300 es
precision highp float;

#define M_PI 3.1415926535897932384626433832795

// !!! vvv DO NOT MODIFY vvv !!!
const int maxIgnoreIds = 0;
const float cMinLevelOfDetail = 0.0;
const float cMaxLevelOfDetail = 255.0;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

uniform mat4 u_mvp;
uniform mediump vec2 u_viewportSize;
uniform vec4 uIgnoreIds[128];
uniform float uLevelOfDetail;
uniform float uStrokeScale;

in vec3 a_vertexCoord0;
in vec3 a_vertexCoord1;
in vec2 a_position;
in vec4 a_color;
in vec4 a_outlineColor;
in float a_radius;
in float a_outlineWidth;
in vec4 aId;

// !!! vvv DO NOT MODIFY vvv !!!
in float aMinLevelOfDetail;
in float aMaxLevelOfDetail;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

out vec4 vColor;

void main() {
  gl_Position = u_mvp * vec4(a_vertexCoord1, 1.0);
  vec4 p0 = u_mvp * vec4(a_vertexCoord0, 1.0);
  p0 /= p0.w;
  vec4 p1 = gl_Position;
  p1 /= p1.w;

// transform the instance data vertex, then translate by the world position in NDC
  vec2 vertexCoord = vec2(0.0);
// rotate, z-axis (heading)
  float heading_rot = atan((p0.y-p1.y)*u_viewportSize.y, (p0.x-p1.x)*u_viewportSize.x) + (M_PI / 2.0);
  float sin_heading = sin(heading_rot);
  float cos_heading = cos(heading_rot);
  vertexCoord.x = (a_position.x*cos_heading)-(a_position.y*sin_heading);
  vertexCoord.y = (a_position.x*sin_heading)+(a_position.y*cos_heading);

// scale
  vertexCoord *= uStrokeScale*a_radius*gl_Position.w/u_viewportSize;
// translate
  gl_Position.x += vertexCoord.x;
  gl_Position.y += vertexCoord.y;
  gl_PointSize = 4.0;
  vColor = a_color;

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