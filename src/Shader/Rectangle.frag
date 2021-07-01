#version 330 core
in vec4 vertexColor;
in vec2 texCoord;
uniform Sampler2D ourTexture;
out vec4 FragColor;
void main() {
    if (ourTexture == 0){
        FragColor = vertexColor;
    } else {
        FragColor = texture(ourTexture, TexCoord) * vertexColor;
    }
}