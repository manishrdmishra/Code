//
// Created by manish on 21.10.16.
//

#ifndef ALGORITHMS_RANDOMCONTRACTION_H
#define ALGORITHMS_RANDOMCONTRACTION_H

#include <iostream>
#include <set>
#include <memory>
#include <vector>
#include <fstream>
#include <list>
#include <algorithm>
#include <map>
#include "helper_functions.h"


class Vertex
{
public:
    Vertex()
    {
        representative_ = 1;
    }
    Vertex(std::vector<int> vertex):vertex_(vertex),representative_(vertex[0])
    {

    }
    inline  int getRepresentative()
    {
        return  representative_;
    };
    int mergeVertex(Vertex& vertex);
    void printVertex();
    std::vector<int > getVertex()
    {
        return vertex_;
    }
    void setRepresentative(int new_representative)
    {
        representative_ = new_representative;
    }
    void setVertices ( std::vector< int> vertex)
    {
        vertex_ = vertex;
    }
private:

    std::vector<int> vertex_;
    // the first entry in this set is the representative of the vertex
// so for example if the root vertex is { 4 , 7 , 9 } then the representative
// of this vertex would be 4.
    int representative_;
};

int Vertex::mergeVertex(Vertex& second_vertex)
{

    //vertex_.insert(second_vertex.getVertex().begin(),second_vertex.getVertex().end());


    for (int i = 0 ; i<second_vertex.getVertex().size(); i++)
    {
        vertex_.push_back(second_vertex.getVertex().at(i));
    }
    std::sort(vertex_.begin(),vertex_.end());

    representative_ =  vertex_[0];
    //std::cout<<"\nnew representative : " << representative_<<std::endl;
    return representative_;

}
void Vertex::printVertex()
{
    // print vertex
    std::cout<<"{";
    for (auto vertex_it = vertex_.begin(); vertex_it != vertex_.end(); ++vertex_it)
    {
        std::cout<<*(vertex_it)<<",";
    }
    std::cout<<"}";
}

class AdjacencyListBaseNode
{

public:
    AdjacencyListBaseNode mergeBaseNode(AdjacencyListBaseNode& base_node);
    void printAdjacencyListBaseNode();

    inline int getRepresentative()
    {
        return root_vertex_.getRepresentative();
    }
    inline Vertex getBaseNode()
    {
        return root_vertex_;
    }
    inline std::list<Vertex>& getAdjacentNodes()
    {
        return adjacent_nodes_;
    }
    inline void setAdjacentNodes(std::list<Vertex> adjacent_nodes)
    {
        adjacent_nodes_ = adjacent_nodes;
    }
    inline void setRootVertex(Vertex& new_vertex)
    {
        root_vertex_ = new_vertex;
    }
    inline void insertAdjacentVertex(Vertex& adjacent_vertex)
    {
        adjacent_nodes_.push_front(adjacent_vertex);
    }
    void removeSelfLoops(Vertex& vertex);
    AdjacencyListBaseNode()
    {

    }
    void setExplored(const bool explored)
    {
        explored_ = explored;
    }
    bool getExplored()
    {
        return  explored_;
    }
private:
    // this is the list of vertices which are adjacent to this node
    // when two  nodes are merged , we need set of int to represent this new node
    std::list<Vertex> adjacent_nodes_;
    Vertex root_vertex_;
    bool  explored_;
    //bool operator==(AdjacencyListBaseNode& node);
};


AdjacencyListBaseNode AdjacencyListBaseNode::mergeBaseNode(AdjacencyListBaseNode& second_base_node)
{

    AdjacencyListBaseNode adjacency_list_base_node_temp ;
    Vertex second_vertex = second_base_node.getBaseNode();
    Vertex root_temp_one = root_vertex_;
    Vertex root_temp_two = second_base_node.getBaseNode();
    root_vertex_.mergeVertex(second_vertex);
    //std::cout<<"\n merged vertex\n";
    //root_vertex_.printVertex();
    std::list<Vertex> temp = second_base_node.getAdjacentNodes();
    adjacent_nodes_.insert(adjacent_nodes_.end(), temp.begin(),
                           temp.end());


    // after merging remove the self loops
    removeSelfLoops(root_temp_one);
    removeSelfLoops(root_temp_two);

    adjacency_list_base_node_temp.setRootVertex(root_vertex_);
    adjacency_list_base_node_temp.setAdjacentNodes(adjacent_nodes_);
    return adjacency_list_base_node_temp;
}
void AdjacencyListBaseNode::removeSelfLoops(Vertex &vertex)
{
    for (auto it = adjacent_nodes_.begin(); it != adjacent_nodes_.end(); )
    {
        if ( it->getVertex() == vertex.getVertex())
        {
            it = adjacent_nodes_.erase(it);
        }
        else
        {
            ++it;

        }
    }
}

void AdjacencyListBaseNode::printAdjacencyListBaseNode()
{
    std::cout<<"\n adjacency list base node \n";
    root_vertex_.printVertex();
    std::cout<<"    ";
    for( auto it = adjacent_nodes_.begin(); it != adjacent_nodes_.end(); it++)
    {
        it->printVertex();
        std::cout<<"->";

    }
}

