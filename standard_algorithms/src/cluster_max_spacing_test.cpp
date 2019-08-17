#include <limits>
#include <numeric>
#include <cctype>
#include <gtest/gtest.h>
#include <fstream>
#include <glog/logging.h>

#include "cluster_max_spacing.hpp"

// TEST(MaxSpacing,test1)
// {
//
//     std::string file_name = "/home/manish/git/Documents/fifth_sem/coursera/algorithms-2/week-2/clustering1.txt";
//     std::ifstream file(file_name);
//     std::string line;
//     getline(file,line);
//     std::istringstream sstream(line);
//     int num_of_nodes;
//     sstream>>num_of_nodes;
//     std::vector<int> vertices_(num_of_nodes);
//
//     std::iota(vertices_.begin(), vertices_.end(),1);
//
//     std::vector<std::pair<std::pair<int ,int >,int >> edge_cost_pairs;
//     while(getline(file,line))
//     {
//         std::istringstream sstream(line);
//         int node1, node2, cost;
//         sstream >> node1;
//         sstream >> node2;
//         sstream >> cost;
//         edge_cost_pairs.emplace_back(std::make_pair(node1,node2),cost);
//         //LOG(INFO) <<node1<<" "<<node2<<" "<<cost;
//     }
//     std::sort(edge_cost_pairs.begin(),edge_cost_pairs.end(),
//     [](auto& it1, auto& it2 )
//     {
//         return (it1.second < it2.second)  ;
//     });
//
//
//     // std::for_each(edge_cost_pairs.begin(), edge_cost_pairs.end(),
//     // [](auto it) {std::cout << it.first.first << " " << it.first.second << " " <<it.second << std::endl;
//     // } );
// int k = 4;
// KClusterMaxSpacing k_cluster_max_spacing;
// auto number = k_cluster_max_spacing(vertices_,edge_cost_pairs,k);
// std::cout << number << std::endl;
// }


TEST(MaxSpacing, hamming_distance_one_first)
{
    auto node = std::vector<int> {1,0,0,0};
    auto expected_nodes = std::vector<std::vector<int>> { {0, 0, 0, 0}, {1, 1, 0, 0},
    {1, 0, 1, 0}, {1, 0, 0, 1}};
    auto nodes_with_distance_one = hamming_distance_one(node, 0);
    EXPECT_EQ(4, nodes_with_distance_one.size());
    copy_to_console(nodes_with_distance_one[0]);
    EXPECT_EQ(expected_nodes, nodes_with_distance_one);
}

TEST(MaxSpacing, hamming_distance_one_second)
{
    auto node = std::vector<int> {0,0,0,0};
    auto expected_nodes = std::vector<std::vector<int>> { {1, 0, 0, 0}, {0, 1, 0, 0},
    {0, 0, 1, 0}, {0, 0, 0, 1}};
    auto nodes_with_distance_one = hamming_distance_one(node, 0);
    EXPECT_EQ(4, nodes_with_distance_one.size());
    //copy_to_console(nodes_with_distance_one[0]);
    EXPECT_EQ(expected_nodes, nodes_with_distance_one);
}

TEST(MaxSpacing, hamming_distance_two_first)
{
    auto node = std::vector<int> {1,0,0,0};
    auto expected_nodes = std::vector<std::vector<int>> { {0, 1, 0, 0}, {0, 0, 1, 0},
    {0, 0, 0, 1}, {1, 1, 1, 0}, {1, 1, 0, 1}, {1, 0, 1, 1}};
    auto nodes_with_distance_two = hamming_distance_two(node);
    EXPECT_EQ(6, nodes_with_distance_two.size());
    //copy_to_console(nodes_with_distance_one[5]);
    EXPECT_EQ(expected_nodes, nodes_with_distance_two);
}


TEST(MaxSpacing, TEST2)
{
//     // std::string file_name = "/home/manish/git/Documents/fifth_sem/coursera/algorithms-2/week-2/clustering_big.txt";
//     // std::ifstream file(file_name);
//     // std::string line;
//     // getline(file,line);
//     // std::istringstream sstream(line);
//     int num_of_nodes, bits;
//     std::cin >> num_of_nodes >> bits;
//     //sstream>>num_of_nodes;
//     //sstream>> bits;
//     //std::cout << num_of_nodes << " " << bits << std::endl;
//
//     std::vector<int> vertices_(num_of_nodes);
//     std::vector<std::vector<int>> vertex;
//     vertex.reserve(num_of_nodes);
//
//     std::iota(vertices_.begin(), vertices_.end(),1);
//
//     for(int i = 0; i<num_of_nodes; ++i)
//     {
//         std::vector<int> bit_rep;
//         for(int j = 0; j<bits; ++j)
//         {
//             int x;
//             std::cin >> x;
//             bit_rep.push_back(x);
//         }
//         vertex.push_back(bit_rep);
//     }
//
// std::cout << " input done " << std::endl;
//
//     // while(getline(file,line))
//     // {
//     //     std::array<int, 24> bit_rep;
//     //     std::istringstream intstream(line);
//     //     std::copy(intstream.begin(), intstream.end(), std::back_inserter(bit_rep));
//     //     //std::copy(bit_rep.begin(), bit_rep.end(), std::ostream_iterator<int>(std::cout," "));
//     //     //std::cout << std::endl;
//     //     vertex.push_back(bit_rep);
//     //     //std::cout << " size " << line.length() << std::endl;
//     // }
//     //
//      KClusterMaxSpacing k_cluster_max_spacing;
//      auto max_spacing = k_cluster_max_spacing.num_of_clusters(vertices_, vertex, 3);
//      std::cout <<" max spacing : " << max_spacing << std::endl;

}
