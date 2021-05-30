//
// Created by 朱洲 on 2021/5/30.
//

#include "Actor.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "../imgui/imgui.h"

Actor::Actor() = default;

void Actor::init() {
    auto *triangle = new Triangle();
    auto *rectangle = new Rectangle();

    initArray.push_back(triangle);
    initArray.push_back(rectangle);
}

void Actor::OnInitGui() {
    if (ImGui::Button(label)) {
        CreateButtonOnClick();
    }
}

void Actor::CreateButtonOnClick() {

}
