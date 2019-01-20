//
// Created by wikoj1021 on 10.12.2018.
//

#ifndef FILE_CLIENT_REQUESTLISTENERTCP_H
#define FILE_CLIENT_REQUESTLISTENERTCP_H

#include "requestListener.h"


class RequestListenerTCP :public RequestListener{

private:
    sf::Thread* listeningThread;
    serverCommands parseRequest(std::vector<std::string>* requestVector, std::string request);
    void listen();

public:
    RequestListenerTCP();
    bool startListening(unsigned short port = 2342);

};


#endif //FILE_CLIENT_REQUESTLISTENERTCP_H
