//
// Created by 朱方灏钧 on 2021/2/23.
//

#include "Environment.h"
#include "ClearColor.h"

Environment::Environment() = default;

void Environment::Init() {
    auto *clearColor = new ClearColor();

    array.push_back(clearColor);
}


void Environment::OnGUI() {
    for (auto current:array) {
        current->OnGUI();
    }
}

void Environment::OnUpdate() {
    for (auto current:array) {
        current->OnUpdate();
    }
}



