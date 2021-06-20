//
// Created by 朱洲 on 2021/6/2.
//

#include <string>
#include "ScenesGUI.h"
#include "../Tools/Singleton.h"

ScenesGUI::ScenesGUI() = default;

void ScenesGUI::Init() {

}

void ScenesGUI::OnGUI() {
    ImGui::Begin("Scenes");
    if (isInit) {
        ImGui::SetWindowPos(ImVec2(1000.f, 50.f));
        ImGui::SetWindowSize(ImVec2(300.f, 600.f));
        isInit = false;
    }
    ImGui::Text("Objects");
    if (ImGui::BeginListBox("", ImVec2(300.f, 200.f))) {
        auto array = GetInstance<Actor>().array;
        for (int i = 0; i < array.size(); i++) {
            Actor *current = array[i];
            char *label = new char;
            sprintf(label, "%d %s", i + 1, current->label);
            ImGui::RadioButton(label, &select, i);
        }
        ImGui::EndListBox();
    }
    ImGui::Text("Setting");
    if (!GetInstance<Actor>().array.empty()) {
        GetInstance<Actor>().array[select]->OnGUI();
    }

    ImGui::End();
}

void ScenesGUI::OnUpdate() {
    GetInstance<Actor>().OnUpdate();
}
