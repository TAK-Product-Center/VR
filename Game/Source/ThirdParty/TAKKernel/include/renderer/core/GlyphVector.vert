R"(#version 300 es
uniform mat4 uMVP;
uniform int uXrayPass;

in vec3 aVertexCoords;
in vec2 aTexCoords;
in vec3 aTranslate;
in float aAnchorF;
in float aRotRadsFontSizeF;
in float aXrayAlpha;
in float aColor;

flat out vec2 vRectSize;
flat out vec4 vColor;
out vec3 vVertexCoord;

vec4 floatToRGB(float v) {
    uint i = floatBitsToUint(v);
    uint r = (i >> 24u) & 0xFFu;
    uint g = (i >> 16u) & 0xFFu;
    uint b = (i >> 8u) & 0xFFu;
    uint a = i & 0xFFu;

    return vec4(float(r)/255., float(g)/255., float(b)/255., float(a)/255.);
}

vec2 unpackFloats(float f, int decPlaces1, int decPlaces2) {
    uint ui = floatBitsToUint(f);
    int i1 = int(ui >> 16u) - 32767;
    int i2 = int(ui & 0xFFFFu) - 32767;
    return vec2(float(i1) / float(10 * decPlaces1), float(i2) / float(10 * decPlaces2));
}

void main() {
    // We stuff the rectangle size in the tex coordinates
    vRectSize = aTexCoords.xy;
    vVertexCoord = aVertexCoords;

    float colorFloat = aColor;
    vColor = floatToRGB(colorFloat);

    vec3 translate = aTranslate;

    float anchorF = aAnchorF;
    vec3 anchor = vec3(unpackFloats(anchorF, 1, 1), 0);

    float rotRadsFontSizeF = aRotRadsFontSizeF;
    vec2 rotRadsFontSize = unpackFloats(rotRadsFontSizeF, 4, 1);
    vec4 quat = vec4(0, 0, sin(rotRadsFontSize.x / 2.), cos(rotRadsFontSize.x / 2.));
    float scale = rotRadsFontSize.y ;

    float xrayAlpha = aXrayAlpha;
    vColor.a = mix(vColor.a, xrayAlpha, float(uXrayPass));

    vec3 coords = aVertexCoords * scale;
    coords -= anchor;
    coords += 2.0 * cross(quat.xyz, cross(quat.xyz, coords) + quat.w * coords);
    coords += anchor;
    coords = coords + translate;

    gl_Position = uMVP * vec4(coords , 1.0);
}
)"