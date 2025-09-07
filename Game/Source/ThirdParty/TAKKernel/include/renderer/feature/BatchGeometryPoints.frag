R"(
#version 100
precision mediump float;
uniform sampler2D uTexture;
uniform vec4 uColor;
varying vec2 vSpriteBottomLeft;
varying vec2 vSpriteTopRight;
varying vec2 vSpriteDimensions;
varying float vPointSize;
varying vec4 vColor;
varying mat3 vRotation;
//<<MPU5>>varying vec3 vPointCoordParams;

void main(void) {
  // Calculate the dimensions of the sprite in a 0 - 1 range
  // Used to make sure that non-square sprites aren't drawn as squares
  float maxDimension = max(vSpriteDimensions.x, vSpriteDimensions.y);
  vec2 normalizedSpriteDimensions = vSpriteDimensions / maxDimension;

  // Create a transform to move the sprite to the origin, rotate it, then move it to its original position
  vec2 pointCoord = gl_PointCoord;
  pointCoord.x = ((((pointCoord.x*2.0)-1.0)*vPointSize/normalizedSpriteDimensions.x)+1.0)/2.0;
  pointCoord.y = ((((pointCoord.y*2.0)-1.0)*vPointSize/normalizedSpriteDimensions.y)+1.0)/2.0;
  vec2 atlasTexPos = (vRotation * vec3(vSpriteBottomLeft + (vSpriteDimensions * pointCoord), 1.0)).xy;

  // Make sure the rotated atlasTexPos stays within the bounds of the sprite so we don't touch any
  // neighboring sprites or run off the edge of the texture atlas.
  bvec2 isDiscard = bvec2(any(greaterThanEqual(atlasTexPos, vSpriteTopRight)), any(lessThanEqual(atlasTexPos, vSpriteBottomLeft)));
  gl_FragColor = uColor * vColor * texture2D(uTexture, atlasTexPos);
  // turn fragment transparent if it should be discarded
  gl_FragColor.a = gl_FragColor.a * (1.0-float(any(isDiscard)));
  // XXX - candidate for separate shader for depth sorted sprites
  if(gl_FragColor.a < 0.1)
      discard;
}
)"
