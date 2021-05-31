//
// Created by 朱方灏钧 on 2021/2/23.
//


#ifndef OPENGL_GAMEENGINE_COMPONENT_H
#define OPENGL_GAMEENGINE_COMPONENT_H

#include "vector"

class Component {
public:

    Component();

    void init();

    virtual void OnGui();
    virtual void OnUpdate();

    std::vector<Component*> array;
};

#endif //OPENGL_GAMEENGINE_COMPONENT_H
