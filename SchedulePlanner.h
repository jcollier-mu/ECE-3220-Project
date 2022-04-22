//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SCHEDULEPLANNER_H
#define FINAL_PROJECT_SCHEDULEPLANNER_H
#include "ScheduleBuilder.h"

// "director" class of builder design
class SchedulePlanner {
public:
    SchedulePlanner(ScheduleBuilder builder);
    void constructSchedule();
    std::vector<Schedule> getSchedules() const {return builder_->getSchedules();};
    void writeSchedulesToFile(std::string file);
private:
    ScheduleBuilder builder_;
};


#endif //FINAL_PROJECT_SCHEDULEPLANNER_H
