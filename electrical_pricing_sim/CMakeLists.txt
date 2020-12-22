cmake_minimum_required(VERSION 3.16)
project(electrical_pricing_sim)

set(CMAKE_CXX_STANDARD 14)

add_executable(electrical_pricing_sim main.cpp Simulation.cpp Simulation.h Reading.cpp Reading.h Customer.cpp Customer.h TOUCustomer.cpp TOUCustomer.h TIERCustomer.cpp TIERCustomer.h)
