#pragma once

#include <iostream>
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
                FILE* file;
                fopen_s(&file, file_path, "r");

                if (file == nullptr)
                {
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
        };
    }
}