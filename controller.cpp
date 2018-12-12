//
// Created by wikoj on 13.11.2018.
//

#include "includes/controller.h"
#include "requestListenerTCP.h"
#include "fileUtils.h"


cmdController::cmdController(std::string connectionMode, std::unordered_map<std::string, std::string> arguments) {

    this->arguments = arguments;

    #ifdef  DEBUG
    std::cout << connectionMode << std::endl;
    #endif

    isRunning = true;

    sf::Thread(&cmdController::getCommand, this).launch();

}

void cmdController::getCommand() {



    RequestListenerTCP listener;

    unsigned short port = arguments["PORT"].empty()?2210:std::stoi(arguments["PORT"]);

    listener.startListening(port);

    std::cout << "listening for command" << std::endl;
    while(isRunning){

        std::string command;

        std::getline(std::cin, command);
        parseCommand(command);

    }
}

void cmdController::parseCommand(std::string command) {

    std::vector<std::string> arguments = util::parseCommandLine(command);

    if(arguments[0] == "STOP"){
        isRunning = false;
    }
    else if(arguments[0] == "PUSH"){
        std::cout << "uploading file: " << arguments[1] << " to server: " << arguments[2] << std::endl;
    }
    else if(arguments[0] == "CONNECT"){
        std::cout << "trying connect to : " << arguments[1] << ":" << arguments[2] << std::endl;
        sf::TcpSocket socket;



        socket.connect(sf::IpAddress(arguments[1]),std::stoi(arguments[2]));

        char *msg = "test";

        std::cout << socket.send(msg, sizeof(msg)) << std::endl;

    }
    else if(arguments[0] == "MERGE"){

        std::cout << "trying to merge files "  << arguments[2] << "in directory " << arguments[1] << "into file " << arguments[3] << std::endl;

        fileUtils::mergeParts(arguments[1], arguments[2], arguments[3]);

    }



}