class Graph
{
private:
    std::map<int,AdjacencyListBaseNode> adjacency_list_;
    std::map<int,AdjacencyListBaseNode> copy_adjacency_list_;
    int mergeTwoNodes(AdjacencyListBaseNode& node_one , AdjacencyListBaseNode& node_two);
    // void removeSelfLoopForNode(AdjacencyListBaseNode& node);
    void insertAdjacentVerticesForNode(std::vector<int> adjacent_vertices);
    void updateGraphAfterMerge(AdjacencyListBaseNode& node ,Vertex& vertex1, Vertex& vertex2);
    //   void removeAdjacentNode(AdjacencyListBaseNode& node_one , AdjacencyListBaseNode& node_two);
    // specific to Kosaraju's algorithm for SCCs
    int t;
    int s;
public:
    void constructGraphFromInputFile(std::string file_name);
    void constructGraphFromInputFile(int i, std::string file_name);
    long executeRandomContraction();
    void printGraph();
    void reinitializeGraph()
    {
        adjacency_list_ = copy_adjacency_list_;
    }

    // Kosaraju's specifi api
    void dfs-loop( Graph graph);
    void dfs(int node_num);
    long executeKosarajuSCC();
};

void Graph::dfs(Graph graph,int node_num)
{
    AdjacencyListBaseNode adjacency_list_base_node = graph[node_num];
    adjacency_list_base_node.
}
void Graph::printGraph()
{

    std::cout<<"\n graph \n";
    for ( auto it = adjacency_list_.begin(); it != adjacency_list_.end() ; ++it)
    {

        (it->second).printAdjacencyListBaseNode();
        std::cout<<"\n";


    }
}
void Graph::constructGraphFromInputFile(std::string file_name)
{
    std::ifstream myfile(file_name);
    int count = 0;
    std::string line;
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            // split the list of vertices separated by spaces
            int number;
            std::vector<int> vertices;// = split(line,' ') ;
            for ( std::istringstream numbers_iss( line);
                  numbers_iss >> number; ) {
                //std::cout << number << ' ';
                vertices.push_back(number);

            }


            insertAdjacentVerticesForNode(vertices);

        }
        myfile.close();
    }
    std::cout<<"graph is constructed"<<std::endl;
    printGraph();
    //keep a copy
    copy_adjacency_list_ = adjacency_list_;
}

// the first element is root vertex and remaining elements are the
// adjacent vertices to root vertex
void Graph::insertAdjacentVerticesForNode(std::vector<int> vertices)
{
    // create the root node in adjacency list
    std::vector<int> root_vertex = {vertices.at(0)};
    Vertex vertex(root_vertex);
    AdjacencyListBaseNode adjacencyListBaseNode;
    adjacencyListBaseNode.setRootVertex(vertex);


    // add the adajcant vertices to root node
    for (auto it = std::next(vertices.begin(), 1); it != vertices.end(); ++it)
    {
        Vertex vertex({*it});
        adjacencyListBaseNode.insertAdjacentVertex(vertex);

    }
    // add root node and its adjacent vertices to adjacency list
    adjacency_list_.insert(std::pair<int, AdjacencyListBaseNode> (vertex.getRepresentative(),adjacencyListBaseNode));


}
/*void Graph::removeAdjacentNode(AdjacencyListBaseNode &node_one, AdjacencyListBaseNode &node_two)
{
    for ( auto it = node_one.adjacent_nodes_.begin(); it != node_one.adjacent_nodes_.end(); it++)
    {
        if ( node_two.root_vertex_ == *(it))
        {
            node_one.adjacent_nodes_.erase(it);
        }
    }
}

 */
int Graph::mergeTwoNodes(AdjacencyListBaseNode &node_one, AdjacencyListBaseNode &node_two)
{

    //std::cout<<"merging graph .. "<< std::endl;
    //int node_two_representative = node_two.getBaseNode().getRepresentative() - 1;
    //std::cout<<"\nfirst adjacency list \n";
    //node_one.printAdjacencyListBaseNode();
    //std::cout<<"\nsecond adjacency list \n";
   // node_two.printAdjacencyListBaseNode();

    AdjacencyListBaseNode temp = node_one.mergeBaseNode(node_two);
    //std::cout<<"\nnew adjacency base node "<<std::endl;
    //temp.printAdjacencyListBaseNode();
    adjacency_list_.erase(node_one.getRepresentative());
    adjacency_list_.erase(node_two.getRepresentative());

    adjacency_list_.insert(std::pair<int, AdjacencyListBaseNode> (temp.getRepresentative(), temp));
    return temp.getRepresentative();

    // find the iterator corresponding to second node ( node_two )
    // and delete this node from adjacency list
    //auto it1 = adjacency_list_.begin();
    //adjacency_list_.erase(it1 + node_two_representative);
}



