#include <iostream>
#include <unordered_map>
#include <string>
#include <locale>
#include "utilities.h"
#include "controller/controller.h"
//#define DEBUG

std::unordered_map<std::string, std::string> parseArgs(int argc, char **args){

    std::unordered_map<std::string, std::string> mappedArgs;
    std::locale loc;

    for(int i = 1; i < argc; i++){
        if(args[i][0] == '-'){

            std::string arg(args[i]);
            arg.erase(0,1);

            util::toUpperCase(arg);

            if(i+1 >= argc || args[i+1][0] == '-'){
                mappedArgs.insert({arg, "1"});
                continue;
            }

            std::string argVal(args[i+1]);
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

int main(int argc, char **args) {

    std::unordered_map<std::string, std::string> argumentsMap = parseArgs(argc, args);

    argumentsMap["MODE"]=argumentsMap["MODE"]==""?"TCP":argumentsMap["MODE"];

    if(argumentsMap["NOGUI"] == "1"){
        cmdController controller(argumentsMap["MODE"]);
    }

    return 0;
}