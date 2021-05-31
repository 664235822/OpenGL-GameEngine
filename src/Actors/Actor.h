//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_ACTOR_H
#define OPENGL_GAMEENGINE_ACTOR_H

#include <vector>
#include "../Components/Shader.h"

class Actor {

public:

    Actor();

    void OnInitGui();

    virtual void OnInit();

    virtual void OnUpdate();

    std::vector<Actor *> array;

protected:

    char *label;

    Shader *shader = nullptr;

};


#endif //OPENGL_GAMEENGINE_ACTOR_H
