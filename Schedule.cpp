//
// Created by James Collier on 4/22/22.
//

#include "Schedule.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <map>

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

std::string Schedule::to_string(){
    std::stringstream ss;
    ss << std::setw(30) << std::left << "Monday";
    ss << std::setw(30) << std::left << "Tuesday";
    ss << std::setw(30) << std::left << "Wednesday";
    ss << std::setw(30) << std::left << "Thursday";
    ss << std::setw(30) << std::left << "Friday" << "\n\n";
    std::sort(schedule_.begin(), schedule_.end(), [](const Course& c1, const Course& c2) -> bool {
        return c1.getMeetingTimes().start_hm < c2.getMeetingTimes().start_hm;
    });
    for(auto course = schedule_.begin(); course < schedule_.end(); course ++){
        Interval meetingTimes = course->getMeetingTimes();
        std::sort(meetingTimes.whichDays.begin(), meetingTimes.whichDays.end());
        int count = 0;
        for(auto days = meetingTimes.whichDays.begin(); days < meetingTimes.whichDays.end(); days++){
            ss << std::setw(30*((int)*days+1-count)) << std::right << course->getName();
            count = (int)*days+1;
        }
        count = 0;
        ss << "\n";
        for(auto days = meetingTimes.whichDays.begin(); days < meetingTimes.whichDays.end(); days++) {
            stringstream times;
            times << "(" << meetingTimes.start_hm.first << ":" << meetingTimes.start_hm.second <<", "
            << meetingTimes.end_hm.first << ":" << meetingTimes.end_hm.second << ")";
            ss << std::setw(30 * ((int) *days + 1 - count)) << std::right << times.str();
            count = (int)*days+1;
        }
        ss << "\n\n";
    }
    return ss.str();
}