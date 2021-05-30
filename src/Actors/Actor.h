//
// Created by 朱洲 on 2021/5/30.
//

#ifndef OPENGL_GAMEENGINE_ACTOR_H
#define OPENGL_GAMEENGINE_ACTOR_H

#include <vector>

class Actor {

public:

    Actor();

    void init();

    void OnInitGui();

    std::vector<Actor*> initArray;
    std::vector<Actor*> currentArray;

protected:

    char* label{};

    virtual void CreateButtonOnClick();

};


#endif //OPENGL_GAMEENGINE_ACTOR_H
