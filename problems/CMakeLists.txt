cmake_minimum_required(VERSION 3.6)
project(problems)

set(CMAKE_CXX_STANDARD 17)

#set(SOURCE_FILES main.cpp LRUcache.h)
set(LONGEST_SUBSTR longest_substring.h longest_substring.cpp)
add_executable(longest_substr ${LONGEST_SUBSTR})
target_link_libraries(longest_substr /usr/lib/libgtest.a /usr/lib/libgtest_main.a pthread)