//
// Created by 朱洲 on 2021/5/30.
//

#include "Triangle.h"
#include "glew.h"

Triangle::Triangle() {
    label = "Triangle";
}


void Triangle::OnInit() {
    Actor::OnInit();

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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    //颜色属性
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Triangle::OnUpdate() {
    Actor::OnUpdate();

    //画三角形、矩形
    glBindVertexArray(VAO);

    //使用着色器
    shader->use();

    glDrawArrays(GL_TRIANGLES,0,3);//三角形
}
