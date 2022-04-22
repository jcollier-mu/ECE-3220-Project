//
// Created by James Collier on 4/22/22.
//

#ifndef FINAL_PROJECT_SLOWSCHEDULEBUILDER_H
#define FINAL_PROJECT_SLOWSCHEDULEBUILDER_H
#include "ScheduleBuilder.h"

// one of the implementations of ScheduleBuilder
// is "slow", just builds a schedule by iterating through all possible schedules
// is also a basic implementation (for now), not considering any program flags/options
class SlowScheduleBuilder : public ScheduleBuilder {
public:
    std::vector<Schedule> getSchedules() const override{return this->schedules_;};
    void buildSchedules() override;
    SlowScheduleBuilder(std::vector<Course> courses) : courses_(courses) {};


private:
    std::vector<Course> courses_; // courses to choose from when scheduling
    std::vector<Schedule> schedules_;
};


#endif //FINAL_PROJECT_SLOWSCHEDULEBUILDER_H
