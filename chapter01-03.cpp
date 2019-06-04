//
// Created by dengchong on 2019-06-03.
//

#include <common.h>
#include <Shader.h>

using namespace std;

int chapter01_03() {

    //1. init glfw and configure
    initGLFW();
    //2. glfw window creation
    GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        cout << "failed to create window" << endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //3. glad init fun pointer
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        cout << "failed to init glad" << endl;
        return -1;
    }

    //build and compile our shader program
    Shader ourShader("/Users/dengchong/project/CLionProjects/OpenGLStudy/shader/3.3.shader-0103.vs.glsl",
                     "/Users/dengchong/project/CLionProjects/OpenGLStudy/shader/3.3.shader-0103.fs.glsl");

    //setup vertex data and configure vertex attributes
    float vertices[] = {
            //positions          colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f,//top
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    //bind the vertex array object first,then bind and set vertex buffers,and then configure vertex attributes
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    //color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //4. render loop
    while (!glfwWindowShouldClose(window)) {
        //input
        processInput(window);

        //render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //render the triangle
        ourShader.use();
        //exercise2:使用uniform定义一个水平偏移量，在顶点着色器中使用这个偏移量把三角形移动到屏幕右侧
        //更新一个uniform之前你必须先使用程序（调用glUseProgram)，因为它是在当前激活的着色器程序中设置uniform的。
        float offset = 0.5f;
        ourShader.setFloat("xOffset", offset);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        //glfw swap buffert and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //de-allocate all resources
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwTerminate();
    return 0;
}

