//
// Created by wikoj1021 on 10.12.2018.
//

#include "requestListenerTCP.h"
#include <iostream>
#include <fstream>
#include "includes/utilities.h"


RequestListenerTCP::RequestListenerTCP() {


}


void RequestListenerTCP::listen() {

    sf::TcpListener listener;

    bool running = true;

    sf::TcpSocket client;
    sf::Socket::Status openError;

    if ((openError = listener.listen(port)) != sf::Socket::Status::Done){

        std::cout << "port not oppend code: " << openError << std::endl;
        running = false;

    }

    while(running){

        std::cout << "listening on " << port << std::endl;

        uint8_t data[128];
        size_t recived;
        std::fstream file;
        std::string commandStr;
        std::vector<std::string> requestVector;
        std::string fileDir;
        sf::Socket::Status status = listener.accept(client);
        char* fileBuf = nullptr;


        if(status == sf::Socket::Status::Done){
            char c = 0;
            std::cout << "status: " << status << std::endl;

            client.receive(&c, sizeof(c), recived);
            while(c != '\n'){
                commandStr += c;
                client.receive(&c, sizeof(c), recived);
            };

            serverCommands command = parseRequest(&requestVector, commandStr);

            switch (command) {
                case PUSH:
                    fileDir = "received/"+requestVector.at(1);

                    std::cout << fileDir << std::endl;

                    file.open(fileDir, std::fstream::out | std::fstream::binary);

                    if(!file.good()){
                        std::cout << "not opened filename " << fileDir << std::endl;
                    }

                    while (sf::Socket::Status::Done == (status = client.receive(data, sizeof(data), recived))) {

                        std::cout << "status: " << status << std::endl;
                        std::cout << "data: " << std::endl;
                        std::cout << data << std::endl;

                        file.write((char*)data, sizeof(data));

                    }

                    file.close();

                    std::cout << data << std::endl;
                    std::cout << "recived: " << recived << std::endl;
                    break;

                case PULL:
                    fileDir = "received/"+requestVector.at(1);

                    fileUtils::getFile(fileDir, &fileBuf);

                    client.send(fileBuf, sizeof(fileBuf));

                    break;
                default:

                    break;

            }
        }
    }



    listener.close();

}

bool RequestListenerTCP::startListening(unsigned short port) {

    this->port = port;


    listeningThread = new sf::Thread(&RequestListenerTCP::listen, this);
    listeningThread->launch();

    return true;
}

serverCommands RequestListenerTCP::parseRequest(std::vector<std::string>* requestVector, std::string request) {
    std::cout << "parsing request: " << request << std::endl;

    *requestVector = util::parseCommandLine(request);

    if("PUSH" == requestVector->at(0))
        return PUSH;
    else if("PULL" == requestVector->at(0))
        return PULL;

    return NOT_IMPLEMENTED;
}