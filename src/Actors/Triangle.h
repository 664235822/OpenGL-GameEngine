//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_TRIANGLE_H
#define OPENGL_GAMEENGINE_TRIANGLE_H

#include "Actor.h"

class Triangle :public Actor{

public:

    Triangle();

protected:

    void CreateButtonOnClick() override;
};


#endif //OPENGL_GAMEENGINE_TRIANGLE_H
