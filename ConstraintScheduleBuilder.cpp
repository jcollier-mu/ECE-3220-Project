//
// Created by James Collier on 5/8/22.
//

#include "ConstraintScheduleBuilder.h"

void ConstraintScheduleBuilder::buildSchedules() {
    // idea: just remove courses that are incompatible with the block and use SlowScheduleBuilder
    for(auto course = courses_.begin(); course < courses_.end(); ){
        if(course->getMeetingTimes().isCompatible(block_)){
            course++;
        }else{
            course = courses_.erase(course);
        }
    }

    auto builder = new SlowScheduleBuilder(courses_);
    builder->buildSchedules();
    this->schedules_ = builder->getSchedules();
    delete builder;
}