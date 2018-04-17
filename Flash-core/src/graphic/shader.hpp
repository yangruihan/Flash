#pragma once

#include <GL/glew.h>
#include "../util/file_util.hpp"
#include "../math/math.h"

namespace flash
{
    namespace graphic
    {
        class Shader
        {
        private:
            GLuint shader_id_;
            const char* vert_path_;
            const char* frag_path_;

        public:
            Shader(const char* vert_path, const char* frag_path);
            ~Shader();

            void set_uniform_1f   (const GLchar* name, float value) const;
            void set_uniform_1i   (const GLchar* name, int value) const;
            void set_uniform_2f   (const GLchar* name, const math::vector2& vector) const;
            void set_uniform_3f   (const GLchar* name, const math::vector3& vector) const;
            void set_uniform_4f   (const GLchar* name, const math::vector4& vector) const;
            void set_uniform_mat4 (const GLchar* name, const math::matrix4& matrix) const;

            void enable() const;
            void disable() const;

        private:
            GLuint load() const;
            GLint get_uniform_location(const GLchar* name) const;
        };
    }
}
