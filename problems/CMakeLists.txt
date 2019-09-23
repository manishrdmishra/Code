cmake_minimum_required(VERSION 3.6)
project(problems)

set(CMAKE_CXX_STANDARD 17)

#set(SOURCE_FILES main.cpp LRUcache.h)
set(LONGEST_SUBSTR functions.h functions_test.cpp)
add_executable(functions_test ${LONGEST_SUBSTR})
target_link_libraries(functions_test /usr/lib/libgtest.a /usr/lib/libgtest_main.a pthread)