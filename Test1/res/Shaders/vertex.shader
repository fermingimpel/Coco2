#version 330

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColour;
layout (location = 2) in vec2 aTextCoord;

out vec3 ourColour;
out vec2 TexCoord;

void main(){
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    ourColour = aColour;
    TexCoord = aTextCoord;
}