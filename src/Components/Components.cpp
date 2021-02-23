//
// Created by 朱方灏钧 on 2021/2/23.
//

#include "Components.h"
#include "ClearColor.h"

Components::Components() = default;

void Components::Update() {

}

void Components::OnGui() {

}

void Components::init() {
    auto *clearColor = new ClearColor();

    array.push_back(clearColor);
}
