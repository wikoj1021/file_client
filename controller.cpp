//
// Created by wikoj on 13.11.2018.
//

#include "includes/controller.h"


cmdController::cmdController(std::string connectionMode) {

    #ifdef  DEBUG
    std::cout << connectionMode << std::endl;
    #endif

    isRunning = true;
    sf::Thread(&cmdController::getCommand, this).launch();

}

void cmdController::getCommand() {
    while(isRunning){

        std::string command;

        std::cin >> command;
        std::cout << command << std::endl;
        parseCommand(command);

    }
}

void cmdController::parseCommand(std::string command) {

    util::toUpperCase(command);


    if(command == "TEST")
        std::cout << "TEST" << std::endl;
    else if(command == "STOP")
        isRunning = false;
    //else if();
    else
        std::cout << "nie rozpoznano polecenia: " << command << std::endl;


}

