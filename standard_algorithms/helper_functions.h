//
// Created by manish on 21.10.16.
//

#ifndef ALGORITHMS_HELPERFUNCTIONS_H
#define ALGORITHMS_HELPERFUNCTIONS_H
#include <string>
#include <sstream>
#include <vector>

void split(const std::string &s, char delim, std::vector<int> &elems) {
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(atoi(item.c_str()));
    }
}


std::vector<int> split(const std::string &s, char delim) {
    std::vector<int> elems;
    split(s, delim, elems);
    return elems;
}

#endif //ALGORITHMS_HELPERFUNCTIONS_H
