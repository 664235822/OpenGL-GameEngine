//
// Created by 朱洲 on 2021/6/1.
//

#ifndef OPENGL_GAMEENGINE_MAINGUI_H
#define OPENGL_GAMEENGINE_MAINGUI_H

#include "GUI.h"
#include "../Actors/Actor.h"
#include "../Components/Component.h"

class MainGUI : public GUI {

public:

    MainGUI();

    void Init() override;

    void OnGUI() override;

    void OnUpdate() override;

private:

    unsigned int tab = 0;

    Actor *actor = new Actor();
    Component *component = new Component();

};


#endif //OPENGL_GAMEENGINE_MAINGUI_H
