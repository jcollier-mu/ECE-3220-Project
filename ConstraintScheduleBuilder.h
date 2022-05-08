//
// Created by James Collier on 5/8/22.
//

#ifndef FINAL_PROJECT_CONSTRAINTSCHEDULEBUILDER_H
#define FINAL_PROJECT_CONSTRAINTSCHEDULEBUILDER_H
#include "ScheduleBuilder.h"
#include "SlowScheduleBuilder.h"

// This builder builds schedules around time constraints (e.g., no class on Friday, lunch breaks)
class ConstraintScheduleBuilder : public ScheduleBuilder{
public:
    std::vector<Schedule> getSchedules() const override{return this->schedules_;};
    void buildSchedules() override;
    ConstraintScheduleBuilder(std::vector<Course> courses, Interval block) : courses_(courses), block_(block) {}
private:
    std::vector<Course> courses_;
    Interval block_;
    std::vector<Schedule> schedules_;

};


#endif //FINAL_PROJECT_CONSTRAINTSCHEDULEBUILDER_H
