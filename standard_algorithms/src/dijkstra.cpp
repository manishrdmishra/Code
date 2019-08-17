#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>

#include "dijkstra.h"

Dijkstra::Dijkstra(int number_vertices) :
        number_vertices_(number_vertices),
        graph_(number_vertices),
        shortest_distance_(number_vertices)

{

}

void Dijkstra::constructGraph(std::string file_name)
{
    std::ifstream graph_desc_file(file_name);

    long int start_node = 0;
    long int node_number = 0;
    int distance = 0;

    if ( graph_desc_file.is_open())
    {
        std::string line;
        while( getline (graph_desc_file,line ))
        {
            std::istringstream number_iss(line);
            number_iss>>start_node ;
            //std::cout<<start_node<<" -> ";
            while ( ( number_iss >> node_number )  && ( number_iss >> distance))
            {
                //   std::cout<<node_number << " : "<< distance;
                graph_[start_node - 1].push_back(pair(node_number, distance));
            }
            std::cout<<"\n";
        }
    }
    std::cout<<"graph is constructed \n";
}

void Dijkstra::printGraph(std::vector< std::vector<pair>> &graph)
{

    for (int i = 0 ; i < graph.size(); i++)
    {

        std::cout<<i + 1 << " -> ";
        for (auto it = graph[i].begin(); it != graph[i].end(); ++it)
        {
            std::cout<<"{" << it->first << " : "<< it->second<<" } ";
        }
        std::cout<<"\n";
    }
}

void Dijkstra::dijkstraShortestPath(int start_node)
{
    // std::cout<<"graph \n";
    //printGraph(graph_);
    // initialize the distance for each vertex with +inf
    for (int i = 0; i<number_vertices_; i++)
    {
        shortest_distance_[i] = std::numeric_limits<long >::max();
    }
    // set the distance of start node as zero
    shortest_distance_[start_node - 1] = 0;

    // create a priority queue
    // pair < distance, node_number >
    //auto compare = [] ( pair pair1, pair  pair2) { return pair1.first < pair2.first;} ;
    std::list<long int > queue;
    queue.push_back(start_node);

    int count = 0;
    while(queue.empty() != true)

    {
        count = count + 1;
        // get the vertex with shortest distance
        long int min_dist = std::numeric_limits<long>::max();
        int current_node = 0;
        auto remove_it = queue.begin();
        for (auto it = queue.begin(); it != queue.end(); ++it)
        {
            if(min_dist > shortest_distance_[*it - 1])
            {
                min_dist =shortest_distance_[*it - 1];
                current_node = *it;
                remove_it = it;

            }
        }
        // delete the first element form the queue
        queue.erase(remove_it);
        std::cout<<"processing node " << current_node << " \n";

        for ( auto it = graph_[current_node - 1].begin(); it != graph_[current_node - 1].end(); ++it)
        {
            long node = (it->first) - 1;
            long distance = it->second;
            if( shortest_distance_[node] > ( shortest_distance_[current_node - 1]  + distance))
            {

                shortest_distance_[node] =  shortest_distance_[current_node - 1]  + distance;
                //std::cout<<"found short dist for "<< it->first << " : "<< shortest_distance_[node]<<std::endl;

                // search for the this node
                // if not found then insert
                // if found then first remove it and then insert it wiht new distance
                auto it2 = std::find(queue.begin(), queue.end(), (it->first));
                if(it2 == queue.end())
                {
                    queue.push_back( it->first);
                }

            }
        }

    }
    std::cout << "count : "<< count <<std::endl;

}

long int Dijkstra::getShortestDistance(int vertex_number)
{
    return  shortest_distance_[vertex_number - 1];
}

