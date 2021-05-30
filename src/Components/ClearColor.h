//
// Created by 朱方灏钧 on 2021/2/23.
//

#ifndef OPENGL_GAMEENGINE_CLEARCOLOR_H
#define OPENGL_GAMEENGINE_CLEARCOLOR_H

#include "Component.h"

class ClearColor : public Component{

public:

    ClearColor();

    void Update() override;

    void OnGui() override;

private:

    float color[4]{};

};


#endif //OPENGL_GAMEENGINE_CLEARCOLOR_H
