#version 330

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 aTextCoord;

out vec3 ourColour;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
    gl_Position = model * vec4(aPos, 1.0f);
    ourColour = aColour;
    TexCoord = aTextCoord;
}