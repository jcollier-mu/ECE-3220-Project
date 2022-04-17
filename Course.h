//
// Created by James Collier on 4/6/22.
//

#ifndef FINAL_PROJECT_COURSE_H
#define FINAL_PROJECT_COURSE_H
#include <string>
#include <vector>
#include <nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

struct DaysOfWeek{
    enum days {M, Tu, W, Th, F};
};

// for representing class meeting times
// for now, the program will only consider classes that meet at the same times every day
// e.g., no classes with lecture at 4 on Monday and at 11 on Thursday
struct Interval{
    int start; // 0-24, which hour class starts
    int end; // 0-24, which hour class ends
    std::vector<enum DaysOfWeek::days> whichDays;
};

class Course {
private:
    std::string CName_;
    int CNum_;
    std::string description_;
    Interval i_;
public:
    Course(std::string CName, int CNum, std::string description, Interval i);
};


#endif //FINAL_PROJECT_COURSE_H
