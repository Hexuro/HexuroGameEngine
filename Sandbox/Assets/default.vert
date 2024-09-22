#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTex;

out vec3 color;
out vec2 texCoord;

uniform float scale;
uniform mat4 modelMatrix;
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main()
{
   gl_Position = projectionMatrix * viewMatrix * modelMatrix * vec4(aPos, 1.0);
   color = aColor;
   texCoord = aTex;
}