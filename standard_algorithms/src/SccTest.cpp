#include <limits>
#include <gtest/gtest.h>

#include "../i nclude/SCC.h"

TEST(StronglyConnectedComponents,test1)
{

    long int node_count = 875714;
    //int node_count = 4;
    //int node_count = 9;
    std::cout<<node_count<<std::endl;
    StronglyConnectedComponents strongly_connected_components(node_count);
    //strongly_connected_components.constructGraphFromInputFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-4/test.txt");
    //strongly_connected_components.constructGraphFromInputFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-4/test_2.txt");
    strongly_connected_components.constructGraphFromInputFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-4/SCC.txt");
    strongly_connected_components.kosarajuSCC();


}





