//
// Created by James Collier on 4/6/22.
//
#include "CourseFactory.h"

int main()
{
    CourseFactory factory;
    std::string file = "../test.json";
    Course* c = factory.createCourse(file);
    c->printCourse();

    factory.removeCourse(c);
    return 0;
}
