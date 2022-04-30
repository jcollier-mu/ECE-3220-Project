//
// Created by James Collier on 4/29/22.
//

#ifndef FINAL_PROJECT_ASSIGNMENTSCHEDULEBUILDER_H
#define FINAL_PROJECT_ASSIGNMENTSCHEDULEBUILDER_H
#include "ScheduleBuilder.h"

// Treat this as an assignment problem, see https://en.wikipedia.org/wiki/Assignment_problem
// Try to find a maximum cardinality/maximum priority matching between hours in days of the week and potential classes
class AssignmentScheduleBuilder : public ScheduleBuilder{
public:
    std::vector<Schedule> getSchedules() const override{return this->schedules_;};
    void buildSchedules() override;
    AssignmentScheduleBuilder(std::vector<Course> courses) : courses_(courses) {};
private:
    std::vector<Course> courses_; // courses to choose from when scheduling
    std::vector<Schedule> schedules_;
};


#endif //FINAL_PROJECT_ASSIGNMENTSCHEDULEBUILDER_H
