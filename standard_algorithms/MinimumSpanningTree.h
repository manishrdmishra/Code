//
// Created by manish on 02.12.16.
//

#ifndef ALGORITHMS_MINIMUMSPANNINGTREE_H
#define ALGORITHMS_MINIMUMSPANNINGTREE_H

#include <vector>
#include <set>

template <typename T>
struct PrimsMinimumSpanningTree
{
    std::vector<int> calculateMSTCost(std::vector<std::vector<std::pair<int, T>>> graph, int start_node = 0);
};
template<typename T>
std::vector<int> PrimsMinimumSpanningTree <T>:: calculateMSTCost(std::vector<std::vector<std::pair< int, T >>> graph, int start_node )

{


    int current_vertex{0};

    std::vector<bool> visited(graph.size(), false);
    std::vector<T> distance ( graph.size(), std::numeric_limits<T>::max());
    std::vector<int> predecessor(graph.size() );

    std::set<int>  processing_queue;

    distance[start_node] = 0;
    current_vertex = start_node;

    processing_queue.insert(start_node);
    visited[start_node] = true;
    predecessor[start_node] = start_node;


    while( processing_queue.empty() != true)
    {
        // find the vertex with the minimum distance
       T min_cost = std::numeric_limits<T>::max();
        for ( int i = 0 ; i< distance.size(); ++i)
        {
            if(visited[i] == false && distance[i] < min_cost)
            {
                min_cost = distance[i];
                current_vertex = i;

            }
        }
        visited[current_vertex] = true;
       /* auto it = min_element( processing_queue.begin(), processing_queue.end(),
                               [&](std::pair<int , T > vertex_cost_one , std::pair<int, T> vertex_cost_two){
                                   return vertex_cost_one.second < vertex_cost_two.second;
                               });*/
        //std::cout<<"min edge "<<current_vertex << " -> " << it->first << " : ";

       // current_vertex = it->first;
        //std::cout<<"processing vertex " <<current_vertex  + 1<<std::endl;
        // remove the current vertex from processing queue
        processing_queue.erase(current_vertex);

        //std::cout<<"neighbour vertex : " ;
        for(auto it = graph[current_vertex].begin(); it != graph[current_vertex].end(); ++it )
        {
         //   std::cout<<it->first + 1<<"  ";
            // if this vertex has not been visited then process it
            if( ( visited[it->first] == false ) && ( distance[it->first ] > ( it->second )))
            {
                distance[it->first ] = it->second;
                processing_queue.insert(it->first) ;
                predecessor[it->first] = current_vertex;
            }
        }
        //std::cout<<std::endl;


    }

    return predecessor;
}
template <typename cost_type, typename MinimumSpanningTreeAlgorithm>
class MinimumSpanningTree
{
public:
    MinimumSpanningTree(std::vector<std::vector<std::pair< int, cost_type>>>&  graph)
            : graph_{graph}
    {

    }

    cost_type calculateMST();
    void printGraph();

protected:
    MinimumSpanningTreeAlgorithm mst_algorithm_;
    std::vector<std::vector< std::pair< int, cost_type>>>  graph_;


};


template <typename cost_type, typename MinimumSpanningTreeAlgorithm>
void MinimumSpanningTree<cost_type, MinimumSpanningTreeAlgorithm> ::printGraph()
{
   std::cout<<std::endl;
    for (int i = 0; i< graph_.size(); i++)
    {
        std::cout<<i<<" -> ";
        for ( auto it = graph_[i].begin() ; it != graph_[i].end(); ++it)
        {
            std::cout<<"{ "<<it->first  << ", " << it->second << "} ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

template <typename cost_type, typename MinimumSpanningTreeAlgorithm>
cost_type MinimumSpanningTree<cost_type, MinimumSpanningTreeAlgorithm> ::calculateMST()
{
    std::vector<int> predecessor_graph{mst_algorithm_.calculateMSTCost(graph_) };

    cost_type total_cost{};
    for (int i = 0; i< predecessor_graph.size(); ++i)
    {
        //std::cout<<"predecessor of "<< i  << " : " << predecessor_graph[i] << " , ";
        auto predecessor = predecessor_graph[i];
        auto it = std::find_if(graph_[i].begin(), graph_[i].end(), [&predecessor](const auto& pair)
        {
           return pair.first == predecessor;
        }
        
        if(it != graph_[i].end())
            total_cost += it->second;

    }
    return  total_cost;

}


#endif //ALGORITHMS_MINIMUMSPANNINGTREE_H
