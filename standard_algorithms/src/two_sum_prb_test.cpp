#include <limits>
#include <gtest/gtest.h>
#include "../i nclude/two_sum_prb.h"

TEST(TwoSumProblem,test1)
{

    TwoSumProblem twoSumProblem;
    twoSumProblem.initializeHashMapFromFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-6/algo1-programming_prob-2sum.txt");
    long low = -10000;
    long high = 10000;
    twoSumProblem.initializeTargetList(low, high);
    long count = twoSumProblem.getNumberOfTargets();
    std::cout<<count<<std::endl;

}