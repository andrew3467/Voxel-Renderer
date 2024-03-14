#type vertex
#version 460

layout (location = 0) in vec3 aPosition;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;


uniform mat4 uTransform;
uniform mat4 uViewProj;

out vec4 vColor;


void main() {
    vColor = vec4(aColor, 1.0);
    gl_Position =  uViewProj * uTransform * vec4(aPosition, 1.0);
}


#type fragment
#version 460

layout (location = 0) out vec4 FragColor;

uniform vec3 uColor;


in vec4 vColor;

void main() {
    FragColor = vColor;
    //FragColor = vec4(uColor, 1.0);
}
