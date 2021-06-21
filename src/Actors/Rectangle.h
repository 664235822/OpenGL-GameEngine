//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_RECTANGLE_H
#define OPENGL_GAMEENGINE_RECTANGLE_H

#include "Actor.h"

class Rectangle : public Actor {
public:

    Rectangle();

    void OnInit() override;

    void OnGUI() override;

    void OnUpdate() override;

private:

    unsigned int VAO{};
    unsigned int VBO{};
    unsigned int EBO{};

    float color[3]{1.0f, 0, 0};

    float vertices[24] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
            -0.5f, 0.5f, 0.0f
    };

    unsigned int indices[6] = {
            0, 1, 3,
            1, 2, 3
    };
};


#endif //OPENGL_GAMEENGINE_RECTANGLE_H