// after merging two vertex they get a new identifier so graph should be
// updated with this new vertex identifier.
// for ex: if vertex {1} and {4 , 5} are merged then new vertex will be
// { 1, 4 , 5 } . so for all the vertice which have a connection to either
// {1} or { 4, 5 } should be update with { 1, 4 , 5 }.
void Graph::updateGraphAfterMerge(AdjacencyListBaseNode &node, Vertex& vertex1, Vertex& vertex2)
{

    //std::cout<<"updating graph.. "<<std::endl;
//printGraph();
    //node.printAdjacencyListBaseNode();
    Vertex new_vertex = node.getBaseNode();
    // std::cout<<"new representative : "<< new_vertex.getRepresentative()<< std::endl;
    //std::cout<<" previous vertex-1 representative: " <<vertex1.getRepresentative()<<std::endl;
    //std::cout<<"previous vertex-2 representative: " <<vertex2.getRepresentative()<<std::endl;
    // iterate over the adjacent list after merging two vertices
    // and update the name of old vertices with this new one vertex
    std::list<Vertex> &temp = node.getAdjacentNodes();
    for ( auto it = temp.begin(); it != temp.end(); it++)
    {
        // to be consistent with zero indexing
        int node_num = ( it->getRepresentative() ) ;
        //  std::cout<<"node num : "<< node_num<<std::endl;

        // std::cout<<"size of list :  "<< (adjacency_list_[node_num]).getAdjacentNodes().size()<<std::endl;

        std::list<Vertex> &temp2 = adjacency_list_[node_num].getAdjacentNodes();
        for (auto it2 = temp2.begin() ; it2 !=   temp2.end();)
        {
            //    std::cout<<"current node representative: " <<it2->getRepresentative()<<std::endl;

            if (( it2->getRepresentative() == vertex1.getRepresentative() ) || (it2->getRepresentative() == vertex2.getRepresentative()))
            {

                //it2->setRepresentative(new_vertex.getRepresentative());

                //it2->setVertices(new_vertex.getVertex());
                it2 = temp2.erase(it2);
                it2 = temp2.insert(it2,new_vertex);
                //it2 = (adjacency_list_[node_num].getAdjacentNodes()).erase(it2);
                //std::cout<<"size of list :  "<< (adjacency_list_[node_num]).getAdjacentNodes().size()<<std::endl;
                //       std::cout<<"node representative: " <<it2->getRepresentative()<<std::endl;
                //adjacency_list_[node_num].insertAdjacentVertex(new_vertex);
                //std::cout<<"size of list :  "<< (adjacency_list_[node_num]).getAdjacentNodes().size()<<std::endl;
            }

            ++it2;
        }


    }
}


long Graph::executeRandomContraction()
{
    //std::cout<<"executing random contraction\n";
    int count = 0;

    //printGraph();
    /* initialize random seed: */
    srand (time(NULL));
    while ( adjacency_list_.size() > 2)
    {
       // std::cout<<"remaining nodes : "<< adjacency_list_.size()<< std::endl;
        /* choose randmoly u and v  */
        int u = rand() % adjacency_list_.size();
        //std::cout<<"u : "<< u << std::endl;


        std::list<Vertex> adjacent_nodes;

        // set count to zero
        count = 0;
        int first_key = 0;
        for (auto it = adjacency_list_.begin(); it != adjacency_list_.end(); it++)
        {
            adjacent_nodes = it->second.getAdjacentNodes();
            if ( count == u )
            {
                first_key = it->first;
         //       std::cout<<"first key : "<< it->first<<std::endl;
                break;
            }
            count = count + 1;
        }

        int v = rand()% (adjacent_nodes.size()) ;
        //std::cout<<"second vertex position : "<<  random_vertex2<< std::endl;

       // std::cout<<"u =  "<<u << " , v = "<<v <<std::endl;

        int second_key = 0;
        // set count to 1
        int count = 0;
        for (auto it = adjacent_nodes.begin(); it != adjacent_nodes.end(); it++)
        {
            second_key= it->getRepresentative();
             //std::cout<<second_key <<" ,";
             if ( count == v )
            {
         //       std::cout<<"first key : "<< it->first<<std::endl;
                break;
            }
            count = count + 1;
        }

        //std::cout<<"first vertex =  "<<first_key << " , second vertex = "<<second_key<<std::endl;

        // just for the convention make u smaller than v
        if( first_key  == second_key)
        {
            continue;
        }

        if ( first_key > second_key )
        {
            int temp = first_key;
            first_key  = second_key;
            second_key =  temp;
        }
        AdjacencyListBaseNode& node1 = adjacency_list_[first_key];
        AdjacencyListBaseNode& node2 = adjacency_list_[second_key];

        Vertex vertex1 = node1.getBaseNode();
        Vertex vertex2 = node2.getBaseNode();
        int key = mergeTwoNodes(node1, node2);
       // std::cout<<"\n";
        //printGraph();
        updateGraphAfterMerge(adjacency_list_[key],vertex1,vertex2);
        //std::cout<< "after update graph "<< std::endl;
        //printGraph();

    }
    auto it = adjacency_list_.begin();
    long int min_cut = it->second.getAdjacentNodes().size();
    return  min_cut;
}
#endif //ALGORITHMS_RANDOMCONTRACTION_H
