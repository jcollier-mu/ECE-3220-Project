//
// Created by James Collier on 4/22/22.
//

#include "Schedule.h"

bool Schedule::isCompatibleWithSchedule(Course c) {
    if(schedule_.empty()) return true;
    else{
        bool flag;
        for(auto course = schedule_.begin(); course < schedule_.end(); course++){
            flag = course->getMeetingTimes().isCompatible(c.getMeetingTimes());
            if(!flag) return flag;
        }
    }
    return true;
}

void Schedule::addCourse(Course c) {
    schedule_.push_back(c);
}

bool Schedule::isValidSchedule() {
    for(auto i=schedule_.begin(); i<schedule_.end(); i++){
        for(auto j = i+1; j < schedule_.end(); j++){
            if(!(i->getMeetingTimes().isCompatible(j->getMeetingTimes()))){
                return false;
            }
        }
    }
    return true;
}