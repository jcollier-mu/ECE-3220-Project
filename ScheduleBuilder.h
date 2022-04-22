//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SCHEDULEBUILDER_H
#define FINAL_PROJECT_SCHEDULEBUILDER_H
#include "Schedule.h"

// interface that all concrete builders inherit from
class ScheduleBuilder {
public:
    virtual Schedule getSchedule() const = 0;
};
#endif //FINAL_PROJECT_SCHEDULEBUILDER_H
