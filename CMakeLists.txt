cmake_minimum_required(VERSION 3.14)
project(OpenGLStudy)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
link_directories(lib)
aux_source_directory(. MAIN_SRC)

add_executable(OpenGLStudy ${MAIN_SRC})

target_link_libraries(
        OpenGLStudy

        glfw)