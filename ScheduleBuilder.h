//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SCHEDULEBUILDER_H
#define FINAL_PROJECT_SCHEDULEBUILDER_H
#include "Schedule.h"

// interface that all concrete builders inherit from
class ScheduleBuilder {
public:
    virtual std::vector<Schedule> getSchedules() const = 0; // more than one schedule may be generated
    virtual void buildSchedules() = 0;
    virtual ~ScheduleBuilder() {};
};
#endif //FINAL_PROJECT_SCHEDULEBUILDER_H
