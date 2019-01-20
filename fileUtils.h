//
// Created by wikoj1021 on 12.12.2018.
//

#ifndef FILE_CLIENT_FILEUTILS_H
#define FILE_CLIENT_FILEUTILS_H

#include <string>
#include <iostream>
#include <fstream>

class fileUtils {

private:

public:
    static void makeParts(std::string fileName);
    static void mergeParts(std::string dir, std::string basename, std::string filename);
    static std::string getPart(std::string fileName, fpos_t size, fpos_t startPoint);
    static int64_t getFile(std::string fileName, char **buf);
};


#endif //FILE_CLIENT_FILEUTILS_H
