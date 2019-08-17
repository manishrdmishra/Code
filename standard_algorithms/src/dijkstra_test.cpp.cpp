#include <limits>
#include <gtest/gtest.h>

#include "../i nclude/dijkstra.h"

TEST(Dijkstra,test1)
{

    int node_count = 200;
    std::cout<<node_count<<std::endl;
    Dijkstra dijkstra(node_count);
    dijkstra.constructGraph("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-5/dijkstraData_orig.txt");
    dijkstra.dijkstraShortestPath(1);
    int nodes[] = {7,37,59,82,99,115,133,165,188,197};
    std::cout<<"dist for nodes : ";
    for (int i = 0; i<10; i++)
    {
        std::cout<<dijkstra.getShortestDistance(nodes[i])<<"," ;
    }

}