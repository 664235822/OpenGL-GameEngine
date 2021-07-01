//
// Created by 朱洲 on 2021/5/31.
//

#ifndef OPENGL_GAMEENGINE_SHADER_H
#define OPENGL_GAMEENGINE_SHADER_H

#include <string>

using namespace std;

class Shader {
public:

    Shader(const char *vertexPath, const char *fragmentPath);

    void use();

    void setBool(const std::string &name, bool value) const;

    void setInt(const std::string &name, int value) const;

    void setFloat(const std::string &name, float value) const;

    void setVector3(const string &name, float value[3]) const;

    void setTexImage(const string &name, float value[3]) const;

private:
    string vertexString;
    string fragmentString;

    const char *vertexSource;
    const char *fragmentSource;

    unsigned int ID;

    void checkCompileErrors(unsigned int ID, string type);
};


#endif //OPENGL_GAMEENGINE_SHADER_H
