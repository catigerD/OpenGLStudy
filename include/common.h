//
// Created by dengchong on 2019-06-03.
//

#ifndef OPENGLSTUDY_COMMON_H
#define OPENGLSTUDY_COMMON_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int chapter01_02();

//着色器
int chapter01_03();

//纹理
int chapter01_04();

//纹理
int chapter01_05();

const int SCR_WIDTH = 800;
const int SCR_HEIGHT = 600;
//c++ static 详解 https://www.cnblogs.com/yc_sunniwell/archive/2010/07/14/1777441.html
extern float mixValue;

void initGLFW();

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);


#endif //OPENGLSTUDY_COMMON_H
