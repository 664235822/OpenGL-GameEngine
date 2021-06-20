//
// Created by 朱洲 on 2021/5/30.
//

#include "Rectangle.h"
#include "glew.h"

Rectangle::Rectangle() {
    label = "Rectangle";
}

void Rectangle::OnInit() {
    //创建VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //创建VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //创建EBO
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    //创建着色器
    shader = new Shader("../src/Shader/Rectangle.vert", "../src/Shader/Rectangle.frag");

    //顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    //颜色属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    Actor::array.push_back(this);
}

void Rectangle::OnUpdate() {
    //画三角形、矩形
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    //使用着色器
    shader->use();

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//矩形
}

void Rectangle::OnGUI() {
    ImGui::Text("Transform");
    ImGui::DragFloat3("Position 1", point1, 0.1f);
    ImGui::DragFloat3("Position 2", point2, 0.1f);
    ImGui::DragFloat3("Position 3", point3, 0.1f);
    ImGui::DragFloat3("Position 4", point4, 0.1f);
    ImGui::Text("Color");
    ImGui::DragFloat3("Color 1", color1, 0.05f, 0.0f, 1.0f);
    ImGui::DragFloat3("Color 2", color2, 0.05f, 0.0f, 1.0f);
    ImGui::DragFloat3("Color 3", color3, 0.05f, 0.0f, 1.0f);
    ImGui::DragFloat3("Color 4", color4, 0.05f, 0.0f, 1.0f);
}

