//
// Created by James Collier on 4/6/22.
//
#include <nlohmann/json.hpp>
#include <iostream>
#include <iomanip>

using json = nlohmann::json;

int main()
{

    std::cout << std::setw(4) << json::meta() << std::endl;


    return 0;
}
