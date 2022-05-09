//
// Created by James Collier on 5/8/22.
//

#ifndef FINAL_PROJECT_BUILDERTEST_H
#define FINAL_PROJECT_BUILDERTEST_H
#include "../CourseFactory.h"
#include "../SchedulePlanner.h"
#include <stdlib.h>

// for testing the builders (Constraint and Slow)
class BuilderTest : public ::testing::Test {
protected:
    void SetUp() override {
        for(int i = 0; i < 11; i++){
            files.push_back(filePrefix + "test" + std::to_string(i) + ".json");
        }
        for(auto j : files){
            courses.push_back(*factory.createCourse(j));
        }
    }

     void TearDown() override {delete director;}

    std::vector<Course> courses;
    std::string filePrefix = "../../json_files/";
    std::vector<std::string> files;
    CourseFactory factory;
    SchedulePlanner* director;
};
#endif //FINAL_PROJECT_BUILDERTEST_H
