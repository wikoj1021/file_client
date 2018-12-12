//
// Created by wikoj on 13.11.2018.
//

#ifndef FILE_CLIENT_UTILITIES_H
#define FILE_CLIENT_UTILITIES_H

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

namespace util{

    static void toUpperCase(std::string &str){
        for(char &c : str){
            c = toupper(c);
        }
    }
    static void toLowerCase(std::string &str){
        for(char &c : str){
            c = tolower(c);
        }
    }
    static std::unordered_map<std::string, std::string> parseArgs(int argc, char **args){
        std::unordered_map<std::string, std::string> mappedArgs;
        std::locale loc;

        for(int i = 1; i < argc; i++){
            std::string arg(args[i]);
            if(arg.substr(0,2) == "--" && arg.erase(0,2) != ""){

                util::toUpperCase(arg);

                std::string argVal(args[i+1]);

                if(i+1 >= argc || argVal.substr(0,2) == "--"){
                    mappedArgs.insert({arg, "1"});
                    continue;
                }

                util::toUpperCase(argVal);
                mappedArgs.insert({arg, argVal});
                i++;

            }
        }

    #ifdef DEBUG
        for(std::pair<std::string, std::string> arg : mappedArgs){
            std::cout << arg.first << " :: " << arg.second << std::endl;
        }
    #endif

        return mappedArgs;

    }
    static std::vector<std::string> parseCommandLine(std::string commandLine){

        std::vector<std::string> commandArgs;
        std::size_t lastPos = 0;
        std::size_t aktPos = 0;

        do{

            aktPos = commandLine.find(' ', lastPos+1);
            commandArgs.push_back(commandLine.substr(lastPos, aktPos-lastPos));
            lastPos = aktPos+1;

        }while (aktPos != std::string::npos);

        util::toUpperCase(commandArgs[0]);

#ifdef DEBUG

        std::cout << "command args: " << std::endl;

        for(std::string s : commandArgs){
            std::cout << s << std::endl;
        }

        std::cout << "end of command args" << std::endl;

#endif

        return commandArgs;

    }

}


#endif //FILE_CLIENT_UTILITIES_H
