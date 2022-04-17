//
// Created by James Collier on 4/6/22.
//

#include "Course.h"
#include "iostream"

Course::Course(std::string CName, int CNum, std::string description, Interval i) :
CName_(CName), CNum_(CNum), description_(description), i_(i) {}

void Interval::printInterval() {
    std::string s;
    for(auto i = whichDays.begin(); i < whichDays.end(); i++){
        s += std::to_string(*i) + " ";
    }
    std::cout << "Time: (" << start << ", " << end << ") " << s << std::endl;
}

void Course::printCourse() {
    std::cout << "Name: " << CName_ << std::endl;
    std::cout << "Number: " << CNum_ << std::endl;
    std::cout << "Description: " << description_ << std::endl;
    i_.printInterval();
}