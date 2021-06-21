//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_TRIANGLE_H
#define OPENGL_GAMEENGINE_TRIANGLE_H

#include "Actor.h"

class Triangle : public Actor {

public:

    Triangle();

    void OnInit() override;

    void OnGUI() override;

    void OnUpdate() override;

private:

    unsigned int VAO{};
    unsigned int VBO{};

    float color[3]{1.0f, 0, 0};

    float vertices[18] = {
            0.5f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f
    };
};


#endif //OPENGL_GAMEENGINE_TRIANGLE_H
