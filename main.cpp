//
// Created by James Collier on 4/6/22.
//
#include "CourseFactory.h"
#include "SchedulePlanner.h"
#include "MessageHandler.h"
#include <unistd.h>

int main(int argc, char* argv[])
{
    opterr =  0;
    int c;
    MessageHandler* msg = MessageHandler::getInstance();

    while((c = getopt(argc, argv, "b:d:o:i:h")) != -1) { // read and parse command-line options
        switch (c) {
            case 'i':
                // Read files, create courses vector
            case 'h':
                msg->printUsage();
                break;
            case 'b':
                // parse command-line interval here and push back to an interval vector
                break;
            case 'o':
                // Specify output filename, default is output.txt
                break;
            case 'd':
                // parse command-line interval and push back to an interval vector
            case '?':
                msg->printMessage("Make sure valid options are passed with the correct arguments!\n");
                msg->printUsage();
                break;
            default:
                msg->printMessage("Default switch used, reevaluate the switch-case in main"); // this shouldn't happen, theoretically
                return 1;
        }
    }

    // after all options are read, create the builder, build the schedules, and write the schedules to file



    return 0;
}
