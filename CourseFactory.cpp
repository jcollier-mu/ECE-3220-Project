//
// Created by James Collier on 4/17/22.
//

#include "CourseFactory.h"
#include <fstream>

Course* CourseFactory::createCourse(std::string filePath) {
    std::ifstream ifs; json j;
    ifs.open(filePath);
    if(ifs.is_open()){
        ifs >> j;
    }else{
        throw std::runtime_error("File could not be opened");
    }

    return createCourse(j);
}

Course* CourseFactory::createCourse(json j) {
    Interval i;
    i.start = j["start"];
    i.end = j["end"];
    for(auto it = j["whichDays"].begin(); it < j["whichDays"].end(); it++){
        i.whichDays.push_back(*it);
    }

    return new Course(j["CName"], j["CNum"], j["description"], i);
}

void CourseFactory::removeCourse(Course *c) {
    delete c;
}