# Schedule Planner
Final Project for Software Development in C++ at University of Missouri-Columbia.

Many Mizzou students are familiar with Schedule Planner, a tool that lets them see class schedules, compare different schedules, and even place conditions on their schedule (like no class on Friday). This is something similar! This project is a command-line interface. Users will input their schedules into the program, which will then output possible schedules.  Some options are included in the program as well, such as scheduling time constraints. 

***List of Features/Functionalities:***
- Users will input courses as .json files that will be parsed by the program. 
  - Includes course name, number, description, section times, and priority, if applicable.
- The program will output possible schedules to .txt files along with detailed error messages to the console where applicable.
  - Where errors occur, program usage should be displayed as well.
- Options for course scheduling will be provided on the command line as flags.
  - Options include time constraints/breaks (e.g., no schedules with class before 10am or after 3pm, lunch breaks, etc.)
  - Day constraints (e.g., no class on Friday)


## Building this Program

There is a Docker repository for this project! It can be found [here](https://hub.docker.com/repository/docker/jcollier01/schedule-planner/general).

- Pull the latest tag and run it via ```docker run jcollier01/schedule-planner:latest``` to see an example of this program in action!

Otherwise, clone the repo from [https://github.com/jcollier-mu/ECE-3220-Project] and run ```cmake -S . -B build``` and ```cmake --build build```  to generate the executable file in the build directory.
This project uses GoogleTest and nlohmann/json libraries. However, due to cmake's ```FetchContent``` module, there shouldn't be any need to worry about installing these libraries.