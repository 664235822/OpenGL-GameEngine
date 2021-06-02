//
// Created by 朱方灏钧 on 2021/2/23.
//


#ifndef OPENGL_GAMEENGINE_ENVIRONMENT_H
#define OPENGL_GAMEENGINE_ENVIRONMENT_H

#include "vector"

class Environment {

public:

    Environment();

    void Init();

    virtual void OnGUI();

    virtual void OnUpdate();

private:

    std::vector<Environment *> array;

};

#endif //OPENGL_GAMEENGINE_ENVIRONMENT_H
