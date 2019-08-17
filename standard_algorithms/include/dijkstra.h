#ifndef ALGORITHMS_DIJKSTRA_H
#define ALGORITHMS_DIJKSTRA_H

#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>


// each vertex number and its distance
typedef  std::pair<long int , long  int> pair;
class Dijkstra
{
public:
    Dijkstra(int number_vertices);
    void dijkstraShortestPath(int start_node);
    void printGraph(std::vector<std::vector<pair>> &graph);
    void constructGraph(std::string file_name);
    long int getShortestDistance(int vertex_number);
    void printAllShortestDistance()
    {
        for (auto it = shortest_distance_.begin(); it!= shortest_distance_.end(); ++it)
        {
            std::cout<<*it<<std::endl;
        }
    }
private:
    std::vector<std::vector<pair>> graph_;
    int number_vertices_;
    std::vector<long int > shortest_distance_;
};



#endif //ALGORITHMS_DIJKSTRA_H
