#version 330 core
layout(location=0) in vec3 position;
layout(location=1) in vec3 vertexColors;

uniform vec2 offset;
out vec3 v_vertexColors;

void main()
{
    v_vertexColors = vertexColors;
    vec4 totalOffset = vec4(offset.x, offset.y, 0.0, 0.0);
    gl_Position = vec4(position.x+totalOffset.x, position.y+totalOffset.y, position.z+totalOffset.z,1.0f);
}