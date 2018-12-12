//
// Created by wikoj1021 on 12.12.2018.
//

#include "fileUtils.h"


void fileUtils::mergeParts(std::string dir, std::string basename, std::string filename) {

    std::ofstream finalFile;
    std::ifstream aktPart;

    int i = 0;

    finalFile.open(filename, std::ifstream::out | std::fstream::binary);

    char partName[50];
    char aktnum[6] = "";


    if(finalFile.good()){

        itoa(i, aktnum, 10);
        //std::sprintf(partName, "%s/%s.part%d", dir.c_str(), basename.c_str(), i);
        i++;
        aktPart.open(dir+"/"+basename+".part"+aktnum, std::ifstream::in | std::fstream::binary);

        //std::cout << partName << std:: endl;

        while (aktPart.good()){

            char buf[64] = "";
            itoa(i, aktnum, 10);
            //std::cout << partName << std::endl;
            std::cout << aktPart.tellg() << std::endl;
            aktPart.read(buf, sizeof(buf));
            finalFile << buf;
            std::cout << buf << std::endl;
            aktPart.close();
            //std::sprintf(partName, "%s/%s.part%d", dir.c_str(), basename.c_str(), i);
            aktPart.open(dir+"/"+basename+".part"+aktnum, std::fstream::in | std::fstream::binary);
            i++;

        }


        system("pause");

        finalFile.close();

    }
    else
        std::cout << "file not oppened." << std::endl;


}

void fileUtils::makeParts(std::string fileName) {

    std::ifstream file;
    std::ofstream aktPart;
    int i = 0;
    file.open(fileName, std::fstream::in | std::fstream::binary);
    char partName[120];

    if(file.good()){

        while (!file.eof()){



            //std::sprintf(partName, "parts/%s.part%d", fileName.c_str(), i);
            std::cout << partName << std::endl;
            //file.readsome();
            char buf[64] = "";
            file.read(buf, sizeof(buf));
            //file.getline(buf, sizeof(buf));

            char aktnum[6] = "";
            itoa(i, aktnum, 10);

            aktPart.open("parts/"+fileName+".part"+aktnum, std::fstream::out | std::fstream::binary);
            if(aktPart.good()){
                aktPart << buf;
                aktPart.close();
            }
            std::cout << buf << std::endl;
            i++;
        }

        system("pause");

        file.close();

    }
    else
        std::cout << "file not oppened." << std::endl;


}