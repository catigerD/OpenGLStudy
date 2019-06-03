//
// Created by dengchong on 2019-06-03.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <chapter01-01.h>

#include <iostream>

using namespace std;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//C++ 函数指针声明不需要 typedef?
void frameBufferSizeCallback(GLFWwindow *, int, int);

void processInput(GLFWwindow *);


int chapter01_01() {

    //glfw : initialize and configure
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // uncomment this statement to fix compilation on OS X
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //glfw window create
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        cout << "Failed to create GLFW window" << endl;
        //释放资源
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    //glad : load all OpenGL function pointers
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    //render loop
    while (!glfwWindowShouldClose(window)) {
        //input
        processInput(window);

        //render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //glfw : swap buffers and poll IO event(key pressed/released,mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //glfw:terminate, clear all previously allocated GLFW resources
    glfwTerminate();
    return 0;
}

void frameBufferSizeCallback(GLFWwindow *window, int widht, int height) {
    glViewport(0, 0, widht, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}


