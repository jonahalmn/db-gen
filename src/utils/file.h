#pragma once
#include <iostream>
#include <fstream>

class File {
    private:
        std::ifstream m_file;

    public:
        File(const char* filename) : m_file{filename} {

        }


        ~File() {
            m_file.close();
        }

        std::string read();
};