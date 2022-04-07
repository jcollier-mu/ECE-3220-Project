//
// Created by James Collier on 4/6/22.
//
#include <iostream>
#include <iomanip>
#include <chrono>
#include <sstream>
using namespace std;

int main()
{
    std::tm tm = {};
    std::stringstream ss;
    ss << "12:35:34";
    ss >> std::get_time(&tm, "%H:%M:%S");
    cout << put_time(&tm, "%H:%M") << endl;
    return 0;
}
