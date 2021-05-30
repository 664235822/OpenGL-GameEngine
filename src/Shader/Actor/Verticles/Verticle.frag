#version 330 core
layout (location = 0) in vec3 aColor;
out vec4 FragColor;
void main() {
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}