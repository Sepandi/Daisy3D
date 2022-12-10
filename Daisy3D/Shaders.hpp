namespace Shaders{
    std::string LoadShaderAsString(const std::string& path){
        std::string result = "";
        std::string line = "";
        std::ifstream myFile(path.c_str());

        if (myFile.is_open()){
            while(std::getline(myFile,line)){
                result += line + "\n";
            }
        }
        myFile.close();
        return result;
    }

    GLuint CompileShader(GLuint type,const std::string& source){
        GLuint shaderObject = 0;
        if (type == GL_VERTEX_SHADER){
            shaderObject = glCreateShader(GL_VERTEX_SHADER);
        }else if (type == GL_FRAGMENT_SHADER){
            shaderObject = glCreateShader(GL_FRAGMENT_SHADER);
        }
        const char* src = source.c_str();
        glShaderSource(shaderObject,1,&src,nullptr);
        glCompileShader(shaderObject);

        return shaderObject;
    }

    GLuint CreateShaderProgram(std::string vertexShaderSource,std::string fragmentShaderSource){
        GLuint programObject = glCreateProgram();

        GLuint vertexShader = CompileShader(GL_VERTEX_SHADER,vertexShaderSource);
        GLuint fragentShader = CompileShader(GL_FRAGMENT_SHADER,fragmentShaderSource);

        glAttachShader(programObject,vertexShader);
        glAttachShader(programObject,fragentShader);
        glLinkProgram(programObject);

        glValidateProgram(programObject);

        return programObject;
    }
}