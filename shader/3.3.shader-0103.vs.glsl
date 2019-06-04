#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 ourColor;

uniform float xOffset;

void main() {
    //    gl_Position = vec4(aPos, 1.0);
    //    gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);//exercise1:修改顶点着色器，让三角形上下颠倒
    gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0);//exercise2:使用uniform定义一个水平偏移量，在顶点着色器中使用这个偏移量把三角形移动到屏幕右侧
    ourColor = aColor;
}
