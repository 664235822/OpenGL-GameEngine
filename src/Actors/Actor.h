//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_ACTOR_H
#define OPENGL_GAMEENGINE_ACTOR_H

#include <vector>
#include <string>
#include "../Tools/Shader.h"

class Actor {

public:

    Actor();

    virtual void OnInit();

    virtual void OnUpdate();

protected:

    string label{};

    Shader *shader = nullptr;

    std::vector<Actor *> array;

};


#endif //OPENGL_GAMEENGINE_ACTOR_H
