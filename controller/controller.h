//
// Created by wikoj on 13.11.2018.
//

#ifndef FILE_CLIENT_CONTROLLER_H
#define FILE_CLIENT_CONTROLLER_H

#include <string>
#include <iostream>
#include <thread>

class cmdController{

private:
    void putAllert();
    void putLog();
    void putMessage();
    void parseCommand(std::thread);

public:
    cmdController(std::string);

};

class guiController{

};


#endif //FILE_CLIENT_CONTROLLER_H
