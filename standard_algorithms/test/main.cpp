#include <iostream>
#include <gtest/gtest.h>
#include <glog/logging.h>
//#include "CountInversions.h"
//#include "QuickSortCountComparisons.h"
//#include "GraphTest.h"
//#include "two_sum_prb.h"

int main(int argc, char* argv[]) {
   /*CountInversions countInversions;
    int a[] = {5, 4, 1, 8, 3, 12, 15, 2};
    int count = countInversions.sortAndCount(a,0,7);
    std::cout<<"number of inversion : "<< count << std::endl;
    return 0;
    */
    google::InitGoogleLogging(argv[0]);
    printf("Running main() from main.cc\n");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
