//
// Created by manish on 16.10.16.
//

#include <gtest/gtest.h>
#include <stdio.h>
#include <iostream>
#include<string>
#include<fstream>
#include <functional>
#include "QuickSortCountComparisons.h"

// In this example, we test the MyString class (a simple string).

/*TEST(CountComparisons,sortAndCount1 )
{
    QuickSortCountComparisons quickSortCountComparisons;
    int a[] = {5, 4, 1, 8, 3, 12, 15, 2};
    //   EXPECT_EQ(13 ,quickSortCountComparisons.quickSortComparison(a,0,7));
}
TEST(CountComparisons,sortAndCount2 )
{
    QuickSortCountComparisons quickSortCountComparisons;
    int a[] = {5};
    //   EXPECT_EQ(0 ,quickSortCountComparisons.quickSortComparison(a,0,0));
}
TEST(CountComparisons,sortAndCount3 )
{
    QuickSortCountComparisons quickSortCountComparisons;
    int a[] = {5, 4};
//    EXPECT_EQ(1 ,quickSortCountComparisons.quickSortComparison(a,0,1));
}
TEST ( CountCompraisons, sortAndCount4)
{
    QuickSortCountComparisons quickSortCountComparisons;
    int *a = NULL;
    a = new int[10000];

    std::ifstream myfile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-2/quicksort.txt");
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
    int left = 0;
    int right = 9999;
    int *temp = NULL;
    temp = new int[10000];
    for (int i = 0 ; i< 10000; i++)
    {
        temp[i] = a[i];
    }
    // choose first element as pivot
    c = quickSortCountComparisons.quickSortComparison(temp , left, right,
                                                      [](int* temp, int left , int right)-> int {
                                                          return left;
                                                      });
    std::cout<<"number of comparisons when first element is chosen as pivot  : " <<c<<std::endl;
// choose last element as pivot
    for (int i = 0 ; i< 10000; i++)
    {
        temp[i] = a[i];
    }
    c = quickSortCountComparisons.quickSortComparison(temp, left, right ,
                                                      []( int* temp, int left , int right ) -> int
                                                      {
                                                          return right;
                                                      });

    std::cout<<"number of comparisons when last element is chosen as pivot  : " <<c<<std::endl;
    for (int i = 0 ; i< 10000; i++)
    {
        temp[i] = a[i];
    }
    c = quickSortCountComparisons.quickSortComparison(temp,left,right,
                                                      [](int* temp,int left,int right) -> int
                                                      {
                                                          int middle = (left + right ) /2;
                                                          int initial_pivot_index = 0;
                                                          int median = std::max(std::min(temp[left],temp[middle]), std::min(std::max(temp[left],temp[middle]),temp[right]));

                                                          if ( median == temp[left])
                                                          {
                                                              initial_pivot_index = left;
                                                          }
                                                          else if ( median == temp[middle])
                                                          {
                                                              initial_pivot_index = middle;
                                                          }
                                                          else
                                                          {
                                                              initial_pivot_index = right;
                                                          }
                                                          return initial_pivot_index;
                                                      });
    std::cout<<"number of comparisons when median of first, middle and last element is chosen as pivot  : " <<c<<std::endl;
    delete[](a);
    delete[](temp);
}
 */
