//
// Created by 朱洲 on 2021/6/1.
//

#include "MainGUI.h"
#include "../Tools/Singleton.h"

MainGUI::MainGUI() = default;

void MainGUI::Init() {
    GetInstance<Environment>().Init();
}

void MainGUI::OnGUI() {
    ImGui::Begin("Main");
    if (isInit) {
        ImGui::SetWindowSize(ImVec2(300.0f, 400.0f));
        isInit = false;
    }
    ImGui::BeginTabBar("Create");
    if (ImGui::TabItemButton("Actors")) tab = 0;
    if (ImGui::TabItemButton("Lights")) tab = 1;
    if (ImGui::TabItemButton("Environment")) tab = 2;
    switch (tab) {
        case 0:
            GetInstance<Actor>().OnInit();
            break;
        case 1:
            break;
        case 2:
            GetInstance<Environment>().OnGUI();
            break;
    }
    ImGui::EndTabBar();
    ImGui::End();
}

void MainGUI::OnUpdate() {
    GetInstance<Environment>().OnUpdate();
}



