//
// Created by 朱洲 on 2021/6/1.
//

#include "GUI.h"
#include "MainGUI.h"
#include "ScenesGUI.h"

GUI::GUI() = default;

void GUI::Init() {
    array.push_back(new MainGUI());
    array.push_back(new ScenesGUI());

    for (auto current:array) {
        current->Init();
    }
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


