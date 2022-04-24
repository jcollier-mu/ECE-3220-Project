//
// Created by James Collier on 4/22/22.
//

#include "SchedulePlanner.h"
#include <fstream>

void SchedulePlanner::writeSchedulesToFile(std::string file) {
    std::vector<Schedule> schedules = this->getSchedules();
    ofstream ofs;
    ofs.open(file);
    if(ofs.is_open()) {
        for (auto schedule = schedules.begin(); schedule < schedules.end(); schedule++) {
            ofs << schedule->to_string();
            ofs << "*****************************************************************************************************************************************\n\n";
        }
    }else{
        throw std::runtime_error("Could not open file for writing");
    }
}