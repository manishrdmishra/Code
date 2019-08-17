#include <limits>
#include <gtest/gtest.h>

#include "../i nclude/maintain_median.h"


TEST(MaintainMedian,test1)
{

    MaintainMedian maintainMedian;
    maintainMedian.readAllNumbersFromFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-6/Median.txt");
    //maintainMedian.readAllNumbersFromFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-6/median_test_3.txt");
    long count = maintainMedian.calculateTheSumOfAllMedian();
    long sum_mod = count % 10000;
    std::cout<<"sum : "<<sum_mod<<std::endl;


}
