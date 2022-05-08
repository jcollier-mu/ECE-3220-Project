//
// Created by James Collier on 5/8/22.
//

#ifndef FINAL_PROJECT_MESSAGEHANDLER_H
#define FINAL_PROJECT_MESSAGEHANDLER_H
#include <iostream>
#include <fstream>
#include <string>

// Singleton-type class that handles all messages and error logs displayed to the user during program execution
class MessageHandler {
public:
    static MessageHandler* getInstance(){
        if(!instance){
            instance = new MessageHandler();
        }
        return instance;
    }

    MessageHandler(MessageHandler const& ) = delete; // copy constructor;
    MessageHandler& operator=(MessageHandler const&) = delete; // copy assignment
    MessageHandler(MessageHandler &&) = delete; // move constructor
    MessageHandler& operator = (MessageHandler &&) = delete; // move assignment

    void printUsage();
    void printMessage(std::string msg);
    void addError();
    void printErrorLog();

private:
    static MessageHandler* instance;
    MessageHandler(){}
    std::string error_log;
};


#endif //FINAL_PROJECT_MESSAGEHANDLER_H
