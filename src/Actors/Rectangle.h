//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_RECTANGLE_H
#define OPENGL_GAMEENGINE_RECTANGLE_H

#include "Actor.h"

class Rectangle : public Actor {
public:

    Rectangle();

protected:

    void CreateButtonOnClick() override;

private:
    float vertices[12]={
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
