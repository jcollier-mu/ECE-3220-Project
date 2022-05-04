//
// Created by James Collier on 5/4/22.
//
#include <gtest/gtest.h>
#include "FactoryTest.h"

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

