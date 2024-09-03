#ifndef _HEXURO_OPENGL_SHADER_
#define _HEXURO_OPENGL_SHADER_

#include<glad/glad.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

namespace Hexuro {
    std::string GetFileContents(const char* filename);

    class Shader {
    public:
        GLuint ID;

        Shader(const char* vertexFile, const char* fragmentFile);

        void Activate();
        void Delete();
    };

}

#endif