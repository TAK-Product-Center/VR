R"(
#version 100
uniform mat4 uProjection;
uniform mat4 uModelView;
attribute vec3 aVertexCoords;
attribute vec2 aTextureCoords;
attribute vec4 aColor;
attribute vec4 aOutlineColor;
attribute float aTexUnit;
varying vec2 vTexPos;
varying vec4 vColor;
varying vec4 vOutlineColor;
varying float vTexUnit;
void main() {
  vTexPos = aTextureCoords;
  vColor = aColor;
  vOutlineColor = aOutlineColor;
  vTexUnit = aTexUnit;
  gl_Position = uProjection * uModelView * vec4(aVertexCoords.xyz, 1.0);
}
)"