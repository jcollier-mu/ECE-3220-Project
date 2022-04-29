//
// Created by James Collier on 4/29/22.
//

#ifndef FINAL_PROJECT_ASSIGNMENTSCHEDULEBUILDER_H
#define FINAL_PROJECT_ASSIGNMENTSCHEDULEBUILDER_H
#include "ScheduleBuilder.h"
#include <map>

// Treat class scheduling as an assignment problem, see https://en.wikipedia.org/wiki/Assignment_problem#Algorithms
// In particular, try to find a maximum cardinality/maximum priority matching between hours in days of the week and potential classes
//
/* e.g.,
 * 8am-8:50am MWF ---------------------> Class1(priority 3) <-- pick this
 * 8am-8:50am TTh ---------------------> Class2(priority 2) <-- pick this
 * 12:30-1:145pm TTh-------------------> Class3(priority 1) x not this one
 *                 '-------------------> Class4(priority 4) <-- pick this one
 * 4-5:15pm MW ------------------------> Class5(priority 1) x not this one
 * 5-6:50 M ---------------------------> Class6(priority 2) <-- pick this (not sure how to handle distinct intervals that conflict, probably want to merge them to one graph node)
 */
class AssignmentScheduleBuilder : public ScheduleBuilder{
public:
    std::vector<Schedule> getSchedules() const override{return this->schedules_;};
    void buildSchedules() override;
    AssignmentScheduleBuilder(std::vector<Course> courses) : courses_(courses) {};
private:
    std::map<Interval, std::vector<Course>> graph_; // adjacency list (sort of), where for each nonconflicting time slot there's a vector of courses to choose from
    std::map<Interval, std::vector<Course>> buildGraph();
    std::vector<Course> courses_; // courses to choose from when scheduling
    std::vector<Schedule> schedules_;
};


#endif //FINAL_PROJECT_ASSIGNMENTSCHEDULEBUILDER_H
