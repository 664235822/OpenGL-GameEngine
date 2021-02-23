//
// Created by 朱方灏钧 on 2021/2/23.
//


#ifndef OPENGL_GAMEENGINE_COMPONENTS_H
#define OPENGL_GAMEENGINE_COMPONENTS_H

#include "vector"

class Components {
public:

    Components();

    void init();

    virtual void OnGui();
    virtual void Update();

    std::vector<Components*> array;
};

#endif //OPENGL_GAMEENGINE_COMPONENTS_H
