cmake_minimum_required(VERSION 3.2)
project(Final_Project)

set(CMAKE_CXX_STANDARD 11)
set(JSON_BuildTests OFF)

include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.10.5/json.tar.xz)
FetchContent_MakeAvailable(json)

set(SOURCES Course.cpp Course.h CourseFactory.cpp CourseFactory.h
        main.cpp Schedule.cpp Schedule.h ScheduleBuilder.h SchedulePlanner.cpp
        SchedulePlanner.h SlowScheduleBuilder.cpp SlowScheduleBuilder.h
        MessageHandler.cpp MessageHandler.h ConstraintScheduleBuilder.cpp
        ConstraintScheduleBuilder.h)
add_executable(main ${SOURCES})
target_link_libraries(main PRIVATE nlohmann_json::nlohmann_json)
