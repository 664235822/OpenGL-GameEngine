//
// Created by 朱洲 on 2021/5/31.
//

#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <glew.h>
#include <glfw3.h>

using namespace std;

Shader::Shader(const char *vertexPath, const char *fragmentPath) {
    ifstream vertexStream;
    ifstream fragmentStream;
    stringstream vertexSStream;
    stringstream fragmentSStream;

    vertexStream.open(vertexPath);
    fragmentStream.open(fragmentPath);
    vertexStream.exceptions();
    fragmentStream.exceptions();

    try {
        if (!vertexStream.is_open() || !fragmentStream.is_open()) {
            logic_error e("open file error");
            throw exception(e);
        }

        vertexSStream << vertexStream.rdbuf();
        fragmentSStream << fragmentStream.rdbuf();

        vertexString = vertexSStream.str();
        fragmentString = fragmentSStream.str();

        vertexSource = vertexString.c_str();
        fragmentSource = fragmentString.c_str();

        unsigned int vertex, fragment;

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vertexSource, NULL);
        glCompileShader(vertex);
        checkCompileErrors(vertex, "VERTEX");

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fragmentSource, NULL);
        glCompileShader(fragment);
        checkCompileErrors(fragment, "FRAGMENT");

        ID = glCreateProgram();
        glAttachShader(ID, vertex);
        glAttachShader(ID, fragment);
        glLinkProgram(ID);
        checkCompileErrors(ID, "PROGRAM");

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    } catch (const exception &e) {
        printf(e.what());
    }
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::checkCompileErrors(unsigned int ID, string type) {
    int success;
    char infoLog[512];

    if (type != "PROGRAM") {
        glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(ID, 512, NULL, infoLog);
            cout << "shader compile error: " << infoLog << endl;
        }
    } else {
        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            cout << "program linking error: " << infoLog << endl;
        }
    }
}

void Shader::setBool(const string &name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int) value);
}

void Shader::setInt(const string &name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const string &name, float value) const {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setVector3(const string &name, float value[3]) const {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), value[0], value[1], value[2]);
}
