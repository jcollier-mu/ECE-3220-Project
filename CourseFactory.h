//
// Created by James Collier on 4/17/22.
//

#ifndef FINAL_PROJECT_COURSEFACTORY_H
#define FINAL_PROJECT_COURSEFACTORY_H
#include <nlohmann/json.hpp>
#include <string>
#include <memory>
#include "Course.h"

using json = nlohmann::json;
class CourseFactory {
public:
    std::shared_ptr<Course> createCourse(json j); // return std::shared_ptr to avoid memory headaches
    std::shared_ptr<Course> createCourse(std::string filePath);
};


#endif //FINAL_PROJECT_COURSEFACTORY_H
