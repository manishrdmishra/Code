cmake_minimum_required(VERSION 3.10)
project(Algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")

include_directories(include)
include_directories(/usr/local/boost_1_63_0)
include_directories(/usr/local/include/glog)
set(SOURCE_FILES test/main.cpp src/CountInversions.cpp 
                include/QuickSortCountComparisons.h
                include/MinimumSpanningTree.h
                test/mst_test.cpp
                src/CountInversionsTest.cpp 
                test/GraphTest.cpp)
#set(SOURCE_FILES main.cpp  src/cluster_max_spacing_test.cpp)
#set(SOURCE_FILES main.cpp helper_functions.h greedy_algorithms_test.cpp greedy_algorithms.cpp greedy_algorithms.h)
add_executable(Algorithms ${SOURCE_FILES})
target_link_libraries(Algorithms /usr/local/lib/libgtest.a )
target_link_libraries(Algorithms /usr/local/lib/libgtest_main.a  pthread)
target_link_libraries(Algorithms /usr/local/lib/libglog.a)
