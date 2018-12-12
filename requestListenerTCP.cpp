//
// Created by wikoj1021 on 10.12.2018.
//

#include "requestListenerTCP.h"
#include <iostream>


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

        sf::Socket::Status status = listener.accept(client);
        if(status == sf::Socket::Status::Done){
            client.receive(data, sizeof(data), recived);

            //std::string()

            //parseRequest();

            std::cout << data << std::endl;
            std::cout << "recived: " << recived << std::endl;
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

void RequestListenerTCP::parseRequest(std::string request) {



}