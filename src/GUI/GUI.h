//
// Created by 朱洲 on 2021/6/1.
//

#ifndef OPENGL_GAMEENGINE_GUI_H
#define OPENGL_GAMEENGINE_GUI_H

#include "vector"
#include "../Actors/Actor.h"
#include "../Environments/Environment.h"
#include "../imgui/imgui.h"

class GUI {

public:

    GUI();

    virtual void Init();

    virtual void OnGUI();

    virtual void OnUpdate();

protected:

    bool isInit = true;

private:

    std::vector<GUI *> array;

};


#endif //OPENGL_GAMEENGINE_GUI_H
