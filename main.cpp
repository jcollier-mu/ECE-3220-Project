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
    std::vector<std::shared_ptr<Course>> coursesPtr;
    std::vector<Course> courses;
    for(int i = 0; i < 11; i++){
        files.push_back(filePrefix + "test" + std::to_string(i) + ".json");
    }
    for(auto c = files.begin(); c < files.end(); c++){
        try{
            coursesPtr.push_back(factory.createCourse(*c)); // we'll let smart pointers worry about memory
        }
        catch(...){std::cout << "Error in reading file " << *c << std::endl;}
    }
    for(auto k=coursesPtr.begin();k<coursesPtr.end();k++){courses.push_back(*(*k));}
    SchedulePlanner *director = new SchedulePlanner(new SlowScheduleBuilder(courses));
    director->constructSchedules();
    director->writeSchedulesToFile("test.txt");

    delete director;
    return 0;
}
