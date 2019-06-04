#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 ourColor;

void main() {
    //    gl_Position = vec4(aPos, 1.0);
    gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);//exerciese1:修改顶点着色器，让三角形上下颠倒
    ourColor = aColor;
}
