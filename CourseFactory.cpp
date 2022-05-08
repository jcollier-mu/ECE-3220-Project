//
// Created by James Collier on 4/17/22.
//

#include "CourseFactory.h"
#include <fstream>

std::shared_ptr<Course> CourseFactory::createCourse(std::string filePath) {
    std::ifstream ifs; json j;
    ifs.open(filePath);
    if(ifs.is_open()){
        ifs >> j;
    }else{
        throw std::runtime_error("File could not be opened");
    }

    return createCourse(j);
}

std::shared_ptr<Course> CourseFactory::createCourse(json j) {
    Interval i;
    i.start_hm = std::make_pair(j["start_h"], j["start_m"]);
    i.end_hm = std::make_pair(j["end_h"], j["end_m"]);
    for(auto it = j["whichDays"].begin(); it < j["whichDays"].end(); it++){
        i.whichDays.push_back(*it);
    }

    auto temp = std::shared_ptr<Course>(new Course(j["CName"], j["CNum"], j["description"], i));
    return temp;
}