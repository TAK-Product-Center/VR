R"(#version 300 es
precision highp float;
uniform mat4 uProjection;
uniform mat4 uModelView;
in vec3 aVertexCoords;
in vec3 aNextVertexCoords;
in float aNormalDir;
uniform float uWidth;
const float c_smoothBuffer = 2.0;
uniform vec2 uViewport;
out vec4 v_color;
out vec2 v_normal;
flat out float f_halfStrokeWidth;
void main() {
  gl_Position = uProjection * uModelView * vec4(aVertexCoords.xyz, 1.0);
  vec4 next_gl_Position = uProjection * uModelView * vec4(aNextVertexCoords.xyz, 1.0);
  vec4 p0 = (gl_Position / gl_Position.w)*vec4(uViewport, 1.0, 1.0); 
  vec4 p1 = (next_gl_Position / next_gl_Position.w) * vec4(uViewport, 1.0, 1.0);
  float dist = distance(p0.xy, p1.xy); 
  float radius = uWidth+c_smoothBuffer;
  float dx = p1.x - p0.x;
  float dy = p1.y - p0.y;
  v_normal = vec2(-aNormalDir*(dy/dist)*(uWidth+c_smoothBuffer), aNormalDir*(dx/dist)*(uWidth+c_smoothBuffer)); 
  float m = sqrt(dx*dx + dy*dy);
  float adjX = aNormalDir*(dx/m)*(radius/uViewport.y);
  float adjY = aNormalDir*(dy/m)*(radius/uViewport.x);
  gl_Position.x = gl_Position.x - adjY*gl_Position.w;
  gl_Position.y = gl_Position.y + adjX*gl_Position.w;
  f_halfStrokeWidth = uWidth;
}
)"