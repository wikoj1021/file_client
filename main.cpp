#include <iostream>
#include <string>
#include "includes/controller.h"

int main(int argc, char **args) {

    std::unordered_map<std::string, std::string> argumentsMap = util::parseArgs(argc, args);

    argumentsMap["MODE"]=argumentsMap["MODE"]==""?"TCP":argumentsMap["MODE"];

    if(argumentsMap["NOGUI"] == "1"){
        cmdController controller(argumentsMap["MODE"]);
    }

    return 0;
}