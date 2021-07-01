cmake_minimum_required(VERSION 3.17)
project(OpenGL_GameEngine)

set(CMAKE_CXX_STANDARD 17)

set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include/GLFW)
set(ASSIMP_H /usr/local/Cellar/assimp/5.0.1/include)
set(GLAD_H /usr/local/include/glad)
set(KH_H /usr/local/include/KHR)
set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include/glm)
include_directories(${GLEW_H} ${GLFW_H} ${ASSIMP_H} ${GLAD_H} ${KH_H} ${GLM_H} ${IMGUI_H})

# 添加目标链接
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.dylib)
set(ASSIMP_LINK /usr/local/Cellar/assimp/5.0.1/lib/libassimp.5.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK} ${ASSIMP_LINK})

# 执行编译命令
# 这个glad.c在第2步中说过要拉到项目中，注意路径
set(SOURCE_FILES "src/glad.c" "src/main.cpp" src/Environments/ClearColor.cpp src/Environments/ClearColor.h src/Environments/Environment.cpp
        src/Environments/Environment.h src/imgui/imconfig.h src/imgui/imgui.cpp src/imgui/imgui.h src/imgui/imgui_demo.cpp src/imgui/imgui_draw.cpp
        src/imgui/imgui_impl_glfw.cpp src/imgui/imgui_impl_glfw.h src/imgui/imgui_impl_opengl3.cpp src/imgui/imgui_impl_opengl3.h
        src/imgui/imgui_internal.h src/imgui/imgui_tables.cpp src/imgui/imgui_widgets.cpp src/imgui/imstb_rectpack.h src/imgui/imstb_textedit.h
        src/Actors/Rectangle.cpp src/Actors/Rectangle.h src/Actors/Actor.cpp src/Actors/Actor.h src/Actors/Triangle.cpp src/Actors/Triangle.h
        src/Tools/Shader.cpp src/Tools/Shader.h src/GUI/MainGUI.cpp src/GUI/MainGUI.h src/GUI/GUI.cpp src/GUI/GUI.h src/GUI/ScenesGUI.cpp src/GUI/ScenesGUI.h
        src/Tools/Singleton.h src/Tools/stb_image.h src/imgui/imfilebrowser.h)
add_executable(OpenGL_GameEngine ${SOURCE_FILES})

# mac下这步很重要
if (APPLE)
    target_link_libraries(OpenGL_GameEngine "-framework OpenGL")
    target_link_libraries(OpenGL_GameEngine "-framework GLUT")
endif()

