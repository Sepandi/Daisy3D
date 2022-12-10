#include "Daisy3D/Daisy.hpp"

int main(){
    Daisy::WindowInit("OpenGL gonna Make me cry :)",1000,800);

    const std::vector<GLfloat> vertexData{
        // first triangle

        -0.5f,-0.5f,1.0f,   // buttom left vertex pos 
        0.0f,1.0f,0.0f,     // color 

        0.5f,-0.5f,1.0f,    //buttom right vertex pos
        0.0f,0.0f,1.0f,     // color 

        -0.5f,0.5f,1.0f,    // top left vertex pos
        1.0f,0.0f,0.0f,     // color 

        0.5f,0.5f,1.0f,     //Top right vertex pos
        0.0f,1.0f,0.0f,     // color 

    };


    GLuint vertexArrayObject = 0;

    GLuint vertexBufferObject = 0;
    GLuint indexBufferObject = 0;

    GLuint graphicsPiplineShaderProg = Shaders::CreateShaderProgram(Shaders::LoadShaderAsString("Shaders/vert.glsl"),Shaders::LoadShaderAsString("Shaders/frag.glsl"));



    glGenVertexArrays(1,&vertexArrayObject);
    glBindVertexArray(vertexArrayObject);

    // vartex info
    glGenBuffers(1,&vertexBufferObject);
    glBindBuffer(GL_ARRAY_BUFFER,vertexBufferObject);
    glBufferData(GL_ARRAY_BUFFER,vertexData.size()*sizeof(GL_FLOAT),vertexData.data(),GL_STATIC_DRAW);

    const std::vector<GLuint> indexBufferData{2,0,1, 3,2,1};
    glGenBuffers(1,&indexBufferObject);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,indexBufferObject);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,indexBufferData.size()*sizeof(GLuint),indexBufferData.data(),GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(GL_FLOAT)*6,(void*)0);

    // color info 
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(GL_FLOAT)*6,(GLvoid*)(sizeof(GL_FLOAT)*3));

    glBindVertexArray(0);
    glDisableVertexAttribArray(1);
    int x = 0;
    while(Daisy::WindowShouldBeOpen(0,0,0)){
        //input 
        //Update
        x++;
        glDisable(GL_DEPTH_TEST);
        glDisable(GL_CULL_FACE);
        glViewport(0,0,Daisy::width,Daisy::height);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glUseProgram(graphicsPiplineShaderProg);
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
        
        //Draw
        glBindVertexArray(vertexArrayObject);
        glBindBuffer(GL_ARRAY_BUFFER,vertexBufferObject);
        //glDrawArrays(GL_TRIANGLES,0,6);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);   
        
        SDL_GL_SwapWindow(Daisy::window);
    }

    Daisy::Quit();
}