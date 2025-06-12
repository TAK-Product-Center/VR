R"(#version 300 es
precision mediump float;
uniform vec4 uColor;
in vec4 vColor;
out vec4 fragColor;
void main(void) {
  fragColor = vColor*uColor;
}
)"