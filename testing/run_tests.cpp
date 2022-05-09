//
// Created by James Collier on 5/4/22.
//
#include <gtest/gtest.h>
#include "FactoryTest.h"
#include "BuilderTest.h"

TEST_F(FactoryTest, coursesAreReadCorrectly){
    EXPECT_EQ((int)4320, courses[0]->getNum());
    EXPECT_EQ((int)3220, courses[1]->getNum());
    EXPECT_EQ((int)4640, courses[2]->getNum());
}

TEST_F(FactoryTest, intervalArithmetic){
    EXPECT_TRUE(courses[1]->getMeetingTimes().isCompatible(courses[2]->getMeetingTimes()));
    EXPECT_TRUE(courses[0]->getMeetingTimes().isCompatible(courses[2]->getMeetingTimes()));
    EXPECT_TRUE(courses[2]->getMeetingTimes() < courses[1]->getMeetingTimes());
    EXPECT_FALSE(courses[3]->getMeetingTimes().isCompatible(courses[1]->getMeetingTimes()));
}

TEST_F(BuilderTest, SlowBuilderTest){
    director = new SchedulePlanner(new SlowScheduleBuilder(courses));
    director->constructSchedules();
    for(auto i : director->getSchedules()){
        // assert the Planner only builds valid schedules
        ASSERT_TRUE(i.isValidSchedule());
    }
}

TEST_F(BuilderTest, ConstraintBuilderTest){
    Interval lunchBreak; Interval friday;
    lunchBreak.start_hm = std::make_pair((unsigned short)12,(unsigned short)0);
    lunchBreak.end_hm = std::make_pair((unsigned short)13, (unsigned short)45);
    lunchBreak.whichDays.push_back(DaysOfWeek::days::M);
    lunchBreak.whichDays.push_back(DaysOfWeek::days::Tu);
    lunchBreak.whichDays.push_back(DaysOfWeek::days::W);
    lunchBreak.whichDays.push_back(DaysOfWeek::days::Th);
    lunchBreak.whichDays.push_back(DaysOfWeek::days::F);
    friday.start_hm = std::make_pair((unsigned short)0,(unsigned short)0);
    friday.end_hm = std::make_pair((unsigned short)23, (unsigned short)59);
    friday.whichDays.push_back(DaysOfWeek::days::F);
    std::vector<Interval> block; block.push_back(lunchBreak); block.push_back(friday);
    director = new SchedulePlanner(new ConstraintScheduleBuilder(courses, block));
    director->constructSchedules();
    for(auto i : director->getSchedules()){
        // assert that there is no class during the breaks
        EXPECT_TRUE(i.isCompatibleWithSchedule(lunchBreak));
        EXPECT_TRUE(i.isCompatibleWithSchedule(friday));
    }
}
