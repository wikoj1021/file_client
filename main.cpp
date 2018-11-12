#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<std::string, std::string> parseArgs(int argc, char **args){

    std::unordered_map<std::string, std::string> mappedArgs;

    std::cout << mappedArgs.size() << std::endl;

    for(int i = 1; i < argc; i++){
        if(args[i][0] == '-'){

            std::string arg(args[i]);
            std::string argVal(args[++i]);

            mappedArgs.insert({arg, argVal});

        }
    }

    for(std::pair<std::string, std::string> elem: mappedArgs){
        std::cout << elem.first << " :: " << elem.second << std::endl;
    }

    return mappedArgs;

}

int main(int argc, char **args) {

    parseArgs(argc, args);

    return 0;
}