#version 330 

out vec4 FragColour;
in vec3 ourColour;

void main(){
    FragColour = vec4(ourColour, 1.0f);
}