cmake_minimum_required(VERSION 3.6)
project(Algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")


#set(SOURCE_FILES main.cpp CountInversions.cpp CountInversions.h CountInversionsTest.cpp QuickSortCountComparisons.h QuickSortCountComparisonsTest.cpp Graph.h helper_functions.h GraphTest.cpp)
set(SOURCE_FILES main.cpp helper_functions.h SccTest.cpp maintain_median.h)
add_executable(Algorithms ${SOURCE_FILES})
target_link_libraries(Algorithms /usr/local/lib/libgtest.a )
target_link_libraries(Algorithms /usr/local/lib/libgtest_main.a  pthread)
