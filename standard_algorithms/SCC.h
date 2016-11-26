//
// Created by manish on 09.11.16.
//
#include <map>
#include <list>
#include <fstream>
#include <vector>
#ifndef ALGORITHMS_SCC_H
#define ALGORITHMS_SCC_H

class StronglyConnectedComponents
{
public:
    void dfsLoop();
    void dfsLoop2();
    void kosarajuSCC();
    void dfs(std::vector<std::vector<long int>> &graph , long int current_node );
    void constructGraphFromInputFile(std::string file_name);
    void printGraph(std::vector<std::vector<long int>> &graph);
    StronglyConnectedComponents(long int node_count);

public:
    std::vector<std::vector<long int>> graph_;
    std::vector<std::vector<long int>> reverse_graph_;
    std::vector<std::vector<long int> >  leader_;
    std::vector<bool> explored_;
    std::map<long int, long int > finish_time_;
    long int time_;
    long int start_node_;
    long int node_count_;


};


StronglyConnectedComponents::StronglyConnectedComponents(long int node_count)
        : node_count_(node_count),
          explored_(node_count),
          graph_(node_count ),
          reverse_graph_(node_count),
          leader_(node_count)
{

}
void StronglyConnectedComponents::constructGraphFromInputFile(std::string file_name)
{
    std::ifstream myfile(file_name);
    long int count = 0;
    long int node_one = 0, node_two = 0;
    std::string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            std::istringstream numbers_iss( line);
            numbers_iss >> node_one;
            numbers_iss >> node_two;

            //std::cout<<node_one<<" : " <<node_two<<std::endl;

            graph_[node_one - 1].push_back(node_two);
            reverse_graph_[node_two - 1].push_back(node_one);


        }
        myfile.close();
    }
    std::cout<<"graph is constructed"<<std::endl;
   // printGraph(graph_);
    //printGraph(reverse_graph_);
}
void StronglyConnectedComponents::printGraph(std::vector<std::vector<long int>> &graph)
{

    std::cout<<"\n graph \n";
    for (long int i = 0 ; i<graph.size(); i++)
    {

        std::cout<<i+1<<"->";
        for ( auto it2 = graph[i].begin();it2 != graph[i].end(); ++it2 )
        {
            std::cout<<*it2<<" -> ";
        }
        std::cout<<"\n";


    }
}
void StronglyConnectedComponents::kosarajuSCC()
{
    //dfsLoop(graph_);
    std::cout<<"executing first dfs loop.. \n";
    for(long int i = 0 ; i< node_count_; i++)
    {
        explored_[i] = false;
        //finish_time_[i] = 0;
    }
    dfsLoop();

    std::cout<<"executing second dfs loop.. \n";
    for(long int i = 0 ; i< node_count_; i++)
    {
        explored_[i] = false;
        leader_[i].clear();
        //finish_time_[i] = 0;
    }
    dfsLoop2();

    // traverse the leader map and count the number of nodes
    // present for each leader


    std::cout<<"leader \n";
    //printGraph(leader_);
    std::vector<long int> scc_sizes;
    for ( auto it = leader_.begin(); it != leader_.end(); ++it)
    {
        long int count =  it->size();
        scc_sizes.push_back(count);
        //std::cout<<"count : "<< count<<std::endl;
    }

    std::sort(scc_sizes.begin(),scc_sizes.end());

    int count = 0;
    for (auto it = scc_sizes.rbegin(); it != scc_sizes.rend(); ++it)
    {
        std::cout<<"count : " << (*it)<<std::endl;
        count = count + 1;
        if (count == 7)
        {
            break;
        }
    }



}

void StronglyConnectedComponents::dfsLoop2()
{
    time_ = 0;
    start_node_ = 0;
    // as vector is 0 indexed
    for (long int i = node_count_; i>0; i--)
    {
        long int node_num = finish_time_[i] ;
        if( explored_[node_num - 1] == false)
        {
            start_node_ = node_num;
            dfs(graph_, node_num);
        }
    }

}


void StronglyConnectedComponents::dfsLoop()
{
    time_ = 0;
    start_node_ = 0;
    // as vector is 0 indexed
    for (long int i =  node_count_  ; i > 0 ; i--)

    {
        if( explored_[i - 1] == false)
        {
            start_node_ = i;
            dfs(reverse_graph_, i);
        }
    }

}

void StronglyConnectedComponents::dfs(std::vector<std::vector<long int>> &graph, long int current_node)
{

    //printGraph(graph);
   // std::cout<<"current_node : "<< current_node<< std::endl;
    explored_[current_node -1]= true;

    //std::cout<<"leader of "<<current_node<<" is : "<< start_node_<<std::endl;
   leader_[start_node_ - 1].push_back(current_node);


        for ( auto it = graph[current_node - 1].begin(); it != graph[current_node - 1].end(); ++it)
        {
            if (explored_[ (*it)  - 1] == false)
            {
                dfs(graph, (*it) );
            }
        }

    time_ = time_ + 1;
//std::cout<<"finishing node : "<<current_node << " finish time : " << time_<<std::endl;
    finish_time_.emplace(time_,current_node);

}
#endif //ALGORITHMS_SCC_H
