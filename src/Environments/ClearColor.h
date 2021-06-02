//
// Created by 朱方灏钧 on 2021/2/23.
//

#ifndef OPENGL_GAMEENGINE_CLEARCOLOR_H
#define OPENGL_GAMEENGINE_CLEARCOLOR_H

#include "Environment.h"

class ClearColor : public Environment {

public:

    ClearColor();

    void OnGUI() override;

    void OnUpdate() override;

private:

    float color[4]{};

};


#endif //OPENGL_GAMEENGINE_CLEARCOLOR_H
