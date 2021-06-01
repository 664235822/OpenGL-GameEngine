//
// Created by 朱洲 on 2021/6/1.
//

#ifndef OPENGL_GAMEENGINE_GUI_H
#define OPENGL_GAMEENGINE_GUI_H

#include "vector"

class GUI {

public:

    GUI();

    virtual void Init();

    virtual void OnGUI();

    virtual void OnUpdate();

private:

    std::vector<GUI *> array;

};


#endif //OPENGL_GAMEENGINE_GUI_H
