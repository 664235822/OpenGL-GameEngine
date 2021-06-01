//
// Created by 朱方灏钧 on 2021/2/23.
//

#include "Component.h"
#include "ClearColor.h"

Component::Component() = default;

void Component::Init() {
    auto *clearColor = new ClearColor();

    array.push_back(clearColor);
}


void Component::OnGUI() {
    for (auto current:array) {
        current->OnGUI();
    }
}

void Component::OnUpdate() {
    for (auto current:array) {
        current->OnUpdate();
    }
}



