//
// Created by dengchong on 2019-06-03.
//

#ifndef OPENGLSTUDY_COMMON_H
#define OPENGLSTUDY_COMMON_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

int chapter01_02();

//着色器
int chapter01_03();

//纹理
int chapter01_04();

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

void initGLFW();

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);


#endif //OPENGLSTUDY_COMMON_H
