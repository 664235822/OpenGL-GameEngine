//
// Created by 朱方灏钧 on 2021/2/23.
//

#ifndef OPENGL_GAMEENGINE_CLEARCOLOR_H
#define OPENGL_GAMEENGINE_CLEARCOLOR_H

#include "Components.h"

class ClearColor : public Components{

public:

    ClearColor();

    void Update() override;

    void OnGui() override;

private:

    float color[4]{};

};


#endif //OPENGL_GAMEENGINE_CLEARCOLOR_H
