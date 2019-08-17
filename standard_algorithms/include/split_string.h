//
// Created by manish on 21.10.16.
//

#ifndef ALGORITHMS_HELPERFUNCTIONS_H
#define ALGORITHMS_HELPERFUNCTIONS_H

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<std::string> split_by(const std::string &text, char delim)
{
    std::stringstream stream;
    stream.str(text);

    std::string item;
    std::vector<std::string> elems;
    while (std::getline(stream, item, delim))
        elems.push_back(item);

    return elems;
}

std::vector<int> split(const std::string &s, char delim)
{
    auto strings = split_by(s, delim);

    std::vector<int> elems;

    std::transform(strings.cbegin(), strings.cend(), std::back_inserter(elems),
                   [](const auto &str) { return atoi(str.c_str()); });

    return elems;
}



#endif //ALGORITHMS_HELPERFUNCTIONS_H
