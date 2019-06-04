#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec3 ourColor;

uniform float xOffset;

void main() {
    gl_Position = vec4(aPos, 1.0);
    //    gl_Position = vec4(aPos.x, -aPos.y, aPos.z, 1.0);//exercise1:修改顶点着色器，让三角形上下颠倒
    //gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0);//exercise2:使用uniform定义一个水平偏移量，在顶点着色器中使用这个偏移量把三角形移动到屏幕右侧
    ourColor = aColor;
}


//使用out关键字把顶点位置输出到片段着色器，并将片段的颜色设置为与顶点位置相等（来看看连顶点位置值都在三角形中被插值的结果）。做完这些后，尝试回答下面的问题：为什么在三角形的左下角是黑的?
// Vertex shader:
// ==============
//#version 330 core
//layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aColor;
//
//// out vec3 ourColor;
//out vec3 ourPosition;
//
//void main()
//{
//    gl_Position = vec4(aPos, 1.0);
//    // ourColor = aColor;
//    ourPosition = aPos;
//}

/*
Answer to the question: Do you know why the bottom-left side is black?
-- --------------------------------------------------------------------
Think about this for a second: the output of our fragment's color is equal to the (interpolated) coordinate of
the triangle. What is the coordinate of the bottom-left point of our triangle? This is (-0.5f, -0.5f, 0.0f). Since the
xy values are negative they are clamped to a value of 0.0f. This happens all the way to the center sides of the
triangle since from that point on the values will be interpolated positively again. Values of 0.0f are of course black
and that explains the black side of the triangle.

想一想这一点：我们片段颜色的输出等于（插值）坐标
三角形。三角形左下角的坐标是多少？这是（-0.5f，-0.5f，0.0f）。自从
Xy值为负，它们被钳制到0.0f的值。这种情况一直发生在中心两侧
从这一点开始，三角形的值将被再次插值。 0.0f的值当然是黑色的
这解释了三角形的黑色面。
*/