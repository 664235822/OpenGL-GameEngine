//
// Created by 朱方灏钧 on 2021/2/23.
//

#include "Component.h"
#include "ClearColor.h"

Component::Component() = default;

void Component::Update() {

}

void Component::OnGui() {

}

void Component::init() {
    auto *clearColor = new ClearColor();

    array.push_back(clearColor);
}
