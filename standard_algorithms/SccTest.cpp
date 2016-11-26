//
// Created by manish on 09.11.16.
//


#include <limits>
#include <gtest/gtest.h>

//#include "SCC.h"
//#include "dijkstra.h"
//#include "two_sum_prb.h"
#include "maintain_median.h"

/*TEST(StronglyConnectedComponents,test1)
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
 */
/*TEST(Dijkstra,test1)
{

  int node_count = 200;
  //int node_count = 4;
  //int node_count = 9;
  std::cout<<node_count<<std::endl;
Dijkstra dijkstra(node_count);
  //dijkstra.constructGraph("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-5/test1.txt");
  dijkstra.constructGraph("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-5/dijkstraData_orig.txt");
    dijkstra.dijkstraShortestPath(1);
   // dijkstra.printAllShortestDistance();
  int nodes[] = {7,37,59,82,99,115,133,165,188,197};
    std::cout<<"dist for nodes : ";
  for (int i = 0; i<10; i++)
  {
    std::cout<<dijkstra.getShortestDistance(nodes[i])<<"," ;
  }

}
TEST(TwoSumProblem,test1)
{

    TwoSumProblem twoSumProblem;
  twoSumProblem.initializeHashMapFromFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-6/algo1-programming_prob-2sum.txt");
  long low = -10000;
  long high = 10000;
  twoSumProblem.initializeTargetList(low, high);
    long count = twoSumProblem.getNumberOfTargets();
    std::cout<<count;


}

 */
TEST(MaintainMedian,test1)
{

   MaintainMedian maintainMedian;
    maintainMedian.readAllNumbersFromFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-6/Median.txt");
    //maintainMedian.readAllNumbersFromFile("/home/manish/git/Documents/fifth_sem/coursera/algorithms-1/week-6/median_test_3.txt");
    long count = maintainMedian.calculateTheSumOfAllMedian();
    long sum_mod = count % 10000;
    std::cout<<"sum : "<<sum_mod<<std::endl;


}
