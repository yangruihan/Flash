#pragma once

#include <GL/glew.h>
#include "../util/file_util.hpp"

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

            void enable() const;
            void disable() const;

        private:
            GLuint load() const;
        };
    }
}
