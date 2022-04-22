//
// Created by James Collier on 4/22/22.
//

#include "SlowScheduleBuilder.h"

void SlowScheduleBuilder::buildSchedules() {
    // idea: iterate through many possible schedules
    // first, make every course its own schedule
    for(auto i=courses_.begin(); i < courses_.end(); i++){
        Schedule* s = new Schedule(*i);
        schedules_.push_back(*s);
        delete s;
    }
    // then, slowly build up each one course schedule
    bool flag=true;
    int count=0;
    while(flag) {
        for (auto k = schedules_.begin(); k < schedules_.end(); k++) {
            int initialSize = (int) k->size();
            for (auto j = courses_.begin(); j < courses_.end(); j++) {
                if (k->isCompatibleWithSchedule(*j)) {
                    k->addCourse(*j);
                }
            }
            if(initialSize == (int) k->size()) count++; //increment count if schedule k is unchanged
        }
        if(count == (int)schedules_.size()) flag=false; //end loop if all schedules remain unchanged
    }
}