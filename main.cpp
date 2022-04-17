//
// Created by James Collier on 4/6/22.
//
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "CourseFactory.h"
#include "Course.h"

using json = nlohmann::json;

int main()
{
    CourseFactory factory;
    std::string file = "../test.json";
    Course* c = factory.createCourse(file);
    c->printCourse();

    return 0;
}
