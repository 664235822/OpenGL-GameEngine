//
// Created by 朱洲 on 2021/6/2.
//

#ifndef OPENGL_GAMEENGINE_SCENESGUI_H
#define OPENGL_GAMEENGINE_SCENESGUI_H

#include "GUI.h"

class ScenesGUI : public GUI {

public:

    ScenesGUI();

    void Init() override;

    void OnGUI() override;

    void OnUpdate() override;

private:

    int select = 0;

    bool isInit = true;

};


#endif //OPENGL_GAMEENGINE_SCENESGUI_H
