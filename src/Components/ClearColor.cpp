//
// Created by 朱方灏钧 on 2021/2/23.
//

#include "ClearColor.h"
#include "glew.h"
#include "../imgui/imgui.h"

ClearColor::ClearColor() = default;

void ClearColor::OnUpdate() {
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}

void ClearColor::OnGUI() {
    ImGui::ColorEdit4("BackGround Color", color);
}
