#include <cstdio>
#include <glew.h>
#include <glfw3.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include "GUI/GUI.h"
#include "Tools/Singleton.h"

int main() {

    //初始化GLFW
    if (!glfwInit()) {
        printf("Init GLFW Failed");
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    //创建GLFW窗口
    GLFWwindow *window = glfwCreateWindow(1366, 768, "OpenGL-GameEngine", NULL, NULL);
    if (window == NULL) {
        printf("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void) io;
    ImGui::StyleColorsLight();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");

    //初始化GLEW
    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        printf("Init GLEW Failed");
        glfwTerminate();
        return -1;
    }

    //视口
    glViewport(0, 0, 1366, 768);

    //背面剔除
    //glEnable(GL_CULL_FACE);
    //glCullFace(GL_BACK);

    GetInstance<GUI>().Init();

    //渲染循环
    while (!glfwWindowShouldClose(window)) {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        GetInstance<GUI>().OnGUI();
        GetInstance<GUI>().OnUpdate();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
        glfwPollEvents();

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }

    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    //退出
    printf("Exit Application");
    glfwTerminate();
    return 0;
}