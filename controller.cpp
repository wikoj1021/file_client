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

        try {
            std::cout << "uploading file: " << arguments.at(1) << " to server: " << arguments.at(2) << ":" << arguments.at(3) << std::endl;

            char *buf;
            int64_t size = fileUtils::getFile(arguments.at(1), &buf);
            std::ofstream file("test.png", std::fstream::out | std::fstream::binary);
            file.write(buf, size);
            file.close();
            sf::TcpSocket socket;
            std::string serverCommand = "PUSH "+arguments.at(1)+"\n";

            socket.connect(sf::IpAddress(arguments[2]),std::stoi(arguments[3]));
            socket.send(serverCommand.data(), serverCommand.size());
            socket.send(buf, size);

        }catch(std::out_of_range &e){
            std::cout << std::endl << "sytax error: " << std::endl;
            std::cout << e.what() << std::endl;
        }



    }
    else if(arguments[0] == "PULL"){
        std::cout << "downloading file: " << arguments[1] << " from server: " << arguments[2] << ":" << arguments[3] << std::endl;

        sf::TcpSocket socket;
        std::string msg = "PULLL "+arguments[1];
        char *ch_msg = msg.data();
        sf::Socket::Status status;
        uint8_t data[128];
        size_t data_received;
        sf::TcpListener listener;

        socket.connect(sf::IpAddress(arguments[2]),std::stoi(arguments[3]));
        socket.send(ch_msg, sizeof(ch_msg));

        listener.accept(socket);

        while (sf::Socket::Status::Done == (status = socket.receive(data, sizeof(data), data_received))) {

            std::cout << "status: " << status << std::endl;
            std::cout << "data: " << std::endl;
            std::cout << data << std::endl;
        }

    }
    else if(arguments[0] == "CONNECT"){
        std::cout << "trying connect to : " << arguments[1] << ":" << arguments[2] << std::endl;
        sf::TcpSocket socket;

        socket.connect(sf::IpAddress(arguments[1]),std::stoi(arguments[2]));

        const char *msg = "test";

        std::cout << socket.send(msg, sizeof(msg)) << std::endl;

    }
    else if(arguments[0] == "PART"){
        std::cout << fileUtils::getPart(arguments[1],std::stoi(arguments[2]),std::stoi(arguments[3])) << std::endl;
    }
    else if(arguments[0] == "MERGE"){

        std::cout << "trying to merge files "  << arguments[2] << " in directory " << arguments[1] << " into file " << arguments[3] << std::endl;

        fileUtils::mergeParts(arguments[1], arguments[2], arguments[3]);

    }



}

