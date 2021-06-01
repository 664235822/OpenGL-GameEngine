//
// Created by 朱方灏钧 on 2021/2/23.
//


#ifndef OPENGL_GAMEENGINE_COMPONENT_H
#define OPENGL_GAMEENGINE_COMPONENT_H

#include "vector"

class Component {
public:

    Component();

    void Init();

    virtual void OnGUI();

    virtual void OnUpdate();

private:

    std::vector<Component *> array;

};

#endif //OPENGL_GAMEENGINE_COMPONENT_H
