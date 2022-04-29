//
// Created by James Collier on 4/6/22.
//

#ifndef FINAL_PROJECT_COURSE_H
#define FINAL_PROJECT_COURSE_H
#include <string>
#include <vector>
#include <chrono>
using namespace std;

struct DaysOfWeek{
    enum days {M, Tu, W, Th, F};
};

// for representing class meeting times
// for now, the program will only consider classes that meet at the same times every day
// e.g., no classes with lecture at 4 on Monday and at 11 on Thursday
struct Interval{
    std::pair<unsigned short int, unsigned short int> start_hm; // 0-24 and 0-60, which hour and minute class starts
    std::pair<unsigned short int, unsigned short int> end_hm; // 0-24 and 0-60, which hour and minute class ends
    std::vector<enum DaysOfWeek::days> whichDays;
    void printInterval();
    bool isCompatible(const Interval& i2) const;

    // to use as key in a 'std::map' for AssignmentScheduleBuilder
    bool operator<(const Interval& i2) const{
        return this->isCompatible(i2);
    }
};

class Course {
private:
    std::string CName_;
    int CNum_;
    std::string description_;
    Interval i_;
    unsigned short int priority_; //1-5, if supplied allows users to build schedules based on what's most important
    //if all course priorities=1, we just find a maximal set of compatible intervals
public:
    Course(std::string CName, int CNum, std::string description, Interval i, unsigned short int priority=1);
    std::string getName() const {return this->CName_;};
    int getNum() const {return this->CNum_;};
    void printCourse();
    Interval getMeetingTimes() const{return this->i_;};
};


#endif //FINAL_PROJECT_COURSE_H
