//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SCHEDULEPLANNER_H
#define FINAL_PROJECT_SCHEDULEPLANNER_H
#include "ScheduleBuilder.h"
#include "SlowScheduleBuilder.h"
#include "AssignmentScheduleBuilder.h"

// "director" class of builder design
class SchedulePlanner {
public:
    SchedulePlanner(ScheduleBuilder* builder) : builder_(builder){};
    void constructSchedules() {builder_->buildSchedules();};
    std::vector<Schedule> getSchedules() const {return builder_->getSchedules();};
    void writeSchedulesToFile(std::string file);
    std::string schedulesToString();
    ~SchedulePlanner() {if(builder_ != nullptr) delete builder_;};
private:
    ScheduleBuilder *builder_;
};


#endif //FINAL_PROJECT_SCHEDULEPLANNER_H
