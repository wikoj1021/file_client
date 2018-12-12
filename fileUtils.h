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

};


#endif //FILE_CLIENT_FILEUTILS_H
