//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_ACTOR_H
#define OPENGL_GAMEENGINE_ACTOR_H

#include <vector>
#include "../imgui/imgui.h"
#include "../Tools/Shader.h"

class Actor {

public:

    Actor();

    virtual void OnInit();

    virtual void OnGUI();

    virtual void OnUpdate();

    char* label{};

    std::vector<Actor *> array;

protected:

    Shader *shader{};

};


#endif //OPENGL_GAMEENGINE_ACTOR_H
