#version 330 core

in vec3 ourColor;
in vec2 TexCoord;

out vec4 FlagColor;

uniform sampler2D texture1;
uniform sampler2D texture2;
uniform float mixValue;

void main() {
    FlagColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), mixValue);
    //exercise1:修改片段着色器，仅让笑脸图案朝另一个方向看
    //FlagColor = mix(texture(texture1, TexCoord), texture(texture2, vec2(1.0 - TexCoord.s, TexCoord.t)), 0.2);
}
