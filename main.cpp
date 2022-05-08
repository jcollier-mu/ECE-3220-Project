//
// Created by James Collier on 4/6/22.
//
#include "CourseFactory.h"
#include "SchedulePlanner.h"
#include "MessageHandler.h"
#include <unistd.h>

std::vector<std::string> splitBy(std::string text, std::string delimiter);
Interval parseInterval(std::string interval_string);

int main(int argc, char* argv[])
{
    opterr =  0;
    int c;
    MessageHandler* msg = MessageHandler::getInstance();

    std::vector<std::string> input_files;
    std::string file_prefix = "../json_files/";
    for(int i = 0; i < 11; i++){ // by default, use all the files in json_files/
        input_files.push_back(file_prefix + "test" + std::to_string(i) + ".json");
    }
    std::vector<Course> courses;
    CourseFactory factory;
    for(auto j : input_files){
        courses.push_back(*factory.createCourse(j));
    }

    std::string output_file = "output.txt";

    std::vector<Interval> blocks;
    std::vector<std::string> interval_strs;
    std::string all_day = "0:00-23:59";

    while((c = getopt(argc, argv, "b:d:o:i:h")) != -1) { // read and parse command-line options
        switch (c) {
            case 'i':
                input_files.clear(); courses.clear();
                // Read files, push to courses vector
                input_files = splitBy(optarg, " ");
                for(auto j : input_files){
                    try{courses.push_back(*factory.createCourse(j));}
                    catch(std::runtime_error &r){
                        msg->printMessage(r.what());
                        msg->addError(r.what() + "in -i [filename]"); // will throw an exception if a file cannot be opened, for instance
                    }
                }
                break;
            case 'h':
                msg->printUsage();
                break;
            case 'b':
                // e.g., "12:15-13:45 0,1,2,3,4;16:00-18:00 0,2,4"
                interval_strs.clear();
                interval_strs = splitBy(optarg, ";");
                for(auto w : interval_strs){
                    blocks.push_back(parseInterval(w));
                }
                break;
            case 'o':
                output_file = optarg;
                break;
            case 'd':
                // parse command-line interval and push back to an interval vector
                // e.g., "1,2,3"
                blocks.push_back(parseInterval(all_day + " " + optarg));
                break;
            case '?':
                msg->printMessage("Make sure valid options are passed with the correct arguments!\n");
                msg->printUsage();
                msg->addError("Unrecognized option");
                break;
            default:
                msg->printMessage("Default switch used, reevaluate the switch-case in main"); // this shouldn't happen, theoretically
                msg->addError("Default switch used");
                return 1;
        }
    }

    // after all options are read, create the builder, build the schedules, and write the schedules to file
    // it would be super easy to expand this program with more options/builders by just changing a few lines of code in main
    SchedulePlanner* director = new SchedulePlanner(new ConstraintScheduleBuilder(courses, blocks));
    director->constructSchedules();
    director->writeSchedulesToFile(output_file);
    msg->printErrorLog(); // summarize program errors
    delete director;
    delete msg;

    return 0;
}

std::vector<std::string> splitBy(std::string text, std::string delimiter){
    std::vector<std::string> words;
    std::string::size_type pos;
    while((pos = text.find(delimiter)) != std::string::npos){
        words.push_back(text.substr(0,pos));
        text.erase(0, pos + delimiter.length());
    }
    words.push_back(text);
    return words;
}

//e.g., "12:15-13:45 0,1,2,3,4"
Interval parseInterval(std::string interval_string) {
    Interval i;
    MessageHandler* msg = MessageHandler::getInstance();
    try {
        std::vector <std::string> timesAndDays = splitBy(interval_string, " ");
        // use std::vector::at() member function because the [] operator has undefined behavior if accessing memory that isn't there, but at() throws std::out_of_range.
        std::vector <std::string> times_hm = splitBy(timesAndDays.at(0), "-");
        std::vector <std::string> days_str = splitBy(timesAndDays.at(1), ",");
        std::vector <DaysOfWeek::days> days;
        for (auto i: days_str) {
            days.push_back((DaysOfWeek::days) std::stoi(i)); // std::stoi may throw std::invalid_argument if the option is incorrectly formatted
        }
        std::vector <std::string> start_hm_str = splitBy(times_hm.at(0), ":");
        std::vector <std::string> end_hm_str = splitBy(times_hm.at(1), ":");

        i.start_hm = std::make_pair(std::stoi(start_hm_str.at(0)), std::stoi(start_hm_str.at(1)));
        i.end_hm = std::make_pair(std::stoi(end_hm_str.at(0)), std::stoi(end_hm_str.at(1)));
        i.whichDays = days;
    }catch(std::invalid_argument &e){
        msg->printMessage("Please ensure arguments are correctly formatted!");
        msg->printUsage();
        msg->addError(e.what());
    }catch(std::out_of_range &e){
        msg->printMessage("Please ensure arguments are correctly formatted!");
        msg->printUsage();
        msg->addError(e.what());
    }
    catch(...){
        msg->printMessage("Please ensure arguments are correctly formatted!");
        msg->printUsage();
        msg->addError("Exception in parseInterval()");
    }
    return i;

}