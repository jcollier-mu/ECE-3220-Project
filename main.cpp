//
// Created by James Collier on 4/6/22.
//
#include "CourseFactory.h"
#include <iostream>

int main()
{
    CourseFactory factory;
    std::string file = "../json_files/test0.json";
    Course* c = factory.createCourse(file);
    c->printCourse();

    factory.removeCourse(c);

    return 0;
}
