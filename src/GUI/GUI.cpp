//
// Created by 朱洲 on 2021/6/1.
//

#include "GUI.h"
#include "MainGUI.h"

GUI::GUI() = default;

void GUI::Init() {
    auto *mainGui = new MainGUI();
    mainGui->Init();

    array.push_back(mainGui);
}

void GUI::OnGUI() {
    for (auto current:array) {
        current->OnGUI();
    }
}

void GUI::OnUpdate() {
    for (auto current:array) {
        current->OnUpdate();
    }
}


