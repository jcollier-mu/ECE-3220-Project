//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SLOWSCHEDULEBUILDER_H
#define FINAL_PROJECT_SLOWSCHEDULEBUILDER_H
#include "ScheduleBuilder.h"

// one of the implementations of ScheduleBuilder
// is "slow", just builds a schedule by iterating through all possible schedules
class SlowScheduleBuilder : public ScheduleBuilder {
public:
    Schedule getSchedule() const override{return this->schedule_;};


private:
    Schedule schedule_;
};


#endif //FINAL_PROJECT_SLOWSCHEDULEBUILDER_H
