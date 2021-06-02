//
// Created by 朱洲 on 2021/6/2.
//

#ifndef OPENGL_GAMEENGINE_SINGLETON_H
#define OPENGL_GAMEENGINE_SINGLETON_H

template<typename T>
T &GetInstance() {
    static T instance;
    return instance;
}

#endif //OPENGL_GAMEENGINE_SINGLETON_H
