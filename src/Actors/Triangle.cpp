//
// Created by 朱洲 on 2021/5/30.
//

#include "Triangle.h"
#include "glew.h"

Triangle::Triangle() {
    label = "Triangle";
}

void Triangle::OnInit() {
    //创建VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //创建VBO
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //创建着色器
    shader = new Shader("../src/Shader/Triangle.vert", "../src/Shader/Triangle.frag");

    //顶点属性
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
}

void Triangle::OnUpdate() {
    //画三角形
    glBindVertexArray(VAO);

    //使用着色器
    shader->use();
    shader->setVector3("aColor", color[0], color[1], color[2]);

    glDrawArrays(GL_TRIANGLES, 0, 3);//三角形
}

void Triangle::OnGUI() {
    ImGui::Text("Color");
    ImGui::DragFloat3("Color", color, 0.05f, 0.0f, 1.0f);
}
