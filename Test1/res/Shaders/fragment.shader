#version 330 

out vec4 FragColour;
in vec3 ourColour;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main(){
    FragColour = texture(ourTexture, TexCoord) * vec4(ourColour, 1.0);
}