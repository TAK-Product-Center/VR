R"(#version 300 es
precision mediump float;
uniform sampler2D uTexture;
smooth in vec2 vTexPos;

flat in vec4 vBufferOutlineGamma;
flat in vec4 vColor;
flat in vec4 vOutlineColor;

out vec4 fragmentColor;

float median(float r, float g, float b) {
    return max(min(r, g), min(max(r, g), b));
}

void main() {
    vec3 msd = texture(uTexture, vTexPos).rgb;
    float vBuffer = vBufferOutlineGamma.r;
    float vGamma = vBufferOutlineGamma.b;
    float vOutlineBuffer = vBufferOutlineGamma.g;
    float dist = median(msd.r, msd.g, msd.b);
    float alpha = smoothstep(vBuffer - vGamma, vBuffer + vGamma, dist);
    vec4 color = vec4(vColor.rgb, alpha * vColor.a);
    float alphaOutline = smoothstep(vOutlineBuffer - vGamma, vOutlineBuffer + vGamma, dist);
    vec4 colorOutline = vec4(vOutlineColor.rgb, alphaOutline * vOutlineColor.a);
    fragmentColor = mix(color, colorOutline, alphaOutline-alpha);
}
)"