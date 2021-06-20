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

    float point1[3]{0.5f, 0.5f, 0.0f};
    float point2[3]{0.5f, -0.5f, 0.0f};
    float point3[3]{-0.5f, -0.5f, 0.0f};

    float color1[3]{1.0f, 0, 0};
    float color2[3]{0, 1.0f, 0};
    float color3[3]{0, 0, 1.0f};

    float vertices[18] = {
            point1[0], point1[1], point1[2], color1[0], color1[1], color1[2],
            point2[0], point2[1], point2[2], color2[0], color2[1], color2[2],
            point3[0], point3[1], point3[2], color3[0], color3[1], color3[2],
    };
};


#endif //OPENGL_GAMEENGINE_TRIANGLE_H
