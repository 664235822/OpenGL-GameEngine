//
// Created by 朱洲 on 2021/5/30.
//

#include "Actor.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "../imgui/imgui.h"

Actor::Actor() = default;

void Actor::OnInit() {
    ImGui::Text("Create");
    if (ImGui::Button("Triangle")) {
        auto *triangle = new Triangle();
        triangle->OnInit();
        array.push_back(triangle);
    }
    if (ImGui::Button("Rectangle")) {
        auto *rectangle = new Rectangle();
        rectangle->OnInit();
        array.push_back(rectangle);
    }
}

void Actor::OnUpdate() {
    for (auto current:array) {
        current->OnUpdate();
    }
}


