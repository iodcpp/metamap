cmake_minimum_required(VERSION 2.8)

project(iod_symbol)

add_definitions(-std=c++1z)

enable_testing()

add_executable(make tests/make.cc)
add_test(make make)

add_executable(cat tests/cat.cc)
add_test(cat cat)

add_executable(intersection tests/intersection.cc)
add_test(intersection intersection)

add_executable(substract tests/substract.cc)
add_test(substract substract)
