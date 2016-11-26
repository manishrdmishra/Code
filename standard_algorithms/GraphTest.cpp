//
// Created by manish on 23.10.16.
//

#include <limits>
#include <gtest/gtest.h>

#include "Graph.h"

/*TEST(Graph,RandomContraction)
{
    Graph graph;
    long int min_cut = std::numeric_limits<long > :: max ();
    graph.constructGraphFromInputFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-3/kargerMinCut.txt");
   //graph.constructGraphFromInputFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-3/test.txt");
    for ( int i = 0 ; i< 10000; i++)
    {

         long int temp = graph.executeRandomContraction();
        std::cout<<"\n temp min cut : "<< temp << std::endl;
        if(min_cut > temp )
        {
            min_cut = temp;
        }
        graph.reinitializeGraph();
    }
    std::cout<<"\n min cut : "<< min_cut << std::endl;

}
 */

