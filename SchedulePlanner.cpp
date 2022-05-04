//
// Created by James Collier on 4/22/22.
//

#include "SchedulePlanner.h"
#include <fstream>
#include <sstream>

void SchedulePlanner::writeSchedulesToFile(std::string file) {
    ofstream ofs;
    ofs.open(file);
    if(ofs.is_open()) {
        ofs << this->schedulesToString();
    }else{
        throw std::runtime_error("Could not open file for writing");
    }
}

std::string SchedulePlanner::schedulesToString() {
    std::vector<Schedule> schedules = this->getSchedules();
    stringstream ss;
    for(auto schedule=schedules.begin();schedule<schedules.end();schedule++){
        ss << schedule->to_string();
        ss << "*********************************************************************************************************************************************************\n\n";
    }
    return ss.str();
}