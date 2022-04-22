//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SCHEDULE_H
#define FINAL_PROJECT_SCHEDULE_H
#include <vector>
#include <string>
#include "Course.h"

// "Product" class of builder design
// Often there will be multiple Schedules generated, which the calling program can parse and print separately
class Schedule {
public:
    std::string print_schedule();
    bool isCompatibleWithSchedule(Course c);
    bool isValidSchedule();
    void addCourse(Course c);
    Schedule(std::vector<Course> schedule) : schedule_(schedule){};
    Schedule(Course c) {schedule_.push_back(c);};
    int size(){return (int)schedule_.size();};
private:
    std::vector<Course> schedule_;
};


#endif //FINAL_PROJECT_SCHEDULE_H
