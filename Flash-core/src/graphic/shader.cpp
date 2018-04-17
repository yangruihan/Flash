#include "shader.hpp"
#include <string>

namespace flash
{
    namespace graphic
    {
        Shader::Shader(const char* vert_path, const char* frag_path)
            : vert_path_(vert_path), frag_path_(frag_path)
        {
            shader_id_ = load();
        }

        Shader::~Shader() = default;

        void Shader::enable() const
        {
            glUseProgram(shader_id_);
        }

        void Shader::disable() const
        {
            glUseProgram(0);
        }

        GLuint Shader::load() const
        {
            const auto program = glCreateProgram();
            const auto vertex = glCreateShader(GL_VERTEX_SHADER);
            const auto fragment = glCreateShader(GL_FRAGMENT_SHADER);

            std::string vert_source_str;
            std::string frag_source_str;

            util::FileUtil::read_file(vert_path_, vert_source_str);
            util::FileUtil::read_file(frag_path_, frag_source_str);

            auto vert_source = vert_source_str.c_str();
            auto frag_source = frag_source_str.c_str();

            GLint result;

            glShaderSource(vertex, 1, &vert_source, nullptr);
            glCompileShader(vertex);
            glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE)
            {
                // todo log error info
                return 0;
            }

            glShaderSource(fragment, 1, &frag_source, nullptr);
            glCompileShader(fragment);
            glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
            if (result == GL_FALSE)
            {
                // todo log error info
                return 0;
            }

            glAttachShader(program, vertex);
            glAttachShader(program, fragment);

            glLinkProgram(program);
            glValidateProgram(program);

            glDeleteShader(vertex);
            glDeleteShader(fragment);

            return program;
        }
    }
}
