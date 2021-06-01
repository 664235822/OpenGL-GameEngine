//
// Created by 朱洲 on 2021/6/1.
//

#include "MainGUI.h"
#include "../imgui/imgui.h"

MainGUI::MainGUI() = default;

void MainGUI::Init() {
    component->Init();
}

void MainGUI::OnGUI() {
    ImGui::Begin("Main");

    ImGui::BeginTabBar("Create");
    ImGui::SetWindowSize(ImVec2(300.0f, 400.0f));
    if (ImGui::TabItemButton("Actors")) tab = 0;
    if (ImGui::TabItemButton("Lighting")) tab = 1;
    if (ImGui::TabItemButton("Components")) tab = 2;
    switch (tab) {
        case 0:
            actor->OnInit();
            break;
        case 1:
            break;
        case 2:
            component->OnGUI();
            break;
    }
    ImGui::EndTabBar();
    ImGui::End();
}

void MainGUI::OnUpdate() {
    component->OnUpdate();
    actor->OnUpdate();
}



