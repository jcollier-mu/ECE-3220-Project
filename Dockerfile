FROM gcc:latest
COPY . /usr/src/final-project/
WORKDIR /usr/src/final-project/
RUN apt-get update
RUN apt-get install -y cmake
RUN rm -rf build
RUN rm -rf testing/build
RUN cmake -S . -B build
RUN cmake --build build

WORKDIR build/

CMD [ "./main" ]