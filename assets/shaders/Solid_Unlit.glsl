#type vertex
#version 460

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec2 aTexCoord;


uniform mat4 uTransform;
uniform mat4 uViewProj;


void main() {
    gl_Position =  uViewProj * uTransform * vec4(aPosition, 1.0);
}


#type fragment
#version 460

layout (location = 0) out vec4 FragColor;

uniform vec3 uColor;

void main() {
    FragColor = vec4(uColor, 1.0);
}
