cmake_minimum_required(VERSION 3.14)
project(project-testing)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

set(SOURCES run_tests.cpp ../Course.cpp ../Course.h ../CourseFactory.cpp ../CourseFactory.h
        ../Schedule.cpp ../Schedule.h ../ScheduleBuilder.h ../SchedulePlanner.cpp
        ../SchedulePlanner.h ../SlowScheduleBuilder.cpp ../SlowScheduleBuilder.h
        ../ConstraintScheduleBuilder.cpp ../ConstraintScheduleBuilder.h FactoryTest.h
        ../MessageHandler.h ../MessageHandler.cpp)
add_executable(
        run_tests
        ${SOURCES}
)
target_link_libraries(
        run_tests
        gtest_main
)

include(GoogleTest)
gtest_discover_tests(run_tests)