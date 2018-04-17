#pragma once

#include <string>

namespace flash
{
    namespace util
    {
        class FileUtil
        {
        public:
            static bool read_file(const char* file_path, std::string &result)
            {
                FILE* file = nullptr;
                auto errno_t = fopen_s(&file, file_path, "r+");

                if (file == nullptr)
                {
                    // todo log error info
                    return false;
                }

                fseek(file, 0, SEEK_END);
                const size_t size = ftell(file);

                const auto content = new char[size];
                memset(content, 0, size);

                rewind(file);
                fread(content, sizeof(char), size, file);
                fclose(file);

                result.assign(content, size);

                delete[] content;
                return true;
            }

            static bool write_file(const char* file_path, const std::string& content)
            {
                FILE* file = nullptr;
                auto errno_t = fopen_s(&file, file_path, "w+");

                if (file == nullptr)
                {
                    // todo log error info
                    return false;
                }

                const auto content_chars = content.c_str();

                fwrite(content_chars, sizeof(char), content.size(), file);
                fclose(file);
                return true;
            }
        };
    }
}