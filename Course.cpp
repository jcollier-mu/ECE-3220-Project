//
// Created by James Collier on 4/6/22.
//

#include "Course.h"
#include "iostream"

Course::Course(std::string CName, int CNum, std::string description, Interval i, unsigned short int priority) :
CName_(CName), CNum_(CNum), description_(description), i_(i), priority_(priority) {}

void Interval::printInterval() {
    std::string s;
    for(auto i = whichDays.begin(); i < whichDays.end(); i++){
        s += std::to_string(*i) + " ";
    }
    std::cout << "Time: (" << start_hm.first << ":" << start_hm.second << ", "
    << end_hm.first << ":" << end_hm.second << ") " << s << std::endl;
}

void Course::printCourse() {
    std::cout << "Name: " << CName_ << std::endl;
    std::cout << "Number: " << CNum_ << std::endl;
    std::cout << "Description: " << description_ << std::endl;
    std::cout << "Priority: " << priority_ << std::endl;
    i_.printInterval();
}

// Two intervals are compatible if they don't fall on the same days or there is no overlap between them on the same days
bool Interval::isCompatible(Interval i2) {
    // assuming start_hm <= end_hm for both intervals
    for(auto j = this->whichDays.begin(); j < this->whichDays.end(); j++) {
        for(auto s = i2.whichDays.begin(); s < i2.whichDays.end(); s++) {
            if(*j == *s) {
                if ((this->start_hm <= i2.end_hm) && (this->end_hm >= i2.start_hm)) return false;
                else return true; // if they're compatible on one day they're compatible on all of them (in this program, at least)
            }
        }
    }

    return true;
}