//
// Created by James Collier on 4/17/22.
//

#ifndef FINAL_PROJECT_COURSEFACTORY_H
#define FINAL_PROJECT_COURSEFACTORY_H
#include <nlohmann/json.hpp>
#include <string>
#include "Course.h"

using json = nlohmann::json;
class CourseFactory {
public:
    Course* createCourse(json j);
    Course* createCourse(std::string filePath);
    void removeCourse(Course* c);
};


#endif //FINAL_PROJECT_COURSEFACTORY_H
