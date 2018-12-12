//
// Created by wikoj1021 on 10.12.2018.
//

#ifndef FILE_CLIENT_REQUESTLISTENER_H
#define FILE_CLIENT_REQUESTLISTENER_H

#include <SFML/System.hpp>
#include <SFML/Network.hpp>

class RequestListener {

protected:
    sf::Thread *requestListener;
    unsigned short port;
    virtual void parseRequest(std::string request) = 0;

public:
    virtual bool startListening(unsigned short port) = 0;

};


#endif //FILE_CLIENT_REQUESTLISTENER_H
