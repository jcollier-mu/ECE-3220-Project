cmake_minimum_required(VERSION 3.2)
project(Final_Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES Course.cpp Course.h CourseFactory.cpp CourseFactory.h
        main.cpp Schedule.cpp Schedule.h ScheduleBuilder.h SchedulePlanner.cpp
        SchedulePlanner.h SlowScheduleBuilder.cpp SlowScheduleBuilder.h)
add_executable(main ${SOURCES})
