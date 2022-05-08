//
// Created by James Collier on 5/8/22.
//

#include "MessageHandler.h"

MessageHandler* MessageHandler::instance = nullptr;

void MessageHandler::printUsage() {
    std::fstream fs;
    fs.open("../usage.txt", std::fstream::in);
    if(fs.is_open()){
        std::stringstream usage;
        usage << fs.rdbuf();
        this->printMessage(usage.str());
        fs.close();
    }else{
        this->printMessage("Could not print program usage.");
    }
}

void MessageHandler::printMessage(std::string msg) {
    std::cout << msg << std::endl;
}

void MessageHandler::addError(std::string error) {
    error_log += error + "\n";
}

void MessageHandler::printErrorLog() {
    this->printMessage("Summary of Runtime Errors and Exceptions:\n");
    this->printMessage(error_log);
}