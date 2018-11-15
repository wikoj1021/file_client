//
// Created by wikoj on 13.11.2018.
//

#ifndef FILE_CLIENT_UTILITIES_H
#define FILE_CLIENT_UTILITIES_H

#include <string>

namespace util{


    void toUpperCase(std::string &str){
        for(char &c : str){
            c = toupper(c);
        }
    }

    void toLowerCase(std::string &str){
        for(char &c : str){
            c = tolower(c);
        }
    }

}

#endif //FILE_CLIENT_UTILITIES_H
