//
// Created by manish on 14.10.16.
//

#ifndef ALORITHMS_COUNTINVERSIONS_H
#define ALORITHMS_COUNTINVERSIONS_H
#include <iostream>


class CountInversions {
public:
    CountInversions()
    {

    }
    long long int sortAndCount(int* list, int low, int high);
    long long int mergeAndCount(int* list,  int left_low, int left_high, int right_low , int right_high );

};


#endif //ALORITHMS_COUNTINVERSIONS_H
