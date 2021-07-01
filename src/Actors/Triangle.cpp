//
// Created by 朱洲 on 2021/5/30.
//

#define STB_IMAGE_IMPLEMENTATION
#include "Triangle.h"

Triangle::Triangle() {
    label = "Triangle";
    fileBrowser.SetTitle("Find Texture");
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

    //uv属性
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(2);

}

void Triangle::OnUpdate() {
    //画三角形
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texBuffer);
    glBindVertexArray(VAO);

    //使用着色器
    shader->use();
    shader->setVector3("aColor", color);
    shader->setInt("ourTexture", 1);

    glDrawArrays(GL_TRIANGLES, 0, 3);//三角形
}

void Triangle::OnGUI() {
    ImGui::Text("Color");
    ImGui::DragFloat3("Color", color, 0.05f, 0.0f, 1.0f);
    ImGui::Text("Texture");
    if (ImGui::Button("Choose Texture")) {
        fileBrowser.Open();
    }
    fileBrowser.Display();
    if (fileBrowser.HasSelected()) {
        //应用纹理
        glGenTextures(1, &texBuffer);
        glBindTexture(GL_TEXTURE_2D, texBuffer);

        int width, height, nrChannel;
        unsigned char *data = stbi_load(fileBrowser.GetSelected().string().c_str(), &width, &height, &nrChannel, 0);
        if (data) {
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
        } else {
            printf("load image failed.");
        }
        stbi_image_free(data);
        fileBrowser.ClearSelected();
    }
}
