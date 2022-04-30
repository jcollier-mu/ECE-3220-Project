//
// Created by James Collier on 4/29/22.
//

#include "AssignmentScheduleBuilder.h"
#include <iostream>

void AssignmentScheduleBuilder::buildSchedules() {
    this->buildGraph();
}

void AssignmentScheduleBuilder::buildGraph() {
    // The idea is to have keys that are distinct time intervals
    // Values are courses that fall within that time interval
    // This way, we can hopefully get a better idea of how courses conflict with one another
    for(auto course=courses_.begin(); course < courses_.end(); course++){
        graph_.insert(std::pair<Interval, Course>(course->getMeetingTimes(), *course));
    }
}

void AssignmentScheduleBuilder::printGraph() {
    for(auto it = graph_.begin(); it != graph_.end(); it++){
        it->first.printInterval();
        std::pair<std::multimap<Interval, Course>::iterator, std::multimap<Interval, Course>::iterator> result = graph_.equal_range(it->first);
        for(auto j = result.first; j != result.second; j++){
            std::cout << j->second.getName() << std::endl;
        }
        std::cout << "\n\n";
    }
}