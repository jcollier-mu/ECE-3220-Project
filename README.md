# Schedule Planner
Final Project for Software Development in C++ at University of Missouri-Columbia.

Many Mizzou students are familiar with Schedule Planner, a tool that lets them see class schedules, compare different schedules, and even place conditions on their schedule (like no class on Friday). This is something similar! This project is a command-line interface. Users will input their schedules into the program, which will then output possible schedules.  Some options are included in the program as well, such as scheduling time constraints. 

***List of Features/Functionalities:***
- Users will input courses as .json files that will be parsed by the program. 
  - Includes course name, number, description, and section times.
- The program will output possible schedules to .txt files along with detailed error messages to the console where applicable.
  - Where errors occur, program usage should be displayed as well.
- Options for course scheduling will be provided on the command line as flags.
  - Options include time constraints/breaks (e.g., no schedules with class before 10am or after 3pm, lunch breaks, etc.)
  - Day constraints (e.g., no class on Friday)
  - Output file options
  - Input file specifications
  - Print program usage


## Building this Program

There is a Docker repository for this project! It can be found [here](https://hub.docker.com/repository/docker/jcollier01/schedule-planner/general).

- Pull the latest tag and run it via ```docker run -it jcollier01/schedule-planner:latest``` to see an example of this program in action! Use the ```-it``` option to run the docker image application with whatever options you'd like. The json_files included in the docker image are those in json_files/

Otherwise, clone the repo from [https://github.com/jcollier-mu/ECE-3220-Project] and run ```cmake -S . -B build``` and ```cmake --build build```  to generate the ```main``` executable file in the build directory.
This project uses GoogleTest and nlohmann/json libraries. However, due to cmake's ```FetchContent``` module, there shouldn't be any need to worry about installing these libraries.

## Design Patterns and Program Implementation

Schedule Planner takes advantage of several design patterns learned in class to read in Courses, build Schedules, output error messages to users, and more.

- The factory method design pattern is used to create Course objects while reading them from .json files.
- The builder design pattern is used to build Schedules.
  - The SchedulePlanner class decides which concrete builder class (SlowScheduleBuilder or ConstraintScheduleBuilder) to use to create schedules. 
  - The concrete builders build the schedules that are then accessed by the SchedulePlanner with methods for printing them, writing them to files, etc.
  - The strengths of this design pattern are how easy it is to incorporate new kinds of builder classes into the program.
- The singleton design method is used to keep track of error logs and is in charge of all messages displayed to the user.