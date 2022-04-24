//
// Created by James Collier on 4/6/22.
//
#include "CourseFactory.h"
#include "SchedulePlanner.h"
#include <iostream>

int main()
{
    CourseFactory factory;
    std::string filePrefix = "../json_files/";
    std::vector<std::string> files;
    std::vector<Course> courses;
    for(int i = 0; i < 11; i++){
        files.push_back(filePrefix + "test" + std::to_string(i) + ".json");
    }
    for(auto c = files.begin(); c < files.end(); c++){
        try{courses.push_back(*factory.createCourse(*c));}
        catch(...){std::cout << "Error in reading file " << *c << std::endl;}
    }
    SchedulePlanner *director = new SchedulePlanner(new SlowScheduleBuilder(courses));
    director->constructSchedules();
    director->writeSchedulesToFile("test.txt");

    delete director;
    return 0;
}
