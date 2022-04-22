//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SCHEDULE_H
#define FINAL_PROJECT_SCHEDULE_H
#include <vector>
#include <string>
#include "Course.h"

// "Product" class of builder design
class Schedule {
public:
    std::string print_schedule();
private:
    std::vector<Course> schedule;
};


#endif //FINAL_PROJECT_SCHEDULE_H
