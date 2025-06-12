R"(
#version 100
// !!! vvv DO NOT MODIFY vvv !!!
const int maxIgnoreIds = 0;
const float cMinLevelOfDetail = 0.0;
const float cMaxLevelOfDetail = 255.0;
const float cHitTestRadius = 0.0;
const vec2 cOffset = vec2(0.0, 0.0);
const float cViewportWidth = 1.0;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

uniform mat4 uMVP;
uniform vec2 uMapRotation;

uniform vec3 uCameraRtc;
uniform vec3 uWcsScale;
uniform float uTanHalfFov;
uniform float uViewportWidth;
uniform float uViewportHeight;
uniform float uDrawTilt;
uniform float uClampToSurface;

uniform vec4 uIgnoreIds[128];
uniform float uLevelOfDetail;
uniform float uHitTestRadius;

attribute float aPointSize;
attribute vec3 aVertexCoords;
attribute vec3 aSurfaceVertexCoords;
// Rotation input is normalized, positive only, 0 -> 360
attribute vec2 aRotation; // x: cos(theta), y: sin(theta)
attribute float aAbsoluteRotationFlag;

// Coordinates needed to access the sprite from the texture atlas
attribute vec2 aSpriteBottomLeft;
attribute vec2 aSpriteDimensions;

attribute vec4 aColor;
attribute vec4 aId;

// !!! vvv DO NOT MODIFY vvv !!!
attribute float aMinLevelOfDetail;
attribute float aMaxLevelOfDetail;
attribute vec2 aOffset;
// !!! ^^^ DO NOT MODIFY ^^^ !!!

varying vec2 vSpriteBottomLeft;
varying vec2 vSpriteTopRight;
varying vec2 vSpriteDimensions;
varying float vPointSize;
varying vec4 vColor;
varying mat3 vRotation;
//<<MPU5>>varying vec3 vPointCoordParams;

void main() {
  // compute the line of sight
  vec3 vertexCoords = mix(aVertexCoords, aSurfaceVertexCoords, uClampToSurface);
  vec3 lineOfSight = (vertexCoords-uCameraRtc)*uWcsScale;

  // compute the radius of the point, in nominal WCS units
  float range = length(lineOfSight);
  float gsd = range*uTanHalfFov/(uViewportHeight/2.0);
  float radiusMeters = gsd*aPointSize/2.0;

  // adjust range to position point at near edge of radius
  range -= radiusMeters;
  
  // recompute vertex position
  vec3 adjustedPos = (normalize(lineOfSight)*range)/uWcsScale + uCameraRtc;

  // Scale normalized value up to radians
  vec2 rotRadians = aRotation * 2.0 * 3.14159;
  // Calculate the actual rotation
  vec2 actualRotation = rotRadians + aAbsoluteRotationFlag * uMapRotation;
  vec2 rotFactors  = vec2(cos(actualRotation.x), sin(actualRotation.y));

  float levelOfDetail = clamp(uLevelOfDetail, 0.0, cMaxLevelOfDetail - 1.0);
  float lodIconScale = 0.5 + smoothstep(0.0, 10.0, uLevelOfDetail)*0.5;

  float pointSize = aPointSize * lodIconScale;
  // !!! vvv DO NOT MODIFY vvv !!!
  float hitTestRadius = cHitTestRadius;
  vec2 offset = cOffset;
  float viewportWidth = cViewportWidth;
  // !!! ^^^ DO NOT MODIFY ^^^ !!!

  // point sprite size is padded out for rotation
  float rotPad = abs(rotFactors.x)+abs(rotFactors.y);
  gl_PointSize = (pointSize*rotPad) + hitTestRadius;
  // compute the (normalized) ratio of the padded sprite versus original size
  vPointSize = gl_PointSize / (pointSize + hitTestRadius);
  vSpriteBottomLeft = aSpriteBottomLeft;
  vSpriteDimensions = aSpriteDimensions;
  gl_Position = uMVP * vec4(adjustedPos.xyz, 1.0);
  gl_Position.xy += (offset / vec2(viewportWidth, uViewportHeight)) * gl_Position.w * 2.0;
  vColor = aColor;

  gl_Position.y += (abs(sin(uDrawTilt))*(aPointSize/2.0)/uViewportHeight) * gl_Position.w;

  // Calculate the center of the sprite in the texture atlas
  vSpriteTopRight = vSpriteBottomLeft + vSpriteDimensions;
  vec2 origin = (vSpriteBottomLeft + (vSpriteTopRight)) / 2.0;
  // Compute the texture atlas rotation matrix
  vRotation = mat3(vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(origin, 1.0)) 
                * mat3(vec3(rotFactors.x, rotFactors.y, 0.0), vec3(-rotFactors.y, rotFactors.x, 0.0), vec3(0.0, 0.0, 1.0))
                * mat3(vec3(1.0, 0.0, 0.0), vec3(0.0, 1.0, 0.0), vec3(-origin, 1.0));


  // check if geometry is marked as ignored and discard by pushing past far plane
  float keep = 1.0;
  for(int i = 0; i < maxIgnoreIds; i++) {
    keep *= step(1.0 / 1024.0, length(aId-uIgnoreIds[i]));
  }

  // !!! vvv DO NOT MODIFY vvv !!!
  float minLevelOfDetail = cMinLevelOfDetail;
  float maxLevelOfDetail = cMaxLevelOfDetail;
  // !!! ^^^ DO NOT MODIFY ^^^ !!!

  // discard if current LOD less than min level of detail
  keep *= step(0.0, levelOfDetail-minLevelOfDetail);
  // discard if current LOD greater-than-or-equal-to max level of detail
  keep *= 1.0 - step(maxLevelOfDetail-1.0, levelOfDetail);

  //<<MPU5>>vPointCoordParams = vec3(((gl_Position.x / gl_Position.w) + 1.0) * uViewportWidth/2.0, ((gl_Position.y / gl_Position.w) + 1.0) * uViewportHeight/2.0, gl_PointSize);
  gl_Position.w *= keep;
}
)"