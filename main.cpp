#include <iostream>
#include <string>
#include "includes/controller.h"
#include "includes/utilities.h"
#include <SFML/Network.hpp>
#include "fileUtils.h"
int main(int argc, char **args) {

    std::unordered_map<std::string, std::string> argumentsMap = util::parseArgs(argc, args);

    argumentsMap["MODE"]=argumentsMap["MODE"].empty()?"TCP":argumentsMap["MODE"];


    if(argumentsMap["MKPARTS"] != ""){
        fileUtils::makeParts(argumentsMap["MKPARTS"]);
    }
    else if(argumentsMap["NOGUI"] == "1"){
        cmdController controller(argumentsMap["MODE"], argumentsMap);
    }

    return 0;
}