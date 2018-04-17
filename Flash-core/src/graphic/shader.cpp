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

        void Shader::set_uniform_1f(const GLchar* name, float value) const
        {
            glUniform1f(get_uniform_location(name), value);
        }

        void Shader::set_uniform_1i(const GLchar* name, int value) const
        {
            glUniform1i(get_uniform_location(name), value);
        }

        void Shader::set_uniform_2f(const GLchar* name, const math::vector2& vector) const
        {
            glUniform2f(get_uniform_location(name), vector.x, vector.y);
        }

        void Shader::set_uniform_3f(const GLchar* name, const math::vector3& vector) const
        {
            glUniform3f(get_uniform_location(name), vector.x, vector.y, vector.z);
        }

        void Shader::set_uniform_4f(const GLchar* name, const math::vector4& vector) const
        {
            glUniform4f(get_uniform_location(name), vector.x, vector.y, vector.z, vector.w);
        }

        void Shader::set_uniform_mat4(const GLchar* name, const math::matrix4& matrix) const
        {
            glUniformMatrix4fv(get_uniform_location(name), 1, GL_FALSE, matrix.elements);
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

        GLint Shader::get_uniform_location(const GLchar* name) const
        {
            return glGetUniformLocation(shader_id_, name);
        }
    }
}
