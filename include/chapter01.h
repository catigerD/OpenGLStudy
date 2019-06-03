//
// Created by dengchong on 2019-06-03.
//

#ifndef OPENGLSTUDY_CHAPTER01_H
#define OPENGLSTUDY_CHAPTER01_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
int chapter01_02();
//着色器
int chapter01_03();

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;

void initGLFW();

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);


#endif //OPENGLSTUDY_CHAPTER01_H
