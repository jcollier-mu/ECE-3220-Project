//
// Created by James Collier on 4/29/22.
//

#include "AssignmentScheduleBuilder.h"
#include <iostream>

void AssignmentScheduleBuilder::buildSchedules() {
    this->buildGraph();
}

// returns adjacency list (sort of), where for each nonconflicting time slot there's courses to choose from
void AssignmentScheduleBuilder::buildGraph() {
    for(auto course=courses_.begin(); course < courses_.end(); course++){
        graph_.insert({course->getMeetingTimes(), *course});
    }
}

void AssignmentScheduleBuilder::printGraph() {

    for(auto it : graph_){
        it.first.printInterval();
        std::pair<std::multimap<Interval, Course>::iterator, std::multimap<Interval, Course>::iterator> result = graph_.equal_range(it.first);
        for(auto it = result.first; it != result.second; it++){
            std::cout << it->second.getName() << std::endl;
        }
        std::cout << "\n\n";
    }
}