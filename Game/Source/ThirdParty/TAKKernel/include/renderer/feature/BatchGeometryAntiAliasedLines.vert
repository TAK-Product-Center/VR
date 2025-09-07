R"(#version 300 es
precision highp float;

// !!! vvv DO NOT MODIFY vvv !!!
const int maxIgnoreIds = 0;
const float cMinLevelOfDetail = 0.0;
const float cMaxLevelOfDetail = 255.0;
const float cHitTestRadius = 0.0;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

const float c_smoothBuffer = 2.0;

uniform mat4 u_mvp;
uniform mediump vec2 u_viewportSize;
uniform vec4 uIgnoreIds[128];
uniform float uLevelOfDetail;
uniform float uHitTestRadius;
uniform float uStrokeScale;
in vec3 a_vertexCoord0;
in vec3 a_vertexCoord1;
in vec2 a_texCoord;
in vec4 a_color;
in vec4 a_outlineColor;
in float a_normal;
in float a_dir;
in int a_pattern;
in float a_factor;
in vec2 a_cap;
in float a_halfStrokeWidth;
in float a_outlineWidth;
in vec4 aId;

// !!! vvv DO NOT MODIFY vvv !!!
in float aMinLevelOfDetail;
in float aMaxLevelOfDetail;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

out vec4 v_color;
out vec4 v_outlineColor;
flat out float f_dist;
out float v_mix;
flat out int f_pattern;
flat out float f_halfStrokeWidth;
flat out float f_outlineWidth;
flat out float f_factor;
flat out vec2 f_p0;
flat out vec2 f_p1;
flat out vec2 f_cap;
out float v_along;
out vec2 v_cross;
void main(void) {
  vec3 vertexCoord0 = mix(a_vertexCoord1, a_vertexCoord0, a_dir);
  vec3 vertexCoord1 = mix(a_vertexCoord0, a_vertexCoord1, a_dir);
  gl_Position = u_mvp * vec4(vertexCoord0.xyz, 1.0);
  vec4 next_gl_Position = u_mvp * vec4(vertexCoord1.xyz, 1.0);
  vec4 p0 = (gl_Position / gl_Position.w)*vec4(u_viewportSize, 1.0, 1.0);
  vec4 p1 = (next_gl_Position / next_gl_Position.w)*vec4(u_viewportSize, 1.0, 1.0);
  v_mix = a_dir;
  // if pattern is not solid line, disable cap/join
  float solidLine = step(65535.0, float(a_pattern));
  vec2 capJoin = a_cap*solidLine;
  float dist = distance(p0.xy, p1.xy);
  float dx = p1.x - p0.x;
  float dy = p1.y - p0.y;
  float normalDir = (2.0*a_normal) - 1.0;
  // !!! vvv DO NOT MODIFY vvv !!!
  float hitTestRadius = cHitTestRadius;
  // !!! ^^^ DO NOT MODIFY ^^^ !!!
  float bufferRadius = (a_halfStrokeWidth+a_outlineWidth+c_smoothBuffer+hitTestRadius);
  float normalizedBufferRadiusX = (bufferRadius/u_viewportSize.x);
  float normalizedBufferRadiusY = (bufferRadius/u_viewportSize.y);
  float adjX = normalDir*(dx/dist)*normalizedBufferRadiusY;
  float adjY = normalDir*(dy/dist)*normalizedBufferRadiusX;
  // adjust endpoint for cap
  gl_Position.x = gl_Position.x - ((dx/dist)*normalizedBufferRadiusX)*gl_Position.w*max(mix(capJoin.y, capJoin.x, a_dir), 0.0);
  gl_Position.y = gl_Position.y - ((dy/dist)*normalizedBufferRadiusY)*gl_Position.w*max(mix(capJoin.y, capJoin.x, a_dir), 0.0);
  // extrude segment vertex into quad vertex
  gl_Position.x = gl_Position.x - adjY*gl_Position.w;
  gl_Position.y = gl_Position.y + adjX*gl_Position.w;
  // outputs to fragment shader
  v_color = a_color;
  v_outlineColor = mix(a_color, a_outlineColor, step(0.5, a_outlineWidth));
  f_pattern = a_pattern;
  f_factor = a_factor;
  f_dist = dist;
  f_halfStrokeWidth = (uStrokeScale*a_halfStrokeWidth)+hitTestRadius;
  f_outlineWidth = a_outlineWidth;
  // endpoints; maintain original direction
  f_p0 = mix(p1.xy, p0.xy, a_dir) + u_viewportSize;
  f_p1 = mix(p0.xy, p1.xy, a_dir) + u_viewportSize;
  // [0,1] will fill, [-1] will clear
  f_cap = vec2(step(0.0, capJoin.x), step(0.0, capJoin.y));

  float a0x = -1.0*bufferRadius*max(capJoin.x, 0.0);
  float a1x = dist + bufferRadius*max(capJoin.y, 0.0);
  v_along = mix(a1x, a0x, a_dir);

  v_cross = vec2(-normalDir*(dy/dist)*bufferRadius, normalDir*(dx/dist)*bufferRadius);

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