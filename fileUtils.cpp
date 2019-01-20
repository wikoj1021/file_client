//
// Created by wikoj1021 on 12.12.2018.
//

#include "fileUtils.h"


void fileUtils::mergeParts(std::string dir, std::string basename, std::string filename) {

    std::ofstream finalFile;
    std::ifstream aktPart;
    char aktNum[6] = {0};

    int i = 0;

    finalFile.open(filename, std::ifstream::out | std::fstream::binary);

    if(finalFile.good()){


        aktPart.open(dir+"/"+basename+".part"+std::to_string(i), std::ifstream::in | std::fstream::binary);
        i++;

        while (aktPart.good()){

            char buf[64] = "";
            aktPart.read(buf, sizeof(buf));
            finalFile.write(buf, sizeof(buf));
            aktPart.close();

            aktPart.open(dir+"/"+basename+".part"+std::to_string(i), std::fstream::in | std::fstream::binary);
            i++;

        }


        finalFile.close();

    }
    else{
        std::cout << "file not oppened." << std::endl;
        system("pause");
    }


}

void fileUtils::makeParts(std::string fileName) {

    std::ifstream file;
    std::ofstream aktPart;
    int i = 0;
    file.open(fileName, std::fstream::in | std::fstream::binary);

    std::cout << "trying to open file" << std::endl;

    if(file.good()){

        std::cout << "file opened" << std::endl;

        while (!file.eof()){

            char buf[64] = "";
            file.read(buf, sizeof(buf));

            std::cout << "making part : " << i << std::endl;

            aktPart.open("parts/"+fileName+".part"+std::to_string(i), std::fstream::out | std::fstream::binary);

            if(aktPart.good()){
                aktPart.write(buf, sizeof(buf));
                aktPart.close();
            }
            i++;
        }

        file.close();

    }
    else{
        std::cout << "file not oppened." << std::endl;
        system("pause");
    }


}

std::string fileUtils::getPart(std::string fileName, fpos_t size, fpos_t startPoint) {

    std::ifstream file;
    char buf[] = {0};
    std::realloc(buf, size);

    file.open(fileName, std::fstream::in | std::fstream::binary);

    if(file.good()){
        std::ofstream log;
        file.seekg(startPoint);
        std::cout << file.eof() << std::endl;
        file.read(buf, sizeof(buf));
        file.close();
        log.open("log.txt", std::fstream::out | std::fstream::binary);
        if(log.good())
            log.write(buf, sizeof(buf));
    }
    else{
        std::cout << "can't open file: " << fileName << std::endl;
    }

    return std::string(buf);

}

int64_t fileUtils::getFile(std::string fileName, char **buf){

    std::ifstream file;
    int64_t fileSize = 0;
    file.open(fileName, std::fstream::ate);

    if (!file.good()) {
        return -1;
    }

    fileSize = file.tellg();
    file.close();
    std::cout << "filesize: " << fileSize << std::endl;
    *buf = (char *)malloc(fileSize);
    file.open(fileName, std::fstream::in | std::fstream::binary);
    file.read(*buf, fileSize);
    file.close();

    return fileSize;

}