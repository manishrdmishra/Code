//
// Created by manish on 14.10.16.
//
#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>
#include<string>
#include<fstream>
#include "CountInversions.h"

// In this example, we test the MyString class (a simple string).

/*TEST(CountInversions,sortAndCount1 ) {
    CountInversions countInversions;
    int a[] = {5, 4, 1, 8, 3, 12, 15, 2};
    EXPECT_EQ(12 ,countInversions.sortAndCount(a,0,7));
}
TEST(CountInversions,sortAndCount2 ) {
    CountInversions countInversions;
    int b[] = {5};
    EXPECT_EQ(0,countInversions.sortAndCount(b,0,0));
}
TEST(CountInversions,sortAndCount3 ) {
    CountInversions countInversions;
    int c[] = {5,4};
    EXPECT_EQ(1,countInversions.sortAndCount(c,0,1));
}
TEST(CountInversions,sortAndCount4 ) {
    CountInversions countInversions;
    int *a = NULL;
    a = new int[100000];

    std::ifstream myfile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-1/IntegerArray.txt");
    int count = 0;
    std::string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            a[count++] = atoi(line.c_str());
        }
        myfile.close();
    }
    std::cout<<"number of lines : " << count << std::endl;
long long int c = 0 ;
    c = countInversions.sortAndCount(a,0,99999);
    std::cout<<" count : " <<c<<std::endl;
    delete[](a);
     //EXPECT_EQ(3,countInversions.sortAndCount(a,0,99999));
   // int c[5] = {2, 4, 1, 3, 5};
   // EXPECT_EQ(3,countInversions.sortAndCount(c,0,4));
}
 */

