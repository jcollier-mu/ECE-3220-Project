//
// Created by James Collier on 4/6/22.
//

#ifndef FINAL_PROJECT_COURSE_H
#define FINAL_PROJECT_COURSE_H
#include <string>
#include <ctime>
using namespace std;

class Course {
private:
    int id;
    string name;
    string description;
    tm start;
    tm stop;
    char day;
public:
    Course* readFile(string path);
    Course* writeFile(string path = "output.txt");
};


#endif //FINAL_PROJECT_COURSE_H
