cmake_minimum_required(VERSION 3.10)
project(problems)

set(CMAKE_CXX_STANDARD 17)

#set(SOURCE_FILES main.cpp LRUcache.h)
set(SOURCES functions.h linked_list.h linked_list.cpp linked_list_tests.cpp functions_test.cpp)
set(SOURCES heap.h heap.cpp heap_test.cpp)
add_executable(functions_test ${SOURCES})
target_link_libraries(functions_test /usr/lib/libgtest.a /usr/lib/libgtest_main.a pthread)