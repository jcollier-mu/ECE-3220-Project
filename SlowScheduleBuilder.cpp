//
// Created by James Collier on 4/22/22.
//

#include "SlowScheduleBuilder.h"
#include <numeric>
#include <algorithm>
#include <random>

void SlowScheduleBuilder::buildSchedules() {
    // idea: iterate through many possible schedules
    // first, make every course its own schedule
    for(auto i=courses_.begin(); i < courses_.end(); i++){
        Schedule* s = new Schedule(*i);
        schedules_.push_back(*s);
        delete s;
    }
    // then, slowly build up each one course schedule
    // this is not an optimal algorithm, i.e., it doesn't find all possible schedules
    // but I hope it gives the user a good selection of compatible, maximal schedules
    bool flag=true;
    std::vector<int> status(schedules_.size(), 0);
    std::default_random_engine rng;
    while(flag) {
        int index=0;
        for (auto k = schedules_.begin(); k < schedules_.end(); k++) {
            // shuffle courses_ vector to hopefully better explore schedule space
            // iterating through courses in the same order could lead to some courses being more prevalent than others
            std::shuffle(std::begin(courses_), std::end(courses_), rng);
            if(status[index]==1) continue;
            int initialSize = (int) k->size();
            for (auto j = courses_.begin(); j < courses_.end(); j++) {
                if (k->isCompatibleWithSchedule(j->getMeetingTimes())) {
                    k->addCourse(*j);
                }
            }
            if(initialSize == (int) k->size()) status[index] = 1; //change status[index] if schedule k is unchanged
            index++;
        }
        if(std::accumulate(status.begin(), status.end(), 0) == (int)schedules_.size()) flag=false; //end loop if all schedules remain unchanged
    }
}