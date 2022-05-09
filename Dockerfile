FROM gcc:latest
COPY . /usr/src/final-project/
WORKDIR /usr/src/final-project/
RUN apt-get update
RUN apt-get install -y cmake
RUN apt-get install -y valgrind # i can finally run memcheck on mac (kinda)!
RUN rm -rf build # remove cached cmake data
RUN rm -rf testing/build
RUN cmake -S . -B build
RUN cmake --build build

WORKDIR build/
