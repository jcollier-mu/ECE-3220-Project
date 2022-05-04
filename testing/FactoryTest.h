//
// Created by James Collier on 5/4/22.
//

#ifndef FINAL_PROJECT_FACTORYTEST_H
#define FINAL_PROJECT_FACTORYTEST_H
#include <gtest/gtest.h>
#include "../CourseFactory.h"

// for testing file read/course creation
class FactoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        for(int i=0; i<4; i++){
            courses.push_back(factory.createCourse(files[i]));
        }
    }

    // void TearDown() override {}

    CourseFactory factory;
    std::vector<std::shared_ptr<Course>> courses;
    std::string files[4] = {"../../json_files/test0.json", "../../json_files/test1.json", "../../json_files/test2.json",
                            "../../json_files/test4.json"};

};
#endif //FINAL_PROJECT_FACTORYTEST_H
